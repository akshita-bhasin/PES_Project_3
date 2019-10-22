/*
 * @file  : main.c
 * @brief : contains calls to all memory tests
 * @author : Akshita Bhasin and Madhukar Arora
 * @date : 10/17/2019
 * @version 1.0
 */

#include "main.h"

uint32_t * valuesNoMatch = NULL; // global pointer used
uint32_t verify_arr[16]; // global array used
size_t valueLength;
uint8_t exceptions=0;

size_t pointer_length(uint32_t * addr, size_t length);


int main(void) {
#ifdef KL25Z //build target = KL25Z
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	BOARD_InitDebugConsole();
#endif

#ifdef KL25Z_LOG //build target = KL25Z_LOG
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	BOARD_InitDebugConsole();
#endif
	const int8_t seed = 8;

#ifdef KL25Z
	turn_on_led_color('B');
	log_disable(); // disable since build target without loggers
#endif

#ifdef PC //build target = PC
	log_disable(); // disable since build target without loggers
#endif

#ifdef KL25Z_LOG
	turn_on_led_color('B');
	log_enable(); // enable since build target with loggers
#endif

#ifdef PC_LOG //build target = PC_LOG
	log_enable(); // enable since build target with loggers
#endif

	log_string("Allocating 16 bytes of data");
  	uint32_t * mem = allocate_words(LENGTH);
  	uint32_t offset = (uint32_t) 0x0004;
  	log_string("Writing a pattern at allocated memory location with seed 0x08");
  	uint8_t status = write_pattern(mem, LENGTH, seed);
  	if(status==0) {
  	  	log_string("Written pattern into memory successfully");
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  	}
  	 else {
  	 	log_string("Writing pattern to memory failed");
#ifdef KL25Z_LOG
  	 	turn_on_led_color('R');
#endif
#ifdef KL25Z
  	 	turn_on_led_color('R');
#endif
  	 	exceptions=1;
  	}
  	printf("%02x", status);
  	log_string("Displaying memory location of 16 bytes");
  	uint8_t * disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);

  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should pass

  	if(valuesNoMatch == NULL) {
  		log_string("Verify pattern successful");
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  	 	turn_on_led_color('G');
#endif
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  		//turn_on_led_color('R');
  		exceptions=1;
  	}

  	uint32_t * addressUpdate = get_address(mem, offset);
  	log_string("Address updated with location + offset");

  	status = write_memory(get_address(addressUpdate, 1), 0xFF);
  	if(status==0) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Written into memory successfully");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		log_string("Writing to memory failed");
  		exceptions=1;
  	}
  	status = write_memory(get_address(addressUpdate, 2), 0xEE);
  	if(status==0) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Written into memory successfully");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		log_string("Writing to memory failed");
  		exceptions=	1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);
  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should fail
  	if(valuesNoMatch == NULL) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Verify pattern successful");
  		exceptions=1;
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  	}
  	status = write_pattern(mem, LENGTH, seed);
  	if(status==0) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Written pattern into memory successfully");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		log_string("Writing pattern to memory failed");
  		exceptions=1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);
  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should pass
  	if(valuesNoMatch == NULL) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Verify pattern successful");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  		exceptions=1;
  	}
  	status = invert_block(get_address(mem, offset), 4);
  	if(status==0) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Inverting memory block successful");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		log_string("Failed to invert memory block");
  		exceptions=1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);
  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should fail
  	if(valuesNoMatch == NULL) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Verify pattern successful");
  		exceptions=1;
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  	}
  	status = invert_block(get_address(mem, offset), 4);
  	if(status==0) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  	  	log_string("Inverting memory block successful");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  	  	log_string("Failed to invert memory block");
  	  	exceptions=1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);

 	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should pass
  	if(valuesNoMatch == NULL) {
#ifdef KL25Z_LOG
  		turn_on_led_color('G');
#endif
#ifdef KL25Z
  		turn_on_led_color('G');
#endif
  		log_string("Verify pattern successful");
  	}
  	else {
#ifdef KL25Z_LOG
  		turn_on_led_color('R');
#endif
#ifdef KL25Z
  		turn_on_led_color('R');
#endif
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  		exceptions=1;
  	}
  	log_string("Freeing allocated memory location");
  	free_words(mem);
#ifdef KL25Z
  	if(exceptions==1)
  		turn_on_led_color('R');
  	else
  		turn_on_led_color('G');
#endif

#ifdef KL25Z_LOG
  	if(exceptions==1)
  		turn_on_led_color('R');
  	else
  		turn_on_led_color('G');
#endif


    return 0 ;
}

/* Function Name: pointer_length
 Function arguments: uint32_t * addr, size_t length
 Function return type: size_t
 Brief: calculates pointer length of stored values in addr
*/
size_t pointer_length(uint32_t * addr, size_t length) {
	valueLength=0; // for every call
	uint8_t i;
	for(i=0;i<length;i++) {
		if(addr[i]!=0)
			valueLength++;
	}
	return valueLength;
}
