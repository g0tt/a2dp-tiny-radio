# A2DP Tiny Radio - Technical Specifications

## Overview
Compact FM radio with Bluetooth A2DP audio output, designed to be USB memory stick sized.

## Key Features
- FM radio reception using RDA5807M module
- Bluetooth A2DP audio output
- 3.5mm earphone jack (serves as antenna)
- Small LCD display for UI
- USB-C powered
- Arduino-compatible firmware
- Hand-solderable components only

## Dimensions
- **Length**: 60mm
- **Width**: 20mm  
- **Height**: 10mm
- **Form Factor**: USB memory stick style

## Hardware Components

### Main Components
1. **Microcontroller**: ATmega328P (Arduino Uno compatible)
   - Operating Voltage: 5V
   - Clock: 16MHz external crystal
   - Flash: 32KB
   - RAM: 2KB
   - EEPROM: 1KB

2. **FM Radio Module**: RDA5807M
   - Frequency Range: 50MHz - 115MHz
   - I2C Interface
   - Integrated LNA and power amplifier
   - Automatic gain control
   - Package: QFN-20 (hand-solderable with practice)

3. **Bluetooth Module**: JDY-64 or HC-05
   - Bluetooth 5.0 (JDY-64) or 2.0 (HC-05)
   - A2DP/AVRCP profile support
   - UART interface
   - Operating Voltage: 3.3V

4. **Display**: 0.91" OLED (128x32)
   - I2C Interface (SSD1306 controller)
   - Operating Voltage: 3.3V - 5V
   - White or blue monochrome

5. **Audio Output**:
   - 3.5mm stereo jack
   - Dual purpose: audio output and FM antenna
   - Capacitive coupling for antenna function

6. **Power Management**:
   - USB-C receptacle (power only, no data)
   - 5V input
   - 3.3V LDO regulator (AMS1117-3.3)
   - Ferrite bead and capacitors for noise filtering

7. **User Interface**:
   - 3x tactile buttons (SPST, 6mm x 6mm)
     - Button 1: Channel Up
     - Button 2: Channel Down
     - Button 3: Mode/Pairing

## Power Requirements
- **Input**: USB-C, 5V DC
- **Typical Current**: 150mA
- **Peak Current**: 250mA (during Bluetooth transmission)

## Audio Specifications
- **Frequency Response**: 50Hz - 15kHz
- **Signal-to-Noise Ratio**: >50dB
- **Output Impedance**: 32Ω earphones recommended
- **Maximum Output Power**: 30mW per channel

## FM Radio Specifications
- **Frequency Range**: 76MHz - 108MHz (Japan/US/EU FM band)
- **Channel Spacing**: 100kHz
- **Sensitivity**: <10dBμV
- **Selectivity**: >50dB

## Bluetooth Specifications
- **Version**: Bluetooth 2.0/5.0 (depending on module)
- **Profiles**: A2DP (Advanced Audio Distribution Profile)
- **Range**: Up to 10 meters (unobstructed)
- **Codec**: SBC (Sub-band Coding)
- **Pairing**: PIN-based or simple pairing

## Operating Conditions
- **Operating Temperature**: 0°C to 50°C
- **Storage Temperature**: -20°C to 70°C
- **Humidity**: 10% to 90% non-condensing

## PCB Specifications
- **Layers**: 2-layer PCB
- **Dimensions**: 60mm x 20mm
- **Thickness**: 1.6mm
- **Copper Weight**: 1oz (35μm)
- **Surface Finish**: HASL or ENIG
- **Minimum Track Width**: 0.2mm
- **Minimum Spacing**: 0.2mm
- **Manufacturer**: Compatible with JLCPCB standards

## Compliance
- **Safety**: USB-C power supply requirements
- **EMC**: Basic filtering for USB noise reduction
- **RoHS**: Compliant (lead-free components)

## Software Features
- Automatic station scanning
- 10 preset stations (stored in EEPROM)
- Volume control via RDA5807M
- Bluetooth pairing mode
- Station frequency display
- Signal strength indicator
- Low power mode
