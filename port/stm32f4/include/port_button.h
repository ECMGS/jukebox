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
#include <stdlib.h>

/* HW dependent includes */
#include "port_system.h"

/* Defines and enums ----------------------------------------------------------*/
/* Defines */
#define BUTTON_0_ID 0
#define BUTTON_0_GPIO GPIOC
#define BUTTON_0_PIN 13
#define BUTTON_0_DEBOUNCE_TIME_MS 33            /// PUEDE DAR PROBLEMAS PERO ALOBAJINI

/* Typedefs --------------------------------------------------------------------*/
typedef struct
{
    GPIO_TypeDef *p_port;
    uint8_t pin;
    bool flag_pressed;
} port_button_hw_t;

/* Global variables */
extern port_button_hw_t buttons_arr[];

/* Function prototypes and explanation -------------------------------------------------*/

#endif
