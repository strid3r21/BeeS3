import time, gc, os
import alarm
import neopixel
import board
import bees3

# Create a NeoPixel instance
# Brightness of 0.3 is ample for the 1515 sized LED
pixel = neopixel.NeoPixel(board.NEOPIXEL, 1, brightness=0.3, auto_write=True, pixel_order=neopixel.GRB)
# Turn on the power to the NeoPixel
bees3.set_pixel_power(True)

pixel[0] = ( 255, 0, 0, 0.5)
pixel.write()

time.sleep(5)

bees3.set_pixel_power(False)

# Create an alarm that will trigger 10 seconds from now.
time_alarm = alarm.time.TimeAlarm(monotonic_time=time.monotonic() + 10)
# Exit the program, and then deep sleep until the alarm wakes us.
alarm.exit_and_deep_sleep_until_alarms(time_alarm)
# Does not return, so we never get here.



# see more examples here https://learn.adafruit.com/deep-sleep-with-circuitpython/alarms-and-sleep
