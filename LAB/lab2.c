
/* main.c */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include "DIO_int.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DIO_voidSetPortDirection(DPORTA,INPUT);
	DIO_voidSetPortDirection(DPORTC, 0xFF);
	
	
	DIO_voidSetPortValue(DPORTA, 0xFF);

	while(1)
	{
		
		if(DIO_u8ReadPinValue(DPORTA, PIN0) == 0){
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			_delay_ms(100);
			} else {
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
		}

		
		if(DIO_u8ReadPinValue(DPORTA, PIN1) == 0){
			DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			_delay_ms(100);
			} else {
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
		}

		
		if(DIO_u8ReadPinValue(DPORTA, PIN2) == 0){
			DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
			_delay_ms(100);
			} else {
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}

		
		if(DIO_u8ReadPinValue(DPORTA, PIN3) == 0){
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
			_delay_ms(100);
		}
		else{
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		
	}

	return 0;
}