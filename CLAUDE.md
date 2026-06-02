# GalaxyRVR 日本語ドキュメント

このプロジェクトは GalaxyRVR 英語ドキュメントの**日本語翻訳版**です。すべての内容変更はまず英語の `docs` ブランチで行い、その後このブランチに同期してください。

## 同期フロー

1. 英語 `docs` ブランチで変更を完了しコミットする
2. `docs` からすべてのファイルをこのブランチにコピーする
3. `.rst` ファイルの内容を翻訳する
4. 日本語のフォーマットと用語ルールを適用する

## 翻訳ルール

### 保持すべきもの（変更不可）
- すべての RST マークアップ：`.. note::`、`.. image::`、`.. toctree::`、`.. raw:: html`、`.. code-block::` などのディレクティブ
- すべての画像パス、URL、ファイルパス — 一切変更しない
- すべての RST セクションマーカー（`===`、`---`、`~~~` など）
- すべてのコードブロックの内容（Arduino コードなど）
- すべての置換参照（`|link_xxx|`、`|download_xxx|`）
- すべての相互参照（`:ref:`target``）

### 翻訳しないもの
- `SunFounder`、`GalaxyRVR`、`Arduino`、`ESP32`、`Raspberry Pi` などのブランド/製品名
- コード内の関数名、変数名、ピン番号
- ファイル名とファイルパス

### ⚠️ RST 太字マーカーと日本語の互換性（重要）

RST の `**太字**` 構文は、開始 `**` の前と終了 `**` の後に ASCII スペースまたは句読点（`.`、`,`、`:`、`）` など）が必要です。日本語の文字や全角句読点（`、`、`。`、`：`、`（`、`）`）はこの要件を満たさず、Sphinx ビルド警告 `Inline strong start-string without end-string` を引き起こします。

**翻訳時には必ず** `**` と隣接する日本語文字の間に ASCII スペースを追加してください：
- `日本語**太字**` → `日本語 **太字**`（開始 `**` の前にスペース）
- `**太字**日本語` → `**太字** 日本語`（終了 `**` の後にスペース）

既存の ASCII スペースや行頭/行末の `**` には追加の対処は不要です。

**よくあるミス：** `**テキスト **: 値` のように閉じ `**` の前にスペースを入れてしまうこと。閉じ `**` の直前は非空白文字でなければならないため、RST が解析できません。正しくは `**テキスト**： 値` — スペースは閉じ `**` の**後**に入れます。

### ⚠️ RST タイトル下線と CJK 表示幅（重要）

RST のセクションタイトル下線（``===``, ``---``, ``~~~``）は、タイトル文字列の**表示幅**以上である必要があります。日本語文字は全角（2カラム幅）としてカウントされます。

**ルール：** 下線の長さ ≧ `(全角文字数 × 2) + 半角文字数`

例：`お楽しみプロジェクト4 リンゴを食べる`（全角17文字 + 半角2文字 = 表示幅約36）→ `===` 下線は最低36文字必要。

インラインマークアップ（``**`` など）を含むタイトルも、``**`` マーカーが表示幅にカウントされます。

### 日本語フォーマット
- 日本語の句読点を使用：、。！？「」『』
- 技術文書には丁寧体（です/ます）を使用する
- 用語の統一性を保つ

### 削除するもの

- ファイル先頭の Facebook コミュニティ `.. note::` ブロック。英語ソースは `.. include:: /index.rst` で参照しているので、同期時に各ページ先頭の3行の include ブロックを削除するだけです：

  ```rst
  .. include:: /index.rst
     :start-after: start_hello_message
     :end-before: end_hello_message
  ```

  また、`index.rst` 内の `.. start_hello_message` と `.. end_hello_message` の間の内容も削除してください。

### 翻訳が必要なもの
- HTML 動画フォールバックテキスト：`Your browser does not support the video tag.` → `お使いのブラウザはこのビデオタグをサポートしていません。`

### 設定ファイルの変更
- `conf.py`：`project` を `'SunFounder GalaxyRVR Arduinoキット'` に変更
- `_static/lang.js`：日本語エントリのキーは `'ja'`（既に存在するはず）

## 用語対照表

| 英語 | 日本語 |
|------|--------|
| Arduino IDE | Arduino IDE（保持） |
| Assemble / Assembly | 組み立て |
| Battery | バッテリー |
| Block (Scratch) | ブロック |
| Camera | カメラ |
| Code | コード |
| Component | コンポーネント |
| Download | ダウンロード |
| Firmware | ファームウェア |
| GalaxyRVR | GalaxyRVR（保持） |
| Hardware | ハードウェア |
| Infrared / IR | 赤外線 |
| Learning Objectives / Goals | 学習目標 |
| Lesson | レッスン |
| Mars Rover | マーズローバー |
| Materials | 必要な材料 |
| Module | モジュール |
| Motor | モーター |
| Obstacle Avoidance | 障害物回避 |
| Pin / Pinout | ピン / ピン配置 |
| Play Mode | プレイモード |
| Programming | プログラミング |
| Quick Start | クイックスタート |
| RGB Strip | RGBストリップ |
| RoboPilot | RoboPilot（保持） |
| Rocker-Bogie | ロッカーボギー |
| Scratch | Scratch（保持） |
| Sensor | センサー |
| Servo | サーボ |
| Shield | シールド |
| Solar Panel | ソーラーパネル |
| Sprite | スプライト |
| Stage | ステージ |
| Steps | 手順 |
| Ultrasonic | 超音波 |
| Upload | アップロード |

## ディレクトリ構造

英語 `docs` と完全に同一です。詳細は英語版の CLAUDE.md を参照してください。
