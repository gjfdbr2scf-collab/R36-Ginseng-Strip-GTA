#!/usr/bin/env bash
set -euo pipefail

PBP="${1:-EBOOT.PBP}"

if [ ! -f "$PBP" ]; then
  echo "FEHLER: $PBP fehlt."
  exit 1
fi

SIZE=$(wc -c < "$PBP")
if [ "$SIZE" -lt 65536 ]; then
  echo "FEHLER: EBOOT.PBP ist auffällig klein ($SIZE Bytes)."
  exit 1
fi

if ! command -v unpack-pbp >/dev/null 2>&1; then
  echo "WARNUNG: unpack-pbp nicht gefunden; PBP-Inhaltsprüfung übersprungen."
  exit 0
fi

TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT
unpack-pbp "$PBP" "$TMP/out" >/dev/null 2>&1 || {
  echo "FEHLER: EBOOT.PBP konnte nicht gelesen werden."
  exit 1
}

echo "PBP-Strukturprüfung erfolgreich."
echo "Größe: $SIZE Bytes"
