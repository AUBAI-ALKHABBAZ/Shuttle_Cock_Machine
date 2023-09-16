/*
 * puls_1.c
 *
 * Created: 3/6/2022 3:49:39 PM
 * Author : AUBAI
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
//#define BIT_SET(PORTA,0) (PORTA |= (1<<0))
//#define BIT_SET(PORTC,0) (PORTC |= (1<<0))
int main(void)
{
    /* Replace with your application code */
	 DDRC = 0b00000000;
	 DDRA = 0b00000001;
	 PORTC = 0b00000001;
    while (1) 
    {
		 
		if ((PINC & (1<<0))==0)
		{
			PORTA=0b00000001;
			_delay_ms(1000);
			PORTA=0b00000000;
			_delay_ms(1000);
		}
			
		
    }
}

