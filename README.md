# QMK keymaps

Personal [QMK](https://qmk.fm) keymaps for Ergodox' [Planck EZ](https://ergodox-ez.com/pages/planck)

## Keymaps

| Keymap                         | Status            |
|:-------------------------------|:------------------|
| [`lucifer`](keymaps/lucifer)   | ✨ Actively in use |
| [`cerberus`](keymaps/cerberus) | ⛔ Deprecated      |

## Usage

The entire compilation and flashing process is being managed via [Nix](https://nixos.org). Replace `<keymap>` with the name of the keymap you want to use. If omitted, the default (`lucifer`) will be used. Since the repository is a [Flake](https://nixos.wiki/wiki/Flakes), you can run all commands either in a local clone or directly from the commandline without cloning anything.

To compile and flash, use `nix run`:

```
$ nix run
$ nix run .#<keymap>
$ nix run github:imatpot/qmk-keymaps#<keymap>
```

To only compile, use `nix build`:

```
$ nix build
$ nix build .#<keymap>
$ nix build github:imatpot/qmk-keymaps#<keymap>
```

## Disclaimers

There's a few things to note about using these keymaps.

### Disk space

The script requires the [QMK](https://qmk.fm) firmware to be placed in the Nix store with each derivation. The firmware is rather chonky, so make sure to clean up after you're tinkering.

```
$ nix-collect-garbage -d
```

### QMK home

The flashing procedure currently overwrites your local QMK's `user.qmk_home` configuration. I have yet to find a way how to conveniently use a different firmware location for a single command.

### WSL

QMK flashing is currently not supported on WSL despite what their [FAQ](https://qmk.github.io/qmk_distro_wsl/faq.html) states. It is recommended to just build the firmware and flash it using the [QMK Toolbox](https://github.com/qmk/qmk_toolbox) on Windows.

### Apple Silicon

QMK is currently broken on Apple Silicon processors. Install Rosetta on your system and pass override the system of your Nix command.

```
$ softwareupdate --install-rosetta --agree-to-license
$ nix run --system x86_64-darwin
```
