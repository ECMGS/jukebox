/**
 * @file fsm_buzzer.c
 * @brief Buzzer melody player FSM main file.
 * @author Eugenio Cano Muñoz
 * @author Jorge Alejandro Estefania Hidalgo
 * @date 06/03/2024
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */

/* Other libraries */
#include <stdlib.h>
#include "port_buzzer.h"
#include "fsm_buzzer.h"
#include "melodies.h"

/* State machine input or transition functions */
static bool check_player_start(fsm_t *p_this)	{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    check_melody_start(p_this);
}

static bool check_melody_start(fsm_t *p_this)	{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->p_melody != NULL && p_fsm->user_action == PLAY;
}

static bool check_end_melody (fsm_t *p_this)    {
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->note_index >= p_fsm->p_melody->melody_length;
}

static bool check_pause	(fsm_t *p_this) {
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == PAUSE;
}	

static bool check_resume(fsm_t *p_this) {
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == PLAY;
}

static bool check_player_stop(fsm_t *p_this) {
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == STOP;
}
static bool check_play_note (fsm_t *p_this) {
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == PLAY && p_fsm->note_index < p_fsm->p_melody->melody_length;
}

static bool check_note_end (fsm_t *p_this) {
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return port_buzzer_get_note_timeout(p_fsm->buzzer_id);
}

/* State machine output or action functions */






/* Public functions */


fsm_t *fsm_buzzer_new(uint32_t buzzer_id)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_buzzer_t));
    fsm_buzzer_init(p_fsm, buzzer_id);
    return p_fsm;
}

void fsm_buzzer_init(fsm_t *p_this, uint32_t buzzer_id)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    fsm_init(p_this, fsm_trans_buzzer);

    /* TO-DO alumnos */
    
}