/*
 * @file pattern_gen.h
 * @brief contains function prototypes and header files for pattern_gen.h
 * @author Akshita Bhasin and Madhukar Arora
 * date 10/22/2019
 * @version 1.0
 */

#ifndef PATTERN_GEN_H_
#define PATTERN_GEN_H_

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

void gen_pattern(uint8_t * pattern, size_t length, int8_t seed);

#endif /* PATTERN_GEN_H_ */
