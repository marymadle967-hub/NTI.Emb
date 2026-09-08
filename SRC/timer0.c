#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "timer0.h"

void TIMER0_voidInitCTC(void) {
	
	clr_bit(TCCR0, WGM01);
	clr_bit(TCCR0, WGM00);

//   /1024
	set_bit(TCCR0, CS02);
	clr_bit(TCCR0, CS01);
	set_bit(TCCR0, CS00);

	set_bit(TIMSK, TOIE0);


	sei();
}

void TIMER0_voidSetOCR0(u8 Copy_u8Value) {
	OCR0 = Copy_u8Value;
}


ISR(TIMER0_OVF_vect) {
	static counter=0;
	counter++;
	if(counter==61){
toggle_bit(PORTC,PIN0);
counter=0;
	}
}
