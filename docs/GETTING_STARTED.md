# Getting Started - A2DP Tiny Radio Project

## Welcome! / ようこそ！

This guide will help you get started with building your own A2DP Tiny Radio. Whether you're an experienced electronics hobbyist or a beginner, this document will guide you through the process.

このガイドは、A2DP Tiny Radioの製作を始める方のためのものです。経験豊富な電子工作愛好家でも初心者でも、このドキュメントが製作プロセスをご案内します。

## Quick Links / クイックリンク

- [技術仕様 / Technical Specs](docs/SPECIFICATIONS.md)
- [部品表 / Bill of Materials](hardware/BOM.md)
- [回路図説明 / Circuit Description](hardware/schematics/SCHEMATIC_DESCRIPTION.md)
- [組み立て手順 / Assembly Guide](docs/ASSEMBLY_GUIDE.md)
- [ユーザーマニュアル / User Manual](docs/USER_MANUAL.md)

## Project Overview / プロジェクト概要

**What You'll Build / 製作するもの:**
A pocket-sized FM radio (76-108MHz) with Bluetooth A2DP audio output, packaged in a USB memory stick form factor.

超小型FMラジオ（76-108MHz）とBluetooth A2DP音声出力機能を、USBメモリサイズの筐体に実装します。

**Key Features / 主な特徴:**
- 📻 FM radio reception / FMラジオ受信
- 📡 Bluetooth audio streaming / Bluetooth音声配信
- 🎧 Wired 3.5mm output / 有線3.5mm出力
- 📺 Small OLED display / 小型OLEDディスプレイ
- 🔌 USB-C powered / USB-C電源
- 📦 Compact & portable / コンパクト＆ポータブル

## What You Need / 必要なもの

### Skills Required / 必要なスキル

**Minimum / 最低限:**
- ✅ Basic soldering (through-hole components)
- ✅ 基本的なはんだ付け（スルーホール部品）
- ✅ Ability to follow instructions
- ✅ 指示に従う能力
- ✅ Using a multimeter
- ✅ テスターの使用

**Recommended / 推奨:**
- ⭐ SMD soldering experience (0805 and TQFP packages)
- ⭐ SMDはんだ付け経験（0805とTQFPパッケージ）
- ⭐ Arduino programming knowledge
- ⭐ Arduinoプログラミング知識
- ⭐ PCB design experience (KiCad)
- ⭐ PCB設計経験（KiCad）

**Optional / オプション:**
- 3D modeling (for custom case)
- 3Dモデリング（カスタムケース用）
- Advanced circuit debugging
- 高度な回路デバッグ

### Tools Needed / 必要な工具

**Essential / 必須:**
- Soldering iron with fine tip / 細先はんだごて
- Solder (lead-free recommended) / はんだ（無鉛推奨）
- Wire cutters / ニッパー
- Tweezers / ピンセット
- Multimeter / テスター
- Magnifying glass / 拡大鏡

**Highly Recommended / 強く推奨:**
- Hot air rework station (for QFN package) / ホットエアー（QFNパッケージ用）
- Flux / フラックス
- Solder wick / はんだ吸取線
- ESD mat and wrist strap / 静電気対策マットとリストストラップ
- Helping hands / はんだ付け補助具

**Optional / オプション:**
- Microscope or USB camera / 顕微鏡またはUSBカメラ
- Oscilloscope / オシロスコープ
- Logic analyzer / ロジックアナライザ

### Software Needed / 必要なソフトウェア

**For Firmware / ファームウェア用:**
- Arduino IDE (1.8.x or later)
- Required libraries (see firmware/README.md)

**For PCB Design / PCB設計用:**
- KiCad 6.0 or later (free)
- https://www.kicad.org/

**For 3D Case / 3Dケース用:**
- Fusion 360 (free for hobbyists) OR
- FreeCAD (free, open source) OR
- OpenSCAD (free, code-based)

## Step-by-Step Process / 段階的プロセス

### Phase 1: Planning and Procurement / 計画と調達 (1-2 weeks)

#### 1.1 Review Documentation
- [ ] Read all documentation in `docs/` folder
- [ ] `docs/`フォルダ内のすべてのドキュメントを読む
- [ ] Understand circuit diagram
- [ ] 回路図を理解する
- [ ] Review BOM (Bill of Materials)
- [ ] BOM（部品表）を確認する

#### 1.2 Order Components
- [ ] Order all components from BOM
- [ ] BOMからすべての部品を注文
- [ ] Recommended suppliers: DigiKey, Mouser, LCSC
- [ ] 推奨サプライヤー：DigiKey、Mouser、LCSC
- [ ] Order modules (JDY-64, OLED) from AliExpress/eBay
- [ ] モジュール（JDY-64、OLED）をAliExpress/eBayから注文

**Cost Estimate / 概算コスト:**
- Components: $25 USD / 部品：約3,500円
- PCB (5 pieces): $10 USD / PCB（5枚）：約1,400円
- Total per unit: ~$7 USD / 1台あたり：約1,000円

#### 1.3 PCB Design and Order
**Option A: Design Your Own / 自分で設計:**
- [ ] Create schematic in KiCad
- [ ] KiCadで回路図を作成
- [ ] Design PCB layout
- [ ] PCBレイアウトを設計
- [ ] Generate Gerber files
- [ ] Gerberファイルを生成
- [ ] Order from JLCPCB
- [ ] JLCPCBから発注

**Option B: Use Existing Design (if available):**
- [ ] Download Gerber files from repository
- [ ] リポジトリからGerberファイルをダウンロード
- [ ] Order from JLCPCB
- [ ] JLCPCBから発注

**JLCPCB Settings:**
```
Layers: 2
PCB Thickness: 1.6mm
Surface Finish: HASL or ENIG
Copper Weight: 1 oz
PCB Color: Green (or your choice)
Quantity: 5 (minimum)
```

**Delivery Time:** 1-2 weeks

### Phase 2: PCB Assembly / PCB組み立て (4-8 hours)

#### 2.1 Prepare Workspace
- [ ] Clean, well-lit workspace
- [ ] 清潔で明るい作業スペース
- [ ] Good ventilation
- [ ] 良好な換気
- [ ] ESD protection
- [ ] 静電気対策
- [ ] Organize components
- [ ] 部品を整理

#### 2.2 Solder Components
Follow the order in `docs/ASSEMBLY_GUIDE.md`:

1. [ ] SMD resistors (0805) / SMD抵抗器
2. [ ] SMD capacitors (0805) / SMDコンデンサ
3. [ ] Crystals / 水晶振動子
4. [ ] ATmega328P (TQFP-32)
5. [ ] RDA5807M (QFN-20) - Most difficult! / 最も難しい！
6. [ ] AMS1117-3.3 voltage regulator
7. [ ] Diode, LEDs / ダイオード、LED
8. [ ] USB-C connector / USB-Cコネクタ
9. [ ] 3.5mm audio jack / 3.5mmオーディオジャック
10. [ ] Tactile switches / タクタイルスイッチ
11. [ ] Bluetooth module / Bluetoothモジュール
12. [ ] OLED display / OLEDディスプレイ

**Tips / ヒント:**
- Start with smallest components first
- 最小の部品から始める
- Use flux generously
- フラックスをたっぷり使う
- Check for solder bridges with magnification
- 拡大してはんだブリッジを確認
- Take breaks to avoid eye strain
- 目の疲れを避けるため休憩を取る

#### 2.3 Inspection and Testing
- [ ] Visual inspection of all joints
- [ ] すべての接合部を目視検査
- [ ] Check for shorts with multimeter
- [ ] テスターでショートを確認
- [ ] Measure power rails (5V, 3.3V)
- [ ] 電源レール（5V、3.3V）を測定

### Phase 3: Firmware Programming / ファームウェアプログラミング (1-2 hours)

#### 3.1 Setup Arduino IDE
- [ ] Download and install Arduino IDE
- [ ] Arduino IDEをダウンロード＆インストール
- [ ] Install required libraries:
  - Adafruit GFX Library
  - Adafruit SSD1306
  - Wire (built-in)
  - EEPROM (built-in)

#### 3.2 Program Microcontroller
- [ ] Open `firmware/a2dp_fm_radio/a2dp_fm_radio.ino`
- [ ] Select Board: "Arduino Uno"
- [ ] ボードを選択：「Arduino Uno」
- [ ] Select Port: [Your COM port]
- [ ] ポートを選択：[あなたのCOMポート]
- [ ] Verify/Compile sketch
- [ ] スケッチを検証/コンパイル
- [ ] Upload to board
- [ ] ボードにアップロード

**Troubleshooting:**
- If upload fails, check UART connections
- アップロードが失敗したら、UART接続を確認
- Ensure ATmega328P has Arduino bootloader
- ATmega328PにArduinoブートローダーがあることを確認

### Phase 4: Testing / テスト (1-2 hours)

#### 4.1 Power-Up Test
- [ ] Connect USB-C power
- [ ] USB-C電源を接続
- [ ] Verify power LED lights up
- [ ] 電源LEDが点灯することを確認
- [ ] Check voltage rails (5V and 3.3V)
- [ ] 電圧レール（5Vと3.3V）を確認

#### 4.2 Display Test
- [ ] OLED shows startup message
- [ ] OLEDが起動メッセージを表示
- [ ] Displays "A2DP FM Radio"
- [ ] "A2DP FM Radio"を表示

#### 4.3 Button Test
- [ ] Test each button
- [ ] 各ボタンをテスト
- [ ] Verify response on display
- [ ] ディスプレイの応答を確認

#### 4.4 FM Radio Test
- [ ] Connect earphones (acts as antenna!)
- [ ] イヤホンを接続（アンテナとして機能！）
- [ ] Tune to known FM station
- [ ] 既知のFM局に同調
- [ ] Verify audio output
- [ ] 音声出力を確認
- [ ] Test automatic scanning
- [ ] 自動スキャンをテスト

#### 4.5 Bluetooth Test
- [ ] Enter pairing mode (long press MODE button)
- [ ] ペアリングモードに入る（MODEボタン長押し）
- [ ] Pair with phone/tablet
- [ ] 携帯/タブレットとペアリング
- [ ] Verify audio streams via Bluetooth
- [ ] Bluetooth経由で音声が流れることを確認

### Phase 5: Case Design and Fabrication / ケース設計と製作 (Optional)

#### 5.1 Design 3D Case
- [ ] Follow specifications in `case/CASE_DESIGN_GUIDE.md`
- [ ] `case/CASE_DESIGN_GUIDE.md`の仕様に従う
- [ ] Create CAD model
- [ ] CADモデルを作成
- [ ] Export STL files
- [ ] STLファイルをエクスポート

#### 5.2 3D Print Case
- [ ] Slice STL files
- [ ] STLファイルをスライス
- [ ] 3D print top and bottom shells
- [ ] 上下のシェルを3Dプリント
- [ ] Remove supports and clean up
- [ ] サポートを除去してクリーンアップ

#### 5.3 Final Assembly
- [ ] Test fit PCB in case
- [ ] ケース内でPCBのフィット感をテスト
- [ ] Install PCB in bottom shell
- [ ] 底部シェルにPCBをインストール
- [ ] Close top shell
- [ ] 上部シェルを閉じる
- [ ] Secure with snaps or screws
- [ ] スナップまたはネジで固定

### Phase 6: Final Testing and Documentation / 最終テストと文書化

#### 6.1 Comprehensive Testing
- [ ] Test all functions in case
- [ ] ケース内ですべての機能をテスト
- [ ] Verify all buttons accessible
- [ ] すべてのボタンがアクセス可能であることを確認
- [ ] Check USB-C and audio jack access
- [ ] USB-Cとオーディオジャックのアクセスを確認
- [ ] Long-term operation test (4+ hours)
- [ ] 長期動作テスト（4時間以上）

#### 6.2 Document Your Build
- [ ] Take photos of completed project
- [ ] 完成したプロジェクトの写真を撮る
- [ ] Note any modifications or improvements
- [ ] 変更や改善点を記録
- [ ] Share on GitHub Discussions (optional)
- [ ] GitHubディスカッションで共有（オプション）

## Estimated Timeline / 予想タイムライン

| Phase | Duration | Can Start After |
|-------|----------|------------------|
| Planning & Procurement | 1-2 weeks | Immediately |
| PCB Design (if DIY) | 1-2 weeks | Planning complete |
| Waiting for PCB | 1-2 weeks | PCB ordered |
| Assembly | 4-8 hours | PCB received |
| Programming | 1-2 hours | Assembly complete |
| Testing | 1-2 hours | Programming complete |
| Case Design | 2-4 hours | PCB tested |
| 3D Printing | 4-6 hours | Design complete |
| Final Assembly | 1 hour | Case printed |

**Total Time: 4-6 weeks from start to finish**
**合計時間：開始から完成まで4〜6週間**

## Common Issues and Solutions / よくある問題と解決策

### "I can't solder the QFN package!" / 「QFNパッケージがはんだ付けできません！」
**Solution / 解決策:**
- Use hot air rework station (highly recommended)
- ホットエアーリワークステーションを使用（強く推奨）
- Or practice on spare PCBs first
- または予備のPCBで最初に練習
- Consider ordering pre-assembled PCB from JLCPCB
- JLCPCBから組み立て済みPCBを注文することを検討

### "Display doesn't work" / 「ディスプレイが機能しません」
**Check / 確認:**
- 3.3V power reaching display
- ディスプレイに3.3V電源が届いているか
- I2C connections (SDA/SCL)
- I2C接続（SDA/SCL）
- I2C address (usually 0x3C)
- I2Cアドレス（通常0x3C）

### "No FM reception" / 「FM受信がありません」
**Check / 確認:**
- Earphone must be connected (antenna!)
- イヤホンを接続する必要があります（アンテナ！）
- Try near window for better signal
- より良い信号のため窓の近くで試す
- Verify RDA5807M soldering
- RDA5807Mのはんだ付けを確認

### "Bluetooth won't pair" / 「Bluetoothがペアリングできません」
**Check / 確認:**
- 3.3V power to Bluetooth module
- Bluetoothモジュールへの3.3V電源
- UART connections (TX↔RX crossed)
- UART接続（TX↔RX交差）
- Try different phone/device
- 別の携帯/デバイスを試す

## Getting Help / ヘルプを得る

### Resources / リソース
- **Documentation**: All docs in this repository
- **ドキュメント**: このリポジトリ内のすべてのドキュメント
- **GitHub Issues**: Report bugs or ask questions
- **GitHub Issues**: バグ報告や質問
- **GitHub Discussions**: Community help
- **GitHub Discussions**: コミュニティヘルプ

### Before Asking for Help / ヘルプを求める前に
1. Read relevant documentation
2. 関連ドキュメントを読む
3. Check troubleshooting sections
4. トラブルシューティングセクションを確認
5. Verify your work (solder joints, connections)
6. 自分の作業を確認（はんだ接合、接続）
7. Take clear photos of your issue
8. 問題の明確な写真を撮る

## Success Tips / 成功のヒント

1. **Don't Rush** - Take your time, especially with SMD soldering
   **急がない** - 特にSMDはんだ付けでは時間をかける

2. **Test As You Go** - Test each section before moving to next
   **進行中にテスト** - 次に移る前に各セクションをテスト

3. **Stay Organized** - Keep components labeled and organized
   **整理整頓** - 部品にラベルを付けて整理

4. **Use Good Tools** - Quality soldering iron makes big difference
   **良い工具を使う** - 品質の良いはんだごてが大きな違いを生む

5. **Practice First** - Practice SMD soldering on old PCBs
   **最初に練習** - 古いPCBでSMDはんだ付けを練習

6. **Ask for Help** - Don't hesitate to ask community
   **助けを求める** - コミュニティに質問することをためらわない

## What's Next? / 次は何？

After completing your build:
- Share photos on GitHub Discussions
- GitHubディスカッションで写真を共有
- Contribute improvements (firmware, case designs)
- 改善点を貢献（ファームウェア、ケース設計）
- Help other builders
- 他のビルダーを助ける
- Consider variations (battery power, external antenna)
- バリエーションを検討（バッテリー電源、外部アンテナ）

## Conclusion / 結論

Building the A2DP Tiny Radio is a rewarding project that combines hardware design, firmware programming, and mechanical design. Take your time, follow the guides, and enjoy the process!

A2DP Tiny Radioの製作は、ハードウェア設計、ファームウェアプログラミング、機械設計を組み合わせたやりがいのあるプロジェクトです。時間をかけて、ガイドに従い、プロセスを楽しんでください！

Good luck! / 頑張ってください！

---

**Questions? / 質問がありますか？**
Open an issue on GitHub: https://github.com/g0tt/a2dp-tiny-radio/issues
