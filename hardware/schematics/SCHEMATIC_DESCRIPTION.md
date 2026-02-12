# A2DP Tiny Radio - Circuit Diagram Description / 回路図説明

## Circuit Overview / 回路概要

This document describes the schematic design for the A2DP Tiny Radio. For the actual schematic files, see the KiCad project in `hardware/schematics/`.

このドキュメントは、A2DP Tiny Radioの回路図設計について説明します。実際の回路図ファイルについては、`hardware/schematics/`のKiCadプロジェクトを参照してください。

## Power Supply Section / 電源セクション

### USB-C Input / USB-C入力

```
USB-C (J1) → D1 (SS34) → L1 (Ferrite) → C13 (47μF) → 5V Rail / 5Vレール
                                      ↓
                                   GND Rail / GNDレール
```

**Components / 部品:**
- J1: USB-C receptacle (power-only sink: VBUS, GND, CC1, CC2) / USB-Cレセプタクル（電源専用シンク：VBUS、GND、CC1、CC2）
- D1: Schottky diode (reverse polarity protection) / ショットキーダイオード（逆極性保護）
- L1: Ferrite bead (noise filtering) / フェライトビーズ（ノイズフィルタリング）
- C13: Bulk capacitor (power supply smoothing) / バルクコンデンサ（電源平滑化）
- R10, R11: 5.1kΩ resistors (CC pull-down, Rd) / 5.1kΩ抵抗器（CCプルダウン、Rd）

**Notes / 注記:**
- USB-C CC1 and CC2 pins each connected to GND through 5.1kΩ pull-down resistors (Rd) for default 5V sink configuration / USB-CのCC1とCC2ピンはそれぞれ5.1kΩプルダウン抵抗（Rd）を介してGNDに接続し、デフォルトの5Vシンク構成とする
- Ferrite bead filters high-frequency noise from USB / フェライトビーズはUSBからの高周波ノイズをフィルタリング
- Schottky diode provides low voltage drop protection / ショットキーダイオードは低電圧降下保護を提供

### 3.3V Regulator / 3.3Vレギュレータ

```
5V → U4 (AMS1117-3.3) → C10 (10μF) → 3.3V Rail / 3.3Vレール
            ↓ GND
```

**Components / 部品:**
- U4: AMS1117-3.3 LDO regulator (SOT-223) / LDOレギュレータ
- C9: 10μF input capacitor / 入力コンデンサ
- C10: 10μF output capacitor / 出力コンデンサ

**Notes / 注記:**
- Provides 3.3V for Bluetooth module and OLED / BluetoothモジュールとOLED用の3.3Vを供給
- 800mA maximum current capability / 最大電流容量800mA
- Dropout voltage: ~1.2V / ドロップアウト電圧：約1.2V

## Microcontroller Section (ATmega328P) / マイクロコントローラセクション（ATmega328P）

### Power and Clock / 電源とクロック
```
ATmega328P (U1):
- VCC, AVCC → 5V (via C1, C2: 100nF)
- GND, AGND → GND
- XTAL1, XTAL2 → Y1 (16MHz) with C7, C8 (22pF to GND)
- RESET → SW4 (optional / オプション) + R1 (10kΩ pull-up to 5V / 5Vへプルアップ)
```

**Components / 部品:**
- U1: ATmega328P-AU (TQFP-32)
- Y1: 16MHz crystal / 16MHz水晶振動子
- C1, C2: 100nF decoupling capacitors / 100nFデカップリングコンデンサ
- C7, C8: 22pF load capacitors for crystal / 水晶用22pF負荷コンデンサ
- R1: 10kΩ reset pull-up / 10kΩリセットプルアップ

### ISP Programming Header (Optional) / ISPプログラミングヘッダ（オプション）
```
J3 (2x3 header / 2x3ヘッダ):
Pin 1: MISO → PB4 (U1 pin 18)
Pin 2: VCC → 5V
Pin 3: SCK → PB5 (U1 pin 19)
Pin 4: MOSI → PB3 (U1 pin 17)
Pin 5: RESET → RESET (U1 pin 1)
Pin 6: GND → GND
```

## FM Radio Section (RDA5807M)

### Connections / 接続
```
RDA5807M (U2):
- VCC → 3.3V (via C3: 100nF)
- GND → GND
- SDA → PC4/SDA (U1 pin 27, A4) + R4 (4.7kΩ to 3.3V)
- SCL → PC5/SCL (U1 pin 28, A5) + R5 (4.7kΩ to 3.3V)
- RCLK → Y2 (32.768kHz crystal)
- LOUT, ROUT → J2 (3.5mm jack) via C11, C12 (1μF coupling)
- ANTENNA → J2 (3.5mm jack ring/tip)
```

**Components / 部品:**
- U2: RDA5807M FM receiver / FMラジオ受信機
- Y2: 32.768kHz crystal (for RDA5807M internal clock) / 32.768kHz水晶振動子（RDA5807M内部クロック用）
- C3: 100nF decoupling / 100nFデカップリング
- R4, R5: 4.7kΩ I2C pull-ups to 3.3V / 4.7kΩ I2Cプルアップ（3.3Vへ）
- C11, C12: 1μF audio coupling capacitors / 1μF音声結合コンデンサ

**Notes / 注記:**
- 3.5mm jack serves dual purpose: audio output and FM antenna / 3.5mmジャックは二重機能：音声出力とFMアンテナ
- I2C pull-ups connected to 3.3V rail to match RDA5807M and OLED voltage levels / I2Cプルアップは3.3Vレールに接続し、RDA5807MとOLEDの電圧レベルに合わせる
- Audio output is DC-blocked with coupling capacitors / 音声出力はカップリングコンデンサでDCブロックされている
- Earphone cable length provides optimal FM antenna (75-80cm) / イヤホンケーブルの長さが最適なFMアンテナを提供（75-80cm）
- Earphone cable acts as FM antenna

## Bluetooth Audio Section / Bluetooth音声セクション

### JDY-64 Module Connections / JDY-64モジュール接続
```
JDY-64 (U3):
- VCC → 3.3V (via C4: 100nF)
- GND → GND
- TXD → PD0/RXD (U1 pin 2)
- RXD → PD1/TXD (U1 pin 3)
- KEY → PD7 (U1 pin 13) [Pairing control / ペアリング制御]
- STATE → LED2 (Blue) via R7 (1kΩ)
```

**Components / 部品:**
- U3: JDY-64 Bluetooth module (or XS3868 for A2DP) / JDY-64 Bluetoothモジュール（A2DP用にはXS3868）
- C4: 100nF decoupling / 100nFデカップリング
- R7: 1kΩ LED current limiting / 1kΩ LED電流制限
- LED2: Blue LED (status indicator) / 青LED（状態インジケータ）

**Notes / 注記:**
- UART communication at 9600 baud (default) / UART通信は9600ボー（デフォルト）
- KEY pin for entering pairing mode / KEYピンはペアリングモード用
- STATE LED indicates connection status / STATE LEDは接続状態を示す
- For A2DP audio, use XS3868 module instead / A2DP音声にはXS3868モジュールを使用
- Module internally routes FM audio to Bluetooth A2DP / モジュールは内部でFM音声をBluetooth A2DPにルーティング

## Display Section (OLED) / ディスプレイセクション（OLED）

### SSD1306 OLED Connections / SSD1306 OLED接続
```
OLED (U5):
- VCC → 3.3V (via C5: 100nF)
- GND → GND
- SDA → PC4 (U1 pin 27, A4) [Shared with RDA5807M / RDA5807Mと共有]
- SCL → PC5 (U1 pin 28, A5) [Shared with RDA5807M / RDA5807Mと共有]
```

**Components / 部品:**
- U5: 0.91" OLED (128x32, SSD1306) / 0.91インチOLED
- C5: 100nF decoupling / 100nFデカップリング

**Notes / 注記:**
- I2C address: 0x3C (default for most SSD1306 modules) / I2Cアドレス：0x3C（ほとんどのSSD1306モジュールのデフォルト）
- Shares I2C bus with RDA5807M / RDA5807MとI2Cバスを共有
- 3.3V or 5V compatible (using 3.3V for power efficiency) / 3.3Vまたは5V互換（電力効率のため3.3Vを使用）

## User Interface Section / ユーザーインターフェースセクション

### Buttons / ボタン
```
SW1 (Channel Up / チャンネルアップ):
- One side → PD2 (U1 pin 4)
- Other side → GND
- Pull-up: R2 (10kΩ to 5V) / プルアップ：R2（5Vへ10kΩ）

SW2 (Channel Down / チャンネルダウン):
- One side → PD3 (U1 pin 5)
- Other side → GND
- Pull-up: R3 (10kΩ to 5V) / プルアップ：R3（5Vへ10kΩ）

SW3 (Mode/Pairing / モード/ペアリング):
- One side → PD6 (U1 pin 12)
- Other side → GND
- Pull-up: Internal pull-up enabled in firmware / プルアップ：ファームウェアで内部プルアップ有効化
```

**Components / 部品:**
- SW1, SW2, SW3: 6x6mm tactile switches / 6x6mmタクタイルスイッチ
- R2, R3: 10kΩ pull-ups / 10kΩプルアップ

**Notes / 注記:**
- Active-low logic (pressed = LOW) / アクティブローロジック（押下=LOW）
- Interrupt-capable pins for responsive UI / 応答性の高いUI用割り込み可能ピン
- SW3 uses internal pull-up to save space / SW3は内部プルアップを使用してスペースを節約

### Status LEDs / 状態LED
```
LED1 (Power / 電源):
- Anode → 5V via R6 (1kΩ)
- Cathode → GND

LED2 (Bluetooth):
- Anode → U3 STATE pin via R7 (1kΩ)
- Cathode → GND
```

**Components / 部品:**
- LED1: Red LED (power indicator) / 赤LED（電源インジケータ）
- LED2: Blue LED (Bluetooth status) / 青LED（Bluetooth状態）
- R6, R7: 1kΩ current limiting resistors / 1kΩ電流制限抵抗器

## Audio Routing / 音声ルーティング

### Audio Path / 音声経路
```
RDA5807M LOUT/ROUT → C11/C12 (1μF) → J2 (3.5mm jack L/R)
                   ↓
              XS3868 Audio Input (internal routing / 内部ルーティング)
                   ↓
              Bluetooth A2DP transmission / Bluetooth A2DP伝送
```

**Notes / 注記:**
- Audio is output to both 3.5mm jack and Bluetooth simultaneously / 音声は3.5mmジャックとBluetoothの両方に同時出力
- For size optimization, can remove 3.5mm jack and use Bluetooth only / サイズ最適化のため、3.5mmジャックを削除してBluetoothのみを使用可能
- Earphone cable still needed as FM antenna / FMアンテナとしてイヤホンケーブルは依然として必要

## PCB Layout Considerations / PCBレイアウト考慮事項

### Ground Plane / グランドプレーン
- Solid ground plane on bottom layer / 底面レイヤーに無垢グランドプレーン
- Separate analog and digital grounds, connected at single point near power supply / アナログとデジタルグランドを分離し、電源近くの1点で接続
- Wide ground traces for return paths / リターンパス用の太いグランドトレース

### Signal Routing / 信号ルーティング
- Keep I2C traces short and parallel / I2Cトレースを短く平行に保つ
- Route USB traces with controlled impedance (90Ω differential) / USB トレースは制御インピーダンス（90Ω差動）でルーティング
- Keep antenna traces away from digital signals / アンテナトレースをデジタル信号から離す
- Shield FM radio section from digital noise / FMラジオセクションをデジタルノイズからシールド

### Component Placement / 部品配置
- USB-C connector at one end / 一端にUSB-Cコネクタ
- 3.5mm jack at opposite end / 反対端に3.5mmジャック
- Group power components together / 電源部品をまとめる
- Place decoupling capacitors close to IC power pins / デカップリングコンデンサをIC電源ピンの近くに配置
- RDA5807M away from USB and high-speed signals / RDA5807MをUSBおよび高速信号から離す

### Thermal Considerations / 熱管理考慮事項
- AMS1117 may require thermal relief / AMS1117はサーマルリリーフが必要な場合あり
- Provide adequate copper area for heat dissipation / 放熱のための十分な銅面積を確保
- Consider adding thermal vias under voltage regulator / 電圧レギュレータの下にサーマルビアの追加を検討

## Signal Characteristics / 信号特性

### I2C Bus / I2Cバス
- **Speed / 速度**: 100kHz (standard mode / 標準モード)
- **Pull-up / プルアップ**: 4.7kΩ to 3.3V / 3.3Vへ4.7kΩ
- **Devices / デバイス**: RDA5807M (0x10/0x11), SSD1306 (0x3C)

### UART Bus (Bluetooth) / UARTバス（Bluetooth）
- **Baud Rate / ボーレート**: 9600 bps
- **Data Bits / データビット**: 8
- **Parity / パリティ**: None / なし
- **Stop Bits / ストップビット**: 1
- **Flow Control / フロー制御**: None / なし

### Audio Signal / 音声信号
- **Level / レベル**: Line-level (~1Vrms) / ラインレベル
- **Impedance / インピーダンス**: 32Ω (headphone / ヘッドホン)
- **Frequency Response / 周波数応答**: 50Hz - 15kHz
- **Coupling / 結合**: AC-coupled (DC-blocking capacitors) / AC結合（DCブロッキングコンデンサ）

## Design Notes / 設計ノート

### USB Noise Mitigation / USBノイズ低減
- Ferrite bead on power input / 電源入力にフェライトビーズ
- Bulk capacitor at USB input / USB入力にバルクコンデンサ
- Decoupling capacitors at each IC / 各ICにデカップリングコンデンサ
- Ground plane continuity / グランドプレーンの連続性
- Separate analog/digital sections / アナログ/デジタルセクションの分離

### Antenna Design / アンテナ設計
- 3.5mm jack tip/ring connected to RDA5807M antenna input / 3.5mmジャックのチップ/リングをRDA5807Mアンテナ入力に接続
- Earphone cable length provides optimal FM antenna length (75-80cm) / イヤホンケーブルの長さが最適なFMアンテナ長を提供（75-80cm）
- No external antenna needed / 外部アンテナ不要

### Power Budget / 電力予算
- ATmega328P: ~30mA @ 16MHz
- RDA5807M: ~40mA
- XS3868/JDY-64: ~30mA (idle / アイドル), ~80mA (transmitting / 送信中)
- OLED: ~20mA
- Total / 合計: ~150mA typical / 標準, 250mA peak / ピーク

## Schematic File Structure / 回路図ファイル構造

The complete schematic is available in KiCad format:

完全な回路図はKiCad形式で利用可能です：

- Main file / メインファイル: `hardware/schematics/a2dp_radio.kicad_sch`
- Symbol library / シンボルライブラリ: `hardware/schematics/a2dp_radio.kicad_sym`
- Project file / プロジェクトファイル: `hardware/schematics/a2dp_radio.kicad_pro`

## Revision History / 改訂履歴
| Version / バージョン | Date / 日付 | Changes / 変更内容 |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial circuit design / 初期回路設計 |
| 1.1 | 2026-02-12 | Fixed USB-C CC pins, I2C voltage levels, pin mappings / USB-C CCピン修正、I2C電圧レベル修正、ピンマッピング修正 |
