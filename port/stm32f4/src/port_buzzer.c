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
  .note_end = BUZZER_0_NOTE_END,
  .p_duration_timer = BUZZER_0_DURATION_TIMER,
  .p_frequency_timer = BUZZER_0_FREQUENCY_TIMER
  }, 
  [BUZZER_1_ID] = {
  .p_port = BUZZER_1_GPIO,
  .pin = BUZZER_1_PIN,
  .alt_func = BUZZER_1_AF,
  .note_end = BUZZER_1_NOTE_END,
  .p_duration_timer = BUZZER_1_DURATION_TIMER,
  .p_frequency_timer = BUZZER_1_FREQUENCY_TIMER
  } 
};

/* Private functions */
static void _timer_duration_setup(uint32_t buzzer_id)
{
  if (valid_buzzer(buzzer_id))
  {
    printf("Valid buffer\n");
    // TO-DO alumnos
    RCC->APB1ENR |= get_timer_RCC(buzzer_id);

    buzzers_arr[buzzer_id].p_duration_timer->CR1 = 0x0000;
    buzzers_arr[buzzer_id].p_duration_timer->CR1 &= ~TIM_CR1_CEN;

    buzzers_arr[buzzer_id].p_duration_timer->CR1 |= TIM_CR1_ARPE;

    buzzers_arr[buzzer_id].p_duration_timer->SR = ~TIM_SR_UIF;

    buzzers_arr[buzzer_id].p_duration_timer->DIER |= TIM_DIER_UIE;

    /* Configure interruptions */
    NVIC_SetPriority(get_timer_IRQn(buzzer_id), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3, 0)); 
    NVIC_EnableIRQ(get_timer_IRQn(buzzer_id));                                                          
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
    if (buzzer_id == BUZZER_1_ID) {
      RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

      TIM4->CR1 = 0x0000;
      TIM4->CR1 &= ~TIM_CR1_CEN;
      TIM4->CR1 |= TIM_CR1_ARPE;
      TIM4->CNT = 0;
      TIM4->ARR = 0;
      TIM4->PSC = 0;
      TIM4->EGR = TIM_EGR_UG;
      TIM4->CCER &= ~TIM_CCER_CC1E;
      TIM4->CCMR1 |= TIM_CCMR1_OC1PE;
      TIM4->CCMR1 |= TIM_AS_PWM1_MASK;
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
  if (buzzer_id == BUZZER_1_ID) {
    TIM5->CR1 &= ~TIM_CR1_CEN;
    TIM5->CNT = 0;

    double sysclk_as_double = (double) SystemCoreClock;
    double ms_as_double = (double) duration_ms;
    
    double psc_min = (int32_t) ceil((sysclk_as_double*ms_as_double)/((ARR_MAX + 1)*1000)-1);
    double arr_value = ((sysclk_as_double * ms_as_double)/((psc_min + 1) * 1000)-1);

    TIM5->ARR = (int32_t) round(arr_value);
    TIM5->PSC = (int32_t) psc_min;

    TIM5->EGR |= TIM_EGR_UG;

    buzzers_arr[buzzer_id].note_end = false;

    TIM5->CR1 |= TIM_CR1_CEN;
  }
}

bool port_buzzer_get_note_timeout	(	uint32_t 	buzzer_id	)	{
  if (!valid_buzzer(buzzer_id)) {
    printf("El buzzer id proporcionado no es válido");
    return false;
  }
  return buzzers_arr[buzzer_id].note_end;
}

void 	port_buzzer_set_note_frequency (uint32_t buzzer_id, double frequency_hz, double volume) {
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

    TIM3->CCR1 = (uint32_t) (volume * (TIM3->ARR+1));

    TIM3->EGR |= TIM_EGR_UG;

    TIM3->CR1 |= TIM_CCER_CC1E;
    TIM3->CR1 |= TIM_CR1_CEN;
  }
  if (buzzer_id == BUZZER_1_ID) {

    TIM4->CR1 &= ~TIM_CR1_CEN;

    if (!frequency_hz) {
      return;
    }

    TIM4->CNT = 0;

    TIM4->CCER = TIM_CCER_CC1E;

    double sysclk_as_double = (double) SystemCoreClock;

    double psc_min = ceil((sysclk_as_double/frequency_hz)/(ARR_MAX + 1)-1);
    double arr_value = (sysclk_as_double/frequency_hz)/(psc_min + 1)-1;

    TIM4->ARR = (int32_t) round(arr_value);
    TIM4->PSC = (int32_t) psc_min;

    TIM4->CCR1 = (uint32_t) (volume * (TIM4->ARR+1));

    TIM4->EGR |= TIM_EGR_UG;

    TIM4->CR1 |= TIM_CCER_CC1E;
    TIM4->CR1 |= TIM_CR1_CEN;
  }
}


void port_buzzer_stop(uint32_t buzzer_id) {
  if (buzzer_id == BUZZER_0_ID) {
    TIM2->CR1 &= ~TIM_CR1_CEN;
    TIM3->CR1 &= ~TIM_CR1_CEN;
  }
  if (buzzer_id == BUZZER_1_ID) {
    TIM5->CR1 &= ~TIM_CR1_CEN;
    TIM4->CR1 &= ~TIM_CR1_CEN;
  }
}