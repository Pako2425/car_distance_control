#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "distance_sensor.h"
//#include "lcd_display.h"
//#include "buzzer.h"
#include "timers.h"

//#define BUZZER_PORT PORTC0

static uint8_t distanceMeasure = 0;
static uint16_t ovfTimer0Ctn = 0;
static uint8_t milisRunning = 0;

void milis(uint16_t timeInMs) {
	if(milisRunning == 0) {
		milisRunning = 1;
		ovfTimer0Ctn = 0;
		resetTimer0();
		startTimer0();
	}
	else {
		if(ovfTimer0Ctn < timeInMs) {
			stopTimer0();
			milisRunning = 0;
		}
	}
}

ISR(TIMER0_COMPA_vect) {
	ovfTimer0Ctn ++;
}

/*
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
*/

int main(void)
{
	sei();
	Timers_init();
	//init buzzer//
	//DDRC |= (1 << BUZZER_PORT);
	//PORTC &= ~(1 << BUZZER_PORT);
	//setFrequency(60);
	//-----------//
	DistanceSensor_init();
	//LcdDisplay_init();
	//Buzzer_init();
    while (1) 
    {
		/*
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
		}*/
		if(distanceMeasure == 0) {
			distanceMeasure = 1;
			trigerEchoSensor();
		}
		for(int i = 0; i<1; i++) {
			int a = 0;
		}
    }
}

