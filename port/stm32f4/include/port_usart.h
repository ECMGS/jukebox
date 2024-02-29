/**
 * @file port_usart.h
 * @brief Header for port_usart.c file.
 * @author Jorge Alejandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 28/02/2024
 */
#ifndef PORT_USART_H_
#define PORT_USART_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/* HW dependent includes */

/* Inclusion of stm32 libraries*/
#include "stm32f4xx.h"


/* Defines and enums ----------------------------------------------------------*/
/* Defines */

/**
 * @brief Definitions for USART 0
*/
#define USART_0_ID 0
#define USART_0 USART3
#define USART_0_GPIO_TX GPIOB
#define USART_0_GPIO_RX GPIOC
#define USART_0_PIN_TX 10
#define USART_0_PIN_RX 11
#define USART_0_AF_TX 7
#define USART_0_AF_RX 7

/**
 * @brief Parammeters for usart transmission
*/

#define USART_INPUT_BUFFER_LENGTH 10
#define USART_OUTPUT_BUFFER_LENGTH 100
#define USART_BUFFER_CONSTANT 0x0           /** Null char in the usart buffer ('\0')*/
#define END_CHAR_CONSTANT 0xA               /** Termination char for the usart transmission ('\n')*/

/* Typedefs --------------------------------------------------------------------*/
typedef struct {
    USART_TypeDef *p_usart;                         /*!< Pointer to the USART defined in USART 0*/
    GPIO_TypeDef *p_port_tx;                        /*!< Pointer to the GPIO port for transmision*/
    GPIO_TypeDef *p_port_rx;                        /*!< Pointer to the GPIO port for reception*/
    uint8_t pin_tx;                                 /*!< Pin for transmision*/
    uint8_t pin_rx;                                 /*!< Pin for reception*/
    uint8_t alt_func_tx;                            /*!< Alternate function for transmision*/
    uint8_t alt_func_rx;                            /*!< Alternate function for reception*/
    char input_buffer[USART_INPUT_BUFFER_LENGTH];   /*!< Buffer for the input data*/
    uint8_t i_idx;                                  /*!< Index for the input buffer*/
    bool read_complete;                             /*!< Flag for the read completion*/
    char output_buffer[USART_OUTPUT_BUFFER_LENGTH]; /*!< Buffer for the output data*/
    uint8_t o_idx;                                  /*!< Index for the output buffer*/
    bool write_complete;                            /*!< Flag for the write completion*/
} port_usart_hw_t;

/* Global variables */
extern port_usart_hw_t port_usart_hw[];

/* Function prototypes and explanation -------------------------------------------------*/
/**
 * @brief Configure the HW specifications of a given USART.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array.
*/
void port_usart_init (uint32_t usart_id);

/**
 * @brief Check if the reception is complete.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
 * @returns True or False
*/
bool port_usart_rx_done (uint32_t usart_id);

/**
 * @brief Check if a transmission is complete.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
 * @returns True or False
*/
bool port_usart_tx_done (uint32_t usart_id);

/**
 * @brief Get the message received through the USART and store it in the buffer passed as argument. This function is called from the function do_get_data_rx() of the FSM to store the message received to the buffer of the FSM.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
 * @param p_buffer	Pointer to the buffer where the message will be stored
 * 
*/
void port_usart_get_from_input_buffer (uint32_t usart_id, char *p_buffer);

/**
 * @brief Check if the USART is ready to receive a new message.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
 * @return True or False
*/
bool port_usart_get_txr_status (uint32_t usart_id);

/**
 * @brief Copy the message passed as argument to the output buffer of the USART. This function is called from the function do_set_data_tx() of the FSM to set the message to send to the USART.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
 * @param p_data	Pointer to the message to be sent
 * @param length	Length of the message to be sent
*/
void port_usart_copy_to_output_buffer (uint32_t usart_id, char *p_data, uint32_t length);

/**
 * @brief Reset the input buffer of the USART. This function is called from the function do_get_data_rx() to reset the input buffer of the USART after the message has been read.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
 * 
*/
void port_usart_reset_input_buffer (uint32_t usart_id);

/**
 * @brief Reset the output buffer of the USART. This function is called from the function do_set_data_tx() and do_tx_end() to reset the output buffer of the USART after the message has been sent.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_reset_output_buffer (uint32_t usart_id);

/**
 * @brief Function to read the data from the USART Data Register and store it in the input buffer. This function is called from the ISR USART3_IRQHandler() when the RXNE flag is set.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_store_data (uint32_t usart_id);

/**
 * @brief Function to write the data from the output buffer to the USART Data Register. his function is called from the ISR USART3_IRQHandler() when the TXE flag is set.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_write_data (uint32_t usart_id);

/**
 * @brief Disable USART RX interrupt.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_disable_rx_interrupt (uint32_t usart_id);

/**
 * @brief Enable USART TX interrupts.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_disable_tx_interrupt (uint32_t usart_id);

/**
 * @brief Enable USART RX interrupts.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_enable_rx_interrupt (uint32_t usart_id);

/**
 * @brief Enable USART TX interrupts.
 * @param usart_id	USART ID. This index is used to select the element of the usart_arr[] array
*/
void port_usart_enable_tx_interrupt (uint32_t usart_id);

#endif