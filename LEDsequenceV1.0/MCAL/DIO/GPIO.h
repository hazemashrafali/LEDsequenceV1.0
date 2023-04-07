/*
 * GPIO.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_DIO_GPIO_H_
#define MCAL_DIO_GPIO_H_

/*============= FILE INCLUSION =============*/

#include "../../Utilities/Registers.h"
#include "../../Utilities/Common_Macros.h"


/*============= TYPE DEFINITION =============*/
typedef enum{
	PIN_INPUT,PIN_OUTPUT
}EN_PIN_DIRECTION;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}EN_PORT_DIRECTION;

typedef enum{
	Low,High
}EN_PIN_VALUE;

typedef enum{
	LOW,HIGH=0xFF
}EN_PORT_VALUE;

typedef enum{
	FAILED,SUCCESS
}EN_STATE;


/*============= FUNCTION PROTOTYPE =============*/

EN_STATE pinMode(uint8 pin_no,EN_PIN_DIRECTION pin_direction);
EN_STATE digitalWrite(uint8 pin_no,EN_PIN_VALUE pin_val);
EN_STATE digitalRead(uint8 pin_no,uint8 *pin_val);
EN_STATE portMode(REG_NAME port,EN_PORT_DIRECTION port_direction);
EN_STATE digitalWrite_Port(REG_NAME port,EN_PORT_VALUE port_val);
EN_STATE digitalRead_Port(REG_NAME port,uint8 *port_val);
EN_STATE Enable_PULLUP (uint8 pin_no);
//void check_pin(uint8* pin_no,REG_NAME* port);

#endif /* MCAL_DIO_GPIO_H_ */



