/*
 * @file ledblink.c
 * @brief running FB_RUN and FB_DEBUG with timing cycle implementation
 * 		on KL25Z and blinking LED
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 30/09/2019
 *  @version 1.0
 */

#include "led_blink.h"

void delay(); // to implement the delay from look-up table

// Function Name: blink
// Function arguments: void
// Function return type: void
/* Brief: Blinking LED with keeeping delay from look-up table
	and executing the timing cycle 10 times, printing the message
	via UART terminal and printing the difference in time
	between two events
	*/

void turn_on_led_color(char color)
{
#ifdef KL25Z
	LED_RED_INIT(1);
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);
	LED_RED_OFF();
	LED_BLUE_OFF();
	LED_GREEN_OFF();

	// for MODULE=FB_DEBUG; blink led, print message via serial terminal
	//	and printing timing cycle delay for the event
	if(color == 'R') {
		LED_BLUE_OFF();
		LED_GREEN_OFF(); /*!< Turn off target LED_GREEN */
		LED_RED_ON(); /*!< Turn on target LED_RED */
		PRINTF("LED RED ON\n\r");
		delay();
	}
	else if(color == 'B') {
    	LED_RED_OFF(); /*!< Turn off target LED_RED */
		LED_GREEN_OFF(); /*!< Turn off target LED_GREEN */
    	LED_BLUE_ON(); /*!< Turn on target LED_BLUE */
    	PRINTF("LED BLUE ON\n\r");
    	delay();
	}
	else if(color == 'G') {
		LED_RED_OFF(); /*!< Turn off target LED_RED */
		LED_BLUE_OFF(); /*!< Turn off target LED_BLUE */
		LED_GREEN_ON(); /*!< Turn on target LED_GREEN */
		PRINTF("LED GREEN ON\n\r");
		delay();
	}
#endif

#ifdef KL25Z_LOG
	LED_RED_INIT(1);
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);
	LED_RED_OFF();
	LED_BLUE_OFF();
	LED_GREEN_OFF();

	// for MODULE=FB_DEBUG; blink led, print message via serial terminal
	//	and printing timing cycle delay for the event
	if(color == 'R') {
		LED_BLUE_OFF();
		LED_GREEN_OFF(); /*!< Turn off target LED_GREEN */
		LED_RED_ON(); /*!< Turn on target LED_RED */
		PRINTF("LED RED ON\n\r");
		delay();
	}
	else if(color == 'B') {
    	LED_RED_OFF(); /*!< Turn off target LED_RED */
		LED_GREEN_OFF(); /*!< Turn off target LED_GREEN */
    	LED_BLUE_ON(); /*!< Turn on target LED_BLUE */
    	PRINTF("LED BLUE ON\n\r");
    	delay();
	}
	else if(color == 'G') {
		LED_RED_OFF(); /*!< Turn off target LED_RED */
		LED_BLUE_OFF(); /*!< Turn off target LED_BLUE */
		LED_GREEN_ON(); /*!< Turn on target LED_GREEN */
		PRINTF("LED GREEN ON\n\r");
		delay();
	}
#endif
}

//Function Name: delay
// Function Parameters: num - used for calculating delay from timing cycle
// Function Return type: void

/* Brief: a delay loop based on trial and error using oscilloscope
 	 which returns a 1000ms time gap for int 2,300,000 */

void delay()
{
	uint64_t numb = 100000*2.3;
	while(numb != 0)
	{
		numb--;
	}
}
