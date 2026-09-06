#include <avr/interrupt.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "INTER.h"

int main(void)
{
    /* Replace with your application code */
	 initExternalInterupts();
	DDRA=0b00000011;
    while (1) 
    {
		
    }
}
ISR(INT0_vect){
	toggle_bit(PORTA,0);
}
ISR(INT1_vect){
	toggle_bit(PORTA,1);
}