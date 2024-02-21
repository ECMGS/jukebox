/**
 * @file port_button.c
 * @brief File containing functions related to the HW of the button.
 *
 * This file defines an internal struct which contains the HW information of the button.
 *
 * @author alumno1
 * @author alumno2
 * @date fecha
 */

/* Includes ------------------------------------------------------------------*/
#include "port_button.h"

/* Global variables ------------------------------------------------------------*/

void port_button_init(uint32_t button_id)
{
    GPIO_TypeDef *p_port = buttons_arr[button_id].p_port;
    uint8_t pin = buttons_arr[button_id].pin;

    /* TO-DO alumnos */
}
