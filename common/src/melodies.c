/**
 * @file melodies.c
 * @brief Melodies source file.
 * @author Sistemas Digitales II
 * @date 2024-01-01
 */

/* Includes ------------------------------------------------------------------*/
#include "melodies.h"
#include <stddef.h>
/* Melodies ------------------------------------------------------------------*/

#define HAPPY_BIRTHDAY_LENGTH 25 /*!< Happy Birthday melody length */

/**
 * @brief Happy Birthday melody notes.
 *
 * This array contains the frequencies of the notes for the Happy Birthday song.1
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double happy_birthday_notes[HAPPY_BIRTHDAY_LENGTH] = {DO4, DO4, RE4, DO4, FA4, MI4, DO4, DO4, RE4, DO4, SOL4, FA4, DO4, DO4, DO5, LA4, FA4, MI4, RE4, LAs4, LAs4, LA4, FA4, SOL4, FA4};

/**
 * @brief Happy Birthday melody durations in miliseconds.
 *
 * This array contains the duration of each note in the Happy Birthday song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t happy_birthday_durations[HAPPY_BIRTHDAY_LENGTH] = {300, 100, 400, 400, 400, 800, 300, 100, 400, 400, 400, 800, 300, 100, 400, 400, 400, 400, 400, 300, 100, 400, 400, 400, 800};

/**
 * @brief Happy Birthday melody struct.
 *
 * This struct contains the information of the Happy Birthday melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t happy_birthday_melody = {.p_name = "happy_birthday",
                                        .p_notes = (double *)happy_birthday_notes,
                                        .p_durations = (uint16_t *)happy_birthday_durations,
                                        .melody_length = HAPPY_BIRTHDAY_LENGTH,
                                        .next_melody = NULL};

#define TETRIS_LENGTH 40 /*!< Tetris melody length */

/**
 * @brief Tetris melody notes.
 *
 * This array contains the frequencies of the notes for the Tetris song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double tetris_notes[TETRIS_LENGTH] = {MI5, SI4, DO5, RE5, DO5, SI4, LA4, LA4, DO5, MI5, RE5, DO5, SI4, DO5, RE5, MI5, DO5, LA4, LA4, LA4, SI4, DO5, RE5, FA4, LA5, SOL5, FA5, MI5, DO5, MI5, RE5, DO5, SI4, SI4, LA4, RE5, MI5, DO5, LA4, LA4};

/**
 * @brief Tetris melody durations in miliseconds.
 *
 * This array contains the duration of each note in the Tetris song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t tetris_durations[TETRIS_LENGTH] = {400, 200, 200, 400, 200, 200, 400, 200, 200, 400, 200, 200, 600, 200, 400, 400, 400, 400, 200, 200, 200, 200, 600, 200, 400, 200, 200, 600, 200, 400, 200, 200, 400, 200, 200, 400, 400, 400, 400, 400};

/**
 * @brief Tetris melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t tetris_melody = {.p_name = "tetris",
                                .p_notes = (double *)tetris_notes,
                                .p_durations = (uint16_t *)tetris_durations,
                                .melody_length = TETRIS_LENGTH,
                                .next_melody = NULL};

#define SCALE_MELODY_LENGTH 8 /*!< Scale melody length */

/**
 * @brief Scale melody notes.
 *
 * This array contains the frequencies of the notes for the scale song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double scale_melody_notes[SCALE_MELODY_LENGTH] = {DO4, RE4, MI4, FA4, SOL4, LA4, SI4, DO5};

/**
 * @brief Scale melody durations in miliseconds.
 *
 * This array contains the duration of each note in the scale song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t scale_melody_durations[SCALE_MELODY_LENGTH] = {250, 250, 250, 250, 250, 250, 250, 250};

/**
 * @brief Scale melody struct.
 *
 * This struct contains the information of the scale melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t scale_melody = {.p_name = "scale",
                               .p_notes = (double *)scale_melody_notes,
                               .p_durations = (uint16_t *)scale_melody_durations,
                               .melody_length = SCALE_MELODY_LENGTH,
                               .next_melody = NULL};

#define ONE_UP_LENGTH 6

static const double one_up_notes[ONE_UP_LENGTH] = {
    1319, 1568, 2637, 2093, 2349, 3136};

static const uint16_t one_up_durations[ONE_UP_LENGTH] = {
    120, 120, 120, 120, 120, 350};

const melody_t one_up_melody = {.p_name = "one_up_melody",
                                .p_notes = (double *)one_up_notes,
                                .p_durations = (uint16_t *)one_up_durations,
                                .melody_length = ONE_UP_LENGTH,
                                .next_melody = NULL};

#define NOKIA_LENGTH 13

static const double nokia_notes[NOKIA_LENGTH] = {
    659, 587, 370, 415, 554, 494, 294, 330, 494, 440, 277, 330, 440};

static const uint16_t nokia_durations[NOKIA_LENGTH] = {
    125, 125, 250, 250, 125, 125, 250, 250, 125, 125, 250, 250, 500};

const melody_t nokia = {.p_name = "nokia",
                        .p_notes = (double *)nokia_notes,
                        .p_durations = (uint16_t *)nokia_durations,
                        .melody_length = NOKIA_LENGTH,
                        .next_melody = NULL};

#define KEROSENE_BASS_LENGTH 80

static const double kerosene_bass_notes[KEROSENE_BASS_LENGTH] = {
    73, 78, 65, 98, 73, 78, 65, 98, 73, 73, 73, 78, 78, 78, 65, 65, 65, 98, 98, 98, 73, 73, 73, 78, 78, 78, 65, 65, 65, 98, 98, 98, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49};

static const uint16_t kerosene_bass_durations[KEROSENE_BASS_LENGTH] = {
    1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 479};

const melody_t kerosene_bass = {.p_name = "kerosene_bass",
                                .p_notes = (double *)kerosene_bass_notes,
                                .p_durations = (uint16_t *)kerosene_bass_durations,
                                .melody_length = KEROSENE_BASS_LENGTH};

#define KEROSENE_LENGTH 508

static const double kerosene_notes[KEROSENE_LENGTH] = {
    622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440, 622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440, 622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440, 622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440};

static const uint16_t kerosene_durations[KEROSENE_LENGTH] = {
    240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 119};

const melody_t kerosene = {.p_name = "kerosene",
                           .p_notes = (double *)kerosene_notes,
                           .p_durations = (uint16_t *)kerosene_durations,
                           .melody_length = KEROSENE_LENGTH,
                           .next_melody = (const melody_t *)&kerosene_bass};

#define MARIO_DEATH_LENGTH 25

static const double mario_death_notes[MARIO_DEATH_LENGTH] = {
    392, 494, 196, 587, 698, 587, 698, 196, 587, 698, 196, 523, 659, 220, 494, 587, 247, 392, 523, 262, 330, 196, 330, 262, 131};

static const uint16_t mario_death_durations[MARIO_DEATH_LENGTH] = {
    159, 168, 134, 111, 111, 151, 151, 151, 188, 199, 188, 180, 192, 180, 190, 202, 190, 145, 154, 118, 110, 115, 141, 115, 115};

const melody_t mario_death = {
    .p_name = "mario_death",
    .p_notes = (double *)mario_death_notes,
    .p_durations = (uint16_t *)mario_death_durations,
    .melody_length = MARIO_DEATH_LENGTH,
    .next_melody = NULL};

/*--------------STAR WARS ORQUESTA 5 INSTRUMENTOS-----------------*/
/**
 * Chello channel 12
 * Trumpet channel 5
 * Trombone channel 6
 * Drums channel 10
 * Glockenspiel channel 14
 */

#define STAR_WARS_TRUMPET_LENGTH 197

static const double star_wars_trumpet_notes[STAR_WARS_TRUMPET_LENGTH] = {391, 0, 0, 391, 0, 0, 391, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 622, 0, 0, 466, 0, 0, 369, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 783, 0, 0, 391, 0, 0, 391, 0, 0, 783, 0, 0, 739, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 659, 0, 0, 415, 0, 0, 554, 0, 0, 523, 0, 0, 493, 0, 0, 466, 0, 0, 440, 0, 0, 466, 0, 0, 311, 0, 0, 369, 0, 0, 311, 0, 0, 369, 0, 0, 466, 0, 0, 391, 0, 0, 466, 0, 0, 587, 0, 0, 783, 0, 0, 391, 0, 0, 391, 0, 0, 783, 0, 0, 739, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 659, 0, 0, 415, 0, 0, 554, 0, 0, 523, 0, 0, 493, 0, 0, 466, 0, 0, 440, 0, 0, 466, 0, 0, 311, 0, 0, 369, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0};
static const uint16_t star_wars_trumpet_durations[STAR_WARS_TRUMPET_LENGTH] = {309, 3, 188, 321, 3, 168, 285, 3, 160, 242, 2, 100, 71, 1, 60, 376, 4, 108, 206, 2, 160, 71, 1, 52, 626, 6, 324, 321, 3, 148, 317, 3, 172, 313, 3, 164, 210, 2, 136, 63, 1, 60, 301, 3, 168, 253, 3, 104, 79, 1, 52, 578, 6, 388, 289, 3, 160, 174, 2, 216, 75, 1, 36, 321, 3, 156, 246, 2, 124, 79, 1, 24, 83, 1, 28, 71, 1, 24, 154, 2, 344, 83, 1, 168, 356, 4, 116, 293, 3, 64, 83, 1, 44, 83, 1, 32, 79, 1, 44, 67, 1, 412, 87, 1, 144, 337, 3, 132, 297, 3, 72, 67, 1, 56, 329, 3, 152, 238, 2, 112, 63, 1, 60, 665, 7, 292, 289, 3, 160, 174, 2, 216, 75, 1, 36, 321, 3, 156, 246, 2, 124, 79, 1, 24, 83, 1, 28, 71, 1, 24, 154, 2, 344, 83, 1, 168, 356, 4, 116, 293, 3, 64, 83, 1, 44, 83, 1, 32, 79, 1, 44, 67, 1, 412, 87, 1, 144, 337, 3, 132, 297, 3, 72, 67, 1, 56, 329, 3, 152, 238, 2, 112, 63, 1, 60, 665, 7};
const melody_t star_wars_trumpet = {
    .p_name = "star_wars_trumpet",
    .p_notes = (double *)star_wars_trumpet_notes,
    .p_durations = (uint16_t *)star_wars_trumpet_durations,
    .melody_length = STAR_WARS_TRUMPET_LENGTH,
    .next_melody = (const melody_t *)&star_wars_trombone};

#define STAR_WARS_TROMBONE_LENGTH 222

static const double star_wars_trombone_notes[STAR_WARS_TROMBONE_LENGTH] = {195, 0, 0, 195, 0, 0, 195, 0, 0, 155, 0, 0, 233, 0, 0, 195, 0, 0, 155, 0, 0, 233, 0, 0, 195, 0, 0, 293, 0, 0, 293, 0, 0, 293, 0, 0, 311, 0, 0, 233, 0, 0, 184, 0, 0, 155, 0, 0, 233, 0, 0, 195, 0, 0, 391, 0, 0, 195, 0, 0, 195, 0, 0, 391, 0, 0, 369, 0, 0, 349, 0, 0, 329, 0, 0, 311, 0, 0, 329, 0, 0, 207, 0, 0, 277, 0, 0, 261, 0, 0, 246, 0, 0, 233, 0, 0, 220, 0, 0, 233, 0, 0, 155, 0, 0, 184, 0, 0, 155, 0, 0, 184, 0, 0, 233, 0, 0, 195, 0, 0, 233, 0, 0, 293, 0, 0, 391, 0, 0, 195, 0, 0, 195, 0, 0, 391, 0, 0, 369, 0, 0, 349, 0, 0, 329, 0, 0, 311, 0, 0, 329, 0, 0, 207, 0, 0, 277, 0, 207, 0, 0, 207, 0, 261, 0, 0, 246, 0, 207, 0, 0, 0, 184, 0, 233, 0, 0, 220, 0, 174, 0, 0, 0, 184, 0, 233, 0, 0, 155, 0, 0, 184, 0, 0, 0, 0, 155, 0, 184, 0, 233, 0, 0, 233, 0, 0, 195, 0, 0, 0, 155, 0, 184, 0, 233, 0, 0, 233, 0, 0, 195, 0};
static const uint16_t star_wars_trombone_durations[STAR_WARS_TROMBONE_LENGTH] = {265, 3, 200, 289, 3, 192, 297, 3, 164, 230, 2, 136, 55, 1, 64, 337, 3, 128, 230, 2, 140, 67, 1, 44, 602, 6, 348, 301, 3, 180, 297, 3, 172, 309, 3, 184, 206, 2, 140, 75, 1, 56, 337, 3, 128, 198, 2, 148, 67, 1, 68, 578, 6, 364, 368, 4, 116, 238, 2, 132, 91, 1, 32, 297, 3, 136, 257, 3, 132, 79, 1, 24, 111, 1, 44, 79, 1, 12, 103, 1, 388, 91, 1, 152, 313, 3, 164, 257, 3, 100, 83, 1, 40, 91, 1, 16, 71, 1, 52, 103, 1, 384, 79, 1, 156, 285, 3, 204, 269, 3, 88, 59, 1, 72, 317, 3, 136, 265, 3, 92, 63, 1, 68, 598, 6, 324, 368, 4, 116, 238, 2, 132, 91, 1, 32, 297, 3, 136, 257, 3, 132, 79, 1, 24, 111, 1, 44, 79, 1, 12, 103, 1, 388, 91, 1, 152, 313, 3, 8, 0, 156, 210, 2, 48, 0, 100, 63, 1, 8, 0, 40, 8, 79, 1, 4, 0, 24, 71, 1, 8, 0, 44, 4, 91, 1, 8, 0, 388, 79, 1, 156, 285, 3, 180, 8, 4, 269, 3, 20, 0, 24, 0, 52, 59, 1, 52, 321, 3, 136, 8, 265, 3, 4, 0, 8, 0, 104, 63, 1, 44, 135, 1};
const melody_t star_wars_trombone = {
    .p_name = "star_wars_trombone",
    .p_notes = (double *)star_wars_trombone_notes,
    .p_durations = (uint16_t *)star_wars_trombone_durations,
    .melody_length = STAR_WARS_TROMBONE_LENGTH,
    .next_melody = (const melody_t *)&star_wars_glockenspiel};

#define STAR_WARS_GLOCKENSPIEL_LENGTH 107

static const double star_wars_glockenspiel_notes[STAR_WARS_GLOCKENSPIEL_LENGTH] = {8, 0, 0, 8, 0, 0, 8, 0, 0, 8, 0, 0, 8, 0, 0, 0, 0, 0, 8, 0, 0, 8, 0, 0, 8, 0, 0, 8, 0, 0, 8, 0, 0, 8, 0, 0, 1567, 0, 0, 783, 0, 0, 783, 0, 0, 1567, 0, 0, 1479, 0, 0, 1396, 0, 0, 1318, 0, 0, 1244, 0, 0, 1318, 0, 0, 830, 0, 0, 1108, 0, 0, 1046, 0, 0, 987, 0, 0, 932, 0, 0, 880, 0, 0, 932, 0, 0, 622, 0, 0, 739, 0, 0, 622, 0, 0, 932, 0, 0, 783, 0, 0, 622, 0, 0, 932, 0, 0, 783, 0};
static const uint16_t star_wars_glockenspiel_durations[STAR_WARS_GLOCKENSPIEL_LENGTH] = {238, 950, 960, 238, 2, 720, 238, 2, 1440, 238, 2, 960, 238, 2, 1440, 238, 2, 1200, 238, 2, 960, 238, 2, 960, 238, 2, 960, 238, 2, 960, 238, 2, 960, 238, 2, 100, 99, 1, 380, 103, 1, 256, 55, 1, 68, 79, 1, 380, 83, 1, 312, 83, 1, 28, 95, 1, 32, 59, 1, 20, 87, 1, 392, 63, 1, 188, 91, 1, 388, 71, 1, 292, 91, 1, 32, 71, 1, 48, 44, 0, 64, 95, 1, 380, 63, 1, 192, 87, 1, 392, 51, 1, 312, 79, 1, 40, 87, 1, 380, 71, 1, 300, 71, 1, 32, 71, 1};
const melody_t star_wars_glockenspiel = {
    .p_name = "star_wars_glockenspiel",
    .p_notes = (double *)star_wars_glockenspiel_notes,
    .p_durations = (uint16_t *)star_wars_glockenspiel_durations,
    .melody_length = STAR_WARS_GLOCKENSPIEL_LENGTH,
    .next_melody = (const melody_t *)&star_wars_drums};

#define STAR_WARS_DRUMS_LENGTH 487

static const double star_wars_drums_notes[STAR_WARS_DRUMS_LENGTH] = {73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 0, 73, 0, 138, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 0, 73, 0, 138, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 0, 73, 0, 138, 0, 73, 0, 0, 73, 0, 0, 73, 0};
static const uint16_t star_wars_drums_durations[STAR_WARS_DRUMS_LENGTH] = {40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 44, 0, 196, 40, 0, 440, 44, 0, 200, 48, 0, 32, 40, 0, 36, 44, 0, 40, 44, 0, 204, 40, 0, 40, 44, 0, 28, 51, 1, 28, 51, 1, 24, 51, 1, 28, 51, 1, 36, 44, 0, 192, 44, 0, 432, 44, 0, 196, 44, 0, 36, 51, 1, 32, 48, 0, 28, 51, 1, 192, 44, 0, 36, 51, 1, 28, 44, 0, 32, 44, 0, 36, 51, 1, 28, 48, 0, 32, 40, 0, 28, 48, 0, 36, 36, 0, 56, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 44, 0, 200, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 40, 0, 24, 48, 0, 40, 32, 0, 60, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 44, 0, 200, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 44, 8, 0, 123, 1, 304, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 4, 36, 0, 67, 1, 136, 44, 0, 36, 48, 0, 28, 51, 1, 28, 4, 40, 0, 36, 0, 59, 1, 20, 44, 0, 40, 44, 0};
const melody_t star_wars_drums = {
    .p_name = "star_wars_drums",
    .p_notes = (double *)star_wars_drums_notes,
    .p_durations = (uint16_t *)star_wars_drums_durations,
    .melody_length = STAR_WARS_DRUMS_LENGTH,
    .next_melody = NULL};

/*
el siguiente codigo sirve para convertir codigo arduino a un formato deseado.

el codigo en python:
import pyperclip
def transform_code(code, song_name):
    notes = []
    durations = []
    lines = code.split("\n")
    for line in lines:
        if "tone(" in line:
            _, freq, duration = line.split(",")
            note = freq.strip()
            notes.append(note)
            duration = float(duration.split(")")[0].strip())
            # Redondear la duración al número entero más cercano
            rounded_duration = int(round(duration))
            durations.append(rounded_duration)
        elif "delay(" in line:
            # Agregar una frecuencia de 0 para representar el silencio
            notes.append("0")
            duration = float(line.split("(")[1].split(")")[0].strip())
            # Redondear la duración al número entero más cercano
            rounded_duration = int(round(duration))
            durations.append(rounded_duration)
    num_notes = len(notes)
    notes_str = ', '.join(notes)
    durations_str = ', '.join(map(str, durations))

    print(f"Notas para {song_name}: {notes_str}")
    print(f"Duraciones para {song_name}: {durations_str}")

    output = f"""
#define {song_name.upper()}_LENGTH {num_notes}

static const double {song_name}_notes[{song_name.upper()}_LENGTH] = {{{notes_str}}};
static const uint16_t {song_name}_durations[{song_name.upper()}_LENGTH] = {{{durations_str}}};
const melody_t {song_name} = {{
    .p_name = "{song_name}",
    .p_notes = (double *){song_name}_notes,
    .p_durations = (uint16_t *){song_name}_durations,
    .melody_length = {song_name.upper()}_LENGTH,
    .next_melody = NULL}};
    """
    return output

# Get the code from the user's clipboard
code = pyperclip.paste()

# Prompt the user for the song name
song_name = input("Introduce el nombre de la canción: ")

output = transform_code(code, song_name)
print(output)

pyperclip.copy(output)
input("Presiona Enter para salir...")

ejemplo de codigo arduino:
    tone(tonePin, 195, 265.32); //configura la frecuencia a 195 Hz y la duración a 265.32 ms
    delay(268.0); //espera a que termine la nota anterior
    delay(200.0); //silencio entre notas
    tone(tonePin, 195, 289.08); //configura la frecuencia a 195 Hz y la duración a 289.08 ms
    delay(292.0); //espera a que termine la nota anterior
    delay(192.0); //silencio entre notas
    tone(tonePin, 195, 297.0); //configura la frecuencia a 195 Hz y la duración a 297 ms
    delay(300.0); //espera a que termine la nota anterior
    delay(164.0);       //silencio entre notas
    tone(tonePin, 155, 229.68); //configura la frecuencia a 155 Hz y la duración a 229.68 ms

En este caso, las frecuencias serian:
195, 0, 195, 0, 195, 0, 155
y las duraciones:
round(265.32), round(268-265.32) + 200, round(289.08), round(292-289.08) + 192, 297, round(300-297) + 164, round(229.68)

Pero el codigo python esta contando todos los delays como silencios y es incorrecto.
modifica el codigo python para que tome las duraciones correctamente y el resultado sea el esperado.
*/