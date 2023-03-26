#include "utils.h"
#include "uart.h"

/**
    \brief Envoie un packet comprenant l'info de tout les inputs de la manette. UART doit déja être initié

	La fx envoie un bit 0, puis notre packet de 4 bit

	La fx filtre aussi les input pour ne pas envoyer de 0 (les valeurs de 0 sont donc impossible pour le joystick et le potentiometre)

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

	La fx lit le buffer jusqua atteindre 0, ce qui signifie le debut d'un packet

	\param[in]  port Port UART a utiliser (UART_0 ou UART_1)	
	\param[in]	packet char[4] qui sera notre output
    \return Rien

*/
void receive_packet(uart_e port, char* packet);

/**
    \brief Converti un uint8_t en array de 8 bool
	\param[in]  value uint8_t a 8 bool
	\param[in]	result array de 8 bool qui sera notre return
    \return Rien, voir result
    
*/
void uint8_to_bool_array(uint8_t value, bool* result);