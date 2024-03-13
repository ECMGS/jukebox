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
#include "fsm_usart.h"
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

void _reset_buffer(char *p_buffer, uint32_t length){
    memset(p_buffer, EMPTY_BUFFER_CONSTANT, length);
}

/* Public functions */

//test  uint32_t usart3_rcc = (RCC->APB1ENR) & RCC_APB1ENR_USART3EN_Msk;
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
        //RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN;// estaba mal el iniciar el reloj de gpiob. con esto ya funciona
    }
    
    


    p_usart->CR1 &= ~USART_CR1_UE; // Disable USART

    p_usart->CR1 &= ~USART_CR1_M; // 8 bits
    p_usart->CR2 &= ~USART_CR2_STOP; // 1 stop bit
    p_usart->CR1 &= ~USART_CR1_PCE; // Parity disabled
    p_usart->CR1 &= ~USART_CR1_OVER8; // Oversampling by 16
    
    //p_usart->BRR = 0b0000011010000011;   // Actual value 16MHz/(8x2x96000) = 104.1667 aprox 104,(12.5)
    uint32_t div_int = SystemCoreClock / (8*2*9600);
    uint8_t div_dec = (
        ((SystemCoreClock << 5) / (8*2*9600))+1 // TODO: MEJORA V5 PER
    )>>1 & 0xf;
    p_usart->BRR = (div_int << 4) | div_dec;
    // especial mencion a esta parte, tremendo leño
    p_usart->CR1 |= USART_CR1_TE | USART_CR1_RE;
    p_usart->CR1 &= ~USART_CR1_RXNEIE; // esto estaba al revés, habilitando interrupciones de recepción en lugar de deshabilitandolas
    
    p_usart->CR1 &= ~(USART_CR1_TXEIE | USART_CR1_TCIE);

    // Enable USART interrupts globally
    if (p_usart == usart_arr[usart_id].p_usart)
    {
        NVIC_SetPriority(USART3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0));
        NVIC_EnableIRQ(USART3_IRQn);
    }

    p_usart->CR1 |= USART_CR1_UE; //habilitar usart
    
    _reset_buffer(usart_arr[USART_0_ID].input_buffer, USART_INPUT_BUFFER_LENGTH);
    _reset_buffer(usart_arr[USART_0_ID].output_buffer, USART_OUTPUT_BUFFER_LENGTH);
}

void port_usart_get_from_input_buffer (uint32_t usart_id, char *p_buffer){
    memcpy(p_buffer, usart_arr[usart_id].input_buffer, USART_INPUT_BUFFER_LENGTH);
}

bool port_usart_get_txr_status (uint32_t usart_id){
    return USART_SR_TXE & usart_arr[usart_id].p_usart->SR;
}

void port_usart_copy_to_output_buffer (uint32_t usart_id, char *p_data, uint32_t length){
    memcpy(usart_arr[usart_id].output_buffer, p_data, USART_OUTPUT_BUFFER_LENGTH);
}

void port_usart_reset_input_buffer(uint32_t usart_id){
    _reset_buffer(usart_arr[usart_id].input_buffer, USART_INPUT_BUFFER_LENGTH);
    usart_arr[usart_id].read_complete = false;
}	

void port_usart_reset_output_buffer(uint32_t usart_id){
    _reset_buffer(usart_arr[usart_id].output_buffer, USART_OUTPUT_BUFFER_LENGTH);
    usart_arr[usart_id].write_complete = false;
}

bool port_usart_rx_done (uint32_t usart_id){
    return usart_arr[usart_id].read_complete;
}

bool port_usart_tx_done (uint32_t usart_id){
    return usart_arr[usart_id].write_complete;
}

void port_usart_store_data(uint32_t usart_id){
    if (usart_arr[usart_id].p_usart->DR == END_CHAR_CONSTANT) //TODO: DONE MEJORA V5 PER soporte varias usart
    {
        usart_arr[usart_id].read_complete = true;
        usart_arr[usart_id].i_idx = 0;
        return;
    }
    if (usart_arr[usart_id].i_idx >= USART_INPUT_BUFFER_LENGTH){
        usart_arr[usart_id].i_idx = 0;
    }
    usart_arr[usart_id].input_buffer[usart_arr[usart_id].i_idx] = usart_arr[usart_id].p_usart->DR;
    usart_arr[usart_id].i_idx++;
}

void port_usart_write_data(uint32_t usart_id){
    if (usart_arr[usart_id].o_idx == USART_OUTPUT_BUFFER_LENGTH - 1 || 
        usart_arr[usart_id].output_buffer[usart_arr[usart_id].o_idx] == END_CHAR_CONSTANT)
    {  //TODO: DONE MEJORA V5 PER varias usart
       usart_arr[usart_id].p_usart->DR = usart_arr[usart_id].output_buffer[usart_arr[usart_id].o_idx]; 
       port_usart_disable_tx_interrupt(usart_id);
       usart_arr[usart_id].o_idx = 0;
       usart_arr[usart_id].write_complete = true;
       return;
    } else if (usart_arr[usart_id].output_buffer[usart_arr[usart_id].o_idx] != EMPTY_BUFFER_CONSTANT){
        usart_arr[usart_id].p_usart->DR = usart_arr[usart_id].output_buffer[usart_arr[usart_id].o_idx];
        usart_arr[usart_id].o_idx++;
    }
    return;
}

void port_usart_enable_rx_interrupt(uint32_t usart_id){
    usart_arr[usart_id].p_usart->CR1 |= USART_CR1_RXNEIE; //TODO: DONE MEJORA V5 PER varias usart
}

void port_usart_enable_tx_interrupt(uint32_t usart_id){
    usart_arr[usart_id].p_usart->CR1 |= USART_CR1_TXEIE; //TODO: DONE MEJORA V5 PER varias usart
}

void port_usart_disable_rx_interrupt(uint32_t usart_id){
    usart_arr[usart_id].p_usart->CR1 &= ~USART_CR1_RXNEIE; //TODO: DONE MEJORA V5 PER varias usart
}

void port_usart_disable_tx_interrupt(uint32_t usart_id){
    usart_arr[usart_id].p_usart->CR1 &= ~USART_CR1_TXEIE; //TODO: DONE MEJORA V5 PER varias usart
}