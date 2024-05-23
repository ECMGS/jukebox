/**
 * @file buzzer_director.h
 * @brief Header for buzzer_director.c file.
 * @author Jorge Aljeandro Estefanía Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 08/05/2024
 */
#include <stdint.h>

#include "melodies.h"

#ifndef BUZZER_DIRECTOR_H
#define BUZZER_DIRECTOR_H

/**
 * @brief Sets the action to be performed by all active buzzers.
 * 
 * @param action Action to be performed, following the enum USER_ACTIONS.
*/
void buzzer_director_set_action(uint8_t action);

/**
 * @brief Gets the action performed by the buzzer.
 * 
 * @warning returns the action of the first buzzer, as all active buzzers should have the same action as they are controlled by the buzzer director.
 * 
 * @return uint8_t Action performed by the buzzer, following the enum USER_ACTIONS. 
*/
uint8_t buzzer_director_get_action(void);

/**
 * @brief Sets the melody to be played by the buzzers.
 * 
 * @param p_melody Pointer to the melody to be played.
 * 
 * If the melody has another melody associated in a linked list, the next melody will be played by multiple buzzers until it reaches the limit of available buzzers defined in MAX_BUZZERS.
*/
void buzzer_director_set_melody(const melody_t *p_melody);

/**
 * @brief Sets the speed of the melody to be played by the buzzers.
 * 
 * @param speed Speed of the melody to be played.
 * 
 * The speed is a double value that will be used to calculate the duration of the notes in the melody. It is a coefficient that will be multiplied by the duration of the notes.
*/
void buzzer_director_set_speed(double speed);

/**
* @brief Sets the volume of the buzzer.
*
* @param volume Volume of the buzzer, a double value between 0 and 1.
*
* The volume is the pwm duty cycle of the buzzer, a value between 0 and 1 that will be used to set the volume of the buzzer. The maximum volume will be 0.5 and the minimum 0 and 1.
*/
void buzzer_director_set_volume(double volume);

/**
 * @brief fires all the directed states machines
 * 
 * This function is used to fire all the directed states machines, so they can perform their actions.
*/
void buzzer_director_fire(void);

/**
 * @brief Initializes the buzzer director.
 * 
 * This function initializes the buzzer director, setting the default values for the buzzer director. Initializing all available buzzers.
*/
void buzzer_director_init(void);

/**
 * @brief Checks if the melody has finished playing.
 * 
 * @return bool Returns true if the melody has finished playing, false otherwise.
 * 
 * Checks for all the active buzzers if the melody has finished playing. If all the buzzers have finished playing the melody, it will return true.
*/
bool buzzer_director_check_melody_finished(void);

/**
 * @brief Checks if the buzzer is active.
 * 
 * @return bool Returns true if the buzzer is active, false otherwise.
 * 
 * Checks for all the active buzzers if the buzzer is active. If any of the buzzers is active, it will return true.
*/
bool buzzer_director_check_activity(void);

/**
 * @brief Gets the volume of the buzzer.
 * 
 * @return double Returns the volume of the buzzer.
 * 
 * Gets the volume of the buzzer, a double value between 0 and 1. It returns the volume of the first managed fsm_buzzer state machine.
*/
double buzzer_director_get_volume(void);

#endif /* BUZZER_DIRECTOR_H */