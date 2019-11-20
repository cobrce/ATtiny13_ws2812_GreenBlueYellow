#include <avr/io.h>
#include <util/delay.h>
#include "light_ws2812.h"

#define COUNTER ((i + j) % 20)

#define MAX 50
#define MAX_GREEN 40
#define MIN_GREEN 5
struct cRGB p;
#define CURRENT_PIXEL p

char LedValues[] = {11, 20, 30, 39, 30, 20, 15, 11, 15, 20};
char dir1 = 0b10011101;
char dir2 = 0b11;

char GetDirection(int i)
{
    if (i < 8)
        return dir1 & _BV(i);
    return dir2 & _BV(i - 8);
}

void InvertDirection(int i)
{
    if (i < 8)
        dir1 ^= _BV(i);
    else
        dir2 ^= _BV(i - 8);
}

int main(void)
{
    CURRENT_PIXEL.r = MAX;
    // CURRENT_PIXEL.b = 0;
    while (1)
    {
        for (int i = 0; i < 10; i++)
        {
            CURRENT_PIXEL.g = LedValues[i];

            ws2812_sendarray_mask_single(&p, _BV(PB0));

            char direction = GetDirection(i);
            LedValues[i] += direction ? 1 : -1;
            if (LedValues[i] == (direction ? MAX_GREEN : MIN_GREEN))
                InvertDirection(i);
        }
        _delay_ms(50);
    }
}