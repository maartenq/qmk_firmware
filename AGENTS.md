# Agent Instructions

Personal fork of [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware)
with my keymaps on `master`. For AI coding agents working in this repo
(`CLAUDE.md` is a symlink to this file).

## Layout

- `keyboards/ferris/keymaps/maartenq/` — Ferris Sweep (Elite-C,
  atmega32u4, `qmk-dfu` bootloader). Main keymap: QWERTY, SYM, NUM, NAV
  layers, combos, caps word. Target `ferris/sweep`.
- `keyboards/splitkb/kyria/keymaps/maartenq/` — Kyria keymap.
- Everything else is upstream. Don't edit it for personal changes; put
  them in a keymap (`keymap.c`, `config.h`, `rules.mk`).

## Build and flash

```console
qmk compile -kb ferris/sweep -km maartenq
qmk flash -kb ferris/sweep -km maartenq
```

- Split halves are flashed one at a time: reset the half into the
  bootloader, flash, repeat for the other.
- Flashing needs the physical keyboard and user action. Compile to
  verify; never flash unasked.
- `qmk doctor` checks the toolchain. On Arch, `qmk` uses `platformdirs`
  but `requirements.txt` still pins `appdirs`; install `python-appdirs` if
  the CLI self-check aborts.
- Don't use root/sudo. Hand the user the exact command instead.

## Git

- Branches: `origin` = my fork, `upstream` = qmk/qmk_firmware. Config
  lives on `master`, rebased on `upstream/master` (history rewritten, so
  push with `--force-with-lease`; ask first).
- Keep a personal commit set small and atomic. Conventional commits:
  `<type>(scope): <description>`, imperative, lowercase, no period.
- Never commit submodule pointer changes (`lib/chibios`,
  `lib/chibios-contrib`, etc.) from local checkout drift. After a rebase
  run `git submodule update --init --recursive`. If a rebase conflicts on
  submodules, take upstream's pointers.

## Syncing with upstream

```console
git fetch upstream
git rebase upstream/master
git submodule update --init --recursive
qmk compile -kb ferris/sweep -km maartenq
```

- Try the rebase in a throwaway `git worktree` first for long gaps.
- Always compile after a sync; QMK renames things. Known: mouse keycodes
  are now `MS_*` (was `KC_MS_*`, `KC_BTN*`, `KC_ACL*`).
- Check upstream's
  [breaking changes](https://docs.qmk.fm/breaking_changes) notes when the
  gap spans a `breakpoint_*` tag.

## Style

- Follow `.editorconfig` (LF, 4-space indent, final newline).
- Match the keymap's existing idioms: layer and keycode enums at the
  top, aliases for readable `LAYOUT` rows, combos in the `combos` enum.
- Prefer QMK's own features and `config.h` options over custom code.
- Verify keycode names against the
  [QMK docs](https://docs.qmk.fm/keycodes); don't guess.
