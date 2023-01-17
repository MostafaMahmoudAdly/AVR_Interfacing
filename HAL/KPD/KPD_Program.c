/*
 * KPD_Program.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Windows 10
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KDP_Interface.h"
#include "KPD_Private.h"


static u8 KPD_Map[RowsNumber][ColumnsNumber]={
										{'1','2','3','A'},
										{'4','5','6','B'},
										{'7','8','9','C'},
										{'*','0','#','D'}
									  	  	  	  	  	    };

void KPD_INT(void)
{
	/* Set Rows as Inputs & Pulled up */
	DIO_voidSetPinDirection(Row_PORT,Row_0,PIN_INPUT);
	DIO_voidSetPinDirection(Row_PORT,Row_1,PIN_INPUT);
	DIO_voidSetPinDirection(Row_PORT,Row_2,PIN_INPUT);
	DIO_voidSetPinDirection(Row_PORT,Row_3,PIN_INPUT);

	DIO_voidSetPinValue(Row_PORT,Row_0,PIN_HIGH);
	DIO_voidSetPinValue(Row_PORT,Row_1,PIN_HIGH);
	DIO_voidSetPinValue(Row_PORT,Row_2,PIN_HIGH);
	DIO_voidSetPinValue(Row_PORT,Row_3,PIN_HIGH);

	/* Set Columns as  Output */
	DIO_voidSetPinDirection(Colunm_PORT,Column_0 ,PIN_OUTPUT);
	DIO_voidSetPinDirection(Colunm_PORT,Column_1 ,PIN_OUTPUT);
	DIO_voidSetPinDirection(Colunm_PORT,Column_2 ,PIN_OUTPUT);
	DIO_voidSetPinDirection(Colunm_PORT,Column_3 ,PIN_OUTPUT);

	DIO_voidSetPinValue(Colunm_PORT,Column_0,PIN_HIGH);
	DIO_voidSetPinValue(Colunm_PORT,Column_1,PIN_HIGH);
	DIO_voidSetPinValue(Colunm_PORT,Column_2,PIN_HIGH);
	DIO_voidSetPinValue(Colunm_PORT,Column_3,PIN_HIGH);

	return ;
}

void KPD_GetPressedKey(u8 *Key)
{
	u8 row_Iterator = 0;
	u8 col_Iterator = 0;
	u8 KeyFlage = 0;

	/*reset the key value */
	*Key = 0;

	for(col_Iterator = 0 ; col_Iterator < ColumnsNumber ; col_Iterator++)
	{
		/*shift the pin to change the column in the next column loop*/
		DIO_voidSetPinValue(Colunm_PORT,(Column_0 + col_Iterator),PIN_LOW);

		for(row_Iterator = 0 ; row_Iterator < RowsNumber ; row_Iterator++)
		{
			if(DIO_voidGetBitValue(Row_PORT,(Row_0 + row_Iterator))==PIN_LOW)
			{
				*Key = KPD_Map[row_Iterator][col_Iterator];

				KeyFlage++;

				break;
			}

			else
			{
				/*Do nothing*/
			}
		}

		DIO_voidSetPinValue(Colunm_PORT,(Column_0 + col_Iterator),PIN_HIGH);

		if(KeyFlage !=0)  /*if keyflage !=0*/
		{
			break;
		}

		else
		{
			/*Do nothing*/
		}
	}
}
