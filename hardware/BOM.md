# Bill of Materials (BOM) - A2DP Tiny Radio / 部品表 - A2DP Tiny Radio

## Components List / 部品リスト

| Ref / 参照 | Qty / 数量 | Value / 値 | Description / 説明 | Package / パッケージ | Manufacturer Part# / メーカー品番 | Notes / 備考 |
|-----|-----|-------|-------------|---------|-------------------|-------|
| U1 | 1 | ATmega328P-AU | Microcontroller / マイクロコントローラ | TQFP-32 | ATmega328P-AU | Arduino compatible / Arduino互換 |
| U2 | 1 | RDA5807M | FM Radio Receiver / FMラジオ受信機 | QFN-20 | RDA5807M | I2C interface / I2Cインターフェース |
| U3 | 1 | JDY-64 | Bluetooth 5.0 Module / Bluetooth 5.0モジュール | Module / モジュール | JDY-64 | Alternative: HC-05 / 代替品：HC-05 |
| U4 | 1 | AMS1117-3.3 | 3.3V LDO Regulator / 3.3V LDOレギュレータ | SOT-223 | AMS1117-3.3 | 800mA output / 800mA出力 |
| U5 | 1 | SSD1306 | 0.91" OLED Display / 0.91" OLEDディスプレイ | Module / モジュール | 128x32 OLED | I2C, white/blue / I2C、白/青 |
| Y1 | 1 | 16MHz | Crystal Oscillator / 水晶振動子 | HC-49S SMD | 16MHz ±20ppm | For ATmega328P / ATmega328P用 |
| Y2 | 1 | 32.768kHz | Crystal Oscillator / 水晶振動子 | SMD 3.2x1.5mm | 32.768kHz | For RDA5807M / RDA5807M用 |
| J1 | 1 | USB-C | USB-C Receptacle / USB-Cレセプタクル | SMD | Korean Hroparts Elec TYPE-C-31-M-12 | Power only / 電源のみ |
| J2 | 1 | PJ-320A | 3.5mm Audio Jack / 3.5mmオーディオジャック | Through-hole / スルーホール | PJ-320A | Stereo, antenna / ステレオ、アンテナ |
| SW1-3 | 3 | - | Tactile Switch / タクタイルスイッチ | 6x6mm SMD | SPST 4-pin | User interface / ユーザーインターフェース |
| C1-C6 | 6 | 100nF | Ceramic Capacitor / セラミックコンデンサ | 0805 | X7R 50V | Decoupling / デカップリング |
| C7-C8 | 2 | 22pF | Ceramic Capacitor / セラミックコンデンサ | 0805 | C0G/NP0 50V | Crystal load caps / 水晶負荷コンデンサ |
| C9-C10 | 2 | 10μF | Ceramic Capacitor / セラミックコンデンサ | 0805 | X7R 16V | Power filtering / 電源フィルタリング |
| C11-C12 | 2 | 1μF | Ceramic Capacitor / セラミックコンデンサ | 0805 | X7R 16V | Audio coupling / 音声結合 |
| C13 | 1 | 47μF | Electrolytic Capacitor / 電解コンデンサ | SMD 6.3x5.4mm | 16V | USB input / USB入力 |
| R1-R3 | 3 | 10kΩ | Resistor / 抵抗器 | 0805 | 1% | Pull-up / プルアップ |
| R4-R5 | 2 | 4.7kΩ | Resistor / 抵抗器 | 0805 | 1% | I2C pull-up / I2Cプルアップ |
| R6-R7 | 2 | 1kΩ | Resistor / 抵抗器 | 0805 | 1% | LED current limiting / LED電流制限 |
| R8-R9 | 2 | 100Ω | Resistor / 抵抗器 | 0805 | 1% | Audio output / 音声出力 |
| L1 | 1 | Ferrite Bead / フェライトビーズ | Ferrite Bead / フェライトビーズ | 0805 | 600Ω@100MHz | USB noise filter / USBノイズフィルタ |
| D1 | 1 | SS34 | Schottky Diode / ショットキーダイオード | SMB | SS34 | Reverse protection / 逆接続保護 |
| LED1 | 1 | Red / 赤 | LED | 0805 | Red 620nm / 赤 620nm | Power indicator / 電源インジケータ |
| LED2 | 1 | Blue / 青 | LED | 0805 | Blue 470nm / 青 470nm | Bluetooth status / Bluetooth状態 |

## Module Components (Pre-assembled) / モジュール部品（組み立て済み）

| Module / モジュール | Interface / インターフェース | Power / 電源 | Dimensions / 寸法 |
|--------|-----------|-------|------------|
| JDY-64 Bluetooth | UART (TX/RX) | 3.3V | 26.9 x 13 x 2.2mm |
| SSD1306 OLED | I2C (SDA/SCL) | 3.3V-5V | 30 x 12 x 4mm |

## Optional Components / オプション部品

| Ref / 参照 | Qty / 数量 | Value / 値 | Description / 説明 | Package / パッケージ | Notes / 備考 |
|-----|-----|-------|-------------|---------|-------|
| J3 | 1 | Header 2x3 / ヘッダ2x3 | ISP Programming Header / ISPプログラミングヘッダ | 2.54mm pitch | For Arduino bootloader programming / Arduinoブートローダープログラミング用 |
| SW4 | 1 | SPST | Reset Switch / リセットスイッチ | 6x6mm SMD | Manual reset / 手動リセット |

## Assembly Notes / 組み立て注意事項

### Soldering Guidelines / はんだ付けガイドライン

1. **QFN Package (RDA5807M) / QFNパッケージ（RDA5807M）**: Requires fine soldering iron tip and flux. Drag soldering technique recommended. / 細いはんだごて先端とフラックスが必要。ドラッグはんだ付け技術を推奨。
2. **TQFP Package (ATmega328P) / TQFPパッケージ（ATmega328P）**: Standard fine-pitch soldering. Use flux and wick for cleanup. / 標準的なファインピッチはんだ付け。クリーンアップにはフラックスとウィックを使用。
3. **SMD 0805 Components / SMD 0805部品**: Hand-solderable with standard soldering iron. / 標準はんだごてで手はんだ可能。
4. **Modules**: Pre-soldered pin headers or direct solder to pads.

### Component Sourcing / 部品調達

- **Primary Suppliers / 主要サプライヤー**: DigiKey, Mouser, LCSC
- **Modules / モジュール**: AliExpress, eBay (JDY-64, OLED)
- **PCB**: JLCPCB, PCBWay

### Cost Estimate / コスト見積もり

- **PCB (5pcs) / PCB（5枚）**: ~$10 USD / 約1,400円
- **Components / 部品**: ~$25 USD / 約3,500円
- **Total per unit / 1台あたり合計**: ~$7 USD / 約1,000円 (excluding NRE / 非経常経費を除く)

## Alternative Components

### Bluetooth Module Alternatives
1. **JDY-64**: Bluetooth 5.0, A2DP, $3-5
2. **HC-05**: Bluetooth 2.0, A2DP, $2-4
3. **XS3868**: Bluetooth with A2DP, built-in audio DAC, $4-6

### Microcontroller Alternatives
1. **ATmega328P-AU**: TQFP-32, standard Arduino Uno chip
2. **ATmega328P-MU**: QFN-32, smaller footprint
3. **ESP32-C3**: Built-in Bluetooth, but requires 3.3V logic

## Storage Recommendations
- Store components in anti-static bags
- Keep moisture-sensitive parts in dry box
- Label by component type and value

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial BOM |
