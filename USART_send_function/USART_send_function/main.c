/*
 * USART_send_function.c
 *
 * Created: 3/13/2022 8:54:28 PM
 * Author : AUBAI
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
void UART_init()
{	uint16_t UBRR_Value = lrint ( (F_CPU / (16L * 9600) ) -1);
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value >> 8);
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);}
void UART_send_char(char data)
{
	while( ! (UCSRA & (1<<UDRE) ) );
	UDR = data;
}
void UART_send_string(char *data)
{
	while(*data > 0)
	UART_send_char(*data++);
	UART_send_char('\0');
	_delay_ms(200);
}
int main(void)
{
	 UART_init(9600) ;
    while (1) 
    {
	UART_send_string("AUBAI");
    }
}

