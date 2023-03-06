/********************************************************************************
* main.c: Demonstration av kombinerat C- och assemblerprogram. I praktiken går
*         det utmärkt att lägga till assemblerkod i ett C-projekt, antingen
*         inline via nyckelordet asm, t.ex. asm("SEI"), men också via hela
*         filer. Ändelsen för sådana assemblerfiler ska sättas till .s i stället
*         för .asm.
*
*         En lysdiod LED1 ansluts till pin 8 (PORTB0) och en tryckknapp ansluts
*         till pin 13 (PORTB5). Vid nedtryckning av tryckknappen blinkar
*         lysdioden var 100:e ms, annars hålls den släckt.
*
*         Samtliga tillförda funktioner förutom fördröjningsrutinen implementeras
*         i assembler, så vi kommer hoppa mellan C- och assemblerkod.
********************************************************************************/
#include "header.h"

/********************************************************************************
* delay_ms: Genererar fördröjning mätt i millisekunder.
*
*           - delay_time_ms: Fördröjningstiden i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms)
{
   for (uint16_t i = 0; i < delay_time_ms; ++i)
   {
      _delay_ms(1);
   }
   return;
}

/********************************************************************************
* main: Initierar systemet vid start. Programmet hålls igång så länge 
*       matningsspänning tillförs. Tryckknappen BUTTON1 pollas (avläses)
*       kontinuerligt. Vid nedtryckning blinkar lysdioden LED1 med 
*       blinkhastigheten 100 ms, annars hålls LED1 släckt.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {
      if (button_is_pressed())
      {
         led_blink(500);
      }
      else
      {
         led_off();
      }
   }

   return 0;
}

