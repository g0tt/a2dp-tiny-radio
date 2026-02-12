# A2DP Tiny Radio

A compact FM radio with Bluetooth A2DP audio output, designed in a USB memory stick form factor.

![Project Status](https://img.shields.io/badge/status-design%20complete-green)
![License](https://img.shields.io/badge/license-MIT-blue)
![Hardware](https://img.shields.io/badge/hardware-Arduino%20compatible-orange)

## 概要 (Overview)

超小型FMラジオで、Bluetooth A2DPとイヤホンジャックから音声出力が可能です。USBメモリサイズの筐体に、RDA5807Mラジオチップ、ATmega328Pマイコン、Bluetoothモジュール、小型OLEDディスプレイを搭載しています。

A pocket-sized FM radio with Bluetooth A2DP audio output. Features RDA5807M FM receiver, ATmega328P microcontroller, Bluetooth module, and small OLED display in a USB memory stick form factor.

## 主な機能 (Key Features)

- 📻 **FM Radio Reception**: RDA5807M chip, 76-108MHz
- 📡 **Bluetooth A2DP Output**: Stream radio to wireless headphones/speakers
- 🎧 **3.5mm Audio Jack**: Wired output + antenna function
- 📺 **OLED Display**: 128x32 pixels, frequency and status display
- 🔘 **3-Button Control**: Channel up/down, mode/pairing
- 🔌 **USB-C Powered**: No battery needed, universal power
- 📦 **Compact Size**: 65mm x 24mm x 14mm (USB stick size)
- 🛠️ **Arduino Compatible**: Easy to program and customize

## 仕様 (Specifications)

### Hardware
- **Microcontroller**: ATmega328P @ 16MHz (Arduino Uno compatible)
- **FM Receiver**: RDA5807M (50-115MHz capable, configurable for 76-108MHz)
- **Bluetooth**: JDY-64 (BT 5.0, A2DP profile)
- **Display**: 0.91" OLED (SSD1306, 128x32, I2C)
- **Power**: USB-C input, 5V, 150mA typical, 250mA peak
- **Audio**: 3.5mm stereo jack (dual purpose: output + FM antenna)

### Dimensions
- Length: 65mm (including connectors)
- Width: 24mm
- Height: 14mm
- Weight: ~15g (with case)

## プロジェクト構成 (Repository Structure)

```
a2dp-tiny-radio/
├── docs/
│   ├── SPECIFICATIONS.md           # 技術仕様書 (Technical specs)
│   ├── ASSEMBLY_GUIDE.md          # 組み立て手順 (Assembly instructions)
│   └── APPEARANCE_AND_DIMENSIONS.md # 外観・寸法 (Appearance & dimensions)
├── hardware/
│   ├── BOM.md                     # 部品表 (Bill of Materials)
│   ├── schematics/
│   │   └── SCHEMATIC_DESCRIPTION.md # 回路図説明 (Circuit description)
│   └── pcb/
│       └── PCB_DESIGN_GUIDE.md    # PCB設計ガイド (PCB design guide)
├── firmware/
│   ├── a2dp_fm_radio/
│   │   └── a2dp_fm_radio.ino      # Arduino firmware
│   └── README.md                   # ファームウェアドキュメント
├── case/
│   └── CASE_DESIGN_GUIDE.md       # ケース設計ガイド (Case design guide)
└── README.md                       # このファイル (This file)
```

## 使い方 (Usage)

### 基本操作 (Basic Operation)

1. **電源を入れる (Power On)**
   - USB-Cケーブルを接続 (Connect USB-C cable)
   - 電源LEDが点灯 (Power LED illuminates)

2. **選局 (Tuning)**
   - CH+ボタン: 周波数を上げる (Increase frequency)
   - CH-ボタン: 周波数を下げる (Decrease frequency)
   - 長押し: 自動スキャン (Long press for auto-scan)

3. **Bluetooth接続 (Bluetooth Connection)**
   - MODEボタンを2秒長押し (Long press MODE for 2 seconds)
   - スマホのBluetooth設定で"FMRadio"を選択
   - Select "FMRadio" in phone's Bluetooth settings
   - 接続完了後、ラジオ音声がBluetoothで出力
   - Radio audio streams via Bluetooth

4. **イヤホン出力 (Wired Output)**
   - 3.5mmジャックにイヤホンを接続
   - Connect earphones to 3.5mm jack
   - イヤホンはFMアンテナとしても機能
   - Earphone cable also serves as FM antenna

### ボタン機能 (Button Functions)

| ボタン | 短押し | 長押し |
|--------|--------|--------|
| CH+ | 周波数 +0.1MHz | 上方向スキャン |
| CH- | 周波数 -0.1MHz | 下方向スキャン |
| MODE | モード切替 | Bluetoothペアリング |

| Button | Short Press | Long Press |
|--------|-------------|------------|
| CH+ | Frequency +0.1MHz | Scan upward |
| CH- | Frequency -0.1MHz | Scan downward |
| MODE | Toggle mode | Bluetooth pairing |

## 製作方法 (Building Instructions)

### 必要なもの (Requirements)

#### ハードウェア (Hardware)
- PCB (JLCPCB等で製造 / Manufactured by JLCPCB, etc.)
- 部品一式 (hardware/BOM.md参照 / See hardware/BOM.md)
- はんだごて、工具類 (Soldering iron, tools)

#### ソフトウェア (Software)
- Arduino IDE 1.8.x or later
- Required libraries:
  - Adafruit GFX Library
  - Adafruit SSD1306
  - Wire (built-in)
  - EEPROM (built-in)

### 組み立て手順 (Assembly Steps)

1. **PCB製造 (PCB Fabrication)**
   - Gerberファイルを作成 (Generate Gerber files)
   - JLCPCBにアップロードして発注 (Upload to JLCPCB)

2. **部品実装 (Component Assembly)**
   - 詳細は`docs/ASSEMBLY_GUIDE.md`参照
   - See `docs/ASSEMBLY_GUIDE.md` for details
   - 小さい部品から順に実装 (Start with smallest components)
   - はんだ付け後、動作確認 (Test after soldering)

3. **ファームウェア書き込み (Firmware Programming)**
   - Arduino IDEで`firmware/a2dp_fm_radio/a2dp_fm_radio.ino`を開く
   - 必要なライブラリをインストール
   - ボードは"Arduino Uno"を選択
   - コンパイル・書き込み実行

4. **ケース製作 (Case Fabrication - Optional)**
   - 3Dプリンタで出力 (3D print case)
   - STLファイルは`case/`フォルダ内 (in case/ folder)
   - PLA, PETG, ABS等で印刷可能

5. **最終組み立て (Final Assembly)**
   - 動作確認後、ケースに収納
   - Assemble in case after testing

## ドキュメント (Documentation)

### 技術文書 (Technical Documents)
- [技術仕様書 / Technical Specifications](docs/SPECIFICATIONS.md)
- [回路図説明 / Circuit Description](hardware/schematics/SCHEMATIC_DESCRIPTION.md)
- [部品表 / Bill of Materials](hardware/BOM.md)
- [PCB設計ガイド / PCB Design Guide](hardware/pcb/PCB_DESIGN_GUIDE.md)
- [外観・寸法 / Appearance & Dimensions](docs/APPEARANCE_AND_DIMENSIONS.md)

### 組み立て・使用 (Assembly & Usage)
- [組み立てガイド / Assembly Guide](docs/ASSEMBLY_GUIDE.md)
- [ファームウェア説明 / Firmware Documentation](firmware/README.md)
- [ケース設計 / Case Design Guide](case/CASE_DESIGN_GUIDE.md)

## トラブルシューティング (Troubleshooting)

### ディスプレイが表示されない (Display Not Working)
- 3.3V電源を確認 (Check 3.3V power)
- I2C接続を確認 (Verify I2C connections)
- I2Cアドレスをスキャン (Run I2C scanner)

### FM受信できない (No FM Reception)
- イヤホンを接続（アンテナとして必要）
- Connect earphones (required as antenna)
- 強い局で試す (Try strong local station)
- 水晶振動子の実装を確認 (Check crystal soldering)

### Bluetooth接続できない (Bluetooth Won't Connect)
- ペアリングモードに入る (Enter pairing mode)
- 3.3V電源を確認 (Check 3.3V power)
- UART接続を確認 (Verify UART connections)

詳細は [組み立てガイド / Assembly Guide](docs/ASSEMBLY_GUIDE.md) のトラブルシューティング章を参照

## ライセンス (License)

MIT License - 詳細はLICENSEファイル参照

Copyright (c) 2026 A2DP Radio Project

## 貢献 (Contributing)

プルリクエスト、Issue報告を歓迎します。
Pull requests and issue reports are welcome!

### 改善案 (Improvement Ideas)
- RDS（ラジオデータシステム）対応
- RDS (Radio Data System) support
- プリセット局の拡張
- More preset stations
- バッテリー駆動オプション
- Battery power option
- ステレオインジケータ
- Stereo indicator
- 音量調整機能
- Volume control

## 参考資料 (References)

### データシート (Datasheets)
- [RDA5807M FM Radio Receiver](https://www.sparkfun.com/datasheets/Wireless/General/RDA5807M.pdf)
- [ATmega328P Microcontroller](https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328P-Datasheet.pdf)
- [SSD1306 OLED Display](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)

### 関連リンク (Related Links)
- [Arduino Official Site](https://www.arduino.cc/)
- [JLCPCB PCB Service](https://jlcpcb.com/)
- [Adafruit Learning System](https://learn.adafruit.com/)

## 謝辞 (Acknowledgments)

このプロジェクトは以下のオープンソースライブラリを使用しています：
- Adafruit GFX & SSD1306 libraries
- Arduino Core libraries

## 連絡先 (Contact)

- GitHub Issues: バグ報告、機能要望
- Discussions: 質問、アイデア共有

---

**注意 (Note)**: このプロジェクトはDIY電子工作プロジェクトです。組み立てには基礎的なはんだ付けスキルが必要です。
This is a DIY electronics project. Basic soldering skills are required for assembly.

**免責事項 (Disclaimer)**: 製作・使用は自己責任で行ってください。
Build and use at your own risk.
