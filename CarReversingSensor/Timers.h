#ifndef TIMERS_H
#define TIMERS_H

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect);

void Timers_init();
void initTimer0();
void initTimer1();
void initTimer2();

void stopTimer0();
void startTimer0();
void resetTimer0();

void stopTimer1();
void startTimer1();
void resetTimer1();

void milis(uint16_t timeInMs);

#endif