
import time, gc, os
import neopixel
from machine import Pin
from machine import deepsleep
from time import sleep
import bees3


# Create a NeoPixel instance
# Brightness of 0.3 is ample for the 1515 sized LED
pixel = neopixel.NeoPixel(Pin(bees3.RGB_DATA), 1)
# Turn on the power to the NeoPixel
bees3.set_rgb_power(True)

# set GRB to red
pixel[0] = ( 255, 0, 0, 0.5)
pixel.write()

# wait 5 seconds so that you can catch the ESP awake to establish a serial communication later
# you should remove this sleep line in your final script
sleep(5)

print('Im awake, but Im going to sleep')

#sleep for 10 seconds (10000 milliseconds)
deepsleep(10000)