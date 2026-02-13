# A2DP Tiny Radio - Technical Specifications / 技術仕様書

## Overview / 概要

Compact FM radio with Bluetooth A2DP audio output, designed to be USB memory stick sized.

USBメモリサイズに設計された、Bluetooth A2DP音声出力機能付きコンパクトFMラジオ。

## Key Features / 主な機能

- FM radio reception using RDA5807M module / RDA5807Mモジュールを使用したFMラジオ受信
- Bluetooth A2DP audio output / Bluetooth A2DP音声出力
- 3.5mm earphone jack (serves as antenna) / 3.5mmイヤホンジャック（アンテナとして機能）
- 0.91" OLED display (128x32) for UI / UI用0.91インチOLEDディスプレイ（128x32）
- USB-C powered / USB-C電源
- Arduino-compatible firmware / Arduino互換ファームウェア
- Hand-solderable components only / 手はんだ可能な部品のみ

## Dimensions / 寸法

### PCB Dimensions / PCB寸法
- **PCB Length / 基板長さ**: 60mm
- **PCB Width / 基板幅**: 20mm  
- **PCB Height / 基板高さ**: ~10mm (including components / 部品を含む)

### Assembled Device Dimensions / 組立後デバイス寸法
- **Total Length / 全長**: 65mm (including case / ケースを含む)
- **Total Width / 全幅**: 24mm  
- **Total Height / 全高**: 14mm
- **Form Factor / フォームファクタ**: USB memory stick style / USBメモリスタイル

## Hardware Components / ハードウェア構成

### Main Components / 主要部品

1. **Microcontroller / マイクロコントローラ**: ATmega328P (Arduino Uno compatible / Arduino Uno互換)
   - Operating Voltage: 5V
   - Clock: 16MHz external crystal
   - Flash: 32KB
   - RAM: 2KB
   - EEPROM: 1KB

2. **FM Radio Module / FMラジオモジュール**: RDA5807M
   - Frequency Range / 周波数範囲: 50MHz - 115MHz
   - I2C Interface / I2Cインターフェース
   - Integrated LNA and power amplifier / 内蔵LNAおよび電力増幅器
   - Automatic gain control / 自動ゲイン制御
   - Package / パッケージ: QFN-20 (hand-solderable with practice / 練習すれば手はんだ可能)

3. **Bluetooth Module / Bluetoothモジュール**: JDY-64 or HC-05
   - Bluetooth 5.0 (JDY-64) or 2.0 (HC-05)
   - A2DP/AVRCP profile support / A2DP/AVRCPプロファイル対応
   - UART interface / UARTインターフェース
   - Operating Voltage / 動作電圧: 3.3V

4. **Display / ディスプレイ**: 0.91" OLED (128x32)
   - I2C Interface (SSD1306 controller) / I2Cインターフェース（SSD1306コントローラ）
   - Operating Voltage / 動作電圧: 3.3V - 5V
   - White or blue monochrome / 白または青の単色

5. **Audio Output / 音声出力**:
   - 3.5mm stereo jack / 3.5mmステレオジャック
   - Dual purpose: audio output and FM antenna / 二重機能：音声出力とFMアンテナ
   - Capacitive coupling for antenna function / アンテナ機能用容量結合

6. **Power Management / 電源管理**:
   - USB-C receptacle (power only, no data) / USB-Cレセプタクル（電源のみ、データなし）
   - 5V input / 5V入力
   - 3.3V LDO regulator (AMS1117-3.3) / 3.3V LDOレギュレータ（AMS1117-3.3）
   - Ferrite bead and capacitors for noise filtering / ノイズフィルタリング用フェライトビーズとコンデンサ

7. **User Interface / ユーザーインターフェース**:
   - 3x tactile buttons (SPST, 6mm x 6mm) / 3つのタクタイルボタン（SPST、6mm x 6mm）
     - Button 1 / ボタン1: Channel Up / チャンネルアップ
     - Button 2 / ボタン2: Channel Down / チャンネルダウン
     - Button 3 / ボタン3: Mode/Pairing / モード/ペアリング

## Power Requirements / 電力要件

- **Input / 入力**: USB-C, 5V DC
- **Typical Current / 標準電流**: 150mA
- **Peak Current / ピーク電流**: 250mA (during Bluetooth transmission / Bluetooth送信中)

## Audio Specifications / 音声仕様

- **Frequency Response / 周波数応答**: 50Hz - 15kHz
- **Signal-to-Noise Ratio / S/N比**: >50dB
- **Output Impedance / 出力インピーダンス**: 32Ω earphones recommended / 32Ωイヤホン推奨
- **Maximum Output Power / 最大出力パワー**: 30mW per channel / チャンネルあたり30mW

## FM Radio Specifications / FMラジオ仕様

- **Frequency Range / 周波数範囲**: 76MHz - 108MHz (Japan/US/EU FM band / 日本/米国/EU FMバンド)
- **Channel Spacing / チャンネル間隔**: 100kHz
- **Sensitivity / 感度**: <10dBμV
- **Selectivity / 選択度**: >50dB

## Bluetooth Specifications / Bluetooth仕様

- **Version / バージョン**: Bluetooth 2.0/5.0 (depending on module / モジュールに依存)
- **Profiles / プロファイル**: A2DP (Advanced Audio Distribution Profile)
- **Range / 通信距離**: Up to 10 meters (unobstructed) / 最大10メートル（障害物なし）
- **Codec / コーデック**: SBC (Sub-band Coding)
- **Pairing / ペアリング**: PIN-based or simple pairing / PINベースまたは簡単ペアリング

## Operating Conditions / 動作条件

- **Operating Temperature / 動作温度**: 0°C to 50°C
- **Storage Temperature / 保管温度**: -20°C to 70°C
- **Humidity / 湿度**: 10% to 90% non-condensing / 結露なし

## PCB Specifications
- **Layers**: 2-layer PCB
- **Dimensions**: 60mm x 20mm
- **Thickness**: 1.6mm
- **Copper Weight**: 1oz (35μm)
- **Surface Finish**: HASL or ENIG
- **Minimum Track Width**: 0.2mm
- **Minimum Spacing**: 0.2mm
- **Manufacturer**: Compatible with JLCPCB standards

## Compliance
- **Safety**: USB-C power supply requirements
- **EMC**: Basic filtering for USB noise reduction
- **RoHS**: Compliant (lead-free components)

## Software Features
- Automatic station scanning
- 10 preset stations (stored in EEPROM)
- Volume control via RDA5807M
- Bluetooth pairing mode
- Station frequency display
- Signal strength indicator
- Low power mode
