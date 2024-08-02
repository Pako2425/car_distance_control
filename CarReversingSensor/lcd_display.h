#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#define RS PINB4
#define RW PINB3
#define E PINB2
#define D7 PIND7
#define D6 PIND6
#define D5 PIND5
#define D4 PIND4

void send4Bits(uint8_t bits);
void sendCommand(uint8_t cmnd);
void sendData(uint8_t data);

void LcdDisplay_init();
void LcdDisplay_display(const char* content);


#endif
