#define F_CPU 160000000
#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>

#include "lcd_display.h"

void send4Bits(uint8_t bits) {
	PORTD &= 0x0F;
	PORTD |= (bits << 4);
	PORTB |= (1 << E);
	_delay_us(100);
	PORTB &= ~(1 << E);
	_delay_us(100);
}

void sendCommand(uint8_t cmnd) {
	uint8_t higherBits = cmnd & 0xF0;
	uint8_t lowerBits = cmnd & 0x0F;
	PORTB &= ~(1 << RS);
	send4Bits(higherBits >> 4);
	send4Bits(lowerBits);
}

void sendData(uint8_t data) {
	uint8_t higherBits = data & 0xF0;
	uint8_t lowerBits = data & 0x0F;
	PORTB |= (1 << RS);
	send4Bits(higherBits >> 4);
	send4Bits(lowerBits);
}

void LcdDisplay_init() {
	DDRD |= (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7);
	DDRB |= (1 << E) | (1 << RW) | (1 << RS);
	
	PORTB &= ~(1 << RW);
	PORTB &= ~(1 << RS);
	PORTB &= ~(1 << E);
	
	_delay_ms(20);
	send4Bits(0x03);
	_delay_ms(1);
	send4Bits(0x03);
	_delay_ms(1);
	send4Bits(0x03);
	_delay_ms(1);
	send4Bits(0x02);
	_delay_ms(1);
	
	sendCommand(0x02);
	_delay_ms(1);
	sendCommand(0x0C);
	_delay_ms(1);
	sendCommand(0x06);
	_delay_ms(1);
	sendCommand(0x01);
	_delay_ms(10);
}

void LcdDisplay_display(const char* content) {
	if(content == NULL) {
		return;
	}
	
	size_t length = strlen(content);
	sendCommand(0x02);
	_delay_us(10);
	for(size_t i = 0; i < length; i++) {
		sendData(content[i]);
		_delay_us(10);
	}
}