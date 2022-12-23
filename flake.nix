{
  description = "Personal QMK keyboard layout for Ergodox' Planck EZ";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-22.11";
    utils.url = "github:numtide/flake-utils";

    firmware = {
      flake = false;
      url = "https://github.com/zsa/qmk_firmware.git";
      type = "git";
      submodules = true;
    };
  };

  outputs = inputs @ { self, nixpkgs, utils, firmware }: utils.lib.eachDefaultSystem (system:
    let
      pname = "planck";
      version = "0.0.0";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      packages.default = pkgs.stdenv.mkDerivation {
        inherit pname version;

        src = ./.;

        # Environment
        SKIP_GIT = true;

        buildInputs = with pkgs; [ qmk ];

        buildPhase = ''
          cp -r --no-preserve=all ${firmware} qmk
          cp -r layout qmk/keyboards/planck/ez/glow/keymaps/${pname}

          chmod -R 777 qmk # I am so sorry

          make --directory=qmk planck/ez/glow:${pname}
        '';
      };
    }
  );
}
