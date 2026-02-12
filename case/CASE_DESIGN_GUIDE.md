# 3D Printable Case Design - A2DP Tiny Radio

## Overview
This document provides specifications and guidelines for designing a 3D printable case for the A2DP Tiny Radio device.

## Case Dimensions

### External Dimensions
- **Length**: 65mm (PCB 60mm + 2.5mm margin each end)
- **Width**: 24mm (PCB 20mm + 2mm margin each side)
- **Height**: 14mm (PCB 10mm + components clearance)
- **Wall Thickness**: 2mm
- **Form Factor**: USB memory stick style

### Internal Clearances
- **PCB to case bottom**: 1mm
- **PCB to case top**: 3mm (for component heights)
- **PCB to case sides**: 2mm
- **Component clearance**: Minimum 0.5mm all sides

## Design Requirements

### Functional Features
1. **USB-C Port Opening**
   - Location: Center of left end
   - Size: 9mm x 3.5mm
   - Depth: 6mm inset from edge
   - Must allow full insertion of USB-C cable

2. **3.5mm Audio Jack Opening**
   - Location: Center of right end
   - Diameter: 6mm (for 3.5mm jack body)
   - Depth: Through entire end panel
   - Must allow earphone plug insertion

3. **Button Access**
   - 3 buttons on top surface
   - Button locations: 20mm, 30mm, 40mm from left edge
   - Hole diameter: 5mm
   - Depth: Through top panel
   - Consider adding tactile caps or actuators

4. **Display Window**
   - Location: Top surface, centered
   - Size: 32mm x 14mm
   - Position: 10mm from left edge
   - Options:
     - Open window with raised rim
     - Clear acrylic insert
     - Transparent filament inlay

5. **LED Indicators**
   - 2 LED light pipes or holes
   - Diameter: 2mm each
   - Location: Front face, near USB port
   - One red (power), one blue (Bluetooth)

6. **Ventilation**
   - Optional: Small ventilation slots on sides
   - Slot size: 0.5mm x 8mm
   - For heat dissipation from voltage regulator

### Assembly Method

#### Two-Part Case (Recommended)
```
[Top Shell]
    ↓
[PCB with Components]
    ↓
[Bottom Shell]
```

**Features:**
- Top and bottom shells snap together
- PCB slides in from one end
- Mounting posts hold PCB
- Snap-fit latches or screws for closure

#### Mounting Method 1: Snap-Fit
- 4 snap-fit latches (2 per long side)
- Latch height: 0.5mm
- Engagement angle: 30°
- Requires slight case flexing for assembly

#### Mounting Method 2: Screws (More Secure)
- 2 x M2 screws
- Self-tapping plastic screws or heat-set inserts
- Screw posts in corners
- Access from bottom of case

### PCB Mounting

#### Internal Support Posts
- 4 posts matching PCB mounting holes
- Post diameter: 3.5mm
- Post height: 1mm above case bottom
- PCB rests on top of posts
- Optional: Add M2 heat-set inserts

#### Alignment Ribs
- Internal ribs along PCB edges
- Height: 0.5mm
- Spacing: 0.2mm clearance from PCB edge
- Prevents lateral PCB movement

## 3D Printing Specifications

### Recommended Materials

#### PLA (Polylactic Acid)
- **Pros**: Easy to print, low warping, good detail
- **Cons**: Lower heat resistance (~60°C)
- **Settings**: 
  - Layer height: 0.2mm
  - Infill: 20%
  - Wall thickness: 3 perimeters (2mm)
  - Temperature: 200-210°C nozzle, 60°C bed

#### PETG (Polyethylene Terephthalate Glycol)
- **Pros**: Stronger, more heat resistant (~80°C), more flexible
- **Cons**: Slightly harder to print, some stringing
- **Settings**:
  - Layer height: 0.2mm
  - Infill: 20%
  - Wall thickness: 3 perimeters (2mm)
  - Temperature: 230-250°C nozzle, 70-80°C bed

#### ABS (Acrylonitrile Butadiene Styrene)
- **Pros**: Strong, heat resistant, can be smoothed with acetone
- **Cons**: Requires heated enclosure, warping issues, fumes
- **Settings**:
  - Layer height: 0.2mm
  - Infill: 25%
  - Wall thickness: 3 perimeters (2mm)
  - Temperature: 230-250°C nozzle, 100°C bed
  - Enclosure required

### Print Orientation

#### Bottom Shell
- Print with outer face down
- Requires no supports
- Posts print upward (good for strength)

#### Top Shell
- Print with outer face down
- Minimal supports needed for button holes
- Display window opening faces bed

### Post-Processing

#### Removing Supports
- Clean up support material carefully
- Use flush cutters and files
- Sand snap-fit latches for smooth operation

#### Fitting Test
- Test fit PCB before final assembly
- Check all openings align with connectors
- Verify button actuation
- Ensure display is visible

#### Surface Finishing (Optional)
- Light sanding with 220-400 grit
- Vapor smoothing for ABS (acetone)
- Paint or coating (ensure ventilation holes remain open)

## Design Variations

### Minimalist Case
- Single piece with removable back plate
- Thinner walls (1.5mm)
- No decorative elements
- Focus on size reduction

### Premium Case
- Two-color printing
- Chamfered edges
- Textured grip surfaces
- Magnetic closure
- Integrated keychain attachment

### Modular Case
- Replaceable faceplates
- Customizable button caps
- Multiple color options
- Allow user customization

## CAD File Format

### Native Format
- **Recommended**: Fusion 360 (.f3d) or FreeCAD (.FCStd)
- Fully parametric design
- Easy to modify dimensions

### Export Formats for 3D Printing
1. **STL** (Standard Tessellation Language)
   - Resolution: High (0.01mm tolerance)
   - Binary format preferred
   - Separate files for each part:
     - `a2dp_radio_case_top.stl`
     - `a2dp_radio_case_bottom.stl`
     - `a2dp_radio_button_caps.stl` (optional)

2. **3MF** (3D Manufacturing Format)
   - Includes color and material information
   - Better than STL for multi-material prints
   - Single file can contain all parts

3. **STEP** (.stp/.step)
   - For users who want to modify design
   - Retains some parametric information
   - Universal CAD format

## Design Checklist

### Structural
- [ ] Wall thickness ≥2mm for strength
- [ ] No overhangs >45° without supports
- [ ] Filleted internal corners (1mm radius) for stress relief
- [ ] Snap-fit latches have appropriate draft angles
- [ ] Screw posts have sufficient wall thickness

### Functional
- [ ] USB-C opening large enough for cable strain relief
- [ ] 3.5mm jack opening allows plug insertion
- [ ] Button holes align with switch positions
- [ ] Display window aligns with OLED screen
- [ ] LED light pipes align with LEDs
- [ ] PCB fits snugly without forcing
- [ ] Case can be assembled/disassembled

### Printability
- [ ] All parts fit within common 3D printer build volume (200x200mm)
- [ ] Support material minimized
- [ ] Overhangs avoided where possible
- [ ] Bridging distances <10mm
- [ ] Layer adhesion considered for strength

### Aesthetics
- [ ] Smooth surfaces (no artifacts)
- [ ] Symmetrical where appropriate
- [ ] Clean lines and edges
- [ ] Professional appearance
- [ ] Branding area (if desired)

## Assembly Instructions

### Tools Required
- Small Phillips screwdriver (if using screws)
- Soldering iron (for heat-set inserts, optional)
- Flush cutters (for removing supports)
- Small file or sandpaper

### Assembly Steps
1. **Prepare Case Parts**
   - Remove all support material
   - Clean out openings (USB, audio, buttons)
   - Test fit LED light pipes

2. **Install Heat-Set Inserts** (if using screw assembly)
   - Heat inserts with soldering iron
   - Press into screw posts
   - Allow to cool

3. **Prepare PCB**
   - Ensure all components soldered
   - Test functionality before assembly
   - Program firmware

4. **Install PCB**
   - Slide PCB into bottom shell
   - Align mounting holes with posts
   - Ensure connectors align with openings

5. **Install Button Actuators** (if using)
   - Place button caps over tactile switches
   - Ensure proper alignment with case holes

6. **Close Case**
   - Place top shell over PCB
   - Press snap-fit latches until clicked
   - Or insert and tighten screws

7. **Final Check**
   - Verify all buttons actuate
   - Check USB-C and audio jack accessibility
   - Confirm display visible
   - Test device functionality

## Customization Ideas

### User Modifications
- Engrave name or logo on top surface
- Multi-color printing with filament swap
- Add lanyard attachment point
- Integrate belt clip
- Add rubber feet on bottom
- Create cradle/dock for desk use

### Advanced Features
- Integrated speaker compartment (add small speaker)
- Battery compartment (if adding battery power)
- Cable management for earphones
- Magnetic mount system

## Example Design Workflow

### Using Fusion 360
1. Create new design
2. Define parameters (length, width, height, wall thickness)
3. Sketch bottom shell profile
4. Extrude walls (shell command)
5. Add mounting posts
6. Create openings for connectors
7. Add snap-fit features or screw posts
8. Mirror/copy to create top shell
9. Add button holes and display window
10. Export STL files

### Using FreeCAD
1. Start new project
2. Create sketches for case profiles
3. Use Part Design workbench
4. Pad and pocket operations for features
5. Use Draft workbench for chamfers/fillets
6. Boolean operations for openings
7. Export mesh as STL

### Using OpenSCAD (Parametric Code)
1. Define all dimensions as variables
2. Create modules for each feature
3. Use difference() for openings
4. Use union() for assembly
5. Render and export STL
6. Easy to adjust dimensions in code

## File Organization

```
case/
├── README.md                          (this file)
├── source/
│   ├── a2dp_radio_case.f3d           (Fusion 360 source)
│   ├── a2dp_radio_case.FCStd         (FreeCAD source)
│   └── a2dp_radio_case.scad          (OpenSCAD source)
├── stl/
│   ├── a2dp_radio_case_top.stl       (Top shell)
│   ├── a2dp_radio_case_bottom.stl    (Bottom shell)
│   └── a2dp_radio_button_caps.stl    (Optional button caps)
├── step/
│   └── a2dp_radio_case_assembly.step (STEP format for editing)
└── images/
    ├── render_assembled.png
    ├── render_exploded.png
    └── dimensions.png
```

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial case design guide |

## References
- [3D Printing Basics](https://www.simplify3d.com/support/print-quality-troubleshooting/)
- [Snap-Fit Design Guidelines](https://www.protocase.com/blog/2017/01/25/designing-snap-fit-enclosures/)
- [Heat-Set Inserts Guide](https://hackaday.com/2019/02/28/threading-3d-printed-parts-how-to-use-heat-set-inserts/)
