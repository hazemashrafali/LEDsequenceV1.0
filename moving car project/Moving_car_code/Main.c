/*
 * Main.c
 *
 *  Created on: Apr 12, 2023
 *      Author: HAZEM-PC
 */


#include "HAL/LED/LED.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/DC_motor/DCmotor.h"
#include "MCAL/TIMER_0/TIMER_0.h"
#include "MCAL/External_INT/External_INT.h"

typedef enum{
	FWD,BWD,right,left,g_stop
}EN_state;

DCmotor_configtype motor_1={16,17};
DCmotor_configtype motor_2={19,18};
DCmotor_configtype motor_3={21,20};
DCmotor_configtype motor_4={23,22};
uint8 LED1=8,LED2=9,LED3=10,LED4=11;
uint8 car_state=0;

void _4_motors_control(DCmotor_configtype m1,DCmotor_configtype m2,DCmotor_configtype m3,DCmotor_configtype m4,EN_state state,uint8 speed);
void stop_car (void);

int main(void)
{
	uint8 Button_on=0;
	uint8 Button_value;
	ST_INT_Config button_off={EN_INT0,RISING};
	LED_init(LED1);
	LED_init(LED2);
	LED_init(LED3);
	LED_init(LED4);
	Button_init(Button_on, disable);
	INT_init(&button_off);
	INT0_setCallBack(stop_car);

	while(1)
	{
		Button_Read(Button_on, &Button_value);
		if(Button_value==1 && car_state == 0)
		{
			DCmotor_init(&motor_1);
			DCmotor_init(&motor_2);
			DCmotor_init(&motor_3);
			DCmotor_init(&motor_4);
			car_state=1;
			Timer0_Delay(1000);
		}
		switch(car_state)
		{
		case 1:
			car_state=2;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,FWD, 50);
			LED_digitalwrite(LED1, High);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(3000);
			break;
		case 2:
			car_state=3;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,g_stop, 0);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(500);
			break;
		case 3:
			car_state=4;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,right, 50);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, High);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(500);
			break;
		case 4:
			car_state=5;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,g_stop, 0);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(500);
			break;
		case 5:
			car_state=6;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,FWD, 30);
			LED_digitalwrite(LED1, High);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(2000);
			break;
		case 6:
			car_state=7;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,g_stop, 0);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(500);
			break;
		case 7:
			car_state=8;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,right, 30);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, High);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(500);
			break;
		case 8:
			car_state=1;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,g_stop, 0);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(500);
			break;
		default:
			car_state=0;
			_4_motors_control(motor_1,motor_2,motor_3,motor_4 ,g_stop, 0);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			break;
		}
	}
}



void _4_motors_control(DCmotor_configtype m1,DCmotor_configtype m2,DCmotor_configtype m3,DCmotor_configtype m4,EN_state state,uint8 speed)
{
	switch(state)
	{
	case FWD:
		DCmotor_start(&m1, CW,speed);
		DCmotor_start(&m2, CW,speed);
		DCmotor_start(&m3, CW,speed);
		DCmotor_start(&m4, CW,speed);
		break;
	case BWD:
		DCmotor_start(&m1, ACW,speed);
		DCmotor_start(&m2, ACW,speed);
		DCmotor_start(&m3, ACW,speed);
		DCmotor_start(&m4, ACW,speed);
		break;
	case right:
		DCmotor_start(&m1, CW,speed);
		DCmotor_start(&m2, CW,speed);
		DCmotor_start(&m3, stop,speed);
		DCmotor_start(&m4, stop,speed);
		break;
	case left:
		DCmotor_start(&m3, CW,speed);
		DCmotor_start(&m4, CW,speed);
		DCmotor_start(&m1, stop,speed);
		DCmotor_start(&m2, stop,speed);
		break;
	case g_stop:
		DCmotor_start(&m1, stop,speed);
		DCmotor_start(&m2, stop,speed);
		DCmotor_start(&m3, stop,speed);
		DCmotor_start(&m4, stop,speed);
		break;
	}
}


void stop_car (void)
{
	car_state=9;
	DCmotor_stop(&motor_1);
	LED_digitalwrite(LED1, Low);
	LED_digitalwrite(LED2, Low);
	LED_digitalwrite(LED3, Low);
	LED_digitalwrite(LED4, High);
}

