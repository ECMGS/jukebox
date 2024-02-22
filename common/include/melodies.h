/**
 * @file melodies.h
 * @brief Definition of notes and melodies arrays in file `melodies.c`.
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

#ifndef MELODIES_H_
#define MELODIES_H_
/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>

/* Defines and enums ----------------------------------------------------------*/
#define SILENCE 0 /*!< Silence note */

// 3rd Octave (Tercera Octava)
#define DO3 130.813   /*!< DO3 note frequency */
#define DOs3 138.591  /*!< DO#3 note frequency */
#define RE3 146.832   /*!< RE3 note frequency */
#define REs3 155.563  /*!< RE#3 note frequency */
#define MI3 164.814   /*!< MI3 note frequency */
#define FA3 174.614   /*!< FA3 note frequency */
#define FAs3 184.997  /*!< FA#3 note frequency */
#define SOL3 195.998  /*!< SOL3 note frequency */
#define SOLs3 207.652 /*!< SOL#3 note frequency */
#define LA3 220.000   /*!< LA3 note frequency */
#define LAs3 233.082  /*!< LA#3 note frequency */
#define SI3 246.942   /*!< SI3 note frequency */

// 4th Octave (Cuarta Octava)
#define DO4 261.626   /*!< DO4 note frequency */
#define DOs4 277.183  /*!< DO#4 note frequency */
#define RE4 293.665   /*!< RE4 note frequency */
#define REs4 311.127  /*!< RE#4 note frequency */
#define MI4 329.628   /*!< MI4 note frequency */
#define FA4 349.228   /*!< FA4 note frequency */
#define FAs4 369.994  /*!< FA#4 note frequency */
#define SOL4 391.995  /*!< SOL4 note frequency */
#define SOLs4 415.305 /*!< SOL#4 note frequency */
#define LA4 440.000   /*!< LA4 note frequency */
#define LAs4 466.164  /*!< LA#4 note frequency */
#define SI4 493.883   /*!< SI4 note frequency */

// 5th Octave (Quinta Octava)
#define DO5 523.251   /*!< DO5 note frequency */
#define DOs5 554.365  /*!< DO#5 note frequency */
#define RE5 587.330   /*!< RE5 note frequency */
#define REs5 622.254  /*!< RE#5 note frequency */
#define MI5 659.255   /*!< MI5 note frequency */
#define FA5 698.456   /*!< FA5 note frequency */
#define FAs5 739.989  /*!< FA#5 note frequency */
#define SOL5 783.991  /*!< SOL5 note frequency */
#define SOLs5 830.609 /*!< SOL#5 note frequency */
#define LA5 880.000   /*!< LA5 note frequency */
#define LAs5 932.328  /*!< LA#5 note frequency */
#define SI5 987.767   /*!< SI5 note frequency */

/* Typedefs --------------------------------------------------------------------*/
/**
 * @brief Structure to define the Buzzer melody player FSM.
 */
typedef struct
{
    char *p_name;           /*!< Pointer to the name of the melody to play */
    double *p_notes;        /*!< Pointer to the notes of the melody */
    uint16_t *p_durations;  /*!< Pointer to the duration of each note of the melody in milliseconds */
    uint16_t melody_length; /*!< Length of the melody to play */
} melody_t;

// Melodies must be defined in melodies.c, and declared here as extern
// Scale melody
extern const melody_t scale_melody; 

// Melody Happy Birthday
extern const melody_t happy_birthday_melody;

// Tetris melody
extern const melody_t tetris_melody;

#endif /* MELODIES_H_ */