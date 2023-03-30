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
			
	//init de la communication UART
	uart_init(UART_0);
	
	// initialisation de l'ecran
	lcd_init();
	lcd_clear_display();
	char str[40];
	
	// initialisation du CAN (ADC)
	adc_init();
	uint8_t out = 0;
	
	//activer les interruptions globales
	sei();
	
	
    while (1) 
    {
		// TODO LORS DU TEST - S'ASSURER QUE LA PIN PINA2 EST LA BONNE
     	out = adc_read(PINA2);
		lcd_clear_display();
        
		
		// cr�er la cha�ne de car. pour l'affichage
		sprintf(str,"%d",out);
		
		// afficher le texte sur l'�cran
		lcd_set_cursor_position(0,0);
		lcd_write_string(str);
		
		//envoi du byte
		uart_put_byte(UART_0, out);
		
		_delay_ms(2);
    }
}