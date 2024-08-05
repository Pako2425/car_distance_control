#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define TRIGER_PORT PORTB1
#define ECHO_PORT PORTB0

ISR(TIMER0_COMPA_vect);
ISR(TIMER1_CAPT_vect);

void trigerEchoSensor();
void measurePulseLength();
void calculateDistance(uint16_t answerPulseLength);

void DistanceSensor_init();
void DistanceSensor_measureDistance();
double DistanceSensor_getDistance();

#endif