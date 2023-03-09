#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/pgmspace.h>

#define petternCount 3
#define patternDelay 400

//0b00000000000111000000111000000111,
//0b00000000111000000111000000111000,
//0b00000111000000111000000111000000

//0b00000000000001000000001000000001,
//0b00000000000010000000010000000010,
//0b00000000000100000000100000000100,
//0b00000000001000000001000000001000,
//0b00000000010000000010000000010000,
//0b00000000100000000100000000100000,
//0b00000001000000001000000001000000,
//0b00000010000000010000000010000000,
//0b00000100000000100000000100000000

const uint32_t PROGMEM Muster [3][8] =
{
	{
		(uint32_t)0b00000101010101010101010101010101,
		(uint32_t)0b00000010101010101010101010101010,
		(uint32_t)0b10000000000000000000000000000000,
		(uint32_t)0b10000000000000000000000000000000,
		(uint32_t)0,
		(uint32_t)0,
		(uint32_t)0,
		(uint32_t)0
	},	
	{
		(uint32_t)0b00000000000001000000001000000001,
		(uint32_t)0b00000000001010000001010000001010,
		(uint32_t)0b00000001010100001010100001010100,
		(uint32_t)0b00000010100000010100000010100000,
		(uint32_t)0b00000100000000100000000100000000,
		(uint32_t)0b00000010100000010100000010100000,
		(uint32_t)0b00000001010100001010100001010100,
		(uint32_t)0b00000000001010000001010000001010
	},
	{
		(uint32_t)0b00000000000000000000000000010000,
		(uint32_t)0b00000000000000000111010000010000,
		(uint32_t)0b00000111111111010111010000010000,
		(uint32_t)0b10000000000000000000000000000000,
		(uint32_t)0b00000000000000000000000000000000,
		(uint32_t)0b00000000000000000000000000000000,
		(uint32_t)0b00000000000000000000000000000000,
		(uint32_t)0b00000000000000000000000000000000,
	}
	
};

	char s = '0';
	int muster = 0;

void output(int layer, int pin) {
	PORTB = (uint8_t) layer;
	
	PORTB &= ~(1<<PB2 | 1<<PB3);
	PORTB |= (layer & (1<<PB3))>>1;
	PORTB |= (layer & (1<<PB2))<<1;

	PORTD = 0;
	PORTD |= 1 << pin;
	
	if ((PIND & (1 << PD2)) != 0 && s != '1')
	{
		s = '1';
		muster++;
		if (muster >= petternCount)
		muster = 0;
		_delay_ms(10);
	}

			
	if (s == '1' && (PIND & (1 << PD2)) == 0)
	s = '0';
}




int main(void)
{


	DDRB = 0xff;
	DDRD = ~((1<<PD2) | (1<<PD1) | (1<<PD0));
	
	int ms =  5;

	s = '0';
	muster = 0;
	
	
	while (1) {
		
		for (int i = 0;i < 8 ; i++)
		{
			if ((uint32_t)pgm_read_dword(&Muster[muster][i]) & (uint32_t)((uint32_t)1<<(uint32_t)31))
				break;

			float current = 0;
			while (current < patternDelay) {
				int layer1 = pgm_read_dword(&Muster[muster][i]) >> 1;
				int layer2 = pgm_read_dword(&Muster[muster][i]) >> 10;
				int layer3 = pgm_read_dword(&Muster[muster][i]) >> 19;
				
				output(layer1, PD3);
				PORTD &= ~(1<<PD6);
				
				if (pgm_read_dword(&Muster[muster][i]) & (uint32_t)0b00000000000000000000000000000001)
					PORTD |= 1<<PD6;
				_delay_ms(ms);
				
				output(layer2, PD5);
				PORTD &= ~(1<<PD6);
				
				if (pgm_read_dword(&Muster[muster][i]) & ((uint32_t)0b00000000000000000000000000000001 << 9))
				PORTD |= 1<<PD6;
				_delay_ms(ms);
				
				output(layer3, PD4);
				PORTD &= ~(1<<PD6);
				
				if (pgm_read_dword(&Muster[muster][i]) & ((uint32_t)0b00000000000000000000000000000001 << 18))
				PORTD |= 1<<PD6;
				_delay_ms(ms);
				
				current += ms * 3;
			}
		}
	}
}



