# Bill of Materials (BOM) - A2DP Tiny Radio / 部品表 - A2DP Tiny Radio

## Components List / 部品リスト

| Ref / 参照 | Qty / 数量 | Value / 値 | Description / 説明 | Package / パッケージ | Manufacturer Part# / メーカー品番 | Notes / 備考 |
|-----|-----|-------|-------------|---------|-------------------|-------|
| U1 | 1 | ATmega328P-AU | Microcontroller / マイクロコントローラ | TQFP-32 | ATmega328P-AU | Arduino compatible / Arduino互換 |
| U2 | 1 | RDA5807M | FM Radio Receiver / FMラジオ受信機 | QFN-20 | RDA5807M | I2C interface / I2Cインターフェース |
| U3 | 1 | JDY-64 or XS3868 | Bluetooth Module / Bluetoothモジュール | Module / モジュール | JDY-64 or XS3868 | For A2DP audio: use XS3868. JDY-64/HC-05 are serial only / A2DP音声用：XS3868を使用。JDY-64/HC-05はシリアルのみ |
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
| R4-R5 | 2 | 4.7kΩ | Resistor / 抵抗器 | 0805 | 1% | I2C pull-up to 3.3V / I2Cプルアップ（3.3Vへ） |
| R6-R7 | 2 | 1kΩ | Resistor / 抵抗器 | 0805 | 1% | LED current limiting / LED電流制限 |
| R8-R9 | 2 | 100Ω | Resistor / 抵抗器 | 0805 | 1% | Audio output / 音声出力 |
| R10-R11 | 2 | 5.1kΩ | Resistor / 抵抗器 | 0805 | 1% | USB-C CC pull-down (Rd) / USB-C CCプルダウン（Rd） |
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

## Alternative Components / 代替部品

### Bluetooth Module Alternatives / Bluetoothモジュール代替品

**For A2DP Audio Streaming / A2DP音声ストリーミング用:**
1. **XS3868**: Bluetooth 2.1+EDR with A2DP, built-in audio DAC / A2DP対応Bluetooth 2.1+EDR、内蔵オーディオDAC, $4-6
   - ✅ **Recommended for this project** / このプロジェクトに推奨
   - Native A2DP audio support / ネイティブA2DP音声対応
   - Simpler firmware integration / より簡単なファームウェア統合

**For UART Serial Communication Only / UARTシリアル通信のみ:**
2. **JDY-64**: Bluetooth 5.0, UART/BLE (no A2DP audio) / Bluetooth 5.0、UART/BLE（A2DP音声なし）, $3-5
3. **HC-05**: Bluetooth 2.0, SPP serial only (no A2DP audio) / Bluetooth 2.0、SPPシリアルのみ（A2DP音声なし）, $2-4
   - ⚠️ **Not suitable for A2DP audio** / A2DP音声には不適

### Microcontroller Alternatives / マイクロコントローラ代替品

**Arduino-Compatible Options / Arduino互換オプション:**

1. **ATmega328P-AU (Current Design) / ATmega328P-AU（現在の設計）**
   - Package / パッケージ: TQFP-32
   - Flash: 32KB, RAM: 2KB, Clock: 16MHz
   - Pros / 長所: Standard Arduino Uno chip, excellent documentation, proven design / 標準Arduino Unoチップ、優れたドキュメント、実績のある設計
   - Cons / 短所: Relatively large footprint, 5V logic requires level shifting for 3.3V peripherals / 比較的大きなフットプリント、5Vロジックは3.3V周辺機器にレベルシフトが必要

2. **ATmega328P-MU**
   - Package / パッケージ: QFN-32 (smaller than TQFP) / QFN-32（TQFPより小さい）
   - Same specs as ATmega328P-AU / ATmega328P-AUと同じ仕様
   - Pros / 長所: Smaller PCB footprint (5x5mm vs 7x7mm) / より小さいPCBフットプリント
   - Cons / 短所: More difficult to hand-solder than TQFP / TQFPよりも手はんだが困難

3. **ATmega168PA/88PA** (Lower-spec options / より低スペックオプション)
   - Flash: 16KB/8KB, RAM: 1KB/512B
   - Pros / 長所: Lower cost (~$1-2 cheaper), same package options / より低コスト、同じパッケージオプション
   - Cons / 短所: Less flash/RAM may limit firmware features and future expansion / より少ないフラッシュ/RAMはファームウェア機能と将来の拡張を制限する可能性
   - **Recommendation / 推奨**: ATmega168PA could work for basic functionality, but 328P recommended for comfortable development / ATmega168PAは基本機能には使えるが、快適な開発には328Pを推奨

**ESP32-Based Options (Significant Design Changes Required) / ESP32ベースオプション（大幅な設計変更が必要）:**

4. **ESP32-C3-MINI-1**
   - Package / パッケージ: SMD module (13.2 x 16.6mm)
   - Flash: 4MB, RAM: 400KB, Clock: 160MHz
   - Built-in: Wi-Fi + Bluetooth 5.0 (BLE) / 内蔵：Wi-Fi + Bluetooth 5.0（BLE）
   - Pros / 長所: 
     - Much more powerful, single 3.3V supply / はるかに強力、単一3.3V電源
     - Eliminates need for separate Bluetooth module / 別のBluetoothモジュールが不要
     - Built-in antenna options / 内蔵アンテナオプション
     - Smaller total board size possible / より小さな全体基板サイズが可能
   - Cons / 短所: 
     - Requires complete firmware rewrite (ESP-IDF or Arduino-ESP32) / 完全なファームウェア書き直しが必要
     - Bluetooth Classic A2DP support requires ESP32 (not C3) / Bluetooth Classic A2DPサポートにはESP32（C3ではない）が必要
     - More complex PCB design (antenna design, RF considerations) / より複雑なPCB設計（アンテナ設計、RF考慮事項）
     - Higher power consumption / より高い消費電力
   - **Recommendation / 推奨**: Consider for future revision if Wi-Fi features desired. ESP32 (not C3) needed for Bluetooth Classic A2DP. / Wi-Fi機能が必要な場合は将来のリビジョンで検討。Bluetooth Classic A2DPにはESP32（C3ではない）が必要。

5. **ESP32-WROOM-32**
   - Package / パッケージ: SMD module (18 x 25.5mm)
   - Flash: 4MB, RAM: 520KB
   - Built-in: Wi-Fi + Bluetooth Classic + BLE / 内蔵：Wi-Fi + Bluetooth Classic + BLE
   - Pros / 長所: 
     - Native A2DP audio support (Bluetooth Classic) / ネイティブA2DP音声サポート（Bluetooth Classic）
     - Could eliminate external Bluetooth module entirely / 外部Bluetoothモジュールを完全に排除可能
     - Powerful enough for advanced audio processing / 高度な音声処理に十分強力
   - Cons / 短所:
     - Larger module size / より大きなモジュールサイズ
     - Requires antenna design (PCB antenna or external) / アンテナ設計が必要（PCBアンテナまたは外部）
     - Complete firmware rewrite needed / 完全なファームウェア書き直しが必要
     - More expensive (~$2-4 per module) / より高価

**Design Decision Summary / 設計決定の要約:**

- **Current ATmega328P design** is optimal for: Arduino ecosystem compatibility, ease of development, proven reliability, hand-soldering / 現在のATmega328P設計が最適：Arduinoエコシステム互換性、開発の容易さ、実績のある信頼性、手はんだ付け
- **ATmega168PA** possible if cost is critical and basic features acceptable / コストが重要で基本機能が許容できる場合、ATmega168PAも可能
- **ESP32** attractive for integrated Wi-Fi/BT but requires: complete redesign, RF expertise, larger module, higher complexity / ESP32は統合Wi-Fi/BTに魅力的だが、完全な再設計、RF専門知識、より大きなモジュール、より高い複雑さが必要

For this USB-stick-sized project prioritizing simplicity and hand-solderability, **ATmega328P remains the best choice**. ESP32 could be considered for a future "advanced" version with Wi-Fi streaming capability. / USBスティックサイズでシンプルさと手はんだ付けを優先するこのプロジェクトでは、**ATmega328Pが最良の選択のまま**。ESP32は、Wi-Fiストリーミング機能を備えた将来の「高度な」バージョンで検討可能。

## Storage Recommendations
- Store components in anti-static bags
- Keep moisture-sensitive parts in dry box
- Label by component type and value

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial BOM |
