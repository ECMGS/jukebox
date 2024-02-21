/**
 * @file port_button.h
 * @brief Header for port_button.c file.
 * @author alumno1
 * @author alumno2
 * @date fecha
 */

#ifndef PORT_BUTTON_H_
#define PORT_BUTTON_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <stdbool.h>

/* HW dependent includes */


/* Defines and enums ----------------------------------------------------------*/
/* Defines */


/* Typedefs --------------------------------------------------------------------*/
typedef struct
{
    GPIO_TypeDef *p_port;
    uint8_t pin;
    bool flag_pressed;
} port_button_hw_t;

/* Global variables */


/* Function prototypes and explanation -------------------------------------------------*/
fsm_t *fsm_button_new(uint32_t debounce_time, uint32_t button_id);
void fsm_button_init(fsm_t *p_this, uint32_t debounce_time, uint32_t button_id);

#endif
