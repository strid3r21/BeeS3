import time, gc, os
import neopixel
from machine import Pin
import bees3

# Create a NeoPixel instance
# Brightness of 0.3 is ample for the 1515 sized LED
pixel = neopixel.NeoPixel(Pin(bees3.RGB_DATA), 1)

# The boot button is on pin 0. When its not being used to put the 
# board into download mode, we can use it like a normal button.
BTN = Pin(0,Pin.IN, Pin.PULL_UP)

# Turn on the power to the NeoPixel
bees3.set_rgb_power(True)

# When the BOOT button is pressed, turn the RGB Blue
#when its not pressed, turn the RGB Red
while True:
    if not BTN.value():
        pixel[0] = (0,0,255, 0.5)
        pixel.write()
    else:
        pixel[0] = (255,0,0, 0.5)
        pixel.write()

    
