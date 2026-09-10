#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI.h"

int main(void) {
	u8 receivedData = 0;

	
	SPI_voidInitSlave();

	DIO_voidSetPinDirection(DPORTA, PIN0, OUTPUT);

	while (1) {
		
		receivedData = SPI_u8Tranceive(0xFF);

	
		if (receivedData == '1') {
			DIO_voidSetPinValue(DPORTA, PIN0, HIGH);
			} else {
			DIO_voidSetPinValue(DPORTA, PIN0, LOW);
		}
	}

	return 0;
}