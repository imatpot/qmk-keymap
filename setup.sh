#!/bin/sh

# use zsa's instead of "official" repo
git clone git@github.com:zsa/qmk_firmware.git

# try NixOS today!
ln -s qmk_firmware/shell.nix shell.nix
echo "eval \"\$(lorri direnv)"\" > .envrc
direnv allow
lorri shell

cd qmk_firmware

# installs chibios
make git-submodule
