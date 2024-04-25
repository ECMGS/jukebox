#include <stdint.h>

#include "melodies.h"

#ifndef BUZZER_DIRECTOR_H
#define BUZZER_DIRECTOR_H

void buzzer_director_set_action(uint8_t action);

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