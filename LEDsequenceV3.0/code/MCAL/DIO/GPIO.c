/*
 * GPIO.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "GPIO.h"

/*============= PRIVATE FUNCTION PROTOTYPE =============*/

static void check_pin(uint8* pin_no,REG_NAME* port);

/*============= FUNCTION DEFINITION =============*/
/*
 *PinMode:used to set pin direction input/output
 * function parameters
 * pin_no:pin number to set
 * pin_direction:direction of the pin
 */
EN_STATE pinMode(uint8 pin_no,EN_PIN_DIRECTION pin_direction)
{
	REG_NAME port = NULL_PTR;
	if(pin_no < 0 || pin_no >= (4*MAX_PIN))
		return FAILED;

	check_pin(&pin_no, &port);
	if(pin_direction==PIN_INPUT)
	{
		CLEAR_BIT(port->ddrx,pin_no);
	}
	else if(pin_direction==PIN_OUTPUT)
	{
		SET_BIT(port->ddrx,pin_no);
	}
	else
	{
		return FAILED;
	}
	return SUCCESS;
}

/*
 *digitalWrite:used to write high/low to specific pin
 * function parameters
 * pin_no:pin number to write
 * pin_val:output value high / low
 */
EN_STATE digitalWrite(uint8 pin_no,EN_PIN_VALUE pin_val)
{
	REG_NAME port = NULL_PTR;
	if(pin_no < 0 || pin_no >= (4*MAX_PIN))
		return FAILED;

	check_pin(&pin_no, &port);
	if(pin_val==Low)
	{
		CLEAR_BIT(port->portx,pin_no);
	}
	else if(pin_val==High)
	{
		SET_BIT(port->portx,pin_no);
	}
	else
	{
		return FAILED;
	}
	return SUCCESS;
}

/*
 *digitalRead:used to read specific pin value
 * function parameters
 * pin_no:pin number to read
 * pin_val:address to variable of the return reading
 */
EN_STATE digitalRead(uint8 pin_no,uint8 *pin_val)
{
	REG_NAME port = NULL_PTR;
	if(pin_no < 0 || pin_no >= (4*MAX_PIN))
		return FAILED;

	check_pin(&pin_no, &port);
	if(BIT_IS_SET(port->pinx,pin_no))
		*pin_val = High;
	else
		*pin_val = Low;

	return SUCCESS;
}

/*
 *portMode:used to specific port direction
 * function parameters
 * port:port name (PORTA-PORTB-PORTC-PORTD)
 * port_direction:direction of the port
 */
EN_STATE portMode(REG_NAME port,EN_PORT_DIRECTION port_direction)
{
	if(port == PORTA || port == PORTB || port == PORTC || port == PORTD)
	{
		port->ddrx=port_direction;
		return SUCCESS;
	}
	return FAILED;
}

/*
 *digitalWrite:used to write high/low to specific port
 * function parameters
 * port:port name (PORTA-PORTB-PORTC-PORTD)
 * port_val:output value HIGH / LOW
 */
EN_STATE digitalWrite_Port(REG_NAME port,EN_PORT_VALUE port_val)
{
	if(port == PORTA || port == PORTB || port == PORTC || port == PORTD)
	{
		port->portx=port_val;
		return SUCCESS;
	}
	return FAILED;
}

/*
 *digitalRead:used to read specific port value
 * function parameters
 * port:port name (PORTA-PORTB-PORTC-PORTD)
 * port_val:address to variable of the return reading
 */
EN_STATE digitalRead_Port(REG_NAME port,uint8 *port_val)
{
	if(port == PORTA || port == PORTB || port == PORTC || port == PORTD)
	{
		*port_val= port->pinx;
		return SUCCESS;
	}
	return FAILED;
}

/*
 * active internal pull up resistor for specific pin
 */
EN_STATE Enable_PULLUP (uint8 pin_no)
{
	REG_NAME port = NULL_PTR;
	if(pin_no < 0 || pin_no >= (4*MAX_PIN))
		return FAILED;

	check_pin(&pin_no, &port);
	SET_BIT(port->portx,pin_no);
	return SUCCESS;
}

/*
 * used to identify port id for a given pin number
 */
void check_pin(uint8* pin_no,REG_NAME* port)
{
	if((*pin_no >=0) && (*pin_no <=7))
	{
		*port= PORTA;
	}
	else if((*pin_no >=8) && (*pin_no<=15))
	{
		*pin_no -= 8;
		*port= PORTB;
	}
	else if((*pin_no >=16) && (*pin_no <=23))
	{
		*pin_no -= 16;
		*port= PORTC;
	}
	else if((*pin_no =24) && (*pin_no <=31))
	{
		*pin_no -= 24;
		*port= PORTD;
	}
	else
	{
		*port= NULL_PTR;
	}
}
