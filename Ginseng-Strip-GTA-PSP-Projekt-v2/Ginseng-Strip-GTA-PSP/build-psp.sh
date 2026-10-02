#!/usr/bin/env bash
set -euo pipefail

echo "=== Ginseng Strip GTA / PSP Build ==="

command -v psp-gcc >/dev/null 2>&1 || {
  echo "FEHLER: psp-gcc nicht gefunden. PSPDEV/PSPSDK installieren und PATH setzen."
  exit 1
}

make clean || true
make

mkdir -p dist
cp -f EBOOT.PBP dist/EBOOT.PBP

chmod +x tools/check_build.sh
tools/check_build.sh dist/EBOOT.PBP

echo "=== BUILD OK ==="
echo "Ausgabe: dist/EBOOT.PBP"
