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
      pname = "qmk-layout";
      version = "0.0.0";
      keyboard = "planck/ez/glow";
      keymap = "lucifer";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    rec {
      packages.default = pkgs.stdenv.mkDerivation rec {
        inherit pname version;

        src = ./.;

        # Environment
        SKIP_GIT = true;
        BUILD_DIR = ./.;

        buildInputs = [
          pkgs.qmk
        ];

        qmkExe = "${pkgs.qmk}/bin/qmk";
        binFile = "${builtins.replaceStrings [ "/" ] [ "_" ] keyboard}_${keymap}.bin";

        # TODO: find a way to temporarily set user.qmk_home, or use a specific firmware path because this overwrites the globally set user.qmk_home
        flashPhase = ''
          ${qmkExe} setup -y --home $out/qmk_firmware
          # ${qmkExe} flash -b
          ${qmkExe} flash $out/qmk_firmware/.build/${binFile} --bootloader dfu-util
        '';

        installPhase = ''
          mkdir -p $out/bin

          cp -r --no-preserve=all ${firmware} $out/qmk_firmware

          mkdir -p $out/qmk_firmware/keyboards/${keyboard}/keymaps
          cp -r --no-preserve=all layout $out/qmk_firmware/keyboards/${keyboard}/keymaps/${keymap}

          find $out -name "*.sh" -exec chmod +x {} +
          make -C $out/qmk_firmware ${keyboard}:${keymap}

          echo "${flashPhase}" > $out/bin/${pname}
          chmod +x $out/bin/${pname}
        '';
      };
    }
  );
}
