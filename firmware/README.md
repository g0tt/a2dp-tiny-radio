# A2DP Tiny Radio - Arduino Firmware

## Overview
This firmware controls the A2DP FM Radio device using an ATmega328P microcontroller (Arduino Uno compatible).

## Features
- FM radio reception using RDA5807M
- I2C communication with radio module and OLED display
- UART communication with Bluetooth module
- Button-based user interface
- Preset station storage in EEPROM
- Automatic station scanning
- Bluetooth pairing mode
- Signal strength display

## Hardware Requirements
- ATmega328P @ 16MHz
- RDA5807M FM radio module
- SSD1306 OLED display (128x32)
- JDY-64 Bluetooth module
- 3 tactile buttons

## Software Dependencies
Install the following libraries via Arduino IDE Library Manager:

1. **Wire** (built-in) - I2C communication
2. **Adafruit GFX Library** - Graphics library for display
   - Version: 1.11.0 or later
   - Author: Adafruit
   - Install via: Sketch → Include Library → Manage Libraries → Search "Adafruit GFX"

3. **Adafruit SSD1306** - OLED display driver
   - Version: 2.5.7 or later
   - Author: Adafruit
   - Install via: Sketch → Include Library → Manage Libraries → Search "Adafruit SSD1306"

4. **EEPROM** (built-in) - Non-volatile memory storage

## Pin Configuration

### Digital Pins
```
Pin 0 (RX):  Bluetooth Module TX
Pin 1 (TX):  Bluetooth Module RX
Pin 2:       Button - Channel Up (with interrupt)
Pin 3:       Button - Channel Down (with interrupt)
Pin 6:       Button - Mode/Menu
Pin 7:       Bluetooth KEY pin (pairing control)
```

### I2C Pins (Analog)
```
Pin A4 (SDA): I2C Data - RDA5807M & SSD1306
Pin A5 (SCL): I2C Clock - RDA5807M & SSD1306
```

## User Interface

### Button Functions

#### Button 1 (Channel Up)
- **Short Press**: Increase frequency by 0.1 MHz
- **Long Press (1s)**: Start automatic scan upward

#### Button 2 (Channel Down)
- **Short Press**: Decrease frequency by 0.1 MHz
- **Long Press (1s)**: Start automatic scan downward

#### Button 3 (Mode)
- **Short Press**: Toggle between normal and preset mode
- **Long Press (2s)**: Enter Bluetooth pairing mode

### Display Information
The OLED displays:
- Current frequency (large text)
- Signal strength indicator (bar graph)
- Bluetooth connection status
- Current mode (normal/preset/pairing)

## Operating Modes

### Normal Mode
- Default operation mode
- Adjust frequency with up/down buttons
- Listen to FM radio via Bluetooth or earphones

### Scan Mode
- Activated by long press on up/down buttons
- Automatically searches for strong stations
- Stops when signal strength > threshold (RSSI > 30)

### Preset Mode
- Store and recall favorite stations
- Use up/down to select preset number
- Long press mode button to save current frequency

### Bluetooth Pairing Mode
- Activated by long press on mode button (2s)
- Device becomes discoverable
- LED indicates pairing status
- Auto-exits after 30 seconds or successful pairing

## EEPROM Memory Map
```
Address 0-19:   Preset frequencies (10 presets x 2 bytes)
Address 20-21:  Last frequency
Address 22:     Volume level
```

## Configuration

### FM Band Settings
Edit these constants in the code to change FM band:
```cpp
#define FM_BAND_MIN    76.0  // MHz - Minimum frequency
#define FM_BAND_MAX    108.0 // MHz - Maximum frequency
#define FM_SPACING     0.1   // MHz - Channel spacing
```

Preset bands:
- Japan: 76.0 - 95.0 MHz
- US/Europe: 87.5 - 108.0 MHz
- Extended: 76.0 - 108.0 MHz

### I2C Addresses
```cpp
#define RDA5807M_ADDR  0x11  // RDA5807M FM Radio
#define OLED_ADDR      0x3C  // SSD1306 OLED Display
```

### Button Debounce
```cpp
const unsigned long DEBOUNCE_DELAY = 50; // milliseconds
```

## Compilation & Upload

### Using Arduino IDE
1. Open `a2dp_fm_radio.ino` in Arduino IDE
2. Select **Tools → Board → Arduino Uno**
3. Select **Tools → Port** → [Your COM port]
4. Click **Verify** to compile
5. Click **Upload** to flash firmware

### Using Arduino CLI
```bash
# Compile
arduino-cli compile --fqbn arduino:avr:uno a2dp_fm_radio/

# Upload
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno a2dp_fm_radio/
```

### Memory Usage
Typical memory usage:
- Sketch: ~15KB (47% of 32KB flash)
- Global variables: ~800 bytes (39% of 2KB RAM)

## Bluetooth Configuration

### JDY-64 Module
Default settings:
- Baud rate: 9600
- Device name: "FMRadio" (can be changed via AT commands)
- PIN: 1234 (if required)

### AT Commands
Send via Serial Monitor:
```
AT+NAME<name>     - Set device name
AT+BAUD<rate>     - Set baud rate
AT+PIN<pin>       - Set pairing PIN
AT+VERSION        - Get firmware version
```

## Troubleshooting

### Display Not Working
- Check I2C connections (SDA, SCL)
- Verify I2C address (use I2C scanner sketch)
- Check 3.3V power supply

### No FM Reception
- Ensure earphone is connected (acts as antenna)
- Check RDA5807M I2C address and connections
- Verify 32.768kHz crystal is present and working
- Try different frequency range

### Bluetooth Not Connecting
- Check UART connections (TX ↔ RX, RX ↔ TX)
- Verify 3.3V power to Bluetooth module
- Enter pairing mode manually
- Check if device appears in Bluetooth settings

### Buttons Not Responding
- Check button connections to ground
- Verify pull-up resistors or internal pull-ups
- Adjust debounce delay if needed

### Audio Quality Issues
- Check coupling capacitors on audio output
- Verify proper grounding
- Ensure adequate power supply filtering
- Try different earphones

## Code Structure

### Main Functions
```cpp
setup()                    // Initialize hardware
loop()                     // Main program loop
initRDA5807M()            // Initialize FM radio module
setFrequency(float)       // Set FM frequency
setVolume(uint8_t)        // Set audio volume
getSignalStrength()       // Read RSSI
handleButtons()           // Process button inputs
startScan(bool)           // Begin auto-scanning
updateDisplay()           // Refresh OLED
initBluetooth()           // Initialize BT module
enterBluetoothPairing()   // Enter pairing mode
loadSettings()            // Load from EEPROM
saveSettings()            // Save to EEPROM
```

## Customization

### Add More Presets
Change `NUM_PRESETS` constant:
```cpp
#define NUM_PRESETS  20  // Increase from 10 to 20
```

### Adjust Scan Threshold
Modify RSSI threshold in `startScan()`:
```cpp
if (rssi > 40) {  // Change from 30 to 40 for stronger signals only
```

### Change Display Update Rate
Modify delay in `loop()`:
```cpp
if (millis() - lastDisplayUpdate > 250) {  // Faster updates (250ms instead of 500ms)
```

## Advanced Features

### Volume Control (Future Enhancement)
Add a volume control function:
```cpp
void adjustVolume(int8_t delta) {
  currentVolume += delta;
  if (currentVolume > 15) currentVolume = 15;
  if (currentVolume < 0) currentVolume = 0;
  setVolume(currentVolume);
  saveSettings();
}
```

### RDS Support (Future Enhancement)
The RDA5807M supports RDS (Radio Data System). To enable:
1. Read RDS registers (0x0C-0x0F)
2. Parse RDS data (PI code, PS name, RT text)
3. Display station name on OLED

### Stereo Indicator (Future Enhancement)
Read stereo flag from status register:
```cpp
bool isStereo() {
  Wire.beginTransmission(RDA5807M_ADDR);
  Wire.write(0x0A);
  Wire.endTransmission(false);
  Wire.requestFrom(RDA5807M_ADDR, 1);
  return (Wire.read() & 0x04) != 0;
}
```

## License
MIT License - See LICENSE file for details

## Version History
| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-02-12 | Initial firmware release |

## References
- [RDA5807M Datasheet](https://www.sparkfun.com/datasheets/Wireless/General/RDA5807M.pdf)
- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328P-Datasheet.pdf)
- [SSD1306 Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
- [JDY-64 Documentation](http://www.jdyiot.com/)
