/*
 * TMR_Private.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Windows 10
 */

#ifndef TMR_PRIVATE_H_
#define TMR_PRIVATE_H_

#define TCCR0		*((volatile u8*)0x53)
#define TCNT0		*((volatile u8*)0x52)
#define OCR0		*((volatile u8*)0x5C)
#define TIMSK		*((volatile u8*)0x59)
#define TIFR		*((volatile u8*)0x58)

#endif /* TMR_PRIVATE_H_ */
