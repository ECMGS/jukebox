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
// #include "fsm_lcd.h"

#include "main.h"

/* Defines ------------------------------------------------------------------*/
#define BUTTON_PRESS_TIME_MS 500 // 1 [s]
#define BUTTON_CLICK_TIME_MS 50

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

    port_system_init();

    fsm_t *p_fsm_button = fsm_button_new(BUTTON_0_DEBOUNCE_TIME_MS, BUTTON_0_ID);
    fsm_t *p_fsm_button_play_pause = fsm_button_new(BUTTON_1_DEBOUNCE_TIME_MS, BUTTON_1_ID);
    fsm_t *p_fsm_button_prev_song = fsm_button_new(BUTTON_2_DEBOUNCE_TIME_MS, BUTTON_2_ID);
    fsm_t *p_fsm_usart = fsm_usart_new(USART);
    // fsm_t *p_fsm_buzzer_t = fsm_buzzer_new(BUZZER_0_ID);
    // fsm_t *p_fsm_buzzer_2_t = fsm_buzzer_new(BUZZER_2);
    // fsm_t *lcd = fsm_lcd_new(p_fsm_button_t, p_fsm_button_play_pause_t, ON_OFF_PRESS_TIME_MS, PLAY_PAUSE_BUTTON_TIME_MS, CHANGE_VOLUME_BUTTON_TIME_MS, NEXT_SONG_BUTTON_TIME_MS, LCD_TIMEOUT_MS);
    fsm_t *jukebox = fsm_jukebox_new(p_fsm_button, p_fsm_button_play_pause, p_fsm_button_prev_song, BUTTON_PRESS_TIME_MS, BUTTON_CLICK_TIME_MS,
                                     p_fsm_usart);
    /* Infinite loop */
    while (1)
    {
        fsm_fire(p_fsm_button);
        fsm_fire(p_fsm_button_play_pause);
        fsm_fire(p_fsm_button_prev_song);
        fsm_fire(p_fsm_usart);
        // fsm_fire(lcd);
        // fsm_fire(p_fsm_buzzer_t);
        buzzer_director_fire();
        fsm_fire(jukebox);
    } // End of while(1)

    fsm_destroy((fsm_t *)p_fsm_button);
    fsm_destroy((fsm_t *)p_fsm_button_play_pause);
    fsm_destroy((fsm_t *)p_fsm_button_prev_song);
    fsm_destroy((fsm_t *)p_fsm_usart);
    // fsm_destroy(lcd);
    // fsm_destroy((fsm_t *) p_fsm_buzzer_t);

    return 0;
}
