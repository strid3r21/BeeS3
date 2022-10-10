import time, gc, os
import neopixel
import board, digitalio
import bees3

# This code is used with the Bee S3 Proto breakout board only.

# Turn on/off the power to the Proto boards 3v3_2 pins
bees3.set_proto_power(True)

while True:
    
    time.sleep(5)
    bees3.set_proto_power(False)
    time.sleep(5)
    bees3.set_proto_power(True)