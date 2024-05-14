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

#include "buzzer_director.h"

#include "main.h"

/* Defines ------------------------------------------------------------------*/
#define ON_OFF_PRESS_TIME_MS 500 // 1 [s]
#define NEXT_SONG_BUTTON_TIME_MS 50

#define PLAY_PAUSE_BUTTON_TIME_MS 50
#define CHANGE_VOLUME_BUTTON_TIME_MS 500
// #define FUNC_BUTTON_0_ID BUTTON_0_ID
// #define FUNC_BUTTON_1_ID BUTTON_1_ID
#define USART USART_0_ID
#define BUZZER BUZZER_0_ID
#define BUZZER_2 BUZZER_1_ID

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* Init board */

    HAL_Init();
    port_system_init();

    fsm_t *p_fsm_button_t = fsm_button_new(BUTTON_0_DEBOUNCE_TIME_MS, BUTTON_0_ID);
    fsm_t *p_fsm_button_play_pause_t = fsm_button_new(BUTTON_1_DEBOUNCE_TIME_MS, BUTTON_1_ID);
    fsm_t *p_fsm_usart_t = fsm_usart_new(USART);
    // fsm_t *p_fsm_buzzer_t = fsm_buzzer_new(BUZZER_0_ID);
    //  fsm_t *p_fsm_buzzer_2_t = fsm_buzzer_new(BUZZER_2);

    fsm_t *jukebox = fsm_jukebox_new(p_fsm_button_t, p_fsm_button_play_pause_t, ON_OFF_PRESS_TIME_MS, PLAY_PAUSE_BUTTON_TIME_MS,
                                     CHANGE_VOLUME_BUTTON_TIME_MS, p_fsm_usart_t, /*p_fsm_buzzer_t,*/ NEXT_SONG_BUTTON_TIME_MS);

    /* Infinite loop */
    while (1)
    {
        fsm_fire(p_fsm_button_t);
        fsm_fire(p_fsm_button_play_pause_t);
        fsm_fire(p_fsm_usart_t);
        // fsm_fire(p_fsm_buzzer_t);
        buzzer_director_fire();
        fsm_fire(jukebox);
    } // End of while(1)

    fsm_destroy(jukebox);

    fsm_destroy((fsm_t *)p_fsm_button_t);
    fsm_destroy((fsm_t *)p_fsm_button_play_pause_t);
    fsm_destroy((fsm_t *)p_fsm_usart_t);
    // fsm_destroy((fsm_t *) p_fsm_buzzer_t);

    return 0;
}
