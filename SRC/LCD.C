/* LCD_program.c */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"

#include "LCD.h"

#define F_CPU 8000000UL
#include <util/delay.h>
void LCD_Init(void)
{
    DIO_voidSetPortDirection(LCD_DATA_PORT, 0xFF);

    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN, OUTPUT);

    _delay_ms(40);

    LCD_SendCommand(0b00111000);
    _delay_ms(1);

    LCD_SendCommand(0b00001100);
    _delay_ms(1);

    LCD_SendCommand(0b00000001);
    _delay_ms(2);
}
void LCD_sendChar(u8 Data)
{
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS, HIGH);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW, LOW);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN, HIGH);

   
    DIO_voidSetPortValue(LCD_DATA_PORT, Data);

    
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN, LOW);
    _delay_ms(5);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN, HIGH);
}
void LCD_SendCommand(u8 command)
{
  
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS, LOW);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW, LOW);

   
    DIO_voidSetPortValue(LCD_DATA_PORT, command);

    //pulse
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN, HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN, LOW);
}

void LCD_SendString(u8 *str)
{
    u8 i = 0;
    while (str[i] != '\0')
    {
        LCD_sendChar(str[i]);
        i++;
    }
}

void GOTEXY(u8 x,u8 y){
	u8 loc =0;
	if(x==0){
		loc=y;
	}
	else if(x==1){
		loc=y+0b01000000;
	}
	LCD_SendCommand(loc+0b10000000);
}

#include <stdlib.h> 

void LCD_voidWriteNumber(s32 num)
{
    char str_buffer[12]; 
	
    itoa(num, str_buffer, 10);

    LCD_SendString((u8 *)str_buffer);
}

