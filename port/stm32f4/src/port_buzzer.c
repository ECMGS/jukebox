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

    TIM2->CR1 |= TIM_CR1_ARPE;

    TIM2->SR = ~TIM_SR_UIF;

    TIM2->DIER |= TIM_DIER_UIE;

    /* Configure interruptions */
    NVIC_SetPriority(TIM2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3, 0)); 
    NVIC_EnableIRQ(TIM2_IRQn);                                                          
  }

}

static void _timer_pwm_setup(uint32_t buzzer_id) {
    if (buzzer_id == BUZZER_0_ID) {
      RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

      TIM3->CR1 = 0x0000;
      TIM3->CR1 &= ~TIM_CR1_CEN;
      TIM3->CR1 |= TIM_CR1_ARPE;

      TIM3->CNT = 0;
      TIM3->ARR = 0;
      TIM3->PSC = 0;

      TIM3->EGR = TIM_EGR_UG;

      TIM3->CCER &= ~TIM_CCER_CC1E;

      TIM3->CCMR1 |= TIM_CCMR1_OC1PE;
      TIM3->CCMR1 |= TIM_AS_PWM1_MASK;
    }
}


/* Public functions -----------------------------------------------------------*/
void port_buzzer_init(uint32_t buzzer_id)
{
  port_buzzer_hw_t buzzer = buzzers_arr[buzzer_id];

  port_system_gpio_config(buzzer.p_port, buzzer.pin, GPIO_MODE_ALTERNATE, GPIO_PUPDR_NOPULL);

  port_system_gpio_config_alternate(buzzer.p_port, buzzer.pin, buzzer.alt_func);

  _timer_duration_setup(buzzer_id);
  _timer_pwm_setup(buzzer_id);
}

void port_buzzer_set_note_duration(uint32_t buzzer_id, uint32_t duration_ms) {
  if (buzzer_id == BUZZER_0_ID) {
    TIM2->CR1 &= ~TIM_CR1_CEN;
    TIM2->CNT = 0;

    double sysclk_as_double = (double) SystemCoreClock;
    double ms_as_double = (double) duration_ms;
    
    double psc_min = (int32_t) ceil((sysclk_as_double*ms_as_double)/((ARR_MAX + 1)*1000)-1);
    double arr_value = ((sysclk_as_double * ms_as_double)/((psc_min + 1) * 1000)-1);

    TIM2->ARR = (int32_t) round(arr_value);
    TIM2->PSC = (int32_t) psc_min;

    TIM2->EGR |= TIM_EGR_UG;

    buzzers_arr[buzzer_id].note_end = false;

    TIM2->CR1 |= TIM_CR1_CEN;
  }
}

bool port_buzzer_get_note_timeout	(	uint32_t 	buzzer_id	)	{
  if (!valid_buzzer(buzzer_id)) {
    printf("El buzzer id proporcionado no es válido");
    return false;
  }
  return buzzers_arr[buzzer_id].note_end;
}

void 	port_buzzer_set_note_frequency (uint32_t buzzer_id, double frequency_hz) {
  if (buzzer_id == BUZZER_0_ID) {

    TIM3->CR1 &= ~TIM_CR1_CEN;

    if (!frequency_hz) {
      return;
    }

    TIM3->CNT = 0;

    TIM3->CCER = TIM_CCER_CC1E;

    double sysclk_as_double = (double) SystemCoreClock;

    double psc_min = ceil((sysclk_as_double/frequency_hz)/(ARR_MAX + 1)-1);
    double arr_value = (sysclk_as_double/frequency_hz)/(psc_min + 1)-1;

    TIM3->ARR = (int32_t) round(arr_value);
    TIM3->PSC = (int32_t) psc_min;

    TIM3->CCR1 = (uint32_t) (BUZZER_PWM_DC * (TIM3->ARR+1));

    TIM3->EGR |= TIM_EGR_UG;

    TIM3->CR1 |= TIM_CCER_CC1E;
    TIM3->CR1 |= TIM_CR1_CEN;
  }
}


void port_buzzer_stop(uint32_t buzzer_id) {
  if (buzzer_id == BUZZER_0_ID) {
    TIM2->CR1 &= ~TIM_CR1_CEN;
    TIM3->CR1 &= ~TIM_CR1_CEN;
  }
}