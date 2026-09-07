#define F_CPU 8000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "ADC.h"
#include "LCD.h"

#define RED_LED    2
#define YELLOW_LED 1
#define GREEN_LED  0

int main(void)
{
	u16 adc_digital_value = 0;
	u32 voltage_mv = 0;
	u16 temp= 0;

	
	clr_bit(DDRA, 0);
	
	
	set_bit(DDRC, RED_LED);
	set_bit(DDRC, YELLOW_LED);
	set_bit(DDRC, GREEN_LED);


	clr_bit(PORTC, RED_LED);
	clr_bit(PORTC, YELLOW_LED);
	clr_bit(PORTC, GREEN_LED);

	ADC_Init();

	while (1)
	{
			adc_digital_value = ADC_Read(0);

		voltage_mv = ((u32)adc_digital_value * 5000UL) / 1024;
		
		temp = voltage_mv / 10;

		clr_bit(PORTC, RED_LED);
		clr_bit(PORTC, YELLOW_LED);
		clr_bit(PORTC, GREEN_LED);
		
		if (temp < 20)
		{
			set_bit(PORTC, GREEN_LED);
		}
		else if (temp >= 20 && temp <= 40)
		{
			set_bit(PORTC, YELLOW_LED);
		}
		else if (temp > 40)
		{
			set_bit(PORTC, RED_LED);
		}

		_delay_ms(100);
	}
}