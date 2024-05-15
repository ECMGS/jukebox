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

#include "fsm_lcd.h"
#include <liquidcrystal_i2c.h>

I2C_HandleTypeDef hi2c1;
/* Private functions */
void _set_timeout(fsm_t *p_this)
{
    fsm_lcd_t *p_fsm = (fsm_lcd_t *)(p_this);
    p_fsm->lcd_timeout = port_system_get_millis() + p_fsm->lcd_timeout_ms;
}

void _lcd_init()
{
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
        __disable_irq();
        while (1)
        {
        }
    }
    HD44780_Init(2);
    HD44780_NoBacklight();
    HD44780_Clear();
}

/* State machine input or transition functions */
static bool check_lcd_timeout(fsm_t *p_this)
{
    fsm_lcd_t *p_fsm = (fsm_lcd_t *)(p_this);
    return port_system_get_millis() >= p_fsm->lcd_timeout;
}

static bool check_on(fsm_t *p_this)
{
    fsm_lcd_t *p_fsm = (fsm_lcd_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button) > p_fsm->on_off_press_time_ms;
}

static bool check_off(fsm_t *p_this)
{
    return check_on(p_this);
}

static bool check_melody_finished(fsm_t *p_this)
{
    // fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    // return fsm_buzzer_get_action(p_fsm->p_fsm_buzzer) == STOP;
    return buzzer_director_check_melody_finished();
}

static bool check_next_song_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button) > p_fsm->next_song_press_time_ms;
}

static bool check_play_pause_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_play_pause) > p_fsm->play_pause_press_time_ms;
}

static bool check_volume_button(fsm_t *p_this)
{
    fsm_jukebox_t *p_fsm = (fsm_jukebox_t *)(p_this);
    return fsm_button_get_duration(p_fsm->p_fsm_button_play_pause) > p_fsm->change_volume_press_time_ms;
}

/* State machine output or action functions */

void lcd_start(fsm_t *p_this)
{
    HD44780_Clear();
    HD44780_Backlight();
    HD44780_SetCursor(5, 0);
    HD44780_PrintStr("STARTING");
    HD44780_SetCursor(6, 1);
    HD44780_PrintStr("JUKEBOX");
}

void lcd_off(fsm_t *p_this)
{
    HD44780_Clear();
    HD44780_NoBacklight();
}
void lcd_update_state(fsm_t *p_this)
{
    HD44780_SetCursor(1, 0);
    if (buzzer_director_get_action() == PLAY)
    {
        HD44780_PrintStr("PLAYING SONG ");
    }
    else if (buzzer_director_get_action() == PAUSE)
    {
        HD44780_PrintStr(" SONG PAUSED ");
    }
    else
    {
        HD44780_PrintStr(" SONG ENDED  ");
    }
}

void lcd_update_song(fsm_t *p_this)
{
    fsm_lcd_t *p_fsm = (fsm_lcd_t *)(p_this);
    lcd_update_state(p_this);
    HD44780_SetCursor(0, 1);
    HD44780_PrintStr("                ");
    HD44780_SetCursor(0, 1);
    HD44780_PrintStr(p_fsm->melodies[p_fsm->melody_idx].p_name);
}

void lcd_update(fsm_t *p_this)
{
    HD44780_Clear();
    lcd_update_song(p_this);
}

void lcd_update_vol(fsm_t *p_this)
{
    HD44780_Clear();
    HD44780_SetCursor(1, 0);
    HD44780_PrintStr("VOLUME CHANGED");
    HD44780_SetCursor(3, 1);
    HD44780_PrintStr("TO: ");
    HD44780_SetCursor(7, 1);
    if (fsm_buzzer_get_volume(p_this) <= 0.7)
    {
        HD44780_PrintStr("HIGH");
    }
    else
    {
        HD44780_PrintStr("LOW ");
    }
    _set_timeout(p_this);
}

void lcd_show_off(fsm_t *p_this)
{
    fsm_lcd_t *p_fsm = (fsm_lcd_t *)(p_this);
    HD44780_Clear();
    HD44780_SetCursor(0, 0);
    HD44780_PrintStr("TURNING JUKEBOX");
    HD44780_SetCursor(4, 1);
    HD44780_PrintStr("OFF");
    HAL_Delay(p_fsm->lcd_timeout);
    _set_timeout(p_this);
}

static fsm_trans_t fsm_trans_lcd[] = {
    {OFF, check_on, START_DISPLAY, lcd_start},
    {START_DISPLAY, check_melody_finished, SONG_DISPLAY, lcd_update},
    {SONG_DISPLAY, check_off, OFF_DISPLAY, lcd_show_off},
    {SONG_DISPLAY, check_next_song_button, SONG_DISPLAY, lcd_update_song},
    {SONG_DISPLAY, check_play_pause_button, SONG_DISPLAY, lcd_update_state},
    {SONG_DISPLAY, check_volume_button, VOLUME_DISPLAY, lcd_update_vol},
    {VOLUME_DISPLAY, check_lcd_timeout, SONG_DISPLAY, lcd_update},
    {VOLUME_DISPLAY, check_off, OFF_DISPLAY, lcd_show_off},
    {OFF_DISPLAY, check_lcd_timeout, OFF_LCD, lcd_off},
    {-1, NULL, -1, NULL}};

/* Public Functions */
fsm_t *fsm_lcd_new(fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, uint32_t on_off_press_time_ms, uint32_t play_pause_press_time_ms, uint32_t change_volume_press_time_ms, uint32_t next_song_press_time_ms, uint32_t lcd_timeout_ms)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_lcd_t));
    fsm_init(p_fsm, fsm_trans_lcd);
    fsm_lcd_init(p_fsm, p_fsm_button, p_fsm_button_play_pause, on_off_press_time_ms, play_pause_press_time_ms, change_volume_press_time_ms, next_song_press_time_ms, lcd_timeout_ms);
    return p_fsm;
}

void fsm_lcd_init(fsm_t *p_this, fsm_t *p_fsm_button, fsm_t *p_fsm_button_play_pause, uint32_t on_off_press_time_ms,
                  uint32_t play_pause_press_time_ms, uint32_t change_volume_press_time_ms,
                  uint32_t next_song_press_time_ms, uint32_t lcd_timeout_ms)
{
    fsm_lcd_t *p_fsm = (fsm_lcd_t *)(p_this);
    fsm_init(p_this, p_this->p_tt);
    p_fsm->p_fsm_button = p_fsm_button;
    p_fsm->p_fsm_button_play_pause = p_fsm_button_play_pause;
    p_fsm->on_off_press_time_ms = on_off_press_time_ms;
    p_fsm->next_song_press_time_ms = next_song_press_time_ms;
    p_fsm->play_pause_press_time_ms = play_pause_press_time_ms;
    p_fsm->change_volume_press_time_ms = change_volume_press_time_ms;
    p_fsm->melody_idx = 0;
    memset(p_fsm->melodies, 0, sizeof(p_fsm->melodies));
    p_fsm->lcd_timeout_ms = lcd_timeout_ms;
    _set_timeout(p_this);

    _lcd_init();

    p_fsm->melodies[0] = one_up_melody;
    p_fsm->melodies[1] = nokia;
    p_fsm->melodies[2] = pokemon;
    p_fsm->melodies[3] = star_wars_trumpet;
    p_fsm->melodies[4] = minecraft_1;
    p_fsm->melodies[5] = kerosene;
    p_fsm->melodies[6] = tetris_melody;
    p_fsm->melodies[7] = scale_melody;
    p_fsm->melodies[8] = happy_birthday_melody;
    p_fsm->melodies[9] = mario_death;
}