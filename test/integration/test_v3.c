/**
 * @file test_v3.c
 * @brief Integration test for the BUZZER FSM and HW setup.
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */
#include <stdio.h>

/* HW dependent libraries */
#include "port_system.h"
#include "port_button.h"
#include "port_buzzer.h"

/* Other libraries */
#include "fsm_button.h"
#include "fsm_buzzer.h"

/* Private defines ------------------------------------------------------------*/
#define TEST_BUTTON_PLAY_TIME 1000
#define TEST_BUTTON_PAUSE_TIME 300
#define TEST_BUTTON_STOP_TIME 3000
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

    // Create a button FSM and a BUZZER FSM
    fsm_t *p_fsm_button = fsm_button_new(BUTTON_0_DEBOUNCE_TIME_MS, BUTTON_0_ID);
    fsm_t *p_fsm_buzzer = fsm_buzzer_new(BUZZER_0_ID);

    printf("1. Ensure that the BUZZER is connected correctly to the board.\n");
    printf("2. Keep the terminal open to monitor the state of the melody BUZZER.\n");
    printf("3. To control the BUZZER, press the button for different durations:\n");
    printf("3.1. Press the the button between %d-%d ms to PLAY the melody. If the melody was paused, it will resume. If the melody was stopped, the next melody will start.\n", TEST_BUTTON_PLAY_TIME, TEST_BUTTON_STOP_TIME);
    printf("3.2. Press the the button between %d-%d ms to PAUSE the next melody.\n", TEST_BUTTON_PAUSE_TIME, TEST_BUTTON_PLAY_TIME);
    printf("3.3. Press the the button for more than %d ms to STOP the melody.\n", TEST_BUTTON_STOP_TIME);
    printf("4. The LD2 LED will blink when a button press is detected.\n");
    printf("5. There are two melodies to play: 'Scale' and 'Tetris'. They will alternate each time the button is pressed.\n");
    printf("6. Press the button to play the first melody.\n");
    printf("7. Ensure that the BUZZER is playing the melody and its name is shown in the terminal. If not, check the connections and the code. Connect the pin to an oscilloscope to check the signal.\n");

    while (1)
    {
        fsm_fire(p_fsm_button);

        uint32_t duration = fsm_button_get_duration(p_fsm_button);

        if (duration)
        {
            // Blink the LD2 LED
            port_system_gpio_write(LD2_PORT, LD2_PIN, HIGH);
            port_system_delay_ms(LD2_DELAY_MS);
            port_system_gpio_write(LD2_PORT, LD2_PIN, LOW);

            if ((duration >= TEST_BUTTON_PAUSE_TIME) && (duration < TEST_BUTTON_PLAY_TIME))
            {
                fsm_buzzer_set_action(p_fsm_buzzer, PAUSE);
                printf("Duration: %ld ms. User action: PAUSE\n", duration);
            }
            else if (duration >= TEST_BUTTON_PLAY_TIME && duration < TEST_BUTTON_STOP_TIME)
            {
                static uint32_t counter = 0;

                // Get previous action
                uint16_t previous_action = fsm_buzzer_get_action(p_fsm_buzzer);

                if (previous_action == PAUSE)
                {
                    fsm_buzzer_set_action(p_fsm_buzzer, PLAY);
                    printf("Duration: %ld ms. User action: PLAY resuming from PAUSE\n", duration);
                }
                else if (previous_action == STOP)
                {
                    fsm_buzzer_set_action(p_fsm_buzzer, PLAY);
                    printf("Duration: %ld ms. User action: PLAY next song\n", duration);

                    if (counter % 2 == 0)
                    {
                        fsm_buzzer_set_melody(p_fsm_buzzer, &scale_melody);
                    }
                    else
                    {
                        fsm_buzzer_set_melody(p_fsm_buzzer, &tetris_melody);
                    }
                    printf("Playing: %s\n", (((fsm_buzzer_t *)(p_fsm_buzzer))->p_melody)->p_name);
                    counter++;
                }
            }
            else if (duration >= TEST_BUTTON_STOP_TIME)
            {
                fsm_buzzer_set_action(p_fsm_buzzer, STOP);
                printf("Duration: %ld ms. User action: STOP\n", duration);
            }
            fsm_button_reset_duration(p_fsm_button);
        }

        fsm_fire(p_fsm_buzzer);
    }

    // We should never reach this point
    fsm_destroy(p_fsm_button);
    fsm_destroy(p_fsm_buzzer);
    return 0;
}
