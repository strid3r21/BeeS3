# How to flash the Micro Python Firmware onto the Bee S3


Erase the flash.
````
esptool.py --port COMxx erase_flash
````

Flash the Firmware
````
esptool.py --chip esp32s3 --port COMxx write_flash -z 0 firmware.bin
````
