#include "comms.h"
#include "utils.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include "uart.h"


//TODO EMPECHER UINT8 DAVOIR 0 COMME VALEUR
void send_packet(uart_e port, uint8_t x, uint8_t y, uint8_t potentiometre,bool S1,bool S2,bool S3,bool S4,bool S5,bool S6,bool S7) {

    uint8_t result = (S1 << 7) | (S2 << 6) | (S3 << 5) | (S4 << 4) | (S5 << 3) | (S6 << 2) | (S7 << 1) | 0;
    char packet[5] = {x,y,potentiometre,result,'\0'};
    uart_put_string(port, packet);
    uart_put_byte(port, 0);
}

// DEFINE char packet[5] = {0}; AVANT LA WHILE (j'ai peur que memory overload et que ca crash en moment donne pck on a creer trop de variable)

uint32_t receive_packet(uart_e port, char* packet){

    if(uart_is_rx_buffer_empty(port)=0){
        
        uart_get_string(port, packet, 4);
        uint32_t in = string_to_uint(packet);
        return in;
    }
}

//DEFINE uint8_t out[5] = {0}; AVANT LA WHILE

void uint32_to_uint(uint32_t value, uint8_t* result) {
    result[0] = (value >> 24) & 0xFF;
    result[1] = (value >> 16) & 0xFF;
    result[2] = (value >> 8) & 0xFF;
    result[3] = value & 0xFF;

    //CREDIT A CHATGPT
}

//DEFINE bool bouton[8]={0}; AVANT LA WHILE

void uint8_to_bool_array(uint8_t value, bool* result){
    for (size_t i = 0; i < 8; i++) {
        result[8 - i - 1] = (value & (1 << i)) ? TRUE : FALSE;
    }
}

