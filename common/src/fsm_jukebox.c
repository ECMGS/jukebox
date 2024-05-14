/**
 * @file fsm_jukebox.c
 * @brief Jukebox FSM main file.
 * @author Jorge Alejandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 10/04/2024
 */

/* Includes ------------------------------------------------------------------*/
// Standard C includes
#include <string.h> // strcmp
#include <stdio.h>  // sprintf
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Other includes
#include "fsm.h"
#include "fsm_jukebox.h"
#include "fsm_button.h"
#include "fsm_usart.h"
#include "fsm_buzzer.h"

#include "port_system.h"
#include "port_usart.h"

#include "buzzer_director.h"

/* Defines ------------------------------------------------------------------*/
#define MAX(a, b) ((a) > (b) ? (a) : (b)) /*!< Macro to get the maximum of two values. */

/* Private functions */
/**
 * @brief Parse the message received by the USART.
 *
 * Given data received by the USART, this function parses the message and extracts the command and the parameter (if available).
 *
 * > 1. Split the message by space using function `strtok()` \n
 * > 2. If there's a token (command), copy it to the `p_command` variable. Otherwise, return `false` \n
 * > 3. Extract the parameter (if available). To do so, get the next token using function `strtok()`. If there's a token, copy it to the `p_param` variable. Otherwise, copy an empty string to the `p_param` variable \n
 * > 4. Return `true` indicating that the message has been parsed correctly \n
 *
 * @param p_message Pointer to the message received by the USART.
 * @param p_command Pointer to store the command extracted from the message.
 * @param p_param Pointer to store the parameter extracted from the message.
 * @return true if the message has been parsed correctly
 * @return false if the message has not been parsed correctly
 */
bool _parse_message(char *p_message, char *p_command, char *p_param)
{
    char *p_token = strtok(p_message, " "); // Split the message by space

    // If there's a token (command), copy it to the command variable
    if (p_token != NULL)
    {
        strcpy(p_command, p_token);
    }
    else
    {
        // No command found, you might return an error or handle it as needed
        // The USART driver of the computer sends an empty at initialization, so we will ignore it
        return false;
    }

    // Extract the parameter (if available)
    p_token = strtok(NULL, " "); // Get the next token

    if (p_token != NULL)
    {
        strcpy(p_param, p_token);
    }
    else
    {
        strcpy(p_param, " "); // NO param found
    }
    return true;
}

void _set_next_song(fsm_jukebox_t *p_fsm_jukebox)
{
    // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, STOP);
    buzzer_director_set_action(STOP);
    p_fsm_jukebox->melody_idx = (p_fsm_jukebox->melody_idx + 1) % MELODIES_MEMORY_SIZE;
    if (!(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].melody_length > 0))
        p_fsm_jukebox->melody_idx = 0;
    p_fsm_jukebox->p_melody = p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].p_name;
    printf(": %s", p_fsm_jukebox->p_melody);
    printf("\n");
    // fsm_buzzer_set_melody(p_fsm_jukebox->p_fsm_buzzer, &(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx]));
    // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, PLAY);
    buzzer_director_set_melody(&(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx]));
    buzzer_director_set_action(PLAY);
}

void _execute_command(fsm_jukebox_t *p_fsm_jukebox, char *p_command, char *p_param)
{
    if (!strcmp(p_command, "play"))
    {
        // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, PLAY);
        buzzer_director_set_action(PLAY);
        return;
    }

    if (!strcmp(p_command, "stop"))
    {
        // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, STOP);
        buzzer_director_set_action(STOP);
        return;
    }

    if (!strcmp(p_command, "pause"))
    {
        // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, PAUSE);
        buzzer_director_set_action(PAUSE);
        return;
    }

    if (!strcmp(p_command, "speed"))
    {
        double param = atoi(p_param);
        // fsm_buzzer_set_speed(p_fsm_jukebox->p_fsm_buzzer, param);
        buzzer_director_set_speed(param / 10.0);
        return;
    }

    if (!strcmp(p_command, "next"))
    {
        _set_next_song(p_fsm_jukebox);
        return;
    }

    if (!strcmp(p_command, "select"))
    {
        uint32_t melody_selected = atoi(p_param);

        if (p_fsm_jukebox->melodies[melody_selected].melody_length == 0)
        {
            printf("Melody not found\n");
            return;
        }

        // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, STOP);
        buzzer_director_set_action(STOP);

        p_fsm_jukebox->melody_idx = melody_selected;

        // fsm_buzzer_set_melody(p_fsm_jukebox->p_fsm_buzzer, &(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx]));
        buzzer_director_set_melody(&(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx]));
        p_fsm_jukebox->p_melody = p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].p_name;

        // fsm_buzzer_set_action(p_fsm_jukebox->p_fsm_buzzer, PLAY);
        buzzer_director_set_action(PLAY);
        return;
    }

    if (!strcmp(p_command, "info"))
    {
        char msg[USART_OUTPUT_BUFFER_LENGTH];
        sprintf(msg, "Melody: %s\n", p_fsm_jukebox->p_melody);
        fsm_usart_set_out_data(p_fsm_jukebox->p_fsm_usart, msg);
        return;
    }

    fsm_usart_set_out_data(p_fsm_jukebox->p_fsm_usart, "Command not found\n");
}

/* State machine input or transition functions */

static bool check_on(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button) > p_fsm->on_off_press_time_ms;
}

static bool check_off(fsm_t *p_this)
{
    return check_on(p_this);
}

static bool check_melody_finished(fsm_t *p_this)
{
    // fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    // return fsm_buzzer_get_action(p_fsm->p_fsm_buzzer) == STOP;
    return buzzer_director_check_melody_finished();
}

static bool check_command_received(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_usart_check_data_received(p_fsm->p_fsm_usart);
}

static bool check_next_song_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button) > p_fsm->next_song_press_time_ms;
}

static bool check_activity(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_check_activity(p_fsm->p_fsm_button) ||
           fsm_button_check_activity(p_fsm->p_fsm_button_play_pause) ||
           fsm_usart_check_activity(p_fsm->p_fsm_usart) ||
           buzzer_director_check_activity()
        /*||fsm_buzzer_check_activity(p_fsm->p_fsm_buzzer)*/;
}

static bool check_no_activity(fsm_t *p_this)
{
    return !check_activity(p_this);
}

static bool check_play_pause_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_play_pause) > p_fsm->play_pause_press_time_ms;
}

static bool check_volume_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_play_pause) > p_fsm->change_volume_press_time_ms;
}

/* State machine output or action functions */

static void do_start_up(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button);
    fsm_usart_enable_rx_interrupt(p_fsm->p_fsm_usart);
    printf("Jukebox ON\n");
    // fsm_buzzer_set_speed(p_fsm->p_fsm_buzzer, 1);
    // fsm_buzzer_set_melody(p_fsm->p_fsm_buzzer, &(p_fsm->melodies[0]));
    // fsm_buzzer_set_action(p_fsm->p_fsm_buzzer, PLAY);
    buzzer_director_set_speed(1);
    buzzer_director_set_melody(&(p_fsm->melodies[0]));
    buzzer_director_set_action(PLAY);
}

static void do_start_jukebox(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    p_fsm->melody_idx = 1;
    p_fsm->p_melody = p_fsm->melodies[p_fsm->melody_idx].p_name;
}

static void do_stop_jukebox(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button);
    fsm_usart_disable_tx_interrupt(p_fsm->p_fsm_usart);
    fsm_usart_disable_rx_interrupt(p_fsm->p_fsm_usart);
    printf("Jukebox OFF\n");
    // fsm_buzzer_set_action(p_fsm->p_fsm_buzzer, STOP);
    buzzer_director_set_action(STOP);
}

static void do_load_next_song(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button);
    _set_next_song(p_fsm);
}

static void do_read_command(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    char p_message[USART_INPUT_BUFFER_LENGTH];
    char p_command[USART_INPUT_BUFFER_LENGTH];
    char p_param[USART_INPUT_BUFFER_LENGTH];
    fsm_usart_get_in_data(p_fsm->p_fsm_usart, p_message);
    if (_parse_message(p_message, p_command, p_param))
        _execute_command(p_fsm, p_command, p_param);
    fsm_usart_reset_input_data(p_fsm->p_fsm_usart);
    p_message[0] = '\0';
}

static void do_sleep_off(fsm_t *p_this)
{
    port_system_sleep();
}

static void do_sleep_wait_command(fsm_t *p_this)
{
    port_system_sleep();
}

static void do_sleep_while_off(fsm_t *p_this)
{
    port_system_sleep();
}

static void do_sleep_while_on(fsm_t *p_this)
{
    port_system_sleep();
}

static void do_play_pause(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button_play_pause);
    if (buzzer_director_get_action() == PLAY)
    {
        printf("PAUSE\n");
        // fsm_buzzer_set_action(p_fsm->p_fsm_buzzer, PAUSE);
        buzzer_director_set_action(PAUSE);
    }
    else
    {
        printf("PLAY\n");
        // fsm_buzzer_set_action(p_fsm->p_fsm_buzzer, PLAY);
        buzzer_director_set_action(PLAY);
    }
}

static void do_change_volume(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button_play_pause);
    // double volume = fsm_buzzer_get_volume(p_fsm->p_fsm_buzzer);
    double volume = buzzer_director_get_volume();
    // if (volume == 0.5) {fsm_buzzer_set_volume(p_fsm->p_fsm_buzzer, 0.995);}
    // else {fsm_buzzer_set_volume(p_fsm->p_fsm_buzzer, 0.5);}
    if (volume == 0.5)
    {
        buzzer_director_set_volume(0.995);
    }
    else
    {
        buzzer_director_set_volume(0.5);
    }
}

static fsm_trans_t fsm_trans_jukebox[] = {
    {OFF, check_on, START_UP, do_start_up},
    {OFF, check_no_activity, SLEEP_WHILE_OFF, do_sleep_off},
    {START_UP, check_melody_finished, WAIT_COMMAND, do_start_jukebox},
    {WAIT_COMMAND, check_off, OFF, do_stop_jukebox},
    {WAIT_COMMAND, check_volume_button, WAIT_COMMAND, do_change_volume},
    {WAIT_COMMAND, check_next_song_button, WAIT_COMMAND, do_load_next_song},
    {WAIT_COMMAND, check_command_received, WAIT_COMMAND, do_read_command},
    {WAIT_COMMAND, check_no_activity, SLEEP_WHILE_ON, do_sleep_wait_command},
    {WAIT_COMMAND, check_play_pause_button, WAIT_COMMAND, do_play_pause},
    {SLEEP_WHILE_ON, check_no_activity, SLEEP_WHILE_ON, do_sleep_while_on},
    {SLEEP_WHILE_ON, check_activity, WAIT_COMMAND, NULL},
    {SLEEP_WHILE_OFF, check_no_activity, SLEEP_WHILE_OFF, do_sleep_while_off},
    {SLEEP_WHILE_OFF, check_activity, OFF, NULL},
    {-1, NULL, -1, NULL}};

/* Public functions */
fsm_t *fsm_jukebox_new(fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, uint32_t on_off_press_time_ms, uint32_t play_pause_time_ms, uint32_t change_volume_press_time_ms, fsm_t *p_fsm_usart, /*fsm_t *p_fsm_buzzer,*/ uint32_t next_song_press_time_ms)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_jukebox_t));
    fsm_init(p_fsm, fsm_trans_jukebox);
    fsm_jukebox_init(p_fsm, p_fsm_button, p_fsm_button_play_pause, on_off_press_time_ms, play_pause_time_ms, change_volume_press_time_ms, p_fsm_usart, /*p_fsm_buzzer,*/ next_song_press_time_ms);

    return p_fsm;
}

void fsm_jukebox_init(fsm_t *p_this, fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, uint32_t on_off_press_time_ms, uint32_t play_pause_time_ms, uint32_t change_volume_press_time_ms, fsm_t *p_fsm_usart, /*fsm_t *p_fsm_buzzer,*/ uint32_t next_song_press_time_ms)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_init(p_this, p_this->p_tt);
    p_fsm->p_fsm_button = p_fsm_button;
    p_fsm->p_fsm_button_play_pause = p_fsm_button_play_pause;
    p_fsm->on_off_press_time_ms = on_off_press_time_ms;
    p_fsm->p_fsm_usart = p_fsm_usart;
    // p_fsm->p_fsm_buzzer = p_fsm_buzzer;
    p_fsm->next_song_press_time_ms = next_song_press_time_ms;
    p_fsm->play_pause_press_time_ms = play_pause_time_ms;
    p_fsm->change_volume_press_time_ms = change_volume_press_time_ms;
    p_fsm->melody_idx = 0;
    memset(p_fsm->melodies, 0, sizeof(p_fsm->melodies));

    buzzer_director_init();

    p_fsm->melodies[0] = one_up_melody;
    p_fsm->melodies[1] = nokia;
    p_fsm->melodies[2] = star_wars_trumpet;
    p_fsm->melodies[3] = happy_birthday_melody;
    p_fsm->melodies[4] = kerosene;
    p_fsm->melodies[5] = mario_death;
    p_fsm->melodies[6] = tetris_melody;
    p_fsm->melodies[7] = scale_melody;
}
