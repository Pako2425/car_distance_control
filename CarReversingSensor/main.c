#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "distance_sensor.h"
#include "lcd_display.h"
//#include "buzzer.h"
#include "timers.h"

#define BUZZER_PORT PORTC0

static uint16_t ovfCtn = 0;
static uint16_t singleBitDuration = 0;

void setFrequency(uint8_t bpm) {
	if(bpm == 0) {
		singleBitDuration = 0;
	}
	else {
		singleBitDuration = 60000 / bpm;
	}
}

ISR(TIMER2_OVF_vect) {
	if(ovfCtn < (singleBitDuration / 2)) {
		ovfCtn++;
	}
	else {
		ovfCtn = 0;
		PORTC ^= (1 << BUZZER_PORT);
	}
}

int main(void)
{
	sei();
	Timers_init();
	//init buzzer//
	DDRC |= (1 << BUZZER_PORT);
	PORTC &= ~(1 << BUZZER_PORT);
	setFrequency(60);
	//-----------//
	DistanceSensor_init();
	LcdDisplay_init();
	//Buzzer_init();
    while (1) 
    {
		double distance = DistanceSensor_measureDistance();
		char buffer[16];
		dtostrf(distance, 16, 2, buffer);
		LcdDisplay_display(buffer);
		_delay_ms(500);
		if(distance > 1) {
			setFrequency(70);
		}
		else if(distance > 0.5) {
			setFrequency(120);
		}
		else if(distance > 0.3) {
			setFrequency(200);
		}
		else if(distance > 0.2) {
			setFrequency(290);
		}
		else if(distance > 0.1) {
			setFrequency(400);
		}
		else {
			setFrequency(0);
		}
    }
}

