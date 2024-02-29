/**
 * @file fsm_usart.h
 * @brief Header for fsm_usart.c file.
 * @author Jorge Lajeandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 27/02/2024 
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
/* Other includes */
#include "fsm.h"

/* Defines and enums ----------------------------------------------------------*/

#ifndef FSM_USART_H_
#define FSM_USART_H_

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
//#define USART_INPUT_BUFFER_LENGTH 0 // TODO FIX
//#define USART_OUTPUT_BUFFER_LENGTH 0 // TODO FIX
#define EMPTY_BUFFER_CONSTANT 0 // TODO FIX

typedef struct {
    fsm_t f;                                    /*!< USART FSM */
    bool data_received;                         /*!< Flag to indicate that a data has been received*/
    char in_data[USART_INPUT_BUFFER_LENGTH];    /*!< Input data*/   //REVISAR
    char out_data[USART_OUTPUT_BUFFER_LENGTH];  /*!< Output data*/  //REVISAR
    uint32_t usart_id;                          /*!< USART ID. Must be unique.*/   
} fsm_usart_t;

/* Function prototypes and explanation -------------------------------------------------*/
/**
 * @brief Check if the USART FSM is active, or not.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 * 
 * @return true or false
 */
bool fsm_usart_check_activity(fsm_t * p_this);

/**
 * @brief Check if data has been received.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 * 
 * @return true or false
 */
bool fsm_usart_check_data_received(fsm_t * p_this);

/**
 * @brief Disable the USART RX interrupt.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 */
void fsm_usart_disable_rx_interrupt(fsm_t * p_this);

/**
 * @brief Disable the USART TX interrupts.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 */
void fsm_usart_disable_tx_interrupt(fsm_t * p_this);

/**
 * @brief Enable the USART RX interrupt.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 */
void fsm_usart_enable_rx_interrupt(fsm_t * p_this);

/**
 * @brief Enable the USART TX interrupts.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 */
void fsm_usart_enable_tx_interrupt(fsm_t * p_this);

/**
 * @brief Get the data from the USART input buffer.
 * @note This function returns the data received by the USART.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 * @param p_data Pointer to the array where the data will be copied from the in_data array
 */
void fsm_usart_get_in_data(fsm_t * p_this, char * p_data);

/**
 * @brief Initialize a USART FSM.
 * @note This function initializes the default values of the FSM struct and calls to the port to initialize the HW of associated to the given ID.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 * @param usart_id Unique USART identifier number
 */
void fsm_usart_init(fsm_t * p_this, uint32_t usart_id);

/**
 * @brief Create a new USART FSM.
 * 
 * @param usart_id Unique USART identifier number
*/
fsm_t* fsm_usart_new(uint32_t usart_id);


/**
 * @brief Reset the input data buffer.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 */
void fsm_usart_reset_input_data(fsm_t * p_this);

/**
 * @brief Set the data to send.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t struct
 * @param p_data Pointer to the array where the data will be copied to the out_data array
 */
void fsm_usart_set_out_data(fsm_t * p_this, char * p_data);

#endif /* FSM_USART_H_ */
