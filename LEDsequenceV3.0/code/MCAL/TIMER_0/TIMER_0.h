/*
 * TIMER_0.h
 *
 *  Created on: Apr 9, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_TIMER_0_TIMER_0_H_
#define MCAL_TIMER_0_TIMER_0_H_

/*============= FILE INCLUSION =============*/
#include "../../Utilities/Std_Types.h"

/*============= TYPE DEFINITION =============*/
typedef struct{
    float delay;
    uint16 prescaler;
    uint8 init_value;
    float NO_OF_OV;
}ST_timer0_config;

/*============= MACRO DEFINITION =============*/
#define TCCR0 (*((volatile uint8*)0x53))
#define TCNT0 (*((volatile uint8*)0x52))
#define OCR0  (*((volatile uint8*)0x5C))
#define TIFR  (*((volatile uint8*)0x58))
#define TIMSK (*((volatile uint8*)0x59))

//TCCR0 timer counter control register
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
//TIMSK interrupt mask register
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7
//TIFR interrupt flag register
#define TOV0  0
#define OCF0  1
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1  5
#define TOV2  6
#define OCF2  7

/*============= FUNCTION PROTOTYPE =============*/
void Timer0_Config(ST_timer0_config* T);
void Timer0_Delay(ST_timer0_config* T);


#endif /* MCAL_TIMER_0_TIMER_0_H_ */
