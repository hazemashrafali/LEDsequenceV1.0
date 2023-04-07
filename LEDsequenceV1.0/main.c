/*
 * main.c
 *V1.0
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#include "MCAL/External_INT/External_INT.h"
#include "./HAL/BUTTON/BUTTON.h"
#include "./HAL/LED/LED.h"
#include <util/delay.h>

int main()
{
	uint8 count=0,flag=1;
	uint8 button=0;
	uint8 LED1=1,LED2=2,LED3=3,LED4=4;
	Button_init(button, enable);
	LED_init(LED1);
	LED_init(LED2);
	LED_init(LED3);
	LED_init(LED4);

	while(1)
	{
		if(Button_Read(button))
		{
			_delay_ms(50);
			if(Button_Read(button))
			{
				if(flag==0)
				{
					count++;
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
					flag=1;
					if(count==9)
						count=0;
				}
			}
		}
		else
			flag=0;
	}
}



