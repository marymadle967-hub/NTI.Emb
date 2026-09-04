#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KEYPAD.h"
#include "LCD.h"
#include "CALC.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	u8 Key;

	s32 Num1 = 0;
	s32 Num2 = 0;
	s32 Result = 0;

	u8 Operator = 0;

	LCD_Init();
	KPD_voidInit();

	LCD_SendString((u8*)"Calculator:");
	_delay_ms(1000);
	LCD_SendCommand(0x01);
	_delay_ms(2);

	while(1)
	{
	  Key = KPD_u8GetPressedKey();

	  if(Key != KPD_NOT_PRESSED)
		{
		 if(Key <= 9)
			{
				if(Operator == 0)
				{
					Num1 = (Num1 * 10) + Key;
					LCD_voidWriteNumber(Key);
				}

				else
				{
					Num2 = (Num2 * 10) + Key;
					LCD_voidWriteNumber(Key);
				}
			}

			
		 else if(Key == '+'  || Key == '-' || Key == '*' || Key == '/')
			{
				Operator = Key;

				LCD_sendChar(Operator);
			}

		else if(Key == '=')
			{
				Result = CALC_s32Calculate(Num1, Num2, Operator);

				LCD_sendChar('=');
				LCD_voidWriteNumber(Result);

				Num1 = Result;
				Num2 = 0;
				Operator = 0;
			}

			
		else if(Key == 'C')
			{
				Num1 = 0;
				Num2 = 0;
				Result = 0;
				Operator = 0;

				LCD_SendCommand(0x01);
				_delay_ms(2);
			}
		}
	}

	return 0;
}