/*
 * ADC.Program.c
 *
 *  Created on: Dec 28, 2022
 *      Author: Windows 10
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

static void (*ADC_CallBack)(void) = {NULL};

void ADC_VoidInit(void)
{
	/*	Voltage Reference Selections for ADC	*/
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	/*	ADC Left Adjust Result(data managing)	*/
	CLR_BIT(ADMUX,5);

	/*	set the prescaller	*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	/*	interrput enable	*/
	SET_BIT(ADCSRA,3);

	/*	 ADEN: ADC Enable	*/
	SET_BIT(ADCSRA,7);
}

void ADC_voidChannelSellect(u8 copy_u8ChannelSellect )
{
	/*	Input Channel and Gain Selections
	 *  clear the first 5 bits
	 *  set the first 5 bits by the select channel from the user
	 * */
	ADMUX &= 0b11100000;
	ADMUX |= copy_u8ChannelSellect;
}

void ADC_StartConversion(u16 *copy_Pu8Data)
{
	/*	start conversion	*/
	SET_BIT(ADCSRA,6);

	/*	polling in the flage	*/
	//while(GET_BIT(ADCSRA,4)==0);
	/*	clear the flage	*/
	//SET_BIT(ADCSRA,4);

	/*	return the data	*/
	*copy_Pu8Data=ADCL;
}

void ADC_voidSetCallBack(  void (*ptr_ext)(void) )
{
	if(ptr_ext!=NULL)
	ADC_CallBack = ptr_ext;
}

void __vector_16 ()
{
	ADC_CallBack();
}


