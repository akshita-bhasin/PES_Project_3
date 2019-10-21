/*
 * pattern_gen.h
 *
 *  Created on: Oct 11, 2019
 *      Author: ASUS
 */

#ifndef PATTERN_GEN_H_
#define PATTERN_GEN_H_

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

void gen_pattern(uint8_t * pattern, size_t length, int8_t seed);

#endif /* PATTERN_GEN_H_ */
