#include <stdio.h>

#include "fsm_button.h"
#include "port_button.h"
#include "port_system.h"

#define CHANGE_MODE_BUTTON_TIME 1000 // time in ms to change mode (long press)

int main(void)
{
    // Initialize the system
    port_system_init();

    // Create the button FSM
    fsm_t *p_fsm_button = fsm_button_new(BUTTON_0_DEBOUNCE_TIME_MS, BUTTON_0_ID);

    while (1)
    {
        // In every iteration, we fire the FSM and retrieve the duration of the button press
        fsm_fire(p_fsm_button);
        uint32_t duration = fsm_button_get_duration(p_fsm_button);
        if (duration > 0)
        {
            printf("Button %d pressed for %ld ms", BUTTON_0_ID, duration);
            // If the button is pressed for more than CHANGE_MODE_BUTTON_TIME, we toggle the LED
            if (duration >= CHANGE_MODE_BUTTON_TIME) {
                printf(" (long press detected)");
            }
            printf("\n");
            // We always reset the duration after reading it
            fsm_button_reset_duration(p_fsm_button);
        }
    }

    // We should never reach this point
    fsm_destroy(p_fsm_button);
    return 0;
}
