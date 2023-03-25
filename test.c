//#include "comms.h"
#include "utils.h"
//#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
//#include "uart.h"

char uint_to_char(uint8_t digit){

    char caracter = '\0';

    if((digit >= 0) && (digit <= 9)){

        caracter = digit + '0';
    }

    return caracter;
}

void send_packet(uint8_t x, uint8_t y, uint8_t potentiometre,bool S1,bool S2,bool S3,bool S4,bool S5,bool S6,bool S7) {

    uint8_t result = (S1 << 7) | (S2 << 6) | (S3 << 5) | (S4 << 4) | (S5 << 3) | (S6 << 2) | (S7 << 1) | 0;
    printf("%d\n",result);
    char packet[5] = {x,y,potentiometre,result,'\0'};
    printf("%s\n", packet);
   // uart_put_string(port, packet);
}

int main(int argc, char const *argv[])
{
    /* code */
    send_packet(110,110,110,0,0,1,1,1,1,1);


    return 0;
}
