/**
 * @file lcd_controller.h
 * @brief Header for lcd_controller.c file.
 * @author Jorge Lajeandro Estefania Hidalgo
 * @author Eugenio Cano Muñoz
 * @date 08/05/2024
 */
#ifndef LCD_CONTROLLER_H_
#define LCD_CONTROLLER_H_
/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>
#include <fsm.h>
#include <stdlib.h>
/* Other includes */
#include "melodies.h"
/**
 * @brief Turn on lcd backlight
 */
void lcd_on(void);

/**
 * @brief Turn off lcd backlight
 */
void lcd_off(void);

void lcd_update(fsm_t *p_this);

/**
 * @brief Print current song on lcd
 * @param p_this Pointer to an fsm_t struct than contains an fsm_jukebox_t struct
 */
void lcd_update_song(fsm_t *p_this);

/**
 * @brief Print current volume on lcd
 * @param  p_this Pointer to an fsm_t struct than contains an fsm_jukebox_t struct
 */
void lcd_update_vol(fsm_t *p_this);

/**
 * @brief Print current song on lcd
 * @param  p_this Pointer to an fsm_t struct than contains an fsm_jukebox_t struct
 */
void lcd_update_song(fsm_t *p_this);

/**
 * @brief Print the current state on lcd
 * @param  p_this Pointer to an fsm_t struct than contains an fsm_jukebox_t struct
 */
void lcd_update_state(fsm_t *p_this);
/**
 * @brief Initialize the lcd
 */
void lcd_init(void);

#endif /* LCD_CONTROLLER_H_ */