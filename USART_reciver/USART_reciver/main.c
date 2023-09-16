/*
 * USART_reciver.c
 *
 * Created: 3/13/2022 8:34:16 PM
 * Author : AUBAI
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRC |= (1<<PC0);
	uint16_t UBRR_Value = 103;
	char Received;
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value >> 8);
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);
    while (1) 
    {
		while (! (UCSRA & (1 << RXC)));
		Received = UDR;
		if(Received == 'N')
		PORTC |= (1<<PC0);
		if(Received == 'F')
		PORTC &= ~(1<<PC0);
    }
}

