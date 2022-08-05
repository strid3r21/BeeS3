# How to flash the Micro Python Firmware onto the Bee S3


Put the board into download mode by holding boot button and pressing reset button then release both buttons. 
Use esptool to erease flash and then flash new firmware onto the board.

Erase the flash.
````
esptool.py --port COMxx erase_flash
````

Flash the Firmware
````
esptool.py --chip esp32s3 --port COMxx write_flash -z 0 firmware.bin
````
