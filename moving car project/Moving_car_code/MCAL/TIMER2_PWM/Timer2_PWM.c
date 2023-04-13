/*
 * Timer0_PWM.c
 *
 *  Created on: Apr 12, 2023
 *      Author: HAZEM-PC
 */

/*============= FILE INCLUSION =============*/
#include "Timer2_PWM.h"
#include "../GPIO/DIO.h"
#include <avr/interrupt.h>

/*============= global variables =============*/
uint8 g_port,g_pin,g_flag=0;
float time_on,time_off;
float initValue_1,initValue_2;


void PWM_Timer2_Init(void)
{
	TCNT2 = 0; //Set Timer Initial value
	DDRD  = DDRD | (1<<PD7);
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) ;
}
void PWM_Timer2_Start(uint8 duty_cycle)
{
	duty_cycle=(duty_cycle*255)/100;
	OCR2  = duty_cycle; // Set Compare Value
	TCCR2 |= (1<<CS21); //enable clock
}
void PWM_Timer2_Stop(void)
{
	TCCR2 = 0;
}


/*
void Timer0_pwm_init(uint8 pin,uint8 duty_cycle)
{
	check_pin(&pin, &g_port);
	g_pin=pin;
	DIO_pinDirection(g_port,pin, PIN_OUTPUT);
	DIO_writePin(g_port,pin,Low);
	time_on=((float)T_period*duty_cycle)/100;
	time_off=T_period-time_on;
	initValue_1=(Tmax-time_on)/TickTime;
	initValue_2=(Tmax-time_off)/TickTime;
	TCNT0=0;									//Set Timer initial value
	TIMSK |= (1<<TOIE0);						// Enable Timer0 Overflow Interrupt
	SREG  |= (1<<7);							// Enable global interrupt
	TCCR0 = (1<<FOC0) | (1<<CS01) | (1<<CS00);
}

void Timer0_pwm_Deinit(uint8 pin)
{
	TIMSK &= (~(1<<TOIE0));
	TCCR0=0;
}

ISR(TIMER0_OVF_vect)
{
	if(g_flag==0)
	{
		TCNT0=initValue_2;
	    g_flag=1;
	}
	else
	{
		TCNT0=initValue_1;
		g_flag=0;
	}
	DIO_togglePin(g_port, g_pin);
}

*/
