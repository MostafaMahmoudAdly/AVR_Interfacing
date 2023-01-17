/*
 * LCD_Program.c

 *
 *  Created on: Nov 11, 2022
 *      Author: Windows 10
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"

static u8 NumberIndex[50];

void LCD_voidWriteBitsToSend(u8 copy_u8Byte)
{

	//DIO_voidSetPinValue(RW_PORT,RW_PIN, PIN_LOW);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);




	DIO_voidSetPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 7) & 1);
	DIO_voidSetPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 6) & 1);
	DIO_voidSetPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 5) & 1);
	DIO_voidSetPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 4) & 1);

	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(30);

	DIO_voidSetPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 3) & 1);
	DIO_voidSetPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 2) & 1);
	DIO_voidSetPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 1) & 1);
	DIO_voidSetPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 0) & 1);

	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(30);



}


void LCD_voidInit(void)
{
	_delay_ms(30);

	DIO_voidSetPinDirection(RS_PORT,RS_PIN,PIN_OUTPUT);
	// DIO_voidSetPinDirection(RW_PORT,RW_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(EN_PORT, EN_PIN,PIN_OUTPUT);


	DIO_voidSetPinDirection(D4_PORT,D4_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D5_PORT,D5_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D6_PORT,D6_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D7_PORT,D7_PIN,PIN_OUTPUT);




	LCD_voidWriteCommand(0x02);
    _delay_ms(2);

	LCD_voidWriteCommand(0x2C);
	_delay_ms(2);

	LCD_voidWriteCommand(0x0C);
	_delay_ms(2);

	LCD_voidWriteCommand(0x01);

	_delay_ms(2);

	LCD_voidWriteCommand(0x06 );

}
void LCD_voidWriteData(u8 copy_u8data)
{

	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_HIGH);


	LCD_voidWriteBitsToSend(copy_u8data);
}
void LCD_voidWriteCommand(u8 copy_u8Command)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_LOW);



	LCD_voidWriteBitsToSend(copy_u8Command);
}
void LCD_voidWriteString(u8 * copy_str)
{
	u32 i= 0;
	while(copy_str[i] != '\0')
	{
		LCD_voidWriteData(copy_str[i]);
		i++;
	}
}

void LCD_voidWriteChar(u8 CharData)
{
	LCD_voidWriteData(CharData);
}

void LCD_SetCursor(u8 Row , u8 Col)
{
	switch(Row)
	{
		case Row0 : LCD_voidWriteCommand( ((0x80) |Col ) );  break;
		case Row1 : LCD_voidWriteCommand( ((0x80) | (0x40) | Col ) );  break;
		default :  break;
	}

}

void LCD_voidClear(void)
{
	LCD_voidWriteCommand( 0x01);
}

void LCD_voidPrintNumber(u16 number)   //to display number like 123 char by char
{
	u8 i =-1;
	u8 x;

	while(number != 0)
	{
		i++;
		x=number % 10;
		number /= 10;
		NumberIndex[i] = x;

	}
	while(i >= 0)
	{
		LCD_voidWriteChar(NumberIndex[i]);
		i--;
	}

}

