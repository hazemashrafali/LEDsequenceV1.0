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
	uint8 port;
	if(pin >= 0 && pin < 32)
	{
		check_pin(&pin, &port);
		DIO_pinDirection(port, pin, PIN_INPUT);
		if(state==enable)
			DIO_writePin(port, pin, High);
		else
			DIO_writePin(port, pin, Low);
		return SUCCESS;
	}
	return FAILED;
}


EN_STATE Button_Read(uint8 pin,uint8* value)
{
	uint8 port,read;
	if(pin >= 0 || pin < 32)
	{
		check_pin(&pin, &port);
		DIO_readPin(port, pin, &read);
		*value=read;
		return SUCCESS;
	}
	return FAILED;
}
