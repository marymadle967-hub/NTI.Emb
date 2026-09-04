 /* main.c */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "KEYPAD.h"

#define F_CPU 8000000UL
#include <util/delay.h>


const u8 SEG_Numbers[10] = {
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
	u8 Key = KPD_NOT_PRESSED;

	DIO_voidSetPortDirection(DPORTD, 0xFF);
	
	DIO_voidSetPortValue(DPORTD, 0x00);

	KPD_voidInit();

	while(1)
	{
		Key = KPD_u8GetPressedKey();
	
			if(Key <= 9)
			{
				DIO_voidSetPortValue(DPORTD, SEG_Numbers[Key]);
			}
		}
	

	return 0;
}
