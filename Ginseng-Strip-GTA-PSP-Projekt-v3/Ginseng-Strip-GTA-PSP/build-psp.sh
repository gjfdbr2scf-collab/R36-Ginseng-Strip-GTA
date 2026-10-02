#!/usr/bin/env bash
set -euo pipefail

echo "=== Ginseng Strip GTA / PSP Build ==="

command -v psp-gcc >/dev/null 2>&1 || {
  echo "ERROR: psp-gcc was not found."
  exit 1
}

command -v psp-config >/dev/null 2>&1 || {
  echo "ERROR: psp-config was not found."
  exit 1
}

rm -rf dist
mkdir -p dist

echo "Cleaning previous objects..."
make clean || true

echo "Compiling PSP project..."
make

test -f EBOOT.PBP || {
  echo "ERROR: make finished without creating EBOOT.PBP."
  exit 1
}

cp EBOOT.PBP dist/EBOOT.PBP

SIZE=$(wc -c < dist/EBOOT.PBP)
echo "Created dist/EBOOT.PBP (${SIZE} bytes)"

if [ "$SIZE" -lt 65536 ]; then
  echo "ERROR: EBOOT.PBP is unexpectedly small."
  exit 1
fi

echo "=== PSP BUILD SUCCESS ==="
