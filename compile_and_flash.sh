#!/bin/sh

# move layout into correct place
rm -rf qmk_firmware/keyboards/planck/ez/glow/keymaps/my_planck
cp -r layout qmk_firmware/keyboards/planck/ez/glow/keymaps/my_planck

cd qmk_firmware

# compile and flash
make planck/ez/glow:my_planck:dfu-util
