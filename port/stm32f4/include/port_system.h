/**
 * @file port_system.h
 * @brief Header for port_system.c file.
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

#ifndef PORT_SYSTEM_H_
#define PORT_SYSTEM_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* HW dependent includes */
#include "stm32f4xx.h"

/* Defines and enums ----------------------------------------------------------*/
/* Defines */
#define BIT_POS_TO_MASK(x) (0x01 << (x))                                                                /*!< Convert the index of a bit into a mask by left shifting */
#define BASE_MASK_TO_POS(m, p) ((m) << (p))                                                             /*!< Move a mask defined in the LSBs to upper positions by shifting left p bits */
#define GET_PIN_IRQN(pin) (pin >= 10 ? EXTI15_10_IRQn : (pin >= 5 ? EXTI9_5_IRQn : (EXTI0_IRQn + pin))) /*!< Compute the IRQ number associated to a GPIO pin */

/* Microcontroller STM32F446RE */
/* Timer configuration */
#define RCC_HSI_CALIBRATION_DEFAULT 0x10U            /*!< Default HSI calibration trimming value */
#define TICK_FREQ_1KHZ 1U                            /*!< Freqency in kHz of the System tick */
#define NVIC_PRIORITY_GROUP_0 ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority, \
                                                         4 bits for subpriority */
#define NVIC_PRIORITY_GROUP_4 ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority, \
                                                         0 bit  for subpriority */

/* Power */
#define POWER_REGULATOR_VOLTAGE_SCALE3 0x01 /*!< Scale 3 mode: the maximum value of fHCLK is 120 MHz. */

/* GPIOs */
#define HIGH true /*!< Logic 1 */
#define LOW false /*!< Logic 0 */

#define GPIO_MODE_IN 0x00        /*!< GPIO as input */
#define GPIO_MODE_OUT 0x01       /*!< GPIO as output */
#define GPIO_MODE_ALTERNATE 0x02 /*!< GPIO as alternate function */
#define GPIO_MODE_ANALOG 0x03    /*!< GPIO as analog */

#define GPIO_PUPDR_NOPULL 0x00 /*!< GPIO no pull up or down */
#define GPIO_PUPDR_PUP 0x01    /*!< GPIO pull up */
#define GPIO_PUPDR_PDOWN 0x02  /*!< GPIO pull down */

/* Interruption */
#define TRIGGER_RISING_EDGE 0x01U                                      /*!< Interrupt mask for detecting rising edge */
#define TRIGGER_FALLING_EDGE 0x02U                                     /*!< Interrupt mask for detecting falling edge */
#define TRIGGER_BOTH_EDGE (TRIGGER_RISING_EDGE | TRIGGER_FALLING_EDGE) /*!< Interrupt mask for detecting both rising and falling edges */
#define TRIGGER_ENABLE_EVENT_REQ 0x04U                                 /*!< Interrupt mask to enable event requests */
#define TRIGGER_ENABLE_INTERR_REQ 0x08U                                /*!< Interrupt mask to enable interrupt request */

/* Function prototypes and explanation -------------------------------------------------*/

/**
 * @brief  This function is based on the initialization of the HAL Library; it must be the first
 *         thing to be executed in the main program (before to call any other
 *          functions), it performs the following:
 *           - Configure the Flash prefetch, instruction and Data caches.
 *           - Configures the SysTick to generate an interrupt each 1 millisecond, which is clocked by the HSI (at this stage, the clock is not yet configured and thus the system is running from the internal HSI at 16 MHz).
 *           - Set NVIC Group Priority to 4.
 *             NVIC_PRIORITYGROUP_4: 4 bits for preemption priority
 *                                    0 bits for subpriority
 *           - Configure the system clock
 *
 * @note   SysTick is used as time base for the delay functions. When using the HAL, the application
 *         needs to ensure that the SysTick time base is always set to 1 millisecond
 *         to have correct HAL operation.
 *    When the NVIC_PRIORITYGROUP_0 is selected, IRQ preemption is no more possible.
 *         The pending IRQ priority will be managed only by the subpriority.
 * @retval Init status
 */
size_t port_system_init(void);

/**
 * @brief Get the count of the System tick in milliseconds
 *
 * > **TO-DO alumnos:**
 * >
 * > ✅ 1. Return System tick \n
 *
 * @return uint32_t
 */
uint32_t port_system_get_millis(void);

/**
 * @brief Sets the number of milliseconds since the system started.
 * @warning This function must be used only by the SysTick_Handler() ISR in file `interr.c`.
 *
 * > **TO-DO alumnos:**
 * >
 * > ✅ 1. Set System tick to the value received \n
 * 
 * @param ms New number of milliseconds since the system started.
º */
void port_system_set_millis(uint32_t ms);

/**
 * @brief Wait for some milliseconds
 *
 * @param ms Number of milliseconds to wait
 *
 * @retval None
 */
void port_system_delay_ms(uint32_t ms);

/**
 * @brief Wait for some milliseconds from a time reference.
 *
 * @note It also updates the time reference to the system time at return.
 *
 * @param p_t Pointer to the time reference
 * @param ms Number of milliseconds to wait
 *
 * @retval None
 */
void port_system_delay_until_ms(uint32_t *p_t, uint32_t ms);

/** @verbatim
      ==============================================================================
                              ##### How to use GPIOs #####
      ==============================================================================
      [..]
        (#) Enable the GPIO AHB clock using the RCC->AHB1ENR register.

        (#) Configure the GPIO pin.
            (++) Configure the IO mode.
            (++) Activate Pull-up, Pull-down resistor.
            (++) In case of Output or alternate function mode, configure the speed if needed.
            (++) Configure digital or analog mode.
            (++) In case of external interrupt/event select the type (interrupt or event) and
                 the corresponding trigger event (rising or falling or both).

        (#) In case of external interrupt/event mode selection, configure NVIC IRQ priority
            mapped to the EXTI line and enable it using.

        (#) To get the level of a pin configured in input mode use the GPIOx_IDR register.

        (#) To set/reset the level of a pin configured in output mode use the GPIOx_BSRR register
            to SET (bits 0..15) or RESET (bits 16..31) the GPIO.

        @endverbatim
      ******************************************************************************
      */
/**
 * @brief Configure the mode and pull of a GPIO
 *
 * > 1. Enable GPIOx clock in AHB1ENR \n
 * > 2. Set mode in MODER \n
 * > 3. Set pull up/down configuration
 *
 * @note This function performs the GPIO Port Clock Enable. It may occur that a port clock is re-enabled,
 *       it does not matter if it was already enabled. *
 * @note This function enables the AHB1 peripheral clock. After reset, the peripheral clock (used for registers
 *       read/write access) is disabled and the application software has to enable this clock before using it.
 *
 * @param p_port Port of the GPIO (CMSIS struct like)
 * @param pin Pin/line of the GPIO (index from 0 to 15)
 * @param mode Input, output, alternate, or analog
 * @param pupd Pull-up, pull-down, or no-pull
 *
 * @retval None
 */
void port_system_gpio_config(GPIO_TypeDef *p_port, uint8_t pin, uint8_t mode, uint8_t pupd);

/**
 * @brief Configure the alternate function of a GPIO
 *
 * > 1. **Create a 4-bit base mask**. \n
 * > 2. Shift left the mask depending on the value of the given **`pin` modulo 8.** \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 The value of `pin` ranges from 0 to 15. The registers GPIOx_AFRH and GPIOx_AFRL implement 8 groups of 4 bits each. In order to use the value of `pin` as index to select the corresponding group of bits, we can use the remainder of the division by 8. \n
 * > 3. Clean and set the bits **as shown in the tutorial document**. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 Clean the corresponding bit on element `0` or `1` of the AFR array (*e.g*, `GPIOA->AFR[0]` for GPIOx_AFRL) \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 Set the given value (`alternate`) of the alternate function, using bit shifting, for example. \n
 * \n
 * > 💡 **You can define your own masks for each alternate function (not recommended), or you can use the macro `BASE_MASK_TO_POS(m, p)` to get the mask of a base mask. Example:** \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;A base mask `m` equals `0x03` (`0b 0000 0011` in binary) can be shifted `p` equals `8` positions `BASE_MASK_TO_POS(0x03, 8)` resulting in `0x300` (`0b 0011 0000 0000` in binary). \n
 *
 * @note The AFR register is a 2-element array representing GPIO alternate function high an low registers (GPIOx_AFRH and GPIOx_AFRL) \n
 * AFRLy: Alternate function selection for port x pin y (y = 0..7) \n
 * AFRHy: Alternate function selection for port x pin y (y = 8..15)
 *
 * @param p_port Port of the GPIO (CMSIS struct like)
 * @param pin Pin/line of the GPIO (index from 0 to 15)
 * @param alternate Alternate function number (values from 0 to 15) according to table of the datasheet: "Table 11. Alternate function".
 *
 * @retval None
 */
void port_system_gpio_config_alternate(GPIO_TypeDef *p_port, uint8_t pin, uint8_t alternate);

/**
 * @brief Configure the external interruption or event of a GPIO
 *
 * > **TO-DO alumnos:**
 * >
 * > ✅ 1. **Enable the System configuration controller clock (SYSCFG).** Enable the SYSCFG by setting the bit SYSCFGEN of the peripheral clock enable register (RCC_APB2ENR). The system configuration controller is used here to manage the external interrupt line connection to the GPIOs. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 As usual, you can access to the register (`APB2ENR`) as element of the structure `RCC`. You can use the macro `RCC_APB2ENR_SYSCFGEN` defined in `stm32f446xx.h` to set the bit. Look for the "RCC_APB2ENR" register in the Reference Manual if you need more information. \n
 * > \n
 * > ✅ 2. **Associate the external interruption line to the given port.** Clean and set the bits **as shown in the tutorial document**. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 Depending on the pin number, use the register SYSCFG_EXTICR1, SYSCFG_EXTICR2, SYSCFG_EXTICR3, or SYSCFG_EXTICR4. The structure `SYSCFG` contains a 4-element array called `EXTICR`; the first element (`EXTICR[0]`) configures the register SYSCFG_EXTICR1, and so on. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 To clean the EXTIx bits, you can create a mask depending on the `pin` value.   \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 To associate the external interruption to the given port, *i.e.* to set the EXTIx bits, you can create another mask depending on the `port` value.   \n
 * > \n
 * > ✅ 3. **Select the direction of the trigger**: rising edge, falling edge, or both, depending on the value of the given `mode`.  \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 If *rising edge*: activate the corresponding bit on the EXTI_RTSR register (element `RTSR`) of the `EXTI` structure. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 If *falling edge*: activate the corresponding bit on the EXTI_FTSR register (element `FTSR`) of the `EXTI` structure. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 If *both*: activate the corresponding bit on both registers. \n
 * > \n
 * > ✅ 4. **Select the interrupt and/or event request**: depending on the  value of the given `mode`.  \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 If *event request* enable: activate the corresponding bit on the EXTI_EMR register (element `EMR`) of the `EXTI` structure. \n
 * > &nbsp;&nbsp;&nbsp;&nbsp;💡 If *interrupt request* enable: activate the corresponding bit on the EXTI_IMR register (element `IMR`) of the `EXTI` structure. \n
 * \n
 * > 💡 **You can define your own masks for each pin value (not recommended), or you can use the `BIT_POS_TO_MASK(pin)` macro to get the mask of a pin.**
 *
 * @warning It is highly recommended to clean the corresponding bit of each register (`RSTR`, `FTSR`, `EMR`, `IMR`) before activating it.
 *
 * @param p_port Port of the GPIO (CMSIS struct like)
 * @param pin Pin/line of the GPIO (index from 0 to 15)
 * @param mode Trigger mode can be a combination (OR) of: (i) direction: rising edge (0x01), falling edge (0x02), (ii)  event request (0x04), or (iii) interrupt request (0x08).
 * @retval None
 */
void port_system_gpio_config_exti(GPIO_TypeDef *p_port, uint8_t pin, uint32_t mode);

/**
 * @brief Enable interrupts of a GPIO line (pin)
 *
 * @param pin Pin/line of the GPIO (index from 0 to 15)
 * @param priority Priority level (from highest priority: 0, to lowest priority: 15)
 * @param subpriority Subpriority level (from highest priority: 0, to lowest priority: 15)
 *
 * @retval None
 */
void port_system_gpio_exti_enable(uint8_t pin, uint8_t priority, uint8_t subpriority);

/**
 * @brief Disable interrupts of a GPIO line (pin)
 *
 * @param pin Pin/line of the GPIO (index from 0 to 15)
 *
 * @retval None
 */
void port_system_gpio_exti_disable(uint8_t pin);

#endif /* PORT_SYSTEM_H_ */
