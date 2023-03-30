//l'objectif de ce code est d'avoir un petit programme rapide pour nous aider a déterminer la bonne puissance a envoyer au moteur
//de la roue d'inertie pour garder un RPM constant (d'environ 6000rpm a priori)

//le code permet de controler la force du moteur avec le potentiometre linéaire et affiche la valeur sur le lcd

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
#include "utils.h"
#include "driver.h"
#include "uart.h"
#include "comms.h"

int main(void)
{

	int8_t input;
	uart_init(UART_0);
	sei();
	
	pwm2_init();
	
	while(1)
	{

 		if(!uart_is_rx_buffer_empty(UART_0))
 		{
			 input =  uart_get_byte(UART_0);
			 //************
			 //ATTENTION AJUSTER LIBRAIRIE DRIVER.c
			 //************
			 pwm2_set_PD6(input);

 		}	
	}
}