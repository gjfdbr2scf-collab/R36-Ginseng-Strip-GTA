# Build-/Starttests

Pflichttests:
1. Toolchain vorhanden.
2. Projekt kompiliert ohne Fehler.
3. EBOOT.PBP wird erzeugt.
4. PBP ist nicht leer/auffällig klein.
5. PBP kann mit unpack-pbp gelesen werden, sofern das Tool vorhanden ist.
6. Der erste Startscreen muss sichtbar sein.

Wichtig:
Ein CI-Check kann keinen echten PSP-Hardwarestart garantieren. Für die endgültige Schwarzer-Bildschirm-Prüfung muss jeder Release-Build zusätzlich auf PSP oder einem geeigneten PSP-Emulator gestartet werden.
