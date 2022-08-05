#include <BeeS3.h> //include the bee s3 helper library

BEES3 bees3;  //pull the BEES3 class from the helper and name it bees3 so we can use it below;

void setup() {
  bees3.begin(); // Initalize the helper library. if you fail to do this the program will not work as intended.

  // Brightness is 0-255. We set it to 1/2 brightness here
   bees3.setPixelBrightness(255 / 2);
}

int color = 0;

void loop() {
  // colorWheel cycles through all the colors.
  bees3.setPixelColor(BEES3::colorWheel(color));
  color++;

  // or you can select a specific color like so
  // the predefined colors you can choose from are green, red, blue, pink, purple, yellow, white, aqua and orange.

  // bees3.setPixelColor(blue);  
  // uncomment the line above to use it.

  // or by using RGB color numbers.
  // bees3.setPixelColor(150,0,150);

  // uncomment the line above to use it.
  // find a list of all color RGB values here https://www.rapidtables.com/web/color/RGB_Color.html
  
  // or you can use any color hex code.
  
  // bees3.setPixelColor(0x00FF0000);
  // uncomment the line above to use it.
  // find hex color codes here https://soft.infomir.com/stb/522/Doc/ColorCodes.html

  delay(15);
}