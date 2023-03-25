#include "utils.h"

/**
    \brief Envoie un packet comprenant l'info de tout les inputs de la manette. UART doit déja être initié
	\param[in]  port Port UART a utiliser (UART_0 ou UART_1)	
	\param[in]	x Une valeur entre 0 et 255
	\param[in]	y Une valeur entre 0 et 255
	\param[in]	potentiometre Une valeur entre 0 et 255
	\param[in]	S1 Boolean
	\param[in]	S2 Boolean
	\param[in]	S3 Boolean
	\param[in]	S4 Boolean
	\param[in]	S5 Boolean
	\param[in]	S6 Boolean
	\param[in]	S7 Boolean
    \return Rien

*/
void send_packet(uart_e port, uint8_t x, uint8_t y, uint8_t potentiometre,bool S1,bool S2,bool S3,bool S4,bool S5,bool S6,bool S7);

/**
    \brief Envoie un packet comprenant l'info de tout les inputs de la manette. UART doit déja être initié
	\param[in]  port Port UART a utiliser (UART_0 ou UART_1)	
	\param[in]	packet char[5] vide à prédéfinir pour eviter des problemes de memoire
    \return Packet sous forme de 32bit

*/
uint32_t receive_packet(uart_e port, char* packet);

/**
    \brief Converti un int32b en array de 4 int8b
	\param[in]  value uint32_t a convertir en uint8	
	\param[in]	result array de 4 uint8_t qui sera notre return
    \return Rien, voir result
    
*/
void uint32_to_uint(uint32_t value, uint8_t* result);

/**
    \brief Converti un uint8_t en array de 8 bool
	\param[in]  value uint8_t a 8 bool
	\param[in]	result array de 8 bool qui sera notre return
    \return Rien, voir result
    
*/
void uint8_to_bool_array(uint8_t value, bool* result);