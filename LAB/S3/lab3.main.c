#include <util/delay.h>
#include "STEPPER.h"
#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	Stepper_Init();
	
    while (1) 
    {
		FULL_STEP(CW);
		_delay_ms(1000);
		FULL_STEP(CCW);
		_delay_ms(1000);
		HALF_STEP(CW);
	   _delay_ms(1000);
       HALF_STEP(CCW);
      _delay_ms(1000);
    }
}

