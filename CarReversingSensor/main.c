#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "distance_sensor.h"
#include "lcd_display.h"
//#include "buzzer.h"
#include "timers.h"

//#define BUZZER_PORT PORTC0

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
	LcdDisplay_init();
	//Buzzer_init();
    while (1) 
    {
		DistanceSensor_measureDistance();
		double distance = DistanceSensor_getDistance();
		char buffer[16];
		dtostrf(distance, 16, 2, buffer);
		LcdDisplay_display(buffer);
		milis(400);

		/*
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
    }
}

