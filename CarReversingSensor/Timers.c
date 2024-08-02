#include "timers.h"

#include <avr/io.h>

void initTimer0CTC() {
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS00);
	OCR0A = 160;
	TIMSK0 |= (1 << OCIE0A);
	TCNT0 = 0;
}

void initTimer1Capt() {	//1TCT = 4uS
	TCCR1B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);
	TCCR1B |= (1 << CS10);
	TCCR1B |= (1 << CS11);
	TCCR1B |= (1 << ICES1);
	TIMSK1 |= (1 << ICIE1);
	TCNT1 = 0;
}

void initTimer2Normal() {
	TCCR2B |= (1 << CS22);
	TIMSK2 |= (1 << TOIE2);
	TCNT2 = 0;
}

void Timers_init() {
	initTimer0CTC();
	initTimer1Capt();
	initTimer2Normal();
}

void stopTimer0() {
	TCCR0B &= ~(1 << CS00);
}

void startTimer0() {
	TCCR0B |= (1 << CS00);
}

void resetTimer0() {
	TCNT0 = 0;
}

void stopTimer1() {
	TCCR1B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);
}

void startTimer1() {
	TCCR1B |= (1 << CS12 | 1 << CS11 | 1 << CS10);
}

void resetTimer1() {
	TCNT1 = 0;
}
