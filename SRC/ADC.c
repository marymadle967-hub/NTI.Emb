#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"

void ADC_Init (void)
{
   clr_bit(ADMUX_Reg, 7); 
    set_bit(ADMUX_Reg, 6); 
// freq/128
   set_bit(ADCSRA_Reg, 2); 
    set_bit(ADCSRA_Reg, 1); 
    set_bit(ADCSRA_Reg, 0); 

    set_bit(ADCSRA_Reg, 7); //ADEN=1
}

u16 ADC_Read (u8 channel)
{
	ADMUX_Reg = (ADMUX_Reg & 0xE0) | (channel & 0x1F);

    set_bit(ADCSRA_Reg, 6); 

    while (GET_BIT(ADCSRA_Reg, 4) == 0);

   set_bit(ADCSRA_Reg, 4); 

    u16 adc_val = ADCL_Reg;
    adc_val |= (ADCH_Reg << 8);

    return adc_val;
}