# 3D Case Files

## Overview
This directory should contain 3D CAD files for the A2DP Tiny Radio case.

## Required Files

### Source Files (CAD Native Format)
Choose one of the following CAD platforms:

#### Fusion 360 (Recommended)
- `a2dp_radio_case.f3d` - Main project file
- Fully parametric design
- Free for hobbyists
- Cloud-based with version control

#### FreeCAD (Open Source)
- `a2dp_radio_case.FCStd` - Main project file
- Free and open source
- Cross-platform (Windows, Mac, Linux)
- Active community

#### OpenSCAD (Code-Based)
- `a2dp_radio_case.scad` - Parametric script
- Text-based design
- Version control friendly
- Highly customizable

### Export Files (For 3D Printing)
```
stl/
├── a2dp_radio_case_top.stl       (Top shell)
├── a2dp_radio_case_bottom.stl    (Bottom shell)
└── a2dp_radio_button_caps.stl    (Optional button actuators)

step/
└── a2dp_radio_case_assembly.step (Universal CAD format)
```

## Design Specifications

Based on `CASE_DESIGN_GUIDE.md`, the case should meet these requirements:

### External Dimensions
- Length: 65mm
- Width: 24mm
- Height: 14mm
- Wall thickness: 2mm

### Internal Clearances
- PCB to bottom: 1mm
- PCB to top: 3mm
- PCB to sides: 2mm
- Component clearance: 0.5mm minimum

### Openings and Features
1. **USB-C Port** (left end)
   - Size: 9mm x 3.5mm
   - Inset: 6mm from edge
   
2. **3.5mm Audio Jack** (right end)
   - Diameter: 6mm
   - Through entire end panel
   
3. **Button Holes** (top surface)
   - 3 holes, 5mm diameter each
   - Positions: 42mm, 50mm, 58mm from left edge
   
4. **Display Window** (top surface)
   - Size: 32mm x 14mm
   - Position: 10mm from left edge
   
5. **LED Light Pipes** (front face)
   - 2 holes, 2mm diameter each
   - Near USB port

## Creating the 3D Case

### Option 1: Using Fusion 360

#### Step 1: Setup
1. Download and install Fusion 360
2. Create new design
3. Set units to millimeters

#### Step 2: Parameters
Define key dimensions as parameters for easy adjustment:
```
length = 65mm
width = 24mm
height = 14mm
wall_thickness = 2mm
pcb_length = 60mm
pcb_width = 20mm
pcb_thickness = 1.6mm
```

#### Step 3: Bottom Shell
1. Create sketch on XY plane
2. Draw rectangle: 60mm x 20mm (PCB size)
3. Offset outward: 2mm (wall thickness)
4. Extrude: 7mm (half of total height)
5. Shell: 2mm wall thickness
6. Add internal support posts for PCB mounting
   - 4 posts, 3.5mm diameter
   - Height: 1mm above case bottom
   - Positions: Match PCB mounting holes

#### Step 4: Top Shell
1. Create new body
2. Mirror bottom shell design
3. Modify for openings:
   - Display window: 32mm x 14mm rectangle extrude cut
   - Button holes: 3x 5mm circles extrude cut
   - LED holes: 2x 2mm circles extrude cut

#### Step 5: Add Openings
**USB-C Opening:**
1. Create sketch on left end face
2. Draw rectangle: 9mm x 3.5mm centered
3. Extrude cut: 6mm depth

**Audio Jack Opening:**
1. Create sketch on right end face
2. Draw circle: 6mm diameter centered
3. Extrude cut: through entire end panel

#### Step 6: Assembly Features
Choose snap-fit or screw mounting:

**Snap-Fit Option:**
1. Add latches to top shell sides
2. Add corresponding catches to bottom shell
3. Latch dimensions:
   - Height: 0.5mm
   - Angle: 30°
   - Position: 2 per long side

**Screw Mount Option:**
1. Add screw posts to bottom shell corners
2. Add corresponding holes to top shell
3. Post dimensions:
   - Diameter: 3.5mm
   - Height: matches shell height
   - M2 heat-set insert cavity

#### Step 7: Refinements
1. Add fillets to internal corners (1mm radius)
2. Add chamfers to external edges (0.5mm)
3. Add texture to top surface (optional)
4. Add engraving for text/logo (optional)

#### Step 8: Export
1. Right-click body → Save as STL
2. Settings:
   - Format: Binary
   - Refinement: High
   - Unit: Millimeter
3. Export top and bottom shells separately
4. Export as STEP for universal compatibility

### Option 2: Using FreeCAD

#### Step 1: Setup
1. Download and install FreeCAD
2. Create new document
3. Switch to Part Design workbench

#### Step 2: Bottom Shell
1. Create sketch on XY plane
2. Draw profile for case bottom
3. Use Pad tool to extrude
4. Use Pocket tool for internal cavity
5. Add mounting posts with separate Pad operations

#### Step 3: Top Shell
1. Create new body
2. Similar process as bottom shell
3. Add cutouts for display and buttons using Pocket tool

#### Step 4: Openings
1. Create sketches for USB-C and audio jack
2. Use Pocket tool to cut openings

#### Step 5: Export
1. File → Export → STL
2. Export each body separately

### Option 3: Using OpenSCAD

#### Step 1: Create Script
Create `a2dp_radio_case.scad`:

```openscad
// Parameters
length = 65;
width = 24;
height = 14;
wall = 2;
pcb_length = 60;
pcb_width = 20;

module bottom_shell() {
    difference() {
        // Outer shell
        cube([length, width, height/2]);
        
        // Inner cavity
        translate([wall, wall, wall])
            cube([length-2*wall, width-2*wall, height]);
            
        // USB-C opening
        translate([0, width/2-4.5, height/2-1.75])
            cube([6, 9, 3.5]);
    }
    
    // Mounting posts
    post_positions = [
        [3, 3],
        [length-3, 3],
        [3, width-3],
        [length-3, width-3]
    ];
    
    for (pos = post_positions) {
        translate([pos[0], pos[1], wall])
            cylinder(h=1, d=3.5, $fn=20);
    }
}

module top_shell() {
    difference() {
        // Outer shell
        cube([length, width, height/2]);
        
        // Inner cavity
        translate([wall, wall, -wall])
            cube([length-2*wall, width-2*wall, height]);
            
        // Display window
        translate([10, wall-1, -1])
            cube([32, 14+2, height]);
            
        // Button holes
        button_positions = [20, 30, 40];
        for (pos = button_positions) {
            translate([pos, width/2, -1])
                cylinder(h=height, d=5, $fn=20);
        }
    }
}

// Render both parts
bottom_shell();
translate([0, width+10, 0])
    top_shell();
```

#### Step 2: Render and Export
1. Open in OpenSCAD
2. Press F6 to render
3. File → Export → STL

## 3D Printing Settings

### Recommended Settings
```
Layer Height:        0.2mm
Infill:              20%
Wall Line Count:     3 (2mm walls)
Top/Bottom Layers:   4
Supports:            Minimal (only for button holes)
Adhesion:            Brim (recommended)
Nozzle Temperature:  200-210°C (PLA), 230-250°C (PETG)
Bed Temperature:     60°C (PLA), 70-80°C (PETG)
Print Speed:         50-60mm/s
```

### Material Recommendations
1. **PLA**: Easy to print, good for prototyping
2. **PETG**: Stronger, more heat resistant
3. **ABS**: Strong, can be smoothed with acetone

### Print Orientation
- **Bottom shell**: Outer face down (no supports needed)
- **Top shell**: Outer face down (minimal supports for button holes)

## Testing the Design

### Before 3D Printing
1. **Verify dimensions** in CAD software
2. **Check wall thickness** (minimum 2mm)
3. **Verify clearances** around PCB
4. **Test assembly** in CAD (interference detection)
5. **Export preview** renders for documentation

### After First Print
1. **Test fit PCB** (should slide in easily)
2. **Check openings** (USB-C and audio jack accessible)
3. **Test button actuation** (buttons reach switches)
4. **Verify display visibility** (OLED visible through window)
5. **Test assembly** (top/bottom fit together)

### Iterate
- Adjust dimensions as needed
- Re-export STL files
- Print again
- Repeat until perfect fit

## Customization Ideas

### Functional
- Add ventilation slots on sides
- Integrate keychain loop
- Add belt clip mount
- Create desktop stand/cradle

### Aesthetic
- Multi-color printing (filament swap)
- Textured grip surfaces
- Custom engraving/logo
- Transparent display window insert
- Glow-in-the-dark filament

## File Organization

Organize files as follows:
```
case/
├── CASE_DESIGN_GUIDE.md           (Design specifications)
├── README.md                       (This file)
├── source/
│   ├── a2dp_radio_case.f3d        (Fusion 360)
│   ├── a2dp_radio_case.FCStd      (FreeCAD)
│   └── a2dp_radio_case.scad       (OpenSCAD)
├── stl/
│   ├── a2dp_radio_case_top.stl
│   ├── a2dp_radio_case_bottom.stl
│   └── a2dp_radio_button_caps.stl
├── step/
│   └── a2dp_radio_case.step
└── images/
    ├── render_top.png
    ├── render_bottom.png
    ├── render_assembled.png
    └── render_exploded.png
```

## Assembly Instructions

After printing:
1. Remove support material
2. Clean up surfaces with file/sandpaper
3. Test fit all parts
4. Install heat-set inserts (if using screw mount)
5. Place PCB in bottom shell
6. Close top shell
7. Secure with snaps or screws

Detailed assembly in `docs/ASSEMBLY_GUIDE.md`.

## Status

⚠️ **Not Started** - 3D CAD files need to be created

This directory contains documentation only. Actual 3D models should be created following the guidelines above and the specifications in `CASE_DESIGN_GUIDE.md`.

## Contributing

If you create a case design:
1. Follow the specifications in CASE_DESIGN_GUIDE.md
2. Test print and verify fit
3. Export STL files
4. Add photos of printed case
5. Submit pull request with all files

## Support

For help with 3D modeling:
- Fusion 360 tutorials: https://www.autodesk.com/products/fusion-360/learn
- FreeCAD documentation: https://wiki.freecadweb.org/
- OpenSCAD manual: https://openscad.org/documentation.html
- This project's GitHub Discussions

## References
- [3D Printing Basics](https://www.simplify3d.com/support/print-quality-troubleshooting/)
- [Snap-Fit Design](https://www.protocase.com/blog/2017/01/25/designing-snap-fit-enclosures/)
- [Heat-Set Inserts](https://hackaday.com/2019/02/28/threading-3d-printed-parts-how-to-use-heat-set-inserts/)
