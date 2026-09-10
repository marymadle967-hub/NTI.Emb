#define F_CPU 8000000UL

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"

int main(void)
{
	u8 ReceivedData;

	
	DDRA = 0xFF;

	PORTA = 0x00;

	UART_voidInit();

	while (1)
	{
		ReceivedData = UART_u8ReceiveByte();

		switch (ReceivedData)
		{
			case '1':
			 clr_bit(PORTA,PA1);
			toggle_bit(PORTA, PA0);
			break;

			case '2':
			 clr_bit(PORTA,PA0);
			toggle_bit(PORTA, PA1);
			break;


			default:
			break;
		}
	}

	return 0;
}