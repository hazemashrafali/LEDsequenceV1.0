/*
 * main.c
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#include "MCAL/External_INT/External_INT.h"
#include "HAL/LED/LED.h"


uint8 g_flag=0;

void buttonCount(void);

int main()
{
	uint8 count=0;
	uint8 LED1=1,LED2=2,LED3=3,LED4=4;
	ST_INT_Config int_0={EN_INT0,RISING};
	LED_init(LED1);
	LED_init(LED2);
	LED_init(LED3);
	LED_init(LED4);
	INT_init(&int_0);
	INT0_setCallBack(buttonCount);

	while(1)
	{
		if(g_flag==1)
		{
			count++;
			if(count==9)
				count=0;
			switch (count)
			{
			case 1:
				LED_digitalwrite(LED1, High);
				break;
			case 2:
				LED_digitalwrite(LED2, High);
				break;
			case 3:
				LED_digitalwrite(LED3, High);
				break;
			case 4:
				LED_digitalwrite(LED4, High);
				break;
			case 5:
				LED_digitalwrite(LED1, Low);
				break;
			case 6:
				LED_digitalwrite(LED2, Low);
				break;
			case 7:
				LED_digitalwrite(LED3, Low);
				break;
			default:
				LED_digitalwrite(LED1, Low);
				LED_digitalwrite(LED2, Low);
				LED_digitalwrite(LED3, Low);
				LED_digitalwrite(LED4, Low);
				count=0;
				break;
			}
			g_flag=0;
		}
	}
}


void buttonCount(void)
{
	g_flag=1;
}


