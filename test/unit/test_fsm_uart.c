/**
 * @file test_port_usart.c
 * @brief Unit test for the USART FSM state machine. It tests the reception and transmission of data from the USART.
 * 
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
/* HW dependent libraries */
#include <string.h>

/* HW dependent libraries */
#include "port_system.h"
#include "port_usart.h"

/* Other libraries */
#include "fsm_usart.h"

/* Test dependencies */
#include <unity.h>

/* Global variables */
static fsm_t *p_fsm;

/**
 * @brief Set the Up object. It is called before a test function is called.
 * 
 */
void setUp(void)
{
    p_fsm = fsm_usart_new(USART_0_ID);
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
    fsm_t *p_inner_fsm = &((fsm_usart_t *)p_fsm)->f;
    UNITY_TEST_ASSERT_EQUAL_PTR(p_fsm, p_inner_fsm, __LINE__, "The inner FSM of fsm_usart_t is not the first field of the struct");

    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_DATA, fsm_get_state(p_fsm), __LINE__, "The initial state of the FSM is not WAIT_DATA");

    // It assumes there are 3 transitions in the table plus the null transition
    fsm_trans_t *last_transition = &p_inner_fsm->p_tt[3];

    UNITY_TEST_ASSERT_EQUAL_INT(-1, last_transition->orig_state, __LINE__, "The origin state of the last transition of the FSM should be -1");
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, last_transition->in, __LINE__, "The input condition function of the last transition of the FSM should be NULL");
    UNITY_TEST_ASSERT_EQUAL_INT(-1, last_transition->dest_state, __LINE__, "The destination state of the last transition of the FSM should be -1");
    UNITY_TEST_ASSERT_EQUAL_INT(NULL, last_transition->out, __LINE__, "The output modification function of the last transition of the FSM should be NULL");
}

/**
 * @brief Test the reception of data from the USART.
 * 
 */
void test_usart_rx()
{
    char char_array_test[] = "TEST RX";

    // Copy the data to the USART buffer
    memcpy(usart_arr[USART_0_ID].input_buffer, char_array_test, sizeof(char_array_test));

    // Force read_complete
    usart_arr[USART_0_ID].read_complete = true;

    // First transition
    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_DATA, fsm_get_state(p_fsm), __LINE__, "The FSM did not remain in WAIT_DATA after receiving a data from the usart");

    // Check that the data has been stored correctly from the USART buffer to the in_data buffer of the FSM
    UNITY_TEST_ASSERT_EQUAL_MEMORY(char_array_test, ((fsm_usart_t *)p_fsm)->in_data, sizeof(char_array_test), __LINE__, "The data has not been stored correctly in the in_data buffer of the USART FSM");

    // Check that the USART buffer has been cleared correctly
    char expected_buffer[sizeof(char_array_test)];
    memset(expected_buffer, EMPTY_BUFFER_CONSTANT, sizeof(expected_buffer));
    UNITY_TEST_ASSERT_EQUAL_MEMORY(expected_buffer, usart_arr[USART_0_ID].input_buffer, sizeof(expected_buffer), __LINE__, "The data has not been cleared correctly from the input buffer of the USART");

    // Check that the read_complete flag has been cleared correctly
    UNITY_TEST_ASSERT_EQUAL_INT(false, usart_arr[USART_0_ID].read_complete, __LINE__, "The read_complete flag has not been cleared correctly");

    // Check that data_received flag has been set correctly
    UNITY_TEST_ASSERT_EQUAL_INT(true, ((fsm_usart_t *)p_fsm)->data_received, __LINE__, "The data_received flag has not been set correctly");
}

/**
 * @brief Test the transmission of data from the USART.
 * 
 */
void test_usart_tx()
{
    char char_array_test[] = "TEST TX\n";

    // Copy the data to the out_data buffer of the FSM
    memcpy(((fsm_usart_t *)p_fsm)->out_data, char_array_test, sizeof(char_array_test));

    // Second transition (first char transmitted)
    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(SEND_DATA, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to SEND_DATA after sending a data to the usart");

    // Check that the data has been stored correctly from the out_data buffer of the FSM to the USART buffer
    UNITY_TEST_ASSERT_EQUAL_MEMORY(((fsm_usart_t *)p_fsm)->out_data, usart_arr[USART_0_ID].output_buffer, sizeof(char_array_test), __LINE__, "The data has not been stored correctly in the output buffer of the USART");

    printf("Assuming that all the chars have been sent correctly from the output buffer of the USART to the data register...\n");

    // Check that the TXEIE bit has been enabled correctly --> The 2nd++ chars are sent by the ISR
    UNITY_TEST_ASSERT_EQUAL_INT(USART_CR1_TXEIE, usart_arr[USART_0_ID].p_usart->CR1 & USART_CR1_TXEIE, __LINE__, "The TXEIE bit has not been enabled correctly after sending the first and following chars");
    
    // Wait for the last char to be sent, leaving the ISR to send the rest of the chars.
    while ((!usart_arr[USART_0_ID].write_complete))
    {        
    }

    // Check that the write_complete flag has been set correctly. It is the only way to assume that the last char has been sent
    UNITY_TEST_ASSERT_EQUAL_INT(true, usart_arr[USART_0_ID].write_complete, __LINE__, "The write_complete flag has not been set correctly");

    
    // Third transition
    fsm_fire(p_fsm);
    UNITY_TEST_ASSERT_EQUAL_INT(WAIT_DATA, fsm_get_state(p_fsm), __LINE__, "The FSM did not change to WAIT_DATA after sending the last char to the usart");

    // Check that the interrupt has been disabled correctly
    UNITY_TEST_ASSERT_EQUAL_INT(0, usart_arr[USART_0_ID].p_usart->CR1 & USART_CR1_TXEIE, __LINE__, "The TXEIE bit has not been disabled correctly after sending the last char");

    // Check that the usart output buffer has been cleared correctly
    char expected_buffer[USART_OUTPUT_BUFFER_LENGTH];
    memset(expected_buffer, EMPTY_BUFFER_CONSTANT, sizeof(expected_buffer));
    UNITY_TEST_ASSERT_EQUAL_MEMORY(expected_buffer, usart_arr[USART_0_ID].output_buffer, sizeof(expected_buffer), __LINE__, "The data has not been cleared correctly from the output buffer of the USART");

    // Check that the out_data buffer of the FSM has been cleared correctly
    UNITY_TEST_ASSERT_EQUAL_MEMORY(expected_buffer, ((fsm_usart_t *)p_fsm)->out_data, sizeof(expected_buffer), __LINE__, "The data has not been cleared correctly from the out_data buffer of the USART FSM");

    // Check that the index has been reset correctly
    UNITY_TEST_ASSERT_EQUAL_INT(0, usart_arr[USART_0_ID].o_idx, __LINE__, "The index has not been reset correctly after sending the last char");

    // Check that the write_complete flag has been cleared correctly
    UNITY_TEST_ASSERT_EQUAL_INT(false, usart_arr[USART_0_ID].write_complete, __LINE__, "The write_complete flag has not been cleared correctly in the transition to WAIT_DATA");
}

/**
 * @brief Main test function. Read the terminal for instructions or notes.
 * 
 * @return int
 */
int main(void)
{
    port_system_init();
    UNITY_BEGIN();
    RUN_TEST(test_initial_config);
    RUN_TEST(test_usart_rx);
    RUN_TEST(test_usart_tx);
    return UNITY_END();
}