/*
 * memorytest.c
 *
 *  Created on: Oct 9, 2019
 *      Author: ASUS
 */
#include "memorytest.h"

uint32_t * allocate_words(size_t length)
{
	if(length > 1024) {
		printf("Invalid allocation request\n");
		return NULL;
	}
	uint32_t * mem_all = (uint32_t *)malloc(length);

	return mem_all;
}
void free_words(uint32_t * src)
{
	if(src==NULL)
		printf("No memory allocated\n");
	free(src);
}

uint8_t * display_memory(uint32_t * loc, size_t length)
{
    return (uint8_t *)loc;
}

mem_status write_memory(uint32_t * loc, uint8_t value)
{
	if(loc==NULL) {
		printf("Invalid address\n");
		return FAILED;
	}
	else
	{
		uint8_t * write_mem = (uint8_t *) loc;
		* write_mem = value;
		return SUCCESS;
	}
}

mem_status invert_block(uint32_t * loc, size_t length){
	if(loc==NULL) {
		return FAILED;
	}
	else
	{
		uint8_t * temp = (uint8_t*) loc;
		uint8_t i;
		for(i=0; i<length;i++) {
			*(temp+i) ^= (uint8_t) 0xFF;
		}
		return SUCCESS;
	}
}

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed){
	uint8_t * gener_pattern;
	gener_pattern = (uint8_t *) loc;
	if(loc==NULL) {
		return FAILED;
	}
	gen_pattern(gener_pattern, length, seed);
	return SUCCESS;
}
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed){
	extern uint32_t verify_arr[16];
	uint8_t i,j=0;
	uint8_t verify_success = 1;
	uint8_t ver_pattern[length];
	uint8_t * stored_pattern = (uint8_t *) loc;
	gen_pattern(ver_pattern, length, seed);

	for(i=0;i<length;i++)
	{
		if(*(stored_pattern+i) == ver_pattern[i])
		{
			continue;
		}
		else if(*(stored_pattern+i) != ver_pattern[i]) {
			verify_arr[j] = (uint32_t)(stored_pattern +i);
			j++;
			verify_success = 0;
		}
	}
	if(verify_success==1)
		verify_arr[0]=0;

	log_data((uint8_t *)verify_arr, j+1);

	return verify_arr;
}
uint32_t * get_address(uint32_t * base_addr, uint8_t offset) {
	uint8_t * temp_addr = (uint8_t *) base_addr;
	base_addr = (uint32_t *) (temp_addr + offset);
	return base_addr;
}
