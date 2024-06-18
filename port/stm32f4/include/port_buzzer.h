/**
 * @file port_buzzer.h
 * @brief Header for port_buzzer.c file.
 * @author Eugenio Cano Muñoz
 * @author Jorge Alejandro Estefanía Hidalgo
 * @date 6/03/2024
 */
#ifndef PORT_BUZZER_H_
#define PORT_BUZZER_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "port_system.h"
/* HW dependent includes */

#define valid_buzzer(buzz_id) ((buzz_id) == BUZZER_0_ID || BUZZER_1_ID || BUZZER_2_ID)

#define get_timer_duration_IRQn(buzz_id) ((buzz_id) == BUZZER_0_ID) ? TIM2_IRQn : (((buzz_id) == BUZZER_1_ID) ? TIM5_IRQn : TIM7_IRQn)
#define get_timer_duration_RCC(buzz_id) ((buzz_id) == BUZZER_0_ID) ? RCC_APB1ENR_TIM2EN : (((buzz_id) == BUZZER_1_ID) ? RCC_APB1ENR_TIM5EN : RCC_APB1ENR_TIM7EN)
#define get_timer_frequency_RCC(buzz_id) ((buzz_id) == BUZZER_0_ID) ? RCC_APB1ENR_TIM3EN : (((buzz_id) == BUZZER_1_ID) ? RCC_APB1ENR_TIM4EN : RCC_APB1ENR_TIM14EN)

/* Defines and enums ----------------------------------------------------------*/
/* Defines */
#define BUZZER_0_ID 0                         /*!< integer identifyer of the buzzer */
#define BUZZER_0_GPIO GPIOA                   /*!< GPIO port of the buzzer */
#define BUZZER_0_PIN 6                        /*!< GPIO pin of the buzzer */
#define BUZZER_0_AF 2                         /*!< Alternate function for the buzzer*/
#define BUZZER_0_NOTE_END false               /*!< Default value for ending notes*/
#define BUZZER_0_DURATION_TIMER TIM2          /*!< Timer for the duration of the note */
#define BUZZER_0_DURATION_TIMER_IRQ TIM2_IRQn /*!< Timer for the duration of the note */
#define BUZZER_0_FREQUENCY_TIMER TIM3         /*!< Timer for the frequency of the note */

#define BUZZER_1_ID 1                         /*!< integer identifyer of the buzzer */
#define BUZZER_1_GPIO GPIOB                   /*!< GPIO port of the buzzer */
#define BUZZER_1_PIN 6                        /*!< GPIO pin of the buzzer */
#define BUZZER_1_AF 2                         /*!< Alternate function for the buzzer*/
#define BUZZER_1_NOTE_END false               /*!< Default value for ending notes*/
#define BUZZER_1_DURATION_TIMER TIM5          /*!< Timer for the duration of the note */
#define BUZZER_1_DURATION_TIMER_IRQ TIM5_IRQn /*!< Timer for the duration of the note */
#define BUZZER_1_FREQUENCY_TIMER TIM4        /*!< Timer for the frequency of the note */

#define BUZZER_2_ID 2                         /*!< integer identifyer of the buzzer */
#define BUZZER_2_GPIO GPIOA                   /*!< GPIO port of the buzzer */
#define BUZZER_2_PIN 7                        /*!< GPIO pin of the buzzer */
#define BUZZER_2_AF 9                         /*!< Alternate function for the buzzer*/
#define BUZZER_2_NOTE_END false               /*!< Default value for ending notes*/
#define BUZZER_2_DURATION_TIMER TIM7          /*!< Timer for the duration of the note */
#define BUZZER_2_DURATION_TIMER_IRQ TIM7_IRQn /*!< Timer for the duration of the note */
#define BUZZER_2_FREQUENCY_TIMER TIM14         /*!< Timer for the frequency of the note */

#define NUM_BUZZERS 3

// #define BUZZER_PWM_DC     0.5     /*!< Duty cycle of the PWM signal */

#define TIM_AS_PWM1_MASK 0X0060
#define ARR_MAX 0xFFFF

/* Typedefs --------------------------------------------------------------------*/

typedef struct
{
    GPIO_TypeDef *p_port;
    uint8_t pin;
    uint8_t alt_func; // AF2 or AF3
    bool note_end;
    TIM_TypeDef *p_duration_timer;
    TIM_TypeDef *p_frequency_timer;
} port_buzzer_hw_t;

/* Global variables */
extern port_buzzer_hw_t buzzers_arr[];

/* Function prototypes and explanation -------------------------------------------------*/
/**
 * @brief Configure the HW specifications of a given buzzer melody player.
 * @param buzzer_id Buzzer melody player ID. This index is used to select the element of the buzzers_arr[] array
 */
void port_buzzer_init(uint32_t buzzer_id);

/**
 * @brief Set the duration of the timer that controls the duration of the note.
 *
 * @param buzzer_id	Buzzer melody player ID. This index is used to select the element of the buzzers_arr[] array
 * @param duration_ms	Duration of the note in ms
 */
void port_buzzer_set_note_duration(uint32_t buzzer_id, uint32_t duration_ms);

/**
 * @brief Set the PWM frequency of the timer that controls the frequency of the note.
 *
 * @param buzzer_id	Buzzer melody player ID. This index is used to select the element of the buzzers_arr[] array
 * @param frequency_hz	Frequency of the note in Hz
 */
void port_buzzer_set_note_frequency(uint32_t buzzer_id, double frequency_hz, double volume);

/**
 * @brief Retrieve the status of the note end flag.
 *
 * @param buzzer_id	Buzzer melody player ID. This index is used to select the element of the buzzers_arr[] array
 */
bool port_buzzer_get_note_timeout(uint32_t buzzer_id);

/**
 * @brief Disable the PWM output of the timer that controls the frequency of the note and the timer that controls the duration of the note.
 *
 * @param buzzer_id	Buzzer melody player ID. This index is used to select the element of the buzzers_arr[] array
 */
void port_buzzer_stop(uint32_t buzzer_id);

/**
 * @brief Set the volume of the buzzer, changing the PWM duty cycle of the buzzer.
 * 
 * @param buzzer_id	Buzzer melody player ID. This index is used to select the element of the buzzers_arr[] array
 * @param volume	Volume of the buzzer, a double value between 0 and 1.
*/
void port_buzzer_set_volume(uint32_t buzzer_id, double volume);

/**
 * @brief Set the note end flag to true.
*/
void port_buzzer_set_note_end(uint32_t buzzer_id);
#endif