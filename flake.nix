{
  description = "Personal QMK keymaps for Ergodox' Planck EZ";

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

  outputs = { self, nixpkgs, utils, firmware }: utils.lib.eachDefaultSystem (system: rec {
    packages = {
      cerberus = lib.mkKeymap {
        keymap = "cerberus";
        version = "1.0.0";
      };

      lucifer = lib.mkKeymap {
        keymap = "lucifer";
        version = "0.1.0";
      };

      default = packages.cerberus;
    };

    lib = {
      mkKeymap = { keymap, version }:
        let
          pkgs = nixpkgs.legacyPackages.${system};
          pname = "qmk-keymap-${keymap}";
        in
        pkgs.stdenv.mkDerivation {
          inherit pname version;

          src = ./.;
          nativeBuildInputs = with pkgs; [ qmk ];

          SKIP_GIT = true;
          BUILD_DIR = ./.;

          installPhase =
            let
              keyboard = "planck/ez/glow";
              qmkExe = "${pkgs.qmk}/bin/qmk";
              firmwareDir = "lib/qmk_firmware";
              keyboardDir = "${firmwareDir}/keyboards/${keyboard}";
              keymapBin = "${builtins.replaceStrings ["/"] ["_"] keyboard}_${keymap}.bin";
            in
            ''
              mkdir -p $out/{bin,lib,share}

              # Copy keymaps into the firmware

              cp -r --no-preserve=all ${firmware} $out/${firmwareDir}
              mkdir -p $out/${keyboardDir}
              cp -r --no-preserve=all keymaps $out/${keyboardDir}

              # Build the selected keymap

              find $out -name "*.sh" -exec chmod +x {} +
              make -C $out/${firmwareDir} ${keyboard}:${keymap}
              ln -s $out/${firmwareDir}/.build/${keymapBin} $out/share/${keymapBin}

              # Create the flash script
              # TODO: find a way to temporarily set user.qmk_home or use a specific firmware path because this overwrites the globally set user.qmk_home

              echo "${qmkExe} setup --yes --home $out/${firmwareDir}" >> $out/bin/${pname}
              echo "${qmkExe} flash $out/share/${keymapBin} --bootloader dfu-util" >> $out/bin/${pname}
              chmod +x $out/bin/${pname}
            '';
        };
    };
  });
}
