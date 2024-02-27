/**
 * @file fsm_usart.h
 * @brief Header for fsm_usart.c file.
 * @author Jorge Lajeandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 27/02/2024 
 */

#ifndef FSM_USART_H_
#define FSM_USART_H_

/* Includes ------------------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Other includes */
#include "fsm.h"
#include "port_usart.h"
/* HW dependent includes */

/* Defines and enums ----------------------------------------------------------*/
/* Enums */
enum  	FSM_USART {
  WAIT_DATA = 0,    /*!< Initial state  */
  SEND_DATA = 1,    /*!< Send data state*/
}

/* Typedefs --------------------------------------------------------------------*/


/* Function prototypes and explanation -------------------------------------------------*/



#endif /* FSM_USART_H_ */
