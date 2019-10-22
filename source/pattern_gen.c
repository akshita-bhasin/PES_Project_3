/*
 * @file pattern_gen.c
 * @brief generates a pattern based on a seed value
 * @author Akshita Bhasin and Madhukar Arora
 * date 10/22/2019
 * @version 1.0
 * leveraged code: // https://www.geeksforgeeks.org/pseudo-random-number-generator-prng/
 */

#include "pattern_gen.h"

/*
 Function Name: gen_pattern
 Function arguments: uint8_t * pattern, size_t length, int8_t seed
 Function return type: void
 Brief: generates a pseudo random number using seed as initial value
 	 and stores in the pattern pointer
*/
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

