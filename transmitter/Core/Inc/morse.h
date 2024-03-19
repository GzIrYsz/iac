/*
 * morse.h
 *
 *  Created on: Mar 7, 2024
 *      Author: thomas
 */

#pragma once

/**
 * The duration (in ms) of the elementary rythm.
 */
#define SHORT_BEEP_LENGTH 100

/**
 * Converts a single character to it's morse representation.
 *
 * @param input The input character to convert.
 * @return A string representation of the input character in morse.
 */
char* ctos(char input);

/**
 * Converts an ASCII string to it's morse representation.
 *
 * @param input The input ASCII string to convert.
 * @return A string representation of the input ASCII string in morse.
 */
char* atom(const char *input);

/**
 * Plays the corresponding morse rythms on a buzzer.
 *
 * @param morse A string containing the morse representation of the text to play.
 */
void morse_to_beep(const char *morse, ACT_GPIO_OUT* act_out);

/**
 * Plays a short beep (1 ER) and waits 1 ER.
 */
void short_beep();

/**
 * Plays a long beep (3 ER) and waits 1 ER.
 */
void long_beep();

/**
 * Waits 2 ER for inter letter spacing.
 */
void inter_letters();

/**
 * Waits 4 ER for inter word spacing.
 */
void inter_words();
