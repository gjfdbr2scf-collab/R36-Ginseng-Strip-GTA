# Ginseng Strip GTA — PSP

Das ist das echte PSP-Homebrew-Projekt. Der Build erzeugt `EBOOT.PBP`.

Die PSPDEV/PSPSDK-Toolchain stellt Compiler, `pack-pbp`, `mksfoex` und die PSP-Bibliotheken bereit. `build.mak` von PSPSDK verpackt das Programm als `EBOOT.PBP`.

## Lokal
```bash
./build-psp.sh
```

Ergebnis:
`dist/EBOOT.PBP`

## PSP
Die erzeugte `EBOOT.PBP` gehört in:
`/PSP/GAME/GinsengStripGTA/EBOOT.PBP`

Dann kann sie über das Homebrew-Menü bzw. eine kompatible PSP-Homebrew-Umgebung gestartet werden.

## PPSSPP
Die gleiche `EBOOT.PBP` kann zum Testen in PPSSPP verwendet werden.

## Hinweis
Dieses Paket ist der echte Projekt-/Buildstand. Es ist noch nicht die behauptete fertige AAA-artige Vollproduktion: dafür fehlen die finalen 3D-Modelle, Texturen, Animationen, Karten und die komplette Audio-Asset-Sammlung. Diese werden im Projekt schrittweise ergänzt; ich werde sie nicht als bereits fertig ausgeben, wenn sie nicht tatsächlich erzeugt wurden.
