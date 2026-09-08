#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "ADC.h"
#include "timer0.h"

int main(void) {
  
  DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);

  TIMER0_voidInitCTC();


  while (1) {
    
  }

  return 0;
}