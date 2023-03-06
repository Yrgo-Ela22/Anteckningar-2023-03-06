/********************************************************************************
* header.h: Innehåller funktionsdeklarationer, både till C-kod samt subrutiner
*           skrivna i assembler. 
*
*           Subrutiner som ska anropas från C-kod ska deklareras i form av 
*           externa funktioner. I assemblerfilen i fråga måste de också 
*           deklareras till globala via direktivet .global.
*
*           Funktioner som ska anropas från assemblerkod måste vara deklarerade
*           som externa funktioner i C-koden. I assemblerfilen måste den också 
*           deklareras till extern via direktivet .extern.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/********************************************************************************
* F_CPU: Definierar klockfrekvensen till 16 MHz för fördröjningsrutiner.
********************************************************************************/
#define F_CPU 16000000UL

/********************************************************************************
* Inkluderingsdirektiv:
********************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

/********************************************************************************
* setup: Sätter lysdioden till utport och aktiverar den interna pullup-resistorn
*        på tryckknappens pin.
********************************************************************************/
void setup(void);

/********************************************************************************
* button_is_pressed: Returnerar true ifall tryckknappen BUTTON1 är nedtryckt,
*                    annars false.
********************************************************************************/
bool button_is_pressed(void);

/********************************************************************************
* led_off: Släcker lysdioden LED1.
********************************************************************************/
void led_off(void);

/********************************************************************************
* led_blink: Blinkar lysdioden LED1 med angiven blinkhastighet i millisekunder.
*
*            - blink_speed_ms: Blinkhastigheten i millisekunder.
********************************************************************************/
void led_blink(const uint16_t blink_speed_ms);

/********************************************************************************
* delay_ms: Genererar fördröjning mätt i millisekunder.
*
*           - delay_time_ms: Fördröjningstiden i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms);

#endif /* HEADER_H_ */