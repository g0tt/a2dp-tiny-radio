# Bill of Materials (BOM) - A2DP Tiny Radio

## Components List

| Ref | Qty | Value | Description | Package | Manufacturer Part# | Notes |
|-----|-----|-------|-------------|---------|-------------------|-------|
| U1 | 1 | ATmega328P-AU | Microcontroller | TQFP-32 | ATmega328P-AU | Arduino compatible |
| U2 | 1 | RDA5807M | FM Radio Receiver | QFN-20 | RDA5807M | I2C interface |
| U3 | 1 | JDY-64 | Bluetooth 5.0 Module | Module | JDY-64 | Alternative: HC-05 |
| U4 | 1 | AMS1117-3.3 | 3.3V LDO Regulator | SOT-223 | AMS1117-3.3 | 800mA output |
| U5 | 1 | SSD1306 | 0.91" OLED Display | Module | 128x32 OLED | I2C, white/blue |
| Y1 | 1 | 16MHz | Crystal Oscillator | HC-49S SMD | 16MHz ±20ppm | For ATmega328P |
| Y2 | 1 | 32.768kHz | Crystal Oscillator | SMD 3.2x1.5mm | 32.768kHz | For RDA5807M |
| J1 | 1 | USB-C | USB-C Receptacle | SMD | Korean Hroparts Elec TYPE-C-31-M-12 | Power only |
| J2 | 1 | PJ-320A | 3.5mm Audio Jack | Through-hole | PJ-320A | Stereo, antenna |
| SW1-3 | 3 | - | Tactile Switch | 6x6mm SMD | SPST 4-pin | User interface |
| C1-C6 | 6 | 100nF | Ceramic Capacitor | 0805 | X7R 50V | Decoupling |
| C7-C8 | 2 | 22pF | Ceramic Capacitor | 0805 | C0G/NP0 50V | Crystal load caps |
| C9-C10 | 2 | 10μF | Ceramic Capacitor | 0805 | X7R 16V | Power filtering |
| C11-C12 | 2 | 1μF | Ceramic Capacitor | 0805 | X7R 16V | Audio coupling |
| C13 | 1 | 47μF | Electrolytic Capacitor | SMD 6.3x5.4mm | 16V | USB input |
| R1-R3 | 3 | 10kΩ | Resistor | 0805 | 1% | Pull-up |
| R4-R5 | 2 | 4.7kΩ | Resistor | 0805 | 1% | I2C pull-up |
| R6-R7 | 2 | 1kΩ | Resistor | 0805 | 1% | LED current limiting |
| R8-R9 | 2 | 100Ω | Resistor | 0805 | 1% | Audio output |
| L1 | 1 | Ferrite Bead | Ferrite Bead | 0805 | 600Ω@100MHz | USB noise filter |
| D1 | 1 | SS34 | Schottky Diode | SMB | SS34 | Reverse protection |
| LED1 | 1 | Red | LED | 0805 | Red 620nm | Power indicator |
| LED2 | 1 | Blue | LED | 0805 | Blue 470nm | Bluetooth status |

## Module Components (Pre-assembled)

| Module | Interface | Power | Dimensions |
|--------|-----------|-------|------------|
| JDY-64 Bluetooth | UART (TX/RX) | 3.3V | 26.9 x 13 x 2.2mm |
| SSD1306 OLED | I2C (SDA/SCL) | 3.3V-5V | 30 x 12 x 4mm |

## Optional Components

| Ref | Qty | Value | Description | Package | Notes |
|-----|-----|-------|-------------|---------|-------|
| J3 | 1 | Header 2x3 | ISP Programming Header | 2.54mm pitch | For Arduino bootloader programming |
| SW4 | 1 | SPST | Reset Switch | 6x6mm SMD | Manual reset |

## Assembly Notes

### Soldering Guidelines
1. **QFN Package (RDA5807M)**: Requires fine soldering iron tip and flux. Drag soldering technique recommended.
2. **TQFP Package (ATmega328P)**: Standard fine-pitch soldering. Use flux and wick for cleanup.
3. **SMD 0805 Components**: Hand-solderable with standard soldering iron.
4. **Modules**: Pre-soldered pin headers or direct solder to pads.

### Component Sourcing
- **Primary Suppliers**: DigiKey, Mouser, LCSC
- **Modules**: AliExpress, eBay (JDY-64, OLED)
- **PCB**: JLCPCB, PCBWay

### Cost Estimate
- **PCB (5pcs)**: ~$10 USD
- **Components**: ~$25 USD
- **Total per unit**: ~$7 USD (excluding NRE)

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
