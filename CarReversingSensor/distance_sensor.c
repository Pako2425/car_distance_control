#define F_CPU 16000000
#include "distance_sensor.h"
#include "timers.h"

static volatile uint16_t startTime;
static volatile uint16_t endTime;
static volatile uint8_t pulseCompleted;
static volatile uint8_t trigerPulse;
static volatile uint16_t answerPulseLength;

/*
void initTimer0CTC() {
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS00);
	OCR0A = 160;
	TIMSK0 |= (1 << OCIE0A);
	TCNT0 = 0;
}

void stopTimer0() {
	TCCR0B &= ~(1 << CS00);
}

void stopTimer1() {
	TCCR1B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);
}

void initTimer1Capt() {	//1TCT = 4uS
	TCCR1B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);
	TCCR1B |= (1 << CS10);
	TCCR1B |= (1 << CS11);
	TCCR1B |= (1 << ICES1);
	TIMSK1 |= (1 << ICIE1);
	TCNT1 = 0;
}
*/
ISR(TIMER0_COMPA_vect) {
	trigerPulse = 0;
}

ISR(TIMER1_CAPT_vect) {
	if(TCCR1B & (1 << ICES1)) {
		startTime = ICR1;
		TCCR1B &= ~(1 << ICES1);
	}
	else {
		TCCR1B |= (1 << ICES1);
		endTime = ICR1;
		pulseCompleted = 1;
	}
}

void trigerEchoSensor() {
	trigerPulse = 1;
	initTimer0CTC();
	PORTB |= (1 << TRIGER_PORT);
	while(trigerPulse) {}
	PORTB &= ~(1 << TRIGER_PORT);
	stopTimer0();
}

uint16_t measurePulseLength() {
	pulseCompleted = 0;
	initTimer1Capt();
	while(!pulseCompleted) {}
	stopTimer1();
	return endTime - startTime;
}

double calculateDistance(uint16_t answerPulseLength) {
	return (((double)(answerPulseLength * 4) / 1000000.0) * 170.0);
}

void DistanceSensor_init() {
	DDRB |= (1 << TRIGER_PORT);
	DDRB &= ~(1 << ECHO_PORT);
	initTimer0CTC();
	initTimer1Capt();
}

double DistanceSensor_measureDistance() {
	trigerEchoSensor();
	answerPulseLength = measurePulseLength();
	return calculateDistance(answerPulseLength);
}