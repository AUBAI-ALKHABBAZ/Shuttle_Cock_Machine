/*
 * ADC_resistor.c
 *
 * Created: 3/14/2022 8:52:24 AM
 * Author : AUBAI
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
volatile uint8_t adcValue;
int main(void)
{
	DDRA = 0x00;
	DDRC = 0xff;
	ADCSRA |= (1 << ADEN); 
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1);
	ADMUX |= (1 << ADLAR); 
	ADMUX |= (1 << MUX0); 
    /* Replace with your application code */
    while (1) 
    {
		ADCSRA |= (1 << ADSC);
		while(ADCSRA & (1<<ADSC));
		adcValue = ADCH;
		PORTC = adcValue;
    }
	return 0; 
}

