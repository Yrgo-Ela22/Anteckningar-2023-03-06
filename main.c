/********************************************************************************
* main.c: Demonstration av kombinerat C- och assemblerprogram. I praktiken g�r
*         det utm�rkt att l�gga till assemblerkod i ett C-projekt, antingen
*         inline via nyckelordet asm, t.ex. asm("SEI"), men ocks� via hela
*         filer. �ndelsen f�r s�dana assemblerfiler ska s�ttas till .s i st�llet
*         f�r .asm.
*
*         En lysdiod LED1 ansluts till pin 8 (PORTB0) och en tryckknapp ansluts
*         till pin 13 (PORTB5). Vid nedtryckning av tryckknappen blinkar
*         lysdioden var 100:e ms, annars h�lls den sl�ckt.
*
*         Samtliga tillf�rda funktioner f�rutom f�rdr�jningsrutinen implementeras
*         i assembler, s� vi kommer hoppa mellan C- och assemblerkod.
********************************************************************************/
#include "header.h"

/********************************************************************************
* delay_ms: Genererar f�rdr�jning m�tt i millisekunder.
*
*           - delay_time_ms: F�rdr�jningstiden i millisekunder.
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
* main: Initierar systemet vid start. Programmet h�lls ig�ng s� l�nge 
*       matningssp�nning tillf�rs. Tryckknappen BUTTON1 pollas (avl�ses)
*       kontinuerligt. Vid nedtryckning blinkar lysdioden LED1 med 
*       blinkhastigheten 100 ms, annars h�lls LED1 sl�ckt.
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

