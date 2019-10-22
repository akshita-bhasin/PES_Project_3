/*
 * @file : memorytest.c
 * @author : Akshita Bhasin & Madhukar Arora
 *  @brief : contains a suite of memory tests to be run on Freedom Board
 *   and Host Environment
 */

#include "memorytest.h"

/*
 Function Name: allocate_words
 Function arguments: size_t length (number of bytes to be allocated)
 Function return type: uint32_t*
 Brief: allocates a block of memory and returns an address to the allocated block
*/
uint32_t * allocate_words(size_t length)
{
	if((length > 1024) && (length<=0)) {
		printf("Invalid allocation request\n");
		return NULL;
	}
	uint32_t * mem_all = (uint32_t *)malloc(length);

	return mem_all;
}


/*
 Function Name: free_words
 Function arguments: uint32_t * src (address of memory to be freed)
 Function return type: void
 Brief: frees a valid block of memory
*/
void free_words(uint32_t * src)
{
	if(src==NULL)
		printf("No memory allocated\n");
	free(src);
}

/*
 Function Name: display_memory
 Function arguments: uint32_t * loc(address to be displayed), size_t length(number of bytes to be displayed)
 Function return type: uint8_t *
 Brief: displays the contents at a memory location
*/
uint8_t * display_memory(uint32_t * loc, size_t length)
{
    return (uint8_t *)loc;
}

/*
 Function Name: write_memory
 Function arguments: uint32_t * loc(address to be written at),uint8_t value(value to be written at memory location)
 Function return type: mem_status
 Brief: writes the value at a memory location
*/
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

/*
 Function Name: invert_block
 Function arguments: uint32_t * loc(address),size_t length(number of bytes to be inverted)
 Function return type: mem_status
 Brief: inverts all the bits at a memory location using XOR
*/
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

/*
 Function Name: write_pattern
 Function arguments: uint32_t * loc(address),size_t length(number of bytes), int8_t seed(for pattern gen)
 Function return type: mem_status
 Brief: generates a pattern using the pattern generator and writes to memory
*/
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed){
	uint8_t * gener_pattern;
	gener_pattern = (uint8_t *) loc;
	if(loc==NULL) {
		return FAILED;
	}
	gen_pattern(gener_pattern, length, seed);
	return SUCCESS;
}

/*
 Function Name: verify_pattern
 Function arguments: uint32_t * loc(address),size_t length(number of bytes), int8_t seed(for pattern gen)
 Function return type: uint32_t*
 Brief: generates a new pattern and checks if it matches with the base pattern generated in memory
*/
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
			verify_arr[j] = (uint32_t)(stored_pattern+i);
			j++;
			verify_success = 0;
		}
	}
	if(verify_success==1)
		return NULL;
		//verify_arr[0]=0;

	return verify_arr;
}

/*
 Function Name: get_address
 Function arguments: uint32_t * base_addr(address),uint8_t offset(offset value)
 Function return type: uint32_t*
 Brief: returns an address which is calculated by adding the base address and offset value
*/
uint32_t * get_address(uint32_t * base_addr, uint8_t offset) {
	uint8_t * temp_addr = (uint8_t *) base_addr;
	base_addr = (uint32_t *) (temp_addr + offset);
	return base_addr;
}
