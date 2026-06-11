# GalaxyRVR Deutsche Dokumentation

Dieses Projekt ist die **deutsche Übersetzung** der GalaxyRVR-Dokumentation. Alle inhaltlichen Änderungen müssen zuerst im englischen `docs`-Branch vorgenommen und dann in diesen Branch synchronisiert werden.

## Synchronisations-Workflow

1. Englischer `docs`-Branch: Änderungen abschließen und committen
2. Alle Dateien von `docs` in diesen Branch kopieren
3. `.rst`-Dateien übersetzen
4. Deutsche Formatierungs- und Stilregeln anwenden

## Übersetzungsregeln

### Beizubehalten (nicht verändern)
- Alle RST-Markierungen: `.. note::`, `.. image::`, `.. toctree::`, `.. raw:: html`, `.. code-block::` usw.
- Alle Bildpfade, URLs, Dateipfade — vollständig unverändert
- Alle RST-Überschriftsmarkierungen (nur die Länge anpassen — siehe unten)
- Alle Code-Blöcke (Arduino-Code usw.) — Code-Kommentare ins Deutsche übersetzen
- Alle Ersetzungsreferenzen (`|link_xxx|`, `|download_xxx|`)
- Alle Querverweise (`:ref:`target``)

### Nicht zu übersetzen
- `SunFounder`, `GalaxyRVR`, `Arduino`, `ESP32`, `ESP32-CAM`, `Raspberry Pi` — Marken-/Produktnamen
- Funktionsnamen, Variablennamen, Pin-Nummern im Code
- Dateinamen und Dateipfade
- Blocknamen in Scratch/Mammoth Coding (z.B. ``when up arrow key pressed``)

### Zu löschende Inhalte

- Den `.. include:: /index.rst`-Block am Anfang jeder `.rst`-Datei (außer `index.rst`):
  ```rst
  .. include:: /index.rst
     :start-after: start_hello_message
     :end-before: end_hello_message
  ```
  Der deutsche `index.rst` hat die Facebook-Notiz als Inline-`.. note::`-Block ohne Marker,
  daher schlagen alle Include-Blöcke mit ``CRITICAL: Problem with "start-after" option`` fehl.

### Zu übersetzende Inhalte
- HTML-Video-Fallback-Text: `Your browser does not support the video tag.` → `Ihr Browser unterstützt das Video-Tag nicht.`
- Code-Kommentare ins Deutsche übersetzen

### Konfigurationsänderungen
- `conf.py`: `project = 'SunFounder GalaxyRVR Kit für Arduino'`
- `_static/lang.js`: Deutscher Eintrag mit Schlüssel `'de'`

## Deutscher Sprachstil

### Formelle Anrede
- **"Sie"** (formell) im gesamten Text verwenden — nicht "du" (informell)
- Dies gilt für die gesamte Bildungsdokumentation

### Substantive
- Alle deutschen Substantive werden **großgeschrieben**
- Zusammengesetzte Wörter sind im Deutschen häufig: `Hindernisvermeidungsmodul`, `Energieversorgungssystem`

### Umlaute und Sonderzeichen
- **Immer korrekte Umlaute verwenden:** ä, ö, ü, ß — nicht ae, oe, ue, ss als Ersatz
- Sphinx/RST verarbeitet UTF-8-Umlaute problemlos
- Häufige Fehler: `konnen` → `können`, `unterstutzt` → `unterstützt`, `fuhren` → `führen`
- Nach der Übersetzung mit `sed` auf fehlende Umlaute prüfen:
  ```bash
  grep -rn "konnen\|mussen\|fuhren\|offnen\|unterstutzt" docs/source/
  ```

### Anführungszeichen
- Deutsche Anführungszeichen: „…" oder »…«
- In RST-Direktiven sind einfache ASCII-Anführungszeichen `"..."` ebenfalls akzeptabel

## Terminologie-Tabelle

| Englisch | Deutsch |
|----------|---------|
| Arduino IDE | Arduino IDE (beibehalten) |
| Assemble / Assembly | Zusammenbau / Montage |
| Battery | Akku / Batterie |
| Block (Scratch) | Block |
| Camera | Kamera |
| Code | Code |
| Component | Komponente |
| Download | Herunterladen |
| Firmware | Firmware |
| GalaxyRVR | GalaxyRVR (beibehalten) |
| Hardware | Hardware |
| Infrared / IR | Infrarot / IR |
| Learning Objectives / Goals | Lernziele |
| Lesson | Lektion |
| Mars Rover | Mars Rover |
| Materials | Materialien |
| Module | Modul |
| Motor | Motor |
| Obstacle Avoidance | Hindernisvermeidung |
| Pin / Pinout | Pin / Pinbelegung |
| Programming | Programmierung |
| Quick Start / Quick Play | Schnellstart |
| RGB Strip | RGB-LED-Streifen |
| RoboPilot | RoboPilot (beibehalten) |
| Rocker-Bogie | Rocker-Bogie (beibehalten) |
| Scratch | Scratch (beibehalten) |
| Sensor | Sensor |
| Servo | Servo |
| Shield | Shield (beibehalten) |
| Solar Panel | Solarpanel / Solarmodul |
| Sprite | Figur |
| Stage | Bühne |
| Steps | Schritte |
| Ultrasonic | Ultraschall |
| Upload | Hochladen |
| Mammoth Coding | Mammoth Coding (beibehalten) |
| Fun Project | Spaßprojekt |

## RST-Formatierungsregeln

### Titelunterstreichungen
Die Unterstreichung (`===`, `---`, `~~~`, `^^^`) muss **mindestens so lang** sein wie der Titeltext.
Deutsche Titel sind typischerweise 20–50% länger als englische. **Jede Unterstreichung nach der Übersetzung überprüfen.**

| Englisch | Deutsch | Unterstreichung |
|----------|---------|----------------|
| `Learning Objectives` (19) | `Lernziele` (9) | ≥ 9 |
| `Quick Start` (11) | `Schnellstart` (12) | ≥ 12 |
| `Programming with Scratch` (24) | `Programmierung mit Scratch` (26) | ≥ 26 |

### Abschnittsmarker (in Reihenfolge verwenden)
```
===================   # Nur für Seitentitel (reserviert)
--------------------   # Abschnittsüberschriften
~~~~~~~~~~~~~~~~~~~~   # Unterabschnittsüberschriften
^^^^^^^^^^^^^^^^^^^^   # Für weitere Unterteilungen
```

## Häufige Build-Fehler und Lösungen

| Fehler | Ursache | Lösung |
|--------|---------|--------|
| `CRITICAL: Problem with "start-after"` | Include-Block nicht gelöscht | `.. include:: /index.rst`-Block aus der Datei entfernen |
| `WARNING: Title underline too short` | Übersetzter Titel länger als Unterstreichung | Unterstreichung verlängern |
| `ERROR: Undefined substitution referenced` | Fehlende Substitution in `conf.py` | Substitution aus englischem `conf.py` kopieren |
| `WARNING: duplicate label` | Gleiches Label in mehreren Dateien | Labels eindeutig machen oder ungenutzte löschen |
| `WARNING: document isn't included in any toctree` | Datei in keinem toctree verlinkt | In `index.rst`-toctree aufnehmen oder verwaiste Datei löschen |

## Verzeichnisstruktur

Identisch mit dem englischen `docs`-Branch. Siehe englische CLAUDE.md für Details.
