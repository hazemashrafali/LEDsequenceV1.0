/*
 * BUTTON.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/DIO/GPIO.h"

/*============= TYPE DEFINITION =============*/
typedef enum{
	disable,enable
}EN_internal_pullup;

/*============= FUNCTION PROTOTYPE =============*/
EN_STATE Button_init(uint8 pin,EN_internal_pullup state);
uint8 Button_Read(uint8 pin);


#endif /* HAL_BUTTON_BUTTON_H_ */
