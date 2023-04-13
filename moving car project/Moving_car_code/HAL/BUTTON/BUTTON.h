/*
 * BUTTON.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/GPIO/DIO.h"

/*============= TYPE DEFINITION =============*/
typedef enum{
	disable,enable
}EN_internal_pullup;

/*============= FUNCTION PROTOTYPE =============*/
EN_STATE Button_init(uint8 pin,EN_internal_pullup state);
EN_STATE Button_Read(uint8 pin,uint8* value);


#endif /* HAL_BUTTON_BUTTON_H_ */
