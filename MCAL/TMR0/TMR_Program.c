/*
 * TMR_Program.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Windows 10
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TMR_Interface.h"
#include "TMR_Private.h"


void (*ptr_callback)(void) = 0;

void TMR0_voidInit(u8 CopyU8_Mode)
{
	/*
	 * 8 bit timer
	 * frequency = 8 MZ
	 * prescaller = 8
	 * desigred time = 1.5 sec
	 * so preload value = 160
	 */

	if(CopyU8_Mode == OverFlow)
	{
		/*	set	preload value  */
		TCNT0 = 160;

		/*		Normal Mode		*/
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		/*EN Overflow Interrupt*/
		SET_BIT(TIMSK,0);
	}
	else if(CopyU8_Mode == CompareMatch)
	{
		/*	set	preload value  */
		OCR0 = 250 ;

		/*		ctc Mode		*/
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		/*EN compare match Interrupt*/
		SET_BIT(TIMSK,1);
	}
	else if(CopyU8_Mode == Fast_PWM)
	{
		/*		fast pwm Mode		*/
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		/*	Non Inverting mode
		 * Clear OC0 on compare match, set OC0 at TOP
		 */
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	}
	else if(CopyU8_Mode == PhaseCorrect_PWM)
	{
		/*		PhaseCorrect pwm Mode		*/
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		/*	Non Inverting mode
		 * Clear OC0 on compare match when up-counting. Set OC0 on compare match when down counting
		 */
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	}

	/*		8prescaller		*/
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void TMR0_GeneratePWM(u8 CopyU8_DutyCycle)
{
	OCR0 = CopyU8_DutyCycle;
}
/*		over flow ISR		*/
void TMR0_CallBack(void (*func)(void))
{
	ptr_callback = func;
}

void __vector_10 (void)
{
	if(ptr_callback !=0)
		ptr_callback();

}

void __vector_11 (void)
{
	if(ptr_callback !=0)
		ptr_callback();

}
