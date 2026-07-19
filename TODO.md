# The New Tiptris : Recompiled — TODO

Backlog of improvements toward a polished release. The game is **fully playable**
(Linux/CachyOS verified; Windows runs). Items are grouped and roughly prioritized.
`[ ]` open · `[x]` done · `[~]` in progress.

## 🔴 High priority (bugs / blockers)

- [~] **Windows: no audio output.** Likely cause: `src/main.cpp` forces
  `SDL_AUDIODRIVER=pulseaudio` on every platform; Windows has no PulseAudio, so
  SDL audio init fails. Fix: only force pulseaudio on Linux; let SDL pick the
  default (WASAPI) on Windows. → being fixed.
- [ ] **Confirm audio buzz fix** across all music/SFX on Linux (device buffer now
  256 < queue floor; verify no residual crackle on varied tracks).
- [ ] **Windows runtime pass**: verify controller input, ROM picker (native Win32
  dialog), saves, and full gameplay actually work — only "it launches + renders"
  is confirmed so far.

## 🟠 Audio

- [ ] Windows audio backend selection + device-loss handling (e.g. Bluetooth
  disconnect) — recover gracefully instead of going silent.
- [ ] Avoid the device close/reopen on `set_frequency` when the rate is unchanged
  (tiny glitch on rate switches; game switches 48000→36000 at boot).
- [ ] Consider resampling to a fixed device rate (e.g. 48000) for robustness
  across hardware, instead of reopening at the game's exact rate.
- [ ] Remove debug audio instrumentation before release: `TNT_AUDIO_DUMP`, the
  per-200-call queue-stats logging, and the `buffer=N frames` line.

## 🟠 Windows polish

- [ ] App icon (`.ico` + `.rc`) — currently none (BanjoRecomp ships one).
- [ ] Crash diagnostics on Windows (current backtrace handler is `#ifdef __linux__`
  only) — add a minidump or SEH handler.
- [ ] With `/SUBSYSTEM:WINDOWS` there's no console — make sure errors surface
  (log file, message box) instead of silently exiting.
- [ ] Optional: code signing to reduce SmartScreen friction.

## 🟡 Packaging / distribution

- [ ] Cut a release with **both** Linux (tar.gz) + Windows (zip) once Windows
  audio + runtime are verified.
- [ ] **Flatpak** for Fedora COSMIC Atomic (robust sandbox + portal file picker).
- [ ] Optional: AppImage for Linux (single-file), if desired alongside the tar.gz.
- [ ] macOS build (deferred; RT64/ultramodern support it via clang + Metal/MoltenVK).
- [ ] README: add Windows download/run instructions; note requirements per OS.
- [ ] Update the `RUN.txt`/README controls list if defaults change.

## 🟡 UI / UX

- [ ] Register a **bold** font face for headers — `primary.ttf` is single-weight,
  so the theme's bold/weight requests don't render as bold.
- [ ] Real **promptfont** for controller glyphs (currently an Ubuntu placeholder),
  so button prompts show proper glyphs.
- [ ] Verify the relabeled Controls menu reads well in-game; tweak names if needed.
- [ ] Consider auto-starting the game on launch if a valid ROM is already stored
  (currently one click on "Start Game" — matches Banjo, but could be smoother).
- [ ] Custom window/app title + branding pass.
- [ ] Theme: iterate colors/spacing after seeing it on real displays.

## 🟡 Input

- [ ] Curate **gamepad** default mappings to game actions (we set keyboard
  defaults; verify controller defaults are sensible: rotate/hold/move/start).
- [ ] Confirm rotate CW vs CCW direction matches the game (mapping was inferred).
- [ ] Rumble/haptics if the game uses the Rumble Pak.

## 🟢 Graphics

- [ ] Exercise the graphics settings tab (resolution, upscaling, vsync) end-to-end.
- [ ] Widescreen / high-res verification across all screens (intro 3D "N", menus,
  gameplay, WONDERS, multiplayer).

## 🟢 Code cleanup / release hygiene

- [ ] Strip `TRACE()` and stray `fprintf` diagnostics from `src/main.cpp`.
- [ ] Review the `n_aspMain_safe` RSP wrapper (belt-and-suspenders) — keep or trim.
- [ ] Remove the dev-only `TNT_ROM` auto-boot path (or clearly document it).
- [ ] License/credits pass: harness license, dependency licenses, tnt-splat credit.
- [ ] Re-verify the repo contains no ROM/game data before each release.

## ✅ Done (recent)

- [x] Full static recompilation (game code + audio microcode) committed.
- [x] Playable port: boot, render (RT64), input, controller detection, audio.
- [x] Launcher + ROM picker (XDG portal on Linux); store-and-reuse ROM.
- [x] GitHub Actions CI: Linux (tar.gz) + Windows (zip); releases on tags.
- [x] Menu theme (charcoal + teal) + game-action control labels.
- [x] Audio buzz root-caused + fixed (SDL device buffer 1024 → 256).
- [x] Windows build compiles/links/packages (SDL FetchContent + native HWND).
- [x] "Tetris" scrubbed from comms; dependency fixes preserved as patches.
