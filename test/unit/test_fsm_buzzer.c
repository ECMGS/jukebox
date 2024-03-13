/**
 * @file test_fsm_buzzer.c
 * @brief Unit test for the BUZZER FSM state machine.
 *
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
/* HW dependent libraries */
#include <math.h>
#include <string.h>

/* HW dependent libraries */
#include "port_system.h"
#include "port_buzzer.h"

/* Other libraries */
#include "fsm_buzzer.h"
#include "melodies.h"

/* Test dependencies */
#include <unity.h>

/* Private defines ------------------------------------------------------------*/
#define BUZZER_TIM_DUR TIM2 /*!< BUZZER timer for note duration */
#define BUZZER_TIM_PWM TIM3 /*!< BUZZER timer for PWM */

/* Global variables */
static fsm_t *p_fsm;
static char msg[200];

/**
 * @brief Set the Up object. It is called before a test function is called.
 *
 */
void setUp(void)
{
    p_fsm = fsm_buzzer_new(BUZZER_0_ID);

    // Disable note duration interrupt
    NVIC_DisableIRQ(TIM2_IRQn);
}

/**
 * @brief Tear down the test. It is called after a test function is called.
 *
 */
void tearDown(void)
{
    fsm_destroy(p_fsm);
}

/**
 * @brief Test the initial configuration of the USART FSM.
 *
 */
void test_initial_config(void)
{
    fsm_t *p_inner_fsm = &((fsm_buzzer_t *)p_fsm)->f;
    UNITY_TEST_ASSERT_EQUAL_PTR(p_fsm, p_inner_fsm, __LINE__, "The inner FSM of fsm_buzzer_t is not the first field of the struct");

    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_START, fsm_get_state(p_fsm), __LINE__, "The initial state of the FSM is not WAIT_START");

    // It assumes there are 8 transitions in the table plus the null transition
    fsm_trans_t *last_transition = &p_inner_fsm->p_tt[8];

    UNITY_TEST_ASSERT_EQUAL_INT(-1, last_transition->orig_state, __LINE__, "The origin state of the last transition of the FSM should be -1");
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, last_transition->in, __LINE__, "The input condition function of the last transition of the FSM should be NULL");
    UNITY_TEST_ASSERT_EQUAL_INT(-1, last_transition->dest_state, __LINE__, "The destination state of the last transition of the FSM should be -1");
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, last_transition->out, __LINE__, "The output modification function of the last transition of the FSM should be NULL");
}

/**
 * @brief Test the note duration timer ISR.
 *
 */
void test_note_duration_interr(void)
{
    // Enable the interrupt for the note duration timer
    NVIC_EnableIRQ(TIM2_IRQn);

    // Set state to WAIT_MELODY
    fsm_set_state(p_fsm, WAIT_START);

    // Set a melody and the index to the 1st note
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = 0;

    // Set user_action to PLAY
    ((fsm_buzzer_t *)p_fsm)->user_action = PLAY;

    // Timeout a little bit more than the duration of the first note
    uint16_t timeout_ms = ((fsm_buzzer_t *)p_fsm)->p_melody->p_durations[0] + 50;

    // Get the current time
    uint32_t start_tick = port_system_get_millis();

    // Fire the FSM
    fsm_fire(p_fsm);

    // Wait for the note to end or for the timeout to be reached
    while (!buzzers_arr[BUZZER_0_ID].note_end)
    {
        // Calculate the elapsed time
        uint32_t elapsed_time = port_system_get_millis() - start_tick;

        // Check if the timeout has been reached
        if (elapsed_time > timeout_ms)
        {
            // Fail the test with a timeout message
            UNITY_TEST_FAIL(__LINE__, "The note duration ISR has not been triggered or note_end has not been set to true after the note duration has ended");
        }
    }
}

/**
 * @brief Test the start of the BUZZER FSM and the first transition.
 *
 */
void test_buzzer_start()
{
    // Check that the p_melody pointer is NULL and user_action is STOP. Check also that index is 0
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, ((fsm_buzzer_t *)p_fsm)->p_melody, __LINE__, "The p_melody pointer is not NULL at the start of the FSM");
    UNITY_TEST_ASSERT_EQUAL_INT(STOP, ((fsm_buzzer_t *)p_fsm)->user_action, __LINE__, "The user_action is not STOP at the start of the FSM");
    UNITY_TEST_ASSERT_EQUAL_INT(0, ((fsm_buzzer_t *)p_fsm)->note_index, __LINE__, "The note_index is not 0 at the start of the FSM");

    // First transition
    // Check the NULL condition at start
    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_START, fsm_get_state(p_fsm), __LINE__, "The FSM should have not changed the state. No melody has been set, and the FSM should not change to WAIT_NOTE");

    // Reset the FSM state (just in case):
    fsm_set_state(p_fsm, WAIT_START);

    // Set a melody but still in STOP mode
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);

    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_START, fsm_get_state(p_fsm), __LINE__, "The FSM should have not changed the state if the user_action is STOP in the first transition");

    // Reset the FSM state (just in case):
    fsm_set_state(p_fsm, WAIT_START);

    // Set a melody and set the user_action to PLAY
    ((fsm_buzzer_t *)p_fsm)->user_action = PLAY;

    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to WAIT_NOTE after setting a melody and the user_action to PLAY");

    // Ensure that the note_index is 1
    UNITY_TEST_ASSERT_EQUAL_INT(1, ((fsm_buzzer_t *)p_fsm)->note_index, __LINE__, "The note_index is not 1 after the first transition");

    // Ensure that the note has been set correctly (frequency and duration)
    double freq = scale_melody.p_notes[0];
    uint16_t dur = scale_melody.p_durations[0];

    // Compute frequency from user ARR and PSC values
    uint32_t arr = BUZZER_TIM_PWM->ARR;
    uint32_t psc = BUZZER_TIM_PWM->PSC;
    double tim_pwm_hz = round((double)(SystemCoreClock) / ((double)(arr) + 1.0) / ((double)(psc) + 1.0));
    sprintf(msg, "ERROR: BUZZER note frequency ARR and PSC are not configured correctly for a frequency of %f Hz. 1st note of the melody: %s", freq, scale_melody.p_name);
    UNITY_TEST_ASSERT_INT_WITHIN(1, freq, tim_pwm_hz, __LINE__, msg);

    // Compute duration from user ARR and PSC values
    arr = BUZZER_TIM_DUR->ARR;
    psc = BUZZER_TIM_DUR->PSC;
    uint16_t tim_note_dur_ms = round((((double)(arr) + 1.0) / ((double)SystemCoreClock / 1000.0)) * ((double)(psc) + 1));
    sprintf(msg, "ERROR: BUZZER note duration ARR and PSC are not configured correctly for a duration of %d ms", dur);
    UNITY_TEST_ASSERT_INT_WITHIN(1, dur, tim_note_dur_ms, __LINE__, msg);
}

/**
 * @brief Test that notes end correctly.
 *
 */
void test_note_end()
{
    // Set state to WAIT_NOTE
    fsm_set_state(p_fsm, WAIT_NOTE);

    // Ensure that note_end is false
    buzzers_arr[BUZZER_0_ID].note_end = false;

    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state has not changed
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have not changed the state. The note has not ended yet");

    // Reset the FSM state (just in case):
    fsm_set_state(p_fsm, WAIT_NOTE);

    // Ensure that note_end is true
    buzzers_arr[BUZZER_0_ID].note_end = true;

    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state has changed to PLAY_NOTE
    UNITY_TEST_ASSERT_EQUAL_INT(PLAY_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to PLAY_NOTE. The note has ended");

    // Ensure that timers are disabled
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_DUR->CR1 & TIM_CR1_CEN, __LINE__, "The note duration timer is not disabled after the note has ended");
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_PWM->CR1 & TIM_CR1_CEN, __LINE__, "The PWM timer is not disabled after the note has ended");
}

/**
 * @brief Test the pause of the melody.
 *
 */
void test_pause_melody()
{
    printf("Testing transition PLAY_NOTE --> PAUSE_NOTE...\n");
    // PLAY_NOTE --> PAUSE_NOTE
    // Set state to PLAY_NOTE
    fsm_set_state(p_fsm, PLAY_NOTE);

    // Set a melody and the index to the second note.
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = 1;

    // Set the user_action to PAUSE
    ((fsm_buzzer_t *)p_fsm)->user_action = PAUSE;

    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state does change to PAUSE_NOTE
    UNITY_TEST_ASSERT_EQUAL_INT(PAUSE_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to PAUSE_NOTE when user_action is PAUSE");

    // Ensure that the note_index has been reset and the timers are disabled
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_DUR->CR1 & TIM_CR1_CEN, __LINE__, "The note duration timer is not disabled after the melody has been paused");
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_PWM->CR1 & TIM_CR1_CEN, __LINE__, "The PWM timer is not disabled after the melody has been paused");
}

/**
 * @brief Test the stop of the melody.
 *
 */
void test_stop_melody()
{
    printf("Testing transition PLAY_NOTE --> WAIT_START...\n");
    // PLAY_NOTE --> WAIT_START
    // Set state to PLAY_NOTE
    fsm_set_state(p_fsm, PLAY_NOTE);

    // Set a melody and the index to the second note.
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = 1;

    // Set the user_action to STOP
    ((fsm_buzzer_t *)p_fsm)->user_action = STOP;

    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state does not change to WAIT_NOTE but WAIT_START
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_START, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to WAIT_START when user_action is STOP");

    // Ensure that the note_index has been reset and the timers are disabled
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_DUR->CR1 & TIM_CR1_CEN, __LINE__, "The note duration timer is not disabled after the melody has been stopped");
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_PWM->CR1 & TIM_CR1_CEN, __LINE__, "The PWM timer is not disabled after the melody has been stopped");
    UNITY_TEST_ASSERT_EQUAL_INT(0, ((fsm_buzzer_t *)p_fsm)->note_index, __LINE__, "The note_index has not been reset after the melody has been stopped");
}

/**
 * @brief Test the play of a note.
 *
 */
void test_play_note(void)
{
    printf("Testing transition PLAY_NOTE --> WAIT_NOTE...\n");
    // Set state to PLAY_NOTE
    fsm_set_state(p_fsm, PLAY_NOTE);

    // Set a melody and the index to the second note.
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = 1;

    // PLAY_NOTE --> WAIT_NOTE
    // Set the user_action to PLAY
    ((fsm_buzzer_t *)p_fsm)->user_action = PLAY;

    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state changes to WAIT_NOTE
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to WAIT_NOTE when user_action is PLAY and the melody index is less than the melody length");

    // Ensure that the note_index has increased
    UNITY_TEST_ASSERT_EQUAL_INT(2, ((fsm_buzzer_t *)p_fsm)->note_index, __LINE__, "The note_index has not been increased after the transition to WAIT_NOTE");

    // Ensure that the note has been set correctly (frequency and duration)
    double freq = scale_melody.p_notes[1];
    uint16_t dur = scale_melody.p_durations[1];

    // Compute frequency from user ARR and PSC values
    uint32_t arr = BUZZER_TIM_PWM->ARR;
    uint32_t psc = BUZZER_TIM_PWM->PSC;
    double tim_pwm_hz = round((double)(SystemCoreClock) / ((double)(arr) + 1.0) / ((double)(psc) + 1.0));
    sprintf(msg, "ERROR: BUZZER note frequency ARR and PSC are not configured correctly for a frequency of %f Hz. 2nd note of the melody: %s", freq, scale_melody.p_name);
    UNITY_TEST_ASSERT_INT_WITHIN(1, freq, tim_pwm_hz, __LINE__, msg);

    // Compute duration from user ARR and PSC values
    arr = BUZZER_TIM_DUR->ARR;
    psc = BUZZER_TIM_DUR->PSC;
    uint16_t tim_note_dur_ms = round((((double)(arr) + 1.0) / ((double)SystemCoreClock / 1000.0)) * ((double)(psc) + 1));
    sprintf(msg, "ERROR: BUZZER note duration ARR and PSC are not configured correctly for a duration of %d ms", dur);
    UNITY_TEST_ASSERT_INT_WITHIN(1, dur, tim_note_dur_ms, __LINE__, msg);
}

/**
 * @brief Test the end of the melody.
 *
 */
void test_end_melody()
{
    printf("Testing transition PLAY_NOTE --> WAIT_MELODY...\n");

    // Set state to PLAY_NOTE
    fsm_set_state(p_fsm, PLAY_NOTE);

    // Set user_action to PLAY
    ((fsm_buzzer_t *)p_fsm)->user_action = PLAY;

    // Set a melody and the index to the last note.
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = scale_melody.melody_length;

    // PLAY_NOTE --> WAIT_MELODY
    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state does not change to WAIT_NOTE, but to WAIT_MELODY
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_MELODY, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to WAIT_MELODY if the melody index is greater or equal to the melody length");

    // Check that the index has been reset to 0, user action to STOP and the timers are disabled
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_DUR->CR1 & TIM_CR1_CEN, __LINE__, "The note duration timer is not disabled after the note has ended");
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_TIM_PWM->CR1 & TIM_CR1_CEN, __LINE__, "The PWM timer is not disabled after the note has ended");
    UNITY_TEST_ASSERT_EQUAL_INT(0, ((fsm_buzzer_t *)p_fsm)->note_index, __LINE__, "The note_index has not been reset after the transition to WAIT_MELODY");
    UNITY_TEST_ASSERT_EQUAL_INT(STOP, ((fsm_buzzer_t *)p_fsm)->user_action, __LINE__, "The user_action has not been set to STOP after the transition to WAIT_MELODY");
}

/**
 * @brief Test the resume of the melody.
 *
 */
void test_resume_melody(void)
{
    printf("Testing transition PAUSE_NOTE --> PLAY_NOTE...\n");

    // Set state to PAUSE_NOTE
    fsm_set_state(p_fsm, PAUSE_NOTE);

    // Set a melody and the index to the 1st note
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = 0;

    // Set user_action to PLAY
    ((fsm_buzzer_t *)p_fsm)->user_action = PLAY;

    // PAUSE_NOTE --> PLAY_NOTE
    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state does change to PLAY_NOTE
    UNITY_TEST_ASSERT_EQUAL_INT(PLAY_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to PLAY_NOTE if the user_action is PLAY when the state is PAUSE_NOTE");
}

/**
 * @brief Test the restart of the melody.
 *
 */
void test_restart_melody(void)
{
    printf("Testing transition WAIT_MELODY --> WAIT_NOTE...\n");

    // Set state to WAIT_MELODY
    fsm_set_state(p_fsm, WAIT_MELODY);

    // Set a melody and the index to the 1st note
    ((fsm_buzzer_t *)p_fsm)->p_melody = (melody_t *)(&scale_melody);
    ((fsm_buzzer_t *)p_fsm)->note_index = 0;

    // Set user_action to PLAY
    ((fsm_buzzer_t *)p_fsm)->user_action = PLAY;

    // WAIT_MELODY --> WAIT_NOTE
    // Fire the FSM
    fsm_fire(p_fsm);

    // Ensure that the state does change to WAIT_NOTE
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_NOTE, fsm_get_state(p_fsm), __LINE__, "The FSM should have changed the state to WAIT_NOTE if the user_action is PLAY when the state is WAIT_MELODY");
}

/**
 * @brief Test the auxiliary functions of the BUZZER FSM. 
 * 
 */
void test_auxiliary_functions(void)
{
    // Test the function to set the melody
    melody_t *p_melody = (melody_t *)(&scale_melody);
    fsm_buzzer_set_melody(p_fsm, p_melody);
    UNITY_TEST_ASSERT_EQUAL_PTR(p_melody, ((fsm_buzzer_t *)p_fsm)->p_melody, __LINE__, "The melody has not been set correctly in the function fsm_buzzer_set_melody()");

    // Test the function to set the user action
    fsm_buzzer_set_action(p_fsm, STOP);
    UNITY_TEST_ASSERT_EQUAL_INT(STOP, ((fsm_buzzer_t *)p_fsm)->user_action, __LINE__, "The user_action has not been set correctly in the function fsm_buzzer_set_action()");
    UNITY_TEST_ASSERT_EQUAL_INT(0, ((fsm_buzzer_t *)p_fsm)->note_index, __LINE__, "The note_index has not been reset correctly in the function fsm_buzzer_set_action() after setting the user_action to STOP");

    // Test the function to get the user action
    ((fsm_buzzer_t *)p_fsm)->user_action = PAUSE;
    UNITY_TEST_ASSERT_EQUAL_INT(PAUSE, fsm_buzzer_get_action(p_fsm), __LINE__, "The user_action has not been retrieved correctly in the function fsm_buzzer_get_action()");

    // Test the function to set the speed
    fsm_buzzer_set_speed(p_fsm, 2);
    UNITY_TEST_ASSERT_EQUAL_INT(2, (uint32_t)(((fsm_buzzer_t *)p_fsm)->player_speed), __LINE__, "The speed has not been set correctly in the function fsm_buzzer_set_speed()");
}

/**
 * @brief Main test function. Read the terminal for instructions or notes.
 *
 * @return int
 */
int main(void)
{
    printf("Starting BUZZER FSM unit test...\n");
    printf("This test checks some (most) of the transitions of the BUZZER FSM independently.\n");
    printf("Please to check that the BUZZER FSM is working correctly run the Integration test.\n");
    printf("Most of the tests check what it is expected to happen, but they do not check what it is not expected to happen.\n");
    printf("The test is not exhaustive.\n");

    port_system_init();
    UNITY_BEGIN();
    RUN_TEST(test_initial_config);
    RUN_TEST(test_buzzer_start);
    RUN_TEST(test_note_duration_interr);
    RUN_TEST(test_note_end);
    RUN_TEST(test_play_note);
    RUN_TEST(test_pause_melody);
    RUN_TEST(test_stop_melody);
    RUN_TEST(test_end_melody);
    RUN_TEST(test_resume_melody);
    RUN_TEST(test_restart_melody);
    RUN_TEST(test_auxiliary_functions);
    return UNITY_END();
}
