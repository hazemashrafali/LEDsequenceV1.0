/*
 * TIMER_0.c
 *
 *  Created on: Apr 9, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "TIMER_0.h"
#include "Timer0_Utilities.h"

/*============= TYPE DEFINITION =============*/
typedef struct{
    uint16 prescaler;
    uint8 init_value;
    float NO_OF_OV;
}ST_timer0_config;

/*============= PRIVATE FUNCTIONS =============*/
static uint8 calc_prescaler(float delay,uint16* prescale);
static void calc_initialValue(uint16 prescaler,uint8* init_value,float delay);
static void set_prescale(uint16 prescaler);

/*============= FUNCTION DEFINITIONS =============*/
/*
 * Description:used to calculate timer settings
 * calculate pre_scale value
 * calculate number of overflows
 * calculate timer initial value
 */

void Timer0_Delay(float delay)
{
	//delay-=5;
	ST_timer0_config Time;
	uint8 real_part,reminder,count;
	if(calc_prescaler(delay, &Time.prescaler))
	{
		calc_initialValue(Time.prescaler, &Time.init_value,delay);
		Time.NO_OF_OV=0;
	}
	else
	{
		Time.prescaler=N1024;
		Time.NO_OF_OV=(delay/Tmax_N1024);
		Time.init_value=0;
	}
	real_part=Time.NO_OF_OV;
	reminder=(Time.NO_OF_OV-real_part)*(Tmax_N1024); //reminder delay to complete required delay period
	count=real_part;
	TCNT0=Time.init_value;
	if(count==0)
	{
		set_prescale(Time.prescaler);
		while(!(TIFR & (1<<TOV0)));
	}
	else
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
				Time.prescaler=N1;
			else if(reminder <= Tmax_N8)
				Time.prescaler=N8;
			else if(reminder <= Tmax_N64)
				Time.prescaler=N64;
			else if(reminder <= Tmax_N256)
				Time.prescaler=N256;
			else if(reminder <= Tmax_N1024)
				Time.prescaler=N1024;
			else
				Time.prescaler = N0;
		}
		switch(Time.prescaler)							//according to selected pre_scaler value
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
	TCCR0 = 0;
}


static uint8 calc_prescaler(float delay,uint16* prescale)
{
	if(delay <= Tmax_N1024)
	{
		if(delay <= Tmax_N1)
			*prescale=N1;
		else if(delay <= Tmax_N8)
			*prescale=N8;
		else if(delay <= Tmax_N64)
			*prescale=N64;
		else if(delay <= Tmax_N256)
			*prescale=N256;
		else if(delay <= Tmax_N1024)
			*prescale=N1024;
		else
			*prescale = N0;
		return 1;
	}
	else
		return 0;
}

static void calc_initialValue(uint16 prescaler,uint8* init_value,float delay)
{
	switch(prescaler)
	{
	case 1:
		*init_value=init_value(Tmax_N1,delay,Tmin_N1);
		break;
	case 8:
		*init_value=init_value(Tmax_N8,delay,Tmin_N8);
		break;
	case 64:
		*init_value=init_value(Tmax_N64,delay,Tmin_N64);
		break;
	case 256:
		*init_value=init_value(Tmax_N256,delay,Tmin_N256);
		break;
	case 1024:
		*init_value=init_value(Tmax_N1024,delay,Tmin_N1024);
		break;
	default:
		*init_value=0;
		break;
	}
}

static void set_prescale(uint16 prescaler)
{
	switch(prescaler)
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
}
