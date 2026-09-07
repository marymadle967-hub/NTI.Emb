#define F_CPU 8000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "ADC.h"
#include "LCD.h"

#define GREEN_LED  0

int main(void)
{
  u16 adc_digital_value = 0;
    float  vout =0.0;
  
  clr_bit(DDRA, 0);
  
  
  
  set_bit(DDRC, GREEN_LED);


  clr_bit(PORTC, GREEN_LED);

  ADC_Init();

  while (1)
  {
      adc_digital_value = ADC_Read(0);
      
     vout = (adc_digital_value * 5.0) / 1024.0;


    clr_bit(PORTC, GREEN_LED);
    
    if(vout  <3){ //ldr<456
      set_bit(PORTC, GREEN_LED);
    }
    else{ //ldr>456
      clr_bit(PORTC, GREEN_LED);
    }

    _delay_ms(100);
  }
}