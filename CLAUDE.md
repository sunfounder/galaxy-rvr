# GalaxyRVR Docs Translation (docs → docs-it)

## Branch 说明

- `docs` 分支：英文源文档（galaxy-rvr - Copy）
- `docs-it` 分支：意大利语翻译（galaxy-rvr）

## 翻译流程

### 1. 复制文档

从 `docs` 分支复制到 `docs-it` 分支：

```powershell
Copy-Item -Path "f:\Basic Kits\Arduino Robots\GalaxyRVR\galaxy-rvr - Copy\docs" -Destination "f:\Basic Kits\Arduino Robots\GalaxyRVR\galaxy-rvr\docs" -Recurse -Force
```

### 2. 翻译规则

- **翻译**：所有 RST 文件中的英文文本 → 意大利语
- **保留**：RST 指令（`.. image::`、`.. note::`、`.. code-block::` 等）、文件路径、URL、代码块、图片引用、RST 标签
- **保留**：产品名（GalaxyRVR、Arduino、ESP32-CAM、SunFounder 等）
- **保留**：技术术语（PWM、GPIO、I2C、servo、LED、IR、RGB 等）
- **修复**：标题下划线长度必须 ≥ 标题文字长度

### 3. 翻译范围（54 个 RST 文件）

| 目录 | 文件数 | 内容 |
|------|--------|------|
| `source/` | 5 | index、faq、assemble_video、update_firmware、conf.py |
| `source/arduino/` | 13 | programming_arduino + 12 课 |
| `source/scratch/` | 14 | scratch + sc1~sc13 |
| `source/scratch/fun/` | 7 | 趣味 Scratch 项目 |
| `source/hardware/` | 12 | 所有硬件模块说明 |
| `source/quick_start/` | 4 | 快速入门（RoboPilot/Arduino/Scratch） |

### 4. 额外翻译文件

- `conf.py` — Sphinx 配置注释
- `lang.js` — 已包含意大利语字符串
- `layout.html` — 无需翻译

### 5. 修复 RST 下划线

翻译后标题变长，下划线需要相应延长。使用 Python 脚本批量修复：

```python
# 自动检测并修复所有 RST 文件中标题下划线长度不足的问题
# 规则：下划线（===、---、~~~、^^^）长度必须 ≥ 标题文字长度
```

修复了 29 个文件中的下划线问题。

### 6. 统一翻译术语

- “Learning Objectives” → "Obiettivi di apprendimento"
- “Course Objectives” → "Obiettivi del corso"
- “Materials” / “Materials Needed” → "Materiali" / "Materiali necessari"
- “Steps” / “Course Steps” → "Procedura" / "Procedura del corso"
- “Overview” → "Panoramica"
- “Summary and Reflection” → "Riepilogo e riflessione"
- “SunFounder community header” → 统一翻译为意大利语版本（见 index.rst）
- “Quick Play” → "Gioco Rapido"
- “Download the Code” → "Scarica il codice"

### 7. 注意事项

- 不要翻译代码块中的注释（保持英文）
- 不要翻译 RST 指令中的参数
- 列表表（list-table）中的技术术语保持英文
- 如果日后需要新增其他语言，可参照此流程
