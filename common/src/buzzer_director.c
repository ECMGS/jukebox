#include "fsm_buzzer.h"
#include "port_buzzer.h"
#include "buzzer_director.h"

fsm_buzzer_t* fsm_buzzer[NUM_BUZZERS];
int used_buzzers = 0;

void buzzer_director_init(void) {
    used_buzzers = 0;
    for (int i = 0; i < NUM_BUZZERS; i++) {
        fsm_buzzer[i] = (fsm_buzzer_t*) fsm_buzzer_new(i);
        fsm_buzzer_init((fsm_t*) fsm_buzzer[i], i);
    }
}

void buzzer_director_set_action(uint8_t action) {
    for (int i = 0; i < used_buzzers; i++) {
        fsm_buzzer_set_action((fsm_t*) fsm_buzzer[i], action);
    }
}

void buzzer_director_set_melody(const melody_t* p_melody) {
    // TODO - FIX THIS METHOD
    const melody_t* p_next_melody = p_melody->next_melody;
    used_buzzers = 0;
    int i = 0;
    for (i = 0; (i < NUM_BUZZERS && p_melody != NULL); i++) {
        fsm_buzzer_set_melody((fsm_t*)fsm_buzzer[i], p_melody);
        used_buzzers++;
        p_melody = p_next_melody;
    }

    for (;i < NUM_BUZZERS; i++) {
        fsm_buzzer_set_action((fsm_t*) fsm_buzzer[i], STOP);
    }
}

void buzzer_director_set_speed(double speed) {
    for (int i = 0; i < NUM_BUZZERS; i++) {
        fsm_buzzer_set_speed((fsm_t*)fsm_buzzer[i], speed);
    }
}

void buzzer_director_set_volume(double volume) {
    for (int i = 0; i < NUM_BUZZERS; i++) {
        fsm_buzzer_set_volume((fsm_t*)fsm_buzzer[i], volume);
    }
}

void buzzer_director_fire(void) {
    for (int i = 0; i < NUM_BUZZERS; i++) {
        fsm_fire((fsm_t*)fsm_buzzer[i]);
    }
}

bool buzzer_director_check_melody_finished(void) {
    for (int i = 0; i < used_buzzers; i++)  {
        if (fsm_buzzer_get_action((fsm_t*)fsm_buzzer[i]) != STOP) {
            return false;
        }
    }

    return true;
}

bool buzzer_director_check_activity(void) {
    for (int i = 0; i < used_buzzers; i++) {
        if (fsm_buzzer_check_activity((fsm_t*)fsm_buzzer[i]) != STOP) {
            return true;
        }
    }

    return false;
}

double buzzer_director_get_volume(void) {
    return fsm_buzzer_get_volume((fsm_t*)fsm_buzzer[0]);
}