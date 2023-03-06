;/********************************************************************************
;* gpio.s: Inneh�llet drivrutiner skrivna i assembler.
;*
;*         I .s-filer, definiera makron med direktivet #define i st�llet f�r .EQU.
;*         Skriv inte kommentarer inline, d� uppst�r konstiga fel!
;*
;*         F�r att eliminera den offset som finns mellan I/O-adresser och 
;*         dataadresser som g�r att PORTB har adress 0x05 i I/O-minnet, men
;*         0x25 i dataminnet (d� R0 - R31 ligger f�rst) anv�nds makrot 
;*         __SFR_OFFSET, d�r offseten normalt �r 0x20, men s�tts till 0.
;*         Om detta inte hade genomf�rts hade instruktioner IN och OUT ej 
;*         fungerat.       
;********************************************************************************/
#define __SFR_OFFSET 0

;/********************************************************************************
;* Inkluderingsdirektiv (enbart assemblerkompatibla bibliotek):
;********************************************************************************/
#include <avr/io.h>

;/********************************************************************************
;* Makrodefinitioner:
;* 
;*                    - LED1   : Lysdiod ansluten till pin 8 (PORTB0).
;*                    - BUTTON1: Tryckknapp ansluten till pin 13 (PORTB5).  
;********************************************************************************/
#define LED1    PORTB0
#define BUTTON1 PORTB5

;/********************************************************************************
;* Globala subrutiner (synliga utanf�r filen, kan anropas fr�n C-kod):
;********************************************************************************/
.GLOBAL setup
.GLOBAL button_is_pressed
.GLOBAL led_off
.GLOBAL led_blink

;/********************************************************************************
;* Externa funktioner (C-funktioner som ska anropas fr�n denna fil):
;********************************************************************************/
.EXTERN delay_ms

;/********************************************************************************
;* setup: S�tter lysdioden till utport och aktiverar den interna pullup-resistorn
;*        p� tryckknappens pin.
;********************************************************************************/
setup:
   LDI R16, (1 << LED1)
   OUT DDRB, R16
   LDI R17, (1 << BUTTON1)
   OUT PORTB, R17
   RET

;/********************************************************************************
;* button_is_pressed: Returnerar 1 ifall tryckknappen BUTTON1 �r nedtryckt,
;*                    annars 0. Returnv�rdet passeras i vanlig ordning i R24.
;********************************************************************************/
button_is_pressed:
   IN R24, PINB
   ANDI R24, (1 << BUTTON1)
   BRNE button_is_pressed_return_1
button_is_pressed_return_0:
   RET
button_is_pressed_return_1:
   LDI R24, 1
   RET

;/********************************************************************************
;* led_on: T�nder lysdioden LED1.
;********************************************************************************/
led_on:
   IN R16, PORTB
   ORI R16, (1 << LED1)
   OUT PORTB, R16
   RET

;/********************************************************************************
;* led_off: Sl�cker lysdioden LED1.
;********************************************************************************/
led_off:
   IN R16, PORTB
   ANDI R16, ~(1 << LED1)
   OUT PORTB, R16
   RET

;/********************************************************************************
;* led_blink: Blinkar lysdioden LED1 med angiven blinkhastighet i millisekunder.
;*            Notering: Vid anrop av C-funktionen delay_ms ska ing�ende argument
;*            delay_time_ms ligga i R25:R24, vilket det redan g�r efter att
;*            denna subrutin har anropats med angiven blinkhastighet 
;*            (detta hamnar i R25:R24, allts� r�tt registerpar).
;*
;*            - R25:R24: Blinkhastigheten i millisekunder.
;********************************************************************************/
led_blink:
   RCALL led_on
   RCALL delay_ms 
   RCALL led_off 
   RCALL delay_ms 
   RET