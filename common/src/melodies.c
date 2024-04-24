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

#define OVERWORLD_LENGTH 419

static const double overworld_notes[OVERWORLD_LENGTH] = {
    659, 659, 659, 523, 659, 784, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 784, 740, 698, 622, 659, 415, 440, 523, 440, 523, 587, 784, 740, 698, 622, 659, 1047, 1047, 1047, 784, 740, 698, 622, 659, 415, 440, 523, 440, 523, 587, 622, 587, 523, 784, 740, 698, 622, 659, 415, 440, 523, 440, 523, 587, 784, 740, 698, 622, 659, 1047, 1047, 1047, 784, 740, 698, 622, 659, 415, 440, 523, 440, 523, 587, 622, 587, 523, 523, 523, 523, 523, 587, 659, 523, 440, 392, 523, 523, 523, 523, 587, 659, 523, 523, 523, 523, 587, 659, 523, 440, 392, 659, 659, 659, 523, 659, 784, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 659, 523, 392, 415, 440, 698, 698, 440, 494, 880, 880, 880, 784, 698, 659, 523, 440, 392, 659, 523, 392, 415, 440, 698, 698, 440, 494, 698, 698, 698, 659, 587, 523, 659, 523, 392, 415, 440, 698, 698, 440, 494, 880, 880, 880, 784, 698, 659, 523, 440, 392, 659, 523, 392, 415, 440, 698, 698, 440, 494, 698, 698, 698, 659, 587, 523, 523, 523, 523, 523, 587, 659, 523, 440, 392, 523, 523, 523, 523, 587, 659, 523, 523, 523, 523, 587, 659, 523, 440, 392, 659, 659, 659, 523, 659, 784, 659, 523, 392, 415, 440, 698, 698, 440, 494, 880, 880, 880, 784, 698, 659, 523, 440, 392, 659, 523, 392, 415, 440, 698, 698, 440, 494, 698, 698, 698, 659, 587, 523};

static const uint16_t overworld_durations[OVERWORLD_LENGTH] = {
    124, 124, 249, 249, 124, 124, 124, 124, 249, 249, 249, 249, 249, 249, 249, 249, 249, 124, 124, 166, 166, 166, 249, 124, 124, 249, 124, 124, 124, 249, 249, 249, 249, 249, 124, 124, 166, 166, 166, 249, 124, 124, 249, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 249, 249, 249, 249, 249, 249, 249, 249, 249, 124, 124, 166, 166, 166, 249, 124, 124, 249, 124, 124, 124, 249, 249, 249, 249, 249, 124, 124, 166, 166, 166, 249, 124, 124, 249, 124, 124, 124, 124, 124, 249, 249, 124, 124, 124, 124, 124, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 124, 124, 124, 124, 124, 124, 124, 249, 249, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 166, 166, 166, 166, 166, 166, 124, 124, 124, 124, 249, 124, 124, 249, 249, 124, 124, 124, 124, 124, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 124, 124, 124, 124, 124, 124, 124, 249, 249, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 166, 166, 166, 166, 166, 166, 124, 124, 124, 124, 249, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 249, 249, 249, 249, 124, 124, 249, 249, 124, 124, 124, 124, 124, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 124, 124, 124, 124, 124, 124, 124, 249, 249, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 166, 166, 166, 166, 166, 166, 124, 124, 124, 124, 249};

const melody_t overworld = {.p_name = "overworld",
                            .p_notes = (double *)overworld_notes,
                            .p_durations = (uint16_t *)overworld_durations,
                            .melody_length = OVERWORLD_LENGTH,
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
                           .next_melody = (const melody_t*) &kerosene_bass};

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

/*

*/
