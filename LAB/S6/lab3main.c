#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SERVO.h"

int main(void) {

	SERVO_voidInit();
 
	while (1) {
	 
	  
		SERVO_voidSetAngle(0);
		_delay_ms(100);

		SERVO_voidSetAngle(90);
		_delay_ms(100);
		
		SERVO_voidSetAngle(180);
		_delay_ms(100);
	}

	return 0;
}