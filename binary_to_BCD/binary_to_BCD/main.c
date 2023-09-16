/*
 * binary_to_BCD.c
 *
 * Created: 3/7/2022 5:12:55 PM
 * Author : AUBAI
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRA = 0b00000001;
    while (1) 
    {
		PORTA = 0b00000001;
		_delay_ms(1000);
		PORTA = 0b00000000;
		_delay_ms(1000);
    }
	return 0; 
}

