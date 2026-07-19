#!/usr/bin/env python3
"""Naming coverage: how many recompiled functions have real names vs address
placeholders, overall and per subsystem/domain. Progress tracker for the naming
campaign (see docs/naming-campaign-plan.md).

Usage:
    tools/coverage.py            # per-subsystem table (most placeholders first)
    tools/coverage.py --domains  # roll up by top-level domain
"""

import argparse
import os
import re
from collections import defaultdict
from pathlib import Path

FUNCS_DIR = Path(__file__).resolve().parent.parent / "RecompiledFuncs"
DEF_RE = re.compile(r"^RECOMP_FUNC\s+\S+\s+(\w+)\(", re.M)
PLACEHOLDER = re.compile(r"[89A-Fa-f][0-9A-Fa-f]{7}|^func_|^FUN_|^D_")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--domains", action="store_true", help="roll up by domain")
    args = ap.parse_args()

    per = defaultdict(lambda: [0, 0])  # key -> [named, total]
    tot_named = tot = 0
    for f in sorted(FUNCS_DIR.rglob("*.c")):
        rel = f.relative_to(FUNCS_DIR)
        domain = rel.parts[0] if len(rel.parts) > 1 else "(root)"
        key = domain if args.domains else rel.with_suffix("").as_posix()
        for m in DEF_RE.finditer(f.read_text()):
            named = not PLACEHOLDER.search(m.group(1))
            per[key][0] += named
            per[key][1] += 1
            tot_named += named
            tot += 1

    pct = lambda n, t: f"{100 * n // t:3d}%" if t else "  -"
    print(f"OVERALL: {tot_named}/{tot} named ({pct(tot_named, tot)}), "
          f"{tot - tot_named} placeholders\n")
    hdr = "domain" if args.domains else "domain/subsystem"
    print(f"  {'rem':>4} {'named/total':>11} {'%':>4}  {hdr}")
    for key, (named, total) in sorted(per.items(), key=lambda kv: (-(kv[1][1] - kv[1][0]), kv[0])):
        print(f"  {total - named:>4} {named:>4}/{total:<6} {pct(named, total)}  {key}")


if __name__ == "__main__":
    main()
