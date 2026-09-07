#define F_CPU 8000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "ADC.h"
#include "LCD.h" 

int main(void)
{
  u16 adc_digital_value = 0;
  u32 voltage_mv = 0;

  DDRA=0b00000000;

  ADC_Init();
  LCD_Init();

    GOTEXY(0, 0);           
  LCD_SendString("Volt:");

  while (1)
  {
      adc_digital_value = ADC_Read(0);

    voltage_mv = ((u32)adc_digital_value * 5000UL) / 1024UL;

      GOTEXY(0, 6);              
    LCD_voidWriteNumber(voltage_mv);  
    LCD_SendString(" mV   ");   

    _delay_ms(100);
  }
}