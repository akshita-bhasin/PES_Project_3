/*
 * logger.c
 *
 *  Created on: Oct 9, 2019
 *      Author: ASUS
 */

#include "logger.h"

uint8_t logger_status=0;

void log_enable()
{
	logger_status=1;
}

void log_disable()
{
	logger_status=0;
}

uint8_t log_status()
{
	return logger_status;
}

void log_data(uint8_t * seqAddr, size_t length)
{
	if(logger_status==1){
	#ifdef KL25Z
		PRINTF("Contents at memory location 0X%x: \n\r",seqAddr);
	#else
		printf("Contents at memory location 0X%x: \n\r",seqAddr);
	#endif
		for(uint8_t i=0;i<length;i++){
		#ifdef KL25Z
			PRINTF("0x%x ",*(seqAddr+i));
		#else
			printf("0x%x ",*(seqAddr+i));
		#endif
		}
	#ifdef KL25Z
		PRINTF("\n\r");
	#else
		printf("\n\r");
	#endif
	}
}

void log_string(char * dispStr)
{
	if(logger_status==1) {
	#ifdef KL25Z
		PRINTF("%s\n\r", dispStr);
	#else
		printf("%s\n\r", dispStr);
	#endif
	}
}

void log_integer(uint32_t * dispInt, size_t length)
{
	uint8_t * tempInt = (uint8_t *) dispInt;
	if(logger_status==1) {
		for(uint8_t i=0;i<length;i++) {
		#ifdef KL25Z
			PRINTF("0x%x\n\r", (tempInt+i));
		#else
			printf("0x%x\n\r", (tempInt+i));
		#endif
		}
	}
}
