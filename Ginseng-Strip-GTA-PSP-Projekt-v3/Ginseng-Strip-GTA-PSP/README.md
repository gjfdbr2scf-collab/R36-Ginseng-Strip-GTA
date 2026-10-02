# Ginseng Strip GTA — PSP

Echtes PSP-Homebrew-Projekt für `EBOOT.PBP`.

## Zielplattformen
- Sony PSP
- PPSSPP
- R36S als zusätzliches Emulationsziel
- R40/R40XX als zusätzliches Emulationsziel
- R40S ist kein Ziel dieses Projekts

Die R36S/R40-Kompatibilität muss anschließend auf den konkreten Geräten bzw. deren PSP-Emulatoren getestet werden. Der PSP-Build selbst erzeugt eine normale PSP-`EBOOT.PBP`.

## GitHub Actions

Der Workflow liegt unter:

`.github/workflows/build-psp.yml`

Er:
1. startet den offiziellen PSPDEV-Container,
2. prüft `psp-gcc`, `psp-config`, `pack-pbp` und `mksfoex`,
3. prüft die Projektdateien,
4. baut das PSP-Programm,
5. prüft `dist/EBOOT.PBP`,
6. lädt `EBOOT.PBP` als GitHub Artifact hoch.

## Lokal
```bash
./build-psp.sh
```

## Ergebnis
```text
dist/EBOOT.PBP
```

Für eine echte PSP wird diese Datei später in einen passenden Homebrew-Ordner unter `PSP/GAME/` gelegt.

Wichtig: Ein grüner CI-Build beweist den erfolgreichen Build. Er ersetzt keinen tatsächlichen Starttest auf PSP/PPSSPP/R36S/R40.
