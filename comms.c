#include "comms.h"
#include "utils.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include "uart.h"



void send_packet(uart_e port, uint8_t x, uint8_t y, uint8_t potentiometre,bool S1,bool S2,bool S3,bool S4,bool S5,bool S6,bool S7) {
    
    uart_put_byte(port, 0)
    uint8_t result = (S1 << 7) | (S2 << 6) | (S3 << 5) | (S4 << 4) | (S5 << 3) | (S6 << 2) | (S7 << 1) | 1;

    if (x == 0) {
        x = 1;
    }

    if (y == 0) {
        y = 1;
    }

    if (potentiometre == 0) {
        potentiometre = 1;
    }
    
    char packet[5] = {x,y,potentiometre,result,'\0'};
    uart_put_string(port, packet);
    ;
}

// DEFINE char packet[4] = {0}; AVANT LA WHILE (j'ai peur que memory overload et que ca crash en moment donne pck on a creer trop de variable)

// FIXED : la fx lit le buffer jusqua avoir un 0, ensuite lit 4 bit (notre packet). devrais normalement fix les erreurs de sync

// TODO : verifier que la solution marche

void receive_packet(uart_e port, char* packet){

    uint8_t buffer = 1;
    
    if(uart_is_rx_buffer_empty(port)==0){    
        
        while (buffer!=0)
        {
            buffer = uart_get_byte(port);
        }

        for (int i = 0; i < 4; i++)
        {
            packet[i] = uart_get_byte(port);
        }
               
    }

    buffer = 1;
}


//DEFINE bool bouton[8]={0}; AVANT LA WHILE

void uint8_to_bool_array(uint8_t value, bool* result){
    for (size_t i = 0; i < 8; i++) {
        result[8 - i - 1] = (value & (1 << i)) ? TRUE : FALSE;
    }
}

