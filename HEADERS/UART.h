#ifndef UART_H_
#define UART_H_

#include "STD_TYPES.h"

void UART_voidInit(void);
void UART_voidSendByte(u8 Copy_u8Data);
u8 UART_u8ReceiveByte(void);

#endif