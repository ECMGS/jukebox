/**
 * @file fsm_buzzer.h
 * @brief Header for fsm_buzzer.c file.
 * @author Eugenio Cano Muñoz
 * @author Jorge Alejandro Estefania
 * @date 06/03/2024
 */

#ifndef FSM_BUZZER_H_
#define FSM_BUZZER_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Other includes */
#include "fsm.h"
#include "melodies.h"

/* HW dependent includes */
#include "port_buzzer.h"

/* Defines and enums ----------------------------------------------------------*/
/* Enums */

/**
 * @brief States for the finite state machine for the buzzer
 *
 */
enum FSM_BUZZER
{
    WAIT_START = 0, /*!< Initial state for the fsm, waiting for melody and user start*/
    WAIT_NOTE,      /*!< Waits the note time of the playing note*/
    PLAY_NOTE,      /*!< Updates the note to be reproduced, and check if stopped or melody end*/
    PAUSE_NOTE,     /*!< Pause command recieved user_action in pause. Waits for resume reproduction*/
    WAIT_MELODY     /*!< Melody ended. Waits for restart. user_action = stop*/
};

enum USER_ACTIONS
{
    STOP = 0,
    PLAY,
    PAUSE
};

/* Typedefs --------------------------------------------------------------------*/
typedef struct
{
    fsm_t f;             /*!< Internal fsm*/
    melody_t *p_melody;  /*!< Pointer storing the direction of the melody*/
    uint32_t note_index; /*!< Index of the note being reproduced*/
    uint8_t buzzer_id;   /*!< Id of the buzzer*/
    uint8_t user_action; /*!< State of the reproducer*/
    double player_speed; /*!< Speed of the melody*/
    double volume;       /*!< Volume of the melody*/
} fsm_buzzer_t;

/* Function prototypes and explanation -------------------------------------------------*/
/**
 * @brief Set the melody to play.
 *
 * This function sets the melody to play. The user must pass a pointer to the melody to play.
 *
 * @param p_this	Pointer to an fsm_t struct than contains an fsm_buzzer_t struct
 * @param p_melody	Pointer to the melody to play
 *
 */
void fsm_buzzer_set_melody(fsm_t *p_this, const melody_t *p_melody);

/**
 * @brief Set the speed of the player.
 *
 * This function sets the speed of the player. The user must pass a double value with the speed of the player.
 *
 * @param p_this	Pointer to an fsm_t struct than contains an fsm_buzzer_t struct
 * @param speed	Speed of the player
 */
void fsm_buzzer_set_speed(fsm_t *p_this, double speed);

/**
 * @brief Set the action to perform on the player.
 *
 * This function sets the action to perform on the player. The user must pass a USER_ACTIONS value with the action desired. These serve as flags to indicate if the user has stopped, paused or started the player, or if the player has stopped itself.
 *
 * @param p_this	Pointer to an fsm_t struct than contains an fsm_buzzer_t struct
 * @param action	Action to perform on the player
 */
void fsm_buzzer_set_action(fsm_t *p_this, uint8_t action);

/**
 * @brief Get the action of the user.
 *
 * This function returns the action performed on the player. This is useful to know if the player is playing, paused or stopped and a melody has ended.
 *
 * @param p_this	Pointer to an fsm_t struct than contains an fsm_buzzer_t struct
 *
 * @returns uint8_t Action to perform on the player
 */
uint8_t fsm_buzzer_get_action(fsm_t *p_this);

/**
 * @brief Creates a new buzzer finite state machine.
 *
 * This FSM implements a buzzer melody player. The buzzer is considered indeed as a melody player. The user can set the melody to play, the speed of the player and the action to perform on the player.
 *
 * The FSM stores a pointer to the melody to play in the p_melody variable. The user should set it using the function fsm_buzzer_set_melody().
 *
 * The FSM stores the current note of the melody in the note_index variable. With this variable, the FSM knows which note to play next.
 *
 * The FSM stores the action of the user (or the system itself) in the user_action variable. The user should set it using the function fsm_buzzer_set_action(). The user can also get it using the function fsm_buzzer_get_action(). These are not the states of the FSM, but the status desired by the user. The FSM will move to the corresponding state. So, these variables are used as flags to indicate if the user has stopped, paused or started the player, or if the player has stopped itself by the end of the melody. The user can also get the status of the player. These actions/ status of the player can be one of the following:
 *
 * STOP: Request to stop the player either from the user or from the player itself when a melody has ended
 * PLAY: Request to play a melody from the user when a previous action/ status was STOP or PAUSE
 * PAUSE: Request to pause the player from the user
 * The main difference between PAUSE and STOP is that when the player is paused, the index of the melody is not reset. This means that if the user resumes the player, the player will continue playing the melody from the note it was playing when it was paused. If the player is stopped, the index of the melody is reset to 0. This means that if the user starts the player again, the player will start playing the melody from the beginning.
 *
 * In the state WAIT_START, the FSM waits for the user to start the system. The user can start the player when it turns on the system or when a melody has ended. When the user starts the player, the FSM moves to the state PLAY_NOTE. When a melody has ended, the FSM moves to the state WAIT_MELODY.
 *
 * In the state PLAY_NOTE, the FSM can start a note, pause the player or stop the player. In this case it is important the order of the transitions. The FSM checks first if the player must be stopped because of the end of the melody or because the user has stopped it. In both cases the FSM moves to the state WAIT_NOTE. In PLAY_NOTE the FSM also checks if the player must be paused. If the player must be paused, the FSM moves to the state PAUSE_NOTE. If none of the previous conditions are met, from this state the FSM checks if it must start a new note. If it must start a note, the FSM moves to the state WAIT_NOTE.
 *
 * In the state PAUSE_NOTE, the FSM pauses the player. The user can pause the player by setting the status of the player to PAUSE. To resume the player, the user must order the action on the player to PLAY.
 *
 * In the state WAIT_NOTE, the FSM waits for the duration of the note to finish and moves again to the state PLAY_NOTE to check if it must stop, pause or play a new note.
 *
 * In the state WAIT_MELODY, the FSM waits for a new melody to play. The user can set a new melody to play by setting the pointer to the melody to play. The user can also set the action on the player to PLAY to start playing the melody again.
 *
 * @param buzzer_id	Unique buzzer identifier number
 *
 * @returns A pointer to the new buzzer finite state machine
 */
fsm_t *fsm_buzzer_new(uint32_t buzzer_id);

/**
 * @brief Initialize a buzzer finite state machine.
 *
 * This function initializes the default values of the FSM struct and calls to the port to initialize the HW of associated to the given ID.
 *
 * @param p_this	Pointer to an fsm_t struct than contains an fsm_buzzer_t struct
 * @param Unique    buzzer identifier number
 */
void fsm_buzzer_init(fsm_t *p_this, uint32_t buzzer_id);

/**
 * @brief Check if the buzzer finite state machine is playing a melody.
 * @param p_this	Pointer to an fsm_t struct than contains an fsm_buzzer_t struct
 *
 * @returns True if the player is playing or paused. False if the player is stopped.
 */
bool fsm_buzzer_check_activity(fsm_t *p_this);

void fsm_buzzer_set_volume(fsm_t *p_this, double volume);

double fsm_buzzer_get_volume(fsm_t *p_this);
#endif /* FSM_BUZZER_H_ */