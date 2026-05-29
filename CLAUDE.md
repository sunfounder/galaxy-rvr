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
   - Remove Facebook community note blocks
   - Translate HTML fallback text (`Your browser does not support the video tag`)
   - Fix language-specific config (`conf.py` project name, `lang.js` key)
   - **Fix bold markers**: ensure ASCII spaces between `**` markers and adjacent CJK characters (see below)
3. Image/video files are shared — copy as-is, no modification needed

## RST Bold Markers in CJK Translations

RST's `**bold**` syntax requires ASCII whitespace or punctuation (`.`, `,`, `:`, `)`, etc.) before the opening `**` and after the closing `**`. Chinese/CJK characters and full-width punctuation (`，`, `。`, `：`, `（`, `）`) do NOT satisfy this requirement and will cause Sphinx build warnings.

**Rule for translators:** Add an ASCII space between `**` and adjacent CJK characters:
- `中文**粗体**` → `中文 **粗体**` (space before opening `**`)
- `**粗体**中文` → `**粗体** 中文` (space after closing `**`)
- `中文**粗体**中文` → `中文 **粗体** 中文` (both sides)

This is the standard workaround for RST+CJK compatibility.

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
