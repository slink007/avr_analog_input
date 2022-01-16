#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"
#include "ad.h"


int main(void)
{
    unsigned int adCount;        // raw A-to-D count
    char number[17];             // for converting the count to a string
    analog_input_t port = AD0;   // get voltage from AD0
    validRow_t row = FIRST;      // first row of LCD
    char position;
    lcd_init();


    while (1)
    {
        adCount = ad_read(port);
        itoa(adCount, number, 10);
        position = lcd_text(row, 1, "Count: ");        
        lcd_text(row, position + 1, number);
        _delay_ms(1000);
        
    }
}
