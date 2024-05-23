/**
 * @file fsm_jukebox.c
 * @brief Jukebox FSM main file.
 * @author Jorge Alejandro Estefanía Hidalgo
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
#include <math.h>
// Other includes
#include "fsm.h"
#include "fsm_jukebox.h"
#include "fsm_button.h"
#include "fsm_usart.h"
#include "fsm_buzzer.h"

#include "port_system.h"
#include "port_usart.h"

#include "buzzer_director.h"
#include <liquidcrystal_i2c.h>

#define LCD_IN_JUKEBOX
/* Defines ------------------------------------------------------------------*/
#define MAX(a, b) ((a) > (b) ? (a) : (b)) /*!< Macro to get the maximum of two values. */

/* LCD FUNCTIONS */
/**
 * @brief Turn on the LCD.
*/
void lcd_on()
{
    HD44780_Clear();
    HD44780_Backlight();
    HD44780_SetCursor(2, 0);
    HD44780_PrintStr("Jukebox ON");
}
/**
 * @brief Turn off the LCD.
*/
void lcd_off()
{
    HD44780_Clear();
    HD44780_SetCursor(2, 0);
    HD44780_PrintStr("JUKEBOX OFF");
    HAL_Delay(2000);
    HD44780_Clear();
    HD44780_PrintStr("PRESS ON BUTTON");
    HD44780_SetCursor(2, 1);
    HD44780_PrintStr("TO POWER UP");
    HAL_Delay(2000);
    HD44780_Clear();
    HD44780_NoBacklight();
}
/**
 * @brief Update the song name on the LCD.
 * 
 * @param p_this	Pointer to the jukebox FSM
*/
void lcd_update_song(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    HD44780_SetCursor(0, 0);
    HD44780_PrintStr("                ");
    HD44780_SetCursor(0, 0);
    HD44780_PrintStr(p_fsm->melodies[p_fsm->melody_idx].p_name);
}
/**
 * @brief Update the volume on the LCD.
 * 
 * @param p_this	Pointer to the jukebox FSM
*/
void lcd_update_vol(fsm_t *p_this)
{
    HD44780_SetCursor(7, 1);
    HD44780_PrintStr("Vol: ");
    HD44780_SetCursor(12, 1);
    if (buzzer_director_get_volume() <= 0.7)
    {
        HD44780_PrintStr("HIGH");
    }
    else
    {
        HD44780_PrintStr("LOW ");
    }
}
/**
 * @brief Update the state of the player on the LCD.
 * 
 * @param p_this	Pointer to the jukebox FSM
*/
void lcd_update_state(fsm_t *p_this)
{
    HD44780_SetCursor(0, 1);
    if (buzzer_director_get_action() == PLAY)
    {
        HD44780_PrintStr("PLAY ");
    }
    else if (buzzer_director_get_action() == PAUSE)
    {
        HD44780_PrintStr("PAUSE");
    }
    else
    {
        HD44780_PrintStr("STOP ");
    }
}

/**
 * @brief Update sond, state and volume on the LCD.
 * 
 * @param p_this	Pointer to the jukebox FSM
*/
void lcd_update(fsm_t *p_this)
{
    // fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    HD44780_Clear();
    lcd_update_song(p_this);
    lcd_update_state(p_this);
    lcd_update_vol(p_this);
}

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

/**
 * @brief Set the next song to play.
 *
 * @param p_fsm_jukebox Pointer to the jukebox FSM.
*/
void _set_next_song(fsm_jukebox_t *p_fsm_jukebox)
{
    buzzer_director_set_action(STOP);
    p_fsm_jukebox->melody_idx = (p_fsm_jukebox->melody_idx + 1) % MELODIES_MEMORY_SIZE;
    if (!(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].melody_length > 0))
        p_fsm_jukebox->melody_idx = 0;
    p_fsm_jukebox->p_melody = p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].p_name;
    printf(": %s", p_fsm_jukebox->p_melody);
    printf("\n");
    buzzer_director_set_melody(&(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx]));
    buzzer_director_set_action(PLAY);
}
/**
 * @brief Set the previous song to play.
 *
 * @param p_fsm_jukebox Pointer to the jukebox FSM.
*/
void _set_prev_song(fsm_jukebox_t *p_fsm_jukebox)
{
    buzzer_director_set_action(STOP);
    p_fsm_jukebox->melody_idx = (p_fsm_jukebox->melody_idx - 1) < 0 ? MELODIES_MEMORY_SIZE - 1 : (p_fsm_jukebox->melody_idx - 1) % MELODIES_MEMORY_SIZE;
    if (!(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].melody_length > 0))
        p_fsm_jukebox->melody_idx = MELODIES_MEMORY_SIZE - 1;
    p_fsm_jukebox->p_melody = p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx].p_name;
    printf(": %s", p_fsm_jukebox->p_melody);
    printf("\n");
    buzzer_director_set_melody(&(p_fsm_jukebox->melodies[p_fsm_jukebox->melody_idx]));
    buzzer_director_set_action(PLAY);
}
/**
 * @brief Execute the command received by the USART. This function is called by do_read_command() to execute the command received by the USART if it is valid.
 * 
 * @param p_fsm_jukebox	Pointer to the Jukebox FSM.
 * @param p_command	Pointer to the command to be executed.
 * @param p_param	Pointer to the parameter of the command to be executed.

*/
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
        lcd_update_song((fsm_t *)p_fsm_jukebox);
        lcd_update_state((fsm_t *)p_fsm_jukebox);
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

/**
 * @brief Check if the ON-OFF button is pressed.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_on(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button) > p_fsm->button_press_time_ms;
}
/**
 * @brief Check if the ON-OFF button is pressed.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_off(fsm_t *p_this)
{
    return check_on(p_this);
}

/**
 * @brief Check if the melody has finished.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_melody_finished(fsm_t *p_this)
{
    // fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    // return fsm_buzzer_get_action(p_fsm->p_fsm_buzzer) == STOP;
    return buzzer_director_check_melody_finished();
}
/**
 * @brief Check if a command has been received by the USART.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_command_received(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_usart_check_data_received(p_fsm->p_fsm_usart);
}
/**
 * @brief Check if the next song button (which is the same as ON-OFF button) has been clicked.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_next_song_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button) > p_fsm->button_click_time_ms;
}
/**
 * @brief Check if there is activity from the buttons.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_activity(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_check_activity(p_fsm->p_fsm_button) ||
           fsm_button_check_activity(p_fsm->p_fsm_button_play_pause) ||
           fsm_button_check_activity(p_fsm->p_fsm_button_prev_song) ||
           fsm_usart_check_activity(p_fsm->p_fsm_usart) ||
           buzzer_director_check_activity()
        /*||fsm_buzzer_check_activity(p_fsm->p_fsm_buzzer)*/;
}
/**
 * @brief Check if there is no activity from the buttons.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_no_activity(fsm_t *p_this)
{
    return !check_activity(p_this);
}
/**
 * @brief Check if the play-pause button has been clicked.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_play_pause_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_play_pause) > p_fsm->button_click_time_ms;
}
/**
 * @brief Check if the volume button (which is the same as play-pause) has been pressed.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_volume_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_play_pause) > p_fsm->button_press_time_ms;
}
/**
 * @brief Check if the previous song button has been clicked.
 * 
 * @param p_this Pointer to the jukebox FSM.
*/
static bool check_prev_song_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_prev_song) > p_fsm->button_click_time_ms;
}

/* State machine output or action functions */
/**
 * @brief Initialize the Jukebox by playing the intro melody, at the beginning of the program.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_start_up(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button);
    fsm_usart_enable_rx_interrupt(p_fsm->p_fsm_usart);
    printf("Jukebox ON\n");
    buzzer_director_set_speed(1);
    buzzer_director_set_melody(&(p_fsm->melodies[0]));
    buzzer_director_set_action(PLAY);
    lcd_on();
}
/**
 * @brief After playing the intro melody, start the Jukebox.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_start_jukebox(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    p_fsm->melody_idx = 1;
    p_fsm->p_melody = p_fsm->melodies[p_fsm->melody_idx].p_name;
    HD44780_SetCursor(7, 1);
    HD44780_PrintStr("Vol: ");
    HD44780_SetCursor(12, 1);
    lcd_update(p_this);
}
/**
 * @brief Stop the Jukebox.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_stop_jukebox(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button);
    fsm_usart_disable_tx_interrupt(p_fsm->p_fsm_usart);
    fsm_usart_disable_rx_interrupt(p_fsm->p_fsm_usart);
    printf("Jukebox OFF\n");
    // fsm_buzzer_set_action(p_fsm->p_fsm_buzzer, STOP);
    buzzer_director_set_action(STOP);
    lcd_off();
}
/**
 * @brief Load the next song.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_load_next_song(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button);
    _set_next_song(p_fsm);
    lcd_update_song(p_this);
    lcd_update_state(p_this);
    _execute_command(p_fsm, "info", "");
}
/**
 * @brief Read the command received by the USART.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
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
/**
 * @brief Put the system to sleep.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_sleep_off(fsm_t *p_this)
{
    port_system_sleep();
}
/**
 * @brief Put the system to sleep.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_sleep_wait_command(fsm_t *p_this)
{
    port_system_sleep();
}
/**
 * @brief Put the system to sleep.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_sleep_while_off(fsm_t *p_this)
{
    port_system_sleep();
}
/**
 * @brief Put the system to sleep.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_sleep_while_on(fsm_t *p_this)
{
    port_system_sleep();
}
/**
 * @brief Play or pause the melody.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
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
    lcd_update_state(p_this);
}
/**
 * @brief Change the volume of the melody.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_change_volume(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button_play_pause);
    double volume = buzzer_director_get_volume();
    if (volume == 0.5)
    {
        buzzer_director_set_volume(0.995);
        printf("Volume LOW\n");
    }
    else
    {
        buzzer_director_set_volume(0.5);
        printf("Volume HIGH\n");
    }

    lcd_update_vol(p_this);
}
/**
 * @brief Load the previous song.
 * 
 * @param p_this Pointer to an fsm_t struct that contains an fsm_jukebox_t.
*/
static void do_load_prev_song(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_button_reset_duration(p_fsm->p_fsm_button_prev_song);
    _set_prev_song(p_fsm);
    lcd_update_song(p_this);
    lcd_update_state(p_this);
    _execute_command(p_fsm, "info", "");

}
/**
 * @brief Array representing the transitions table of the FSM Jukebox. 
 * 
 * @image html docs/assets/imgs/jukebox_fsm.jpeg
*/
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
    {WAIT_COMMAND, check_prev_song_button, WAIT_COMMAND, do_load_prev_song},
    {WAIT_COMMAND, check_melody_finished, WAIT_COMMAND, lcd_update_state},
    {SLEEP_WHILE_ON, check_no_activity, SLEEP_WHILE_ON, do_sleep_while_on},
    {SLEEP_WHILE_ON, check_activity, WAIT_COMMAND, NULL},
    {SLEEP_WHILE_OFF, check_no_activity, SLEEP_WHILE_OFF, do_sleep_while_off},
    {SLEEP_WHILE_OFF, check_activity, OFF, NULL},
    {-1, NULL, -1, NULL}};

/* Public functions */
fsm_t *fsm_jukebox_new(fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, fsm_t *p_fsm_button_prev_song, uint32_t button_press_time_ms, uint32_t button_click_time_ms,
                       fsm_t *p_fsm_usart)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_jukebox_t));
    fsm_init(p_fsm, fsm_trans_jukebox);
    fsm_jukebox_init(p_fsm, p_fsm_button, p_fsm_button_play_pause, p_fsm_button_prev_song, button_press_time_ms, button_click_time_ms,
                     p_fsm_usart);

    return p_fsm;
}

void fsm_jukebox_init(fsm_t *p_this, fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause,
                      fsm_t *p_fsm_button_prev_song, uint32_t button_press_time_ms, uint32_t button_click_time_ms,
                      fsm_t *p_fsm_usart)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    fsm_init(p_this, p_this->p_tt);
    p_fsm->p_fsm_button = p_fsm_button;
    p_fsm->p_fsm_button_play_pause = p_fsm_button_play_pause;
    p_fsm->p_fsm_button_prev_song = p_fsm_button_prev_song;
    p_fsm->button_press_time_ms = button_press_time_ms;
    p_fsm->button_click_time_ms = button_click_time_ms;
    p_fsm->p_fsm_usart = p_fsm_usart;
    p_fsm->melody_idx = 0;
    memset(p_fsm->melodies, 0, sizeof(p_fsm->melodies));

    buzzer_director_init();
    p_fsm->melodies[0] = one_up_melody;
    p_fsm->melodies[1] = nokia;
    p_fsm->melodies[2] = coconut_mall;
    p_fsm->melodies[3] = star_wars;
    p_fsm->melodies[4] = minecraft;
    p_fsm->melodies[5] = kerosene;
    p_fsm->melodies[6] = tetris_melody;
    p_fsm->melodies[7] = megalovania;
    p_fsm->melodies[8] = zelda_theme_song;
    p_fsm->melodies[9] = mario_death;
    p_fsm->melodies[10] = pokemon;
}
