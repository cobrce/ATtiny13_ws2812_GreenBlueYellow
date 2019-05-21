# ATtiny13_ws2812_GreenBlueYellow
Drive a 20 LED ws2812 strip with an ATtiny13 to display blue to yellow rainbow.

## How to use
* make sure you have avr-gcc and avrdude installed
* the code is already compiled, but if you change it execute ```make```
* update the Makefile according to your flasher, actually it expects an Arduino ISP on COM13
* use ```make flash``` to download the hex to your attiny13
* flash the fuse configuration with ```make fuse```, if you use a different chip update the values
