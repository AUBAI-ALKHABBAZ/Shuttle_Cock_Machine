/*
 * PWM_model.c
 *
 * Created: 1/12/2023 9:38:11 AM
 * Author : AUBAI
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile uint8_t adcValue;

int main(void)
{
DDRD=0xFF; // set PD as output port
DDRB=0xFF; //Set PB as output port
PORTB=0x00;
ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);// enable A/D, and

ADMUX=0x25; // choose input channel 5, and left adjust result
TCCR0A |= (1 << WGM00)| (1 << WGM02); // set timer mode to PWM (5)
TCCR0A |= (1<<COM0A0)| (1<<COM0A1); // Inverting on OC0A
TCCR0B |= (1 << CS02) | (1 << CS00); 
    while (1) 
    {
		ADCSRA |= (1<<ADSC); //start conversion
		while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
		OCR0A = ADCH; // read the ADC high byte
    }
}

