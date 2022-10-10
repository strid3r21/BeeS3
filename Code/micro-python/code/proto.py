import time, gc, os
import neopixel
from machine import Pin
import bees3

# this code is to be used with the Bee S3 Proto breakout board only

# turn the power on/off to the 3V3_2 pins

# Turn on the power to the NeoPixel
bees3.set_proto_power(True)

# Rainbow colours on the NeoPixel
while True:
   
    time.sleep(5)
    bees3.set_proto_power(False)
    time.sleep(5)
    bees3.set_proto_power(True)
    
