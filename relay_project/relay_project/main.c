/*
 * relay_project.c
 *
 * Created: 3/19/2022 5:37:55 PM
 * Author : AUBAI
 */ 
#define F_CPU 1000000UL 
#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{
	DDRC &= ~(1 << PC0);
	DDRC &= ~(1 << PC1);
	//DDRC=0b11111111;
	//DDRA=0b11100000;
	PORTC |= (1 << PC0)|(1 << PC1); 
	DDRA|= (1 << PA5)|(1 << PA6)|(1 << PA7);
	
    /* Replace with your application code */
    while (1) 
    {
		if((PINC & (1<<0))==0)
		{
		PORTA |= (1<<PA5); 
		PORTA |= (1<<PA6); 
		PORTA &= ~ (1<<PA7);  
		//PORTA=0b01100000;
			//PORTA |= (1<<6);
		}
		if((PINC & (1<<1))==0)
		{
			PORTA &= ~ (1<<PA5);
			PORTA &= ~ (1<<PA6);
			PORTA |= (1<<PA7);
			//PORTA |= (1<<7);
			
		}
    }
}

