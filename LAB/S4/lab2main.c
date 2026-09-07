#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "INTER.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
volatile u8 m=0;
int main(void)
{
    /* Replace with your application code */
	 initExternalInterupts();
	DDRA=0b11111111;
	
    while (1) 
    {
		if(m==0){
		 for (u8 i = 0; i < 8; i++)
		 { 
			 if(m!=0)break;
		   set_bit(PORTA,i);
            _delay_ms(150);
		 }
		 for (u8 i = 0; i < 8; i++)
		 {
			 if(m!=0)break;
			 clr_bit(PORTA,i);
			 _delay_ms(150);
		 }
		 
		}
		else if(m==1){
			PORTA=0b00000000;
			for (s8 i = 7; i >=0; i--)
			{
				if(m!=1)break;
				set_bit(PORTA,i);
				_delay_ms(150);
			}
			for (s8 i = 7; i >=0; i--)
			{
				if(m!=1)break;
				clr_bit(PORTA,i);
				_delay_ms(150);
			}
			
		}
		
		
		
    }
}
ISR(INT0_vect){
	m++;
	if(m>1){
		m=0;
	}
}
