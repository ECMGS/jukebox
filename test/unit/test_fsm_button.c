#include <unity.h>
#include "fsm_button.h"
#include "port_system.h"
#include "port_button.h"

static fsm_t *p_fsm;

void setUp(void)
{
    p_fsm = fsm_button_new(BUTTON_0_DEBOUNCE_TIME_MS, BUTTON_0_ID);
    port_system_gpio_exti_disable(BUTTON_0_PIN); // Disable EXTI to avoid unwanted interrupts
}

void tearDown(void)
{
    fsm_destroy(p_fsm);
}

void test_initial_config(void)
{
    fsm_t *p_inner_fsm = &((fsm_button_t *)p_fsm)->f;
    UNITY_TEST_ASSERT_EQUAL_PTR(p_fsm, p_inner_fsm, __LINE__, "The inner FSM of fsm_button_t is not the first field of the struct");

    UNITY_TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, fsm_get_state(p_fsm), __LINE__, "The initial state of the FSM is not BUTTON_RELEASED");

    // It assumes there are 4 transitions in the table plus the null transition
    fsm_trans_t *last_transition = &p_inner_fsm->p_tt[4];

    UNITY_TEST_ASSERT_EQUAL_INT(-1, last_transition->orig_state, __LINE__, "The origin state of the last transition of the FSM should be -1");
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, last_transition->in, __LINE__, "The input condition function of the last transition of the FSM should be NULL");
    UNITY_TEST_ASSERT_EQUAL_INT(-1, last_transition->dest_state, __LINE__, "The destination state of the last transition of the FSM should be -1");
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, last_transition->out, __LINE__, "The output modification function of the last transition of the FSM should be NULL");
}

void _test_button_press(uint32_t press_time)
{
    // First transition
    buttons_arr[BUTTON_0_ID].flag_pressed = true;
    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED_WAIT, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to BUTTON_PRESSED_WAIT after pressing the button");

    // Second transition
    port_system_delay_ms(press_time);
    fsm_fire(p_fsm);
    if (press_time < BUTTON_0_DEBOUNCE_TIME_MS)
    {
        UNITY_TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED_WAIT, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to BUTTON_RELEASED_WAIT after pressing the button for a short time");
    }
    else
    {
        UNITY_TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to BUTTON_PRESSED after pressing the button for a long time");

        // Third transition
        buttons_arr[BUTTON_0_ID].flag_pressed = false;
        fsm_fire(p_fsm);
        UNITY_TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED_WAIT, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to BUTTON_RELEASED_WAIT after releasing the button");

        // Fourth transition
        port_system_delay_ms(BUTTON_0_DEBOUNCE_TIME_MS+1);
        fsm_fire(p_fsm);
        UNITY_TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to BUTTON_RELEASED after releasing the button");
    }
}

void test_short_button_press(void)
{
    _test_button_press(100);
}

void test_long_button_press(void)
{
    _test_button_press(1000);
}

int main(void)
{
    port_system_init();
    UNITY_BEGIN();

    RUN_TEST(test_initial_config);
    RUN_TEST(test_short_button_press);
    RUN_TEST(test_long_button_press);

    return UNITY_END();
}
