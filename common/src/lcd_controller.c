/**
 * @file fsm_buzzer.c
 * @brief LCD controller main file.
 * @author Eugenio Cano Muñoz
 * @author Jorge Alejandro Estefania Hidalgo
 * @date 08/05/2024
 */
/* Includes ------------------------------------------------------------------*/
// Standard C includes
#include <string.h> // strcmp
#include <stdio.h>  // sprintf
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Other includes
#include "fsm.h"
#include "fsm_jukebox.h"
#include "fsm_button.h"
#include "fsm_usart.h"
#include "fsm_buzzer.h"

#include "port_system.h"
#include "port_usart.h"

#include "buzzer_director.h"

#include "lcd_controller.h"
#include <liquidcrystal_i2c.h>

I2C_HandleTypeDef hi2c1;

void lcd_on()
{
    HD44780_Clear();
    HD44780_Backlight();
}

void lcd_off()
{
    HD44780_Clear();
    HD44780_NoBacklight();
}

void lcd_update_song(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    HD44780_Clear();
    HD44780_SetCursor(0, 0);
    HD44780_PrintStr(p_fsm->p_melody);
    lcd_update_state(p_this);
    lcd_update_vol(p_this);
}

void lcd_update_vol(fsm_t *p_this)
{
    HD44780_SetCursor(1, 7);
    HD44780_PrintStr("Vol: ");
    HD44780_SetCursor(1, 11);
    if (fsm_buzzer_get_volume(p_this) == 0.5)
    {
        HD44780_PrintStr("HIGH");
    }
    else
    {
        HD44780_PrintStr("LOW");
    }
}

void lcd_update_state(fsm_t *p_this)
{
    HD44780_SetCursor(1, 0);
    if (buzzer_director_get_action() == PLAY)
    {
        HD44780_PrintStr("PLAY");
    }
    else if (buzzer_director_get_action() == PAUSE)
    {
        HD44780_PrintStr("PAUSE");
    }
    else
    {
        HD44780_PrintStr("STOP");
    }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

static void MX_I2C1_Init(void)
{

    /* USER CODE BEGIN I2C1_Init 0 */

    /* USER CODE END I2C1_Init 0 */

    /* USER CODE BEGIN I2C1_Init 1 */

    /* USER CODE END I2C1_Init 1 */
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    if (HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        Error_Handler();
    }
    /* USER CODE BEGIN I2C1_Init 2 */

    /* USER CODE END I2C1_Init 2 */
}

void lcd_init()
{
    MX_I2C1_Init();
    HD44780_Init(2);
    HD44780_NoCursor();
    HD44780_AutoScroll();
    HD44780_Backlight();
    HD44780_Clear();
}