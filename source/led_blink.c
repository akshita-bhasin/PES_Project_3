/*
 * @file ledblink.c
 * @brief to implement led control for the memory tests for KL25Z builds
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 10/17/2019
 *  @version 1.0
 */

#include "led_blink.h"

void delay(); // to implement the delay

/* Function Name: turn_on_led_color
 Function arguments: char color
 Function return type: void
 Brief: function to glow LED on the Freedom Board based on the execution of memory tests
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
		LED_BLUE_OFF(); /*!< Turn off target LED_BLUE */
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

#ifdef KL25Z_UT
	LED_RED_INIT(1);
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);
	LED_RED_OFF();
	LED_BLUE_OFF();
	LED_GREEN_OFF();

	// for MODULE=FB_DEBUG; blink led, print message via serial terminal
	//	and printing timing cycle delay for the event
	if(color == 'R') {
		LED_BLUE_OFF(); /*!< Turn off target LED_BLUE */
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

/*Function Name: delay
 Function Parameters: void
 Function Return type: void
 Brief: a simple delay loop based on trial and error
  using oscilloscope which returns a 1000ms time gap for int 2,300,000
*/

void delay()
{
	uint64_t numb = 100000*2.3;
	while(numb != 0)
	{
		numb--;
	}
}
