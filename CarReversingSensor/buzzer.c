#include <avr/io.h>
#include "buzzer.h"

void init() {
	DDRD |= (1 << BUZZER_PORT);
	PORTD &= ~(1 << BUZZER_PORT);
}

void Buzzer_turnOn() {
	PORTD |= (1 << BUZZER_PORT);
}

void Buzzer_turnOff() {
	PORTD &= ~(1 << BUZZER_PORT);
}

void Buzzer_init() {
	init();
}

void Buzzer_setBeepingBpm(uint16_t bpm) {
	
}

void Buzzer_startBeeping() {
	
}

void Buzzer_stopBeeping() {
	
}