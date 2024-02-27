/**
 * @file fsm_usart.h
 * @brief Header for fsm_usart.c file.
 * @author Jorge Lajeandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 27/02/2024 
 */

#ifndef FSM_USART_H_
#define FSM_USART_H_
#define USART_INPUT_BUFFER_LENGTH
#define USART_OUTPUT_BUFFER_LENGTH
/* Includes ------------------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Other includes */
#include "fsm.h"
/* HW dependent includes */

/* Defines and enums ----------------------------------------------------------*/
/* Enums */
/**
 * @brief States for the finite state machine for the usart
 * 
*/
enum FSM_USART {
    WAIT_DATA = 0,  /*!< Initial state. Also comes here when data has been send or read*/
    SEND_DATA       /*!< Send data state*/
};

/* Typedefs --------------------------------------------------------------------*/
/**
 * @brief FSM structure for the usart
*/
typedef struct {
    fsm_t f;
    bool data_received;
    char in_data[USART_INPUT_BUFFER_LENGTH];
    char out_data[USART_OUTPUT_BUFFER_LENGTH];
    uint32_t usart_id;
} fsm_usart_t;

/* Function prototypes and explanation -------------------------------------------------*/
bool fsm_usart_check_activity(fsm_t * p_this);


#endif /* FSM_USART_H_ */
