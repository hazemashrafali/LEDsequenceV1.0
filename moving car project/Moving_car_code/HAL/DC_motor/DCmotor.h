/*
 * DCmotor.h
 *
 *  Created on: Feb 23, 2022
 *      Author: HAZEM-PC
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/*============= FILE INCLUSION =============*/
#include "../../MCAL/GPIO/DIO.h"
#include "../../MCAL/TIMER2_PWM/Timer2_PWM.h"

/*============= TYPE DEFINITION  =============*/
typedef struct{
	uint8 input_pin_1;
	uint8 input_pin_2;
}DCmotor_configtype;

typedef enum{
	CW,ACW,stop
}DCMotor_state;
/*============= FUNCTION PROTOTYPE =============*/
EN_STATE DCmotor_init(DCmotor_configtype *motor);
void DCmotor_start(DCmotor_configtype *motor,DCMotor_state State,uint8 speed);
void DCmotor_stop(DCmotor_configtype *motor);

#endif /* DCMOTOR_H_ */
