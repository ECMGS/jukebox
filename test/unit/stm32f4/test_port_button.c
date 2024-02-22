#include <unity.h>
#include "port_button.h"
#include "port_system.h"
#include "stm32f4xx.h"

void setUp(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

void tearDown(void)
{
    RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN;
}

void test_identifiers(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(0, BUTTON_0_ID, __LINE__, "ERROR: BUTTON_0_ID must be 0");
}

void test_pins(void)
{
    UNITY_TEST_ASSERT_EQUAL_INT(GPIOC, BUTTON_0_GPIO, __LINE__, "ERROR: BUTTON_0 GPIO must be GPIOC");
    UNITY_TEST_ASSERT_EQUAL_INT(13, BUTTON_0_PIN, __LINE__, "ERROR: BUTTON_0 pin must be 13");
}

void _test_regs(void)
{
    // Retrieve previous configuration
    uint32_t prev_gpio_mode = BUTTON_0_GPIO->MODER;
    uint32_t prev_gpio_pupd = BUTTON_0_GPIO->PUPDR;

    // Call configuration function
    port_button_init(BUTTON_0_ID);

    // Check that the mode is configured correctly
    uint32_t button_mode = ((BUTTON_0_GPIO->MODER) >> (BUTTON_0_PIN * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_MODE_IN, button_mode, __LINE__, "ERROR: Button mode is not configured as input");

    // Check that the pull up/down is configured correctly
    uint32_t button_pupd = ((BUTTON_0_GPIO->PUPDR) >> (BUTTON_0_PIN * 2)) & 0x3;
    UNITY_TEST_ASSERT_EQUAL_UINT32(GPIO_PUPDR_NOPULL, button_pupd, __LINE__, "ERROR: Button pull up/down is not configured as no pull up/down");

    // Check that no other pins other than the needed have been modified:
    uint32_t mask = ~(0x3 << (BUTTON_0_PIN * 2));
    uint32_t prev_gpio_mode_masked = prev_gpio_mode & mask;
    uint32_t prev_gpio_pupd_masked = prev_gpio_pupd & mask;

    uint32_t curr_gpio_mode_masked = BUTTON_0_GPIO->MODER & mask;
    uint32_t curr_gpio_pupd_masked = BUTTON_0_GPIO->PUPDR & mask;
    
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_mode_masked, curr_gpio_mode_masked, __LINE__, "ERROR: GPIO MODE has been modified for other pins than the button");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_pupd_masked, curr_gpio_pupd_masked, __LINE__, "ERROR: GPIO PUPD has been modified for other pins than the button");    
}

void test_regs(void)
{
    GPIOC->MODER = ~0;
    GPIOC->PUPDR = ~0;
    _test_regs();
    GPIOC->MODER = 0;
    GPIOC->PUPDR = 0;
    _test_regs();
}

void _test_exti(void)
{
    // Retrieve previous configuration
    uint32_t prev_gpio_exticr = SYSCFG->EXTICR[BUTTON_0_PIN / 4];
    uint32_t prev_gpio_rtsr = EXTI->RTSR;
    uint32_t prev_gpio_ftsr = EXTI->FTSR;
    uint32_t prev_gpio_emr = EXTI->EMR;
    uint32_t prev_gpio_imr = EXTI->IMR;

    // Call configuration function
    port_button_init(BUTTON_0_ID);

    // Check that the EXTI CR is configured correctly (EXTI both edges)
    uint32_t button_exticr = ((SYSCFG->EXTICR[BUTTON_0_PIN / 4]) >> ((BUTTON_0_PIN % 4) * 4)) & 0xF;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0x2, button_exticr, __LINE__, "ERROR: Button EXTI CR is not configured correctly");

    // Check that the EXTI RTSR is configured correctly (Rising edge)
    uint32_t button_rtsr = ((EXTI->RTSR) >> BUTTON_0_PIN) & 0x1;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0x1, button_rtsr, __LINE__, "ERROR: Button EXTI RTSR is not configured correctly. It must be both rising and falling edge.");
    
    // Check that the EXTI FTSR is configured correctly (Falling edge)
    uint32_t button_ftsr = ((EXTI->FTSR) >> BUTTON_0_PIN) & 0x1;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0x1, button_ftsr, __LINE__, "ERROR: Button EXTI FTSR is not configured correctly. It must be both rising and falling edge.");

    // Check that the EXTI EMR is configured correctly (Event)
    uint32_t button_emr = ((EXTI->EMR) >> BUTTON_0_PIN) & 0x1;
    UNITY_TEST_ASSERT_EQUAL_UINT32(0, button_emr, __LINE__, "ERROR: Button EXTI EMR is not configured correctly. It should not be in event mode.");

    // Check that the EXTI IMR is configured correctly (Interrupt)
    uint32_t button_imr = ((EXTI->IMR) >> BUTTON_0_PIN) & 0x1;
    UNITY_TEST_ASSERT_EQUAL_UINT32(1, button_imr, __LINE__, "ERROR: Button EXTI IMR is not configured correctly. It must be in interrupt mode.");

    // Check that no other pins other than the needed have been modified:
    uint32_t mask_exticr = ~(0xF << ((BUTTON_0_PIN % 4) * 4));
    uint32_t prev_gpio_exticr_masked = prev_gpio_exticr & mask_exticr;
    uint32_t curr_gpio_exticr_masked = SYSCFG->EXTICR[BUTTON_0_PIN / 4] & mask_exticr;
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_exticr_masked, curr_gpio_exticr_masked, __LINE__, "ERROR: EXTI CR has been modified for other ports than the button");

    uint32_t prev_gpio_rtsr_masked = prev_gpio_rtsr & ~(0x1 << BUTTON_0_PIN);
    uint32_t prev_gpio_ftsr_masked = prev_gpio_ftsr & ~(0x1 << BUTTON_0_PIN);
    uint32_t curr_gpio_rtsr_masked = EXTI->RTSR & ~(0x1 << BUTTON_0_PIN);
    uint32_t curr_gpio_ftsr_masked = EXTI->FTSR & ~(0x1 << BUTTON_0_PIN);
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_rtsr_masked, curr_gpio_rtsr_masked, __LINE__, "ERROR: EXTI RTSR has been modified for other ports than the button");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_ftsr_masked, curr_gpio_ftsr_masked, __LINE__, "ERROR: EXTI FTSR has been modified for other ports than the button");

    uint32_t prev_gpio_emr_masked = prev_gpio_emr & ~(0x1 << BUTTON_0_PIN);
    uint32_t prev_gpio_imr_masked = prev_gpio_imr & ~(0x1 << BUTTON_0_PIN);
    uint32_t curr_gpio_emr_masked = EXTI->EMR & ~(0x1 << BUTTON_0_PIN);
    uint32_t curr_gpio_imr_masked = EXTI->IMR & ~(0x1 << BUTTON_0_PIN);
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_emr_masked, curr_gpio_emr_masked, __LINE__, "ERROR: EXTI EMR has been modified for other ports than the button");
    UNITY_TEST_ASSERT_EQUAL_UINT32(prev_gpio_imr_masked, curr_gpio_imr_masked, __LINE__, "ERROR: EXTI IMR has been modified for other ports than the button");
}

void test_exti(void)
{
    SYSCFG->EXTICR[BUTTON_0_PIN / 4] = ~0;
    EXTI->RTSR = ~0;
    EXTI->FTSR = ~0;
    EXTI->EMR = ~0;
    EXTI->IMR = ~0;
    _test_exti();
    EXTI->RTSR = 0;
    EXTI->FTSR = 0;
    EXTI->EMR = 0;
    EXTI->IMR = 0;
    SYSCFG->EXTICR[BUTTON_0_PIN / 4] = 0;
    _test_exti();
}

void test_exti_priority(void) {
    uint32_t Priority = NVIC_GetPriority(EXTI15_10_IRQn);
    uint32_t PriorityGroup = NVIC_GetPriorityGrouping();
    uint32_t pPreemptPriority;
    uint32_t pSubPriority;

    NVIC_DecodePriority(Priority, PriorityGroup, &pPreemptPriority, &pSubPriority);

    TEST_ASSERT_EQUAL(1, pPreemptPriority);
    TEST_ASSERT_EQUAL(0, pSubPriority);
}

int main(void)
{
    port_system_init();
    UNITY_BEGIN();
    RUN_TEST(test_identifiers);    
    RUN_TEST(test_pins);
    RUN_TEST(test_regs);
    RUN_TEST(test_exti);
    RUN_TEST(test_exti_priority);
    return UNITY_END();
}
