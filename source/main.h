/*
 * @file main.h
 * @brief includes header files required for executing main.c
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 10/17/2019
 *  @version 1.0
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#define LENGTH 16
#ifdef KL25Z
#include "led_blink.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif
#ifdef KL25Z_LOG
#include "led_blink.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif
#include "pattern_gen.h"
#include "memorytest.h"
#include "logger.h"

size_t pointer_length(uint32_t * addr, size_t length);

#endif /* MAIN_H_ */
