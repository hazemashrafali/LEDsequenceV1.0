/*
 * LED.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/DIO/GPIO.h"


/*============= MACRO DEFINITION =============*/
#define LED_logic 1 //1:positive logic , 2:negative logic


/*============= FUNCTION PROTOTYPE =============*/
EN_STATE LED_init(uint8 led);
EN_STATE LED_digitalwrite(uint8 led,EN_PIN_VALUE value);

#endif /* HAL_LED_LED_H_ */
