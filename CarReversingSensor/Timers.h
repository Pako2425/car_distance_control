#ifndef TIMERS_H
#define TIMERS_H

void Timers_init();
void initTimer0();	//CTC
void initTimer1();	//Capt
void initTimer2();  //Normal

void stopTimer0();
void startTimer0();
void resetTimer0();

void stopTimer1();
void startTimer1();
void resetTimer1();

#endif