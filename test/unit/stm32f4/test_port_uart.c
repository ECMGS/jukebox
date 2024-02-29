/**
 * @file test_port_usart.c
 * @brief Unit test for the USART port driver. 
 * 
 * It checks the configuration of the USART peripheral and the GPIO pins, and the reset of the input and output buffers. It also checks the priority of the USART interrupt using the Unity framework.
 * 
 * It also checks that the registers of the button are configured correctly and that no other registers have been modified.
 * 
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
/* HW dependent libraries */
#include "port_usart.h"
#include "port_button.h"
#include "port_system.h"
#include "stm32f4xx.h"

/* Test dependencies */
#include <unity.h>

/**
 * @brief Set the Up object
 * 
 * This function is called before each test function is run.
 * 
 */
void setUp(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

/**
 * @brief Tear down the object
 * 
 * This function is called after each test function is run.
 * 
 */
void tearDown(void)
{
    RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN;
    RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN;
    RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN;
}

/**
 * @brief Test the identifiers of the USART for the basis specifications
 * 
 */
void test_identifiers(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(0, USART_0_ID, __LINE__, "ERROR: USART_0_ID must be 0");
    UNITY_TEST_ASSERT_EQUAL_INT(USART3, USART_0, __LINE__, "ERROR: USART_0 must be USART3");
}

/**
 * @brief Test the TX pins of the USART for the basis specifications
 * 
 */
void test_pins_tx(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(GPIOB, USART_0_GPIO_TX, __LINE__, "ERROR: USART_0_GPIO_TX GPIO must be GPIOB");
    UNITY_TEST_ASSERT_EQUAL_INT(10, USART_0_PIN_TX, __LINE__, "ERROR: USART_0_PIN_TX pin must be 10");
}

/**
 * @brief Test the RX pins of the USART for the basis specifications
 * 
 */
void test_pins_rx(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(GPIOC, USART_0_GPIO_RX, __LINE__, "ERROR: USART_0_GPIO_RX GPIO must be GPIOC");
    UNITY_TEST_ASSERT_EQUAL_INT(11, USART_0_PIN_RX, __LINE__, "ERROR: USART_0_PIN_RX pin must be 11");
}

/**
 * @brief Test the configuration of the GPIO registers for the TX pin of the USART
 * 
 */
void test_regs_tx(void)
{
    // Retrieve previous configuration
    uint32_t prev_gpio_mode = USART_0_GPIO_TX->MODER;
    uint32_t prev_gpio_pupd = USART_0_GPIO_TX->PUPDR;

    // Call configuration function
    port_usart_init(USART_0_ID);

    // Check that the mode is configured correctly
    uint32_t mode = ((USART_0_GPIO_TX->MODER) >> (USART_0_PIN_TX * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_MODE_ALTERNATE, mode, __LINE__, "ERROR: USART TX mode is not configured as alternate");

    // Check that the pull up/down is configured correctly
    uint32_t usart_tx_pupd = ((USART_0_GPIO_TX->PUPDR) >> (USART_0_PIN_TX * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_PUPDR_PUP, usart_tx_pupd, __LINE__, "ERROR: USART TX pull up/down is not configured as pull up");

    // Check alternate function
    uint32_t usart_tx_af = ((USART_0_GPIO_TX->AFR[USART_0_PIN_TX / 8]) >> ((USART_0_PIN_TX % 8) * 4)) & 0xF;
    UNITY_TEST_ASSERT_EQUAL_UINT32(7, usart_tx_af, __LINE__, "ERROR: USART TX alternate function is not configured as AF7");

    // Check that no other pins other than the needed have been modified:
    uint32_t mask = ~(0x3 << (USART_0_PIN_TX * 2));
    uint32_t prev_gpio_mode_masked = prev_gpio_mode & mask;
    uint32_t prev_gpio_pupd_masked = prev_gpio_pupd & mask;

    uint32_t curr_gpio_mode_masked = USART_0_GPIO_TX->MODER & mask;
    uint32_t curr_gpio_pupd_masked = USART_0_GPIO_TX->PUPDR & mask;

    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_mode_masked, curr_gpio_mode_masked, __LINE__, "ERROR: The GPIO MODE has been modified for other pins than the USART TX");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_pupd_masked, curr_gpio_pupd_masked, __LINE__, "ERROR: GPIO PUPD has been modified for other pins than the USART TX");
}

/**
 * @brief Test the configuration of the GPIO registers for the RX pin of the USART
 * 
 */
void test_regs_rx(void)
{
    port_button_init(BUTTON_0_ID); // to make sure that the GPIO configuration is not modified by the USART
    // Retrieve previous configuration
    uint32_t prev_gpio_mode = USART_0_GPIO_RX->MODER;
    uint32_t prev_gpio_pupd = USART_0_GPIO_RX->PUPDR;

    // Call configuration function
    port_usart_init(USART_0_ID);

    // Check that the mode is configured correctly
    uint32_t mode = ((USART_0_GPIO_RX->MODER) >> (USART_0_PIN_RX * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_MODE_ALTERNATE, mode, __LINE__, "ERROR: USART RX mode is not configured as alternate");

    // Check that the pull up/down is configured correctly
    uint32_t usart_tx_pupd = ((USART_0_GPIO_RX->PUPDR) >> (USART_0_PIN_RX * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_PUPDR_PUP, usart_tx_pupd, __LINE__, "ERROR: USART RX pull up/down is not configured as pull up");

    // Check alternate function
    uint32_t usart_tx_af = ((USART_0_GPIO_RX->AFR[USART_0_PIN_RX / 8]) >> ((USART_0_PIN_RX % 8) * 4)) & 0xF;
    UNITY_TEST_ASSERT_EQUAL_UINT32(7, usart_tx_af, __LINE__, "ERROR: USART RX alternate function is not configured as AF7");

    // Check that no other pins other than the needed have been modified:
    uint32_t mask = ~(0x3 << (USART_0_PIN_RX * 2));
    uint32_t prev_gpio_mode_masked = prev_gpio_mode & mask;
    uint32_t prev_gpio_pupd_masked = prev_gpio_pupd & mask;

    uint32_t curr_gpio_mode_masked = USART_0_GPIO_RX->MODER & mask;
    uint32_t curr_gpio_pupd_masked = USART_0_GPIO_RX->PUPDR & mask;

    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_mode_masked, curr_gpio_mode_masked, __LINE__, "ERROR: The GPIO MODE has been modified for other pins than the USART RX");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_pupd_masked, curr_gpio_pupd_masked, __LINE__, "ERROR: GPIO PUPD has been modified for other pins than the USART RX");
}

/**
 * @brief Test the configuration of the USART registers for the basis specifications
 * 
 */
void test_usart_config(void)
{
    // Retrieve previous configuration
    uint32_t prev_usart_cr1 = USART_0->CR1;
    uint32_t prev_usart_cr2 = USART_0->CR2;
    uint32_t prev_usart_sr = USART_0->SR;

    // Call configuration function
    port_usart_init(USART_0_ID);

    // Disable USART interrupts to avoid any interference
    NVIC_DisableIRQ(USART3_IRQn);    

    // Ckeck that the peripheral clock is enabled
    uint32_t usart3_rcc = (RCC->APB1ENR) & RCC_APB1ENR_USART3EN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(RCC_APB1ENR_USART3EN_Msk, usart3_rcc, __LINE__, "ERROR: USART3 peripheral clock is not enabled after configuration");

    // Check that the USART is disabled
    uint32_t usart_ue = (USART_0->CR1) & USART_CR1_UE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(USART_CR1_UE_Msk, usart_ue, __LINE__, "ERROR: USART is not enabled after configuration");

    // Check that TX and RX are enabled
    uint32_t usart_te = (USART_0->CR1) & USART_CR1_TE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(USART_CR1_TE_Msk, usart_te, __LINE__, "ERROR: USART Transmission is not enabled after configuration");

    uint32_t usart_re = (USART_0->CR1) & USART_CR1_RE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(USART_CR1_RE_Msk, usart_re, __LINE__, "ERROR: USART Reception is not enabled after configuration");

    // Check that interrupts are disabled
    uint32_t usart_txeie = (USART_0->CR1) & USART_CR1_TXEIE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_txeie, __LINE__, "ERROR: USART Tranmission Interrupt should be disabled in the configuration");

    uint32_t usart_rxneie = (USART_0->CR1) & USART_CR1_RXNEIE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_rxneie, __LINE__, "ERROR: USART Reception Interrupt should be disabled in the configuration");

    uint32_t usart_tcie = (USART_0->CR1) & USART_CR1_TCIE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_tcie, __LINE__, "ERROR: USART Tranmission Complete Interrupt should be disabled in the configuration");

    // Check that the data length is configured correctly
    uint32_t usart_m = (USART_0->CR1) & USART_CR1_M_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_m, __LINE__, "ERROR: USART data length is not configured as 8 bits");

    // Check that the parity is configured correctly
    uint32_t usart_pce = (USART_0->CR1) & USART_CR1_PCE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_pce, __LINE__, "ERROR: USART parity is not configured as no parity");

    // Check that the oversampling is configured correctly
    uint32_t usart_over = (USART_0->CR1) & USART_CR1_OVER8_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_over, __LINE__, "ERROR: USART oversampling is not configured by a factor of 16");

    // Check that the stop bits are configured correctly
    uint32_t usart_stop = (USART_0->CR2) & USART_CR2_STOP_Pos;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_stop, __LINE__, "ERROR: USART stop bits are not configured as 1 stop bit");

    // Check that the status registers are configured correctly
    uint32_t usart_dr = (USART_0->DR) & 0x1FF;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_dr, __LINE__, "ERROR: USART data register is not reset after configuration");

    // Wait for the TXE and TC flags to be set, because they are set after send an idle frame as first transmission when `TE` bit is set in USART_CR1!
    port_system_delay_ms(10);

    // If data register is empty, the TXE flag is set, and TC too
    uint32_t usart_sr_tx = (USART_0->SR) & USART_SR_TXE_Msk;
    uint32_t usart_sr_tc = (USART_0->SR) & USART_SR_TC_Msk;
    if (!usart_dr)
    {
        UNITY_TEST_ASSERT_EQUAL_UINT32(USART_SR_TXE_Msk, usart_sr_tx, __LINE__, "ERROR: USART data register is empty and thus the TXE flag should be set");
        
        if (usart_sr_tx)
        {
            UNITY_TEST_ASSERT_EQUAL_UINT32(USART_SR_TC_Msk, usart_sr_tc, __LINE__, "ERROR: USART data register is empty, TXE bit is set, and thus the TC flag should be set as well");
        }        
    }
    else
    {
        UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_sr_tx, __LINE__, "ERROR: USART data register is not empty and thus the TXE flag should not be set");
        UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_sr_tc, __LINE__, "ERROR: USART data register is not empty and thus the TC flag should not be set");
    }

    uint32_t usart_sr_rx = (USART_0->SR) & USART_SR_RXNE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, usart_sr_rx, __LINE__, "ERROR: USART status register for Reception Interrupt should be cleared in the configuration");

    
    // Check that the baud rate is configured correctly
    uint32_t usart_brr = USART_0->BRR;
    UNITY_TEST_ASSERT_EQUAL_UINT32(03203, usart_brr, __LINE__, "ERROR: USART baud rate is not configured as 9600 bauds");

    // Check that no other registers have been modified
    uint32_t mask_cr1 = ~(0xB5EC);

    uint32_t prev_usart_cr1_masked = prev_usart_cr1 & mask_cr1;
    uint32_t curr_usart_cr1_masked = USART_0->CR1 & mask_cr1;
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_usart_cr1_masked, curr_usart_cr1_masked, __LINE__, "ERROR: USART CR1 has been modified for other bits that should not be modified");

    uint32_t mask_cr2 = ~(0x3000);
    uint32_t prev_usart_cr2_masked = prev_usart_cr2 & mask_cr2;
    uint32_t curr_usart_cr2_masked = USART_0->CR2 & mask_cr2;
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_usart_cr2_masked, curr_usart_cr2_masked, __LINE__, "ERROR: USART CR2 has been modified for other bits that should not be modified");

    uint32_t mask_sr = ~(0xE0);
    uint32_t prev_usart_sr_masked = prev_usart_sr & mask_sr;
    uint32_t curr_usart_sr_masked = USART_0->SR & mask_sr;
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_usart_sr_masked, curr_usart_sr_masked, __LINE__, "ERROR: USART SR has been modified for other bits that should not be modified");
}

/**
 * @brief Test the reset of the input and output buffers
 * 
 */
void test_buffer_reset(void)
{
    // Call configuration function
    port_usart_init(USART_0_ID);

    // Check that the input and output buffers are reset with the EMPTY value
    for (int i = 0; i < USART_INPUT_BUFFER_LENGTH; i++)
    {
        UNITY_TEST_ASSERT_EQUAL_UINT8(EMPTY_BUFFER_CONSTANT, usart_arr[USART_0_ID].input_buffer[i], __LINE__, "ERROR: USART input buffer is not reset with the EMPTY_BUFFER_CONSTANT value");
    }

    for (int i = 0; i < USART_OUTPUT_BUFFER_LENGTH; i++)
    {
        UNITY_TEST_ASSERT_EQUAL_UINT8(EMPTY_BUFFER_CONSTANT, usart_arr[USART_0_ID].output_buffer[i], __LINE__, "ERROR: USART output buffer is not reset with the EMPTY_BUFFER_CONSTANT value");
    }
}

/**
 * @brief Test the priority of the USART interrupt
 * 
 */
void test_usart_isr_priority(void)
{
    uint32_t Priority = NVIC_GetPriority(USART3_IRQn);
    uint32_t PriorityGroup = NVIC_GetPriorityGrouping();
    uint32_t pPreemptPriority;
    uint32_t pSubPriority;

    NVIC_DecodePriority(Priority, PriorityGroup, &pPreemptPriority, &pSubPriority);

    TEST_ASSERT_EQUAL(2, pPreemptPriority);
    TEST_ASSERT_EQUAL(0, pSubPriority);
}

/**
 * @brief Main function to run the unit tests.
 * 
 * @return int 
 */
int main(void)
{
    port_system_init();
    UNITY_BEGIN();
    RUN_TEST(test_identifiers);
    RUN_TEST(test_pins_tx);
    RUN_TEST(test_pins_rx);
    RUN_TEST(test_regs_tx);
    RUN_TEST(test_regs_rx);
    RUN_TEST(test_usart_config);
    RUN_TEST(test_buffer_reset);
    RUN_TEST(test_usart_isr_priority);
    return UNITY_END();
}