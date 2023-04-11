/*
 * TIMER_0.c
 *
 *  Created on: Apr 9, 2023
 *      Author: HAZEM-PC
 */
#include "TIMER_0.h"
#include <avr/interrupt.h>
#include "math.h"
#include "Timer0_Utilities.h"

/*
 * Description:used to calculate timer settings
 * calculate pre_scale value
 * calculate number of overflows
 * calculate timer initial value
 */
void Timer0_Config(ST_timer0_config* T)
{
	//T->delay-=5;
	if(T->delay <= Tmax_N1024)
	{
		if(T->delay <= Tmax_N1)
			T->prescaler=N1;
		else if(T->delay <= Tmax_N8)
			T->prescaler=N8;
		else if(T->delay <= Tmax_N64)
			T->prescaler=N64;
		else if(T->delay <= Tmax_N256)
			T->prescaler=N256;
		else if(T->delay <= Tmax_N1024)
			T->prescaler=N1024;
		else
			T->prescaler = N0;
		switch(T->prescaler)
		{
		case 1:
			T->init_value=init_value(Tmax_N1,T->delay,Tmin_N1);
			break;
		case 8:
			T->init_value=init_value(Tmax_N8,T->delay,Tmin_N8);
			break;
		case 64:
			T->init_value=init_value(Tmax_N64,T->delay,Tmin_N64);
			break;
		case 256:
			T->init_value=init_value(Tmax_N256,T->delay,Tmin_N256);
			break;
		case 1024:
			T->init_value=init_value(Tmax_N1024,T->delay,Tmin_N1024);
			break;
		default:
			T->init_value=0;
			break;
		}
		T->NO_OF_OV=0;
	}
	else
	{
		T->prescaler=N1024;
		T->NO_OF_OV=(T->delay/Tmax_N1024);
		T->init_value=0;
	}
}

/*
 * Description:used to apply delay using polling technique
 * it convert number of overflows to integer number to implement the required delay correctly
 * example: if number of overflows=3.8
 * mean perform 3 overflows and calculate the remaining time to complete the delay
 */
void Timer0_Delay(ST_timer0_config* T)
{
	uint8 real_part=T->NO_OF_OV;
	uint8 reminder=(T->NO_OF_OV-real_part)*(Tmax_N1024); //reminder delay to complete required delay period
	uint8 count=real_part;
	TCNT0=T->init_value;
	if(count==0)										//number of overflows
	{
		switch(T->prescaler)    						//set TCCR0 register with clock source
		{
		case 1:
			TCCR0 = (1<<FOC0) | (1<<CS00);
			break;
		case 8:
			TCCR0 = (1<<FOC0) | (1<<CS01);
			break;
		case 64:
			TCCR0 = (1<<FOC0) | (1<<CS01) | (1<<CS00);
			break;
		case 256:
			TCCR0 = (1<<FOC0) | (1<<CS02);
			break;
		case 1024:
			TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
			break;
		default:
			TCCR0 = 0;
			break;
		}
		while(!(TIFR & (1<<TOV0)));						//Wait until the Timer0 Overflow occurs (wait until TOV0 = 1)
	}
	else												//with overflows
	{
		TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);		//use clock pre_scale 1024
		while(count != 0)								//run delay of real part
		{
			while(!(TIFR & (1<<TOV0)));
			count--;
			TIFR |= (1<<TOV0);
		}
		if(reminder > 0)								//run remaining delay period
		{
			if(reminder <= Tmax_N1)						//find best range that contain the required remaining delay
				T->prescaler=N1;
			else if(reminder <= Tmax_N8)
				T->prescaler=N8;
			else if(reminder <= Tmax_N64)
				T->prescaler=N64;
			else if(reminder <= Tmax_N256)
				T->prescaler=N256;
			else if(reminder <= Tmax_N1024)
				T->prescaler=N1024;
			else
				T->prescaler = N0;
		}
		switch(T->prescaler)							//according to selected pre_scaler value
		{
		case 1:
			TCNT0=init_value(Tmax_N1,reminder,Tmin_N1);	//set TCNT0 register with the initial value
			TCCR0 = (1<<FOC0) | (1<<CS00);				//set TCCR0 register with clock source
			break;
		case 8:
			TCNT0=init_value(Tmax_N8,reminder,Tmin_N8);
			TCCR0 = (1<<FOC0) | (1<<CS01);
			break;
		case 64:
			TCNT0=init_value(Tmax_N64,reminder,Tmin_N64);
			TCCR0 = (1<<FOC0) | (1<<CS01) | (1<<CS00);
			break;
		case 256:
			TCNT0=init_value(Tmax_N256,reminder,Tmin_N256);
			TCCR0 = (1<<FOC0) | (1<<CS02);
			break;
		case 1024:
			TCNT0=init_value(Tmax_N1024,reminder,Tmin_N1024);
			TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
			break;
		default:
			TCNT0=0;
			TCCR0 = 0;
			break;
		}
		while(!(TIFR & (1<<TOV0)));			//Wait until the Timer0 Overflow occurs (wait until TOV0 = 1)
	}
	TIFR |= (1<<TOV0);						//Clear TOV0 bit by set its value
	TCCR0 = 0;								// Stop Timer0 by clear the Clock bits (CS00, CS01 and CS02)
}

