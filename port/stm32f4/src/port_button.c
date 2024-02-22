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
port_button_hw_t buttons_arr[] = {
    [BUTTON_0_ID] = {.p_port = BUTTON_0_GPIO, .pin = BUTTON_0_PIN, .flag_pressed = false},
};

/**
 * @brief Configure the HW specifications of a given button.
 * 
 * @param button_id	Button ID. This index is used to select the element of the buttons_arr[] array
*/
void port_button_init(uint32_t button_id)
{
    //GPIO_TypeDef *p_port = buttons_arr[button_id].p_port;
    //uint8_t pin = buttons_arr[button_id].pin;

    port_system_gpio_config(
        buttons_arr[button_id].p_port,
        buttons_arr[button_id].pin,
        GPIO_MODE_IN,
        GPIO_PUPDR_NOPULL
    );

    port_system_gpio_config_exti(
        buttons_arr[button_id].p_port,
        buttons_arr[button_id].pin,
        TRIGGER_BOTH_EDGE | TRIGGER_ENABLE_INTERR_REQ
    );

    port_system_gpio_exti_enable(buttons_arr[button_id].pin, 1, 0);
}


/**
 * @brief Return the status of the button (pressed or not)
 * 
 * @param button_id	Button ID. This index is used to select the element of the buttons_arr[] array
 * @return true If the button has been pressed, false If the button has not been pressed
*/
bool port_button_is_pressed (uint32_t button_id) {
    return buttons_arr[button_id].flag_pressed;
}

/**
 * @brief Return the count of the System tick in milliseconds.
 * 
 * @return uint32_t
*/
uint32_t port_button_get_tick (){
    return port_system_get_millis();
}