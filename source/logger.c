/*
 * @file  : logger.c
 * @brief : contains logger implementation
 * @author : Akshita Bhasin and Madhukar Arora
 * @date : 10/15/2019
 * @version 1.0
 */

#include "logger.h"

uint8_t logger_status=0; // flag to indicate if logger enabled(1) or disabled(0)

/* function name : log_enable
 * return type : void
 * parameters : void
 * @brief : enables the logger functionality
 */
void log_enable()
{
	logger_status=1;
}

/* function name : log_disable
 * return type : void
 * parameters : void
 * @brief : disables the logger functionality
 */

void log_disable()
{
	logger_status=0;
}

/* function name : log_status
 * return type : uint8_t
 * parameters : void
 * @brief : returns logger status
 */
uint8_t log_status()
{
	return logger_status;
}

/* function name : log_data
 * return type : void
 * parameters : uint8_t* seqAddr (address), size_t length(number of bytes)
 * @brief : logs the data at a memory location
 */
void log_data(uint8_t * seqAddr, size_t length)
{
	if(logger_status==1){
	#ifdef KL25Z_LOG
		PRINTF("Contents at memory location 0X%x: \n\r",seqAddr);
	#endif
	#ifdef PC_LOG
		printf("Contents at memory location 0X%x: \n\r",seqAddr);
	#endif
		for(uint8_t i=0;i<length;i++){
		#ifdef KL25Z_LOG
			PRINTF("0x%x ",*(seqAddr+i));
		#endif
		#ifdef PC_LOG
			printf("0x%x ",*(seqAddr+i));
		#endif
		}
	#ifdef KL25Z_LOG
		PRINTF("\n\r");
	#endif
	#ifdef PC_LOG
		printf("\n\r");
	#endif
	}
}

/* function name : log_string
 * return type : void
 * parameters : char *dispStr
 * @brief : if logger enabled, logger logs a string
 */
void log_string(char * dispStr)
{
	if(logger_status==1) {
	#ifdef KL25Z_LOG
		PRINTF("%s\n\r", dispStr);
	#endif
	#ifdef PC_LOG
		printf("%s\n\r", dispStr);
	#endif
	}
}

/* function name : log_integer
 * return type : void
 * parameters : uint32_t * dispInt(address), size_t length(number of bytes)
 * @brief : if logger enabled, logger logs the values at an address
 */
void log_integer(uint32_t * dispInt, size_t length)
{
	if(logger_status==1) {
		for(uint8_t i=0;i<length;i++) {
		#ifdef KL25Z_LOG
			PRINTF("0x%x\n\r", *(dispInt+i));
		#endif
		#ifdef PC_LOG
			printf("0x%x\n\r", *(dispInt+i));
		#endif
		}
	}
}
