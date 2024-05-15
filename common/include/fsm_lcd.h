/**
 * @file lcd_controller.h
 * @brief Header for lcd_controller.c file.
 * @author Jorge Lajeandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 08/05/2024
 */
#ifndef FSM_LCD_H_
#define FSM_LCD_H_
/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <fsm.h>
#include <stdlib.h>
/* Other includes */
#include "melodies.h"

/* Enums */
enum FSM_LCD
{
    OFF_LCD = 0,
    START_DISPLAY,
    SONG_DISPLAY,
    VOLUME_DISPLAY,
    OFF_DISPLAY
};

/* Typedefs ------------------------------------------------------------------*/
typedef struct
{
    fsm_t f;
    melody_t melodies[MELODIES_MEMORY_SIZE];
    uint8_t melody_idx;
    fsm_t *p_fsm_button;
    fsm_t *p_fsm_button_play_pause;
    uint32_t on_off_press_time_ms;
    fsm_t *p_fsm_buzzer;
    uint32_t next_song_press_time_ms;
    uint32_t play_pause_press_time_ms;
    uint32_t change_volume_press_time_ms;
    uint32_t lcd_timeout_ms;
    uint32_t lcd_timeout;
} fsm_lcd_t;

/* Function prototypes and explanation ---------------------------------------*/

/**
 * @brief Create a new lcd FSM.
 * @param p_fsm_button	Pointer to the button FSM
 * @param on_off_press_time_ms	Button press time in milliseconds to turn the system ON or OFF
 * @param p_fsm_buzzer	Pointer to the buzzer FSM.
 * @param next_song_press_time_ms	Button press time in milliseconds to change to the next song.
 * @param play_pause_press_time_ms  Button press time in milliseconds to play or pause the song.
 * @param change_volume_press_time_ms Button press time in milliseconds to change the volume.
 * @param lcd_timeout Time between transitions
 * @returns A pointer to the lcd FSM

 */
fsm_t *fsm_lcd_new(fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, uint32_t on_off_press_time_ms,
                   uint32_t play_pause_press_time_ms, uint32_t change_volume_press_time_ms,
                   uint32_t next_song_press_time_ms, uint32_t lcd_timeout);

/**
 * @brief Initialize a new lcd FSM.
 * @param p_this	Pointer to the lcd FSM
 * @param p_fsm_button	Pointer to the button FSM
 * @param on_off_press_time_ms	Button press time in milliseconds to turn the system ON or OFF
 * @param p_fsm_buzzer	Pointer to the buzzer FSM.
 * @param next_song_press_time_ms	Button press time in milliseconds to change to the next song.
 * @param play_pause_press_time_ms  Button press time in milliseconds to play or pause the song.
 * @param change_volume_press_time_ms Button press time in milliseconds to change the volume.
 * @param lcd_timeout Time between transitions

 */
void fsm_lcd_init(fsm_t *p_this, fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, uint32_t on_off_press_time_ms,
                  uint32_t play_pause_press_time_ms, uint32_t change_volume_press_time_ms,
                  uint32_t next_song_press_time_ms, uint32_t lcd_timeout);

#endif /* LCD_CONTROLLER_H_ */