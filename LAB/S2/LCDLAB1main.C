
/* main.c */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LCD.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
LCD_Init();
GOTEXY(0,3);
LCD_SendString("Mariam Adel");
GOTEXY(1,3);
LCD_voidWriteNumber(-1234);

	while(1)
	{
	}
	return 0;
}