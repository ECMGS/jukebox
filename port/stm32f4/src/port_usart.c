/**
 * @file port_usart.c
 * @brief Portable functions to interact with the USART FSM library.
 * @author Jorge Estefanía Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 28/02/2024
 */
/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */

/* HW dependent libraries */
#include "port_usart.h"
#include "port_system.h"

/* Global variables */
port_usart_hw_t usart_arr[] = {
    [USART_0_ID] = {
        .p_usart =  USART_0, 
        .p_port_tx = USART_0_GPIO_TX,
        .p_port_rx = USART_0_GPIO_RX,
        .pin_tx = USART_0_PIN_TX,
        .pin_rx = USART_0_PIN_RX,
        .alt_func_tx = USART_0_AF_TX,
        .alt_func_rx = USART_0_AF_RX,
        .i_idx = 0,
        .read_complete = false,
        .o_idx = 0,
        .write_complete = false
    },
};

/* Private functions */



/* Public functions */


void port_usart_init(uint32_t usart_id)
{
    USART_TypeDef *p_usart = usart_arr[usart_id].p_usart;
    GPIO_TypeDef *p_port_tx = usart_arr[usart_id].p_port_tx;
    GPIO_TypeDef *p_port_rx = usart_arr[usart_id].p_port_rx;
    uint8_t pin_tx = usart_arr[usart_id].pin_tx;
    uint8_t pin_rx = usart_arr[usart_id].pin_rx;
    uint8_t alt_func_tx = usart_arr[usart_id].alt_func_tx;
    uint8_t alt_func_rx = usart_arr[usart_id].alt_func_rx;

    /* TO-DO alumnos: */
    port_system_gpio_config(p_port_tx, pin_tx, GPIO_MODE_ALTERNATE, GPIO_PUPDR_PUP);
    port_system_gpio_config(p_port_rx, pin_rx, GPIO_MODE_ALTERNATE, GPIO_PUPDR_PUP);

    port_system_gpio_config_alternate(p_port_tx, pin_tx, alt_func_tx);
    port_system_gpio_config_alternate(p_port_rx, pin_rx, alt_func_rx);

    if (p_port_tx == GPIOB) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    }

    p_usart->CR1 &= ~USART_CR1_UE;
    p_usart->CR1 &= ~USART_CR1_M;
    p_usart->CR2 &= ~USART_CR2_STOP;
    p_usart->CR1 &= ~USART_CR1_PCE;
    p_usart->CR1 &= ~USART_CR1_OVER8;
    
    //p_usart->BRR = 0b0000011010000011;   // Actual value 16MHz/(8x2x96000) = 104.1667 aprox 104,(12.5)
    uint32_t div_int = SystemCoreClock / (8*2*9600);
    uint8_t div_dec = (
        ((SystemCoreClock << 5) / (8*2*9600))+1 // TODO: MEJORA V5 PER
    )>>1 & 0xf;
    p_usart->BRR = (div_int << 4) | div_dec;

    p_usart->CR1 |= USART_CR1_TE | USART_CR1_RE;
    p_usart->CR1 |= USART_CR1_RXNEIE;
    p_usart->CR1 &= ~(USART_CR1_TXEIE | USART_CR1_TCIE);

    // Enable USART interrupts globally
    if (p_usart == USART3)
    {
        NVIC_SetPriority(USART3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0));
        NVIC_EnableIRQ(USART3_IRQn);
    }

    p_usart->CR1 |= USART_CR1_UE;

    _reset_buffer(usart_arr[USART_0_ID].input_buffer, USART_INPUT_BUFFER_LENGTH);
    _reset_buffer(usart_arr[USART_0_ID].output_buffer, USART_OUTPUT_BUFFER_LENGTH);
}