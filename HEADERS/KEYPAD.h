#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KPD_NOT_PRESSED   0xFF


void KPD_voidInit(void);

u8 KPD_u8GetPressedKey(void);

#define KPD_PORT        DPORTC

#define KPD_ROW0_PIN    PIN0
#define KPD_ROW1_PIN    PIN1
#define KPD_ROW2_PIN    PIN2
#define KPD_ROW3_PIN    PIN3

#define KPD_COL0_PIN    PIN4
#define KPD_COL1_PIN    PIN5
#define KPD_COL2_PIN    PIN6
#define KPD_COL3_PIN    PIN7

#define KPD_KEYS \
{ \
	{7, 8, 9, '/'}, \
	{4, 5, 6, '*'}, \
	{1, 2, 3, '-'}, \
	{'C', 0, '=', '+'} \
}


#endif
