# A2DP Tiny Radio - Appearance and Dimensions

## Device Overview

The A2DP Tiny Radio is a compact FM radio with Bluetooth A2DP output, designed in a USB memory stick form factor for ultimate portability.

## External Dimensions

```
┌─────────────────────────────────────────────────────────────┐
│                                                               │
│  ←─────────────────── 65mm Total Length ───────────────────→ │
│                                                               │
└─────────────────────────────────────────────────────────────┘

     ↑
     │
   24mm Width
     │
     ↓

     ↑
     │
   14mm Height
     │
     ↓
```

### Detailed Measurements
- **Total Length**: 65mm (including USB-C connector protrusion)
- **PCB Length**: 60mm
- **Width**: 24mm (case), 20mm (PCB)
- **Height**: 14mm (maximum with case)
- **Weight**: ~15g (with case)

## Front View (Top Surface)

```
┌─────────────────────────────────────────────────────────────┐
│                                                               │
│   [PWR LED]  ╔══════════════════════════╗   ● ● ●           │
│   [BT LED]   ║                          ║  ╭─╮╭─╮╭─╮        │
│              ║   OLED DISPLAY WINDOW    ║  │ ││ ││ │        │
│              ║      128 x 32 pixels     ║  │ ││ ││ │        │
│              ║                          ║  ╰─╯╰─╯╰─╯        │
│              ╚══════════════════════════╝  CH- MD CH+       │
│                                                               │
└─────────────────────────────────────────────────────────────┘
         10mm        ↔ 32mm ↔            20mm      spacing
```

### Top Surface Elements

**1. LED Indicators (Left Side)**
- Power LED (Red): 2mm diameter, 5mm from left edge
- Bluetooth LED (Blue): 2mm diameter, 8mm from left edge
- Vertical spacing: 3mm between LEDs

**2. Display Window (Center)**
- Position: 10mm from left edge
- Size: 32mm (L) x 14mm (H)
- 0.91" OLED (128x32 pixels)
- Displays: Frequency, signal strength, BT status

**3. Control Buttons (Right Side)**
- Button 1 (Channel Down): 42mm from left edge
- Button 2 (Mode): 50mm from left edge  
- Button 3 (Channel Up): 58mm from left edge
- Button size: 5mm diameter holes
- Label markings on case

## Left End View (USB-C Port)

```
┌─────────────────────┐
│                     │
│                     │
│    ╔═══════════╗    │
│    ║ USB-C     ║    │
│    ║  PORT     ║    │
│    ╚═══════════╝    │
│                     │
│                     │
└─────────────────────┘
        24mm width

   ↑
   │ 14mm height
   ↓
```

**USB-C Receptacle**
- Position: Centered on left end
- Opening: 9mm (W) x 3.5mm (H)
- Recess depth: 6mm from edge
- Allows full cable insertion

## Right End View (Audio Jack)

```
┌─────────────────────┐
│                     │
│                     │
│        ●            │
│       ╱ ╲           │
│      │ O │          │
│       ╲ ╱           │
│        ●            │
│                     │
│                     │
└─────────────────────┘
    3.5mm Jack
    (centered)
```

**3.5mm Audio Jack**
- Position: Centered on right end
- Hole diameter: 6mm
- Jack type: Stereo (TRS)
- Dual purpose: Audio output + FM antenna
- Standard 3.5mm earphone compatible

## Side View (Profile)

```
┌─USB─┐  ┌─────────────────────────────────┐  ┌─Jack─┐
│  C  │  │                                 │  │  ♪   │
│     ╰──╯                                 ╰──╯      │
└─────┘                                         └─────┘
 ←2mm→  ←────────── 60mm PCB ──────────→     ←─3mm→

                    ↑ 14mm max height ↑
        ↑ 10mm PCB & components ↑
    ↑ 2mm case bottom ↑
```

### Profile Details
- Case thickness: 2mm walls
- PCB height: 1.6mm
- Component clearance: Up to 10mm
- Internal height: 12mm (max component height)
- USB-C and audio jack protrude slightly

## Bottom View

```
┌─────────────────────────────────────────────────────────────┐
│                                                               │
│     A2DP TINY FM RADIO                                       │
│     v1.0                                                      │
│                                                               │
│     Made with ♥                                               │
│                                                               │
│     █████████████     █████████████                           │
│     █           █     █           █     [Mounting holes]     │
│     █  QR CODE  █     █  QR CODE  █                          │
│     █   (opt)   █     █   (opt)   █                          │
│     █████████████     █████████████                           │
│                                                               │
└─────────────────────────────────────────────────────────────┘
```

**Bottom Surface Elements**
- Product name and version
- Optional QR codes (link to documentation/repo)
- Smooth surface (no protruding components)
- 4x mounting holes (2.2mm dia.) for M2 screws
- Rubber feet optional (adhesive, 6mm diameter)

## Size Comparison

### USB Flash Drive Size Reference
```
A2DP Radio:  ┌──────────────────────────────┐
             │         65mm x 24mm          │
             └──────────────────────────────┘

USB Flash:   ┌─────────────────────┐
             │    55mm x 18mm      │
             └─────────────────────┘

Similar form factor, slightly larger to accommodate components
```

### Pocket-Sized Comparison
- Similar to: Large USB flash drive, small lipstick, USB lighter
- Easily fits in shirt pocket
- Can attach to keychain (with case modification)
- Portable enough for daily carry

## Color Options (3D Printed Case)

### Standard Colors
1. **Black** - Professional, sleek appearance
2. **White** - Clean, modern look
3. **Gray** - Neutral, understated

### Custom Colors
- Red, Blue, Green (PLA available in many colors)
- Transparent/translucent (show internal components)
- Two-tone (print top and bottom in different colors)
- Glow-in-the-dark filament (for night visibility)

## Display Content Example

### Normal Operation Mode
```
╔════════════════════════════╗
║  FM  99.5 MHz              ║
║  |||||||||  [Signal 9/10]  ║
║  BT: Connected             ║
║  ♪ Now Playing             ║
╚════════════════════════════╝
```

### Scanning Mode
```
╔════════════════════════════╗
║                            ║
║    SCANNING...             ║
║    FM  88.3 MHz            ║
║    ████████░░  80%         ║
╚════════════════════════════╝
```

### Pairing Mode
```
╔════════════════════════════╗
║  BLUETOOTH PAIRING         ║
║                            ║
║  "FMRadio"                 ║
║  Waiting to pair...        ║
╚════════════════════════════╝
```

## Material and Finish

### PCB
- FR-4 substrate
- Green solder mask (standard)
- White silkscreen
- HASL or ENIG surface finish

### Case (3D Printed)
- Material: PLA, PETG, or ABS
- Finish: Matte (natural print texture)
- Optional: Sanded and painted for smooth finish
- Layer height: 0.2mm (good detail)

### LEDs
- Power LED: Red, 5mm standard or 0805 SMD
- Bluetooth LED: Blue, 5mm standard or 0805 SMD
- Brightness: Medium (5-10mA current)

## Ergonomics

### Button Placement
- Buttons positioned for single-hand operation
- 8mm spacing allows comfortable pressing
- Tactile feedback from switches
- Can be operated without looking (with practice)

### Port Access
- USB-C: Easy to plug in either orientation
- 3.5mm jack: Standard size, universal compatibility
- Both ports accessible without removing from pocket

### Display Visibility
- Viewing angle: >160° (OLED advantage)
- Outdoor visibility: Good (high contrast)
- Low-light visibility: Excellent (self-illuminating)
- No backlight needed

## Mounting Options

### Lanyard/Keychain
- Add small loop or hole to case corner
- Attach lanyard ring or split ring
- Allows hanging from neck or keys

### Desk Stand (Optional Accessory)
- Simple cradle design
- Holds device at viewing angle
- Cable pass-through for USB power

### Magnetic Mount
- Add small magnet to case back
- Mount to metal surfaces
- Useful for kitchen, workshop, vehicle

## Packaging (If Producing Commercially)

### Retail Package Contents
1. A2DP Tiny Radio device (assembled)
2. USB-C cable (30cm)
3. Quick start guide (folded card)
4. Safety information

### Package Dimensions
- Box size: 100mm x 70mm x 25mm
- Clear window showing device
- Hang tab for retail display

## Visual Design Elements

### Typography
- Product name: Bold sans-serif
- Version number: Small, bottom edge
- Button labels: Simple icons or text

### Icons (Optional Silkscreen)
- ▲ (Channel Up)
- ▼ (Channel Down)  
- ☰ (Mode/Menu)
- ♪ (Audio/Music)
- ⚡ (Power indicator)
- ⟳ (Bluetooth symbol)

## Regulatory Markings (If Required)

### For Commercial Products
- CE mark (Europe)
- FCC ID (USA)
- IC mark (Canada)
- RoHS compliance
- WEEE symbol (disposal)
- Manufactured date code

### Placement
- Bottom surface, small text
- Does not detract from aesthetics

## Appearance Renders (To Be Created)

When CAD model is complete, generate:
1. **Isometric view** - 3/4 perspective showing top and sides
2. **Exploded view** - Show internal components and assembly
3. **In-use mockup** - Person holding device, showing scale
4. **Color variations** - Different case color options
5. **Technical drawing** - All dimensions clearly labeled

## Brand Identity (Optional)

### Logo Placement
- Small logo on top surface (5mm x 5mm area)
- Bottom surface for larger branding
- Keep minimal for clean design

### Product Line
- Could be part of series: "Tiny Radio", "Tiny MP3", etc.
- Consistent design language across products
- Recognizable form factor

## Accessibility Considerations

### Button Identification
- Raised markings for tactile identification
- High-contrast button labels
- Audible feedback (speaker beep) as future enhancement

### Display
- High contrast OLED (white on black)
- Large font size for frequency display
- Icons to supplement text

## Environmental Considerations

### Durability
- Splash-resistant (not waterproof)
- Drop-resistant from 1m (with proper case)
- Temperature range: 0-50°C operating

### Sustainability
- 3D printed case: Recyclable PLA option
- Repairable design (modular construction)
- Long service life (no battery degradation)
- USB-C standard (future-proof)

## Revision History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial appearance documentation |

---

## Notes for CAD Designer

When creating 3D model:
- Start with PCB dimensions as foundation (60x20mm)
- Add 2mm clearance all sides for case walls
- Model all external features (ports, buttons, display)
- Verify button actuation mechanism
- Check USB-C and audio jack accessibility
- Add internal mounting posts for PCB
- Include snap-fit or screw mounting features
- Consider printability (avoid overhangs >45°)
- Export STL files for 3D printing
- Generate 2D technical drawings with dimensions
