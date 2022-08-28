# How to flash the Micro Python Firmware onto the Bee S3


Put the board into download mode by holding boot button and pressing reset button then release both buttons. 
Use esptool to erease flash and then flash new firmware onto the board.

## Erase the flash.
### Linux
```bash
esptool.py --chip esp32s3 --port /dev/ttyACM0 erase_flash
```

### Mac
Please do a `ls /dev/cu.usbm*` to determine the port your board has enumerated as.
```bash
esptool.py --chip esp32s3 --port /dev/cu.usbmodem01 erase_flash
```

### Windows
Change xxx to whatever COM port is being used by the board
```bash
esptool --chip esp32s3 --port COMxxx erase_flash
```
______________
## Flash the Firmware

### Linux
```bash
esptool.py --chip esp32s3 --port /dev/ttyACM0 write_flash -z 0 firmware.bin
```

### Mac
Please do a `ls /dev/cu.usbm*` to determine the port your board has enumerated as.
```bash
esptool.py --chip esp32s3 --port /dev/cu.usbmodem01 write_flash -z 0 firmware.bin
```

### Windows
Change xxx to whatever COM port is being used by the board
```bash
esptool.py --chip esp32s3 --port COMxxx write_flash -z 0 firmware.bin
