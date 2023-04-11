/*
 * BUTTON.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "BUTTON.h"

/*============= FUNCTION DEFINITION =============*/

EN_STATE Button_init(uint8 pin,EN_internal_pullup state)
{
	EN_STATE state_1,state_2;
	state_1=pinMode(pin, PIN_INPUT);
	if(state_1==SUCCESS)
	{
		if(state==enable)
			state_2=digitalWrite(pin, High);
		else
			state_2=digitalWrite(pin, Low);
		if(state_1 == SUCCESS && state_2 == SUCCESS)
			return SUCCESS;
	}
	return FAILED;
}


uint8 Button_Read(uint8 pin)
{
	uint8 pin_val;
	digitalRead(pin,&pin_val);
	return pin_val;
}
