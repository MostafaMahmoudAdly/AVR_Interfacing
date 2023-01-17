/*
 * EXTI_Interface.h
 *
 *  Created on: Nov 17, 2022
 *      Author: Windows 10
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define INT0_PIN    0X00
#define INT1_PIN    0X01
#define INT2_PIN    0X02

#define RISING_EDGE       0X00
#define FALLING_EDGE      0X01
#define SWITCHING         0X02
#define LOW_LEVEL         0X03



void EXTI_VoidInit(u8 Copy_u8Pin,u8 Copy_u8ControlSense);

void EXTI_VoidEnable(u8 Copy_u8Pin);

void EXTI_VoidDisable(u8 Copy_u8Pin);

void EXT_VoidSetCallBack(  void (*ptr_ext)(void) ,u8 Copy_u8Pin);

void __vector_1 (void) __attribute__((signal));

void __vector_2 (void) __attribute__((signal));

void __vector_3 (void) __attribute__((signal));


#endif /* EXTI_INTERFACE_H_ */
