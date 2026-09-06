#define F_CPU 8000000UL
#include <util/delay.h>
#include<avr/io.h>
int main(void)
{
  DDRA =0b00000001;
   
  while(1)
  {
  PORTA=0b00000001;
  _delay_ms(1000);
  
  PORTA=0b00000000;
  _delay_ms(1000);
  }

  return 0;
}