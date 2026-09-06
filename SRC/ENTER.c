#include <avr/io.h>
#include <avr/interrupt.h>
#include "INTER.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "STD_TYPES.h"
void initExternalInterupts(){
	clr_bit(DDRD,2);
	clr_bit(DDRD,3);
	
	set_bit(PORTD,2);
	set_bit(PORTD,3);
	
	clr_bit(MCUCR,ISC01);
	set_bit(MCUCR,ISC00);
	
	clr_bit(MCUCR,ISC11);
	set_bit(MCUCR,ISC10);
	
	set_bit(GICR,INT0);
	set_bit(GICR,INT1);
	
	sei();
	

	
}
