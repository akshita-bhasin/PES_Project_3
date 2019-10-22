/* @file test.h
 * @brief Unit test cases headers for PES_Project3
 * @author : Akshita Bhasin and Madhukar Arora
 * @date : 10/18/2019
 * @version 1.0
 **/

#ifdef PC_UT
#include "uCUnit/uCUnit.h"
#endif
#include <stdio.h>
#include "uCUnit.h"
#include "led_blink.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#include <stdint.h>
#include "logger.h"
#include "memorytest.h"
#include "pattern_gen.h"


#define LENGTH 16

void unit_test_cases(void);
