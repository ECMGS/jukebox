/**
 * @file fsm_button.c
 * @brief Button FSM main file.
 * @author Jorge Alejandro Estefanía Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 21/02/2024
 */

/* Includes ------------------------------------------------------------------*/
#include "fsm_button.h"
#include "port_button.h"

bool fsm_button_check_activity (fsm_t *p_this) {
    fsm_button_t *p_fsm = (fsm_button_t*) (p_this);

    return BUTTON_RELEASED != p_fsm->f.current_state;
}

/**
 * @brief checks if the button is pressed.
 * 
 * @param p_fsm pointer to the button FSM
 * @return true if the button is pressed; false otherwise.
 */
static bool check_button_pressed(fsm_t * p_this) {
    fsm_button_t *p_fsm = (fsm_button_t*) (p_this);

    return port_button_is_pressed(p_fsm->button_id);
}	
/**
 * @brief checks if the button is released.
 *
 * @param p_fsm pointer to the button FSM
 * @return true if the button is realeased; false otherwise.
 */
static bool check_button_released(fsm_t *p_this) {
    fsm_button_t *p_fsm = (fsm_button_t*) (p_this);

    return !port_button_is_pressed(p_fsm->button_id);    
}
/**
 * @brief checks if the debounce time has passed.
 * 
 * @param p_fsm pointer to the button FSM
 * @return true if the current system time is greater than the last debounce timeout.
 */
static bool check_timeout(fsm_t *p_this) {
    fsm_button_t *p_fsm = (fsm_button_t*) (p_this);

    return port_button_get_tick() > p_fsm->next_timeout;
}


/* State machine output or action functions */
/**
 * @brief stores the current system time as the last time the button was pressed
 *
 * @param p_fsm pointer to the button FSM
 */
static void do_store_tick_pressed(fsm_t* p_this) {
    fsm_button_t *p_fsm = (fsm_button_t*) (p_this);

    p_fsm->tick_pressed = port_button_get_tick();
    p_fsm->next_timeout = p_fsm->tick_pressed + p_fsm->debounce_time;
}
/**
 * @brief it computes the time since the last time the button has been pressed.
 *
 * @param p_fsm pointer to the button FSM
 */
static void do_set_duration(fsm_t* p_this) {
    fsm_button_t *p_fsm = (fsm_button_t*) (p_this);

    p_fsm->duration = port_button_get_tick() - p_fsm->tick_pressed;
    p_fsm->next_timeout = port_button_get_tick() + p_fsm->debounce_time;
}

fsm_trans_t fsm_trans_button[] = {
    { BUTTON_RELEASED, check_button_pressed, BUTTON_PRESSED_WAIT, do_store_tick_pressed },
    { BUTTON_PRESSED_WAIT, check_timeout, BUTTON_PRESSED, NULL },
    { BUTTON_PRESSED, check_button_released, BUTTON_RELEASED_WAIT, do_set_duration },
    { BUTTON_RELEASED_WAIT, check_timeout, BUTTON_RELEASED, NULL },
    {-1, NULL, -1, NULL },
};

/* Other auxiliary functions */

fsm_t *fsm_button_new(uint32_t debounce_time, uint32_t button_id)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_button_t)); /* Do malloc to reserve memory of all other FSM elements, although it is interpreted as fsm_t (the first element of the structure) */
    fsm_button_init(p_fsm, debounce_time, button_id);
    return p_fsm;
}

void fsm_button_init(fsm_t *p_this, uint32_t debounce_time, uint32_t button_id)
{
    fsm_button_t *p_fsm = (fsm_button_t *)(p_this);
    fsm_init(p_this, fsm_trans_button);

    p_fsm->debounce_time = debounce_time;
    p_fsm->button_id = button_id;

    p_fsm->tick_pressed = 0;
    p_fsm->duration = 0;

    port_button_init(button_id);
}

uint32_t fsm_button_get_duration (fsm_t *p_this) {
    fsm_button_t *p_fsm = (fsm_button_t *)(p_this);
    return p_fsm->duration;
}

void fsm_button_reset_duration (fsm_t *p_this) {
    fsm_button_t *p_fsm = (fsm_button_t *)(p_this);
    p_fsm->duration = 0;
}