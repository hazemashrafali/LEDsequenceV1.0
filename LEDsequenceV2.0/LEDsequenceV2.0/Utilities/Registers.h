/*
 * Registers.h
 *
 *  Created on: Apr 4, 2023
 *      Author: HAZEM-PC
 */

#ifndef UTILITIES_REGISTERS_H_
#define UTILITIES_REGISTERS_H_

#include "Std_Types.h"

/*============= TYPE DEFINITION =============*/
typedef struct{
	uint8 pinx;
	uint8 ddrx;
	uint8 portx;
}ST_register_name;
typedef ST_register_name* REG_NAME;


/*============= MACRO DEFINITION =============*/
#define PORTA ((volatile REG_NAME)0x39)
#define PORTB ((volatile REG_NAME)0x36)
#define PORTC ((volatile REG_NAME)0x33)
#define PORTD ((volatile REG_NAME)0x30)

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define MAX_PIN 8

#endif /* UTILITIES_REGISTERS_H_ */
