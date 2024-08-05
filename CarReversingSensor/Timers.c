#include "timers.h"

#include <avr/io.h>

void initTimer0() {
	TCCR0A |= (1 << WGM01);
	OCR0A = 249;
	TIMSK0 |= (1 << OCIE0A);
	TCCR0B |= (1 << CS01) | (1 << CS00);
}

void initTimer1() {
	TCCR1B |= (1 << ICES1);
	TIMSK1 |= (1 << ICIE1) | (1 << OCIE1A);
	OCR1A = 25000;
	TCCR1B |= (1 << CS11 | 1 << CS10);	//prescaler 64
}

void initTimer2() {
	
}

/*
void initTimer2Normal() {
	TCCR2B |= (1 << CS22);
	TIMSK2 |= (1 << TOIE2);
	TCNT2 = 0;
}
*/
void Timers_init() {
	initTimer0();
	initTimer1();
	initTimer2();
}

void stopTimer0() {
	TCCR0B &= ~((1 << CS01) | (1 << CS00));
}

void stopTimer1() {
	TCCR1B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);
}

void startTimer0() {
	TCCR0B |= (1 << CS00);
}

void startTimer1() {
	TCCR1B |= (1 << CS11 | 1 << CS10);
}

void resetTimer0() {
	TCNT0 = 0;
}

void resetTimer1() {
	TCNT1 = 0;
}
