#!/usr/bin/env python3
"""Call graph for the recompiled functions: who calls a function, and what it calls.

Every call in the recompiled C is a line `<Name>(rdram, ctx);`, so the whole
call graph is extractable statically from RecompiledFuncs/**/*.c (no ROM needed).
This builds an in-memory manifest of callers/callees and prints a tree in either
direction.

Usage:
    tools/callgraph.py <func>                 # direct callers + callees
    tools/callgraph.py <func> --depth 3       # trees 3 levels deep, both ways
    tools/callgraph.py <func> --callees -d 4  # only what it calls, 4 deep
    tools/callgraph.py <func> --callers        # only what calls it
    tools/callgraph.py <substr> --find         # list functions matching a substring
"""

import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

FUNCS_DIR = Path(__file__).resolve().parent.parent / "RecompiledFuncs"
DEF_RE = re.compile(r"^RECOMP_FUNC\s+[\w*]+\s+(\w+)\s*\(uint8_t")
CALL_RE = re.compile(r"^\s*(\w+)\(rdram, ctx\);")


def build():
    """Return (home, callees, callers): home[fn]='domain/stem', callees/callers
    are dicts fn -> set(fn)."""
    home, callees = {}, defaultdict(set)
    for path in sorted(FUNCS_DIR.rglob("*.c")):
        rel = path.relative_to(FUNCS_DIR).with_suffix("").as_posix()
        lines = path.read_text().splitlines()
        cur = None
        for l in lines:
            d = DEF_RE.match(l)
            if d:
                cur = d.group(1)
                home[cur] = rel
                continue
            c = CALL_RE.match(l)
            if c and cur and c.group(1) != cur:  # drop self-recursion; it only adds (cycle) noise
                callees[cur].add(c.group(1))
    callers = defaultdict(set)
    for fn, outs in callees.items():
        for o in outs:
            callers[o].add(fn)
    return home, callees, callers


def tree(root, edges, home, depth, defined):
    def label(fn):
        h = home.get(fn)
        return f"{fn}  [{h}]" if h else f"{fn}  [external]"
    print(label(root))

    def rec(fn, prefix, remaining, path):
        kids = sorted(edges.get(fn, ()))
        for i, k in enumerate(kids):
            last = i == len(kids) - 1
            conn = "└─ " if last else "├─ "
            if k in path:
                print(prefix + conn + k + "  (cycle)")
                continue
            print(prefix + conn + label(k))
            if remaining > 1:
                rec(k, prefix + ("   " if last else "│  "), remaining - 1, path | {k})

    rec(root, "", depth, {root})


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("-d", "--depth", type=int, default=1)
    ap.add_argument("--callers", action="store_true", help="only the caller tree")
    ap.add_argument("--callees", action="store_true", help="only the callee tree")
    ap.add_argument("--find", action="store_true", help="list functions matching <func> as a substring")
    args = ap.parse_args()

    home, callees, callers = build()
    defined = set(home)

    if args.find:
        hits = sorted(f for f in defined if args.func.lower() in f.lower())
        for f in hits:
            print(f"{f}  [{home[f]}]")
        print(f"\n{len(hits)} match(es)")
        return

    if args.func not in defined:
        hits = sorted(f for f in defined if args.func.lower() in f.lower())[:15]
        print(f"'{args.func}' is not a defined function.", file=sys.stderr)
        if hits:
            print("did you mean:\n  " + "\n  ".join(hits), file=sys.stderr)
        sys.exit(1)

    both = not (args.callers or args.callees)
    nce, ncr = len(callees.get(args.func, ())), len(callers.get(args.func, ()))
    print(f"{args.func}  [{home[args.func]}]   calls {nce}, called-by {ncr}\n")

    if args.callees or both:
        print(f"CALLS  (callee tree, depth {args.depth}):")
        tree(args.func, callees, home, args.depth, defined)
        print()
    if args.callers or both:
        print(f"CALLED BY  (caller tree, depth {args.depth}):")
        tree(args.func, callers, home, args.depth, defined)


if __name__ == "__main__":
    main()
