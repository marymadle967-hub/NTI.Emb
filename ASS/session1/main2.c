/* main.c */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#define F_CPU 8000000UL
#include <util/delay.h>


static const u8 SevSeg_Numbers[10] = {
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111  // 9
};

int main(void)
{

	DIO_voidIntinitialization();

	
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN2, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN3, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN4, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN5, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN6, OUTPUT);

	
	DIO_voidSetPinDirection(DPORTB, PIN0, OUTPUT);

	u8 counter = 0;

	while(1)
	{
		
		DIO_voidSetPortValue(DPORTC, SevSeg_Numbers[counter]);
        
	
		counter++;
		if(counter > 9)
		{
			counter = 0;
		}
		_delay_ms(500);
	}
}