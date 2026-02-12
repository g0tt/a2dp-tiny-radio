# PCB Design Guide - A2DP Tiny Radio / PCB設計ガイド - A2DP Tiny Radio

## Overview / 概要

This document provides guidelines for designing the PCB for the A2DP Tiny Radio. The design targets JLCPCB manufacturing capabilities.

このドキュメントは、A2DP Tiny RadioのPCB設計に関するガイドラインを提供します。設計はJLCPCB製造能力を対象としています。

## Board Specifications / 基板仕様

### Dimensions / 寸法

- **Length / 長さ**: 60mm
- **Width / 幅**: 20mm
- **Thickness / 厚さ**: 1.6mm (standard / 標準)
- **Layers / レイヤー数**: 2 (Top and Bottom / 表面と裏面)

### Manufacturing Specs (JLCPCB Compatible) / 製造仕様（JLCPCB互換）

```
PCB Material / 基板材料:        FR-4
Layers / レイヤー数:              2
Thickness / 厚さ:           1.6mm
Min Track Width / 最小配線幅:     0.2mm (8mil)
Min Track Spacing / 最小配線間隔:   0.2mm (8mil)
Min Hole Size / 最小穴サイズ:       0.3mm
Surface Finish / 表面処理:      HASL or ENIG
Copper Weight / 銅箔厚:       1oz (35μm)
Solder Mask / ソルダーマスク:         Green (or Blue/Black) / 緑（または青/黒）
Silkscreen / シルクスクリーン:          White / 白
Edge Connector / エッジコネクタ:      No / なし
Gold Fingers / 金メッキ指:        No / なし
```

## Layer Stack-up

### Top Layer (Component Side)
- Signal traces
- Component pads
- Ground pour (with clearance for signals)
- Silkscreen labels

### Bottom Layer (Ground Side)
- Solid ground plane (primary)
- Critical signal return paths
- Component pads (if needed)
- Minimal routing (avoid if possible)

## Component Placement Strategy

### Layout Zones
```
[USB-C] [Power Section] [MCU & Radio] [Display] [3.5mm Jack]
  5mm        15mm           25mm          10mm      5mm
```

### Top Side Components
1. **Left End (USB Input)**
   - J1: USB-C receptacle
   - D1: Schottky diode
   - L1: Ferrite bead
   - C13: 47μF bulk capacitor

2. **Power Section**
   - U4: AMS1117-3.3 voltage regulator
   - C9, C10: 10μF capacitors
   - LED1: Power indicator
   - R6: LED resistor

3. **Microcontroller Section**
   - U1: ATmega328P (TQFP-32)
   - Y1: 16MHz crystal
   - C7, C8: 22pF load capacitors
   - C1, C2: 100nF decoupling
   - R1: 10kΩ reset pull-up
   - SW4: Reset button (optional)

4. **Radio Section**
   - U2: RDA5807M (QFN-20)
   - Y2: 32.768kHz crystal
   - C3: 100nF decoupling
   - C11, C12: 1μF audio coupling

5. **Bluetooth Section**
   - U3: JDY-64 module (on header or direct solder)
   - C4: 100nF decoupling
   - LED2: Bluetooth status LED
   - R7: LED resistor

6. **Display Section**
   - U5: 0.91" OLED module (header mount)
   - C5: 100nF decoupling

7. **User Interface**
   - SW1, SW2, SW3: Tactile switches
   - R2, R3: 10kΩ pull-ups

8. **Right End (Audio Output)**
   - J2: 3.5mm audio jack
   - R8, R9: 100Ω series resistors

### Bottom Side Components
- Minimize bottom-side components
- Small passive components only if space constrained
- Keep bottom clear for mounting/case

## Routing Guidelines

### Power Traces
- **5V Rail**: 0.5mm minimum width
- **3.3V Rail**: 0.4mm minimum width
- **Ground**: Solid plane on bottom layer, flood fill on top

### Signal Routing
1. **I2C Bus (SDA/SCL)**
   - Route as parallel pair
   - Keep traces short (<100mm)
   - 0.3mm trace width
   - Add pull-up resistors near MCU

2. **UART (Bluetooth)**
   - TX and RX traces
   - 0.25mm trace width
   - Keep away from FM antenna traces

3. **Audio Signals**
   - LOUT and ROUT from RDA5807M to 3.5mm jack
   - 0.3mm trace width
   - Route as differential pair if possible
   - Keep away from digital signals

4. **FM Antenna**
   - 3.5mm jack to RDA5807M antenna input
   - 0.3mm trace width
   - Keep away from USB and high-speed signals
   - Ground plane clearance around antenna trace

5. **USB Power**
   - VBUS and GND from USB-C
   - 0.6mm trace width
   - Short and direct path to power section

### Critical Routing Rules
- **No 90° angles**: Use 45° or curved traces
- **Trace length matching**: Not critical for this design
- **Via usage**: Minimize vias in high-speed paths
- **Ground stitching**: Add vias around perimeter (every 5mm)

## Ground Plane Design

### Top Layer Ground
- Flood fill with clearance for signals
- Connect to bottom ground with multiple vias
- Keep clear of antenna traces

### Bottom Layer Ground
- Solid pour covering entire board
- Split ground only if necessary (not recommended)
- Connect analog and digital grounds at single point near power supply

### Ground Connection Points
- Multiple vias under each IC for heat dissipation
- Via fence around USB connector
- Ground stitching vias every 5mm around board edge

## Thermal Management

### AMS1117 Voltage Regulator
- Add thermal relief on ground connections
- Use copper pour under device for heat spreading
- Consider thermal via array under package
- Maximum dissipation: ~1W (from 5V to 3.3V @ 250mA)

### QFN Package (RDA5807M)
- Thermal pad must be soldered to PCB
- Add thermal vias under thermal pad (4x 0.3mm vias)
- Connect to ground plane

## Design for Manufacturing (DFM)

### Component Clearances
- IC to board edge: >3mm
- Component to component: >1mm
- Component to mounting hole: >3mm

### Mounting Holes
- 4x M2 mounting holes (2.2mm diameter)
- Located in corners with 3mm edge clearance
- Connected to ground plane
- Clearance from components: >3mm

### Fiducials
- Add 3 fiducials for automated assembly
- 1mm diameter copper circle
- 2mm solder mask clearance
- Asymmetric placement for orientation

### Silkscreen
- Component designators (U1, R1, etc.)
- Polarity markings for diodes and LEDs
- Pin 1 indicators for ICs
- Board name and version number
- I2C addresses for reference
- Button labels

### Solder Mask
- Standard solder mask expansion: 0.1mm
- No solder mask on pads
- Solder mask between fine-pitch pins

### Paste Stencil (Optional)
- For SMD assembly
- QFN package: reduced paste for thermal pad (50-80%)
- Standard paste for other pads

## JLCPCB Assembly Service

### SMT Assembly
JLCPCB offers assembly service for basic components:
- Resistors, capacitors, diodes, LEDs
- Basic ICs in common packages
- Not all specialized modules may be available

### Parts to Hand-Solder
- RDA5807M (QFN-20) - may not be in JLCPCB library
- JDY-64 Bluetooth module
- OLED display module
- 3.5mm audio jack
- USB-C connector (if not in library)
- Tactile switches

## Design Files for Manufacturing

### Required Files for JLCPCB
1. **Gerber Files** (RS-274X format)
   - Top Copper (GTL)
   - Bottom Copper (GBL)
   - Top Solder Mask (GTS)
   - Bottom Solder Mask (GBS)
   - Top Silkscreen (GTO)
   - Bottom Silkscreen (GBO)
   - Board Outline (GML/GKO)
   - Drill File (TXT or DRL)

2. **Bill of Materials (BOM)**
   - CSV format
   - Columns: Designator, Value, Package, JLCPCB Part#
   - Only for components to be assembled by JLCPCB

3. **Pick and Place File (CPL)**
   - CSV format
   - Columns: Designator, X, Y, Rotation, Layer
   - Coordinates in millimeters

### KiCad Export Settings
```
File → Plot
  Plot Format: Gerber
  Include Layers: All copper, solder mask, silkscreen, Edge.Cuts
  Options:
    ☑ Use Protel filename extensions
    ☑ Subtract solder mask from silkscreen
    ☑ Plot footprint values
    ☑ Plot reference designators
    
File → Fabrication Outputs → Drill Files
  Format: Excellon
  Zeros Format: Decimal
  
File → Fabrication Outputs → BOM
  Format: CSV
  Fields: Reference, Value, Footprint, LCSC Part#
```

## Design Verification Checklist

### Electrical
- [ ] All power pins connected to correct voltage
- [ ] All ground pins connected to ground plane
- [ ] Decoupling capacitors placed near IC power pins
- [ ] Pull-up/pull-down resistors on critical signals
- [ ] Correct I2C pull-ups (4.7kΩ to 3.3V for proper voltage levels with 3.3V peripherals) / 正しいI2Cプルアップ（3.3V周辺機器との適切な電圧レベルのため3.3Vへ4.7kΩ）
- [ ] Series resistors on audio output
- [ ] Reverse protection diode oriented correctly
- [ ] LED current limiting resistors present

### Mechanical
- [ ] Board dimensions within specification (60x20mm)
- [ ] Mounting holes positioned correctly
- [ ] Component heights compatible with case
- [ ] USB-C connector accessible from case edge
- [ ] 3.5mm jack accessible from case edge
- [ ] Buttons accessible from case top
- [ ] Display visible through case window

### Manufacturing
- [ ] All traces meet minimum width (0.2mm)
- [ ] All clearances meet minimum spacing (0.2mm)
- [ ] No isolated copper islands
- [ ] Via sizes manufacturable (≥0.3mm)
- [ ] Silkscreen not covering pads
- [ ] Fiducials present and correctly placed
- [ ] Board outline defined in Edge.Cuts layer

### Assembly
- [ ] All components have footprints
- [ ] Footprints match component packages
- [ ] IC pin 1 marked on silkscreen
- [ ] Polarized components marked
- [ ] No components too close to board edge
- [ ] Reference designators readable

## Testing Points

### Add Test Points for Debug
- TP1: 5V rail
- TP2: 3.3V rail
- TP3: Ground
- TP4: I2C SDA
- TP5: I2C SCL
- TP6: UART TX
- TP7: UART RX
- TP8: FM antenna signal

Use 1mm diameter pad with no solder mask for easy probing.

## Panelization (Optional)

For production runs, create panels:
- Multiple boards per panel (e.g., 10 boards on 100x100mm panel)
- 2mm spacing between boards
- V-score or tab routing for separation
- Add tooling holes for assembly equipment

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial PCB design guide |

## References
- [JLCPCB Capabilities](https://jlcpcb.com/capabilities/Capabilities)
- [KiCad PCB Design Documentation](https://docs.kicad.org/)
- [IPC-2221 PCB Design Standard](https://www.ipc.org/TOC/IPC-2221.pdf)
