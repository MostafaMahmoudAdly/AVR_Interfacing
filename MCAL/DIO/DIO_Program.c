/*
 * DIO_Program.c
 *
 *  Created on: Nov 11, 2022
 *      Author: Mostafa Mahmoud
 *
 */

/****************************************************************************************/
/*                                   Includes                                           */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"


/****************************************************************************************/
/*                                   Functions Definitions                              */
/****************************************************************************************/

void DIO_SETPinDirection(u8 PORT_ID , u8 PIN_ID , u8 PinDirection)
{
	if(PinDirection==OUTPUT)
	{
		switch(PORT_ID)
		{
			case PORTA_ID : SET_BIT(DDRA_REG,PIN_ID);  break;
			case PORTB_ID : SET_BIT(DDRB_REG,PIN_ID);  break;
			case PORTC_ID : SET_BIT(DDRC_REG,PIN_ID);  break;
			case PORTD_ID : SET_BIT(DDRD_REG,PIN_ID);  break;
		}
	}
	else if(PinDirection==INPUT)
	{
		switch(PORT_ID)
		{
			case PORTA_ID : CLR_BIT(DDRA_REG,PIN_ID);  break;
			case PORTB_ID : CLR_BIT(DDRB_REG,PIN_ID);  break;
			case PORTC_ID : CLR_BIT(DDRC_REG,PIN_ID);  break;
			case PORTD_ID : CLR_BIT(DDRD_REG,PIN_ID);  break;
		}
	}
}

void DIO_SETPinValue(u8 PORT_ID , u8 PIN_ID , u8 pinValue)
{
	if(pinValue==HIGH)
		{
			switch(PORT_ID)
			{
				case PORTA_ID : SET_BIT(PORTA_REG,PIN_ID);  break;
				case PORTB_ID : SET_BIT(PORTB_REG,PIN_ID);  break;
				case PORTC_ID : SET_BIT(PORTC_REG,PIN_ID);  break;
				case PORTD_ID : SET_BIT(PORTD_REG,PIN_ID);  break;
			}
		}
		else if(pinValue==LOW)
		{
			switch(PORT_ID)
			{
				case PORTA_ID : CLR_BIT(PORTA_REG,PIN_ID);  break;
				case PORTB_ID : CLR_BIT(PORTB_REG,PIN_ID);  break;
				case PORTC_ID : CLR_BIT(PORTC_REG,PIN_ID);  break;
				case PORTD_ID : CLR_BIT(PORTD_REG,PIN_ID);  break;
			}
		}
}

void DIO_SETPortDirection(u8 PORT_ID , u8 PortDirection)
{

		switch(PORT_ID)
		{
		case PORTA_ID : DDRA_REG = PortDirection;    break;
		case PORTB_ID : DDRB_REG = PortDirection;    break;
		case PORTC_ID : DDRC_REG = PortDirection;    break;
		case PORTD_ID : DDRD_REG = PortDirection;    break;
		}

}

void DIO_SETPortValue(u8 PORT_ID , u8 PortValue)
{
		switch(PORT_ID)
			{
			case PORTA_ID : PORTA_REG = PortValue;    break;
			case PORTB_ID : PORTB_REG = PortValue;    break;
			case PORTC_ID : PORTC_REG = PortValue;    break;
			case PORTD_ID : PORTD_REG = PortValue;    break;
			}

}

void DIO_TogglingPin(u8 PORT_ID , u8 PIN_ID)
{
		switch(PORT_ID)
		{
			case PORTA_ID : TOG_BIT(PORTA_REG,PIN_ID);  break;
			case PORTB_ID : TOG_BIT(PORTB_REG,PIN_ID);  break;
			case PORTC_ID : TOG_BIT(PORTC_REG,PIN_ID);  break;
			case PORTD_ID : TOG_BIT(PORTD_REG,PIN_ID);  break;
		}

}

u8 DIOReadPinValue(u8 PORT_ID , u8 PIN_ID)
{
	u8 Local_PinValue;
	switch(PORT_ID)
	{
		case PORTA_ID : Local_PinValue = GET_BIT(PINA_REG,PIN_ID);    break;
		case PORTB_ID : Local_PinValue = GET_BIT(PINB_REG,PIN_ID);    break;
		case PORTC_ID : Local_PinValue = GET_BIT(PINC_REG,PIN_ID);    break;
		case PORTD_ID : Local_PinValue = GET_BIT(PIND_REG,PIN_ID);    break;
	}

	return Local_PinValue;
}
