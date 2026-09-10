#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI.h"

int main(void) {
	
	SPI_voidInitMaster();

	while (1) {
		
		DIO_voidSetPinValue(DPORTB, PIN4, LOW);

		SPI_u8Tranceive('1');

		DIO_voidSetPinValue(DPORTB, PIN4, HIGH);

		_delay_ms(1000);
	}

	return 0;
}