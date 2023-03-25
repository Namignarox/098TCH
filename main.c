/*
 * LABO22.c
 *
 * Created: 2023-02-03 14:26:19
 * Author : at06700
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
#include "utils.h"
#include "driver.h"
#include "uart.h"

int main(void)
{
			
	//init de la communication UART
	uart_init(UART_0);
	
	//configuration du bouton
	//DDRA=clear_bit(DDRA,PA2);
	//PORTA=set_bit(PORTA,PA2);
	//uint8_t bouton = 1;
	
	// initialisation de l'�cran
	lcd_init();
	lcd_clear_display();
	char str[40];
	

	
	// initialisation du CAN (ADC)
	adc_init();
	uint8_t out = 0;
	

	
	//activer les interruptions globales
	sei();
	
	
    /* Replace with your application code */
    while (1) 
    {
		//Maybe x y
     	out = adc_read(PINA0);
		lcd_clear_display();
		
		// cr�er la cha�ne de car. pour l'affichage
		sprintf(str,"%d",out);
		
		// afficher le texte sur l'�cran
		lcd_set_cursor_position(0,0);
		//lcd_write_string(str);
		lcd_write_string(str);
		
		//uart_put_string(UART_0,str);
		uart_put_byte(UART_0, out);
		
		_delay_ms(99);
    }
}

