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
	double voltage;              // convert count to volts
    lcd_init();


    while (1)
    {
        adCount = ad_read(port);                 // get raw A-to-D count
        itoa(adCount, number, 10);               // convert count to string
        position = lcd_text(row, 1, " Count: ");        
        lcd_text(row, position + 1, number);
        
        /* 
           With 10-bits the resolution is 2^10 = 1024.
           The Vref = 5V
           Step size = 5V / 1024 steps or approx. 0.0049 V/step
        */
         voltage = (double)adCount * 0.0049;

         /*
            Reserve 5 characters of space to store the voltage.
            Use 2 digits of precision after the decimal.  First
            character will be reserved and used for minus sign if
            voltage is negative.
         */
         dtostrf(voltage, 5, 2, number);

         row = SECOND;
         position = lcd_text(row, 1, number);
         lcd_text(row, position + 1, " V");
         row = FIRST;
        _delay_ms(1000);
    }
}
