/*
 * Timer2_PWM.h
 *
 *  Created on: Apr 13, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_TIMER2_PWM_TIMER2_PWM_H_
#define MCAL_TIMER2_PWM_TIMER2_PWM_H_

/*============= FILE INCLUSION =============*/
#include "../../Microcontrol/Registers.h"
#include "../../Utilities/Common_Macros.h"

/*============= MACRO DEFINITION =============*/
#define Tmax 	 16.4F
#define TickTime 0.064F
#define T_period 4.0F

/*============= FUNCTION PROTOTYPE =============*/
void PWM_Timer2_Init(void);
void PWM_Timer2_Start(uint8 duty_cycle);
void PWM_Timer2_Stop(void);
/*
void Timer0_pwm_init(uint8 pin,uint8 duty_cycle);
void Timer0_pwm_start(uint8 duty_cycle);
void Timer0_pwm_Deinit(uint8 pin);
*/

#endif /* MCAL_TIMER2_PWM_TIMER2_PWM_H_ */
