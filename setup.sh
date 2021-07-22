#!/bin/sh

git clone git@github.com:zsa/qmk_firmware.git

if [[ $(uname -v) == *NixOS* ]]
then
    echo "Info: NixOS detected! Attempting to create lorri environment..."
    ln -s qmk_firmware/shell.nix shell.nix

    if command -v lorri &> /dev/null && command -v direnv &> /dev/null
    then
        echo "eval \"\$(lorri direnv)"\" > .envrc
        direnv allow
        lorri shell
    else
        echo "Failed setting up lorri environment: This script assumes you use lorri and direnv."
    fi
fi


if command -v make &> /dev/null
then
    cd qmk_firmware
    make git-submodule
else
    echo "Failed setting up qmk_firmware: make is not installed"
fi
