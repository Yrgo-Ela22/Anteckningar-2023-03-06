/********************************************************************************
* header.h: Inneh�ller funktionsdeklarationer, b�de till C-kod samt subrutiner
*           skrivna i assembler. 
*
*           Subrutiner som ska anropas fr�n C-kod ska deklareras i form av 
*           externa funktioner. I assemblerfilen i fr�ga m�ste de ocks� 
*           deklareras till globala via direktivet .global.
*
*           Funktioner som ska anropas fr�n assemblerkod m�ste vara deklarerade
*           som externa funktioner i C-koden. I assemblerfilen m�ste den ocks� 
*           deklareras till extern via direktivet .extern.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/********************************************************************************
* F_CPU: Definierar klockfrekvensen till 16 MHz f�r f�rdr�jningsrutiner.
********************************************************************************/
#define F_CPU 16000000UL

/********************************************************************************
* Inkluderingsdirektiv:
********************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

/********************************************************************************
* setup: S�tter lysdioden till utport och aktiverar den interna pullup-resistorn
*        p� tryckknappens pin.
********************************************************************************/
void setup(void);

/********************************************************************************
* button_is_pressed: Returnerar true ifall tryckknappen BUTTON1 �r nedtryckt,
*                    annars false.
********************************************************************************/
bool button_is_pressed(void);

/********************************************************************************
* led_off: Sl�cker lysdioden LED1.
********************************************************************************/
void led_off(void);

/********************************************************************************
* led_blink: Blinkar lysdioden LED1 med angiven blinkhastighet i millisekunder.
*
*            - blink_speed_ms: Blinkhastigheten i millisekunder.
********************************************************************************/
void led_blink(const uint16_t blink_speed_ms);

/********************************************************************************
* delay_ms: Genererar f�rdr�jning m�tt i millisekunder.
*
*           - delay_time_ms: F�rdr�jningstiden i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms);

#endif /* HEADER_H_ */