# GalaxyRVR

Arduino UNO firmware for the GalaxyRVR robot car, works with the SunFounder Controller APP.

Current version: **2.0.0**

- [Dev Environment](#dev-environment)
- [Quick Start](#quick-start)
- [Project Structure](#project-structure)
- [Firmware Flashing](#firmware-flashing)
- [Docs](#docs)
- [About SunFounder](#about-sunfounder)

## Dev Environment

| Item | Version |
|------|---------|
| Board | Arduino UNO |
| IDE | Arduino IDE 2.x |
| AVR Boards | 1.8.3 |

Dependencies:

- IRLremote
- SoftPWM
- Servo
- ArduinoJson
- SunFounder_AI_Camera

## Quick Start

1. Open `galaxy-rvr/galaxy-rvr.ino` in Arduino IDE
2. Select Board: Arduino UNO, pick the correct port
3. Compile and upload
4. Install SunFounder Controller APP on your phone, connect to WiFi `GalaxyRVR` (password `12345678`)

## Project Structure

```
galaxy-rvr/
├── galaxy-rvr/                   # Main firmware
│   ├── galaxy-rvr.ino            # Entry point (setup/loop/state machine/WS handler)
│   ├── galaxy-rvr.h              # Central config (pins, constants, includes)
│   ├── cmd_code_config.hpp       # Mode definitions, voice command table
│   ├── car_control.cpp/h         # Motor driver
│   ├── rgb.cpp/h                 # RGB LED strip
│   ├── ir_obstacle.cpp/h         # IR obstacle avoidance sensor
│   ├── ultrasonic.cpp/h          # Ultrasonic distance sensor
│   ├── soft_servo.cpp/h          # Software PWM servo (camera gimbal)
│   ├── battery.h                 # Battery voltage / percentage
│   └── test.h                    # Per-module test routines
├── lesson_codes/                 # Tutorial examples (by chapter)
│   ├── 5_car_move/               # Car movement
│   ├── 6_read_ir/                # IR sensor read
│   ├── 6_ir_avoid/               # IR obstacle avoidance
│   ├── 7_read_ultrasonic/        # Ultrasonic read
│   ├── 7_ultrasonic_avoid/       # Ultrasonic avoidance
│   ├── 8_ultrasonic_ir_avoid/    # Ultrasonic + IR avoidance
│   ├── 8_ultrasonic_ir_follow/   # Ultrasonic + IR follow
│   ├── 9_rgb_*/                  # RGB LED control
│   ├── 10_servo*/                # Servo control
│   ├── 11_camera_*/              # Camera control
│   ├── 12_app_*/                 # APP interaction
│   └── 13_*battery*/             # Battery monitoring
├── test/
│   └── electric-test/            # Factory electrical test
├── ai-camera-firmware.v1.5.3-ota.bin  # ESP32-CAM firmware image
├── update-arduino-firmware.bat    # One-click flash script (Windows)
├── LICENSE
└── Readme.md
```

## Firmware Flashing

### Option 1: One-click script (Windows)

```bat
update-arduino-firmware.bat
```

The script uses `avrdude` to flash `galaxy-rvr.ino.2.0.0.hex`.

### Option 2: Arduino IDE

Open `galaxy-rvr/galaxy-rvr.ino`, compile and upload.

### ESP32-CAM firmware

The AI Camera module requires its own firmware. See [ai-camera-firmware](https://github.com/sunfounder/ai-camera-firmware) for source and instructions.

## Docs

https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/

## About SunFounder

SunFounder focuses on STEAM education with open-source robots, dev boards, kits, and modules. We help students and hobbyists learn programming and engineering through hands-on practice.

Website: [www.sunfounder.com](https://www.sunfounder.com)

Contact: [service@sunfounder.com](mailto:service@sunfounder.com)
