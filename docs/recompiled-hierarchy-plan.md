# Plan: reorganize `RecompiledFuncs/` into a subsystem hierarchy

**Status:** ready to execute in a fresh session. Self-contained — everything a cold
start needs is below. No behavior change; this is a pure, mechanical file
reorganization of already-committed generated code.

## Goal

Today the recompiled C is split into ~29 arbitrary chunk files
(`funcs_0.c … funcs_13.c`, etc.) with no semantic meaning. Reorganize the 1430
recompiled functions into a **two-level hierarchy grouped by game subsystem**, so
the codebase is navigable (mirrors `FUNCTION_INDEX.md`). Example:
`RecompiledFuncs/Tetris/Tetris.c`, `RecompiledFuncs/Board/Board.c`, …

This is code *organization* only — NOT decompilation, NOT renaming functions, NOT
touching logic. The build output and runtime behavior must be byte-for-byte
equivalent in terms of which functions exist.

## Verified facts about the current state (trust these — already checked)

- `RecompiledFuncs/` contains: **29 `.c` files**, `funcs.h` (all prototypes),
  `lookup.cpp` (name-based vram→func table), `recomp_overlays.inl` (section/func
  tables; `#include`d by `src/register_overlays.cpp:4`).
- **1430** `RECOMP_FUNC` definitions total across the `.c` files.
- **Every `.c` file is ONLY:** `#include "recomp.h"`, `#include "funcs.h"`, then a
  sequence of `RECOMP_FUNC <type> <Name>(uint8_t* rdram, recomp_context* ctx) { … }`
  bodies. Verified: **no file-scope `static`s, no file-scope data/arrays, no
  top-level jump tables** — nothing at file scope except the two includes and the
  function bodies. → **functions are freely relocatable between files with zero
  cross-file hazards.**
- Functions call each other by name; all prototypes live in `funcs.h`. So a
  function body compiles in any `.c` that includes `funcs.h`.
- Nothing `#include`s a `funcs_N.c`. `recomp_overlays.inl` and `lookup.cpp`
  reference functions by symbol name only → location-independent.
- `CMakeLists.txt:80-82` builds them via
  `file(GLOB FUNC_C_SOURCES ${CMAKE_SOURCE_DIR}/RecompiledFuncs/*.c)` +
  `file(GLOB FUNC_CXX_SOURCES … *.cpp)`. **Non-recursive** — must become
  `GLOB_RECURSE` so subdirectories are picked up.
- `tnt.us.toml`: `output_func_path = "RecompiledFuncs"`, `single_file_output = false`.
  (The recompiler regenerates flat chunk files here; see "Regeneration" below.)
- A grouped index already exists at repo root: **`FUNCTION_INDEX.md`**, plus the
  Python categorization logic used to build it (subsystem = identifier before the
  first `_`; special buckets for `~N64 library/OS` and `~unlabeled (FUN_/func_)`;
  out-degree = count of lines matching `^\s+Name\(rdram, ctx\);`).

## Subsystem categorization (reuse from FUNCTION_INDEX)

For each function name derive its subsystem:
1. `FUN_…`, `func_…`, `D_…`, `jtbl…`, `unk…`, `L8……` → **unlabeled**.
2. Matches `^(os|__os|__sc|__pi|__vi|__d|__ll|gu[A-Z]|guMtx|bzero|bcopy|memcpy|memset|sqrtf|sprintf|str…)` or ends in `_recomp` → **libultra / OS**.
3. Otherwise subsystem = leading identifier before the first `_`
   (`Tetris_CheckButtons` → `Tetris`, `BoardP_…` → `BoardP`, `Game_Update` → `Game`).

There are ~60–100 real subsystems (see FUNCTION_INDEX for the exact list & counts:
Minos 30, Audio2 29, BoardP 26, Game 24, KeySpin 23, CurrentPiece 22, …).

### Unlabeled functions (~696) — recommended: assign by ROM adjacency
Don't dump all `FUN_…` into one file. Related code is contiguous in the ROM, so
assign each unlabeled function to **the subsystem of the nearest preceding
*named* function by `vram`** (from `tnt.syms.toml`). A `FUN_xxxx` sitting between
`Board_` functions almost certainly belongs to `Board`. Keep a `_unlabeled/`
fallback only for any that precede the first named symbol. (Simpler alternative if
adjacency proves messy: a single `_unlabeled/` bucket, optionally split by address
range. Decide during execution; adjacency is strongly preferred for navigability.)

## Layout decision (CONFIRM AT KICKOFF — the one real choice)

The user described it as "two levels of hierarchy, highlevel/lowlevel.c". Pick one:

- **Layout A (recommended default): one file per subsystem.**
  `RecompiledFuncs/<Subsystem>/<Subsystem>.c`. Cleanest, ~1 file per subsystem.
  High-vs-low-level info stays available via `FUNCTION_INDEX.md` (out-degree column).
- **Layout B: high/low split per subsystem** (matches the phrase literally).
  `RecompiledFuncs/<Subsystem>/highlevel.c` (out-degree ≥ T, e.g. T=5) +
  `RecompiledFuncs/<Subsystem>/lowlevel.c` (the rest).
- **Layout C: global two-tier.** `RecompiledFuncs/highlevel/<Subsystem>.c` +
  `RecompiledFuncs/lowlevel/<Subsystem>.c`.

Switching layouts is a one-line change in the emit step, since categorization and
out-degree are already computed. Default to **A** unless the user says otherwise.

Root of `RecompiledFuncs/` keeps `funcs.h`, `lookup.cpp`, `recomp_overlays.inl`,
and (if present) `recomp.h`.

## Implementation — a re-runnable Python script `tools/reorganize_recompiled.py`

1. **Discover & parse.** Read every `RecompiledFuncs/**/*.c`. Split each into units:
   a unit starts at a line matching `^RECOMP_FUNC ` and runs until the next such
   line (or EOF). Capture the function name from the signature
   (`RECOMP_FUNC <type> <NAME>(uint8_t\* rdram`). Drop the per-file `#include`
   preamble (it's re-emitted). **Assert** every non-blank, non-`#include` line
   outside a function body is absent (matches the verified invariant); if any is
   found, abort loudly — it means a new codegen introduced file-scope content that
   must be handled.
2. **Assert completeness.** Collect the set of defined names; assert count == 1430
   (or == current count, computed fresh) and that no name is defined twice.
3. **Categorize** each name → subsystem (rules above; adjacency for unlabeled using
   `tnt.syms.toml` vram order). Optionally compute out-degree if Layout B/C.
4. **Emit** the chosen layout. Each output `.c` = `#include "recomp.h"\n#include "funcs.h"\n\n`
   followed by its function bodies **in `vram` ascending order** (stable, diff-friendly).
5. **Delete** the old flat `funcs_*.c` (only the chunk files — never `funcs.h`,
   `lookup.cpp`, `recomp_overlays.inl`, `recomp.h`).
6. **Idempotent:** running again on the already-hierarchical tree reproduces it
   exactly (re-parse handles nested dirs; same categorization → same files).

The script must NOT modify `funcs.h`, `lookup.cpp`, `recomp_overlays.inl`, or any
function *body text* (copy bytes verbatim, including the `// 0x…` asm comments).

## Build integration

In `CMakeLists.txt` change the two globs (lines ~80-81) to recurse:
```cmake
file(GLOB_RECURSE FUNC_C_SOURCES   ${CMAKE_SOURCE_DIR}/RecompiledFuncs/*.c)
file(GLOB_RECURSE FUNC_CXX_SOURCES ${CMAKE_SOURCE_DIR}/RecompiledFuncs/*.cpp)
```
(Keep the `RecompiledFuncs` target's include dirs as-is; `funcs.h` still resolves.)
Note: `recomp_overlays.inl` is included via a relative path from
`src/register_overlays.cpp` (`../RecompiledFuncs/recomp_overlays.inl`) — leave that
file at the `RecompiledFuncs/` root so that path stays valid.

## Verification (must all pass before declaring done)

1. **Symbol invariant:** the set of `RECOMP_FUNC` names defined after == before
   (script asserts; also `grep -rhoE 'RECOMP_FUNC [^(]+\(' | sort -u` diff = empty).
2. **Clean configure+build:**
   `cmake -S . -B build-cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build build-cmake --target TntRecompiled -j"$(nproc)"`
   — no duplicate-symbol or missing-symbol link errors.
3. **Boot smoke test** (optional, GPU): run via Dozen and confirm launcher + a
   short in-game session still work
   (`VK_ICD_FILENAMES=$PWD/dzn/dzn_icd.json ./build-cmake/TntRecompiled`; the stored
   ROM at `~/.local/share/N64Recomp/TheNewTiptris/tnt.n64.us.z64` auto-populates the
   launcher). NOTE: launch via the Bash tool's `run_in_background:true`; do NOT use a
   foreground `sleep` (blocked in this sandbox, SIGSTKFLT) and do NOT `pkill -f
   TntRecompiled` from inside a wrapper that matches its own command line.

## Regeneration story (document in README or tools/ header)

The recompiler (`N64Recomp` via `tnt.us.toml`) emits **flat** chunk files into
`output_func_path`. So the hierarchy is a **post-processing step**, not the
recompiler's native output. Two supported workflows — pick one and document it:
- **(recommended) Hierarchy is canonical, committed.** Regeneration is rare. If you
  ever re-run the recompiler, point `output_func_path` at a scratch dir (e.g.
  `RecompiledFuncs_raw`), then run `tools/reorganize_recompiled.py` to rebuild the
  committed hierarchy from it. Keep the script as the reproducible bridge.
- **(alt) In-place, idempotent.** Recompiler writes flat files into
  `RecompiledFuncs/`; run the script to fold them into the hierarchy. Script is
  idempotent so re-running is safe.

## Rollback

Everything is under git and generated. If anything is off:
`git checkout -- RecompiledFuncs CMakeLists.txt` restores the flat layout. Because
the transform only moves function bodies verbatim, a bad run can't corrupt logic —
worst case is a build error, fixed by rollback + rerun.

## Non-goals

- No function renaming, no logic edits, no decompilation.
- No change to `funcs.h`, `lookup.cpp`, `recomp_overlays.inl` contents.
- Not wiring context-aware controls (separate effort; this reorg makes that RE work
  easier by clustering related functions).
