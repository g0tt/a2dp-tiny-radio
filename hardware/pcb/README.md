# KiCad PCB Layout Files

## Overview
This directory should contain the KiCad PCB layout files for the A2DP Tiny Radio project.

## Required Files
To complete the PCB design, create the following files using KiCad 6.0 or later:

### Project Files
- `a2dp_radio.kicad_pcb` - PCB layout file
- `a2dp_radio.kicad_pro` - Project file (shared with schematic)

### Manufacturing Files (Generated)
```
gerbers/
├── a2dp_radio-F_Cu.gbr          (Top copper)
├── a2dp_radio-B_Cu.gbr          (Bottom copper)
├── a2dp_radio-F_Mask.gbr        (Top solder mask)
├── a2dp_radio-B_Mask.gbr        (Bottom solder mask)
├── a2dp_radio-F_SilkS.gbr       (Top silkscreen)
├── a2dp_radio-B_SilkS.gbr       (Bottom silkscreen)
├── a2dp_radio-Edge_Cuts.gbr     (Board outline)
├── a2dp_radio-NPTH.drl          (Non-plated holes)
├── a2dp_radio-PTH.drl           (Plated holes)
└── a2dp_radio-job.gbrjob        (Gerber job file)
```

## Creating the PCB Layout

### Step 1: Start PCB Editor
1. Open KiCad project `a2dp_radio.kicad_pro`
2. Click "PCB Editor" button
3. Or File → New Board from Schematic

### Step 2: Import from Schematic
1. Tools → Update PCB from Schematic (F8)
2. Click "Update PCB"
3. All components appear at cursor - click to place temporarily

### Step 3: Set Board Outline
1. Select Edge.Cuts layer
2. Draw rectangle: 60mm x 20mm
   - Use Grid: 0.5mm for precision
   - Place → Drawing → Rectangle
3. Round corners with 1mm radius (optional for aesthetics)

### Step 4: Define Design Rules

**File → Board Setup → Design Rules → Constraints:**
```
Minimum Track Width:    0.2mm (8mil)
Minimum Clearance:      0.2mm (8mil)
Minimum Via Diameter:   0.6mm
Minimum Via Hole:       0.3mm
Minimum Through-Hole:   0.3mm
Minimum uVia Diameter:  0.4mm (not used)
```

**Track Width Classes:**
```
Power (5V):       0.5mm
Power (3.3V):     0.4mm
Signal:           0.25mm
I2C:              0.3mm
Audio:            0.3mm
Ground:           Use copper pour
```

**Via Sizes:**
```
Standard:         0.6mm drill, 1.0mm pad
Power:            0.8mm drill, 1.2mm pad
```

### Step 5: Component Placement

Follow the layout strategy from `PCB_DESIGN_GUIDE.md`:

**Left to Right Placement:**
```
[USB-C] → [Power] → [MCU] → [Radio] → [BT/Display] → [Audio Jack]
  5mm      15mm      25mm     10mm       15mm            5mm
```

**Top Layer Components:**
1. **USB-C connector (J1)** - Left edge, centered vertically
2. **Power section** - Near USB input
   - D1, L1, C13 (bulk cap)
   - U4 (voltage regulator)
   - C9, C10 (regulator caps)
   - LED1, R6 (power indicator)

3. **Microcontroller (U1)** - Central position
   - Orient with pin 1 toward top-left
   - Place crystals Y1 near MCU
   - Place C7, C8 load caps close to crystal
   - Place C1, C2 decoupling caps at VCC pins

4. **RDA5807M (U2)** - Right of MCU
   - Orient for minimal trace lengths to antenna
   - Place Y2 (32.768kHz) adjacent
   - Place C3 decoupling cap close to VCC
   - Keep away from USB (noise isolation)

5. **Bluetooth module (U3)** - Right side
   - Can overlap with display if height permits
   - Place C4 decoupling cap close
   - LED2 visible from top

6. **OLED display (U5)** - Top center
   - Position to be visible through case window
   - 4-pin header or direct mount

7. **Buttons (SW1-3)** - Top surface, right side
   - Equal spacing (8mm apart)
   - Accessible through case holes
   - Pull-up resistors R2, R3 nearby

8. **3.5mm jack (J2)** - Right edge, centered
   - Through-hole component
   - C11, C12 coupling caps close to RDA5807M

9. **I2C pull-ups (R4, R5)** - Near MCU

**Bottom Layer:**
- Minimize bottom-side components
- Only small passive components if necessary
- Keep clear for mounting

### Step 6: Routing

**Layer Stackup:**
- **Top (F.Cu)**: Signal routing + ground pour
- **Bottom (B.Cu)**: Solid ground plane

**Routing Order:**
1. **Power traces first** (5V, 3.3V, GND)
   - 5V: 0.5mm width
   - 3.3V: 0.4mm width
   - Short and direct paths
   - Star topology from regulator

2. **Critical signals** (I2C, UART, audio)
   - I2C: Keep SDA and SCL parallel, equal length
   - I2C traces: 0.3mm width
   - UART: Standard routing, 0.25mm width
   - Audio: Keep away from digital signals

3. **Clock signals** (crystal connections)
   - Short traces
   - Ground plane under crystal
   - No vias in crystal traces if possible

4. **Button signals**
   - Standard routing
   - 0.25mm width

5. **Remaining signals**
   - Complete routing
   - Avoid acute angles (use 45° or curves)

**Special Routing Rules:**
- **FM antenna trace** (3.5mm jack to RDA5807M)
  - 0.3mm width
  - Clearance from other signals
  - No ground pour under antenna trace
  - Route away from USB

- **USB power traces**
  - 0.6mm width minimum
  - Short and direct
  - Via fence around USB connector

### Step 7: Copper Pours

**Top Copper Pour:**
1. Select F.Cu layer
2. Place → Zone
3. Net: GND
4. Clearance: 0.2mm
5. Thermal relief: Yes (spoke width 0.3mm)
6. Fill zone covering entire board
7. Exclude under FM antenna trace

**Bottom Copper Pour:**
1. Select B.Cu layer
2. Place → Zone
3. Net: GND
4. Solid ground plane
5. Fill entire board area

**Ground Stitching:**
- Add vias connecting top and bottom ground
- Spacing: Every 5mm around board perimeter
- Via array under ICs for thermal relief
- Especially around USB connector

### Step 8: Mounting Holes

Add 4x mounting holes:
- Diameter: 2.2mm (for M2 screws)
- Positions: 3mm from each corner
- Connected to GND net
- Add keepout zones around holes

### Step 9: Silkscreen

**Add labels:**
- Component designators (R1, U1, etc.)
- Polarity markings for LEDs, diodes, electrolytics
- Pin 1 indicators for ICs (dot or triangle)
- Button functions (CH+, CH-, MODE)
- Board name: "A2DP Tiny Radio v1.0"
- I2C addresses for reference
- Fiducial markers (3 asymmetric positions)

**Silkscreen rules:**
- Text size: 1.0mm height minimum
- Line width: 0.15mm minimum
- No silkscreen on pads
- High contrast (white on green)

### Step 10: Design Rule Check (DRC)

1. Tools → Design Rule Checker
2. Run DRC
3. Fix all errors:
   - Clearance violations
   - Track width violations
   - Unconnected nets
   - Missing footprints

4. Fix warnings as appropriate
5. Re-run until clean

### Step 11: 3D Viewer

1. View → 3D Viewer
2. Verify:
   - Component placement looks correct
   - No physical interferences
   - Connectors accessible
   - Mounting holes positioned correctly
   - Overall aesthetics

3. Take screenshots for documentation
4. Export 3D model (STEP format) for case design

### Step 12: Generate Manufacturing Files

**For JLCPCB:**

1. **Gerber Files:**
   ```
   File → Plot
   Format: Gerber
   Output directory: gerbers/
   Layers to plot:
     ☑ F.Cu
     ☑ B.Cu
     ☑ F.SilkS
     ☑ B.SilkS
     ☑ F.Mask
     ☑ B.Mask
     ☑ Edge.Cuts
   
   Options:
     ☑ Use Protel filename extensions
     ☑ Subtract soldermask from silkscreen
     ☑ Plot footprint values
     ☑ Plot reference designators
   
   Click "Plot"
   ```

2. **Drill Files:**
   ```
   File → Fabrication Outputs → Drill Files
   Output directory: gerbers/
   Format: Excellon
   Zeros format: Decimal
   Click "Generate Drill File"
   ```

3. **Zip Gerbers:**
   ```
   cd gerbers/
   zip a2dp_radio_gerbers.zip *.gbr *.drl *.gbrjob
   ```

4. **BOM for Assembly:**
   ```
   File → Fabrication Outputs → BOM
   Format: CSV
   Include: Only components for assembly
   Columns: Designator, Value, Package, JLCPCB Part#
   ```

5. **Pick and Place File:**
   ```
   File → Fabrication Outputs → Component Placement
   Format: CSV
   Units: Millimeters
   Include: Only top-side components
   ```

## Ordering from JLCPCB

### Upload Gerbers
1. Go to https://cart.jlcpcb.com/quote
2. Click "Add gerber file"
3. Upload `a2dp_radio_gerbers.zip`

### PCB Specifications
```
Base Material:              FR-4
Layers:                     2
Dimensions:                 60mm x 20mm
PCB Qty:                    5 (minimum)
PCB Thickness:              1.6mm
PCB Color:                  Green (or choose)
Silkscreen:                 White
Surface Finish:             HASL (or ENIG for better)
Copper Weight:              1 oz
Gold Fingers:               No
Confirm Production File:    No
Flying Probe Test:          Fully Test
Castellated Holes:          No
Remove Order Number:        Specify location (or No)
```

### Assembly Service (Optional)
If using JLCPCB assembly:
1. Enable "SMT Assembly"
2. Upload BOM CSV
3. Upload Pick-and-place CSV
4. Review component availability
5. Confirm assembly positions

**Note:** Some components may need to be hand-soldered:
- RDA5807M (if not in JLCPCB library)
- JDY-64 module
- OLED display
- 3.5mm jack
- Any unavailable components

## Design Verification Checklist

Before ordering PCBs:
- [ ] All components have footprints
- [ ] Board dimensions correct (60x20mm)
- [ ] DRC passes with no errors
- [ ] 3D view looks correct
- [ ] Mounting holes present and positioned
- [ ] USB-C connector accessible
- [ ] 3.5mm jack accessible
- [ ] Button positions correct for case
- [ ] Display window position correct
- [ ] Silkscreen readable and accurate
- [ ] Fiducials placed (if using assembly)
- [ ] Gerbers generated correctly
- [ ] Drill files generated
- [ ] BOM matches schematic
- [ ] Test points accessible (if added)

## Post-Production

After receiving PCBs:
1. **Visual inspection**
   - Check for manufacturing defects
   - Verify dimensions
   - Check silkscreen quality

2. **Electrical test**
   - Continuity test for power rails
   - Check for shorts (5V to GND, 3.3V to GND)
   - Verify traces not broken

3. **Assembly**
   - Follow assembly guide in `docs/ASSEMBLY_GUIDE.md`
   - Start with smallest components
   - Test after each major section

## Tips and Best Practices

### Thermal Management
- Thermal vias under QFN packages (RDA5807M)
- Thermal relief for AMS1117-3.3
- Adequate copper area for heat dissipation

### Signal Integrity
- Keep high-speed signals short
- Use ground plane for return paths
- Separate analog and digital sections
- FM antenna isolation from digital

### Manufacturability
- Meet minimum feature sizes
- Adequate clearances
- No acute angles in traces
- Smooth transitions in trace widths
- Teardrops on vias (optional but recommended)

### Testing
- Add test points for critical nets
- Accessible programming header (ISP)
- Easy access to power rails for measurement

## Status

⚠️ **Not Started** - KiCad PCB files need to be created

This directory contains documentation only. Actual PCB layout files should be created following the guidelines above and the PCB design guide in `PCB_DESIGN_GUIDE.md`.

## Support

If you need help creating the PCB layout:
- KiCad documentation: https://docs.kicad.org/
- KiCad forums: https://forum.kicad.info/
- PCB design tutorials: YouTube, Hackaday, EEVblog
- JLCPCB capabilities: https://jlcpcb.com/capabilities/Capabilities
- This project's GitHub Discussions

## References
- [IPC-2221 PCB Design Standard](https://www.ipc.org/TOC/IPC-2221.pdf)
- [JLCPCB Capabilities](https://jlcpcb.com/capabilities/Capabilities)
- [KiCad PCB Tutorial](https://docs.kicad.org/master/en/getting_started_in_kicad/getting_started_in_kicad.html)
