/*
 * A2DP Tiny Radio - Main Firmware
 * 
 * Hardware: ATmega328P @ 16MHz
 * Peripherals:
 *   - RDA5807M FM Radio (I2C)
 *   - SSD1306 OLED Display (I2C)
 *   - JDY-64 Bluetooth Module (UART)
 * 
 * Author: A2DP Radio Project
 * License: MIT
 * Version: 1.0
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

// Pin Definitions
#define BTN_CH_UP      2   // PD2 - Channel Up
#define BTN_CH_DOWN    3   // PD3 - Channel Down
#define BTN_MODE       6   // PD6 - Mode/Pairing
#define BT_KEY         7   // PD7 - Bluetooth pairing control
#define BT_RX          0   // PD0 - Bluetooth module TXD
#define BT_TX          1   // PD1 - Bluetooth module RXD

// I2C Addresses
#define RDA5807M_ADDR  0x11  // RDA5807M Sequential Access
#define OLED_ADDR      0x3C  // SSD1306 OLED

// RDA5807M Registers
#define RDA_REG_CHIPID  0x00
#define RDA_REG_CONFIG  0x02
#define RDA_REG_TUNING  0x03
#define RDA_REG_STATUS  0x0A

// Display Settings
#define SCREEN_WIDTH   128
#define SCREEN_HEIGHT  32
#define OLED_RESET     -1  // No reset pin

// FM Band Settings
#define FM_BAND_MIN    76.0  // MHz
#define FM_BAND_MAX    108.0 // MHz
#define FM_SPACING     0.1   // MHz

// EEPROM Addresses
#define EEPROM_PRESET_START  0
#define EEPROM_LAST_FREQ     20
#define EEPROM_VOLUME        22
#define NUM_PRESETS          10

// Global Objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Global Variables
float currentFreq = 87.5;
uint8_t currentVolume = 8;
uint8_t currentPreset = 0;
bool btConnected = false;
unsigned long lastButtonPress = 0;
const unsigned long DEBOUNCE_DELAY = 50;

// Mode enumeration
enum Mode {
  MODE_NORMAL,
  MODE_SCAN,
  MODE_PRESET,
  MODE_BT_PAIRING
};
Mode currentMode = MODE_NORMAL;

// Button state tracking
struct ButtonState {
  bool pressed;
  unsigned long pressTime;
  bool longPress;
};
ButtonState btnUp, btnDown, btnMode;

void setup() {
  // Initialize serial for debugging and Bluetooth
  Serial.begin(9600);
  
  // Initialize I2C
  Wire.begin();
  Wire.setClock(100000); // 100kHz
  
  // Initialize buttons
  pinMode(BTN_CH_UP, INPUT_PULLUP);
  pinMode(BTN_CH_DOWN, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BT_KEY, OUTPUT);
  digitalWrite(BT_KEY, HIGH); // Normal mode
  
  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    // Display failed - continue anyway
    delay(1000);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("A2DP FM Radio");
  display.println("Initializing...");
  display.display();
  delay(1000);
  
  // Initialize RDA5807M
  if (!initRDA5807M()) {
    displayError("FM Init Failed");
    delay(2000);
  }
  
  // Load settings from EEPROM
  loadSettings();
  
  // Set initial frequency
  setFrequency(currentFreq);
  setVolume(currentVolume);
  
  // Initialize Bluetooth
  initBluetooth();
  
  // Initial display update
  updateDisplay();
}

void loop() {
  // Handle button inputs
  handleButtons();
  
  // Update display periodically
  static unsigned long lastDisplayUpdate = 0;
  if (millis() - lastDisplayUpdate > 500) {
    updateDisplay();
    lastDisplayUpdate = millis();
  }
  
  // Check Bluetooth status
  static unsigned long lastBTCheck = 0;
  if (millis() - lastBTCheck > 1000) {
    checkBluetoothStatus();
    lastBTCheck = millis();
  }
  
  // Handle different modes
  switch (currentMode) {
    case MODE_SCAN:
      performScan();
      break;
    case MODE_PRESET:
      // Preset mode handled by buttons
      break;
    case MODE_BT_PAIRING:
      // Pairing mode - waiting for user
      break;
    case MODE_NORMAL:
    default:
      // Normal operation
      break;
  }
}

bool initRDA5807M() {
  // Power up and configure RDA5807M
  Wire.beginTransmission(RDA5807M_ADDR);
  Wire.write(0x02); // Register 0x02
  Wire.write(0xC0); // DHIZ, DMUTE, BASS, power up, etc.
  Wire.write(0x01); // Enable tuning, soft mute
  if (Wire.endTransmission() != 0) {
    return false;
  }
  
  delay(500); // Wait for chip to power up
  
  // Configure band and spacing
  Wire.beginTransmission(RDA5807M_ADDR);
  Wire.write(0x05); // Register 0x05
  Wire.write(0x88); // Volume, INT mode, I2S mode
  Wire.write(0x8F); // Band: 87-108MHz, Space: 100kHz
  Wire.endTransmission();
  
  delay(100);
  return true;
}

void setFrequency(float freq) {
  if (freq < FM_BAND_MIN) freq = FM_BAND_MIN;
  if (freq > FM_BAND_MAX) freq = FM_BAND_MAX;
  
  currentFreq = freq;
  
  // Calculate channel number
  uint16_t channel = (uint16_t)((freq - FM_BAND_MIN) / FM_SPACING);
  
  // Set frequency on RDA5807M
  Wire.beginTransmission(RDA5807M_ADDR);
  Wire.write(0x03); // Register 0x03
  Wire.write((channel >> 2) | 0xC0); // Channel[9:2] + TUNE bit
  Wire.write((channel << 6) & 0xC0); // Channel[1:0]
  Wire.endTransmission();
  
  delay(50); // Wait for tuning
}

void setVolume(uint8_t vol) {
  if (vol > 15) vol = 15;
  currentVolume = vol;
  
  Wire.beginTransmission(RDA5807M_ADDR);
  Wire.write(0x05); // Register 0x05
  Wire.write(0x80 | (vol & 0x0F)); // Set volume
  Wire.write(0x8F); // Band and spacing
  Wire.endTransmission();
}

uint8_t getSignalStrength() {
  Wire.beginTransmission(RDA5807M_ADDR);
  Wire.write(RDA_REG_STATUS);
  Wire.endTransmission(false);
  
  Wire.requestFrom(RDA5807M_ADDR, 2);
  if (Wire.available() >= 2) {
    Wire.read(); // Status high byte
    uint8_t statusLow = Wire.read();
    return (statusLow & 0xFE) >> 1; // RSSI value
  }
  return 0;
}

void handleButtons() {
  unsigned long now = millis();
  
  // Debounce
  if (now - lastButtonPress < DEBOUNCE_DELAY) {
    return;
  }
  
  // Channel Up button
  if (digitalRead(BTN_CH_UP) == LOW) {
    if (!btnUp.pressed) {
      btnUp.pressed = true;
      btnUp.pressTime = now;
      btnUp.longPress = false;
    } else if (!btnUp.longPress && (now - btnUp.pressTime > 1000)) {
      // Long press - start scan up
      btnUp.longPress = true;
      startScan(true);
    }
  } else {
    if (btnUp.pressed && !btnUp.longPress) {
      // Short press - increment frequency
      setFrequency(currentFreq + FM_SPACING);
      updateDisplay();
      lastButtonPress = now;
    }
    btnUp.pressed = false;
  }
  
  // Channel Down button
  if (digitalRead(BTN_CH_DOWN) == LOW) {
    if (!btnDown.pressed) {
      btnDown.pressed = true;
      btnDown.pressTime = now;
      btnDown.longPress = false;
    } else if (!btnDown.longPress && (now - btnDown.pressTime > 1000)) {
      // Long press - start scan down
      btnDown.longPress = true;
      startScan(false);
    }
  } else {
    if (btnDown.pressed && !btnDown.longPress) {
      // Short press - decrement frequency
      setFrequency(currentFreq - FM_SPACING);
      updateDisplay();
      lastButtonPress = now;
    }
    btnDown.pressed = false;
  }
  
  // Mode button
  if (digitalRead(BTN_MODE) == LOW) {
    if (!btnMode.pressed) {
      btnMode.pressed = true;
      btnMode.pressTime = now;
      btnMode.longPress = false;
    } else if (!btnMode.longPress && (now - btnMode.pressTime > 2000)) {
      // Long press - Bluetooth pairing mode
      btnMode.longPress = true;
      enterBluetoothPairing();
    }
  } else {
    if (btnMode.pressed && !btnMode.longPress) {
      // Short press - cycle through modes
      cycleMode();
      lastButtonPress = now;
    }
    btnMode.pressed = false;
  }
}

void startScan(bool up) {
  currentMode = MODE_SCAN;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Scanning...");
  display.display();
  
  float startFreq = currentFreq;
  float scanFreq = startFreq;
  
  // Scan for strong signal
  do {
    if (up) {
      scanFreq += FM_SPACING;
      if (scanFreq > FM_BAND_MAX) scanFreq = FM_BAND_MIN;
    } else {
      scanFreq -= FM_SPACING;
      if (scanFreq < FM_BAND_MIN) scanFreq = FM_BAND_MAX;
    }
    
    setFrequency(scanFreq);
    delay(50);
    
    uint8_t rssi = getSignalStrength();
    if (rssi > 30) { // Strong signal threshold
      break;
    }
  } while (scanFreq != startFreq);
  
  currentMode = MODE_NORMAL;
  updateDisplay();
}

void cycleMode() {
  // Toggle between normal and preset mode
  if (currentMode == MODE_NORMAL) {
    currentMode = MODE_PRESET;
  } else {
    currentMode = MODE_NORMAL;
  }
  updateDisplay();
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  
  // Show frequency
  display.setTextSize(2);
  display.print(currentFreq, 1);
  display.println(" MHz");
  
  // Show signal strength
  display.setTextSize(1);
  uint8_t rssi = getSignalStrength();
  display.print("Signal: ");
  for (int i = 0; i < (rssi / 10); i++) {
    display.print("|");
  }
  display.println();
  
  // Show Bluetooth status
  display.print("BT: ");
  if (btConnected) {
    display.println("Connected");
  } else {
    display.println("Disconnected");
  }
  
  // Show mode
  if (currentMode == MODE_PRESET) {
    display.print("Preset #");
    display.println(currentPreset + 1);
  } else if (currentMode == MODE_BT_PAIRING) {
    display.println("Pairing...");
  }
  
  display.display();
}

void displayError(const char* msg) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ERROR:");
  display.println(msg);
  display.display();
}

void initBluetooth() {
  // JDY-64 initializes automatically
  // Send AT command to set name (optional)
  delay(1000);
  Serial.println("AT+NAMEFMRadio");
  delay(100);
}

void enterBluetoothPairing() {
  currentMode = MODE_BT_PAIRING;
  digitalWrite(BT_KEY, LOW); // Enter pairing mode
  delay(100);
  digitalWrite(BT_KEY, HIGH);
  
  updateDisplay();
  
  // Wait for pairing (timeout after 30 seconds)
  unsigned long startTime = millis();
  while (millis() - startTime < 30000) {
    if (btConnected) {
      currentMode = MODE_NORMAL;
      return;
    }
    delay(100);
  }
  
  currentMode = MODE_NORMAL;
  updateDisplay();
}

void checkBluetoothStatus() {
  // Read status from Bluetooth module via serial
  // This is simplified - actual implementation depends on module
  // JDY-64 sends status messages via UART
  if (Serial.available()) {
    String response = Serial.readStringUntil('\n');
    if (response.indexOf("CONNECT") >= 0) {
      btConnected = true;
    } else if (response.indexOf("DISCONNECT") >= 0) {
      btConnected = false;
    }
  }
}

void loadSettings() {
  // Load last frequency
  uint16_t freqInt;
  EEPROM.get(EEPROM_LAST_FREQ, freqInt);
  if (freqInt >= FM_BAND_MIN * 10 && freqInt <= FM_BAND_MAX * 10) {
    currentFreq = freqInt / 10.0;
  }
  
  // Load volume
  uint8_t vol = EEPROM.read(EEPROM_VOLUME);
  if (vol <= 15) {
    currentVolume = vol;
  }
}

void saveSettings() {
  // Save current frequency
  uint16_t freqInt = (uint16_t)(currentFreq * 10);
  EEPROM.put(EEPROM_LAST_FREQ, freqInt);
  
  // Save volume
  EEPROM.write(EEPROM_VOLUME, currentVolume);
}

void savePreset(uint8_t preset, float freq) {
  if (preset < NUM_PRESETS) {
    uint16_t freqInt = (uint16_t)(freq * 10);
    EEPROM.put(EEPROM_PRESET_START + (preset * 2), freqInt);
  }
}

float loadPreset(uint8_t preset) {
  if (preset < NUM_PRESETS) {
    uint16_t freqInt;
    EEPROM.get(EEPROM_PRESET_START + (preset * 2), freqInt);
    if (freqInt >= FM_BAND_MIN * 10 && freqInt <= FM_BAND_MAX * 10) {
      return freqInt / 10.0;
    }
  }
  return FM_BAND_MIN;
}
