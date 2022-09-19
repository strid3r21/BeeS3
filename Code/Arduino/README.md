# Programming on Arduino

## Add the Espressif ESP32 arduino board library to Arduino IDE
File > Preferences > at the bottom "Additional Board Manager URLS" paste in this url
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json 
 
From there you will be able to search and add the ESP32 board library from the board library search bar. install the ESP32 library by Espressif and make sure you're using version number 2.0.5 or later. You will then be able to select your Bee S3 from the board manager.

## How to program the Bee Motion
In order to program the Bee Motion you need to put it into download mode. To do so all you need to do is connect the USB-C cable and then press and hold the boot button. with the boot button being held down, press the reset button and release. then you can release the boot button. this will put the Bee Motion into download mode which will allow it to be programmed. Then for the board, select "Bee S3" from the board manager.

# Bee S3 Arduino Example Sketches & helper library

Examples can be found in the [Bee S3 Arduino Helper](https://github.com/strid3r21/BeeS3-Arduino-Helper) repo.

## Installation

This library can be installed through the Arduino library manager or manually from github by following [the instructions here](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries).

## List of functions

```c++

// Initializes all Bee S3 board peripherals
void begin();

// Set neopixel power on or off
void setPixelPower(bool on);

// Set neopixel color
void setPixelColor(uint8_t r, uint8_t g, uint8_t b);
void setPixelColor(uint32_t rgb);

// Set neopixel brightness
void setPixelBrightness(uint8_t brightness);

// Pack r,g,b (0-255) into a 32bit rgb color
static uint32_t color(uint8_t r, uint8_t g, uint8_t b);

// Convert a color wheel angle (0-255) to a 32bit rgb color
static uint32_t colorWheel(uint8_t pos);

// Get the battery voltage in volts
float getBatteryVoltage();

```
