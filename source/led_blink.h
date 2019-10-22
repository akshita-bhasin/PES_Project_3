/*
 * @file led_blink.h
 * @brief to implement led control for the memory tests for KL25Z builds
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 10/17/2019
 *  @version 1.0
 */

#ifndef LED_BLINK_H_
#define LED_BLINK_H_

#include <stdint.h>
#ifdef KL25Z
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

#ifdef KL25Z_LOG
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

#ifdef KL25Z_UT
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

void turn_on_led_color(char color);

void delay();

#endif /* LED_BLINK_H_ */
