# Flashing Circuit Python Firmware onto your board.

put the board into download mode by holding boot button and pressing reset button then release both buttons. 
Use esptool to erease flash and then flash new firmware onto the board.

#Erase the flash
````
esptool.py --port COMxx erase_flash
````
#Flash new Firmware
````
esptool.py --chip esp32s3 -p COMxxx --before=default_reset --after=no_reset write_flash --flash_mode dio --flash_size detect --flash_freq 80m 0x0 bootloader.bin 0x8000 partition-table.bin 0xe000 ota_data_initial.bin 0x410000 tinyuf2.bin
````

Once that is done you should see a new drive show up called BEES3BOOT
Open that up and drag the firmware.uf2 file onto it. 
The BEES3BOOT drive will disappear and come back after a few seconds as CIRCUITPY. 
You're now good to use circuit python on the board!
