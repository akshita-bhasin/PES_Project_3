/*
 * led_blink.h
 *
 *  Created on: Oct 9, 2019
 *      Author: ASUS
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

void turn_on_led_color(char color);

void delay();

#endif /* LED_BLINK_H_ */
