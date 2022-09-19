# Bee S3 Arduino Helper Library

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
