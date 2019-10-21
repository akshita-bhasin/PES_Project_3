/*
 * pattern_gen.c
 *
 *  Created on: Oct 11, 2019
 *      Author: ASUS
 */

// https://www.geeksforgeeks.org/pseudo-random-number-generator-prng/
#include "pattern_gen.h"

void gen_pattern(uint8_t * pattern, size_t length, int8_t seed)
{
	uint8_t X[length];
	X[0] = seed;

	uint8_t a=1, c=4, m=9;
	uint8_t i;

	for(i=1; i<length; i++) {
		X[i] = (((a*X[i-1]) + c) % m);
	}

	for(i=0; i<length; i++) {
		* pattern = X[i];
		pattern++;
	}
}

