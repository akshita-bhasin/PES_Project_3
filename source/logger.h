/*
 * logger.h
 *
 *  Created on: Oct 9, 2019
 *      Author: ASUS
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#ifdef KL25Z
#include "fsl_debug_console.h"
#endif

//Log_enable – begin printing log messages when called
void log_enable();

// Log_disable – ignore any log messages until re-enabled
void log_disable();

/* Log_status – returns a flag to indicate
 * whether the logger is enabled or disabled */
uint8_t log_status();

/* Log_data – display in hexadecimal an address
 * and contents of a memory location, arguments are
 *  a pointer to a sequence of bytes and a specified length */
void log_data(uint8_t * seqAddr, size_t length);

// Log_string – display a string
void log_string(char * dispStr);

// Log_integer – display an integer
void log_integer(uint32_t * dispInt, size_t length);

#endif /* LOGGER_H_ */
