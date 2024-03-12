/*
 * morse.c
 *
 *  Created on: Mar 7, 2024
 *      Author: thomas
 */

#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "morse.h"

/**
 * Table du morse dans l'ordre de la table ASCII (debut a 33)
 */
const char *morse_table[] = {
		"-.-.--",	// !
		".-..-.",	// "
		"",			// #
		"...-..-",	// $
		"",			// %
		".-...",	// &
		".----.",	// '
		"-.--.",	// (
		"-.--.-",	// )
		"",			// *
		".-.-.",	// +
		"--..--",	// ,
		"-....-",	// -
		".-.-.-",	// .
		"-..-.",	// /
		"-----",	// 0
		".----",	// 1
		"..---",	// 2
		"...--",	// 3
		"....-",	// 4
		".....",	// 5
		"-....",	// 6
		"--...",	// 7
		"---..",	// 8
		"----.",	// 9
		"---...",	// :
		"-.-.-.",	// ;
		"",			// <
		"-...-",	// =
		"",			// >
		"..--..",	// ?
		".--.-.",	// @
		".-",		// A
		"-...",		// B
		"-.-.",		// C
		"-..",		// D
		".",		// E
		"..-.",		// F
		"--.",		// G
		"....",		// H
		"..",		// I
		".---",		// J
		"-.-",		// K
		".-..",		// L
		"--",		// M
		"-.",		// N
		"---",		// O
		".--.",		// P
		"--.-",		// Q
		".-.",		// R
		"...",		// S
		"-",		// T
		"..-",		// U
		"...-",		// V
		".--",		// W
		"-..-",		// X
		"-.--",		// Y
		"--..",		// Z
		"",			// [
		"",			// '\'
		"",			// ]
		"",			// ^
		"..--.-",	// _
		"",			// `
		".-",		// A
		"-...",		// B
		"-.-.",		// C
		"-..",		// D
		".",		// E
		"..-.",		// F
		"--.",		// G
		"....",		// H
		"..",		// I
		".---",		// J
		"-.-",		// K
		".-..",		// L
		"--",		// M
		"-.",		// N
		"---",		// O
		".--.",		// P
		"--.-",		// Q
		".-.",		// R
		"...",		// S
		"-",		// T
		"..-",		// U
		"...-",		// V
		".--",		// W
		"-..-",		// X
		"-.--",		// Y
		"--..",		// Z
		"",			// {
		"",			// |
		"",			// }
		"",			// ~
};

char* ctos(char input) {
	int index = (int) input;
	if (index > 32 && index < 127) {
		return morse_table[index - 33];
	} else if (index == 32) {
		return "/";
	}
}

char* atom(const char *input) {
	int input_len = strlen(input);
	char *output = (char*) malloc(7 * input_len * sizeof(char));
	output[0] = '\0';

    int i = 0;
	int char_index = (int) input[i];

	if (char_index > 32 && char_index < 127) {
		strcat(output, morse_table[char_index - 33]);
	} else if (char_index == 32) {
		strcat(output, "/");
	}

	for (int i = 1; i < input_len; i++) {
	    strcat(output, " ");
		char_index = (int) input[i];
		if (char_index > 32 && char_index < 127) {
			strcat(output, morse_table[char_index - 33]);
		} else if (char_index == 32) {
			strcat(output, "/");
		}
	}

	return output;
}

void morse_to_beep(const char *morse) {
	int i = 0;
	char symbole;
	while ((symbole = morse[i]) != '\0') {
		switch (symbole) {
		case '.':
			short_beep();
			break;
		case '-':
			long_beep();
			break;
		case ' ':
			inter_letters();
			break;
		case '/':
			inter_words();
		}
		i++;
	}
}

void short_beep() {
	HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, GPIO_PIN_SET);
	HAL_Delay(SHORT_BEEP_LENGTH);
	HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, GPIO_PIN_RESET);
	HAL_Delay(SHORT_BEEP_LENGTH);
}

void long_beep() {
	HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, GPIO_PIN_SET);
	HAL_Delay(3 * SHORT_BEEP_LENGTH);
	HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, GPIO_PIN_RESET);
	HAL_Delay(SHORT_BEEP_LENGTH);
}

void inter_letters() {
	HAL_Delay(2 * SHORT_BEEP_LENGTH);
}

void inter_words() {
	HAL_Delay(2 * SHORT_BEEP_LENGTH);
}
