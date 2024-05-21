/**
 * @file port_button.h
 * @brief Header for port_button.c file.
 * @author Jorge Alejandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
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
#define BUTTON_0_DEBOUNCE_TIME_MS 50


#define BUTTON_1_ID 1
#define BUTTON_1_GPIO GPIOB
#define BUTTON_1_PIN 12
#define BUTTON_1_DEBOUNCE_TIME_MS 50

#define BUTTON_2_ID 2
#define BUTTON_2_GPIO GPIOB
#define BUTTON_2_PIN 15
#define BUTTON_2_DEBOUNCE_TIME_MS 50

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
void port_button_init(uint32_t button_id);

/**
 * @brief Checks if the button is pressed.
 *
 * @param button_id id of the button
 * @return true if the button is pressed; false otherwise.
 */
bool port_button_is_pressed(uint32_t button_id);

/**
 * @brief Gets the current system tick.
 *
 * @return current system tick.
 *
 */
uint32_t port_button_get_tick();
#endif
