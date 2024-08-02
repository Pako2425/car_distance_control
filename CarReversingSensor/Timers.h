#ifndef TIMERS_H
#define TIMERS_H

void Timers_init();
void initTimer0CTC();
void initTimer1Capt();
void initTimer2Normal();

void stopTimer0();
void startTimer0();
void resetTimer0();

void stopTimer1();
void startTimer1();
void resetTimer0();

#endif