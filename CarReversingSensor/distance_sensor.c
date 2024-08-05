#define F_CPU 16000000
#include "distance_sensor.h"
#include "timers.h"

static volatile uint16_t startTime;
static volatile uint16_t endTime;
static volatile uint8_t distanceMeasurement = 0;
static volatile uint8_t trigerPulse = 0;
static volatile uint16_t answerPulseLength = 0;

static volatile double distance = 0.0;

ISR(TIMER1_COMPA_vect) {
	PORTB &= ~(1 << TRIGER_PORT);
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
		answerPulseLength = endTime - startTime;
		distanceMeasurement = 0;
	}
}

void trigerEchoSensor() {
	trigerPulse = 1;
	OCR1A = TCNT1 + 3;
	PORTB |= (1 << TRIGER_PORT);
}

void measurePulseLength() {
	distanceMeasurement = 1;
	resetTimer1();
	trigerEchoSensor();
}

void calculateDistance(uint16_t answerPulseLength) {
	distance = (((double)(answerPulseLength * 4) / 1000000.0) * 170.0);
}

void DistanceSensor_init() {
	DDRB |= (1 << TRIGER_PORT);
	DDRB &= ~(1 << ECHO_PORT);
	resetTimer1();
}

void DistanceSensor_measureDistance() {
	measurePulseLength();
	calculateDistance(answerPulseLength);
}

double DistanceSensor_getDistance() {
	return distance;
}
