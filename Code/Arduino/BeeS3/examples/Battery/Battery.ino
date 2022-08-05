// include the Bee S3 libaray so we can use the RGB LED and Battery Voltage Monitor
#include <BeeS3.h>

BEES3 bees3;

void setup() {
  Serial.begin(115200);

  // starts up all board peripherals, call this first
  bees3.begin();

  // Brightness is 0-255. We set it to 1/3 brightness.
  bees3.setPixelBrightness(255 / 3);
}

void batteryLevel() {
  // gets the battery voltage and stores it in the variable ""battery"
  float battery = bees3.getBatteryVoltage(); 
  // we can print out the battery voltage. 4.2v is full and 3.0v is dead 
  Serial.println(String("Battery: ") + battery);


  //or we can map the voltage to a precentage between 0-100 for easier reading
  int battery_precentage = map(battery,3.0,4.2,0,100);
  Serial.print(String("Battery Precentage: ") + battery_precentage);
  Serial.println("%");


  
    // we can also turn on the RGB LED to show what range the battery level is currently at.
    if (battery < 3.1) {
      //esp_deep_sleep_start();
    } else if (battery < 3.3) {
      // Below 3.3v - red
      bees3.setPixelColor(0xFF0000);
    } else if (battery < 3.6) {
      // Below 3.6v (around 50%) - orange
      bees3.setPixelColor(0xFF8800);
    } else {
      // Above 3.6v - green
      bees3.setPixelColor(0x00FF00);
    }
  
}

// Store the millis of the last battery reading
unsigned long lastBatteryCheck = 0;
// Define the battery check interval as one second
#define BATTERY_CHECK_INTERVAL 1000

void loop() {
  if (lastBatteryCheck == 0 || millis() - lastBatteryCheck > BATTERY_CHECK_INTERVAL) {
    batteryLevel();
    lastBatteryCheck = millis();
  }
}
