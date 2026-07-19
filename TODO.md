# The New Tiptris : Recompiled — TODO

Backlog of improvements toward a polished release. The game is **fully playable**
(Linux/CachyOS verified; Windows runs). Items are grouped and roughly prioritized.
`[ ]` open · `[x]` done · `[~]` in progress.

## 🔴 High priority (bugs / blockers)

- [x] **Windows: no audio output.** Cause: `src/main.cpp` forced
  `SDL_AUDIODRIVER=pulseaudio` on every platform; Windows has no PulseAudio, so
  SDL audio init failed. Fixed — guarded to Linux (Windows uses WASAPI). *Verify
  on Windows.*
- [ ] **Controls config screen is broken** — can't actually set/rebind any keys.
  The rebind flow (`recompui` controls page → capture keypress → save mapping)
  isn't working. Investigate `ui_config_page_controls` binding capture + our
  keyboard-player setup.
- [ ] **Flashing garbage pixels along the RIGHT edge of the screen** (always
  visible). Likely uninitialized/overscan framebuffer area or a scissor/viewport
  issue in the F3DEX2 HLE. Options: crop the right overscan columns, add a
  scissor/letterbox, or fix the framebuffer clear. Investigate RT64 + the game's
  VI/framebuffer setup.
- [ ] **Multiplayer doesn't work** — add the ability to configure multiple
  controllers (player 2–4 assignment). Currently single-player keyboard only;
  `recompinput` supports multiple players but assignment/UI needs wiring.
- [ ] **Confirm audio buzz fix** across all music/SFX on Linux (device buffer now
  256 < queue floor; verify no residual crackle on varied tracks).
- [ ] **Windows runtime pass**: verify controller input, ROM picker (native Win32
  dialog), saves, and full gameplay actually work — only "it launches + renders +
  audio" is expected so far.

## 🔵 Boot / intro flow

- [ ] Skip the **N64 boot logo** screen at startup with any button press.
- [ ] Skip the **H2O credits** screen (immediately after the logo) with any
  button press.
- [ ] (Nice-to-have) a single "skip intros" that fast-forwards straight to the
  main menu.

## 🟣 Mods

- [ ] The **"Mods" launcher button currently just opens Settings** — wire it to a
  real mods screen/flow.
- [ ] **Implement mod support** — load/enable/manage mods. The N64Recomp stack has
  a mod framework (`RecompModTool`, `OfflineModRecomp`, librecomp mod loading);
  integrate it and expose a mods UI.

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

- [ ] **Missing-font errors flood the event log, and some buttons are invisible**
  (only appear/clickable on hover). The theme/RCSS references font weights, faces,
  or glyphs that aren't actually provided (`primary.ttf` is single-weight;
  `promptfont.ttf` is an Ubuntu placeholder; emoji font) — so those elements
  render nothing until a hover state changes them. Likely the same root cause
  behind several UI problems (invisible buttons, missing icons, maybe the
  "controls config looks broken" symptom). Fix: register the font under all
  requested weights (or alias to the single face) and ship the real
  promptfont/icon/emoji faces.
- [ ] **Back / Close buttons show no icon** — they're meant to display an icon
  glyph but nothing renders (missing icon/promptfont glyph; same root cause as
  above). Ship/register the proper icon font.
- [ ] **Controls screen has an unlabeled slider** (seems related to menu inputs /
  possibly a deadzone or sensitivity control) — identify what it actually does and
  give it a proper label (or remove it if not applicable to this game).
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

- [ ] **Adopt the standard modern control scheme** for this falling-block genre as
  the defaults (as used in current official PC releases): e.g. Left/Right move,
  Down soft-drop, Up/Space hard-drop, Z/X or Ctrl rotate CCW/CW, Shift/C hold,
  plus sensible DAS/ARR feel. Research the common layout and map our inputs to it.
- [ ] Curate **gamepad** default mappings to game actions (we set keyboard
  defaults; verify controller defaults are sensible: rotate/hold/move/start).
- [ ] Confirm rotate CW vs CCW direction matches the game (mapping was inferred).
- [ ] Rumble/haptics if the game uses the Rumble Pak.

## 🟢 Graphics

- [ ] **Implement 16:9 widescreen mode** (native is 4:3; add proper widescreen,
  not just stretch).
- [ ] **Explore custom framerates** — options beyond native (e.g. 30/60/120/144/
  uncapped) with game-speed correctly decoupled from render rate.
- [ ] **Confirm MSAA / anti-aliasing actually works** — the setting exists; verify
  it visibly applies (and at which sample counts).
- [ ] **Confirm downsampling / resolution-scale actually works** — verify the
  resolution / upscale / downsample options take real effect.
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
