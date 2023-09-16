/*
 * shuttle_cock_C.c
 *
 * Created: 12/28/2022 8:45:00 AM
 * Author : AUBAI
 */ 
#define F_CPU 10000000
#include <avr/io.h>
#include <util/delay.h>
#include "bit_math.h"
#define LCD_Port PORTD			//Define LCD Port (PORTA, PORTB, PORTC, PORTD)
#define LCD_DPin  DDRD			//Define 4-Bit Pins (PD4-PD7 at PORT D)
#define RSPIN PD0			//RS Pin
#define ENPIN PD1 			//E Pin
int runtime;
volatile uint8_t adcValue; 			 //Timer for LCD
void delay_M_10()
{
	BIT_CLEAR(PORTB,2);
	BIT_SET(PORTB,0);
	BIT_SET(PORTB,3);
	_delay_ms(900);
	BIT_CLEAR(PORTB,3);
	BIT_SET(PORTB,0);
	BIT_SET(PORTB,2);
	_delay_ms(100);
}
void delay_M_20()
{
	BIT_CLEAR(PORTB,2);
	BIT_SET(PORTB,0);
	BIT_SET(PORTB,3);
	_delay_ms(2000);
	BIT_CLEAR(PORTB,3);
	BIT_SET(PORTB,0);
	BIT_SET(PORTB,2);
	_delay_ms(100);
}
void delay_M_30()
{
	BIT_CLEAR(PORTB,2);
	BIT_SET(PORTB,0);
	BIT_SET(PORTB,3);
	_delay_ms(3000);
	BIT_CLEAR(PORTB,3);
	BIT_SET(PORTB,0);
	BIT_SET(PORTB,2);
	_delay_ms(100);
}
void LCD_Action( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	LCD_Port &= ~ (1<<RSPIN);
	LCD_Port |= (1<<ENPIN);
	_delay_us(1);
	LCD_Port &= ~ (1<<ENPIN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
	LCD_Port |= (1<<ENPIN);
	_delay_us(1);
	LCD_Port &= ~ (1<<ENPIN);
	_delay_ms(2);
}

void LCD_Init (void)
{
	LCD_DPin = 0xFF;		//Control LCD Pins (D4-D7)
	_delay_ms(15);		//Wait before LCD activation
	LCD_Action(0x02);	//4-Bit Control
	LCD_Action(0x28);       //Control Matrix @ 4-Bit
	LCD_Action(0x0c);       //Disable Cursor
	LCD_Action(0x06);       //Move Cursor
	LCD_Action(0x01);       //Clean LCD
	_delay_ms(2);
}
void LCD_Clear()
{
	LCD_Action (0x01);		//Clear LCD
	_delay_ms(2);			//Wait to clean LCD
	LCD_Action (0x80);		//Move to Position Line 1, Position 1
}

void LCD_Print (char *str)
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_Port = (LCD_Port & 0x0F) | (str[i] & 0xF0);
		LCD_Port |= (1<<RSPIN);
		LCD_Port|= (1<<ENPIN);
		_delay_us(1);
		LCD_Port &= ~ (1<<ENPIN);
		_delay_us(200);
		LCD_Port = (LCD_Port & 0x0F) | (str[i] << 4);
		LCD_Port |= (1<<ENPIN);
		_delay_us(1);
		LCD_Port &= ~ (1<<ENPIN);
		_delay_ms(2);
	}
}
void LCD_Printpos (char row, char pos, char *str)
{
	if (row == 0 && pos<16)
	LCD_Action((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_Action((pos & 0x0F)|0xC0);
	LCD_Print(str);
}
int main(void)
{
	
	//DDRB = 0xFF ;
/*or(int i =0 ;i<3 ; i++){
		BIT_SET(DDRB,i);
		BIT_CLEAR(DDRD,i);
	} */
	DDRB = 0xff;
	DDRC = 0b00000000;
	DDRD=0xFF; // set PD as output port
	DDRB=0xFF; //Set PB as output port
	LCD_Init(); //Activate LCD
	LCD_Print("Hello user ");
	_delay_ms(100);
	LCD_Clear();
	LCD_Print("AUBAI");
	_delay_ms(100);
	LCD_Clear();
	PORTB=0x00;
/*	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);// enable A/D, and

	ADMUX=0x25; // choose input channel 5, and left adjust result
	TCCR0A |= (1 << WGM00)| (1 << WGM02); // set timer mode to PWM (5)
	TCCR0A |= (1<<COM0A0)| (1<<COM0A1); // Inverting on OC0A
	TCCR0B |= (1 << CS02) | (1 << CS00);*/
    /* Replace with your application code */
    while (1) 
    {		
		/*	if(BIT_CHECK(PINC,0) == 1){
		  ADCSRA |= (1<<ADSC); //start conversion
		  while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
		  adcValue = ADCH;// read the ADC high byte
		  OCR0A =adcValue;}*/
			if (BIT_CHECK(PINC,0) == 1) { 				
					ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);// enable A/D, and

					ADMUX=0x25; // choose input channel 5, and left adjust result
					TCCR0A |= (1 << WGM00)| (1 << WGM02); // set timer mode to PWM (5)
					TCCR0A |= (1<<COM0A0)| (1<<COM0A1); // Inverting on OC0A
					TCCR0B |= (1 << CS02) | (1 << CS00);
				
				
				LCD_Print("Feeder delay_10s");
				_delay_ms(100);

				BIT_CLEAR(PORTB,2);
				BIT_SET(PORTB,0);
				BIT_SET(PORTB,3);
				_delay_ms(900);
				BIT_CLEAR(PORTB,3);
				BIT_SET(PORTB,0);
				BIT_SET(PORTB,2);
				_delay_ms(200);
				LCD_Clear();
				ADCSRA |= (1<<ADSC); //start conversion
				while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
				adcValue = ADCH;// read the ADC high byte
				OCR0A =adcValue;
				} // Button 1 pressed

			else if (BIT_CHECK(PINC,1) == 1) {
				ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);// enable A/D, and

				ADMUX=0x25; // choose input channel 5, and left adjust result
				TCCR0A |= (1 << WGM00)| (1 << WGM02); // set timer mode to PWM (5)
				TCCR0A |= (1<<COM0A0)| (1<<COM0A1); // Inverting on OC0A
				TCCR0B |= (1 << CS02) | (1 << CS00);
				
				
				
				LCD_Print("Feeder delay_20s");
				_delay_ms(100);
				
					BIT_CLEAR(PORTB,2);
				BIT_SET(PORTB,0);
				BIT_SET(PORTB,3);
				_delay_ms(2000);
				BIT_CLEAR(PORTB,3);
				BIT_SET(PORTB,0);
				BIT_SET(PORTB,2);
				_delay_ms(200);
				LCD_Clear();
								ADCSRA |= (1<<ADSC); //start conversion
								while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
								adcValue = ADCH;// read the ADC high byte
								OCR0A =adcValue;
				} // Button 2 pressed

			else if (BIT_CHECK(PINC,2) == 1) {
									ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);// enable A/D, and

									ADMUX=0x25; // choose input channel 5, and left adjust result
									TCCR0A |= (1 << WGM00)| (1 << WGM02); // set timer mode to PWM (5)
									TCCR0A |= (1<<COM0A0)| (1<<COM0A1); // Inverting on OC0A
									TCCR0B |= (1 << CS02) | (1 << CS00);
				
				LCD_Print("Feeder delay_30s");
				_delay_ms(100);
				
				BIT_CLEAR(PORTB,2);
				BIT_SET(PORTB,0);
				BIT_SET(PORTB,3);
				_delay_ms(3000);
				BIT_CLEAR(PORTB,3);
				BIT_SET(PORTB,0);
				BIT_SET(PORTB,2);
				_delay_ms(200);
				LCD_Clear();
												ADCSRA |= (1<<ADSC); //start conversion
												while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
												adcValue = ADCH;// read the ADC high byte
												OCR0A =adcValue;
				} // Button 3 pressed
			else {
				LCD_Print("press button");
				_delay_ms(100);
				LCD_Clear();}
		}
	}


