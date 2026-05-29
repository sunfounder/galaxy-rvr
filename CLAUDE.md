# GalaxyRVR 中文文档

此项目为 GalaxyRVR 英文文档的**中文翻译版本**。所有内容修改请先在英文 `docs` 分支进行，然后同步到此分支。

## 同步流程

1. 英文 `docs` 分支完成修改并提交
2. 将 `docs` 中的所有文件复制到此分支
3. 翻译 `.rst` 文件内容
4. 应用中文格式和用词规范

## 翻译规则

### 必须保留（不可修改）
- 所有 RST 标记：`.. note::`、`.. image::`、`.. toctree::`、`.. raw:: html`、`.. code-block::` 等指令
- 所有图片路径、URL、文件路径——完全不变
- 所有 RST 节标题标记（`===`、`---`、`~~~` 等）
- 所有代码块内容（Arduino 代码等）
- 所有替换引用（`|link_xxx|`、`|download_xxx|`）
- 所有交叉引用（`:ref:`target``）

### 不应翻译的内容
- `SunFounder`、`GalaxyRVR`、`Arduino`、`ESP32`、`Raspberry Pi` 等品牌/产品名
- 代码中的函数名、变量名、引脚号
- 文件名和文件路径

### ⚠️ RST 粗体标记与中文的兼容性（重要）

RST 的 `**粗体**` 语法要求开始 `**` 前和结束 `**` 后必须是 ASCII 空格或英文标点（如 `.`, `,`, `:`, `)` 等）。中文文字和全角标点（`，`、`。`、`：`、`（`、`）`）不符合此要求，会导致 Sphinx 编译警告 `Inline strong start-string without end-string`。

**翻译时必须**在 `**` 与相邻中文字符之间添加 ASCII 空格：
- `中文**粗体**` → `中文 **粗体**`（开始 `**` 前加空格）
- `**粗体**中文` → `**粗体** 中文`（结束 `**` 后加空格）

无需在 `**` 与已存在的 ASCII 空格或行首/行尾之间额外处理。

### 中文格式规范
- 使用中文标点符号：，、。！？：；""''【】《》
- 术语翻译需保持一致

### 要删除的内容

- 文件开头的 Facebook 社区 `.. note::` 块。英文源使用 `.. include:: /index.rst` 方式引用，同步时直接删除每个页面开头的 3 行 include 块即可：

  ```rst
  .. include:: /index.rst
     :start-after: start_hello_message
     :end-before: end_hello_message
  ```

  同时删除 `index.rst` 中 `.. start_hello_message` 和 `.. end_hello_message` 之间的内容。

### 要翻译的内容
- HTML 视频后备文本：`Your browser does not support the video tag.` → `您的浏览器不支持此视频标签。`

### 配置文件修改
- `conf.py`：将 `project` 改为 `'SunFounder GalaxyRVR Arduino 套件'`
- `_static/lang.js`：中文条目的 key 应为 `'zh-cn'`（不是 `'en'`）

## 术语对照表

| 英文 | 中文 |
|------|------|
| Arduino IDE | Arduino IDE（保留） |
| Assemble / Assembly | 组装 |
| Battery | 电池 |
| Block (Scratch) | 积木块 |
| Camera | 摄像头 |
| Code | 代码 |
| Component | 组件 |
| Download | 下载 |
| Firmware | 固件 |
| GalaxyRVR | GalaxyRVR（保留） |
| Hardware | 硬件 |
| Infrared / IR | 红外 |
| Learning Objectives / Goals | 学习目标 |
| Lesson | 课程 |
| Mars Rover | 火星车 |
| Materials | 所需材料 |
| Module | 模块 |
| Motor | 电机 |
| Obstacle Avoidance | 避障 |
| Pin / Pinout | 引脚 / 引脚图 |
| Play Mode | Play模式 |
| Programming | 编程 |
| Quick Start | 快速入门 |
| RGB Strip | RGB灯带 |
| RoboPilot | RoboPilot（保留） |
| Rocker-Bogie | 摇臂转向架 |
| Scratch | Scratch（保留） |
| Sensor | 传感器 |
| Servo | 舵机 |
| Shield | 扩展板 |
| Solar Panel | 太阳能板 |
| Sprite | 精灵 |
| Stage | 舞台 |
| Steps | 步骤 |
| Ultrasonic | 超声波 |
| Upload | 上传 |

## 目录结构

与英文 `docs` 完全一致，详见英文版的 CLAUDE.md。
