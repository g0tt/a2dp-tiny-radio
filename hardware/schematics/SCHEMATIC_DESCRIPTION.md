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

## Microcontroller Section (ATmega328P)

### Power and Clock
```
ATmega328P (U1):
- VCC, AVCC → 5V (via C1, C2: 100nF)
- GND, AGND → GND
- XTAL1, XTAL2 → Y1 (16MHz) with C7, C8 (22pF to GND)
- RESET → SW4 (optional) + R1 (10kΩ pull-up to 5V)
```

**Components:**
- U1: ATmega328P-AU (TQFP-32)
- Y1: 16MHz crystal
- C1, C2: 100nF decoupling capacitors
- C7, C8: 22pF load capacitors for crystal
- R1: 10kΩ reset pull-up

### ISP Programming Header (Optional)
```
J3 (2x3 header):
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

## Bluetooth Audio Section

### JDY-64 Module Connections
```
JDY-64 (U3):
- VCC → 3.3V (via C4: 100nF)
- GND → GND
- TXD → PD0/RXD (U1 pin 2)
- RXD → PD1/TXD (U1 pin 3)
- KEY → PD7 (U1 pin 13) [Pairing control]
- STATE → LED2 (Blue) via R7 (1kΩ)
```

**Components:**
- U3: JDY-64 Bluetooth module
- C4: 100nF decoupling
- R7: 1kΩ LED current limiting
- LED2: Blue LED (status indicator)

**Notes:**
- UART communication at 9600 baud (default)
- KEY pin for entering pairing mode
- STATE LED indicates connection status
- Module internally routes FM audio to Bluetooth A2DP

## Display Section (OLED)

### SSD1306 OLED Connections
```
OLED (U5):
- VCC → 3.3V (via C5: 100nF)
- GND → GND
- SDA → PD4 (U1 pin 6) [Shared with RDA5807M]
- SCL → PD5 (U1 pin 11) [Shared with RDA5807M]
```

**Components:**
- U5: 0.91" OLED (128x32, SSD1306)
- C5: 100nF decoupling

**Notes:**
- I2C address: 0x3C (default for most SSD1306 modules)
- Shares I2C bus with RDA5807M
- 3.3V or 5V compatible (using 3.3V for power efficiency)

## User Interface Section

### Buttons
```
SW1 (Channel Up):
- One side → PD2 (U1 pin 4)
- Other side → GND
- Pull-up: R2 (10kΩ to 5V)

SW2 (Channel Down):
- One side → PD3 (U1 pin 5)
- Other side → GND
- Pull-up: R3 (10kΩ to 5V)

SW3 (Mode/Pairing):
- One side → PD6 (U1 pin 12)
- Other side → GND
- Pull-up: Internal pull-up enabled in firmware
```

**Components:**
- SW1, SW2, SW3: 6x6mm tactile switches
- R2, R3: 10kΩ pull-ups

**Notes:**
- Active-low logic (pressed = LOW)
- Interrupt-capable pins for responsive UI
- SW3 uses internal pull-up to save space

### Status LEDs
```
LED1 (Power):
- Anode → 5V via R6 (1kΩ)
- Cathode → GND

LED2 (Bluetooth):
- Anode → U3 STATE pin via R7 (1kΩ)
- Cathode → GND
```

**Components:**
- LED1: Red LED (power indicator)
- LED2: Blue LED (Bluetooth status)
- R6, R7: 1kΩ current limiting resistors

## Audio Routing

### Audio Path
```
RDA5807M LOUT/ROUT → C11/C12 (1μF) → J2 (3.5mm jack L/R)
                   ↓
              JDY-64 Audio Input (internal routing)
                   ↓
              Bluetooth A2DP transmission
```

**Notes:**
- Audio is output to both 3.5mm jack and Bluetooth simultaneously
- For size optimization, can remove 3.5mm jack and use Bluetooth only
- Earphone cable still needed as FM antenna

## PCB Layout Considerations

### Ground Plane
- Solid ground plane on bottom layer
- Separate analog and digital grounds, connected at single point near power supply
- Wide ground traces for return paths

### Signal Routing
- Keep I2C traces short and parallel
- Route USB traces with controlled impedance (90Ω differential)
- Keep antenna traces away from digital signals
- Shield FM radio section from digital noise

### Component Placement
- USB-C connector at one end
- 3.5mm jack at opposite end
- Group power components together
- Place decoupling capacitors close to IC power pins
- RDA5807M away from USB and high-speed signals

### Thermal Considerations
- AMS1117 may require thermal relief
- Provide adequate copper area for heat dissipation
- Consider adding thermal vias under voltage regulator

## Signal Characteristics

### I2C Bus
- **Speed**: 100kHz (standard mode)
- **Pull-up**: 4.7kΩ to 5V
- **Devices**: RDA5807M (0x10/0x11), SSD1306 (0x3C)

### UART Bus (Bluetooth)
- **Baud Rate**: 9600 bps
- **Data Bits**: 8
- **Parity**: None
- **Stop Bits**: 1
- **Flow Control**: None

### Audio Signal
- **Level**: Line-level (~1Vrms)
- **Impedance**: 32Ω (headphone)
- **Frequency Response**: 50Hz - 15kHz
- **Coupling**: AC-coupled (DC-blocking capacitors)

## Design Notes

### USB Noise Mitigation
- Ferrite bead on power input
- Bulk capacitor at USB input
- Decoupling capacitors at each IC
- Ground plane continuity
- Separate analog/digital sections

### Antenna Design
- 3.5mm jack tip/ring connected to RDA5807M antenna input
- Earphone cable length provides optimal FM antenna length (75-80cm)
- No external antenna needed

### Power Budget
- ATmega328P: ~30mA @ 16MHz
- RDA5807M: ~40mA
- JDY-64: ~30mA (idle), ~80mA (transmitting)
- OLED: ~20mA
- Total: ~150mA typical, 250mA peak

## Schematic File Structure
The complete schematic is available in KiCad format:
- Main file: `hardware/schematics/a2dp_radio.kicad_sch`
- Symbol library: `hardware/schematics/a2dp_radio.kicad_sym`
- Project file: `hardware/schematics/a2dp_radio.kicad_pro`

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial circuit design |
