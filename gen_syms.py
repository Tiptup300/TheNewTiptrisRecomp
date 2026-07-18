#!/usr/bin/env python3
"""Generate an N64Recomp symbols TOML from tnt-splat all-asm disassembly.

Strategy: every function spimdisasm found is a `glabel` in asm_allasm/. The VRAM
of each function is in the instruction comment on the line right after the glabel:
    glabel osCreateThread
        /* 07C290 800B6010 27BDFFD8 */  addiu ...
We collect all (vram, name), sort, and emit a single .text section (rom 0x1000,
vram 0x8003AD80) with per-function sizes = next_vram - vram. N64Recomp reads the
actual code bytes from the real ROM, so this is correct for a static game.
"""
import os, re, sys, glob

ASM_DIR = "tnt-splat/asm_allasm"
TEXT_ROM = 0x1000
TEXT_VRAM = 0x8003AD80
DATA_START = 0x800C5590  # first .data vram (from yaml); text ends before this

glabel_re = re.compile(r'^\s*glabel\s+(\w+)\s*$')
# instruction comment: /* <rom_hex> <vram_hex(8)> <word_hex(8)> */
instr_re = re.compile(r'/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/')

funcs = {}          # vram -> name
max_instr_vram = 0  # highest instruction address seen (to bound last function)

for path in glob.glob(os.path.join(ASM_DIR, "**", "*.s"), recursive=True):
    with open(path) as f:
        lines = f.readlines()
    for i, line in enumerate(lines):
        m = instr_re.search(line)
        if m:
            v = int(m.group(1), 16)
            if TEXT_VRAM <= v < DATA_START and v > max_instr_vram:
                max_instr_vram = v
        gm = glabel_re.match(line)
        if gm:
            name = gm.group(1)
            # find the next instruction comment line to get this func's vram
            for j in range(i + 1, min(i + 4, len(lines))):
                im = instr_re.search(lines[j])
                if im:
                    vram = int(im.group(1), 16)
                    # keep first name seen for a vram (named beats later dup)
                    if vram not in funcs or funcs[vram].startswith("func_"):
                        funcs[vram] = name
                    break

if not funcs:
    print("ERROR: no functions found", file=sys.stderr)
    sys.exit(1)

vrams = sorted(funcs)
text_end = max_instr_vram + 4
text_size = text_end - TEXT_VRAM
# round section size up to 16
text_size = (text_size + 0xF) & ~0xF

# sanity: all funcs within [TEXT_VRAM, text_end)
assert vrams[0] >= TEXT_VRAM, hex(vrams[0])
assert vrams[-1] < TEXT_VRAM + text_size

out = []
out.append("# Auto-generated from tnt-splat all-asm disassembly (gen_syms.py)")
out.append("[[section]]")
out.append('name = ".text"')
out.append(f"rom  = 0x{TEXT_ROM:X}")
out.append(f"vram = 0x{TEXT_VRAM:X}")
out.append(f"size = 0x{text_size:X}")
out.append("functions = [")
for idx, v in enumerate(vrams):
    end = vrams[idx + 1] if idx + 1 < len(vrams) else text_end
    size = end - v
    name = funcs[v]
    out.append(f'    {{ name = "{name}", vram = 0x{v:X}, size = 0x{size:X} }},')
out.append("]")
out.append("")

with open("tnt.syms.toml", "w") as f:
    f.write("\n".join(out))

print(f"functions: {len(vrams)}")
print(f"text: rom=0x{TEXT_ROM:X} vram=0x{TEXT_VRAM:X} size=0x{text_size:X} (end vram 0x{text_end:X})")
print(f"first func 0x{vrams[0]:X} ({funcs[vrams[0]]}), last 0x{vrams[-1]:X} ({funcs[vrams[-1]]})")
print("wrote tnt.syms.toml")
