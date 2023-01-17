/*
 * EXTI_Program.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Windows 10
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

static void (*ptr_ArrCallBack[ ])(void) = {NULL,NULL,NULL};  //pointer to function (back to function)

void EXTI_VoidInit(u8 Copy_u8Pin,u8 Copy_u8ControlSense)
{
	switch(Copy_u8Pin)
	{
		case INT0_PIN :
			switch(Copy_u8ControlSense)
			{
				case RISING_EDGE : SET_BIT(MCUCR_REG,ISC00);  SET_BIT(MCUCR_REG,ISC01);  break;
				case FALLING_EDGE: CLR_BIT(MCUCR_REG,ISC00);  SET_BIT(MCUCR_REG,ISC01);  break;
				case SWITCHING   : SET_BIT(MCUCR_REG,ISC00);  CLR_BIT(MCUCR_REG,ISC01);  break;
				case LOW_LEVEL   : CLR_BIT(MCUCR_REG,ISC00);  CLR_BIT(MCUCR_REG,ISC01);  break;
				default : break;
			}
		break;
		case INT1_PIN :
			switch(Copy_u8ControlSense)
			{
				case RISING_EDGE : SET_BIT(MCUCR_REG,ISC10);  SET_BIT(MCUCR_REG,ISC11);  break;
				case FALLING_EDGE: CLR_BIT(MCUCR_REG,ISC10);  SET_BIT(MCUCR_REG,ISC11);  break;
				case SWITCHING   : SET_BIT(MCUCR_REG,ISC10);  CLR_BIT(MCUCR_REG,ISC11);  break;
				case LOW_LEVEL   : CLR_BIT(MCUCR_REG,ISC10);  CLR_BIT(MCUCR_REG,ISC11);  break;
				default : break;
			}
		break;
		case INT2_PIN :
			switch(Copy_u8ControlSense)
			{
				case RISING_EDGE : SET_BIT(MCUCSR_REG,ISC2);   break;
				case FALLING_EDGE: CLR_BIT(MCUCSR_REG,ISC2);   break;
				default : break;
		   }
		break;
	}
}

void EXTI_VoidEnable(u8 Copy_u8Pin)
{
	switch(Copy_u8Pin)
	{
	 case INT0_PIN : SET_BIT(GICR_REG,INT0);  break;
	 case INT1_PIN : SET_BIT(GICR_REG,INT1);  break;
	 case INT2_PIN : SET_BIT(GICR_REG,INT2);  break;
	 default : break;
	}
}

void EXTI_VoidDisable(u8 Copy_u8Pin)
{
	switch(Copy_u8Pin)
	{
	 case INT0 : CLR_BIT(GICR_REG,INT0);  break;
	 case INT1 : CLR_BIT(GICR_REG,INT1);  break;
	 case INT2 : CLR_BIT(GICR_REG,INT2);  break;
	 default : break;
	}
}

void EXT_VoidSetCallBack(  void (*ptr_ext)(void) ,u8 Copy_u8Pin)
{
	switch(Copy_u8Pin)
    {
	  case INT0_PIN:
		  ptr_ArrCallBack[ 0 ]= ptr_ext;
		  break;
	  case INT1_PIN:
		  ptr_ArrCallBack[ 1 ]= ptr_ext;
		  break;
	 case INT2_PIN:
		 ptr_ArrCallBack[ 2 ]= ptr_ext;
		 break;
	 default: break;
	}
}

void __vector_1 ()
{
	if(ptr_ArrCallBack[ 0 ] != 0)
	ptr_ArrCallBack[0]();

}

void __vector_2 ()
{
	if(ptr_ArrCallBack[ 1 ] != 0)
	ptr_ArrCallBack[1]();


}

void __vector_3 ()
{
	if(ptr_ArrCallBack[ 2 ] != 0)
	ptr_ArrCallBack[2]();


}

