/**
 * @file test_v2.c
 * @brief Integration test for the USART FSM and HW setup.
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */
#include <stdio.h>

/* HW dependent libraries */
#include "port_system.h"
#include "port_button.h"
#include "port_usart.h"

/* Other libraries */
#include "fsm_button.h"
#include "fsm_usart.h"

/* Private defines ------------------------------------------------------------*/
#define TEST_BUTTON_TIME 1000
#define TEST_USART_BAUDRATE 9600
#define LD2_PORT GPIOA
#define LD2_PIN 5
#define LD2_DELAY_MS 100

/**
 * @brief Main test function. Read the terminal for instructions.
 *
 * @return int
 */
int main(void)
{
    // Initialize the system
    port_system_init();

    // Configure the LD2 pin as output
    port_system_gpio_config(LD2_PORT, LD2_PIN, GPIO_MODE_OUT, GPIO_PUPDR_NOPULL);

    // Create a button FSM and a USART FSM
    fsm_t *p_fsm_button = fsm_button_new(BUTTON_0_DEBOUNCE_TIME_MS, BUTTON_0_ID);
    fsm_t *p_fsm_usart = fsm_usart_new(USART_0_ID);

    fsm_usart_enable_rx_interrupt(p_fsm_usart);

    printf("1. Ensure that the USART TX and RX pins are connected to the RX and TX pins of the converter\n");
    printf("2. Ensure that the converter is connected to the PC.\n");
    printf("3. Open a serial terminal and configure it to %d bauds, 8N1.\n", TEST_USART_BAUDRATE);
    printf("3.1. Select in the `Line ending` menu the `LF` option to add a line feed character when you press enter.\n");
    printf("3.2. Start monitoring the serial port.\n");
    printf("4. To send a message from the microcontroller to the PC push the button for more than %d ms.\n", TEST_BUTTON_TIME);
    printf("5. The LD2 LED will blink when a message is sent.\n");
    printf("6. To send a message from the PC to the microcontroller, type a message in the serial terminal and press enter.\tThe message will be printed back in the terminal\n");
    printf("7. The LD2 LED will blink when a message is received.\n");

    while (1)
    {
        fsm_fire(p_fsm_button);

        uint32_t duration = fsm_button_get_duration(p_fsm_button);

        if (duration)
        {
            if (duration >= TEST_BUTTON_TIME)
            {
                fsm_usart_set_out_data(p_fsm_usart, "Hello I'm the microcontroller!\n");
                port_system_gpio_write(LD2_PORT, LD2_PIN, HIGH);
                port_system_delay_ms(LD2_DELAY_MS);
                port_system_gpio_write(LD2_PORT, LD2_PIN, LOW);
            }
            fsm_button_reset_duration(p_fsm_button);
        }

        if (fsm_usart_check_data_received(p_fsm_usart))
        {
            char message[USART_INPUT_BUFFER_LENGTH];
            fsm_usart_get_in_data(p_fsm_usart, message);
            printf("The PC said: %s\n", message);
            fsm_usart_reset_input_data(p_fsm_usart);
            port_system_gpio_write(LD2_PORT, LD2_PIN, HIGH);
            port_system_delay_ms(LD2_DELAY_MS);
            port_system_gpio_write(LD2_PORT, LD2_PIN, LOW);
        }

        fsm_fire(p_fsm_usart);
    }

    // We should never reach this point
    fsm_destroy(p_fsm_button);
    fsm_destroy(p_fsm_usart);
    return 0;
}
