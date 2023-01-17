/*
 * ADC_Interface.h
 *
 *  Created on: Dec 28, 2022
 *      Author: Windows 10
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


void ADC_VoidInit(void);

void ADC_voidChannelSellect(u8 copy_u8ChannelSellect );

void ADC_StartConversion(u16 *copy_Pu8Data);

void ADC_voidSetCallBack(  void (*ptr_ext)(void) );

void  __vector_16() __attribute__((signal));


#endif /* ADC_INTERFACE_H_ */
