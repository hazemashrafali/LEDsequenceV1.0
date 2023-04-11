/*
 * LED.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "LED.h"

/*============= FUNCTION DEFINITION =============*/

EN_STATE LED_init(uint8 pin)
{
	EN_STATE state_1,state_2;
	state_1=pinMode(pin, PIN_OUTPUT);
#if (LED_logic ==1)
	state_2=digitalWrite(pin, Low);
#elif (LED_logic ==2)
	state_2=digitalWrite(pin, High);
#endif
	if(state_1 == SUCCESS && state_2 == SUCCESS)
		return SUCCESS;
	return FAILED;
}

EN_STATE LED_digitalwrite(uint8 pin,EN_PIN_VALUE value)
{
	EN_STATE state;
#if (LED_logic ==1)
	if(value==High)
		state=digitalWrite(pin, High);
	else
		state=digitalWrite(pin, Low);
#elif (LED_logic ==2)
	if(value==High)
		state=digitalWrite(pin, Low);
	else
		state=digitalWrite(pin, High);
#endif
		return state;
}

