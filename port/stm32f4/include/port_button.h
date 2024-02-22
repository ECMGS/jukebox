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
#define BUTTON_0_DEBOUNCE_TIME_MS 32            /// PUEDE DAR PROBLEMAS PERO ALOBAJINI

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
/**
 * @brief Initializes the button.
 *
 * @param button_id id of the button
*/
void port_button_init (uint32_t button_id);

/**
 * @brief Checks if the button is pressed.
 *
 * @param button_id id of the button
 * @return true if the button is pressed; false otherwise.
*/
bool port_button_is_pressed (uint32_t button_id);

/**
 * @brief Gets the current system tick.
 *
 * @return current system tick.
 * 
*/
uint32_t port_button_get_tick();
#endif
