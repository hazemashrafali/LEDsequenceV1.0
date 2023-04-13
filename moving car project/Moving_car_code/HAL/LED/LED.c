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
	uint8 port;
	if(pin >= 0 && pin < 32)
	{
		check_pin(&pin, &port);
		DIO_pinDirection(port, pin, PIN_OUTPUT);
		DIO_writePin(port, pin, Low);
		return SUCCESS;
	}
	return FAILED;
}

EN_STATE LED_digitalwrite(uint8 pin,EN_PIN_VALUE value)
{
	uint8 port;
	if(pin >= 0 && pin < 32)
	{
		check_pin(&pin, &port);
		if(value == Low)
			DIO_writePin(port, pin, Low);
		else
			DIO_writePin(port, pin, High);
		return SUCCESS;
	}
	return FAILED;
}

