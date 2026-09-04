/* main.c */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LED_INTERFACE.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	
	DIO_voidIntinitialization();

	
	LED_voidInit(DPORTB, PIN0);

	while(1)
	{
	
		LED_voidTurnOn(DPORTB, PIN0, ACTIVE_HIGH);
		_delay_ms(1000);

		LED_voidTurnOff(DPORTB, PIN0, ACTIVE_HIGH);
		_delay_ms(1000);
	}
}