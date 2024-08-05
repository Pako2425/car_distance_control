#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define TRIGER_PORT PORTB1
#define ECHO_PORT PORTB0

//void initTimer0CTC();
//void initTimer1Capt();
//void stopTimer0();
//void stopTimer1();
ISR(TIMER0_COMPA_vect);
ISR(TIMER1_CAPT_vect);
void trigerEchoSensor();
void measurePulseLength();
double calculateDistance(uint16_t answerPulseLength);

void DistanceSensor_init();
double DistanceSensor_measureDistance();

#endif