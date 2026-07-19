#!/usr/bin/env python3
"""Cyclomatic-complexity score for every recompiled function.

The recompiler translates each MIPS conditional branch into an `if (...) { ...
goto L; }` and each jump table into a `switch`/`case`. So the decision points of
a function map to: (# of `if (` statements) + (# of `case` labels). McCabe
cyclomatic complexity is then M = decisions + 1.

Note: `slt`-style ternaries (`r1 = a < b ? 1 : 0`) are NOT counted — they compute
a boolean into a register; the actual branch is the later `if` that tests it.

Usage:
    python3 tools/complexity.py               # print top 40 + summary, write full list
    python3 tools/complexity.py --top 100     # print top 100
    python3 tools/complexity.py --out FILE.md # where to write the full ranked table
"""

import argparse
import re
from pathlib import Path

FUNCS_DIR = Path(__file__).resolve().parent.parent / "RecompiledFuncs"

FUNC_START = re.compile(r"^RECOMP_FUNC\s+[\w*]+\s+(\w+)\s*\(uint8_t")
IF_RE = re.compile(r"^\s*if \(", re.M)
CASE_RE = re.compile(r"^\s*case ", re.M)
CODE_RE = re.compile(r"^\s*(?!//)\S")  # non-blank, non-comment line
PLACEHOLDER = re.compile(r"[89A-Fa-f][0-9A-Fa-f]{7}|^func_|^FUN_|^D_")


def functions():
    for path in sorted(FUNCS_DIR.rglob("*.c")):
        lines = path.read_text().splitlines(keepends=True)
        starts = [i for i, l in enumerate(lines) if l.startswith("RECOMP_FUNC ")]
        for idx, s in enumerate(starts):
            e = starts[idx + 1] if idx + 1 < len(starts) else len(lines)
            body = "".join(lines[s:e])
            m = FUNC_START.match(body)
            if not m:
                continue
            name = m.group(1)
            ifs = len(IF_RE.findall(body))
            cases = len(CASE_RE.findall(body))
            cyc = ifs + cases + 1
            sloc = sum(1 for l in lines[s:e] if CODE_RE.match(l))
            named = not PLACEHOLDER.search(name)
            yield {
                "cyc": cyc, "ifs": ifs, "cases": cases, "sloc": sloc,
                "name": name, "file": path.stem, "named": named,
            }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--out", default=str(FUNCS_DIR.parent / "FUNCTION_COMPLEXITY.md"))
    args = ap.parse_args()

    rows = sorted(functions(), key=lambda r: (-r["cyc"], -r["sloc"], r["name"]))
    total = len(rows)
    named = sum(1 for r in rows if r["named"])

    # Full ranked table to file.
    out = Path(args.out)
    lines = [
        "# Function cyclomatic complexity",
        "",
        f"{total} functions, ranked by cyclomatic complexity "
        "(M = if-branches + case-labels + 1). `named?` marks whether the function "
        "has a meaningful name yet (blank = still an address placeholder).",
        "",
        "| rank | cyc | if | case | sloc | named? | file | function |",
        "|-----:|----:|---:|-----:|-----:|:------:|------|----------|",
    ]
    for i, r in enumerate(rows, 1):
        lines.append(
            f"| {i} | {r['cyc']} | {r['ifs']} | {r['cases']} | {r['sloc']} | "
            f"{'y' if r['named'] else ' '} | {r['file']} | `{r['name']}` |"
        )
    out.write_text("\n".join(lines) + "\n")

    # Console summary + top N.
    cycs = [r["cyc"] for r in rows]
    print(f"{total} functions ({named} named, {total - named} placeholder)")
    print(f"cyclomatic: max {cycs[0]}, median {cycs[total // 2]}, "
          f"mean {sum(cycs) / total:.1f}")
    print(f"full ranked table -> {out}")
    print(f"\ntop {args.top} by cyclomatic complexity:")
    print(f"  {'cyc':>4} {'sloc':>5}  {'file':<14} function")
    for r in rows[: args.top]:
        flag = " " if r["named"] else "*"
        print(f"  {r['cyc']:>4} {r['sloc']:>5} {flag} {r['file']:<14} {r['name']}")
    print("\n(* = still a placeholder name)")


if __name__ == "__main__":
    main()
