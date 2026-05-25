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

- 当前开发分支（默认分支）跟随最新大版本线，如 `v2`
- 旧版本分支仅修紧急 bug，新功能在主线分支开发
- 分支编号匹配大版本号 A
- 禁止引用 `main` 分支作为依赖

## 发布流程

```bash
git checkout v2
git pull origin v2
git tag 2.0.0
git push origin 2.0.0
```

分发时通过 tag 引用：`@2.0.0`，或通过分支引用自动获取兼容修复：`@v2`
