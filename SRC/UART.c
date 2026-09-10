#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"

void UART_voidInit(void)
{
    // Baud Rate = 9600 & F= 8MHz 
    UBRRH = 0;
    UBRRL = 51;

    set_bit(UCSRB, RXEN);
    set_bit(UCSRB, TXEN);

    // 8 Data bits & 1 Stop bit & No Parity 

    set_bit(UCSRC, URSEL);

    clr_bit(UCSRC, UMSEL);

    clr_bit(UCSRC, UPM1);
    clr_bit(UCSRC, UPM0);

    clr_bit(UCSRC, USBS);

    set_bit(UCSRC, UCSZ1);
    set_bit(UCSRC, UCSZ0);

    clr_bit(UCSRB, UCSZ2);
}

void UART_voidSendByte(u8 Copy_u8Data)
{
   
    while (get_bit(UCSRA, UDRE) == 0);

    UDR = Copy_u8Data;
}

u8 UART_u8ReceiveByte(void)
{
   
    while (get_bit(UCSRA, RXC) == 0);

    return UDR;
}