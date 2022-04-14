/*=============================================================================
 * Author: Pedro Valentin Nieva <valentin9702@gmail.com>
 * Date: 2022/03/30
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TP_1.h"
#include "sapi.h"
#include "GPIO.h" // Drivers del GPIO

/*=====[Definición de variables globales]==============================*/
int Tecla = 0;

/*=====[Definición de funciones]=============================*/
void STATE_ON(); // Estado encendido
void STATE_OFF();// Estado apagado

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();
   // Se inicializan los LEDs
   Init_LED('1');
   Init_LED('2');
   Init_LED('3');
   Init_LED('R');
   Init_LED('G');
   Init_LED('B');
   // Se inicializan las teclas
   Init_TEC(1);
   Init_TEC(2);
   Init_TEC(3);
   STATE_OFF();
   // ----- Bucle infinito -------------------------
   while( true ) {

	   // --- Lee si alguna tecla fue pulsada ---
	   if (Leer_TEC(1) != true){
		   Tecla=1;
	   }
	   if (Leer_TEC(2) != true){
		   Tecla=2;
	   }
	   if (Leer_TEC(3) != true){
		   Tecla=3;
	   }
	   if (Leer_TEC(4) != true){
		   Tecla=4;
	   }

	   // --- Si alguna tecla fue pulsada, cambia de estado, caso contrario, se mantiene en apagado ---
	   if (Tecla != 0){
		   STATE_ON();
	   } else{
		   STATE_OFF();
	   }
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

void STATE_ON(){ // --- Función de estado encendido ---
	switch (Tecla){
	case 1:
		Encender('1');
		Encender('R');
		break;
	case 2:
		Encender('2');
		Encender('G');
		break;
	case 3:
		Encender('3');
		Encender('B');
		break;
	case 4:
		Encender('1');
		Encender('2');
		Encender('3');
		Encender('R');
		Encender('G');
		Encender('B');

		break;
	}
	Tecla=0;
}
void STATE_OFF(){ // --- Función de estado apagado ---
	Apagar('1');
	Apagar('2');
	Apagar('3');
	Apagar('R');
	Apagar('G');
	Apagar('B');
}
