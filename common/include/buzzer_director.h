/**
 * @file lcd_controller.h
 * @brief Header for lcd_controller.c file.
 * @author Jorge Lajeandro Estefania Hidalgo
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
 * @warning 
*/
uint8_t buzzer_director_get_action(void);

void buzzer_director_set_melody(const melody_t *p_melody);

void buzzer_director_set_speed(double speed);

void buzzer_director_set_volume(double volume);

void buzzer_director_fire(void);

void buzzer_director_init(void);

bool buzzer_director_check_melody_finished(void);

bool buzzer_director_check_activity(void);

double buzzer_director_get_volume(void);

#endif /* BUZZER_DIRECTOR_H */