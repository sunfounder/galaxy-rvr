# GalaxyRVR Documentation (English Source)

This is the **source of truth** for all GalaxyRVR documentation. Changes are made here first, then synced to language branches (`docs-cn`, `docs-de`, `docs-es`, `docs-fr`, `docs-it`, `docs-ja`).

## Structure

```
docs/
├── make.bat / Makefile          # Sphinx build scripts
├── requirements.txt             # Python dependencies (sphinx, sphinx_rtd_theme, sphinx_copybutton)
└── source/
    ├── conf.py                  # Sphinx config, rst_epilog substitutions
    ├── index.rst                # Main landing page
    ├── assemble_video.rst       # Assembly videos & PDF link
    ├── update_firmware.rst      # Firmware update guide (ESP32-CAM + R3 board)
    ├── faq.rst                  # Frequently asked questions
    ├── _static/
    │   ├── lang.js              # Language detection & redirect script
    │   └── video/               # 40 tutorial MP4 videos
    ├── _templates/
    │   └── layout.html          # RTD theme layout override
    ├── img/                     # General images (53 files: JPG, PNG, GIF)
    │   └── firmware/            # Firmware update screenshots
    ├── quick_start/
    │   ├── quick_start.rst            # Quick start overview (3 paths)
    │   ├── quick_start_arduino.rst    # Arduino IDE quick start
    │   ├── quick_start_robopilot.rst  # RoboPilot app quick start
    │   ├── quick_start_scratch.rst    # Scratch/Mammoth Coding quick start
    │   └── img/                       # Quick start screenshots
    ├── arduino/
    │   ├── programming_arduino.rst    # Arduino learning path overview (13 lessons)
    │   ├── lesson1_history.rst        # Lesson 1: Mars Rover history
    │   ├── lesson2_rocker_bogie.rst   # Lesson 2: Rocker-bogie system
    │   ├── lesson3_arduino_ide.rst    # Lesson 3: Arduino IDE setup
    │   ├── lesson4_motor.rst          # Lesson 4: TT motors
    │   ├── lesson5_car_move.rst       # Lesson 5: Car movement
    │   ├── lesson6_ir_avoid.rst       # Lesson 6: IR obstacle avoidance
    │   ├── lesson7_ultrasonic_avoid.rst # Lesson 7: Ultrasonic avoidance
    │   ├── lesson8_ir_ultrasonic.rst  # Lesson 8: IR + ultrasonic combined
    │   ├── lesson9_rgb_strips.rst     # Lesson 9: RGB LED strips
    │   ├── lesson10_servo.rst         # Lesson 10: Servo control
    │   ├── lesson11_camera.rst        # Lesson 11: ESP32 camera
    │   ├── lesson12_solar_panel.rst   # Lesson 12: Solar panel & battery monitoring
    │   └── img/                       # Arduino lesson images (109 files)
    ├── scratch/
    │   ├── scratch.rst                # Scratch learning path overview
    │   ├── sc1_history.rst  through sc13_all.rst  # 13 Scratch lessons
    │   ├── fun/                       # 7 standalone fun projects (no rover needed)
    │   │   ├── sc_fun_balloon.rst
    │   │   ├── sc_fun_eat_apple.rst
    │   │   ├── sc_fun_fish.rst
    │   │   ├── sc_fun_flappy_parrot.rst
    │   │   ├── sc_fun_sensitive_ball.rst
    │   │   ├── sc_fun_shooting.rst
    │   │   ├── sc_fun_tap_tile.rst
    │   │   └── img/                  # ~120 fun project screenshots
    │   └── img/                       # ~260 scratch lesson screenshots
    │       └── block/                 # Individual scratch block images
    └── hardware/
        ├── hardware.rst               # Hardware overview toctree
        ├── cpn_r3_board.rst           # SunFounder R3 board
        ├── cpn_galaxy_shield.rst      # GalaxyRVR shield
        ├── cpn_esp_32_cam.rst         # ESP32-CAM module
        ├── cpn_camera_adapter.rst     # Camera adapter board
        ├── cpn_ultrasonic_module_xh.rst  # Ultrasonic module
        ├── cpn_ir_obstacle_module.rst # IR obstacle module
        ├── cpn_rgb_strip.rst          # 4-LED RGB strip
        ├── cpn_servo.rst              # Servo motor
        ├── cpn_tt_motor_xh.rst        # TT DC motor
        ├── cpn_solar_panel.rst        # Solar panel
        ├── cpn_18650_battery.rst      # 18650 lithium battery
        └── img/                       # Hardware component images (55 files)
```

## RST Conventions

### Section markers (use in order)
```
===================   # Only for page titles (reserved)
--------------------   # Section headings
~~~~~~~~~~~~~~~~~~~~   # Subsection headings
=================      # Can be used as needed
```

### Directives
- `.. note::` — For informational callouts (NOT for Facebook community blocks — see below)
- `.. image::` — For images, always include `:width:` and/or `:align: center`
- `.. raw:: html` — Only for YouTube/video embeds. Always include fallback text.
- `.. toctree::` — For page navigation trees, use `:maxdepth: 1` or `:maxdepth: 2`
- `.. code-block:: arduino` — For Arduino code snippets
- `.. list-table::` — For formatted tables

### Cross-references
- `:ref:`target`` — Internal page references (use labels like `.. _quick_start:` on target pages)
- `:download:` — For downloadable files (local files only, not external URLs)

### Substitutions
All external links are defined in `conf.py` `rst_epilog`:
- `|link_sf_facebook|` — SunFounder Facebook community
- `|link_Mars_Rover_Kit|` / `|link_GalaxyRVR|` — Purchase link
- `|link_github_galaxyrvr|` — GitHub repository
- `|download_galaxyrvr_code|` — Code download
- `|download_galaxyrvr_filmware|` — Firmware download
- And others (see conf.py for full list)

### Video embeds
```rst
.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/example.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>
```
For YouTube: use `<iframe>` with `width="600" height="400"`.

## Facebook Community Note

The Facebook community `.. note::` block is defined once in `index.rst` between `.. start_hello_message` and `.. end_hello_message` markers. All other pages pull it in via:

```rst
.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

```
**Important:** The include block MUST be followed by a blank line before the next content (title, label, paragraph, etc.), otherwise Sphinx will error.

**When syncing to language branches that don't want this note (e.g., `docs-cn`):** simply delete the 3-line `.. include::` block from each page. Do NOT delete it from `index.rst` — there, only delete the markers and the note content.

## Terminology

| English | Usage |
|---------|-------|
| GalaxyRVR | Always one word, camelCase — never "Galaxy RVR" |
| Mars Rover | Generic term for Mars exploration vehicles |
| Arduino IDE | Arduino development environment |
| ESP32 / ESP32-CAM | Keep as-is |
| Mammoth Coding | Scratch-based coding app |
| RoboPilot | Mobile control app |
| SunFounder | Keep as-is (company name) |
| Rocker-Bogie | Suspension system name |

## Modification Workflow

1. **All changes go to `docs` (English source) first**
2. After changes are committed to `docs`, sync to language branches:
   - Copy all files from `docs` to the target language branch
   - Translate `.rst` file content (preserve ALL markup, paths, URLs)
   - **Delete the `.. include:: /index.rst` block** from every page except `index.rst` (3 lines each)
   - In `index.rst`, delete everything between `.. start_hello_message` and `.. end_hello_message`
   - Translate HTML fallback text (`Your browser does not support the video tag`)
   - **Fix title underlines**: ensure every underline is at least as long as the translated title (see "RST Title Underlines in ALL Translations")
   - **Fix list-table blocks**: verify 3-space indent + blank line after options (see "list-table Directive Format")
   - Fix language-specific config (`conf.py` project name, `lang.js` key)
   - **Fix bold markers**: ensure ASCII spaces between `**` markers and adjacent CJK characters (see below)
3. Image/video files are shared — copy as-is, no modification needed

## Syncing docs Changes to Language Branches

When `docs` (English source) has new commits after a language branch was last synced, use this incremental sync workflow instead of re-copying everything:

### Step 1: Find what changed

```bash
# Find commits in docs that the language branch doesn't have
git fetch origin docs
git log origin/<lang-branch>..origin/docs --oneline

# List all files changed in those commits
git log origin/<lang-branch>..origin/docs --oneline --name-only | grep "\.rst$\|\.png$\|\.jpg$\|\.js$\|\.py$" | sort -u
```

### Step 2: Categorize changes

| Type | Files | Action |
|------|-------|--------|
| New images/binary | `.png`, `.jpg`, `.gif`, `.mp4` | Copy directly from `docs` |
| New RST files | New `.rst` not in language branch | Copy and translate |
| Content updates | Modified `.rst` with new content | Copy from `docs`, then translate new parts |
| Format-only changes | `include` block format, BOM, whitespace | Skip if language branch uses different convention |
| Config files | `conf.py`, `lang.js`, `.gitignore` | Check diff, apply relevant changes |

### Step 3: Apply and translate

- **Images/config**: `cp` from `docs` to language branch
- **RST files with new content**: Copy the English file, translate to target language (use agents for large files in parallel)
- **Facebook note**: Language branches use inline `.. note::` block, NOT `.. include:: /index.rst`
- **Existing translations**: Use old language branch file as reference for terminology consistency
- **Build and fix**: Run `make html`, fix any title underlines or format issues

### Common patterns

- `docs` working directory: `f:\Basic Kits\Arduino Robots\GalaxyRVR\galaxy-rvr - Copy`
- Language branch working directory: `f:\Basic Kits\Arduino Robots\GalaxyRVR\galaxy-rvr`
- To switch language branches: `git checkout docs-<lang>` in the `galaxy-rvr` directory

## RST Bold Markers in CJK Translations

RST's `**bold**` syntax requires ASCII whitespace or punctuation (`.`, `,`, `:`, `)`, etc.) before the opening `**` and after the closing `**`. Chinese/CJK characters and full-width punctuation (`，`, `。`, `：`, `（`, `）`) do NOT satisfy this requirement and will cause Sphinx build warnings.

**Rule for translators:** Add an ASCII space between `**` and adjacent CJK characters:
- `中文**粗体**` → `中文 **粗体**` (space before opening `**`)
- `**粗体**中文` → `**粗体** 中文` (space after closing `**`)
- `中文**粗体**中文` → `中文 **粗体** 中文` (both sides)

This is the standard workaround for RST+CJK compatibility.

**Common mistake:** Translators often write `**text **: value` (space before closing `**`). This breaks RST parsing because the closing `**` must be immediately preceded by a non-whitespace character. Always write `**text**： value` — the space goes AFTER the closing `**`, not before.

## RST Title Underlines in CJK Translations

RST section title underlines (``===``, ``---``, ``~~~``) must be at least as long as the title text's **display width**, not its character count. CJK characters are double-width — each counts as 2 columns.

**Rule:** When writing CJK titles, make the underline roughly `(CJK_char_count × 2) + ASCII_char_count` characters long.

Example: Title `お楽しみプロジェクト4 リンゴを食べる` has 17 CJK chars + 2 ASCII chars = display width ≈ 36. The ``===`` underline must be at least 36 characters.

This also applies to inline-markup-containing titles like ``4. **クロスヘア** スプライト`` — the ``**`` markers count toward the display width.

## RST Title Underlines in ALL Translations

**Every time a title is translated, the underline must be re-checked.** Translated titles are often longer than the English original, especially in French, Spanish, German, and Italian. If the underline is shorter than the title, Sphinx will emit ``WARNING: Title underline too short.`` and the title will not render correctly.

**Rule:** Count the characters in the translated title. The underline (``===``, ``---``, ``~~~``, ``^^^``) must be **at least** as many characters as the title.

| Language | Example | Risk |
|----------|---------|------|
| English | ``Quick Start`` → ``-----------`` (11 chars each) | Baseline |
| French | ``Démarrage rapide`` → need ≥17 dashes | French titles ~30-50% longer |
| Spanish | ``Inicio rápido`` → need ≥14 dashes | Spanish titles ~20-30% longer |
| German | ``Schnellstart`` → need ≥12 dashes | German compound words can be very long |
| Italian | ``Avvio rapido`` → need ≥13 dashes | Similar expansion to French |

**Common mistake:** Translating ``Learning Objectives`` (19 chars) to ``Objectifs d'apprentissage`` (25 chars) but forgetting to lengthen the underline from 19 to ≥25 dashes.

## list-table Directive Format

The ``.. list-table::`` directive requires specific formatting that is easily broken during copy/paste or translation:

```rst
.. list-table::
   :widths: 25 25 50
   :header-rows: 1

   * - Header 1
     - Header 2
     - Header 3
   * - Row 1
     - Data
     - Value
```

**Three critical rules:**
1. Options (``:widths:``, ``:header-rows:``) and rows must be indented by **3 spaces** (not 4, not tab)
2. There MUST be a **blank line** between the last option and the first row
3. Each row's content must be indented consistently (3 spaces relative to ``*``)

**Common mistake:** Using 4-space indentation or omitting the blank line between options and rows, which causes ``ERROR: Error in "list-table" directive: invalid option block.``

## Translation Pre-Flight Checklist

Before building Sphinx after translation, verify:

1. **All title underlines** — for every ``===``, ``---``, ``~~~``, and ``^^^`` in translated files, count title chars and ensure underline ≥ title length
2. **list-table blocks** — check 3-space indent + blank line after options
3. **``.. include::`` blocks** — must be deleted from ALL files except ``index.rst``. The ``index.rst`` in language branches does NOT have ``start_hello_message`` / ``end_hello_message`` markers (the Facebook note is usually inlined instead), so any remaining include blocks will cause ``CRITICAL: Problem with "start-after" option`` errors.
4. **HTML fallback text** — translate ``Your browser does not support the video tag.``
5. **Bold markers** — for CJK languages, ensure ASCII space between ``**`` and CJK characters
6. **Substitution references** — ensure ``conf.py`` ``rst_epilog`` contains all ``|link_xxx|`` and ``|download_xxx|`` substitutions used in the translated files (missing substitutions cause ``ERROR: Undefined substitution referenced``)
7. **Duplicate labels** — avoid translating section labels like ``.. _learning_objectives:`` to the same string across multiple files. Either delete unused labels or make them unique per file (e.g., ``.. _lernziele_sc3:``)
8. **Orphan files** — delete old-structure files that are no longer in any toctree after restructuring
9. **BOM characters** — files copied with BOM (byte order mark ``﻿``) at line 1 can break ``sed`` and other text processing. Strip BOM before bulk edits

## FAQ Conventions

### Ordering logic
FAQs should follow this priority order — from most actionable/reassuring to most technical/nuclear:

1. **Why update firmware?** — explain the value FIRST so users understand the context before diving into troubleshooting
2. **Connection issues** (general → RoboPilot → Scratch) — the most common user-facing problems
3. **Compilation/upload errors** — Arduino IDE issues
4. **Configuration** (WiFi channel, AP→STA setup) — optional setup tasks
5. **Firmware operations** (update ESP32, restore R3) — how-to guides
6. **Factory reset** (ESP32 CAM) — last-resort troubleshooting

### Writing style
- Use **bold** for each checklist item's key phrase (e.g., `**Check the battery**:`)
- Use `:ref:` cross-references liberally to connect related FAQs
- Use `.. note::` blocks for important reminders (re-configuration needed, side effects, etc.)
- Each checklist item is one complete paragraph — no multi-paragraph items

### ESP32 CAM factory reset
To restore ESP32 CAM to factory settings: short **IO13** and **IO15** pins while powering on. The ESP32 CAM LED will flash twice quickly — remove the jumper at that point. After reset:
- Hotspot first appears as `AI Camera-xxxxxx` (password `12345678`)
- After reboot, changes to `GalaxyRVR-xxxxxx`
- Saved home WiFi settings are cleared — user must reconfigure

### update_firmware.rst
- The intro section should explain **why** to update (same 4 reasons as FAQ #1), not just how
- Include SunFounder Controller tip and v1 docs fallback note
- The v1 docs link is for users who prefer NOT to update — not because their product is "old"

### v1 documentation fallback
When users don't want to update firmware and prefer to keep their current configuration, link to `https://docs.sunfounder.com/projects/galaxy-rvr/en/v1/index.html`. The new docs work for all product versions; the v1 link is only for those who choose not to update.

## Known Issues (do not fix)

- `assemble_video.rst`: `:Download:` uses capital D (custom role, works with current Sphinx config)
- `hardware.rst`: `..  cpn_camera_adapter` (double-space comment, intentionally inactive)
- `update_firmware.rst`: "firware" spelling in bin file references (matches actual GitHub filenames)
- `conf.py`: `|download_galaxyrvr_filmware|` substitution name (internal only, harmless)

## File summary

| Type | Count |
|------|-------|
| `.rst` documentation files | 54 |
| `.png` images | ~400+ |
| `.jpg` images | ~60+ |
| `.mp4` videos | 40 |
| `.gif` animations | ~12 |
| `.webp` images | 2 |
| Total files | ~710 |
