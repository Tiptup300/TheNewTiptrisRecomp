#!/usr/bin/env bash
#
# Build + verify TntRecompiled, reporting a single GREEN pass / RED fail.
#
# Usage:
#   tools/verify.sh            # symbol invariant + configure + build+link (headless, no GPU)
#   tools/verify.sh --boot     # also boot once under Dozen and confirm it reaches the game loop
#
# For a rename or file reorganization (the common edits to RecompiledFuncs/), the
# default headless run is the DEFINITIVE test: a dangling reference to an old name
# or a duplicate definition fails the link. Runtime behavior can't change, so the
# GPU boot (--boot) is only meaningful when you edited something behavioral.
#
# Exit code: 0 = pass, 1 = fail (usable in CI / other scripts).

set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
BUILD_DIR="build-cmake"
LOG="$(mktemp)"
trap 'rm -f "$LOG"' EXIT

if [ -t 1 ]; then R=$'\e[31m'; G=$'\e[32m'; DIM=$'\e[2m'; B=$'\e[1m'; N=$'\e[0m'; else R=; G=; DIM=; B=; N=; fi

step() { printf "  ${B}▶${N} %s ... " "$1"; }
ok()   { printf "${G}ok${N}\n"; }
fail() {
    printf "${R}FAILED${N}\n\n"
    printf "${R}${B}  ✗ RED — %s${N}\n" "$1"
    printf "${DIM}  ── last output ──────────────────────────────────────${N}\n"
    tail -n 30 "$LOG" | sed 's/^/  /'
    exit 1
}

printf "${B}TntRecompiled verify${N}\n"

# 1. Symbol-set invariant: every RECOMP_FUNC is defined exactly once. Catches a
#    botched reorg (dropped or duplicated function). Uniqueness, not a magic
#    count — the total legitimately changes if the game is re-split.
step "recompiled symbol set (no dupes/missing)"
names="$(grep -rhoE '^RECOMP_FUNC[^(]+\(' RecompiledFuncs --include='*.c' \
        | sed -E 's/^RECOMP_FUNC[[:space:]]+[A-Za-z0-9_*]+[[:space:]]+([A-Za-z0-9_]+)\(.*/\1/')"
total="$(printf '%s\n' "$names" | grep -c .)"
uniq="$(printf '%s\n' "$names" | sort -u | grep -c .)"
if [ "$total" -eq 0 ]; then
    printf '%s\n' "no RECOMP_FUNC definitions found under RecompiledFuncs/" >"$LOG"
    fail "no recompiled functions found"
fi
if [ "$total" -ne "$uniq" ]; then
    { echo "duplicate RECOMP_FUNC definitions:"; printf '%s\n' "$names" | sort | uniq -d; } >"$LOG"
    fail "duplicate symbols ($total defs, $uniq unique)"
fi
printf "${G}ok${N} ${DIM}(%s functions)${N}\n" "$total"

# 2. Configure. Always run: it's idempotent and refreshes the file GLOB, which
#    CMake caches — required after the file set changes (reorg adds/removes .c).
step "cmake configure"
if ! cmake -S . -B "$BUILD_DIR" \
        -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
        -G Ninja -DCMAKE_BUILD_TYPE=Release >"$LOG" 2>&1; then
    fail "cmake configure failed"
fi
ok

# 3. Build + link. This is the headless correctness test.
step "build + link TntRecompiled"
if ! cmake --build "$BUILD_DIR" --target TntRecompiled -j"$(nproc)" >"$LOG" 2>&1; then
    fail "build/link failed (missing or duplicate symbol?)"
fi
ok

# 4. Optional runtime smoke test under Dozen (needs a GPU/Vulkan ICD).
if [ "${1:-}" = "--boot" ]; then
    step "boot smoke test (Dozen)"
    if [ ! -f "$ROOT/dzn/dzn_icd.json" ]; then
        printf '%s\n' "dzn/dzn_icd.json not found — Dozen Vulkan ICD required for --boot" >"$LOG"
        fail "Dozen ICD missing"
    fi
    blog="$(mktemp)"
    VK_ICD_FILENAMES="$ROOT/dzn/dzn_icd.json" "$BUILD_DIR/TntRecompiled" >"$blog" 2>&1 &
    pid=$!
    reached=0
    for _ in $(seq 1 40); do          # up to ~20s
        if grep -q 'set_frequency' "$blog" 2>/dev/null; then reached=1; break; fi
        kill -0 "$pid" 2>/dev/null || break
        sleep 0.5
    done
    kill "$pid" 2>/dev/null
    cp "$blog" "$LOG"; rm -f "$blog"
    # 'set_frequency' is emitted by the recompiled game's audio init — proof that
    # recompiled code actually executed, not just that the window opened. The app
    # segfaults on window-close under Dozen, which is why we kill it first.
    [ "$reached" -eq 1 ] || fail "app did not reach the game loop"
    ok
fi

printf "\n${G}${B}  ✓ GREEN — all checks passed${N}\n"
