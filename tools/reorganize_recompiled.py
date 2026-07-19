#!/usr/bin/env python3
"""Reorganize RecompiledFuncs/*.c into a subsystem hierarchy (Layout A).

The N64Recomp recompiler (driven by tnt.us.toml) emits flat chunk files
(funcs_0.c ... funcs_N.c) into RecompiledFuncs/. This script re-buckets every
RECOMP_FUNC body into RecompiledFuncs/<Subsystem>/<Subsystem>.c, where the
subsystem is derived from the function name (identifier before the first '_';
libultra/OS routines and unlabeled FUN_/func_ names get special handling).

It is a pure, mechanical reorganization: function bodies are copied verbatim
(byte-for-byte, including asm comments), nothing is renamed, and funcs.h /
lookup.cpp / recomp_overlays.inl are untouched at the RecompiledFuncs/ root.

Re-runnable and idempotent: it parses RecompiledFuncs/**/*.c recursively, so
running it on an already-hierarchical tree reproduces the same tree, and
running it after the recompiler drops fresh flat chunk files folds them in.

Usage:
    python3 tools/reorganize_recompiled.py [--dry-run]
"""

import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
FUNCS_DIR = REPO_ROOT / "RecompiledFuncs"

PREAMBLE = '#include "recomp.h"\n#include "funcs.h"\n\n'
ALLOWED_PREAMBLE_LINES = {'#include "recomp.h"', '#include "funcs.h"', ""}

FUNC_START_RE = re.compile(r"^RECOMP_FUNC\s+[\w*]+\s+(\w+)\s*\(uint8_t\s*\*\s*rdram")
VRAM_RE = re.compile(r"//\s*(0x[0-9A-Fa-f]{8}):")

UNLABELED_RE = re.compile(r"^(FUN_|func_|D_|jtbl|unk|L8)")
LIBULTRA_RE = re.compile(
    r"^(_"                # every _/__ name in this ROM is a library internal
    r"|os[A-Z]|gu[A-Z]"   # libultra OS + gfx utils
    r"|al[A-Z]"           # libaudio (alSyn*, alEnvmixer*, ...)
    r"|bzero|bcopy|bcmp|memcpy|memset|memmove"
    r"|sqrtf?$|sinf?$|cosf?$|sins$|coss$|sprintf|vsprintf|printf|rand|ldiv|lldiv"
    r"|str(len|cpy|ncpy|cat|cmp|ncmp|chr|rchr|pbrk|str)$"
    r"|Printf|proutSprintf|kdebugserver|isPrintable)"
)
NO_SPLIT_RE = re.compile(r"^(n64Heap|h2o)")  # camelCase families kept whole

# Generic verb prefixes are NOT subsystems: get_board_size (Board) and
# get_char_width (Font) share only the verb. A name whose prefix-before-the-
# first-underscore is one of these folds by vram adjacency like an unlabeled
# function, instead of spawning a junk bucket. Real subsystems are PascalCase
# or a known camelCase family (Board, Minos, displayText, n64Heap), so a
# lowercase verb prefix is an unambiguous signal. The right long-term fix for
# such a function is to rename it Subsystem_Verb in tnt.syms.toml.
GENERIC_VERB_PREFIXES = {
    "get", "set", "has", "is", "can", "check", "load", "save", "add",
    "remove", "update", "do", "init", "inits", "gets", "create", "calls",
}

# Special buckets get a leading underscore so they sort first and cannot
# collide with a real subsystem prefix from the game.
LIBULTRA_BUCKET = "_libultra"
UNLABELED_BUCKET = "_unlabeled"


def parse_units(path: Path):
    """Split one .c file into (name, body_text) units; verify the invariant
    that nothing exists at file scope except the two #includes."""
    text = path.read_text()
    lines = text.splitlines(keepends=True)
    starts = [i for i, l in enumerate(lines) if l.startswith("RECOMP_FUNC ")]
    if not starts:
        sys.exit(f"ERROR: {path} contains no RECOMP_FUNC definitions")

    for l in lines[: starts[0]]:
        if l.rstrip("\n").rstrip() not in ALLOWED_PREAMBLE_LINES:
            sys.exit(
                f"ERROR: unexpected file-scope content in {path!s} before first "
                f"function: {l.rstrip()!r}\n(new codegen output? handle it first)"
            )

    units = []
    for idx, start in enumerate(starts):
        end = starts[idx + 1] if idx + 1 < len(starts) else len(lines)
        body = "".join(lines[start:end])
        m = FUNC_START_RE.match(body)
        if not m:
            sys.exit(f"ERROR: cannot parse function signature in {path!s}:\n{lines[start]!r}")
        vram_m = VRAM_RE.search(body)
        if vram_m:
            vram = int(vram_m.group(1), 16)
        else:
            # Empty stubs have no asm comments; their names encode the vram
            # (func_800A32B0, FUN_..._8003b3e4_...).
            name_m = re.search(r"(?<![0-9A-Fa-f])([8-9A-Fa-f][0-9A-Fa-f]{7})(?![0-9A-Fa-f])", m.group(1))
            if not name_m:
                sys.exit(f"ERROR: cannot determine vram for {m.group(1)} ({path!s})")
            vram = int(name_m.group(1), 16)
        units.append((m.group(1), vram, body.rstrip() + "\n"))
    return units


def subsystem_of(name: str) -> str:
    if name == "recomp_entrypoint" or name.endswith("_recomp"):
        return LIBULTRA_BUCKET
    if UNLABELED_RE.match(name):
        return UNLABELED_BUCKET
    if LIBULTRA_RE.match(name):
        return LIBULTRA_BUCKET
    m = NO_SPLIT_RE.match(name)
    if m:
        return m.group(1)
    if "_" in name:
        prefix = name.split("_", 1)[0]
        if prefix in GENERIC_VERB_PREFIXES:
            return UNLABELED_BUCKET  # fold by adjacency, don't make a verb bucket
        return prefix
    return name


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true", help="print the bucket table, write nothing")
    args = ap.parse_args()

    src_files = sorted(FUNCS_DIR.rglob("*.c"))
    all_units = []
    for f in src_files:
        all_units.append((f, parse_units(f)))

    # Completeness / uniqueness invariants.
    flat = [u for _, units in all_units for u in units]
    names = [n for n, _, _ in flat]
    dupes = {n for n in names if names.count(n) > 1} if len(set(names)) != len(names) else set()
    if dupes:
        sys.exit(f"ERROR: duplicate function definitions: {sorted(dupes)}")
    print(f"parsed {len(flat)} functions from {len(src_files)} files")

    # Categorize in two passes over vram order (related code is contiguous in
    # the ROM). Pass 1 counts named functions per subsystem; subsystems with
    # >= MIN_SIZE named functions are "kept". Pass 2 assigns every function:
    # kept-subsystem functions go to their own bucket, everything else
    # (unlabeled FUN_/func_ names AND one-off named functions whose subsystem
    # was too small to keep) inherits the nearest preceding kept subsystem.
    # Any leading run before the first kept function falls back to _unlabeled.
    MIN_SIZE = 3
    flat.sort(key=lambda u: u[1])
    named_counts = defaultdict(int)
    for name, _, _ in flat:
        sub = subsystem_of(name)
        if sub != UNLABELED_BUCKET:
            named_counts[sub] += 1
    kept = {s for s, c in named_counts.items() if c >= MIN_SIZE}
    kept.add(LIBULTRA_BUCKET)
    folded = sorted(set(named_counts) - kept)
    if folded:
        print(f"  (folding {len(folded)} small subsystems into vram neighbors: "
              f"{', '.join(folded)})")

    buckets = defaultdict(list)
    current = UNLABELED_BUCKET
    for name, vram, body in flat:
        sub = subsystem_of(name)
        if sub in kept:
            current = sub
        else:
            sub = current
        buckets[sub].append((name, vram, body))

    # Windows is case-insensitive: two subsystems differing only by case would
    # collide on disk. Merge case variants into the largest spelling.
    lowered = defaultdict(list)
    for sub in buckets:
        lowered[sub.lower()].append(sub)
    for variants in lowered.values():
        if len(variants) > 1:
            canonical = max(variants, key=lambda s: len(buckets[s]))
            for v in variants:
                if v != canonical:
                    print(f"  (merging case variant {v!r} into {canonical!r})")
                    buckets[canonical].extend(buckets.pop(v))

    for sub in sorted(buckets, key=lambda s: (-len(buckets[s]), s)):
        print(f"  {sub:24s} {len(buckets[sub]):4d} funcs")
    print(f"{len(buckets)} subsystems")

    if args.dry_run:
        return

    # Emit the hierarchy, then delete every previously-parsed .c that is no
    # longer an output (old flat chunk files, or stale subsystem files after a
    # re-categorization). funcs.h / lookup.cpp / recomp_overlays.inl are never
    # touched.
    outputs = set()
    for sub, units in buckets.items():
        units.sort(key=lambda u: u[1])
        out = FUNCS_DIR / sub / f"{sub}.c"
        out.parent.mkdir(exist_ok=True)
        out.write_text(PREAMBLE + "\n".join(body for _, _, body in units))
        outputs.add(out)
    for f in src_files:
        if f not in outputs:
            f.unlink()
    for d in sorted(FUNCS_DIR.iterdir()):
        if d.is_dir() and not any(d.iterdir()):
            d.rmdir()

    # Post-write symbol-set invariant.
    after = sorted(
        n for f in FUNCS_DIR.rglob("*.c") for n, _, _ in parse_units(f)
    )
    if after != sorted(names):
        sys.exit("ERROR: symbol set changed during reorganization! rollback with: "
                 "git checkout -- RecompiledFuncs")
    print(f"wrote {len(outputs)} files; symbol set verified ({len(after)} functions)")


if __name__ == "__main__":
    main()
