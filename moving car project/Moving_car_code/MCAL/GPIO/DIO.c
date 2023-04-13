/*
 * DIO.c
 *
 *  Created on: Apr 12, 2023
 *      Author: HAZEM-PC
 */
#include "DIO.h"

EN_STATE DIO_pinDirection(uint8 port,uint8 pin,EN_PIN_DIRECTION direction)
{
	if(port >= MAX_PORT_ID || pin >= MAX_PIN)
	{
		return FAILED;
	}
	switch(port)
	{
	case PORTA_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLEAR_BIT(DDRA,pin);
		}
		break;
	case PORTB_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLEAR_BIT(DDRB,pin);
		}
		break;
	case PORTC_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLEAR_BIT(DDRC,pin);
		}
		break;
	case PORTD_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLEAR_BIT(DDRD,pin);
		}
		break;
	default:
		return FAILED;
	}
	return SUCCESS;
}

EN_STATE DIO_writePin(uint8 port,uint8 pin,EN_PIN_VALUE value)
{
	if(port >= MAX_PORT_ID || pin >= MAX_PIN)
	{
		return FAILED;
	}
	switch(port)
	{
	case PORTA_ID:
		if(value == High)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLEAR_BIT(PORTA,pin);
		}
		break;
	case PORTB_ID:
		if(value == High)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLEAR_BIT(PORTB,pin);
		}
		break;
	case PORTC_ID:
		if(value == High)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLEAR_BIT(PORTC,pin);
		}
		break;
	case PORTD_ID:
		if(value == High)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLEAR_BIT(PORTD,pin);
		}
		break;
	default:
		return FAILED;
	}
	return SUCCESS;
}

EN_STATE DIO_readPin(uint8 port,uint8 pin,uint8* value)
{
	if(port >= MAX_PORT_ID || pin >= MAX_PIN)
	{
		return FAILED;
	}
	switch(port)
	{
	case PORTA_ID:
		if(BIT_IS_SET(PINA,pin))
		{
			*value = LOGIC_HIGH;
		}
		else
		{
			*value = LOGIC_LOW;
		}
		break;
	case PORTB_ID:
		if(BIT_IS_SET(PINB,pin))
		{
			*value = LOGIC_HIGH;
		}
		else
		{
			*value = LOGIC_LOW;
		}
		break;
	case PORTC_ID:
		if(BIT_IS_SET(PINC,pin))
		{
			*value = LOGIC_HIGH;
		}
		else
		{
			*value = LOGIC_LOW;
		}
		break;
	case PORTD_ID:
		if(BIT_IS_SET(PIND,pin))
		{
			*value = LOGIC_HIGH;
		}
		else
		{
			*value = LOGIC_LOW;
		}
		break;
	default:
		return FAILED;
	}
	return SUCCESS;
}

EN_STATE DIO_togglePin(uint8 port,uint8 pin)
{
	if(port >= MAX_PORT_ID || pin >= MAX_PIN)
	{
		return FAILED;
	}
	switch (port)
	{
	case PORTA_ID:
		TOGGLE_BIT(PORTA,pin);
		break;
	case PORTB_ID:
		TOGGLE_BIT(PORTB,pin);
		break;
	case PORTC_ID:
		TOGGLE_BIT(PORTC,pin);
		break;
	case PORTD_ID:
		TOGGLE_BIT(PORTD,pin);
		break;
	default:
		return FAILED;
	}
	return SUCCESS;
}

void check_pin(uint8* pin_no,uint8* port)
{
	if((*pin_no >=0) && (*pin_no <=7))
	{
		*port= PORTA_ID;
	}
	else if((*pin_no >=8) && (*pin_no<=15))
	{
		*pin_no -= 8;
		*port= PORTB_ID;
	}
	else if((*pin_no >=16) && (*pin_no <=23))
	{
		*pin_no -= 16;
		*port= PORTC_ID;
	}
	else if((*pin_no =24) && (*pin_no <=31))
	{
		*pin_no -= 24;
		*port= PORTD_ID;
	}
	else
	{
		*port= 4;
	}
}
