/*
 * Timer0_Utilities.h
 *
 *  Created on: Apr 10, 2023
 *      Author: HAZEM-PC
 */

#ifndef MCAL_TIMER_0_TIMER0_UTILITIES_H_
#define MCAL_TIMER_0_TIMER0_UTILITIES_H_

/*============= MACRO DEFINITION =============*/

#define max_count 256
#define min_count 1
#define init_value(T_max,T_delay,tick)  (((float)T_max-T_delay)/tick)

//pre_scaler values for TIMER0
#define N0    0
#define N1    1
#define N8    8
#define N64   64
#define N256  256
#define N1024 1024

//T_max in (ms) delay for each pre_scaler
#define Tmax_N1    0.26F
#define Tmax_N8    2.05F
#define Tmax_N64   16.38F
#define Tmax_N256  65.54F
#define Tmax_N1024 262.14F

//T_min in (ms) delay for each pre_scaler
#define Tmin_N1    0.001F
#define Tmin_N8    0.008F
#define Tmin_N64   0.064F
#define Tmin_N256  0.256F
#define Tmin_N1024 1.024F

#endif /* MCAL_TIMER_0_TIMER0_UTILITIES_H_ */
