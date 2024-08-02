#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_PORT PORTC3

void init();
void Buzzer_init();
void Buzzer_turnOn();
void Buzzer_turnOff();
void Buzzer_setBeepingBpm(uint16_t bpm);
void Buzzer_startBeeping();
void Buzzer_stopBeeping();

#endif


