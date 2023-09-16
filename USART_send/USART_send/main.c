/*
 * USART_send.c
 *
 * Created: 3/13/2022 8:29:49 PM
 * Author : AUBAI
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRC &= ~((1<<PC0) | (1<<PC3)); // ßÏÎá áÊÚãá ÇáØÑÇÝ ÖÈØ
	PORTC |= (1<<PC0) | (1<<PC3); //ÇáÑÝÚ ãÞÇæãÉ ÊÝÚíá
	uint16_t UBRR_Value = 103;
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value >> 8);
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);
    while (1) 
    {
		if(bit_is_clear(PINC,0))
		{
			while(!(UCSRA & (1<<UDRE)));
			UDR = 'N';
			_delay_ms(300);
		}
		if(bit_is_clear(PINC,3))
		{
			while(!(UCSRA & (1<<UDRE)));
			UDR = 'F';
			_delay_ms(300);
		}
    }
}

