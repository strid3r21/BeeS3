# If main.py is used it will run whatever code is in here once your Bee S3
# boots up. So you dont have to repl into the board and import the code to 
# start it! just replace the code below with whatever code you want to run
# on boot.


import time, gc, os
import neopixel
from machine import Pin
import bees3

# Create a NeoPixel instance
# Brightness of 0.3 is ample for the 1515 sized LED
pixel = neopixel.NeoPixel(Pin(bees3.RGB_DATA), 1)

# Create a colour wheel index int
color_index = 0

# Turn on the power to the NeoPixel
bees3.set_rgb_power(True)

# Rainbow colours on the NeoPixel
while True:
    # Get the R,G,B values of the next colour
    r,g,b = bees3.rgb_color_wheel( color_index )
    # Set the colour on the NeoPixel
    pixel[0] = ( r, g, b, 0.5)
    pixel.write()
    # Increase the wheel index
    color_index += 1

    # If the index == 255, loop it
    if color_index == 255:
        color_index = 0
        # Invert the internal LED state every half colour cycle
       
        
    # Sleep for 15ms so the colour cycle isn't too fast
    time.sleep(0.015)