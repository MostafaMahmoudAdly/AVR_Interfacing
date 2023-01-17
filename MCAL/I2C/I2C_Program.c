/*
* I2C_Program.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Windows 10
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"

void I2C_voidMasterInit(void)
{
	/*		Set the Bit Rate = 100KHz			*/
	TWBR = 72;
	/*		Enable I2C							*/
	SET_BIT(TWCR,TWCR_TWEN);
	/*		Enable ACK							*/
	SET_BIT(TWCR,TWCR_TWEA);
	/*		Assign the master Address			*/
	TWAR = (Master_ADD<<1);
}

void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd)
{
	/*		Enable I2C							*/
	SET_BIT(TWCR,TWCR_TWEN);
	/*		Enable ACK							*/
	SET_BIT(TWCR,TWCR_TWEA);
	/*		Assign the slave Address			*/
	TWAR = (Slave_ADD<<1);
}


I2C_Error I2C_enuSendStrartCond(void)
{
	I2C_Error  Local_enuErr = I2C_NOK;
	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Send a Start cond.		        */
	SET_BIT(TWCR,TWCR_TWEA);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0x08)
	{
		Local_enuErr = I2C_OK;
	}
	else
	{
		Local_enuErr = STRAT_COD_ERR;
	}
	return Local_enuErr;
}

I2C_Error I2C_enuSendStopCond(void)
{
	I2C_Error  Local_enuErr = I2C_NOK;
	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Send a Stop cond.		        */
	SET_BIT(TWCR,TWCR_TWSTO);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0xA0)
	{
		Local_enuErr = I2C_OK;
	}
	else
	{
		Local_enuErr = STOP_COD_ERR;
	}
	return Local_enuErr;
}


I2C_Error I2C_enuSendSlaWrite(u8 Copy_u8SlaveAdd)
{
	I2C_Error  Local_enuErr = I2C_NOK;
	/*		Clear the Start Cond	*/
	CLR_BIT(TWCR,TWCR_TWEA);
	/*		Set the Slave Add		*/
	TWAR = (Copy_u8SlaveAdd <<1 );     //shift right 1 to make LSB = 0 to write

	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0x18)
	{
		Local_enuErr = I2C_OK;
	}
	else
	{
		Local_enuErr = SLA_W_ERR;
	}
	return Local_enuErr;
}

I2C_Error I2C_enuSendSlaRaed(u8 Copy_u8SlaveAdd)
{
	I2C_Error  Local_enuErr = I2C_NOK;
	/*		Clear the Start Cond	*/
	CLR_BIT(TWCR,TWCR_TWEA);
	/*		Set the Slave Add		*/
	TWAR = (Copy_u8SlaveAdd <<1 );        //shift right 1 to make LSB = 0
	/*		For Read Operation		*/
	SET_BIT(TWAR,0);                     //then set the LSB to read

	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0x40)
	{
		Local_enuErr = I2C_OK;
	}
	else
	{
		Local_enuErr = SLA_R_ERR;
	}

	return Local_enuErr;
}


I2C_Error I2C_enuSendDataM(u8 Copy_u8Data)
{
	I2C_Error  Local_enuErr = I2C_NOK;
	/*		Set the Data			*/
	TWDR = Copy_u8Data;

	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0x28)
	{
		Local_enuErr = I2C_OK;
	}
	else
	{
		Local_enuErr = DATA_M_S_ERR;
	}

	return Local_enuErr;
}

I2C_Error I2C_enuReceiveDataM(u8 * Copy_u8Data)
{
	I2C_Error  Local_enuErr = I2C_NOK;

	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0x50)
	{
		Local_enuErr = I2C_OK;
		*Copy_u8Data = TWDR;
	}
	else
	{
		Local_enuErr = DATA_M_R_ERR;
	}

	return Local_enuErr;
}


I2C_Error I2C_enuSendDataS(u8 Copy_u8Data)
{
	I2C_Error  Local_enuErr = I2C_NOK;
	/*		Set the Data			*/
	TWDR = Copy_u8Data;

	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0xB8)
	{
		Local_enuErr = I2C_OK;
	}
	else
	{
		Local_enuErr = DATA_S_S_ERR;
	}

	return Local_enuErr;
}

I2C_Error I2C_enuReceiveDataS(u8 * Copy_u8Data)
{
	I2C_Error  Local_enuErr = I2C_NOK;

	/*		Clear the Flag	by sit it		*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*		Wait on the Flag		        */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*		Error Check				        */
	if(( TWSR & 0xF8 ) == 0x80)
	{
		Local_enuErr = I2C_OK;
		*Copy_u8Data = TWDR;
	}
	else
	{
		Local_enuErr = DATA_S_R_ERR;
	}

	return Local_enuErr;
}



