/*
 * counter_1.c
 *
 * Created: 3/8/2022 9:23:23 AM
 * Author : AUBAI
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	uint8_t counter;
	DDRA = 0xff;  // ���� ������ 8 �� ������� ����� ff
    /* Replace with your application code */
    while (1) 
    {
				for(counter = 0; counter <= 7; counter++)
				{
					PORTA = (1 << counter);
					_delay_ms(500);
				}
    }
	return 0;
	
}

