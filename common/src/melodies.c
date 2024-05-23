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

#define ONE_UP_LENGTH 6 /*!< one_up_melody melody length */
/**
 * @brief one_up_melody melody notes.
 *
 * This array contains the frequencies of the notes for the one_up_melody song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double one_up_notes[ONE_UP_LENGTH] = {
    1319, 1568, 2637, 2093, 2349, 3136};
/**
 * @brief one_up_melody melody durations in miliseconds.
 *
 * This array contains the duration of each note in the one_up_melody song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t one_up_durations[ONE_UP_LENGTH] = {
    120, 120, 120, 120, 120, 350};
/**
 * @brief one_up_melody melody struct.
 *
 * This struct contains the information of the one_up_melody melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t one_up_melody = {.p_name = "one_up_melody",
                                .p_notes = (double *)one_up_notes,
                                .p_durations = (uint16_t *)one_up_durations,
                                .melody_length = ONE_UP_LENGTH,
                                .next_melody = NULL};

#define NOKIA_LENGTH 13 /*!< nokia melody length */
/**
 * @brief nokia melody notes.
 *
 * This array contains the frequencies of the notes for the nokia song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double nokia_notes[NOKIA_LENGTH] = {
    659, 587, 370, 415, 554, 494, 294, 330, 494, 440, 277, 330, 440};
/**
 * @brief nokia melody durations in miliseconds.
 *
 * This array contains the duration of each note in the nokia song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t nokia_durations[NOKIA_LENGTH] = {
    125, 125, 250, 250, 125, 125, 250, 250, 125, 125, 250, 250, 500};
/**
 * @brief nokia melody struct.
 *
 * This struct contains the information of the nokia melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t nokia = {.p_name = "nokia",
                        .p_notes = (double *)nokia_notes,
                        .p_durations = (uint16_t *)nokia_durations,
                        .melody_length = NOKIA_LENGTH,
                        .next_melody = NULL};

#define KEROSENE_BASS_LENGTH 80 /*!< kerosene_bass melody length */
/**
 * @brief kerosene_bass melody notes.
 *
 * This array contains the frequencies of the notes for the kerosene_bass song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double kerosene_bass_notes[KEROSENE_BASS_LENGTH] = {
    73, 78, 65, 98, 73, 78, 65, 98, 73, 73, 73, 78, 78, 78, 65, 65, 65, 98, 98, 98, 73, 73, 73, 78, 78, 78, 65, 65, 65, 98, 98, 98, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49, 37, 37, 37, 39, 39, 39, 33, 33, 33, 49, 49, 49};
/**
 * @brief kerosene_bass melody durations in miliseconds.
 *
 * This array contains the duration of each note in the kerosene_bass song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t kerosene_bass_durations[KEROSENE_BASS_LENGTH] = {
    1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 480, 720, 720, 479};
/**
 * @brief kerosene_bass melody struct.
 *
 * This struct contains the information of the kerosene_bass melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t kerosene_bass = {.p_name = "kerosene_bass",
                                .p_notes = (double *)kerosene_bass_notes,
                                .p_durations = (uint16_t *)kerosene_bass_durations,
                                .melody_length = KEROSENE_BASS_LENGTH};

#define KEROSENE_LENGTH 508 /*!< kerosene melody length */
/**
 * @brief kerosene melody notes.
 *
 * This array contains the frequencies of the notes for the kerosene song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double kerosene_notes[KEROSENE_LENGTH] = {
    622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440, 622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440, 622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440, 622, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 392, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 523, 466, 523, 466, 622, 523, 622, 622, 523, 622, 523, 523, 587, 523, 587, 587, 466, 587, 466, 466, 440, 466, 440, 440, 466, 440, 466, 466, 392, 466, 392, 392, 349, 392, 349, 349, 523, 349, 523, 523, 523, 523, 523, 523, 587, 523, 587, 587, 698, 587, 698, 698, 587, 698, 587, 587, 523, 587, 523, 523, 466, 523, 466, 466, 440, 466, 440, 440};
/**
 * @brief kerosene melody durations in miliseconds.
 *
 * This array contains the duration of each note in the kerosene song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t kerosene_durations[KEROSENE_LENGTH] = {
    240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 119};
/**
 * @brief kerosene melody struct.
 *
 * This struct contains the information of the kerosene melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t kerosene = {.p_name = "kerosene",
                           .p_notes = (double *)kerosene_notes,
                           .p_durations = (uint16_t *)kerosene_durations,
                           .melody_length = KEROSENE_LENGTH,
                           .next_melody = (const melody_t *)&kerosene_bass};

#define MARIO_DEATH_LENGTH 25 /*!< mario_death melody length */
/**
 * @brief mario_death melody notes.
 *
 * This array contains the frequencies of the notes for the mario_death song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double mario_death_notes[MARIO_DEATH_LENGTH] = {
    392, 494, 196, 587, 698, 587, 698, 196, 587, 698, 196, 523, 659, 220, 494, 587, 247, 392, 523, 262, 330, 196, 330, 262, 131};
/**
 * @brief mario_death melody durations in miliseconds.
 *
 * This array contains the duration of each note in the mario_death song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t mario_death_durations[MARIO_DEATH_LENGTH] = {
    159, 168, 134, 111, 111, 151, 151, 151, 188, 199, 188, 180, 192, 180, 190, 202, 190, 145, 154, 118, 110, 115, 141, 115, 115};
/**
 * @brief mario_death melody struct.
 *
 * This struct contains the information of the mario_death melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t mario_death = {
    .p_name = "mario_death",
    .p_notes = (double *)mario_death_notes,
    .p_durations = (uint16_t *)mario_death_durations,
    .melody_length = MARIO_DEATH_LENGTH,
    .next_melody = NULL};

#define STAR_WARS_TRUMPET_LENGTH 197 /*!< star_wars_trumpet melody length */
/**
 * @brief star_wars_trumpet melody notes.
 *
 * This array contains the frequencies of the notes for the star_wars_trumpet song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double star_wars_trumpet_notes[STAR_WARS_TRUMPET_LENGTH] = {391, 0, 0, 391, 0, 0, 391, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 622, 0, 0, 466, 0, 0, 369, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 783, 0, 0, 391, 0, 0, 391, 0, 0, 783, 0, 0, 739, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 659, 0, 0, 415, 0, 0, 554, 0, 0, 523, 0, 0, 493, 0, 0, 466, 0, 0, 440, 0, 0, 466, 0, 0, 311, 0, 0, 369, 0, 0, 311, 0, 0, 369, 0, 0, 466, 0, 0, 391, 0, 0, 466, 0, 0, 587, 0, 0, 783, 0, 0, 391, 0, 0, 391, 0, 0, 783, 0, 0, 739, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 659, 0, 0, 415, 0, 0, 554, 0, 0, 523, 0, 0, 493, 0, 0, 466, 0, 0, 440, 0, 0, 466, 0, 0, 311, 0, 0, 369, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0, 0, 311, 0, 0, 466, 0, 0, 391, 0};
/**
 * @brief star_wars_trumpet melody durations in miliseconds.
 *
 * This array contains the duration of each note in the star_wars_trumpet song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t star_wars_trumpet_durations[STAR_WARS_TRUMPET_LENGTH] = {309, 3, 188, 321, 3, 168, 285, 3, 160, 242, 2, 100, 71, 1, 60, 376, 4, 108, 206, 2, 160, 71, 1, 52, 626, 6, 324, 321, 3, 148, 317, 3, 172, 313, 3, 164, 210, 2, 136, 63, 1, 60, 301, 3, 168, 253, 3, 104, 79, 1, 52, 578, 6, 388, 289, 3, 160, 174, 2, 216, 75, 1, 36, 321, 3, 156, 246, 2, 124, 79, 1, 24, 83, 1, 28, 71, 1, 24, 154, 2, 344, 83, 1, 168, 356, 4, 116, 293, 3, 64, 83, 1, 44, 83, 1, 32, 79, 1, 44, 67, 1, 412, 87, 1, 144, 337, 3, 132, 297, 3, 72, 67, 1, 56, 329, 3, 152, 238, 2, 112, 63, 1, 60, 665, 7, 292, 289, 3, 160, 174, 2, 216, 75, 1, 36, 321, 3, 156, 246, 2, 124, 79, 1, 24, 83, 1, 28, 71, 1, 24, 154, 2, 344, 83, 1, 168, 356, 4, 116, 293, 3, 64, 83, 1, 44, 83, 1, 32, 79, 1, 44, 67, 1, 412, 87, 1, 144, 337, 3, 132, 297, 3, 72, 67, 1, 56, 329, 3, 152, 238, 2, 112, 63, 1, 60, 665, 7};
const melody_t star_wars_trumpet = {
    .p_name = "star_wars_trumpet",
    .p_notes = (double *)star_wars_trumpet_notes,
    .p_durations = (uint16_t *)star_wars_trumpet_durations,
    .melody_length = STAR_WARS_TRUMPET_LENGTH,
    .next_melody = (const melody_t *)&star_wars_trombone};
/**
 * @brief star_wars_trombone melody struct.
 *
 * This struct contains the information of the star_wars_trombone melody.
 * It is used to play the melody using the buzzer.
 */
#define STAR_WARS_TROMBONE_LENGTH 222 /*!< star_wars_trombone melody length */
/**
 * @brief star_wars_trombone melody notes.
 *
 * This array contains the frequencies of the notes for the star_wars_trombone song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double star_wars_trombone_notes[STAR_WARS_TROMBONE_LENGTH] = {195, 0, 0, 195, 0, 0, 195, 0, 0, 155, 0, 0, 233, 0, 0, 195, 0, 0, 155, 0, 0, 233, 0, 0, 195, 0, 0, 293, 0, 0, 293, 0, 0, 293, 0, 0, 311, 0, 0, 233, 0, 0, 184, 0, 0, 155, 0, 0, 233, 0, 0, 195, 0, 0, 391, 0, 0, 195, 0, 0, 195, 0, 0, 391, 0, 0, 369, 0, 0, 349, 0, 0, 329, 0, 0, 311, 0, 0, 329, 0, 0, 207, 0, 0, 277, 0, 0, 261, 0, 0, 246, 0, 0, 233, 0, 0, 220, 0, 0, 233, 0, 0, 155, 0, 0, 184, 0, 0, 155, 0, 0, 184, 0, 0, 233, 0, 0, 195, 0, 0, 233, 0, 0, 293, 0, 0, 391, 0, 0, 195, 0, 0, 195, 0, 0, 391, 0, 0, 369, 0, 0, 349, 0, 0, 329, 0, 0, 311, 0, 0, 329, 0, 0, 207, 0, 0, 277, 0, 207, 0, 0, 207, 0, 261, 0, 0, 246, 0, 207, 0, 0, 0, 184, 0, 233, 0, 0, 220, 0, 174, 0, 0, 0, 184, 0, 233, 0, 0, 155, 0, 0, 184, 0, 0, 0, 0, 155, 0, 184, 0, 233, 0, 0, 233, 0, 0, 195, 0, 0, 0, 155, 0, 184, 0, 233, 0, 0, 233, 0, 0, 195, 0};
/**
 * @brief star_wars_trombone melody durations in miliseconds.
 *
 * This array contains the duration of each note in the star_wars_trombone song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t star_wars_trombone_durations[STAR_WARS_TROMBONE_LENGTH] = {265, 3, 200, 289, 3, 192, 297, 3, 164, 230, 2, 136, 55, 1, 64, 337, 3, 128, 230, 2, 140, 67, 1, 44, 602, 6, 348, 301, 3, 180, 297, 3, 172, 309, 3, 184, 206, 2, 140, 75, 1, 56, 337, 3, 128, 198, 2, 148, 67, 1, 68, 578, 6, 364, 368, 4, 116, 238, 2, 132, 91, 1, 32, 297, 3, 136, 257, 3, 132, 79, 1, 24, 111, 1, 44, 79, 1, 12, 103, 1, 388, 91, 1, 152, 313, 3, 164, 257, 3, 100, 83, 1, 40, 91, 1, 16, 71, 1, 52, 103, 1, 384, 79, 1, 156, 285, 3, 204, 269, 3, 88, 59, 1, 72, 317, 3, 136, 265, 3, 92, 63, 1, 68, 598, 6, 324, 368, 4, 116, 238, 2, 132, 91, 1, 32, 297, 3, 136, 257, 3, 132, 79, 1, 24, 111, 1, 44, 79, 1, 12, 103, 1, 388, 91, 1, 152, 313, 3, 8, 0, 156, 210, 2, 48, 0, 100, 63, 1, 8, 0, 40, 8, 79, 1, 4, 0, 24, 71, 1, 8, 0, 44, 4, 91, 1, 8, 0, 388, 79, 1, 156, 285, 3, 180, 8, 4, 269, 3, 20, 0, 24, 0, 52, 59, 1, 52, 321, 3, 136, 8, 265, 3, 4, 0, 8, 0, 104, 63, 1, 44, 135, 1};
/**
 * @brief star_wars_trombone melody struct.
 *
 * This struct contains the information of the star_wars_trombone melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t star_wars_trombone = {
    .p_name = "star_wars_trombone",
    .p_notes = (double *)star_wars_trombone_notes,
    .p_durations = (uint16_t *)star_wars_trombone_durations,
    .melody_length = STAR_WARS_TROMBONE_LENGTH,
    .next_melody = (const melody_t *)&star_wars_glockenspiel};

#define STAR_WARS_GLOCKENSPIEL_LENGTH 107 /*!< star_wars_glockenspiel melody length */
/**
 * @brief star_wars_glockenspiel melody notes.
 *
 * This array contains the frequencies of the notes for the star_wars_glockenspiel song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double star_wars_glockenspiel_notes[STAR_WARS_GLOCKENSPIEL_LENGTH] = {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1567, 0, 0, 783, 0, 0, 783, 0, 0, 1567, 0, 0, 1479, 0, 0, 1396, 0, 0, 1318, 0, 0, 1244, 0, 0, 1318, 0, 0, 830, 0, 0, 1108, 0, 0, 1046, 0, 0, 987, 0, 0, 932, 0, 0, 880, 0, 0, 932, 0, 0, 622, 0, 0, 739, 0, 0, 622, 0, 0, 932, 0, 0, 783, 0, 0, 622, 0, 0, 932, 0, 0, 783, 0};
/**
 * @brief star_wars_glockenspiel melody durations in miliseconds.
 *
 * This array contains the duration of each note in the star_wars_glockenspiel song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t star_wars_glockenspiel_durations[STAR_WARS_GLOCKENSPIEL_LENGTH] = {238, 950, 960, 238, 2, 720, 238, 2, 1440, 238, 2, 960, 238, 2, 1440, 238, 2, 1200, 238, 2, 960, 238, 2, 960, 238, 2, 960, 238, 2, 960, 238, 2, 960, 238, 2, 100, 99, 1, 380, 103, 1, 256, 55, 1, 68, 79, 1, 380, 83, 1, 312, 83, 1, 28, 95, 1, 32, 59, 1, 20, 87, 1, 392, 63, 1, 188, 91, 1, 388, 71, 1, 292, 91, 1, 32, 71, 1, 48, 44, 0, 64, 95, 1, 380, 63, 1, 192, 87, 1, 392, 51, 1, 312, 79, 1, 40, 87, 1, 380, 71, 1, 300, 71, 1, 32, 71, 1};
/**
 * @brief star_wars_glockenspiel melody struct.
 *
 * This struct contains the information of the star_wars_glockenspiel melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t star_wars_glockenspiel = {
    .p_name = "star_wars_glockenspiel",
    .p_notes = (double *)star_wars_glockenspiel_notes,
    .p_durations = (uint16_t *)star_wars_glockenspiel_durations,
    .melody_length = STAR_WARS_GLOCKENSPIEL_LENGTH,
    .next_melody = (const melody_t *)&star_wars_drums};

#define STAR_WARS_DRUMS_LENGTH 487 /*!< star_wars_drums melody length */
/**
 * @brief star_wars_drums melody notes.
 *
 * This array contains the frequencies of the notes for the star_wars_drums song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double star_wars_drums_notes[STAR_WARS_DRUMS_LENGTH] = {73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 0, 73, 0, 138, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 0, 73, 0, 138, 0, 0, 73, 0, 0, 73, 0, 0, 73, 0, 0, 0, 73, 0, 138, 0, 73, 0, 0, 73, 0, 0, 73, 0};
/**
 * @brief star_wars_drums melody durations in miliseconds.
 *
 * This array contains the duration of each note in the star_wars_drums song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t star_wars_drums_durations[STAR_WARS_DRUMS_LENGTH] = {40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 44, 0, 196, 40, 0, 440, 44, 0, 200, 48, 0, 32, 40, 0, 36, 44, 0, 40, 44, 0, 204, 40, 0, 40, 44, 0, 28, 51, 1, 28, 51, 1, 24, 51, 1, 28, 51, 1, 36, 44, 0, 192, 44, 0, 432, 44, 0, 196, 44, 0, 36, 51, 1, 32, 48, 0, 28, 51, 1, 192, 44, 0, 36, 51, 1, 28, 44, 0, 32, 44, 0, 36, 51, 1, 28, 48, 0, 32, 40, 0, 28, 48, 0, 36, 36, 0, 56, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 44, 0, 200, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 40, 0, 24, 48, 0, 40, 32, 0, 60, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 51, 1, 428, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 40, 0, 204, 44, 0, 36, 48, 0, 28, 51, 1, 24, 44, 0, 40, 59, 1, 16, 44, 0, 44, 44, 0, 200, 40, 0, 440, 44, 0, 192, 40, 0, 28, 48, 0, 40, 36, 0, 48, 55, 1, 184, 44, 0, 40, 44, 0, 36, 44, 0, 32, 48, 0, 32, 48, 0, 28, 51, 1, 32, 51, 1, 192, 44, 8, 0, 123, 1, 304, 51, 1, 196, 40, 0, 32, 44, 0, 36, 44, 0, 28, 4, 36, 0, 67, 1, 136, 44, 0, 36, 48, 0, 28, 51, 1, 28, 4, 40, 0, 36, 0, 59, 1, 20, 44, 0, 40, 44, 0};
/**
 * @brief star_wars_drums melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t star_wars_drums = {
    .p_name = "star_wars_drums",
    .p_notes = (double *)star_wars_drums_notes,
    .p_durations = (uint16_t *)star_wars_drums_durations,
    .melody_length = STAR_WARS_DRUMS_LENGTH,
    .next_melody = NULL};

#define POKEMON_LENGTH 713 /*!< pokemon melody length */
/**
 * @brief pokemon melody notes.
 *
 * This array contains the frequencies of the notes for the pokemon song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double pokemon_notes[POKEMON_LENGTH] = {9, 0, 0, 587, 0, 0, 587, 0, 0, 880, 0, 0, 587, 0, 0, 587, 0, 0, 932, 0, 0, 587, 0, 0, 587, 0, 0, 880, 0, 0, 587, 0, 0, 587, 0, 0, 739, 0, 0, 587, 0, 0, 587, 0, 0, 880, 0, 0, 587, 0, 0, 587, 0, 0, 932, 0, 0, 1174, 0, 0, 587, 0, 0, 932, 0, 0, 523, 0, 0, 587, 0, 0, 587, 0, 0, 880, 0, 0, 587, 0, 0, 587, 0, 0, 932, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 587, 0, 0, 587, 0, 0, 932, 0, 0, 880, 0, 0, 1174, 0, 0, 195, 0, 0, 246, 0, 0, 293, 0, 0, 369, 0, 0, 391, 0, 0, 391, 0, 0, 391, 0, 0, 391, 0, 0, 391, 0, 0, 391, 0, 0, 391, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 391, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 349, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 587, 0, 0, 261, 0, 0, 246, 0, 0, 261, 0, 0, 293, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 329, 0, 0, 293, 0, 0, 329, 0, 0, 493, 0, 0, 349, 0, 0, 329, 0, 0, 261, 0, 0, 293, 0, 0, 246, 0, 0, 261, 0, 0, 293, 0, 0, 391, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 349, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 587, 0, 0, 261, 0, 0, 246, 0, 0, 261, 0, 0, 293, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 698, 0, 0, 659, 0, 0, 698, 0, 0, 587, 0, 0, 698, 0, 0, 587, 0, 0, 698, 0, 0, 932, 0, 0, 698, 0, 0, 698, 0, 0, 932, 0, 0, 987, 0, 0, 1046, 0, 0, 783, 0, 0, 783, 0, 0, 1046, 0, 0, 1108, 0, 0, 1174, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 1046, 0, 0, 1108, 0, 0, 1174, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 1046, 0, 0, 987, 0, 0, 391, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 349, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 587, 0, 0, 261, 0, 0, 246, 0, 0, 261, 0, 0, 293, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 329, 0, 0, 293, 0, 0, 329, 0, 0, 493, 0, 0, 349, 0, 0, 329, 0, 0, 261, 0, 0, 293, 0, 0, 246, 0, 0, 261, 0, 0, 293, 0, 0, 391, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 349, 0, 0, 698, 0, 0, 659, 0, 0, 622, 0, 0, 587, 0, 0, 261, 0, 0, 246, 0, 0, 261, 0, 0, 293, 0, 0, 493, 0, 0, 587, 0, 0, 261, 0, 0, 698, 0, 0, 659, 0, 0, 698, 0, 0, 587, 0, 0, 698, 0, 0, 587, 0, 0, 698, 0, 0, 932, 0, 0, 698, 0, 0, 698, 0, 0, 932, 0, 0, 987, 0, 0, 1046, 0, 0, 783, 0, 0, 783, 0, 0, 1046, 0, 0, 1108, 0, 0, 1174, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 1046, 0, 0, 1108, 0, 0, 1174, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 1046, 0, 0, 1108, 0, 0, 1174, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 1046, 0, 0, 1108, 0, 0, 1174, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 1046, 0, 0, 1046, 0, 0, 987, 0, 0, 783, 0};
/**
 * @brief pokemon melody durations in miliseconds.
 *
 * This array contains the duration of each note in the pokemon song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t pokemon_durations[POKEMON_LENGTH] = {197, 21, 1529, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 688, 77, 109, 721, 80, 73, 688, 77, 109, 721, 80, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 1507, 168, 73, 328, 36, 837, 94, 11, 5, 143, 16, 5, 143, 16, 5, 94, 11, 5, 328, 36, 73, 328, 36, 291, 94, 11, 5, 94, 11, 5, 328, 36, 73, 328, 36, 73, 328, 36, 73, 143, 16, 5, 143, 16, 5, 94, 11, 5, 143, 16, 5, 143, 16, 5, 94, 11, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 524, 59, 73, 193, 21, 5, 524, 59, 73, 94, 11, 5, 94, 11, 5, 688, 77, 1857, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 688, 77, 109, 291, 32, 5, 242, 27, 5, 242, 27, 5, 688, 77, 109, 291, 32, 5, 242, 27, 5, 242, 27, 5, 688, 77, 328, 193, 21, 5, 193, 21, 5, 193, 21, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 524, 59, 73, 193, 21, 5, 524, 59, 73, 94, 11, 5, 94, 11, 5, 688, 77, 1857, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 688, 77, 109, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 1475, 163, 109, 688, 77, 109, 524, 59, 73, 193, 21, 5, 1475, 163, 109, 328, 36, 73, 328, 36, 73, 524, 59, 73, 193, 21, 5, 1475, 163, 109, 328, 36, 73, 328, 36, 73, 291, 32, 5, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 291, 32, 5, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 5, 291, 32, 5, 94, 11, 332, 94, 11, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 524, 59, 73, 193, 21, 5, 524, 59, 73, 94, 11, 5, 94, 11, 5, 688, 77, 1857, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 688, 77, 109, 291, 32, 5, 242, 27, 5, 242, 27, 5, 688, 77, 109, 291, 32, 5, 242, 27, 5, 242, 27, 5, 688, 77, 328, 193, 21, 5, 193, 21, 5, 193, 21, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 524, 59, 73, 193, 21, 5, 524, 59, 73, 94, 11, 5, 94, 11, 5, 688, 77, 1857, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 688, 77, 109, 688, 77, 109, 291, 32, 5, 242, 27, 5, 242, 27, 5, 524, 59, 73, 193, 21, 5, 1475, 163, 109, 688, 77, 109, 524, 59, 73, 193, 21, 5, 1475, 163, 109, 328, 36, 73, 328, 36, 73, 524, 59, 73, 193, 21, 5, 1475, 163, 109, 328, 36, 73, 328, 36, 73, 291, 32, 5, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 291, 32, 5, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 5, 291, 32, 5, 94, 11, 332, 94, 11, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 291, 32, 5, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 291, 32, 5, 94, 11, 332, 94, 11, 332, 94, 11, 332, 94, 11, 5, 291, 32, 5, 94, 11, 332, 94, 11, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 1475, 163};
/**
 * @brief pokemon melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t pokemon = {
    .p_name = "pokemon",
    .p_notes = (double *)pokemon_notes,
    .p_durations = (uint16_t *)pokemon_durations,
    .melody_length = POKEMON_LENGTH,
    .next_melody = (const melody_t *)&pokemon_guitar};

#define POKEMON_GUITAR_LENGTH 992 /*!< pokemon_guitar melody length */
/**
 * @brief pokemon_guitar melody notes.
 *
 * This array contains the frequencies of the notes for the pokemon_guitar song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double pokemon_guitar_notes[POKEMON_GUITAR_LENGTH] = {9, 0, 0, 440, 0, 0, 440, 0, 0, 587, 0, 0, 440, 0, 0, 440, 0, 0, 622, 0, 0, 440, 0, 0, 440, 0, 0, 587, 0, 0, 440, 0, 0, 440, 0, 0, 466, 0, 0, 440, 0, 0, 440, 0, 0, 587, 0, 0, 440, 0, 0, 440, 0, 0, 783, 0, 0, 880, 0, 0, 440, 0, 0, 698, 0, 0, 349, 0, 0, 440, 0, 0, 440, 0, 0, 587, 0, 0, 440, 0, 0, 440, 0, 0, 622, 0, 0, 440, 0, 0, 440, 0, 0, 698, 0, 0, 440, 0, 0, 440, 0, 0, 783, 0, 0, 739, 0, 0, 293, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 195, 0, 0, 195, 0, 0, 195, 0, 0, 174, 0, 0, 174, 0, 0, 184, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 220, 0, 0, 174, 0, 0, 220, 0, 0, 261, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 195, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 220, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 261, 0, 0, 261, 0, 0, 277, 0, 0, 293, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 261, 0, 0, 261, 0, 0, 246, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 130, 0, 0, 174, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 146, 0, 0, 195, 0, 0, 195, 0, 0, 146, 0, 0, 220, 0, 0, 174, 0, 0, 220, 0, 0, 261, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 195, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 261, 0, 0, 220, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 261, 0, 0, 261, 0, 0, 277, 0, 0, 293, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 261, 0, 0, 261, 0, 0, 277, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 261, 0, 0, 261, 0, 0, 277, 0, 0, 293, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 261, 0, 0, 261, 0, 0, 246, 0, 0, 195, 0};
/**
 * @brief pokemon_guitar melody durations in miliseconds.
 *
 * This array contains the duration of each note in the pokemon_guitar song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t pokemon_guitar_durations[POKEMON_GUITAR_LENGTH] = {197, 21, 655, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 688, 77, 109, 721, 80, 73, 688, 77, 109, 721, 80, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 193, 21, 5, 193, 21, 5, 328, 36, 73, 1507, 168, 73, 328, 36, 510, 328, 36, 1384, 328, 36, 73, 328, 36, 510, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 291, 32, 5, 94, 11, 5, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 193, 21, 5, 389, 43, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 328, 36, 73, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 193, 21, 5, 291, 32, 5, 242, 27, 5, 242, 27, 5, 1475, 163};
/**
 * @brief pokemon_guitar melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t pokemon_guitar = {
    .p_name = "pokemon_guitar",
    .p_notes = (double *)pokemon_guitar_notes,
    .p_durations = (uint16_t *)pokemon_guitar_durations,
    .melody_length = POKEMON_GUITAR_LENGTH,
    .next_melody = NULL};

#define MINECRAFT_1_LENGTH 146 /*!< minecraft_1 melody length */
/**
 * @brief minecraft_1 melody notes.
 *
 * This array contains the frequencies of the notes for the minecraft_1 song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double minecraft_1_notes[MINECRAFT_1_LENGTH] = {698, 0, 0, 739, 0, 0, 830, 0, 0, 932, 0, 0, 830, 0, 0, 698, 0, 0, 739, 0, 0, 554, 0, 0, 698, 0, 0, 932, 0, 0, 830, 0, 0, 932, 0, 0, 1108, 0, 0, 932, 0, 0, 830, 0, 0, 554, 0, 0, 987, 0, 0, 932, 0, 0, 739, 0, 0, 622, 0, 0, 830, 0, 0, 739, 0, 0, 698, 0, 0, 554, 0, 0, 698, 0, 0, 932, 0, 0, 830, 0, 0, 932, 0, 0, 1108, 0, 0, 932, 0, 0, 830, 0, 0, 554, 0, 0, 1396, 0, 0, 1108, 0, 0, 830, 0, 0, 932, 0, 0, 554, 0, 0, 1479, 0, 0, 1661, 0, 0, 1108, 0, 0, 739, 0, 0, 830, 0, 0, 554, 0, 0, 1396, 0, 0, 1108, 0, 0, 830, 0, 0, 739, 0, 0, 554, 0, 0, 1479, 0};
/**
 * @brief minecraft_1 melody durations in miliseconds.
 *
 * This array contains the duration of each note in the minecraft_1 song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t minecraft_1_durations[MINECRAFT_1_LENGTH] = {170, 19, 11, 170, 19, 11, 170, 19, 11, 341, 38, 21, 341, 38, 21, 170, 19, 11, 341, 38, 21, 1025, 114, 61, 170, 19, 11, 170, 19, 11, 170, 19, 11, 341, 38, 21, 512, 57, 31, 170, 19, 11, 170, 19, 11, 1025, 114, 61, 170, 19, 11, 170, 19, 11, 170, 19, 11, 341, 38, 21, 341, 38, 21, 170, 19, 11, 341, 38, 21, 1025, 114, 61, 170, 19, 11, 170, 19, 11, 170, 19, 11, 341, 38, 21, 512, 57, 31, 170, 19, 11, 170, 19, 11, 1025, 114, 61, 341, 38, 21, 854, 95, 51, 170, 19, 11, 341, 38, 21, 1025, 114, 61, 170, 19, 11, 170, 19, 11, 1025, 114, 61, 170, 19, 11, 170, 19, 11, 1025, 114, 61, 341, 38, 21, 854, 95, 51, 170, 19, 11, 341, 38, 21, 1025, 114, 61, 1367, 152};
/**
 * @brief minecraft_1 melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t minecraft_1 = {
    .p_name = "minecraft_1",
    .p_notes = (double *)minecraft_1_notes,
    .p_durations = (uint16_t *)minecraft_1_durations,
    .melody_length = MINECRAFT_1_LENGTH,
    .next_melody = (const melody_t *)&minecraft_1_sub};

#define MINECRAFT_1_SUB_LENGTH 151 /*!< minecraft_1_sub melody length */
/**
 * @brief minecraft_1_sub melody notes.
 *
 * This array contains the frequencies of the notes for the minecraft_1_sub song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double minecraft_1_sub_notes[MINECRAFT_1_SUB_LENGTH] = {184, 0, 0, 349, 0, 0, 277, 0, 0, 233, 0, 0, 0, 0, 277, 0, 184, 0, 0, 155, 0, 0, 233, 0, 0, 349, 0, 0, 277, 0, 0, 0, 0, 233, 0, 155, 0, 0, 123, 0, 0, 369, 0, 0, 277, 0, 0, 184, 0, 0, 0, 0, 0, 155, 0, 123, 0, 0, 138, 0, 0, 207, 0, 0, 349, 0, 0, 277, 0, 0, 0, 0, 207, 0, 138, 0, 0, 184, 0, 0, 349, 0, 0, 277, 0, 0, 233, 0, 0, 184, 0, 0, 277, 0, 0, 233, 0, 0, 349, 0, 0, 184, 0, 0, 233, 0, 0, 349, 0, 0, 277, 0, 0, 184, 0, 0, 277, 0, 0, 233, 0, 0, 349, 0, 0, 184, 0, 0, 349, 0, 0, 277, 0, 0, 233, 0, 0, 184, 0, 0, 277, 0, 0, 233, 0, 0, 349, 0, 0, 184, 0};
/**
 * @brief minecraft_1_sub melody durations in miliseconds.
 *
 * This array contains the duration of each note in the minecraft_1_sub song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t minecraft_1_sub_durations[MINECRAFT_1_SUB_LENGTH] = {170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 30, 30, 1384, 154, 1, 0, 1, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 30, 30, 1384, 154, 1, 0, 1, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 30, 30, 32, 1355, 151, 1, 0, 1, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 30, 30, 1384, 154, 1, 0, 1, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 170, 19, 11, 170, 19, 11, 170, 19, 11, 854, 95, 51, 1367, 152};
/**
 * @brief minecraft_1_sub melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t minecraft_1_sub = {
    .p_name = "minecraft_1_sub",
    .p_notes = (double *)minecraft_1_sub_notes,
    .p_durations = (uint16_t *)minecraft_1_sub_durations,
    .melody_length = MINECRAFT_1_SUB_LENGTH,
    .next_melody = NULL};

#define ZELDA_THEME_SONG_LENGTH 908 /*!< zelda_theme_song melody length */
/**
 * @brief zelda_theme_song melody notes.
 *
 * This array contains the frequencies of the notes for the zelda_theme_song song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double zelda_theme_song_notes[ZELDA_THEME_SONG_LENGTH] = {146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 174, 0, 0, 146, 0, 0, 146, 0, 0, 130, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 155, 0, 0, 174, 0, 0, 195, 0, 0, 207, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 207, 0, 0, 207, 0, 0, 233, 0, 0, 261, 0, 0, 277, 0, 0, 184, 0, 0, 184, 0, 0, 207, 0, 0, 233, 0, 0, 261, 0, 0, 277, 0, 0, 277, 0, 0, 261, 0, 0, 233, 0, 0, 277, 0, 0, 207, 0, 0, 207, 0, 0, 207, 0, 0, 184, 0, 0, 207, 0, 0, 207, 0, 0, 207, 0, 0, 184, 0, 0, 207, 0, 0, 184, 0, 0, 184, 0, 0, 184, 0, 0, 207, 0, 0, 233, 0, 0, 207, 0, 0, 184, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 184, 0, 0, 207, 0, 0, 184, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 155, 0, 0, 174, 0, 0, 184, 0, 0, 195, 0, 0, 220, 0, 0, 233, 0, 0, 261, 0, 0, 220, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 174, 0, 0, 146, 0, 0, 146, 0, 0, 130, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 155, 0, 0, 174, 0, 0, 195, 0, 0, 207, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 207, 0, 0, 207, 0, 0, 233, 0, 0, 261, 0, 0, 277, 0, 0, 311, 0, 0, 261, 0, 0, 261, 0, 0, 220, 0, 0, 246, 0, 0, 311, 0, 0, 261, 0, 0, 220, 0, 0, 220, 0, 0, 246, 0, 0, 311, 0, 0, 261, 0, 0, 220, 0, 0, 220, 0, 0, 246, 0, 0, 311, 0, 0, 233, 0, 0, 233, 0, 0, 174, 0, 0, 155, 0, 0, 155, 0, 0, 164, 0, 0, 174, 0, 0, 195, 0, 0, 195, 0, 0, 220, 0, 0, 233, 0, 0, 261, 0, 0, 220, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 174, 0, 0, 146, 0, 0, 146, 0, 0, 130, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 155, 0, 0, 174, 0, 0, 195, 0, 0, 207, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 207, 0, 0, 207, 0, 0, 233, 0, 0, 261, 0, 0, 277, 0, 0, 184, 0, 0, 184, 0, 0, 207, 0, 0, 233, 0, 0, 261, 0, 0, 277, 0, 0, 277, 0, 0, 261, 0, 0, 233, 0, 0, 277, 0, 0, 207, 0, 0, 207, 0, 0, 207, 0, 0, 184, 0, 0, 207, 0, 0, 207, 0, 0, 207, 0, 0, 184, 0, 0, 207, 0, 0, 184, 0, 0, 184, 0, 0, 184, 0, 0, 207, 0, 0, 233, 0, 0, 207, 0, 0, 184, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 184, 0, 0, 207, 0, 0, 184, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 155, 0, 0, 174, 0, 0, 184, 0, 0, 195, 0, 0, 220, 0, 0, 233, 0, 0, 261, 0, 0, 220, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 174, 0, 0, 146, 0, 0, 146, 0, 0, 130, 0, 0, 146, 0, 0, 146, 0, 0, 146, 0, 0, 155, 0, 0, 174, 0, 0, 195, 0, 0, 207, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 207, 0, 0, 207, 0, 0, 233, 0, 0, 261, 0, 0, 277, 0, 0, 311, 0, 0, 261, 0, 0, 261, 0, 0, 220, 0, 0, 246, 0, 0, 311, 0, 0, 261, 0, 0, 220, 0, 0, 220, 0, 0, 246, 0, 0, 311, 0, 0, 261, 0, 0, 220, 0, 0, 220, 0, 0, 246, 0, 0, 311, 0, 0, 233, 0, 0, 233, 0, 0, 174, 0, 0, 155, 0, 0, 155, 0, 0, 164, 0, 0, 174, 0, 0, 195, 0, 0, 195, 0, 0, 220, 0, 0, 233, 0, 0, 261, 0, 0, 220, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 110, 0, 0, 146, 0};
/**
 * @brief zelda_theme_song melody durations in miliseconds.
 *
 * This array contains the duration of each note in the zelda_theme_song song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t zelda_theme_song_durations[ZELDA_THEME_SONG_LENGTH] = {594, 66, 223, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 499, 56, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 499, 56, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 224, 25, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 251, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 1199, 134};
/**
 * @brief zelda_theme_song melody struct.
 *
 * This struct contains the information of the Tetris melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t zelda_theme_song = {
    .p_name = "zelda_theme_song",
    .p_notes = (double *)zelda_theme_song_notes,
    .p_durations = (uint16_t *)zelda_theme_song_durations,
    .melody_length = ZELDA_THEME_SONG_LENGTH,
    .next_melody = (const melody_t *)&zelda_bass};

#define ZELDA_BASS_LENGTH 827 /*!< zelda_bass melody length */
/**
 * @brief zelda_bass melody notes.
 *
 * This array contains the frequencies of the notes for the zelda_bass song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double zelda_bass_notes[ZELDA_BASS_LENGTH] = {116, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 97, 0, 0, 110, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 77, 0, 0, 92, 0, 0, 92, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 123, 0, 0, 138, 0, 0, 138, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 116, 0, 0, 123, 0, 0, 123, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 103, 0, 0, 103, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 97, 0, 0, 110, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 77, 0, 0, 92, 0, 0, 92, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 77, 0, 0, 87, 0, 0, 87, 0, 0, 82, 0, 0, 116, 0, 0, 138, 0, 0, 164, 0, 0, 233, 0, 0, 277, 0, 0, 329, 0, 0, 174, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 82, 0, 0, 116, 0, 0, 138, 0, 0, 164, 0, 0, 233, 0, 0, 277, 0, 0, 329, 0, 0, 174, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 116, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 97, 0, 0, 110, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 77, 0, 0, 92, 0, 0, 92, 0, 0, 138, 0, 0, 138, 0, 0, 138, 0, 0, 123, 0, 0, 138, 0, 0, 138, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 116, 0, 0, 123, 0, 0, 123, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 103, 0, 0, 103, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 97, 0, 0, 110, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 103, 0, 0, 103, 0, 0, 92, 0, 0, 92, 0, 0, 92, 0, 0, 77, 0, 0, 92, 0, 0, 92, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 77, 0, 0, 87, 0, 0, 87, 0, 0, 82, 0, 0, 116, 0, 0, 138, 0, 0, 164, 0, 0, 233, 0, 0, 277, 0, 0, 329, 0, 0, 174, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 82, 0, 0, 116, 0, 0, 138, 0, 0, 164, 0, 0, 233, 0, 0, 277, 0, 0, 329, 0, 0, 174, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 116, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 123, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 103, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 130, 0, 0, 87, 0, 0, 87, 0, 0, 87, 0, 0, 97, 0, 0, 110, 0, 0, 87, 0};
/**
 * @brief zelda_bass melody durations in miliseconds.
 *
 * This array contains the duration of each note in the zelda_bass song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t zelda_bass_durations[ZELDA_BASS_LENGTH] = {294, 33, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 334, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 299, 34, 1, 299, 34, 1, 299, 34, 1, 149, 17, 1, 149, 17, 1, 1199, 134};
/**
 * @brief zelda_bass melody struct.
 *
 * This struct contains the information of the zelda_bass melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t zelda_bass = {
    .p_name = "zelda_bass",
    .p_notes = (double *)zelda_bass_notes,
    .p_durations = (uint16_t *)zelda_bass_durations,
    .melody_length = ZELDA_BASS_LENGTH,
    .next_melody = (const melody_t *)&zelda_trombone};

#define ZELDA_TROMBONE_LENGTH 674 /*!< zelda_trombone melody length */
/**
 * @brief zelda_trombone melody notes.
 *
 * This array contains the frequencies of the notes for the zelda_trombone song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double zelda_trombone_notes[ZELDA_TROMBONE_LENGTH] = {233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 207, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 207, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 233, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 233, 0, 0, 174, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 415, 0, 0, 466, 0, 0, 466, 0, 0, 466, 0, 0, 415, 0, 0, 369, 0, 0, 415, 0, 0, 369, 0, 0, 349, 0, 0, 349, 0, 0, 311, 0, 0, 311, 0, 0, 349, 0, 0, 369, 0, 0, 349, 0, 0, 311, 0, 0, 277, 0, 0, 277, 0, 0, 311, 0, 0, 349, 0, 0, 311, 0, 0, 277, 0, 0, 261, 0, 0, 261, 0, 0, 293, 0, 0, 329, 0, 0, 391, 0, 0, 349, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 233, 0, 0, 174, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 415, 0, 0, 466, 0, 0, 554, 0, 0, 523, 0, 0, 440, 0, 0, 349, 0, 0, 369, 0, 0, 466, 0, 0, 440, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 466, 0, 0, 440, 0, 0, 349, 0, 0, 293, 0, 0, 311, 0, 0, 369, 0, 0, 349, 0, 0, 277, 0, 0, 233, 0, 0, 261, 0, 0, 261, 0, 0, 293, 0, 0, 329, 0, 0, 391, 0, 0, 349, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 233, 0, 0, 174, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 415, 0, 0, 466, 0, 0, 466, 0, 0, 466, 0, 0, 415, 0, 0, 369, 0, 0, 415, 0, 0, 369, 0, 0, 349, 0, 0, 349, 0, 0, 311, 0, 0, 311, 0, 0, 349, 0, 0, 369, 0, 0, 349, 0, 0, 311, 0, 0, 277, 0, 0, 277, 0, 0, 311, 0, 0, 349, 0, 0, 311, 0, 0, 277, 0, 0, 261, 0, 0, 261, 0, 0, 293, 0, 0, 329, 0, 0, 391, 0, 0, 349, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 233, 0, 0, 174, 0, 0, 233, 0, 0, 233, 0, 0, 261, 0, 0, 293, 0, 0, 311, 0, 0, 349, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 415, 0, 0, 466, 0, 0, 554, 0, 0, 523, 0, 0, 440, 0, 0, 349, 0, 0, 369, 0, 0, 466, 0, 0, 440, 0, 0, 349, 0, 0, 349, 0, 0, 369, 0, 0, 466, 0, 0, 440, 0, 0, 349, 0, 0, 293, 0, 0, 311, 0, 0, 369, 0, 0, 349, 0, 0, 277, 0, 0, 233, 0, 0, 261, 0, 0, 261, 0, 0, 293, 0, 0, 329, 0, 0, 391, 0, 0, 349, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 174, 0, 0, 233, 0};
/**
 * @brief zelda_trombone melody durations in miliseconds.
 *
 * This array contains the duration of each note in the zelda_trombone song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t zelda_trombone_durations[ZELDA_TROMBONE_LENGTH] = {594, 66, 223, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 499, 56, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 499, 56, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 524, 59, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 749, 84, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 799, 89, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 524, 59, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 749, 84, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 524, 59, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 749, 84, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 799, 89, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 199, 23, 1, 99, 11, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 149, 17, 1, 149, 17, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 299, 34, 1, 524, 59, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 74, 9, 1, 749, 84, 1, 149, 17, 1, 99, 11, 1, 99, 11, 1, 99, 11, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 899, 100, 1, 299, 34, 1, 299, 34, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 599, 67, 1, 299, 34, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 74, 9, 1, 74, 9, 1, 149, 17, 1, 149, 17, 1, 1199, 134};
/**
 * @brief zelda_trombone melody struct.
 *
 * This struct contains the information of the zelda_trombone melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t zelda_trombone = {
    .p_name = "zelda_trombone",
    .p_notes = (double *)zelda_trombone_notes,
    .p_durations = (uint16_t *)zelda_trombone_durations,
    .melody_length = ZELDA_TROMBONE_LENGTH,
    .next_melody = NULL};

#define MEGALOVANIA_LENGTH 1226 /*!< megalovania melody length */
/**
 * @brief megalovania melody notes.
 *
 * This array contains the frequencies of the notes for the megalovania song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double megalovania_notes[MEGALOVANIA_LENGTH] = {293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 261, 0, 261, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 246, 0, 246, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 233, 0, 233, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 261, 0, 261, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 246, 0, 246, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 233, 0, 233, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 587, 0, 587, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 523, 0, 523, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 493, 0, 493, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 466, 0, 466, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 587, 0, 587, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 523, 0, 523, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 493, 0, 493, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 466, 0, 466, 0, 1174, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 698, 0, 0, 698, 0, 698, 0, 698, 0, 698, 0, 587, 0, 587, 0, 698, 0, 698, 0, 698, 0, 783, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 783, 0, 698, 0, 0, 698, 0, 698, 0, 783, 0, 830, 0, 880, 0, 1046, 0, 0, 880, 0, 1174, 0, 1174, 0, 1174, 0, 880, 0, 1174, 0, 1046, 0, 698, 0, 0, 880, 0, 880, 0, 880, 0, 880, 0, 783, 0, 783, 0, 698, 0, 0, 880, 0, 880, 0, 880, 0, 783, 0, 880, 0, 1174, 0, 880, 0, 783, 0, 698, 0, 698, 0, 587, 0, 587, 0, 1046, 0, 698, 0, 587, 0, 659, 0, 466, 0, 523, 0, 587, 0, 0, 466, 0, 1046, 0, 0, 698, 0, 587, 0, 698, 0, 783, 0, 830, 0, 783, 0, 698, 0, 587, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 0, 523, 0, 0, 830, 0, 880, 0, 1046, 0, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 659, 0, 698, 0, 783, 0, 880, 0, 1046, 0, 1108, 0, 830, 0, 830, 0, 783, 0, 698, 0, 622, 0, 349, 0, 391, 0, 440, 0, 698, 0, 659, 0, 440, 0, 391, 0, 698, 0, 783, 0, 440, 0, 587, 0, 880, 0, 830, 0, 783, 0, 739, 0, 698, 0, 659, 0, 622, 0, 587, 0, 554, 0, 622, 0, 0, 698, 0, 587, 0, 698, 0, 783, 0, 830, 0, 783, 0, 698, 0, 587, 0, 830, 0, 783, 0, 698, 0, 587, 0, 698, 0, 0, 783, 0, 0, 830, 0, 880, 0, 1046, 0, 0, 880, 0, 830, 0, 783, 0, 698, 0, 587, 0, 659, 0, 698, 0, 783, 0, 880, 0, 1046, 0, 554, 0, 830, 0, 830, 0, 783, 0, 698, 0, 622, 0, 349, 0, 391, 0, 440, 0, 698, 0, 659, 0, 440, 0, 391, 0, 698, 0, 783, 0, 440, 0, 587, 0, 880, 0, 830, 0, 783, 0, 739, 0, 698, 0, 659, 0, 622, 0, 587, 0, 415, 0, 466, 0, 233, 0, 349, 0, 329, 0, 293, 0, 349, 0, 0, 233, 0, 349, 0, 329, 0, 293, 0, 293, 0, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 261, 0, 261, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 246, 0, 246, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 246, 0, 246, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 261, 0, 261, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 0, 587, 0, 698, 0, 659, 0, 0, 415, 0, 659, 0, 0, 349, 0, 440, 0, 523, 0, 349, 0, 0, 587, 0, 698, 0, 440, 0, 0, 415, 0, 391, 0, 0, 349, 0, 261, 0, 523, 0, 587, 0, 466, 0, 466, 0, 349, 0, 349, 0, 466, 0, 349, 0, 466, 0, 349, 0, 349, 0, 391, 0, 523, 0, 391, 0, 391, 0, 523, 0, 391, 0, 523, 0, 391, 0, 391, 0, 440, 0, 587, 0, 440, 0, 440, 0, 554, 0, 415, 0, 554, 0, 415, 0, 415, 0, 391, 0, 523, 0, 391, 0, 391, 0, 493, 0, 391, 0, 493, 0, 391, 0, 391, 0, 349, 0, 466, 0, 349, 0, 349, 0, 466, 0, 349, 0, 466, 0, 349, 0, 349, 0, 391, 0, 523, 0, 391, 0, 391, 0, 523, 0, 391, 0, 523, 0, 391, 0, 391, 0, 440, 0, 587, 0, 440, 0, 440, 0, 587, 0, 440, 0, 587, 0, 440, 0, 440, 0, 440, 0, 587, 0, 440, 0, 440, 0, 587, 0, 440, 0, 587, 0, 440, 0, 440, 0, 466, 0, 466, 0, 349, 0, 349, 0, 466, 0, 349, 0, 466, 0, 349, 0, 349, 0, 391, 0, 523, 0, 391, 0, 391, 0, 523, 0, 391, 0, 523, 0, 391, 0, 391, 0, 440, 0, 587, 0, 440, 0, 440, 0, 554, 0, 415, 0, 554, 0, 415, 0, 415, 0, 391, 0, 523, 0, 391, 0, 391, 0, 493, 0, 391, 0, 493, 0, 391, 0, 391, 0, 349, 0, 466, 0, 349, 0, 349, 0, 466, 0, 349, 0, 466, 0, 349, 0, 349, 0, 391, 0, 523, 0, 391, 0, 391, 0, 523, 0, 391, 0, 523, 0, 391, 0, 391, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 233, 0, 233, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 261, 0, 261, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0, 293, 0, 293, 0, 587, 0, 440, 0, 415, 0, 391, 0, 349, 0, 293, 0, 349, 0, 391, 0};
/**
 * @brief megalovania melody durations in miliseconds.
 *
 * This array contains the duration of each note in the megalovania song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t megalovania_durations[MEGALOVANIA_LENGTH] = {98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 489, 54, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 293, 33, 98, 11, 109, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 109, 293, 33, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 880, 98, 98, 11, 109, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 489, 54, 98, 11, 109, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 109, 196, 21, 880, 98, 870, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 49, 5, 49, 5, 49, 5, 49, 5, 98, 11, 109, 783, 87, 109, 196, 21, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 880, 98, 196, 21, 196, 21, 196, 21, 196, 21, 391, 44, 391, 44, 391, 44, 391, 44, 391, 44, 391, 44, 783, 87, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 685, 76, 880, 98, 870, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 49, 5, 49, 5, 49, 5, 49, 5, 98, 11, 109, 783, 87, 109, 196, 21, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 880, 98, 196, 21, 196, 21, 196, 21, 196, 21, 391, 44, 391, 44, 391, 44, 391, 44, 391, 44, 391, 44, 783, 87, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 685, 76, 880, 98, 1174, 130, 391, 44, 783, 87, 783, 87, 1565, 174, 1739, 1174, 130, 391, 44, 783, 87, 783, 87, 1565, 174, 1739, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 217, 147, 16, 49, 5, 98, 11, 217, 196, 21, 98, 11, 109, 196, 21, 98, 11, 98, 11, 98, 11, 217, 147, 16, 49, 5, 98, 11, 217, 196, 21, 98, 11, 109, 196, 21, 98, 11, 98, 11, 98, 11, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 196, 21, 293, 33, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11};
/**
 * @brief megalovania melody struct.
 *
 * This struct contains the information of the megalovania melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t megalovania = {
    .p_name = "megalovania",
    .p_notes = (double *)megalovania_notes,
    .p_durations = (uint16_t *)megalovania_durations,
    .melody_length = MEGALOVANIA_LENGTH,
    .next_melody = (const melody_t *)&megalovania_secondary};

#define MEGALOVANIA_SECONDARY_LENGTH 1211 /*!< megalovania_secondary melody length */
/**
 * @brief megalovania_secondary melody notes.
 *
 * This array contains the frequencies of the notes for the megalovania_secondary song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double megalovania_secondary_notes[MEGALOVANIA_SECONDARY_LENGTH] = {9, 0, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 116, 0, 116, 0, 116, 0, 116, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 146, 0, 73, 0, 146, 0, 146, 0, 146, 0, 73, 0, 146, 0, 146, 0, 146, 0, 65, 0, 65, 0, 130, 0, 130, 0, 65, 0, 130, 0, 65, 0, 130, 0, 65, 0, 123, 0, 123, 0, 61, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 116, 0, 116, 0, 58, 0, 116, 0, 65, 0, 130, 0, 130, 0, 130, 0, 130, 0, 146, 0, 146, 0, 73, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 130, 0, 130, 0, 65, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 123, 0, 123, 0, 61, 0, 61, 0, 123, 0, 61, 0, 123, 0, 61, 0, 123, 0, 116, 0, 116, 0, 58, 0, 58, 0, 65, 0, 65, 0, 130, 0, 65, 0, 130, 0, 146, 0, 220, 0, 146, 0, 220, 0, 220, 0, 220, 0, 146, 0, 220, 0, 146, 0, 130, 0, 195, 0, 195, 0, 195, 0, 130, 0, 130, 0, 195, 0, 130, 0, 130, 0, 195, 0, 195, 0, 195, 0, 123, 0, 123, 0, 123, 0, 195, 0, 195, 0, 123, 0, 174, 0, 174, 0, 174, 0, 174, 0, 130, 0, 130, 0, 130, 0, 130, 0, 195, 0, 220, 0, 220, 0, 220, 0, 220, 0, 220, 0, 220, 0, 220, 0, 220, 0, 146, 0, 130, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 130, 0, 123, 0, 123, 0, 195, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 195, 0, 174, 0, 174, 0, 116, 0, 116, 0, 130, 0, 195, 0, 130, 0, 195, 0, 195, 0, 174, 0, 116, 0, 174, 0, 116, 0, 116, 0, 116, 0, 116, 0, 116, 0, 116, 0, 195, 0, 195, 0, 195, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 220, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 138, 0, 207, 0, 207, 0, 138, 0, 155, 0, 155, 0, 233, 0, 155, 0, 155, 0, 116, 0, 116, 0, 116, 0, 174, 0, 174, 0, 174, 0, 174, 0, 174, 0, 116, 0, 130, 0, 130, 0, 130, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 130, 0, 146, 0, 146, 0, 146, 0, 220, 0, 220, 0, 220, 0, 220, 0, 220, 0, 220, 0, 138, 0, 138, 0, 138, 0, 207, 0, 155, 0, 233, 0, 155, 0, 233, 0, 155, 0, 116, 0, 116, 0, 174, 0, 116, 0, 116, 0, 116, 0, 116, 0, 116, 0, 116, 0, 195, 0, 195, 0, 195, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 220, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 207, 0, 207, 0, 138, 0, 138, 0, 155, 0, 155, 0, 233, 0, 155, 0, 155, 0, 174, 0, 174, 0, 174, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 116, 0, 195, 0, 130, 0, 195, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 130, 0, 220, 0, 146, 0, 146, 0, 220, 0, 220, 0, 220, 0, 146, 0, 220, 0, 146, 0, 138, 0, 138, 0, 138, 0, 207, 0, 155, 0, 155, 0, 233, 0, 155, 0, 155, 0, 174, 0, 116, 0, 116, 0, 116, 0, 174, 0, 174, 0, 174, 0, 174, 0, 174, 0, 195, 0, 130, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 123, 0, 195, 0, 123, 0, 195, 0, 123, 0, 123, 0, 123, 0, 123, 0, 123, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 174, 0, 116, 0, 116, 0, 174, 0, 174, 0, 174, 0, 174, 0, 174, 0, 174, 0, 174, 0, 130, 0, 130, 0, 130, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 116, 0, 116, 0, 174, 0, 116, 0, 116, 0, 116, 0, 116, 0, 116, 0, 116, 0, 195, 0, 130, 0, 195, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 195, 0, 195, 0, 123, 0, 195, 0, 195, 0, 195, 0, 195, 0, 123, 0, 195, 0, 123, 0, 123, 0, 195, 0, 195, 0, 195, 0, 195, 0, 195, 0, 123, 0, 195, 0, 174, 0, 174, 0, 116, 0, 116, 0, 174, 0, 116, 0, 174, 0, 116, 0, 116, 0, 130, 0, 195, 0, 130, 0, 130, 0, 195, 0, 130, 0, 195, 0, 130, 0, 130, 0, 293, 0, 146, 0, 0, 293, 0, 220, 0, 0, 146, 0, 146, 0, 146, 0, 220, 0, 116, 0, 174, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 130, 0, 195, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 146, 0, 220, 0, 220, 0, 146, 0, 207, 0, 138, 0, 207, 0, 138, 0, 207, 0, 130, 0, 195, 0, 195, 0, 130, 0, 123, 0, 123, 0, 195, 0, 123, 0, 195, 0, 116, 0, 174, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 130, 0, 195, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 146, 0, 220, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 220, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 220, 0, 116, 0, 174, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 130, 0, 195, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 146, 0, 220, 0, 220, 0, 146, 0, 207, 0, 138, 0, 207, 0, 138, 0, 207, 0, 130, 0, 195, 0, 195, 0, 130, 0, 123, 0, 123, 0, 195, 0, 123, 0, 195, 0, 116, 0, 174, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 116, 0, 174, 0, 130, 0, 195, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 130, 0, 195, 0, 220, 0, 220, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 146, 0, 220, 0, 220, 0, 146, 0, 146, 0, 146, 0, 146, 0, 146, 0, 220, 0};
/**
 * @brief megalovania_secondary melody durations in miliseconds.
 *
 * This array contains the duration of each note in the megalovania_secondary song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t megalovania_secondary_durations[MEGALOVANIA_SECONDARY_LENGTH] = {98, 11, 6848, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 98, 11, 98, 11, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 98, 11, 98, 11, 1522, 98, 11, 98, 11, 761, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21, 196, 21, 196, 21, 196, 21, 98, 11, 196, 21};
/**
 * @brief megalovania_secondary melody struct.
 *
 * This struct contains the information of the megalovania_secondary melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t megalovania_secondary = {
    .p_name = "megalovania_secondary",
    .p_notes = (double *)megalovania_secondary_notes,
    .p_durations = (uint16_t *)megalovania_secondary_durations,
    .melody_length = MEGALOVANIA_SECONDARY_LENGTH,
    .next_melody = (const melody_t *)&megalovania_drums};

#define MEGALOVANIA_DRUMS_LENGTH 1744 /*!< megalovania_drums melody length */
/**
 * @brief megalovania_drums melody notes.
 *
 * This array contains the frequencies of the notes for the megalovania_drums song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double megalovania_drums_notes[MEGALOVANIA_DRUMS_LENGTH] = {8, 0, 0, 195, 0, 0, 195, 0, 0, 195, 0, 0, 195, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 65, 0, 82, 0, 65, 0, 82, 0, 0, 82, 0, 0, 65, 0, 103, 0, 82, 0, 103, 0, 65, 0, 103, 0, 82, 0, 65, 0, 103, 0, 103, 0, 82, 0, 65, 0, 65, 0, 103, 0, 65, 0, 0, 103, 0, 103, 0, 82, 0, 103, 0, 103, 0, 103, 0, 82, 0, 65, 0, 103, 0, 103, 0, 82, 0, 65, 0, 65, 0, 103, 0, 82, 0, 0, 65, 0, 103, 0, 82, 0, 103, 0, 65, 0, 103, 0, 82, 0, 65, 0, 103, 0, 65, 0, 82, 0, 103, 0, 65, 0, 103, 0, 65, 0, 0, 65, 0, 103, 0, 82, 0, 103, 0, 65, 0, 82, 0, 0, 82, 0, 103, 0, 65, 0, 82, 0, 138, 0, 65, 0, 103, 0, 220, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 220, 0, 116, 0, 65, 0, 82, 0, 0, 220, 0, 0, 220, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 220, 0, 116, 0, 82, 0, 65, 0, 82, 0, 220, 0, 0, 220, 0, 0, 82, 0, 0, 116, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 116, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 116, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 116, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 116, 0, 82, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 138, 0, 116, 0, 82, 0, 220, 0, 0, 220, 0, 0, 82, 0, 0, 116, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 116, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 116, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 116, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 116, 0, 82, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 138, 0, 116, 0, 82, 0, 220, 0, 0, 220, 0, 0, 116, 0, 0, 116, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 116, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 116, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 0, 116, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 116, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 0, 116, 0, 82, 0, 116, 0, 65, 0, 116, 0, 65, 0, 116, 0, 138, 0, 65, 0, 82, 0, 220, 0, 0, 220, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 82, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 82, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 82, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 82, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 82, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 82, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 195, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 65, 0, 0, 103, 0, 0, 82, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 103, 0, 0, 103, 0, 0, 103, 0, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 65, 0, 103, 0, 0, 103, 0, 82, 0, 0, 220, 0, 0, 138, 0, 0, 220, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 65, 0, 82, 0, 65, 0, 82, 0, 0, 220, 0, 0, 220, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 116, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 65, 0, 82, 0, 82, 0, 65, 0, 82, 0, 220, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 220, 0, 116, 0, 65, 0, 82, 0, 0, 220, 0, 0, 220, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 65, 0, 116, 0, 65, 0, 116, 0, 65, 0, 65, 0, 0, 116, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 116, 0, 65, 0, 116, 0, 65, 0, 82, 0, 65, 0, 65, 0, 0, 82, 0, 0, 65, 0, 0, 82, 0, 0, 65, 0, 82, 0, 116, 0, 82, 0, 116, 0, 220, 0, 116, 0, 82, 0, 65, 0, 82, 0, 220, 0};
/**
 * @brief megalovania_drums melody durations in miliseconds.
 *
 * This array contains the duration of each note in the megalovania_drums song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t megalovania_drums_durations[MEGALOVANIA_DRUMS_LENGTH] = {24, 3, 13016, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 98, 11, 2717, 98, 11, 109, 98, 11, 109, 196, 21, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 109, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11, 98, 11};
/**
 * @brief megalovania_drums melody struct.
 *
 * This struct contains the information of the megalovania_drums melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t megalovania_drums = {
    .p_name = "megalovania_drums",
    .p_notes = (double *)megalovania_drums_notes,
    .p_durations = (uint16_t *)megalovania_drums_durations,
    .melody_length = MEGALOVANIA_DRUMS_LENGTH,
    .next_melody = NULL};

#define COCONUT_MALL_LENGTH 294 /*!< coconut_mall melody length */
/**
 * @brief coconut_mall melody notes.
 *
 * This array contains the frequencies of the notes for the coconut_mall song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double coconut_mall_notes[COCONUT_MALL_LENGTH] = {523, 0, 0, 523, 0, 0, 523, 0, 0, 466, 0, 0, 523, 0, 0, 466, 0, 0, 523, 0, 0, 523, 0, 261, 0, 0, 523, 0, 0, 466, 0, 0, 311, 0, 0, 466, 0, 0, 523, 0, 0, 523, 0, 261, 0, 0, 523, 0, 0, 466, 0, 0, 523, 0, 0, 466, 0, 0, 523, 0, 0, 523, 0, 0, 523, 0, 0, 293, 0, 311, 0, 329, 0, 0, 293, 0, 293, 0, 329, 0, 349, 0, 523, 0, 0, 587, 0, 0, 523, 0, 0, 587, 0, 0, 523, 0, 0, 466, 0, 440, 0, 391, 0, 349, 0, 0, 293, 0, 311, 0, 329, 0, 0, 293, 0, 293, 0, 329, 0, 349, 0, 349, 0, 440, 0, 349, 0, 440, 0, 0, 349, 0, 0, 293, 0, 329, 0, 0, 349, 0, 0, 293, 0, 311, 0, 329, 0, 0, 293, 0, 293, 0, 329, 0, 349, 0, 523, 0, 0, 587, 0, 0, 523, 0, 0, 587, 0, 0, 523, 0, 0, 466, 0, 440, 0, 391, 0, 349, 0, 0, 523, 0, 698, 0, 587, 0, 523, 0, 0, 493, 0, 466, 0, 440, 0, 523, 0, 554, 0, 587, 0, 0, 349, 0, 440, 0, 698, 0, 440, 0, 0, 698, 0, 0, 587, 0, 659, 0, 0, 698, 0, 311, 0, 329, 0, 349, 0, 0, 311, 0, 311, 0, 349, 0, 369, 0, 554, 0, 0, 622, 0, 0, 554, 0, 0, 622, 0, 0, 554, 0, 0, 493, 0, 466, 0, 415, 0, 369, 0, 0, 311, 0, 329, 0, 349, 0, 0, 311, 0, 311, 0, 349, 0, 369, 0, 369, 0, 466, 0, 369, 0, 466, 0, 0, 369, 0, 0, 311, 0, 349, 0, 0, 369, 0};
/**
 * @brief coconut_mall melody durations in miliseconds.
 *
 * This array contains the duration of each note in the coconut_mall song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t coconut_mall_durations[COCONUT_MALL_LENGTH] = {85, 10, 95, 85, 10, 189, 85, 10, 95, 85, 10, 95, 85, 10, 379, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 379, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 379, 85, 10, 95, 85, 10, 95, 85, 10, 95, 852, 95, 189, 170, 19, 170, 19, 170, 19, 95, 170, 19, 170, 19, 85, 10, 170, 19, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 379, 170, 19, 170, 19, 170, 19, 95, 170, 19, 170, 19, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 758, 170, 19, 170, 19, 170, 19, 95, 170, 19, 170, 19, 85, 10, 170, 19, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 189, 170, 19, 170, 19, 170, 19, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 170, 19, 170, 19, 170, 19, 95, 170, 19, 170, 19, 85, 10, 170, 19, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 379, 170, 19, 170, 19, 170, 19, 95, 170, 19, 170, 19, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10};
/**
 * @brief coconut_mall melody struct.
 *
 * This struct contains the information of the coconut_mall melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t coconut_mall = {
    .p_name = "coconut_mall",
    .p_notes = (double *)coconut_mall_notes,
    .p_durations = (uint16_t *)coconut_mall_durations,
    .melody_length = COCONUT_MALL_LENGTH,
    .next_melody = (const melody_t *)&coconut_mall_secondary};

#define COCONUT_MALL_SECONDARY_LENGTH 214 /*!< coconut_mall_secondary melody length */
/**
 * @brief coconut_mall_secondary melody notes.
 *
 * This array contains the frequencies of the notes for the coconut_mall_secondary song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double coconut_mall_secondary_notes[COCONUT_MALL_SECONDARY_LENGTH] = {659, 0, 0, 349, 0, 349, 0, 0, 659, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 659, 0, 0, 349, 0, 349, 0, 0, 659, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 659, 0, 0, 349, 0, 349, 0, 0, 659, 0, 0, 587, 0, 0, 587, 0, 0, 587, 0, 0, 659, 0, 0, 349, 0, 0, 9, 0, 0, 1046, 0, 0, 1174, 0, 0, 1046, 0, 0, 1174, 0, 0, 1046, 0, 0, 932, 0, 880, 0, 783, 0, 698, 0, 0, 698, 0, 880, 0, 698, 0, 880, 0, 0, 698, 0, 0, 587, 0, 659, 0, 0, 698, 0, 0, 8, 0, 0, 1046, 0, 0, 1174, 0, 0, 1046, 0, 0, 1174, 0, 0, 1046, 0, 0, 932, 0, 880, 0, 783, 0, 698, 0, 0, 1046, 0, 1396, 0, 1174, 0, 1046, 0, 0, 987, 0, 932, 0, 880, 0, 1046, 0, 1108, 0, 1174, 0, 0, 880, 0, 0, 880, 0, 0, 8, 0, 0, 1108, 0, 0, 1244, 0, 0, 1108, 0, 0, 1244, 0, 0, 1108, 0, 0, 987, 0, 932, 0, 830, 0, 739, 0, 0, 739, 0, 932, 0, 739, 0, 932, 0, 0, 739, 0, 0, 622, 0, 698, 0, 0, 739, 0};
/**
 * @brief coconut_mall_secondary melody durations in miliseconds.
 *
 * This array contains the duration of each note in the coconut_mall_secondary song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t coconut_mall_secondary_durations[COCONUT_MALL_SECONDARY_LENGTH] = {85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 284, 85, 10, 189, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 284, 85, 10, 189, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 284, 85, 10, 189, 85, 10, 95, 85, 10, 95, 85, 10, 95, 1534, 171, 758, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 1610, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10, 758, 1023, 113, 189, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 189, 170, 19, 170, 19, 170, 19, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 85, 10, 189, 85, 10, 95, 85, 10, 473, 1364, 151, 758, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 1610, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 85, 10};
/**
 * @brief coconut_mall_secondary melody struct.
 *
 * This struct contains the information of the coconut_mall_secondary melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t coconut_mall_secondary = {
    .p_name = "coconut_mall_secondary",
    .p_notes = (double *)coconut_mall_secondary_notes,
    .p_durations = (uint16_t *)coconut_mall_secondary_durations,
    .melody_length = COCONUT_MALL_SECONDARY_LENGTH,
    .next_melody = (const melody_t *)&coconut_mall_third};

#define COCONUT_MALL_THIRD_LENGTH 191 /*!< coconut_mall_third melody length */
/**
 * @brief coconut_mall_third melody notes.
 *
 * This array contains the frequencies of the notes for the coconut_mall_third song.
 * The notes are defined as frequency values in Hertz, and they are arranged in the order they are played in the song.
 */
static const double coconut_mall_third_notes[COCONUT_MALL_THIRD_LENGTH] = {8, 0, 0, 9, 0, 0, 9, 0, 0, 97, 0, 65, 0, 87, 0, 87, 0, 0, 87, 0, 87, 0, 0, 92, 0, 97, 0, 65, 0, 87, 0, 87, 0, 0, 87, 0, 87, 0, 0, 92, 0, 97, 0, 65, 0, 87, 0, 87, 0, 0, 87, 0, 87, 0, 0, 92, 0, 97, 0, 65, 0, 87, 0, 0, 65, 0, 87, 0, 0, 97, 0, 65, 0, 87, 0, 87, 0, 0, 87, 0, 87, 0, 0, 92, 0, 97, 0, 65, 0, 87, 0, 87, 0, 0, 87, 0, 87, 0, 0, 87, 0, 116, 0, 123, 0, 130, 0, 138, 0, 146, 0, 0, 146, 0, 110, 0, 103, 0, 97, 0, 0, 97, 0, 0, 130, 0, 130, 0, 0, 87, 0, 0, 103, 0, 69, 0, 92, 0, 92, 0, 0, 92, 0, 92, 0, 0, 97, 0, 103, 0, 69, 0, 92, 0, 92, 0, 0, 92, 0, 92, 0, 0, 97, 0, 103, 0, 69, 0, 92, 0, 92, 0, 0, 92, 0, 92, 0, 0, 97, 0, 103, 0, 69, 0, 92, 0, 0, 69, 0, 92, 0};
/**
 * @brief coconut_mall_third melody durations in miliseconds.
 *
 * This array contains the duration of each note in the coconut_mall_third song.
 * The durations are defined in milliseconds, and they are arranged in the order they are played in the song.
 */
static const uint16_t coconut_mall_third_durations[COCONUT_MALL_THIRD_LENGTH] = {852, 95, 947, 852, 95, 568, 852, 95, 758, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 95, 170, 19, 170, 19, 189, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 341, 38, 170, 19, 85, 10, 85, 10, 95, 85, 10, 85, 10, 85, 10, 85, 10, 95, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 663, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 85, 10, 95, 85, 10, 85, 10, 95, 170, 19, 341, 38, 256, 28, 170, 19, 95, 170, 19, 170, 19};
/**
 * @brief coconut_mall_third melody struct.
 *
 * This struct contains the information of the coconut_mall_third melody.
 * It is used to play the melody using the buzzer.
 */
const melody_t coconut_mall_third = {
    .p_name = "coconut_mall_third",
    .p_notes = (double *)coconut_mall_third_notes,
    .p_durations = (uint16_t *)coconut_mall_third_durations,
    .melody_length = COCONUT_MALL_THIRD_LENGTH,
    .next_melody = NULL};
