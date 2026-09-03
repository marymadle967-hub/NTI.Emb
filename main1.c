/*main*/
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include <util/delay.h>

void main(void)
{
 DIO_voidIntinitialization();
 
 while(1)
 {
  DIO_voidSetPinValue(DPORTA, PIN7 , HIGH);
  _delay_ms(1000);
  //_delay_us();
  //__asm("NOP");//ASSIMPLY CODE delay contains of this function
  DIO_voidSetPinValue(DPORTA, PIN7 , LOW);
  _delay_ms(1000);
 }
 
 
}
