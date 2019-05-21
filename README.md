# ATtiny13_ws2812_GreenBlueYellow
Drive a 20 LED ws2812 strip with an ATtiny13 to display blue to yellow rainbow.

## How to use
* make sure you have avr-gcc and avrdude installed
* the code is already compiled, but if you change it execute ```make```
* update the Makefile according to your flasher, actually it expects an Arduino ISP on COM13
* use ```make flash``` to download the hex to your attiny13
* flash the fuse configuration with ```make fuse```, if you use a different chip update the values


## Schematic
*The arduino is only to flash the attiny13*
![Alt text](https://raw.githubusercontent.com/cobrce/ATtiny13_ws2812_GreenBlueYellow/master/schematic/Schematic_ATtiny-ws2812_Sheet-1_20190521184719.png)


## Minimal board (zoomed)
![Alt text](https://raw.githubusercontent.com/cobrce/ATtiny13_ws2812_GreenBlueYellow/master/schematic/photo%20view%20(large).png)

