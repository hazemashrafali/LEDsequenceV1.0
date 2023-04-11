/*
 * main.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */
#include "MCAL/External_INT/External_INT.h"
#include "./HAL/BUTTON/BUTTON.h"
#include "./HAL/LED/LED.h"
#include "MCAL/TIMER_0/TIMER_0.h"


uint8 g_press_count=0;
uint16 g_blink_mode=100;
uint8 g_buttonMode_count=0;

void buttonpress(void);
void Blink_mode(void);


int main()
{

	uint8 LED1=1,LED2=2,LED3=3,LED4=4;
	ST_INT_Config int_0={EN_INT0,RISING};
	ST_INT_Config int_1={EN_INT1,RISING};

	ST_timer0_config delay_on={0};
	ST_timer0_config delay_off={0};
	Timer0_Config(&delay_on);
	Timer0_Config(&delay_off);

	LED_init(LED1);
	LED_init(LED2);
	LED_init(LED3);
	LED_init(LED4);
	INT_init(&int_0);
	INT_init(&int_1);
	INT0_setCallBack(buttonpress);
	INT1_setCallBack(Blink_mode);

	while(1)
	{
		switch (g_press_count)
		{
		case 1:
			LED_digitalwrite(LED1, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED1, Low);
			Timer0_Delay(&delay_off);
			break;
		case 2:
			LED_digitalwrite(LED1, High);
			LED_digitalwrite(LED2, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			Timer0_Delay(&delay_off);
			break;
		case 3:
			LED_digitalwrite(LED1, High);
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			Timer0_Delay(&delay_off);
			break;
		case 4:
			LED_digitalwrite(LED1, High);
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, High);
			LED_digitalwrite(LED4, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(&delay_off);
			break;
		case 5:
			LED_digitalwrite(LED2, High);
			LED_digitalwrite(LED3, High);
			LED_digitalwrite(LED4, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(&delay_off);
			break;
		case 6:
			LED_digitalwrite(LED3, High);
			LED_digitalwrite(LED4, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(&delay_off);
			break;
		case 7:
			LED_digitalwrite(LED4, High);
			Timer0_Delay(&delay_on);
			LED_digitalwrite(LED4, Low);
			Timer0_Delay(&delay_off);
			break;
		default:
			LED_digitalwrite(LED1, Low);
			LED_digitalwrite(LED2, Low);
			LED_digitalwrite(LED3, Low);
			LED_digitalwrite(LED4, Low);
			break;
		}
		delay_on.delay=g_blink_mode;
		delay_off.delay=1000-g_blink_mode;
		Timer0_Config(&delay_on);
		Timer0_Config(&delay_off);
	}

}


void buttonpress(void)
{
	g_press_count++;
	if(g_press_count==8)
		g_press_count=0;
}



void Blink_mode(void)
{
	g_buttonMode_count++;
	switch(g_buttonMode_count)
	{
	case 1:
		g_blink_mode=200;
		break;
	case 2:
		g_blink_mode=300;
		break;
	case 3:
		g_blink_mode=400;
		break;
	case 4:
		g_blink_mode=500;
		break;
	case 5:
		g_blink_mode=800;
		break;
	default:
		g_blink_mode=100;
		break;
	}
	if(g_buttonMode_count==6)
		g_buttonMode_count=0;
}



