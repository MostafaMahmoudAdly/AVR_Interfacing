/*
 * LCD_Interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Windows 10
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define Row0   0
#define Row1   1


#define Col0   0
#define Col1   1
#define Col2   2
#define Col3   3
#define Col4   4
#define Col5   5
#define Col6   6
#define Col7   7
#define Col8   8
#define Col9   9
#define Col10  10
#define Col11  11
#define Col12  12
#define Col13  13
#define Col14  14
#define Col15  15



void LCD_voidWriteBitsToSend(u8 copy_u8Byte);

void LCD_voidInit(void);

void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);

void LCD_voidWriteString(u8 * copy_str);

void LCD_voidWriteChar(u8 CharData);

void LCD_SetCursor(u8 Row , u8 Col);

void LCD_voidClear(void);

void LCD_voidPrintNumber(u16 number);


#endif /* LCD_INTERFACE_H_ */
