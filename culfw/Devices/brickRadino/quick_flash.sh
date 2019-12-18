#!/bin/bash

avrdude -C /etc/avrdude.conf -v -p atmega32u4 -cavr109 -P /dev/ttyACM0 -b 57600 -D -V -Uflash:w:./brickRadino868.hex:i
