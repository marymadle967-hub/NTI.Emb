#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>

#include "ADC.h"

#define RED_LED    0
#define YELLOW_LED 1
#define GREEN_LED  2

int main(void)
{
  u16 adc_digital_value = 0;
  f32  voltage_mv = 0.0;

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

      voltage_mv = ((u32)adc_digital_value * 5000UL) / 1024UL;;

    clr_bit(PORTC, RED_LED);
    clr_bit(PORTC, YELLOW_LED);
    clr_bit(PORTC, GREEN_LED);

  if ( voltage_mv > 0.0 &&  voltage_mv < 1500)
    {
      set_bit(PORTC, RED_LED_PIN);   
    }
    else if ( voltage_mv >= 1500 &&  voltage_mv <= 3000)
    {
      set_bit(PORTC, YELLOW_LED_PIN); 
    }
    else if ( voltage_mv > 3000)
    {
      set_bit(PORTC, GREEN_LED_PIN);  
    }

    _delay_ms(100);
  }
}