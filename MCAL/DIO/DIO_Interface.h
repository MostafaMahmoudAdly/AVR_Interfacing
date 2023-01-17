/*
 * DIO_Interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Mostafa Mahmoud
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/************************************************************************************/
/*                                 Interfacing Macros                               */
/************************************************************************************/

#define PORTA_ID   0
#define PORTB_ID   1
#define PORTC_ID   2
#define PORTD_ID   3

#define PIN0_ID    0
#define PIN1_ID    1
#define PIN2_ID    2
#define PIN3_ID    3
#define PIN4_ID    4
#define PIN5_ID    5
#define PIN6_ID    6
#define PIN7_ID    7

#define HIGH       1
#define LOW        0

#define OUTPUT     1
#define INPUT      0

/****************************************************************************************/
/*                                   Functions Prototypes                               */
/****************************************************************************************/

void DIO_SETPinDirection(u8 PORT_ID , u8 PIN_ID , u8 PinDirection);

void DIO_SETPinValue(u8 PORT_ID , u8 PIN_ID , u8 pinValue);

void DIO_SETPortDirection(u8 PORT_ID , u8 PortDirection);

void DIO_SETPortValue(u8 PORT_ID , u8 PortValue);

void DIO_TogglingPin(u8 PORT_ID , u8 PIN_ID);

u8 DIO_ReadPinValue(u8 PORT_ID , u8 PIN_ID);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
