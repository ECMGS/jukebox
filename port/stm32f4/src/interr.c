/**
 * @file interr.c
 * @brief Interrupt service routines for the STM32F4 platform.
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */
// Include HW dependencies:
#include "port_system.h"

// Include headers of different port elements:
#include "port_button.h"
#include "port_usart.h"
#include "port_buzzer.h"
//------------------------------------------------------
// INTERRUPT SERVICE ROUTINES
//------------------------------------------------------
/**
 * @brief Interrupt service routine for the System tick timer (SysTick).
 *
 * @note This ISR is called when the SysTick timer generates an interrupt.
 * The program flow jumps to this ISR and increments the tick counter by one millisecond.
 *
 * @warning **The variable `msTicks` must be declared volatile!** Just because it is modified by a call of an ISR, in order to avoid [*race conditions*](https://en.wikipedia.org/wiki/Race_condition). **Added to the definition** after *static*.
 *
 */
void SysTick_Handler(void)
{
    uint32_t systemTime = port_system_get_millis();

    port_system_set_millis(systemTime + 1);
}

void EXTI15_10_IRQHandler ()
{
    /* ISR user button */
    if (EXTI->PR & BIT_POS_TO_MASK(buttons_arr[BUTTON_0_ID].pin))
    {
        port_system_systick_resume();
        buttons_arr[BUTTON_0_ID].flag_pressed = !port_system_gpio_read(buttons_arr[BUTTON_0_ID].p_port,buttons_arr[BUTTON_0_ID].pin);
        EXTI->PR = BIT_POS_TO_MASK(buttons_arr[BUTTON_0_ID].pin);
    }
}

void EXTI4_IRQHandler ()
{
    /* ISR user button */
    if (EXTI->PR & BIT_POS_TO_MASK(buttons_arr[BUTTON_1_ID].pin))
    {
        port_system_systick_resume();
        buttons_arr[BUTTON_1_ID].flag_pressed = !port_system_gpio_read(buttons_arr[BUTTON_1_ID].p_port,buttons_arr[BUTTON_1_ID].pin);
        EXTI->PR = BIT_POS_TO_MASK(buttons_arr[BUTTON_1_ID].pin);
    }
}

/**
 * @brief This function handles USART3 global interrupt.
 * First, this function identifies the line/ pin which has raised the interruption. Then, perform the desired action. Before leaving it cleans the interrupt pending register.
 * The program flow jumps to this ISR when the USART3 generates an interrupt. It can be due to:
 * Reception of a new byte (RXNE)
 * Transmission of a byte has finished (TC)
 * Transmission buffer is empty (TXE)
 * 
*/
void 	USART3_IRQHandler (void)
{
    port_system_systick_resume();
    if (USART_SR_RXNE & USART3->SR && USART_CR1_RXNEIE & USART3->CR1){
        port_usart_store_data(USART_0_ID);
    }
    if (USART_SR_TXE & USART3->SR && USART_CR1_TXEIE & USART3->CR1){
        port_usart_write_data(USART_0_ID);
    }
}
/**
 * @brief This function handles TIM2 global interrupt.
*/
void 	TIM2_IRQHandler (void) 
{
    TIM2->SR &= ~TIM_SR_UIF;
    buzzers_arr[BUZZER_0_ID].note_end = true;
}