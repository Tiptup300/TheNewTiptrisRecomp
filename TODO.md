# The New Tiptris : Recompiled — TODO

## Rendering / graphics
- [ ] on the right of the stcreen there are flashing garpage pixels always showing, is there any way to hide these or change the rendering so these are not rendered.
- [ ] explor implementing custom framerates
- [ ] confirm ms anti-aliasing actually works
- [ ] confirm downsampling/resolution features actually works
- [ ] implement 16:9 mode
- [ ] exercise the graphics settings tab end-to-end (resolution, upscaling, vsync)
- [ ] verify high-res / widescreen across all screens (intro 3D "N", menus, gameplay, wonders, multiplayer)

## Intro
- [ ] allow ability to skip the n64 logo screen at the very beginning with any button press
- [ ] allow abillity to skil the h20 credits screen immeditetly after the logo screen, with any button press

## Controls / input
- [ ] multiplayer is not working, allow to configure mutilple controllers
- [ ] the control config screen seems completely broken, i cant actually set any keys
- [ ] in the controls screen there is an unlabeled slider, what does this do, it seems like it shows the menu controllers, but it's unlabeled
- [ ] curate sensible gamepad default mappings to the game actions (not just keyboard)
- [ ] confirm rotate CW vs CCW direction matches the game (current mapping was inferred)
- [ ] rumble / haptics if the game uses the Rumble Pak

## UI / fonts
- [ ] replace the placeholder primary UI font (primary.ttf is a renamed Ubuntu placeholder) with a real display face; add a bold weight for headers (theme requests bold the single-weight font can't provide)
- [ ] ship a real icon/emoji face if needed (NotoEmoji is the only real extra face; promptfont is now the real controller-glyph font)
- [ ] auto-start the game if a valid ROM is already stored (skip the launcher click)
- [ ] custom window title / app branding pass

## Audio
- [ ] verify Windows audio actually outputs (forced-pulseaudio was guarded to Linux; needs a Windows test)
- [ ] confirm the buzz fix holds across all music/SFX on Linux (SDL device buffer now 256, under the queue floor)
- [ ] handle audio device loss gracefully (e.g. Bluetooth disconnect) instead of going silent
- [ ] avoid the SDL device close/reopen on set_frequency when the rate is unchanged (glitch on the 48000->36000 switch at boot)
- [ ] consider resampling to a fixed device rate for robustness across hardware
- [ ] remove debug audio instrumentation before release (TNT_AUDIO_DUMP, per-200-call queue-stats logging, the "buffer=N frames" line)

## Windows
- [ ] full runtime pass: verify controller input, ROM picker (native Win32 dialog), saves, and full gameplay
- [ ] app icon (.ico + .rc)
- [ ] crash diagnostics on Windows (current backtrace handler is Linux-only)
- [ ] with /SUBSYSTEM:WINDOWS there is no console — surface errors (log file / message box) instead of silently exiting
- [ ] optional: code signing to reduce SmartScreen friction

## Mods
- [ ] the mods button just goes to settings
- [ ] implement mod ability
- [ ] investigate if you can add "default" mods that are enabled
- [ ] add default mod that hides "transfer name" and "dump lines to game pak" menu options in data
- [ ] add an included but not on by default mod to unlock all levels at start
- [ ] add an included but not on by default mod to adjust the wonders lines required to be more reasonable
  - they are currently 2499, 7499, 19999, 49999, 99999, 249999, 499999 these are way too extreme
  - they should be 2499 9300 20061 34611 52838 74657 99999
- [ ] include a mod thats not enabled by default that does a hd texture pack on the game

## Packaging / release
- [ ] cut a release with both Linux (tar.gz) + Windows (zip) once Windows runtime/audio are verified
- [ ] flatpak for Fedora COSMIC Atomic (sandbox + portal file picker)
- [ ] optional: AppImage for Linux (single-file), alongside the tar.gz
- [ ] macOS build (deferred)
- [ ] README: Windows download/run instructions + per-OS requirements
- [ ] README: add a "How to Improve the Game Source Code" guide — tnt-splat was a
      one-time bootstrap (not a live dep); tnt.syms.toml is the source of truth;
      workflow = edit syms -> regenerate (needs ROM) -> tools/reorganize_recompiled.py;
      you CAN rename/regroup/comment, you CANNOT rewrite the register-level bodies
      (that's full decompilation); point at FUNCTION_INDEX.md + the categorizer rules

## Code cleanup / release hygiene
- [ ] strip TRACE() / stray fprintf diagnostics from src/main.cpp
- [ ] review the n_aspMain_safe RSP wrapper (belt-and-suspenders) — keep or trim
- [ ] remove or clearly document the dev-only TNT_ROM auto-boot path
- [ ] license + credits pass (harness license, dependency licenses, tnt-splat credit)
- [ ] re-verify the repo contains no ROM / game data before each release
