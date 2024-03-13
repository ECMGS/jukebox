/**
 * @file test_port_buzzer.c
 * @brief Unit test for the BUZZER port driver.
 *
 * It checks the configuration of the BUZZER peripheral and the GPIO pins. It also checks the priority of the BUZZER interrupt using the Unity framework.
 * Some of other PORT functions are also called to check the correct behavior of the BUZZER driver. 
 *
 * It also checks that the registers of the button and USART are configured correctly and that no other registers have been modified.
 *
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */
#include <math.h>

/* HW dependent libraries */
#include "port_button.h"
#include "port_usart.h"
#include "port_buzzer.h"
#include "port_system.h"
#include "stm32f4xx.h"

/* Test dependencies */
#include <unity.h>

/* Private defines ------------------------------------------------------------*/
#define BUZZER_TIM_DUR TIM2 /*!< BUZZER timer for note duration */
#define BUZZER_TIM_PWM TIM3 /*!< BUZZER timer for PWM */

/* Private variables ---------------------------------------------------------*/
static char msg[200]; /*!< Buffer for the error messages */

/**
 * @brief Set the Up object
 *
 * This function is called before each test function is run.
 *
 */
void setUp(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

/**
 * @brief Tear down the object
 *
 * This function is called after each test function is run.
 *
 */
void tearDown(void)
{
    RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
}

/**
 * @brief Test the identifiers of the BUZZER for the basis specifications
 *
 */
void test_identifiers(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUZZER_0_ID, __LINE__, "ERROR: BUZZER_0_ID must be 0");
    UNITY_TEST_ASSERT_EQUAL_FLOAT(0.5, BUZZER_PWM_DC, __LINE__, "ERROR: BUZZER_PWM_DC must be 0.5");
}

/**
 * @brief Test the pin of the BUZZER for the basis specifications
 *
 */
void test_pins(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(GPIOA, BUZZER_0_GPIO, __LINE__, "ERROR: BUZZER_0_GPIO_TX GPIO must be GPIOA");
    UNITY_TEST_ASSERT_EQUAL_INT(6, BUZZER_0_PIN, __LINE__, "ERROR: BUZZER_0_PIN_TX pin must be 6");
}
/**
 * @brief Test the configuration of the GPIO registers for the pin of the BUZZER
 *
 */
void test_regs(void)
{
    port_button_init(BUTTON_0_ID); // to make sure that the GPIO configuration is not modified by the BUZZER
    port_usart_init(USART_0_ID);   // to make sure that the GPIO configuration is not modified by the BUZZER

    // Retrieve previous configuration
    uint32_t prev_gpio_mode = BUZZER_0_GPIO->MODER;
    uint32_t prev_gpio_pupd = BUZZER_0_GPIO->PUPDR;

    // Call configuration function
    port_buzzer_init(BUZZER_0_ID);

    // Check that the mode is configured correctly
    uint32_t mode = ((BUZZER_0_GPIO->MODER) >> (BUZZER_0_PIN * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_MODE_ALTERNATE, mode, __LINE__, "ERROR: BUZZER mode is not configured as alternate");

    // Check that the pull up/down is configured correctly
    uint32_t buzzer_pupd = ((BUZZER_0_GPIO->PUPDR) >> (BUZZER_0_PIN * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_PUPDR_NOPULL, buzzer_pupd, __LINE__, "ERROR: BUZZER pull up/down is not configured as no pull up/down");

    // Check alternate function
    uint32_t buzzer_tx_af = ((BUZZER_0_GPIO->AFR[BUZZER_0_PIN / 8]) >> ((BUZZER_0_PIN % 8) * 4)) & 0xF;
    UNITY_TEST_ASSERT_EQUAL_UINT32(2, buzzer_tx_af, __LINE__, "ERROR: BUZZER alternate function is not configured as AF2");

    // Check that no other pins other than the needed have been modified:
    uint32_t mask = ~(0x3 << (BUZZER_0_PIN * 2));
    uint32_t prev_gpio_mode_masked = prev_gpio_mode & mask;
    uint32_t prev_gpio_pupd_masked = prev_gpio_pupd & mask;

    uint32_t curr_gpio_mode_masked = BUZZER_0_GPIO->MODER & mask;
    uint32_t curr_gpio_pupd_masked = BUZZER_0_GPIO->PUPDR & mask;

    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_mode_masked, curr_gpio_mode_masked, __LINE__, "ERROR: The GPIO MODE has been modified for other pins than the BUZZER");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_pupd_masked, curr_gpio_pupd_masked, __LINE__, "ERROR: GPIO PUPD has been modified for other pins than the BUZZER");
}

/**
 * @brief Test the configuration of the BUZZER timer for note duration
 *
 */
void test_buzzer_timer_note_duration_config(void)
{
    // Retrieve previous configuration
    uint32_t prev_tim_note_dur_cr1 = BUZZER_TIM_DUR->CR1;
    uint32_t prev_tim_note_dur_dier = BUZZER_TIM_DUR->DIER;
    uint32_t prev_tim_note_dur_sr = BUZZER_TIM_DUR->SR;

    // Call configuration function
    port_buzzer_init(BUZZER_0_ID);

    // Disable BUZZER note duration interrupts to avoid any interference
    NVIC_DisableIRQ(TIM2_IRQn);

    // Check that the BUZZER timer for note duration is enabled in RCC
    uint32_t tim_note_dur_rcc = (RCC->APB1ENR) & RCC_APB1ENR_TIM2EN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(RCC_APB1ENR_TIM2EN_Msk, tim_note_dur_rcc, __LINE__, "ERROR: BUZZER timer for note duration is not enabled in RCC");

    // Check that the BUZZER timer for note duration is disabled
    uint32_t tim_note_dur_en = (BUZZER_TIM_DUR->CR1) & TIM_CR1_CEN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_note_dur_en, __LINE__, "ERROR: BUZZER timer for note duration must be disabled after configuration");

    // Check that the BUZZER timer for note duration is configured with auto-reload preload enabled
    uint32_t tim_note_dur_arpe = (BUZZER_TIM_DUR->CR1) & TIM_CR1_ARPE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CR1_ARPE_Msk, tim_note_dur_arpe, __LINE__, "ERROR: BUZZER timer for note duration must be configured with auto-reload preload enabled");

    // Check that the BUZZER timer for note duration has cleared the update interrupt
    uint32_t tim_note_dur_sr = (BUZZER_TIM_DUR->SR) & TIM_SR_UIF_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_note_dur_sr, __LINE__, "ERROR: BUZZER timer for note duration must have cleared the update interrupt");

    // Check that the BUZZER timer for note duration has cleared the interrupt
    uint32_t tim_note_dur_dier = (BUZZER_TIM_DUR->DIER) & TIM_DIER_UIE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_DIER_UIE_Msk, tim_note_dur_dier, __LINE__, "ERROR: BUZZER timer for note duration must have enabled the interrupt");

    // Check that no other bits other than the needed have been modified:
    uint32_t prev_tim_note_dur_cr1_masked = prev_tim_note_dur_cr1 & ~(TIM_CR1_ARPE_Msk | TIM_CR1_CEN_Msk);
    uint32_t prev_tim_note_dur_dier_masked = prev_tim_note_dur_dier & ~TIM_DIER_UIE_Msk;
    uint32_t prev_tim_note_dur_sr_masked = prev_tim_note_dur_sr & ~TIM_SR_UIF_Msk;

    uint32_t curr_tim_note_dur_cr1_masked = BUZZER_TIM_DUR->CR1 & ~(TIM_CR1_ARPE_Msk | TIM_CR1_CEN_Msk);
    uint32_t curr_tim_note_dur_dier_masked = BUZZER_TIM_DUR->DIER & ~TIM_DIER_UIE_Msk;
    uint32_t curr_tim_note_dur_sr_masked = BUZZER_TIM_DUR->SR & ~TIM_SR_UIF_Msk;

    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_note_dur_cr1_masked, curr_tim_note_dur_cr1_masked, __LINE__, "ERROR: The register CR1 of the BUZZER timer for note duration has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_note_dur_dier_masked, curr_tim_note_dur_dier_masked, __LINE__, "ERROR: The register DIER of the BUZZER timer for note duration has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_note_dur_sr_masked, curr_tim_note_dur_sr_masked, __LINE__, "ERROR: The register SR of the BUZZER timer for note duration has been modified for other bits than the needed");
}

/**
 * @brief Test the configuration of the BUZZER timer for PWM
 *
 */
void test_buzzer_timer_pwm_config(void)
{
    // Retrieve previous configuration
    uint32_t prev_tim_pwm_cr1 = BUZZER_TIM_PWM->CR1;
    uint32_t prev_tim_pwm_ccer = BUZZER_TIM_PWM->CCER;
    uint32_t prev_tim_pwm_ccr1 = BUZZER_TIM_PWM->CCR1;
    uint32_t prev_tim_pwm_ccmr1 = BUZZER_TIM_PWM->CCMR1;
    uint32_t prev_tim_pwm_ccmr2 = BUZZER_TIM_PWM->CCMR2;

    // Call configuration function
    port_buzzer_init(BUZZER_0_ID);

    // Check that the BUZZER timer for PWM is enabled in RCC
    uint32_t tim_pwm_rcc = (RCC->APB1ENR) & RCC_APB1ENR_TIM3EN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(RCC_APB1ENR_TIM3EN_Msk, tim_pwm_rcc, __LINE__, "ERROR: BUZZER timer for PWM is not enabled in RCC");

    // Check that the BUZZER timer for PWM is disabled
    uint32_t tim_pwm_en = (BUZZER_TIM_PWM->CR1) & TIM_CR1_CEN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_pwm_en, __LINE__, "ERROR: BUZZER timer for PWM must be disabled after configuration");

    // Check that the BUZZER timer for PWM is configured with auto-reload preload enabled
    uint32_t tim_pwm_arpe = (BUZZER_TIM_PWM->CR1) & TIM_CR1_ARPE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CR1_ARPE_Msk, tim_pwm_arpe, __LINE__, "ERROR: BUZZER timer for PWM must be configured with auto-reload preload enabled");

    // Cannot check that the BUZZER timer for PWM has set the update generation bit. It is cleared by HW after the update event is generated.

    // Check that the ARR, PSC and CNT are cleared
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, BUZZER_TIM_PWM->ARR, __LINE__, "ERROR: BUZZER timer for PWM ARR must be cleared");
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, BUZZER_TIM_PWM->PSC, __LINE__, "ERROR: BUZZER timer for PWM PSC must be cleared");
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, BUZZER_TIM_PWM->CNT, __LINE__, "ERROR: BUZZER timer for PWM CNT must be cleared");

    // Check that the BUZZER timer for PWM output compare is disabled
    uint32_t tim_pwm_ccer = (BUZZER_TIM_PWM->CCER) & TIM_CCER_CC1E_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_pwm_ccer, __LINE__, "ERROR: BUZZER timer for PWM output compare must be disabled");

    // Check that the BUZZER timer for PWM has configured the PWM mode correctly
    uint32_t tim_pwm_ccmr1 = (BUZZER_TIM_PWM->CCMR1) & (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1);
    UNITY_TEST_ASSERT_EQUAL_UINT32((TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1), tim_pwm_ccmr1, __LINE__, "ERROR: BUZZER timer for PWM has not configured the PWM mode correctly");

    // Check that the BUZZER timer for PWM has configured the preload register correctly
    uint32_t tim_pwm_ccmr1_preload = (BUZZER_TIM_PWM->CCMR1) & TIM_CCMR1_OC1PE_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CCMR1_OC1PE_Msk, tim_pwm_ccmr1_preload, __LINE__, "ERROR: BUZZER timer for PWM has not configured the preload register correctly");

    // Check that no other bits other than the needed have been modified:
    uint32_t prev_tim_pwm_cr1_masked = prev_tim_pwm_cr1 & ~(TIM_CR1_ARPE_Msk | TIM_CR1_CEN_Msk);
    uint32_t prev_tim_pwm_ccer_masked = prev_tim_pwm_ccer & ~TIM_CCER_CC1E_Msk;
    uint32_t prev_tim_pwm_ccr1_masked = prev_tim_pwm_ccr1 & 0xFFFFU;
    uint32_t prev_tim_pwm_ccmr1_masked = prev_tim_pwm_ccmr1 & ~(TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE_Msk);
    uint32_t prev_tim_pwm_ccmr2_masked = prev_tim_pwm_ccmr2 & 0xFFFFU;

    uint32_t curr_tim_pwm_cr1_masked = BUZZER_TIM_PWM->CR1 & ~(TIM_CR1_ARPE_Msk | TIM_CR1_CEN_Msk);
    uint32_t curr_tim_pwm_ccer_masked = BUZZER_TIM_PWM->CCER & ~TIM_CCER_CC1E_Msk;
    uint32_t curr_tim_pwm_ccr1_masked = BUZZER_TIM_PWM->CCR1 & 0xFFFFU;
    uint32_t curr_tim_pwm_ccmr1_masked = BUZZER_TIM_PWM->CCMR1 & ~(TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE_Msk);
    uint32_t curr_tim_pwm_ccmr2_masked = BUZZER_TIM_PWM->CCMR2 & 0xFFFFU;

    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_cr1_masked, curr_tim_pwm_cr1_masked, __LINE__, "ERROR: The register CR1 of the BUZZER timer for PWM has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccer_masked, curr_tim_pwm_ccer_masked, __LINE__, "ERROR: The register CCER of the BUZZER timer for PWM has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccr1_masked, curr_tim_pwm_ccr1_masked, __LINE__, "ERROR: The register CCR1 of the BUZZER timer for PWM has been modified and the duty cycle should not have been configured yet");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccmr1_masked, curr_tim_pwm_ccmr1_masked, __LINE__, "ERROR: The register CCMR1 of the BUZZER timer for PWM has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccmr2_masked, curr_tim_pwm_ccmr2_masked, __LINE__, "ERROR: The register CCMR2 of the BUZZER timer for PWM has been modified and it should not have been changed");
}

/**
 * @brief Test the priority of the BUZZER interrupt
 *
 */
void test_buzzer_timer_note_isr_priority(void)
{
    uint32_t Priority = NVIC_GetPriority(TIM2_IRQn);
    uint32_t PriorityGroup = NVIC_GetPriorityGrouping();
    uint32_t pPreemptPriority;
    uint32_t pSubPriority;

    NVIC_DecodePriority(Priority, PriorityGroup, &pPreemptPriority, &pSubPriority);

    TEST_ASSERT_EQUAL(3, pPreemptPriority);
    TEST_ASSERT_EQUAL(0, pSubPriority);
}

void _test_buzzer_set_note_duration(uint32_t ms_test)
{
    port_buzzer_set_note_duration(BUZZER_0_ID, ms_test);
    uint32_t arr = BUZZER_TIM_DUR->ARR;
    uint32_t psc = BUZZER_TIM_DUR->PSC;
    uint32_t tim_note_dur_ms = round((((double)(arr) + 1.0) / ((double)SystemCoreClock / 1000.0)) * ((double)(psc) + 1));
    sprintf(msg, "ERROR: BUZZER note duration ARR and PSC are not configured correctly for a duration of %ld ms", ms_test);
    UNITY_TEST_ASSERT_INT_WITHIN(1, ms_test, tim_note_dur_ms, __LINE__, msg);
}

/**
 * @brief Test the configuration of the BUZZER note duration
 *
 */
void test_buzzer_set_note_duration()
{
    uint32_t prev_tim_note_dur_cr1 = BUZZER_TIM_DUR->CR1;

    // Check the computation of the ARR and PSC for the BUZZER note duration
    uint32_t ms_test = 1000;
    _test_buzzer_set_note_duration(ms_test);

    ms_test = 268435; // maximum value
    _test_buzzer_set_note_duration(ms_test);

    ms_test = 1; // minimum value
    _test_buzzer_set_note_duration(ms_test);

    // Check that the BUZZER timer for note duration is enabled
    uint32_t tim_note_dur_en = (BUZZER_TIM_DUR->CR1) & TIM_CR1_CEN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CR1_CEN_Msk, tim_note_dur_en, __LINE__, "ERROR: BUZZER timer for note duration must be enabled after setting the note duration");

    // Check that the note_end flag is cleared
    bool note_end = buzzers_arr[BUZZER_0_ID].note_end;
    UNITY_TEST_ASSERT_EQUAL_UINT32(false, note_end, __LINE__, "ERROR: BUZZER note_end flag must be cleared after setting the note duration");

    // Check that no other bits other than the needed have been modified:
    uint32_t prev_tim_note_dur_cr1_masked = prev_tim_note_dur_cr1 & ~TIM_CR1_CEN_Msk;
    uint32_t curr_tim_note_dur_cr1_masked = BUZZER_TIM_DUR->CR1 & ~TIM_CR1_CEN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_note_dur_cr1_masked, curr_tim_note_dur_cr1_masked, __LINE__, "ERROR: The register CR1 of the BUZZER timer for note duration has been modified for other bits than the needed");
}

void _test_buzzer_set_note_frequency(double hz_test)
{
    port_buzzer_set_note_frequency(BUZZER_0_ID, hz_test);

    if (hz_test == 0.0)
    {
        // Check that the BUZZER timer for PWM is disabled
        uint32_t tim_pwm_en = (BUZZER_TIM_PWM->CR1) & TIM_CR1_CEN_Msk;
        UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_pwm_en, __LINE__, "ERROR: BUZZER timer for PWM must be disabled for a frequency of 0 Hz. Please, ensure that no other register has been modified.");
    }
    else
    {
        uint32_t arr = BUZZER_TIM_PWM->ARR;
        uint32_t psc = BUZZER_TIM_PWM->PSC;
        double tim_pwm_hz = (double)(SystemCoreClock) / ((double)(arr) + 1.0) / ((double)(psc) + 1.0);
        sprintf(msg, "ERROR: BUZZER note frequency ARR and PSC are not configured correctly for a frequency of %f Hz", hz_test);
        UNITY_TEST_ASSERT_INT_WITHIN(1, hz_test, tim_pwm_hz, __LINE__, msg);

        // Check that the duty cycle is configured correctly
        uint32_t tim_pwm_ccr1 = BUZZER_TIM_PWM->CCR1;
        uint32_t tim_pwm_dc = (uint32_t)((arr + 1) * BUZZER_PWM_DC);
        UNITY_TEST_ASSERT_UINT32_WITHIN(1, tim_pwm_dc, tim_pwm_ccr1, __LINE__, "ERROR: BUZZER note frequency CCRx is not configured correctly. Duty cycle is not configured correctly.");
    }
}

/**
 * @brief Test the configuration of the BUZZER note frequency
 *
 */
void test_buzzer_set_note_frequency(void)
{
    uint32_t prev_tim_pwm_cr1 = BUZZER_TIM_PWM->CR1;
    uint32_t prev_tim_pwm_ccer = BUZZER_TIM_PWM->CCER;
    uint32_t prev_tim_pwm_ccmr1 = BUZZER_TIM_PWM->CCMR1;
    uint32_t prev_tim_pwm_ccmr2 = BUZZER_TIM_PWM->CCMR2;

    // Check the computation of the ARR and PSC for the BUZZER note frequency
    double hz_test = 0.0; // imposible value
    _test_buzzer_set_note_frequency(hz_test);

    hz_test = 1000.0;
    _test_buzzer_set_note_frequency(hz_test);

    // Maximum frequency
    hz_test = (double)(SystemCoreClock);
    _test_buzzer_set_note_frequency(hz_test);

    hz_test = 0.00373; // minimum value
    _test_buzzer_set_note_frequency(hz_test);

    // Check that the BUZZER timer for PWM is enabled
    uint32_t tim_pwm_en = (BUZZER_TIM_PWM->CR1) & TIM_CR1_CEN_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CR1_CEN_Msk, tim_pwm_en, __LINE__, "ERROR: BUZZER timer for PWM must be enabled after setting the note frequency");

    // Check that the BUZZER timer for PWM output compare is enabled
    uint32_t tim_pwm_ccer = (BUZZER_TIM_PWM->CCER) & TIM_CCER_CC1E_Msk;
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CCER_CC1E_Msk, tim_pwm_ccer, __LINE__, "ERROR: BUZZER timer for PWM output compare must be enabled after setting the note frequency");

    // Check that no other bits other than the needed have been modified:
    uint32_t prev_tim_pwm_cr1_masked = prev_tim_pwm_cr1 & ~TIM_CR1_CEN_Msk;
    uint32_t prev_tim_pwm_ccer_masked = prev_tim_pwm_ccer & ~TIM_CCER_CC1E_Msk;

    uint32_t curr_tim_pwm_cr1_masked = BUZZER_TIM_PWM->CR1 & ~TIM_CR1_CEN_Msk;
    uint32_t curr_tim_pwm_ccer_masked = BUZZER_TIM_PWM->CCER & ~TIM_CCER_CC1E_Msk;
    uint32_t curr_tim_pwm_ccmr1 = BUZZER_TIM_PWM->CCMR1;
    uint32_t curr_tim_pwm_ccmr2 = BUZZER_TIM_PWM->CCMR2;

    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_cr1_masked, curr_tim_pwm_cr1_masked, __LINE__, "ERROR: The register CR1 of the BUZZER timer for PWM has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccer_masked, curr_tim_pwm_ccer_masked, __LINE__, "ERROR: The register CCER of the BUZZER timer for PWM has been modified for other bits than the needed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccmr1, curr_tim_pwm_ccmr1, __LINE__, "ERROR: The register CCMR1 of the BUZZER timer for PWM has been modified and it should not have been changed");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_tim_pwm_ccmr2, curr_tim_pwm_ccmr2, __LINE__, "ERROR: The register CCMR2 of the BUZZER timer for PWM has been modified and it should not have been changed");
}

/**
 * @brief Test the configuration of the BUZZER note timeout
 *
 */
void test_buzzer_note_timeout(void)
{
    // Set the note_end flag to true and check it with a good and wrong buzzer_id
    buzzers_arr[BUZZER_0_ID].note_end = true;
    bool note_end = port_buzzer_get_note_timeout(BUZZER_0_ID);
    UNITY_TEST_ASSERT_EQUAL_UINT32(true, note_end, __LINE__, "ERROR: BUZZER note_end flag must be true after setting the it to true");

    note_end = port_buzzer_get_note_timeout(BUZZER_0_ID + 1);
    UNITY_TEST_ASSERT_EQUAL_UINT32(false, note_end, __LINE__, "ERROR: BUZZER note_end flag must be false for a buzzer_id different form 0");
}

void test_buzzer_stop(void)
{
    // Enable BUZZER timer for note duration and PWM
    BUZZER_TIM_DUR->CR1 |= TIM_CR1_CEN_Msk;
    BUZZER_TIM_PWM->CR1 |= TIM_CR1_CEN_Msk;

    // Call stop function with a wrong buzzer_id
    port_buzzer_stop(BUZZER_0_ID+1);
    uint32_t tim_note_dur_en = (BUZZER_TIM_DUR->CR1) & TIM_CR1_CEN_Msk;
    uint32_t tim_pwm_en = (BUZZER_TIM_PWM->CR1) & TIM_CR1_CEN_Msk;

    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CR1_CEN_Msk, tim_note_dur_en, __LINE__, "ERROR: BUZZER timer for note duration must keep enabled after calling stop function with a buzzer_id different from 0");
    UNITY_TEST_ASSERT_EQUAL_UINT32(TIM_CR1_CEN_Msk, tim_pwm_en, __LINE__, "ERROR: BUZZER timer for PWM must keep enabled after calling stop function with a buzzer_id different from 0");

    // Call stop function with a good buzzer_id
    port_buzzer_stop(BUZZER_0_ID);
    tim_note_dur_en = (BUZZER_TIM_DUR->CR1) & TIM_CR1_CEN_Msk;
    tim_pwm_en = (BUZZER_TIM_PWM->CR1) & TIM_CR1_CEN_Msk;

    UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_note_dur_en, __LINE__, "ERROR: BUZZER timer for note duration must be disabled after calling stop function");
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, tim_pwm_en, __LINE__, "ERROR: BUZZER timer for PWM must be disabled after calling stop function");
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
    RUN_TEST(test_pins);
    RUN_TEST(test_regs);
    RUN_TEST(test_buzzer_timer_note_duration_config);
    RUN_TEST(test_buzzer_timer_note_isr_priority);
    RUN_TEST(test_buzzer_timer_pwm_config);
    RUN_TEST(test_buzzer_set_note_duration);
    RUN_TEST(test_buzzer_set_note_frequency);
    RUN_TEST(test_buzzer_note_timeout);
    RUN_TEST(test_buzzer_stop);
    return UNITY_END();
}
