# TheNewTiptrisRecomp

A work-in-progress native PC port of **The New Tiptris** — an N64 game by H2O —
built with [N64: Recompiled](https://github.com/N64Recomp/N64Recomp): static
recompilation of the game's MIPS code to C, run on a modern runtime + renderer.

> ### ⚠️ No game content is included in this repository
> This repo contains **only** original harness code, build scripts, and
> configuration. It contains **no ROM, no recompiled game code, no audio
> microcode, no symbols, and no rendered game imagery** — all of that is
> generated locally from **your own legally-obtained copy** of the ROM. You must
> supply the ROM yourself. See "Generate the game code" below. `.gitignore`
> enforces this.

## What's here

| Path | What it is |
|---|---|
| `src/` | The port harness (app entry, overlay registration, callbacks, RSP/audio wiring) |
| `CMakeLists.txt`, `executable.cmake` | Build definition (RT64 + N64ModernRuntime + RecompFrontend + the recompiled output) |
| `tnt.us.toml` | N64Recomp config for the game code (section layout + entrypoint; **no game data**) |
| `n_aspMain.us.toml` | RSPRecomp config for the audio microcode (offsets + the audio-command jump table) |
| `gen_syms.py` | Generates the N64Recomp symbols file from the `tnt-splat` decompilation |
| `patches/ui_funcs.h` | Minimal UI-API glue required by RecompFrontend |
| `assets/` | Open-source UI fonts (Ubuntu, Noto Emoji) + a minimal RmlUi stylesheet |

## Status

- ✅ Boots, renders (RT64), full keyboard/controller input, all menus & gameplay
- ✅ Music/SFX play (audio microcode recompiled) — delivery still being polished
- Target ROM: the (U) release — sha1 `83fff25e82181a6993f28c91b9eeb8430396838b`, crc32 `528a07fa`

## Build

### 1. Prerequisites (Ubuntu/WSL2)
```bash
sudo apt-get install -y cmake ninja-build clang lld llvm libsdl2-dev libgtk-3-dev \
    libfreetype-dev libx11-dev libxrandr-dev binutils-mips-linux-gnu python3-venv
```

### 2. Dependencies (external — cloned, not committed)
```bash
mkdir -p lib && cd lib
# Pin to these commits (mutually compatible):
git clone https://github.com/N64Recomp/N64ModernRuntime && (cd N64ModernRuntime && git checkout ca568b6 && git submodule update --init --recursive)
git clone https://github.com/rt64/rt64                   && (cd rt64            && git checkout f0d8c9f && git submodule update --init --recursive)
git clone https://github.com/N64Recomp/RecompFrontend    && (cd RecompFrontend  && git checkout b3b7ebb && git submodule update --init --recursive)
cd ..
```
Also build the N64Recomp tools (`N64Recomp`, `RSPRecomp`) from
[N64Recomp](https://github.com/N64Recomp/N64Recomp).

### 3. Generate the game code from *your* ROM (nothing here is committed)
```bash
# a) Symbols: from the chris-gilmore/tnt-splat decompilation (matches this ROM).
#    Run its `splat split` on an all-asm variant, then:
python3 gen_syms.py            # -> tnt.syms.toml

# b) Recompiled game code:
N64Recomp tnt.us.toml          # -> RecompiledFuncs/

# c) Recompiled audio microcode:
RSPRecomp n_aspMain.us.toml    # -> rsp/n_aspMain.cpp
```
(See `gen_syms.py` and the `.toml` configs for exact offsets. Put your ROM where
the configs expect it — it is never checked in.)

### 4. Build
```bash
cmake -S . -B build-cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build-cmake -j
```
Run `build-cmake/TntRecompiled` and point the launcher at your ROM.

## WSL2 note (GPU + audio)
RT64 needs a Vulkan GPU. On WSL2 the default is the CPU rasterizer (`llvmpipe`),
which is slow. To use your real GPU, extract Mesa's **Dozen** (Vulkan-on-D3D12)
driver from the `kisak-mesa` PPA `mesa-vulkan-drivers` package and launch with:
```bash
VK_ICD_FILENAMES=/path/to/dzn_icd.json ./build-cmake/TntRecompiled
```
Audio uses PulseAudio; if it won't connect, `wsl --shutdown` from Windows and reopen.

## Credits
- [N64Recomp / N64ModernRuntime / RecompFrontend](https://github.com/N64Recomp) and [RT64](https://github.com/rt64/rt64)
- [chris-gilmore/tnt-splat](https://github.com/chris-gilmore/tnt-splat) — the decompilation used for symbols
