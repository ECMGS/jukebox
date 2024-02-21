/**
 * @file fsm_button.h
 * @brief Header for fsm_button.c file.
 * @author Eugenio Cano
 * @author Jorge Estefanía
 * @date 21/02/2024
 */

#ifndef FSM_BUTTON_H_
#define FSM_BUTTON_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <stdbool.h>

/* Other includes */
#include "fsm.h"

/* Defines and enums ----------------------------------------------------------*/
/* Enums */

/**
 * @brief States for the finite state machine for the button
 * 
*/
enum FSM_BUTTON {
    BUTTON_RELEASED,        /*!< Starting state, button hasn't been pressed*/
    BUTTON_PRESSED_WAIT,    /*!< Button has been pressed, wait some time to remove false positives from mechanical noise*/
    BUTTON_PRESSED,         /*!< Button is currently pressed*/
    BUTTON_RELEASED_WAIT    /*!< Button has been released, wait some time to filter false positives from mechanical noise*/
};

/* Typedefs --------------------------------------------------------------------*/

/**
 * @brief FSM structure for the button
*/
typedef struct {
    fsm_t f;                /*!< Internal FSM*/
    uint32_t debounce_time; /*!< Button debounce time in ms*/
    uint32_t next_timeout;  /*!< Next timeout for debounce in ms*/
    uint32_t tick_preset;   /*!< Number of sys ticks when the button was pressed*/
    uint32_t duration;      /*!< How much time the button has been pressed*/
    uint32_t button_id;     /*!< Id of the button*/
} fsm_button_t;

 

/* Function prototypes and explanation -------------------------------------------------*/
fsm_t *fsm_button_new(uint32_t debounce_time, uint32_t button_id);
void fsm_button_init(fsm_t *p_this, uint32_t debounce_time, uint32_t button_id);


#endif
