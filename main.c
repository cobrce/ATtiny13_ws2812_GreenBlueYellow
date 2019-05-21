#include <avr/io.h>
#include <util/delay.h>
#include "light_ws2812.h"

#define COUNTER ((i+j)%60)

#define MAX 50
struct cRGB p;
#define CURRENT_PIXEL p

int main(void)
{
	char i =0;

	while (1)
	{
		for (int j = 0;j<20;j++)
		{
			if (COUNTER<10)
			{
				// full blue, rising green
				CURRENT_PIXEL.r = 0;
				CURRENT_PIXEL.g =COUNTER*MAX/10;
				CURRENT_PIXEL.b = MAX;
			}
			else if (COUNTER<20)
			{
				// full green, falling blue
				CURRENT_PIXEL.r = 0;
				CURRENT_PIXEL.g = MAX;
				CURRENT_PIXEL.b =(20-1-COUNTER)*MAX/10;
			}
			else if (COUNTER<30)
			{	//full green rising red
				CURRENT_PIXEL.r = (COUNTER-20)*MAX/10;
				CURRENT_PIXEL.g = MAX;
				CURRENT_PIXEL.b = 0;
			}
			else if  (COUNTER<40)
			{	//full green falling red
				CURRENT_PIXEL.r = (40-1-COUNTER)*MAX/10;
				CURRENT_PIXEL.g = MAX;
				CURRENT_PIXEL.b = 0;
			}
			else if (COUNTER<50)
			{   //full green rising blue
				CURRENT_PIXEL.r = 0;
				CURRENT_PIXEL.g = MAX;
				CURRENT_PIXEL.b = (COUNTER-40)*MAX/10;
			}
			else
			{    //full blue falling green
				CURRENT_PIXEL.r = 0;
				CURRENT_PIXEL.g = (60-1-COUNTER)*MAX/10;
				CURRENT_PIXEL.b = MAX;
			}
			ws2812_sendarray_mask_single(&p,_BV(PB0));
		}
		// ws2812_setleds((struct cRGB *)&p, 10);
		_delay_ms(50);
		i = (i+1)%60;
	
    }
}