/*
 * memorytest.h
 *
 *  Created on: Oct 9, 2019
 *      Author: ASUS
 */

#ifndef MEMORYTEST_H_
#define MEMORYTEST_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "logger.h"
#include "pattern_gen.h"

typedef enum mem_status
{
	SUCCESS = 0, // no error
	FAILED // failure case
} mem_status;

uint32_t * allocate_words(size_t length);
void free_words(uint32_t * src);
uint8_t * display_memory(uint32_t * loc, size_t length);
mem_status write_memory(uint32_t * loc, uint8_t value);
mem_status invert_block(uint32_t * loc, size_t length);
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed);
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed);
uint32_t * get_address(uint32_t * base_addr, uint8_t offset);

#endif /* MEMORYTEST_H_ */
