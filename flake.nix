{
  description = "Personal QMK keyboard layout for Ergodox' Planck EZ";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-22.11";
    utils.url = "github:numtide/flake-utils";

    firmware = {
      flake = false;
      url = "https://github.com/qmk/qmk_firmware.git";
      type = "git";
      submodules = true;
    };
  };

  outputs = inputs @ { self, nixpkgs, utils, firmware }: utils.lib.eachDefaultSystem (system:
    let
      pname = "qmk-keymap";
      version = "1.0.0";
      keyboard = "planck/ez/glow";
      keymap = "lucifer";
      firmwareDir = "lib/qmk_firmware";
      keymapDir = "${firmwareDir}/keyboards/${keyboard}/keymaps";
      keymapFile = "${builtins.replaceStrings ["/"] ["_"] keyboard}_${keymap}.bin";
      pkgs = nixpkgs.legacyPackages.${system};
      qmkExe = "${pkgs.qmk}/bin/qmk";
    in
    {
      packages.default = pkgs.stdenv.mkDerivation {
        inherit pname version;

        src = ./.;
        nativeBuildInputs = with pkgs; [ qmk ];

        SKIP_GIT = true;
        BUILD_DIR = ./.;

        installPhase = ''
          mkdir -p $out/{bin,lib,share}

          # Copy keymap into the firmware

          cp -r --no-preserve=all ${firmware} $out/${firmwareDir}
          mkdir -p $out/${keymapDir}
          cp -r --no-preserve=all keymap $out/${keymapDir}/${keymap}

          # Build the layout

          find $out -name "*.sh" -exec chmod +x {} +
          make -C $out/${firmwareDir} ${keyboard}:${keymap}
          ln -s $out/${firmwareDir}/.build/${keymapFile} $out/share/${keymapFile}

          # Create the flash script
          # TODO: find a way to temporarily set user.qmk_home or use a specific firmware path because this overwrites the globally set user.qmk_home

          echo "${qmkExe} setup --yes --home $out/${firmwareDir}" >> $out/bin/${pname}
          echo "${qmkExe} flash $out/share/${keymapFile} --bootloader dfu-util" >> $out/bin/${pname}
          chmod +x $out/bin/${pname}
        '';
      };
    }
  );
}
