/*
 * DIO.h
 *
 *  Created on: Apr 12, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_GPIO_DIO_H_
#define MCAL_GPIO_DIO_H_

/*============= FILE INCLUSION =============*/
#include "../../Microcontrol/Registers.h"
#include "../../Utilities/Common_Macros.h"

/*============= TYPE DEFINITION =============*/

typedef enum{
	PIN_INPUT,PIN_OUTPUT
}EN_PIN_DIRECTION;

typedef enum{
	Low,High
}EN_PIN_VALUE;

typedef enum{
	FAILED,SUCCESS
}EN_STATE;


/*============= FUNCTION PROTOTYPE =============*/
EN_STATE DIO_pinDirection(uint8 port,uint8 pin,EN_PIN_DIRECTION direction);
EN_STATE DIO_writePin(uint8 port,uint8 pin,EN_PIN_VALUE value);
EN_STATE DIO_readPin(uint8 port,uint8 pin,uint8* value);
EN_STATE DIO_togglePin(uint8 port,uint8 pin);
void check_pin(uint8* pin_no,uint8* port);


#endif /* MCAL_GPIO_DIO_H_ */
