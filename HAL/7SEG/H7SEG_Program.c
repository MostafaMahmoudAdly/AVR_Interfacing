/*
 * H7SEG_Program.c
 *
 *  Created on: Dec 17, 2022
 *      Author: Windows 10
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "H7SEG_Interface.h"
#include "H7SEG_Private.h"


void H7SEG_Init()
{
	DIO_SETPinDirection(H7SEG_PORT,H7SEG_A,OUTPUT);
	DIO_SETPinDirection(H7SEG_PORT,H7SEG_B,OUTPUT);
	DIO_SETPinDirection(H7SEG_PORT,H7SEG_C,OUTPUT);
	DIO_SETPinDirection(H7SEG_PORT,H7SEG_D,OUTPUT);
}

void H7SEG_DesplayNumber(u8 Copy_U8Number)
{

	DIO_SETPinValue(H7SEG_PORT,H7SEG_A,GET_BIT(Copy_U8Number,0));
	DIO_SETPinValue(H7SEG_PORT,H7SEG_B,GET_BIT(Copy_U8Number,1));
	DIO_SETPinValue(H7SEG_PORT,H7SEG_C,GET_BIT(Copy_U8Number,2));
	DIO_SETPinValue(H7SEG_PORT,H7SEG_D,GET_BIT(Copy_U8Number,3));
}
