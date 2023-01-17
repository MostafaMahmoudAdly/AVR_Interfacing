/*
 * TMR_Interface.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Windows 10
 */

#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

#define OverFlow			0
#define CompareMatch		1
#define Fast_PWM			3
#define PhaseCorrect_PWM	4

#define OC0				3  //pin 4 portB

void TMR0_voidInit(u8 CopyU8_Mode);

void TMR0_GeneratePWM(u8 CopyU8_DutyCycle);

void TMR0_CallBack(void (*func)(void));

void __vector_10 (void) __attribute__((signal));

void __vector_11 (void) __attribute__((signal));

#endif /* TMR_INTERFACE_H_ */
