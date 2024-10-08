/**
 * @file fsm_buzzer.c
 * @brief Buzzer melody player FSM main file.
 * @author Eugenio Cano Muñoz
 * @author Jorge Alejandro Estefanía Hidalgo
 * @date 06/03/2024
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */

/* Other libraries */
#include <stdlib.h>
#include "port_buzzer.h"
#include "fsm_buzzer.h"
#include "melodies.h"

#include "fsm_jukebox.h"
// #include "lcd_controller.h" 
/* State machine input or transition functions */

bool fsm_buzzer_check_activity(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);

    return p_fsm->user_action == PLAY || PAUSE;
}

static void _start_note(fsm_t *p_this, double freq, uint32_t duration, double volume)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);

    port_buzzer_set_note_duration(p_fsm->buzzer_id, duration / p_fsm->player_speed);
    port_buzzer_set_note_frequency(p_fsm->buzzer_id, freq, volume);
}

/**
 * @brief Check if the melody has started.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_melody_start(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->p_melody != NULL && p_fsm->user_action == PLAY;
}
/**
 * @brief Check if the melody has ended.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_end_melody(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->note_index >= p_fsm->p_melody->melody_length;
}
/**
 * @brief Check if the player has paused.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_pause(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == PAUSE;
}
/**
 * @brief Check if the player has resumed.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_resume(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == PLAY;
}
/**
 * @brief Check if the player has stopped.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_player_stop(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == STOP;
}
/**
 * @brief Check if the player has to play a note.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_play_note(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action == PLAY && p_fsm->note_index < p_fsm->p_melody->melody_length;
}
/**
 * @brief Check if the note has ended.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_note_end(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return port_buzzer_get_note_timeout(p_fsm->buzzer_id);
}
/**
 * @brief Check if the player has started.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 * @returns true or false
 */
static bool check_player_start(fsm_t *p_this)
{
    return check_melody_start(p_this);
}
/* State machine output or action functions */
/**
 * @brief Start a note.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_melody_start(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    _start_note(p_this, p_fsm->p_melody->p_notes[0], p_fsm->p_melody->p_durations[0], p_fsm->volume);
    p_fsm->note_index = 1; // estamos seguros de que es 1 y no 0?
}
/**
 * @brief Start the player.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_player_start(fsm_t *p_this)
{
    do_melody_start(p_this);
}
/**
 * @brief End the melody.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_end_melody(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    port_buzzer_stop(p_fsm->buzzer_id);
    p_fsm->note_index = 0;
    p_fsm->user_action = STOP;
    // lcd_update_state(p_this);
}
/**
 * @brief Pause the player.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_pause(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    port_buzzer_stop(p_fsm->buzzer_id);
}
/**
 * @brief Stop the player.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_player_stop(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    port_buzzer_stop(p_fsm->buzzer_id);
    p_fsm->note_index = 0;
}
/**
 * @brief Play a note.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_play_note(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    _start_note(p_this, p_fsm->p_melody->p_notes[p_fsm->note_index], p_fsm->p_melody->p_durations[p_fsm->note_index], p_fsm->volume);
    p_fsm->note_index++;
}
/**
 * @brief End a note.
 *
 * @param p_this Pointer to an fsm_t struct than contains an fsm_buzzer_t.
 */
static void do_note_end(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    port_buzzer_stop(p_fsm->buzzer_id);
}

/* State machine transitions */
static fsm_trans_t fsm_trans_buzzer[] = {
    {WAIT_START, check_player_start, WAIT_NOTE, do_player_start},
    {WAIT_NOTE, check_note_end, PLAY_NOTE, do_note_end},
    {PLAY_NOTE, check_player_stop, WAIT_START, do_player_stop},
    {PLAY_NOTE, check_play_note, WAIT_NOTE, do_play_note},
    {PLAY_NOTE, check_end_melody, WAIT_MELODY, do_end_melody},
    {PLAY_NOTE, check_pause, PAUSE_NOTE, do_pause},
    {PAUSE_NOTE, check_resume, PLAY_NOTE, NULL},
    {WAIT_MELODY, check_melody_start, WAIT_NOTE, do_melody_start},
    {-1, NULL, -1, NULL}};

/* Public functions */

void fsm_buzzer_set_melody(fsm_t *p_this, const melody_t *p_melody)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    p_fsm->p_melody = (melody_t *)p_melody;
}

void fsm_buzzer_set_speed(fsm_t *p_this, double speed)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    p_fsm->player_speed = speed;
}

void fsm_buzzer_set_action(fsm_t *p_this, uint8_t action)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    p_fsm->user_action = action;
    if (action == STOP)
        p_fsm->note_index = 0;
}

void fsm_buzzer_set_volume(fsm_t *p_this, double volume)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    p_fsm->volume = volume;
}

double fsm_buzzer_get_volume(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->volume;
}
uint8_t fsm_buzzer_get_action(fsm_t *p_this)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    return p_fsm->user_action;
}

void fsm_buzzer_init(fsm_t *p_this, uint32_t buzzer_id)
{
    fsm_buzzer_t *p_fsm = (fsm_buzzer_t *)(p_this);
    p_fsm->buzzer_id = buzzer_id;
    p_fsm->p_melody = NULL;
    p_fsm->note_index = 0;
    p_fsm->user_action = STOP;
    p_fsm->player_speed = 1.0;
    p_fsm->volume = 0.5;
    port_buzzer_init(p_fsm->buzzer_id);
}

fsm_t *fsm_buzzer_new(uint32_t buzzer_id)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_buzzer_t));
    fsm_init(p_fsm, fsm_trans_buzzer);
    fsm_buzzer_init(p_fsm, buzzer_id);
    return p_fsm;
}

void fsm_buzzer_note_end(fsm_t *p_this)
{
    do_note_end(p_this);
}