# GalaxyRVR

Arduino UNO 固件项目，控制 GalaxyRVR 机器人小车。通过 ESP32-CAM 与 SunFounder Controller APP 通信，支持 APP 遥控、红外/超声波避障、红外跟随等模式。

## 构建

- **Board**: Arduino UNO
- **IDE**: Arduino IDE 2.x
- **编译器工具**: Arduino AVR Boards 1.8.3

依赖库：`IRLremote`, `SoftPWM`, `ArduinoJson`, `SunFounder_AI_Camera`

项目在仓库根目录 `galaxy-rvr/` 子目录下（库例代码结构），打开 `galaxy-rvr/galaxy-rvr.ino` 编译烧录。

## 架构

```
galaxy-rvr.ino          — 主程序（setup, loop, 状态机, WS 消息处理）
galaxy-rvr.h            — 中心头文件（引用所有模块，集中配置 pin/常量）
cmd_code_config.hpp     — 模式定义、语音指令表、指令回调表
car_control.cpp/h       — 电机驱动（前进/后退/左转/右转/停止）
rgb.cpp/h               — RGB LED 灯带控制（含预设颜色）
ir_obstacle.cpp/h       — 红外避障传感器
ultrasonic.cpp/h        — 超声波测距 + 避障判定
soft_servo.cpp/h        — 软件 PWM 舵机（摄像头云台）
battery.h               — 电池电压/电量检测
test.h                  — 各模块测试函数
```

### 状态机

主控状态：`STATE_IDLE`（等待 APP 连接, LED 闪烁）→ `STATE_APP`（已连接, 进入模式处理）

模式：`MODE_APP_CONTROL` / `MODE_OBSTACLE_AVOIDANCE` / `MODE_OBSTACLE_FOLLOWING`

APP 通过 WebSocket 发送控制帧（`onReceive()`），格式为 entity ID + 数据，entity 包括：马达 0x01、RGB 0x02、舵机 0x03、前灯 0x04、避障模式 0x05。

## 版本号

```
A . B . C
│   │   └── 小 Bug 修复，向下兼容
│   └────── 向下兼容的小版本更新
└────────── 不向下兼容的大版本更新
```

- `VERSION` 宏定义在 `galaxy-rvr/galaxy-rvr.ino` 中
- 每次发布必须打 tag，格式 `A.B.C`

## Git 分支

- `main` = 当前发布分支（v2 已合并，v1 保留在 `v1` 分支作为备份）
- 大版本开发在 `vN` 分支（如 `v3`），通过 PR 合并到 `main`
- 旧版本分支仅修紧急 bug，新功能在对应大版本分支开发
- 分支编号匹配大版本号 A

## 发布流程

```bash
# 1. 开发分支发 PR 到 main
git checkout v2
# ... develop, commit, push ...
gh pr create --title "Release v2.0.0" --body "..."

# 2. PR 合并后，在 main 上打 tag
git checkout main
git pull origin main
git tag 2.0.0
git push origin 2.0.0

# 3. 创建/更新 GitHub Release（见上方 "发布 GitHub Release"）
```

分发时通过 tag 引用：`@2.0.0`，或通过分支引用自动获取兼容修复：`@v2`（大版本分支保留，不删除）

## Release 产物 (`output/`)

`output/` 目录存放发布附件，随 GitHub Release 打包为 zip：

| 文件 | 说明 |
|------|------|
| `galaxy-rvr.ino.X.Y.Z.hex` | Arduino UNO 固件（不含 bootloader） |
| `galaxy-rvr.ino.X.Y.Z.with_bootloader.hex` | 含 bootloader 的完整固件 |
| `ai-camera-firmware.v*.*.*-ota.bin` | ESP32-CAM AI 摄像头 OTA 固件（来自 `ai-camera-firmware` 项目，方便用户一次下载无需多处获取） |
| `avrdude.exe` / `avrdude.conf` | Windows 烧录工具（已自带） |
| `update-arduino-firmware.bat` | Windows 烧录脚本 |
| `update-arduino-firmware-mac.sh` | macOS 烧录脚本 |
| `update-arduino-firmware-linux.sh` | Linux 烧录脚本 |

### 烧录脚本依赖

- **Windows**: `avrdude.exe` 和 `avrdude.conf` 已打包在 output 中，无需额外安装
- **macOS**: 需先安装 avrdude — `brew install avrdude`
- **Linux**: 需先安装 avrdude — `apt install avrdude`（Debian/Ubuntu）或 `dnf install avrdude`（Fedora）；**注意**用户需在 `dialout` 组：`sudo usermod -a -G dialout $USER`

所有脚本逻辑相同：列出可用串口 → 用户选择 → `avrdude -p atmega328p -c arduino -P <port> -D -U flash:w:<hex>:a`

## 发布 GitHub Release

```bash
# 0. 清理 output 中残留的旧 zip，避免嵌套打包
rm output/*.zip 2>/dev/null

# 1. 创建/更新 output zip
powershell -Command "Compress-Archive -Path output\* -DestinationPath galaxy-rvr.ino.X.Y.Z.zip -Force"

# 2. 删除旧 asset（如有）
gh api repos/sunfounder/galaxy-rvr/releases/tags/X.Y.Z --jq '.assets[].id'
gh api -X DELETE repos/sunfounder/galaxy-rvr/releases/assets/<asset-id>

# 3. 上传新 zip
gh release upload X.Y.Z galaxy-rvr.ino.X.Y.Z.zip --clobber
```

Release Notes 使用英文撰写，结构：Core Upgrade → Breaking Changes → Features → Bug Fixes → Firmware Update

## v2 核心特性

- **Robo Pilot 遥控器**: 替代 SunFounder Controller APP，提供更流畅的遥控体验
- **Mammoth Coding**: 兼容图形化编程平台（Scratch 体系）
