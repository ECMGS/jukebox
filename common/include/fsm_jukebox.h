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
#define MELODIES_MEMORY_SIZE

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

/* Function prototypes and explanation ---------------------------------------*/
fsm_t * fsm_jukebox_new(fsm_t *p_fsm_button, uint32_t on_off_press_time_ms, 
                        fsm_t *p_fsm_usart, fsm_t *p_fsm_buzzer, uint32_t next_song_press_time_ms);

void fsm_jukebox_init(  fsm_t *p_this, fsm_t *p_fsm_button, uint32_t on_off_press_time_ms, 
                        fsm_t *p_fsm_usart, fsm_t *p_fsm_buzzer, uint32_t next_song_press_time_ms);
#endif /* FSM_JUKEBOX_H_ */