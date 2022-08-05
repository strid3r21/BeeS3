#ifndef _BeeS3
#define _BeeS3

#include <Arduino.h>
#include <esp_adc_cal.h>
#include <soc/adc_channel.h>

#define VBAT_ADC_CHANNEL ADC1_GPIO1_CHANNEL

#define green 0,255,0
#define red  255,0,0
#define blue 0,0,255
#define pink 255,20,147
#define purple 148,0,211
#define yellow 242,239,61
#define white 255,255,255
#define aqua 0,255,255
#define orange 255,140,0
#define off 0,0,0


class BEES3 {
  public:
    BEES3() : brightness(255) {}

    void begin() {
      // RGB_PWR is LDO2 on boards that have it
      pinMode(RGB_PWR, OUTPUT);
      rmt = rmtInit(RGB_DATA, RMT_TX_MODE, RMT_MEM_64);
      rmtSetTick(rmt, 25);


      esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_2_5, ADC_WIDTH_BIT_12, 0, &adc_cal);
      adc1_config_channel_atten(VBAT_ADC_CHANNEL, ADC_ATTEN_DB_2_5);

    }


    void setPixelPower(bool on) {
      digitalWrite(RGB_PWR, on);
    }

    void setPixelColor(uint8_t r, uint8_t g, uint8_t b) {
      pixel_color[0] = g;
      pixel_color[1] = r;
      pixel_color[2] = b;
      writePixel();
    }

    void setPixelColor(uint32_t rgb) {
      setPixelColor(rgb >> 16, rgb >> 8, rgb);
    }

    void setPixelBrightness(uint8_t brightness) {
      this->brightness = brightness;
      writePixel();
    }

    void writePixel() {
      setPixelPower(true);
      while (micros() < next_rmt_write) {
        yield();
      }
      int index = 0;
      for (auto chan : pixel_color) {
        uint8_t value = chan * (brightness + 1) >> 8;
        for (int bit = 7; bit >= 0; bit--) {
          if ((value >> bit) & 1) {
            rmt_data[index].level0 = 1;
            rmt_data[index].duration0 = 32; // 800ns
            rmt_data[index].level1 = 0;
            rmt_data[index].duration1 = 18; // 450ns
          } else {
            rmt_data[index].level0 = 1;
            rmt_data[index].duration0 = 16; // 400ns
            rmt_data[index].level1 = 0;
            rmt_data[index].duration1 = 34; // 850ns
          }
          index++;
        }
      }
      rmtWrite(rmt, rmt_data, 3 * 8);
      next_rmt_write = micros() + 350;
    }

    static uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
      return (r << 16) | (g << 8) | b;
    }

    static uint32_t colorWheel(uint8_t pos) {
      if (pos < 85) {
        return color(255 - pos * 3, pos * 3, 0);
      } else if (pos < 170) {
        pos -= 85;
        return color(0, 255 - pos * 3, pos * 3);
      } else {
        pos -= 170;
        return color(pos * 3, 0, 255 - pos * 3);
      }
    }


    float getBatteryVoltage() {
      uint32_t raw = adc1_get_raw(VBAT_ADC_CHANNEL);
      uint32_t millivolts = esp_adc_cal_raw_to_voltage(raw, &adc_cal);
      const uint32_t upper_divider = 442;
      const uint32_t lower_divider = 160;
      return (float)(upper_divider + lower_divider) / lower_divider / 1000 * millivolts;
    }

  

  private:
    rmt_obj_t *rmt;
    rmt_data_t rmt_data[3 * 8];
    unsigned long next_rmt_write;
    uint8_t pixel_color[3];
    uint8_t brightness;
    esp_adc_cal_characteristics_t adc_cal;
};

#endif
