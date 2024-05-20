/**
 * @file fsm_jukebox.h
 * @brief Header for fsm_jukebox.c file.
 * @author Jorge Alejandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 10/04/2024
 */
#ifndef FSM_JUKEBOX_H_
#define FSM_JUKEBOX_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <fsm.h>

/* Other includes */
#include "melodies.h"

/* Defines and enums ----------------------------------------------------------*/
/* Defines */
#define MELODIES_MEMORY_SIZE 11 // Number of melodies in the melodies array

/* Enums */
enum FSM_JUKEBOX
{
    OFF = 0,
    START_UP,
    WAIT_COMMAND,
    SLEEP_WHILE_OFF,
    SLEEP_WHILE_ON
};

/* Typedefs ------------------------------------------------------------------*/
typedef struct
{
    fsm_t f;
    melody_t melodies[MELODIES_MEMORY_SIZE];
    uint8_t melody_idx;
    char *p_melody;
    fsm_t *p_fsm_button;
    fsm_t *p_fsm_button_play_pause;
    fsm_t *p_fsm_button_prev_song;
    uint32_t button_press_time_ms;
    uint32_t button_click_time_ms;
    fsm_t *p_fsm_usart;
    fsm_t *p_fsm_buzzer;
    double speed;
} fsm_jukebox_t;

/* Function prototypes and explanation ---------------------------------------*/

/**
 * @brief Create a new jukebox FSM.
 * @param p_fsm_button	Pointer to the button FSM
 * @param p_fsm_button_play_pause
 * @param p_fsm_button_prev_song
 * @param button_press_time_ms	Button press time in milliseconds to turn the system ON or OFF
 * @param button_click_time_ms	Button press time in milliseconds to change to the next song.
 * @param p_fsm_usart	Pointer to the USART FSM
 * @returns A pointer to the jukebox FSM
 */
void lcd_update_state(fsm_t *p_this);

fsm_t *fsm_jukebox_new(fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, fsm_t *p_fsm_button_prev_song, uint32_t button_press_time_ms, uint32_t button_click_time_ms,
                       fsm_t *p_fsm_usart);

/**
 * @brief Initialize a jukebox FSM.
 * @param p_this	Pointer to the jukebox FSM
 * @param p_fsm_button	Pointer to the button FSM
 * @param button_press_time_ms	Button press time in milliseconds to turn the system ON or OFF
 * @param button_click_time_ms	Button press time in milliseconds to change to the next song.
 * @param p_fsm_usart	Pointer to the USART FSM
 * @param p_fsm_buzzer	Pointer to the buzzer FSM.
 */
void fsm_jukebox_init(fsm_t *p_this, fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, fsm_t *p_fsm_button_prev_song, uint32_t button_press_time_ms, uint32_t button_click_time_ms,
                      fsm_t *p_fsm_usart);
#endif /* FSM_JUKEBOX_H_ */