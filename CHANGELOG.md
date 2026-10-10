# Changelog

## [2.0.1] - 2026-10-10

### Fixed
- A 1.4.x ESP32-CAM no longer leaves the board stuck in `setup()`. That camera generation
  only understands the legacy command set (`SSID` / `PSK` / `MODE`); with the new one it
  answered `[ERROR]` and the library ended up in `while (1)`, so the rover appeared dead
  and there was no way to update the camera (no programmer, OTA only).
- The idle LED blinks **red** while a legacy camera is detected, so the state is visible
  without a serial monitor.

### Added
- Recovery instructions on the serial port (115200): join the camera AP, open
  `http://192.168.4.1/`, upload the new camera firmware, restart the rover.
- Compile-time guard: building with `SunFounder_AI_Camera < 1.2.0` fails with a clear
  `#error`, because a stale library would look new while still hanging on a legacy camera.

### Requires
- `SunFounder_AI_Camera >= 1.2.0`

## [2.0.0] - 2026-05-21

- Switched to the Robo Pilot remote controller and added Mammoth Coding support.

Older releases: see https://github.com/sunfounder/galaxy-rvr/releases
