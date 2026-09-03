#include <stdio.h>
#include "std_types.h"
#include<avr/io.h>
#include"BIT_MATH.h"
int main()
{
	DDRA = 0b00000010;  

	while(1)
	{
		if(GET_BIT(PINA, 0) == 0)
		{
			PORTA = 0b00000010;  
		}
		else
		{
			PORTA = 0b00000000;   
		}
	}

	return 0;
}