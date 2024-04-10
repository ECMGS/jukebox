/**
 * @file main.c
 * @brief Main file.
 * @author Sistemas Digitales II
 * @date 2023-10-01
 */


/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */
#include <stdio.h> // printf

/* HW libraries */
#include "port_system.h"

#include "port_button.h"
#include "port_usart.h"
#include "port_buzzer.h"

/* FSM libraries*/
#include "fsm.h"

#include "fsm_button.h"
#include "fsm_usart.h"
#include "fsm_buzzer.h"
#include "fsm_jukebox.h"

/* Defines ------------------------------------------------------------------*/
#define ON_OFF_PRESS_TIME_MS 1000 // 1 [s]
#define NEXT_SONG_BUTTON_TIME_MS 500 // 0.5 [s]

#define FUNC_BUTTON_ID BUTTON_0_ID
#define USART USART_0_ID
#define BUZZER BUZZER_0_ID

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* Init board */
    port_system_init();

    fsm_button_t *function_button = (fsm_button_t *)fsm_button_new(ON_OFF_PRESS_TIME_MS, FUNC_BUTTON_ID);
    fsm_usart_t *usart = (fsm_usart_t *)fsm_usart_new(USART);
    fsm_buzzer_t *buzzer = (fsm_buzzer_t *)fsm_buzzer_new(BUZZER);
    
    fsm_t *jukebox = fsm_jukebox_new((fsm_t *) function_button, ON_OFF_PRESS_TIME_MS, (fsm_t *) usart, (fsm_t *) buzzer, NEXT_SONG_BUTTON_TIME_MS;

    /* Infinite loop */
    while (1)
    {
        fsm_fire(jukebox);
    } // End of while(1)

    fsm_destroy(jukebox);

    fsm_destroy((fsm_t *) function_button);
    fsm_destroy((fsm_t *) usart);
    fsm_destroy((fsm_t *) buzzer);
    
    return 0;
}
