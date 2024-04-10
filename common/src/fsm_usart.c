/**
 * @file fsm_usart.c
 * @brief USART FSM main file.
 * @author Jorge Alejandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 27/02/2024
 */

/* Includes ------------------------------------------------------------------*/
#include "port_usart.h"
#include "fsm_usart.h"
/* Standard C libraries */
#include <string.h>
#include <stdlib.h>
/* Other libraries */

/* State machine input or transition functions */

bool fsm_usart_check_activity (fsm_t *p_this){
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);

    return p_fsm->f.current_state == SEND_DATA ||  p_fsm->data_received;
}

/**
 * @brief Check if data have been received.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t.
 * @returns true or false
*/
static bool check_data_rx(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    return port_usart_rx_done(p_fsm->usart_id);
}

/**
 * @brief Check if there are data to be sent.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t.
 * @returns true or false
*/
static bool check_data_tx(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    return p_fsm->out_data[0] != EMPTY_BUFFER_CONSTANT;
}

/**
 * @brief Check if the data have been sent.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t.
 * @returns true or false
*/
static bool check_tx_end(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    return port_usart_tx_done(p_fsm->usart_id);
}

/* State machine output or action functions */
/**
 * @brief Get the data received.
 * @note This function gets the data received by the USART that still remains in the internal buffer of the PORT layer.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t.
*/
static void do_get_data_rx(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    port_usart_get_from_input_buffer(p_fsm->usart_id, p_fsm->in_data);
    port_usart_reset_input_buffer(p_fsm->usart_id);
    p_fsm->data_received = true;
}

/**
 * @brief Set the data to be sent.
 * @note This function sets the data to be sent by the USART to the internal buffer of the PORT layer.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t.
*/
static void do_set_data_tx(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    
    port_usart_reset_output_buffer(p_fsm->usart_id); //REVISAR
    port_usart_copy_to_output_buffer(p_fsm->usart_id, p_fsm->out_data, USART_OUTPUT_BUFFER_LENGTH);
    while (!port_usart_get_txr_status(p_fsm->usart_id)) {/*Wait until the TX register is empty*/}
    port_usart_write_data(p_fsm->usart_id);
    port_usart_enable_tx_interrupt(p_fsm->usart_id);
}

/**
 * @brief Finish the data transmission.
 * @note This function finishes the data transmission by resetting the output data in the PORT layer.
 * 
 * @param p_this Pointer to an fsm_t struct than contains an fsm_usart_t.
*/
static void do_tx_end(fsm_t * p_this) {
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);

    port_usart_reset_output_buffer(p_fsm->usart_id);

    memset(p_fsm->out_data, EMPTY_BUFFER_CONSTANT, USART_OUTPUT_BUFFER_LENGTH);
}

/** @brief State machine transitions */
static fsm_trans_t fsm_trans_usart[] = {
    {WAIT_DATA, check_data_tx, SEND_DATA, do_set_data_tx},  /*!< Initial state. Also comes here when data has been send or read*/
    {WAIT_DATA, check_data_rx, WAIT_DATA, do_get_data_rx},  /*!< Initial state. Also comes here when data has been send or read*/
    {SEND_DATA, check_tx_end, WAIT_DATA, do_tx_end},        /*!< Send data state*/
    {-1, NULL, -1, NULL}
};

/* Public functions */

void fsm_usart_get_in_data(fsm_t *p_this, char *p_data)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    memcpy(p_data, p_fsm->in_data, USART_INPUT_BUFFER_LENGTH);
}

void fsm_usart_set_out_data(fsm_t *p_this, char *p_data)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    // Ensure to reset the output data before setting a new one
    memset(p_fsm->out_data, EMPTY_BUFFER_CONSTANT, USART_OUTPUT_BUFFER_LENGTH);
    memcpy(p_fsm->out_data, p_data, USART_OUTPUT_BUFFER_LENGTH);
}


fsm_t *fsm_usart_new(uint32_t usart_id)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_usart_t)); /* Do malloc to reserve memory of all other FSM elements, although it is interpreted as fsm_t (the first element of the structure) */
    fsm_usart_init(p_fsm, usart_id);
    return p_fsm;
}

void fsm_usart_init(fsm_t *p_this, uint32_t usart_id)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    
    //fsm_init(p_fsm, fsm_trans_usart);
    fsm_init(p_this, fsm_trans_usart); //REVISAR
    p_fsm->usart_id = usart_id;
    p_fsm->data_received = false;
    memset(p_fsm->in_data, EMPTY_BUFFER_CONSTANT, USART_INPUT_BUFFER_LENGTH);
    memset(p_fsm->out_data, EMPTY_BUFFER_CONSTANT, USART_OUTPUT_BUFFER_LENGTH);
    port_usart_init(p_fsm->usart_id);
}


 bool fsm_usart_check_data_received(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    return p_fsm->data_received;
}

void fsm_usart_reset_input_data(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    memset(p_fsm->in_data, EMPTY_BUFFER_CONSTANT, USART_INPUT_BUFFER_LENGTH);
    p_fsm->data_received = false;
}



void fsm_usart_disable_rx_interrupt(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    port_usart_disable_rx_interrupt(p_fsm->usart_id);
}


void fsm_usart_disable_tx_interrupt(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    port_usart_disable_tx_interrupt(p_fsm->usart_id);
}


void fsm_usart_enable_rx_interrupt(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    port_usart_enable_rx_interrupt(p_fsm->usart_id);
}


void fsm_usart_enable_tx_interrupt(fsm_t *p_this)
{
    fsm_usart_t *p_fsm = (fsm_usart_t *)(p_this);
    port_usart_enable_tx_interrupt(p_fsm->usart_id);
}

