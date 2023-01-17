/*
 * EXTI_Program.h
 *
 *  Created on: Nov 17, 2022
 *      Author: Windows 10
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define MCUCR_REG      *((volatile u8*)0x55)
#define ISC00          0x00
#define ISC01          0x01
#define ISC10		   0x02
#define ISC11          0x03

#define MCUCSR_REG     *((volatile u8*)0x54)
#define ISC2           0x06

#define GICR_REG      *((volatile u8*)0x5B)
#define INT2          0x05
#define INT0          0x06
#define INT1          0x07

#define GIFR_REG      *((volatile u8*)0x5A)
#define INTF2          0x05
#define INTF0          0x06
#define INTF1          0x07


void __vector_1 () __attribute__ ((signal));

void __vector_2 () __attribute__ ((signal));

void __vector_3 () __attribute__ ((signal));

#endif /* EXTI_PRIVATE_H_ */
