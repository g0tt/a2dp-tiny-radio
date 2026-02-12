# KiCad Schematic Files

## Overview
This directory should contain the KiCad schematic files for the A2DP Tiny Radio project.

## Required Files
To complete the schematic design, create the following files using KiCad 6.0 or later:

### Project Files
- `a2dp_radio.kicad_pro` - KiCad project file
- `a2dp_radio.kicad_sch` - Main schematic file
- `a2dp_radio.kicad_sym` - Custom symbol library (if needed)

### Optional Files
- `fp-lib-table` - Footprint library table
- `sym-lib-table` - Symbol library table

## Creating the Schematic

### Step 1: Create New KiCad Project
1. Open KiCad
2. File → New Project
3. Name: `a2dp_radio`
4. Location: This directory

### Step 2: Add Schematic Symbols
Based on the circuit description in `SCHEMATIC_DESCRIPTION.md`, add the following components:

#### Power Supply Section
- USB-C connector (use GCT USB4110-GF-A or similar)
- D1: Schottky diode SS34 (DO-214AC package)
- L1: Ferrite bead 0805
- C13: 47μF electrolytic capacitor
- U4: AMS1117-3.3 voltage regulator (SOT-223)
- C9, C10: 10μF ceramic capacitors

#### Microcontroller Section
- U1: ATmega328P-AU (TQFP-32)
- Y1: 16MHz crystal
- C1, C2: 100nF decoupling capacitors
- C7, C8: 22pF load capacitors
- R1: 10kΩ reset pull-up resistor

#### FM Radio Section
- U2: RDA5807M (QFN-20)
- Y2: 32.768kHz crystal
- C3: 100nF decoupling capacitor
- R4, R5: 4.7kΩ I2C pull-ups
- C11, C12: 1μF audio coupling capacitors

#### Bluetooth Section
- U3: JDY-64 module connector
- C4: 100nF decoupling capacitor
- LED2: Blue LED with R7 (1kΩ) current limiting resistor

#### Display Section
- U5: OLED display connector (4-pin: VCC, GND, SDA, SCL)
- C5: 100nF decoupling capacitor

#### User Interface
- SW1, SW2, SW3: Tactile switches 6x6mm
- R2, R3: 10kΩ pull-up resistors
- LED1: Red power LED with R6 (1kΩ) resistor
- J2: PJ-320A 3.5mm audio jack

### Step 3: Connect Components
Follow the connection diagram in `SCHEMATIC_DESCRIPTION.md`:

**Power Rails:**
- 5V from USB-C through D1 and L1
- 3.3V from AMS1117-3.3 output
- Ground plane connections

**I2C Bus:**
- ATmega328P SDA (PC4/A4) → RDA5807M SDA, OLED SDA
- ATmega328P SCL (PC5/A5) → RDA5807M SCL, OLED SCL
- 4.7kΩ pull-ups to 5V

**UART:**
- ATmega328P TX (PD1) → JDY-64 RX
- ATmega328P RX (PD0) → JDY-64 TX

**Buttons:**
- SW1 → PD2 (with R2 pull-up)
- SW2 → PD3 (with R3 pull-up)
- SW3 → PD6 (internal pull-up)

**Audio:**
- RDA5807M LOUT/ROUT → J2 via C11/C12 coupling capacitors

### Step 4: Add Power Symbols
- VCC (5V)
- +3.3V
- GND

### Step 5: Annotate Schematic
Tools → Annotate Schematic
- Use default settings
- Update reference designators (U1, R1, etc.)

### Step 6: Electrical Rules Check (ERC)
Inspect → Electrical Rules Checker
- Fix any errors or warnings
- Verify all nets are properly connected
- Check for missing connections

### Step 7: Assign Footprints
Tools → Assign Footprints

**Recommended Footprints:**
- ATmega328P-AU: TQFP-32_7x7mm_P0.8mm
- RDA5807M: QFN-20-1EP_4x4mm_P0.5mm
- AMS1117-3.3: SOT-223
- Resistors/Capacitors: 0805 (2012 metric)
- Tactile switches: SW_SPST_6mm
- USB-C: USB_C_Receptacle_GCT_USB4110
- 3.5mm jack: Jack_3.5mm_PJ320A_Horizontal

### Step 8: Generate Netlist
File → Export → Netlist
- Save as `a2dp_radio.net`

### Step 9: Generate BOM
File → Export → BOM
- Use built-in BOM generator or plugin
- Export as CSV for easy import

## Symbol Libraries

### Standard Libraries Used
- Device (resistors, capacitors, LEDs, etc.)
- Connector (USB-C, audio jack, headers)
- MCU_Microchip_ATmega (ATmega328P)
- Regulator_Linear (AMS1117)

### Custom Symbols Needed
You may need to create custom symbols for:
- RDA5807M (if not in standard library)
- JDY-64 Bluetooth module
- SSD1306 OLED display connector

To create custom symbols:
1. Tools → Symbol Editor
2. File → New Symbol
3. Draw symbol outline and pins
4. Set electrical types for pins
5. Save to project library

## Datasheet References

Download and reference these datasheets while creating the schematic:
- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328P-Datasheet.pdf)
- [RDA5807M Datasheet](https://www.sparkfun.com/datasheets/Wireless/General/RDA5807M.pdf)
- [AMS1117 Datasheet](http://www.advanced-monolithic.com/pdf/ds1117.pdf)

## Tips for KiCad

### Keyboard Shortcuts
- `A` - Add symbol
- `W` - Add wire
- `L` - Add label
- `P` - Add power symbol
- `M` - Move item
- `R` - Rotate item
- `E` - Edit item properties

### Best Practices
1. **Use hierarchical sheets** for complex designs (optional for this project)
2. **Add net labels** for connections between sheets
3. **Use global labels** for power and ground
4. **Group related components** visually on schematic
5. **Add notes and documentation** directly on schematic
6. **Use consistent naming** for nets and components
7. **Run ERC frequently** during design process

## Export Formats

### For Documentation
- PDF: File → Plot → PDF
- PNG: File → Export → Export Drawing to Clipboard

### For PCB Design
- Netlist: File → Export → Netlist

### For Review
- Print: File → Print
- PDF with all sheets combined

## Version Control

### Files to Commit
- ✅ .kicad_pro
- ✅ .kicad_sch
- ✅ .kicad_sym (custom library)
- ✅ fp-lib-table
- ✅ sym-lib-table

### Files to Ignore (.gitignore)
- ❌ *-backups/
- ❌ *.bak
- ❌ *~
- ❌ *.tmp
- ❌ *.net (can regenerate)

## Next Steps

After completing the schematic:
1. Review against circuit description
2. Run ERC and fix all errors
3. Assign footprints
4. Generate netlist
5. Proceed to PCB layout in `../pcb/` directory

## Status

⚠️ **Not Started** - KiCad schematic files need to be created

This directory contains documentation only. Actual schematic files should be created following the guidelines above and the circuit description in `SCHEMATIC_DESCRIPTION.md`.

## Support

If you need help creating the schematic:
- KiCad documentation: https://docs.kicad.org/
- KiCad forums: https://forum.kicad.info/
- YouTube tutorials: Search "KiCad tutorial"
- This project's GitHub Discussions
