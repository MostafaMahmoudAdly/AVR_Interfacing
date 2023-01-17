/*
 * I2C_Interface.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Windows 10
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

/* 						Macros             			*/
#define Master_ADD   0x01
#define Slave_ADD    0x02



/*     				    Function Prototypes          */
typedef enum
{
	I2C_OK,
	I2C_NOK,
	STRAT_COD_ERR,
	STOP_COD_ERR,
	SLA_W_ERR,
	SLA_R_ERR,
	DATA_M_S_ERR,
	DATA_M_R_ERR,
	DATA_S_S_ERR,
	DATA_S_R_ERR
}I2C_Error;


void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd);


I2C_Error I2C_enuSendStrartCond(void);
I2C_Error I2C_enuSendStopCond(void);

I2C_Error I2C_enuSendSlaWrite(u8 Copy_u8SlaveAdd);
I2C_Error I2C_enuSendSlaRaed(u8 Copy_u8SlaveAdd);

I2C_Error I2C_enuSendDataM(u8 Copy_u8Data);
I2C_Error I2C_enuReceiveDataM(u8 * Copy_u8Data);

I2C_Error I2C_enuSendDataS(u8 Copy_u8Data);
I2C_Error I2C_enuReceiveDataS(u8 * Copy_u8Data);


#endif /* I2C_INTERFACE_H_ */
