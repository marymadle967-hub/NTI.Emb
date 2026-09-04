#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KEYPAD.h"


#define F_CPU 8000000UL
#include <util/delay.h>

static const u8 KPD_u8Buttons[4][4] = KPD_KEYS;

static const u8 KPD_u8RowsPins[4] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
static const u8 KPD_u8ColsPins[4] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};

void KPD_voidInit(void)
{
	u8 i;

	for(i = 0; i < 4; i++)
	{
		DIO_voidSetPinDirection(KPD_PORT, KPD_u8RowsPins[i], INPUT);
		DIO_voidSetPinValue(KPD_PORT, KPD_u8RowsPins[i], HIGH);
	}
	
	for(i = 0; i < 4; i++)
	{
		DIO_voidSetPinDirection(KPD_PORT, KPD_u8ColsPins[i], OUTPUT);
		DIO_voidSetPinValue(KPD_PORT, KPD_u8ColsPins[i], HIGH);
	}
}

u8 KPD_u8GetPressedKey(void)
{
	u8 PressedKey = KPD_NOT_PRESSED;
	u8 j, k;
	u8 Local_u8PinState;

	for(j = 0; j < 4; j++)
	{
		/* Make current column LOW */
		DIO_voidSetPinValue(KPD_PORT, KPD_u8ColsPins[j], LOW);

		for(k = 0; k < 4; k++)
		{
			Local_u8PinState =
			DIO_u8ReadPinValue(KPD_PORT, KPD_u8RowsPins[k]);

			if(Local_u8PinState == LOW)
			{
				_delay_ms(20);

				if(DIO_u8ReadPinValue(KPD_PORT, KPD_u8RowsPins[k]) == LOW)
				{
					PressedKey = KPD_u8Buttons[k][j];

					/* Wait until key is released */
					while(DIO_u8ReadPinValue(KPD_PORT,
					KPD_u8RowsPins[k]) == LOW);

					/* Return column HIGH before returning */
					DIO_voidSetPinValue(KPD_PORT,
					KPD_u8ColsPins[j], HIGH);

					return PressedKey;
				}
			}
		}

		/* Return current column HIGH */
		DIO_voidSetPinValue(KPD_PORT, KPD_u8ColsPins[j], HIGH);
	}

	return KPD_NOT_PRESSED;
}