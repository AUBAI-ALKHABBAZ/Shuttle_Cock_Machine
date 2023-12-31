/*
 * ISP.c
 *
 * Created: 3/9/2022 2:47:11 PM
 * Author : AUBAI
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int main(void)
{
	
	DDRA |= (1 << PA0);
	DDRB |= (1 << PB0);
	
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);
	
	MCUCR |= (1 << ISC01);
	GICR |= (1 << INT0);
	
	sei();
	while(1)
	{
		PORTA ^= (1 << PA0);
		_delay_ms(100);
	}
	return 0;
}
ISR(INT0_vect)
{
	PORTB ^= (1 << PB0);
}

