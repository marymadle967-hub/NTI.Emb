#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"

int main(void)
{
	DDRA = 0x00;

	PORTA = 0xFF;

	UART_voidInit();

	while (1)
	{
		
		UART_voidSendByte('1');
		_delay_ms(300);
		
		UART_voidSendByte('2');
		_delay_ms(300);
  

	}

	return 0;
}