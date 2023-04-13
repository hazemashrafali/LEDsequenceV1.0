/*
 * DCmotor.c
 *
 *  Created on: Feb 23, 2022
 *      Author: HAZEM-PC
 */



#include "DCmotor.h"


EN_STATE DCmotor_init(DCmotor_configtype *motor)
{
	uint8 port,pin;
	if(motor->input_pin_1 >= 0 && motor->input_pin_1 < 32 && motor->input_pin_2 >= 0 && motor->input_pin_2 < 32 )
	{
		pin=motor->input_pin_1;
		check_pin(&pin, &port);
		DIO_pinDirection(port, pin, PIN_OUTPUT);
		DIO_writePin(port, pin, Low);
		pin=motor->input_pin_2;
		check_pin(&pin, &port);
		DIO_pinDirection(port, pin, PIN_OUTPUT);
		DIO_writePin(port, pin, Low);
		PWM_Timer2_Init();
		return SUCCESS;
	}
	return FAILED;
}

void DCmotor_start(DCmotor_configtype *motor,DCMotor_state State,uint8 speed)
{
	uint8 port,pin;
	PWM_Timer2_Start(speed);
	if(State==CW)				//rotate clockwise
	{
		pin=motor->input_pin_1;
		check_pin(&pin, &port);
		DIO_writePin(port,pin,Low);  //input A
		pin=motor->input_pin_2;
		check_pin(&pin, &port);
		DIO_writePin(port,pin,High);  //input B
	}
	else if(State==ACW)			//rotate anti clockwise
	{
		pin=motor->input_pin_1;
		check_pin(&pin, &port);
		DIO_writePin(port,pin,High);  //input A
		pin=motor->input_pin_2;
		check_pin(&pin, &port);
		DIO_writePin(port,pin,Low);  //input B
	}
	else						//stop the motor
	{
		pin=motor->input_pin_1;
		check_pin(&pin, &port);
		DIO_writePin(port,pin,Low);  //input A
		pin=motor->input_pin_2;
		check_pin(&pin, &port);
		DIO_writePin(port,pin,Low);  //input B
	}

}

void DCmotor_stop(DCmotor_configtype *motor)
{
	PWM_Timer2_Stop();
	uint8 port,pin;
	pin=motor->input_pin_1;
	check_pin(&pin, &port);
	DIO_writePin(port,pin,Low);  //input A
	pin=motor->input_pin_2;
	check_pin(&pin, &port);
	DIO_writePin(port,pin,Low);  //input B

}

