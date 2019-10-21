/**
 * @file    main.c
 * @brief   Application entry point.
 */
#include "main.h"

uint32_t verify_arr[16];
size_t valueLength;
uint8_t exceptions=0;

size_t pointer_length(uint32_t * addr, size_t length);


int main(void) {
#ifdef KL25Z
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	BOARD_InitDebugConsole();
#endif

#ifdef KL25Z_LOG
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	BOARD_InitDebugConsole();
#endif
	const int8_t seed = 8;

	uint32_t * valuesNoMatch = NULL;
#ifdef KL25Z
	turn_on_led_color('B');
	log_disable();
#endif

#ifdef PC
	log_disable();
#endif

#ifdef KL25Z_LOG
	turn_on_led_color('B');
	log_enable();
#endif

#ifdef PC_LOG
	log_enable();
#endif

	log_string("Allocating 16 bytes of data");
  	uint32_t * mem = allocate_words(LENGTH);
  	uint32_t offset = (uint32_t) 0x0004;
  	log_string("Writing a pattern at allocated memory location with seed 0x08");
  	uint8_t status = write_pattern(mem, LENGTH, seed);
  	if(status==0)
  	  	log_string("Written pattern into memory successfully");
  	 else {
  	 	log_string("Writing pattern to memory failed");
  	 	exceptions=1;
  	}
  	printf("%02x", status);
  	log_string("Displaying memory location of 16 bytes");
  	uint8_t * disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);

  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should pass

  	if(valuesNoMatch[0] == 0) {
  		log_string("Verify pattern successful");
  	}
  	else {
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  		//turn_on_led_color('R');
  		exceptions=1;
  	}

  	uint32_t * addressUpdate = get_address(mem, offset);
  	log_string("Address updated with location + offset");
  	log_integer(addressUpdate, 1);

  	status = write_memory(get_address(addressUpdate, 1), 0xFF);
  	if(status==0)
  		log_string("Written into memory successfully");
  	else {
  		log_string("Writing to memory failed");
  		exceptions=1;
  	}
  	status = write_memory(get_address(addressUpdate, 2), 0xEE);
  	if(status==0)
  		log_string("Written into memory successfully");
  	else {
  		log_string("Writing to memory failed");
  		exceptions=	1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);
  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should fail
  	if(valuesNoMatch[0] == 0) {
  		log_string("Verify pattern successful");
  		exceptions=1;
  	}
  	else {
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  	}
  	status = write_pattern(mem, LENGTH, seed);
  	if(status==0)
  		log_string("Written pattern into memory successfully");
  	else {
  		log_string("Writing pattern to memory failed");
  		exceptions=1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);
  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should pass
  	if(valuesNoMatch[0] == 0) {
  		log_string("Verify pattern successful");
  	}
  	else {
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  		exceptions=1;
  	}
  	status = invert_block(get_address(mem, offset), 4);
  	if(status==0)
  		log_string("Inverting memory block successful");
  	else {
  		log_string("Failed to invert memory block");
  		exceptions=1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);
  	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should fail
  	if(valuesNoMatch[0] == 0) {
  		log_string("Verify pattern successful");
  		exceptions=1;
  	}
  	else {
  		pointer_length(valuesNoMatch, LENGTH);
  		log_string("Verify pattern failed at the following addresses for seed 0x08");
  		log_integer(valuesNoMatch, valueLength);
  	}
  	status = invert_block(get_address(mem, offset), 4);
  	if(status==0)
  	  	log_string("Inverting memory block successful");
  	else {
  	  	log_string("Failed to invert memory block");
  	  	exceptions=1;
  	}
  	log_string("Displaying memory location of 16 bytes");
  	disp_mem = display_memory(mem, LENGTH);
  	log_data(disp_mem, LENGTH);

 	valuesNoMatch = verify_pattern(mem, LENGTH, seed); // should pass
  	if(valuesNoMatch[0] == 0) {
  		log_string("Verify pattern successful");
  	}
  	else {
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

    return 0 ;
}

size_t pointer_length(uint32_t * addr, size_t length) {
	uint8_t i;
	for(i=0;i<length;i++) {
		if(addr[i]!=0)
			valueLength++;
	}
	return valueLength;
}
