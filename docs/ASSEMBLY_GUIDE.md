# A2DP Tiny Radio - Assembly Instructions / 組み立て手順書

## Overview / 概要

This guide provides step-by-step instructions for assembling the A2DP Tiny Radio from components and PCB.

このガイドは、部品とPCBからA2DP Tiny Radioを組み立てるための段階的な手順を提供します。

## Safety Warnings / 安全上の警告

⚠️ **IMPORTANT SAFETY INFORMATION / 重要な安全情報**
- Soldering iron operates at high temperature (350-400°C) / はんだごては高温で動作します（350-400°C）
- Work in well-ventilated area when soldering / はんだ付け時は換気の良い場所で作業してください
- Wear safety glasses when cutting component leads / 部品リード線を切る際は保護メガネを着用してください
- Disconnect power before making any connections / 接続を行う前に電源を切断してください
- Check polarity before connecting power supply / 電源を接続する前に極性を確認してください
- ICs are static-sensitive - use ESD precautions / ICは静電気に敏感です - 静電気対策を使用してください

## Tools Required / 必要な工具

### Essential Tools / 必須工具

- Soldering iron with fine tip (0.5mm or smaller) / 細先はんだごて（0.5mm以下）
- Lead-free solder (0.5mm diameter) / 無鉛はんだ（直径0.5mm）
- Flux (rosin-based or no-clean) / フラックス（ロジンベースまたはノークリーン）
- Solder wick (desoldering braid) / はんだ吸取線
- Tweezers (fine-tip) / ピンセット（細先）
- Wire cutters (flush cut) / ニッパー（フラッシュカット）
- Multimeter / テスター
- Magnifying glass or microscope / 拡大鏡または顕微鏡

### Recommended Tools / 推奨工具

- Hot air rework station (for QFN package) / ホットエアーリワークステーション（QFNパッケージ用）
- Helping hands or PCB holder / はんだ付け補助具またはPCBホルダー
- Isopropyl alcohol (IPA) for cleaning / クリーニング用イソプロピルアルコール（IPA）
- ESD mat and wrist strap / 静電気対策マットとリストストラップ
- Solder paste (for QFN packages) / はんだペースト（QFNパッケージ用）
- Temperature-controlled soldering iron / 温度制御はんだごて

### Programming Tools / プログラミング工具

- USB-UART adapter (for Arduino programming) / USB-UARTアダプタ（Arduinoプログラミング用）
- ISP programmer (for bootloader - optional) / ISPプログラマ（ブートローダー用 - オプション）
- USB-C cable and power supply (5V, 1A minimum) / USB-Cケーブルと電源（5V、1A以上）

## Component Preparation

### Inventory Check
Before starting, verify you have all components from the BOM:
- [ ] ATmega328P-AU (TQFP-32) with Arduino bootloader
- [ ] RDA5807M (QFN-20) FM radio IC
- [ ] JDY-64 Bluetooth module
- [ ] SSD1306 OLED display module
- [ ] All passive components (resistors, capacitors)
- [ ] All connectors (USB-C, 3.5mm jack)
- [ ] Switches, LEDs, crystals, voltage regulator

### Pre-Assembly Testing
Test key components before soldering:
- [ ] Verify ATmega328P has Arduino bootloader
- [ ] Test OLED display module (connect to Arduino)
- [ ] Test Bluetooth module (connect to phone)
- [ ] Check all IC orientations and pin 1 markings

## Assembly Order

The recommended assembly sequence from smallest to largest components:

### Step 1: Solder SMD Passive Components (30-45 minutes)
Smallest components first to avoid shadowing by larger parts.

**1.1 Resistors (0805 package)**
- R1-R9: All 0805 resistors
- Use tweezers to place component
- Tack one end, then solder other end
- Verify values with multimeter if not labeled

**1.2 Ceramic Capacitors (0805 package)**
- C1-C12: 100nF and other ceramic caps
- No polarity - can be placed either direction
- Check values if marking is unclear

**1.3 Crystals**
- Y1: 16MHz crystal (near ATmega328P)
- Y2: 32.768kHz crystal (near RDA5807M)
- Ensure proper orientation and grounding

### Step 2: Solder ICs (45-60 minutes)

**2.1 ATmega328P (TQFP-32)**
- Align pin 1 marker with PCB marking
- Tack opposite corner pins first
- Use drag soldering technique with flux
- Inspect for bridges with magnification
- Clean with IPA after soldering

Tips for TQFP soldering:
1. Apply flux to all pads
2. Tack two opposite corners
3. Add small amount of solder to iron tip
4. Drag along pins, solder will flow to pads
5. Use solder wick to remove bridges
6. Verify connections with multimeter

**2.2 RDA5807M (QFN-20)**
⚠️ Most difficult component - consider using hot air

Method 1: Hot air reflow (recommended)
1. Apply solder paste to pads (stencil or syringe)
2. Place component, align with pads
3. Apply hot air at 350°C, circular motion
4. Watch for solder to melt and component to self-align
5. Allow to cool naturally

Method 2: Soldering iron
1. Pre-tin pads lightly
2. Apply flux generously
3. Place component, align pin 1
4. Tack two opposite corners
5. Carefully solder remaining pins with fine tip
6. Solder thermal pad from bottom via or side vias

**2.3 AMS1117-3.3 Voltage Regulator (SOT-223)**
- Check polarity (pins match silkscreen)
- Solder all three pins
- Ensure good thermal connection to pad

### Step 3: Solder Through-Hole Components (30 minutes)

**3.1 Diode (D1 - SS34)**
- Note polarity: cathode (stripe) matches silkscreen
- Bend leads to fit pad spacing
- Solder from bottom, trim excess leads

**3.2 Electrolytic Capacitor (C13 - 47μF)**
- Check polarity: negative stripe matches marking
- Insert and solder from bottom
- Trim leads

**3.3 USB-C Receptacle (J1)**
- Align carefully with PCB pads
- Solder anchor pins first for stability
- Solder data pins (or power pins if power-only)
- Check for bridges between adjacent pins

**3.4 3.5mm Audio Jack (J2)**
- Insert through holes
- Ensure proper seating
- Solder all pins from bottom

**3.5 Tactile Switches (SW1-SW3)**
- Orient correctly (usually no polarity)
- Push flush against PCB
- Solder all four pins

**3.6 LEDs (LED1, LED2)**
- Check polarity: flat edge = cathode (-)
- Bend leads to appropriate height (5-8mm)
- Solder and trim

### Step 4: Solder Modules (20 minutes)

**4.1 Bluetooth Module (JDY-64)**
Option A: Direct solder (more compact)
- Align module pads with PCB pads
- Solder each pin carefully

Option B: Header pins (easier to replace)
- Solder header pins to PCB
- Plug module onto headers
- Can be removed for testing/replacement

**4.2 OLED Display Module**
Option A: Direct solder (more compact)
- Align display with PCB cutout/window
- Solder 4 pins (VCC, GND, SDA, SCL)

Option B: Socket headers (removable)
- Solder female headers to PCB
- Plug display into headers

### Step 5: Optional Components

**5.1 ISP Programming Header (J3 - optional)**
- 2x3 pin header (2.54mm pitch)
- Solder from top side
- Used for programming ATmega328P bootloader

**5.2 Reset Button (SW4 - optional)**
- Same as other tactile switches
- Convenient for development

## Post-Soldering Inspection

### Visual Inspection
Use magnifying glass or microscope:
- [ ] Check all solder joints are shiny and concave
- [ ] No cold solder joints (dull, grainy appearance)
- [ ] No solder bridges between pins
- [ ] All components properly oriented
- [ ] No missing components
- [ ] Proper polarity on diodes, LEDs, capacitors

### Cleaning
- Remove flux residue with IPA and soft brush
- Dry completely before powering
- Inspect again after cleaning

### Electrical Inspection
Use multimeter in continuity mode:
- [ ] Check for shorts between VCC and GND
- [ ] Verify 5V and 3.3V rails are not shorted
- [ ] Check continuity of critical connections:
  - USB VBUS to power input
  - I2C SDA/SCL connections
  - UART TX/RX connections
  - Audio output to jack

## Initial Power-Up

### Pre-Power Checks
- [ ] Visual inspection complete
- [ ] No shorts between power and ground
- [ ] All ICs properly oriented (check pin 1)
- [ ] Proper polarity on all polarized components

### First Power Application
1. **Connect USB-C cable to power supply**
   - Use known-good 5V USB power supply
   - Do NOT connect to computer USB port yet
   
2. **Check LED1 (Power Indicator)**
   - Should illuminate red
   - If not, disconnect immediately and troubleshoot
   
3. **Measure Voltages with Multimeter**
   - 5V rail: Should measure 4.8-5.2V
   - 3.3V rail: Should measure 3.2-3.4V
   - If voltages incorrect, disconnect and troubleshoot

### Troubleshooting Power Issues

**No power LED:**
- Check D1 diode orientation
- Check LED1 polarity
- Verify R6 resistor is installed
- Check USB-C soldering

**No 5V:**
- Check USB-C VBUS connection
- Check D1 diode
- Check ferrite bead L1
- Verify no shorts

**No 3.3V:**
- Check AMS1117-3.3 orientation
- Check input capacitor C9
- Check output capacitor C10
- Verify 5V input is present
- Check for shorts on 3.3V rail

## Firmware Programming

### Method 1: USB-UART Adapter (If Bootloader Present)

**Hardware Connection:**
```
USB-UART    →   ATmega328P
TX          →   RX (Pin 2)
RX          →   TX (Pin 3)
GND         →   GND
```

**Software Steps:**
1. Install Arduino IDE
2. Install required libraries (see firmware README)
3. Open `a2dp_fm_radio.ino`
4. Select Tools → Board → Arduino Uno
5. Select Tools → Port → [Your COM Port]
6. Click Upload

### Method 2: ISP Programmer (For Bootloader or Direct Upload)

**Hardware Connection:**
Connect ISP programmer to J3 header:
```
ISP Pin     →   ATmega328P
MISO        →   PB4 (Pin 18)
VCC         →   5V
SCK         →   PB5 (Pin 19)
MOSI        →   PB3 (Pin 17)
RESET       →   RESET (Pin 1)
GND         →   GND
```

**Software Steps:**
1. Tools → Programmer → [Your ISP Type]
2. Tools → Burn Bootloader (if needed)
3. Sketch → Upload Using Programmer

## Functional Testing

### Test Sequence

**1. Power Test**
- [ ] Power LED illuminates
- [ ] No smoke or excessive heat
- [ ] Voltage rails correct (5V and 3.3V)

**2. Display Test**
- [ ] OLED powers on
- [ ] Displays initialization message
- [ ] Shows "A2DP FM Radio" startup screen

**3. Button Test**
- [ ] Press each button, observe response on display
- [ ] SW1 (Channel Up) increments frequency
- [ ] SW2 (Channel Down) decrements frequency
- [ ] SW3 (Mode) changes display mode

**4. FM Radio Test**
- [ ] Connect earphones to 3.5mm jack (serves as antenna)
- [ ] Tune to known FM station
- [ ] Verify audio output through earphones
- [ ] Check signal strength display
- [ ] Test volume control (if implemented)

**5. Bluetooth Test**
- [ ] Long press Mode button to enter pairing mode
- [ ] LED2 (blue) should flash
- [ ] Device appears in phone's Bluetooth settings as "FMRadio"
- [ ] Pair with phone
- [ ] Verify connection status on display
- [ ] Audio should play through phone's Bluetooth

**6. Preset Test**
- [ ] Save current frequency to preset
- [ ] Switch to different frequency
- [ ] Recall preset
- [ ] Verify frequency restored

## Final Assembly

### Install in Case (If 3D Printed Case Available)
1. Test all functions before closing case
2. Gently place PCB in bottom case shell
3. Align mounting posts with PCB holes
4. Route any internal wiring (if applicable)
5. Place top case shell
6. Secure with snap-fit or screws
7. Test all external access (USB, audio jack, buttons)

### Quality Check
- [ ] All functions working properly
- [ ] No rattling or loose components
- [ ] Clean appearance (no flux residue visible)
- [ ] Buttons actuate smoothly
- [ ] Connectors accessible
- [ ] Display clearly visible

## Troubleshooting Guide

### Display Not Working
**Symptoms:** OLED stays blank
**Possible Causes:**
- Power not reaching display (check 3.3V)
- I2C connection issue
- Wrong I2C address
- Display module defective

**Solutions:**
1. Check 3.3V at display VCC pin
2. Verify I2C pullup resistors (R4, R5)
3. Check SDA/SCL continuity from MCU to display
4. Run I2C scanner sketch to detect address
5. Try different display module

### No FM Reception
**Symptoms:** No audio, low signal strength, scanning finds no stations
**Possible Causes:**
- Earphone not connected (no antenna)
- RDA5807M not initialized
- I2C communication failure
- Wrong frequency band setting
- Crystal not oscillating

**Solutions:**
1. Ensure earphones connected (acts as antenna)
2. Check 3.3V at RDA5807M VCC
3. Verify 32.768kHz crystal placement and soldering
4. Check I2C connections
5. Try known strong local FM station
6. Review RDA5807M datasheet for correct init sequence

### Bluetooth Not Connecting
**Symptoms:** Device not discoverable, won't pair, no audio via BT
**Possible Causes:**
- JDY-64 module not powered
- UART connection issue
- Module not in pairing mode
- Incompatible phone/device

**Solutions:**
1. Check 3.3V at Bluetooth module
2. Verify TX/RX connections (TX→RX, RX→TX)
3. Enter pairing mode manually
4. Check blue LED status
5. Try different phone/device
6. Send AT commands via serial monitor for diagnostics

### Buttons Not Responding
**Symptoms:** Pressing buttons has no effect
**Possible Causes:**
- Switch not soldered properly
- Missing pull-up resistors
- MCU pin not configured correctly
- Firmware issue

**Solutions:**
1. Check continuity when button pressed
2. Verify pull-up resistors installed
3. Check firmware pin configuration
4. Test button with multimeter
5. Reload firmware

### Excessive Heat
**Symptoms:** Voltage regulator or other component very hot
**Possible Causes:**
- Short circuit
- Excessive current draw
- Wrong component value
- Defective component

**Solutions:**
1. Disconnect power immediately
2. Locate hot component
3. Check for shorts around hot component
4. Verify component values
5. Check load on power rails
6. Replace defective component

## Maintenance

### Regular Care
- Keep device dry
- Avoid extreme temperatures
- Clean with soft, dry cloth
- Store in protective case when not in use

### Battery-Free Design
This device is powered by USB only - no battery maintenance required.

### Firmware Updates
- Can be reprogrammed via USB-UART interface
- Preserve custom settings by saving to EEPROM before update
- Follow programming steps as during initial assembly

## Warranty and Support

### Disclaimer
This is a DIY electronics project. Assembly requires soldering skills and is done at your own risk. No warranty is provided for assembled units.

### Community Support
- GitHub Issues: Report bugs or request features
- Documentation: Refer to other docs in this repository
- Forums: Arduino Forum, EEVblog Forum

## Appendix: Advanced Tips

### Improving Solder Joints on QFN
- Use magnification (10x or higher)
- Apply ample flux
- Use temperature-controlled iron (350°C)
- Consider using low-temp solder paste (138°C)
- Hot air station makes this much easier

### Better Audio Quality
- Use quality earphones
- Ensure good ground connection
- Keep audio traces away from digital signals
- Consider adding small RC filter on audio output

### Extended FM Range
Some RDA5807M modules support 64-108MHz:
- Modify firmware to allow wider tuning range
- Check local regulations for legal frequencies

### Adding External Antenna
For better reception without earphones:
- Add 75-80cm wire antenna
- Connect to antenna input of RDA5807M
- May require redesigned PCB or external connector

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial assembly guide |
