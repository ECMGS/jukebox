/**
 * @file port_buzzer.c
 * @brief Portable functions to interact with the Buzzer melody player FSM library.
 * @author Eugenio Cano Muñoz
 * @author Jorge Alejandro Estefania Hidalgo
 * @date 06/03/2024
 */
/* Includes ------------------------------------------------------------------*/
/* Standard C libraries */
#include <math.h>
#include "port_buzzer.h"

/* HW dependent libraries */
#include "port_system.h"
#include "port_buzzer.h"
#include "fsm_buzzer.h"
/* Global variables */
port_buzzer_hw_t buzzers_arr[] = {
  [BUZZER_0_ID] = {
  .p_port = BUZZER_0_GPIO,
  .pin = BUZZER_0_PIN,
  .alt_func = BUZZER_0_AF,
  .note_end = BUZZER_0_NOTE_END
  },  
}; 

/* Private functions */
static void _timer_duration_setup(uint32_t buzzer_id)
{
  if (buzzer_id == BUZZER_0_ID)
  {
    // TO-DO alumnos
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->CR1 = 0x0000;
    TIM2->CR1 &= ~TIM_CR1_CEN;

    TIM2->ARR = 39999;

    TIM2->SR = ~TIM_SR_UIF;

    TIM2->DIER |= TIM_DIER_UIE;

    /* Configure interruptions */
    NVIC_SetPriority(TIM2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3GIT, 0)); 
    NVIC_EnableIRQ(TIM2_IRQn);                                                          
  }
}





/* Public functions -----------------------------------------------------------*/



void port_buzzer_init(uint32_t buzzer_id)
{
  port_buzzer_hw_t buzzer = buzzers_arr[buzzer_id];

  

}
