/*
 * GIE_Program.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Windows 10
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Private.h"

void GIE_VoidEnable(void)
{
	SET_BIT(SREG_REG,I);
}

void GIE_VoidDisable(void)
{
	CLR_BIT(SREG_REG,I);
}
