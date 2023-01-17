/*
 * I2C_Private.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Windows 10
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*   Bit Rate Register           */
#define TWBR       *((volatile u8*)0x20)

/*      Control register          */
#define TWCR       *((volatile u8*)0x56)
#define TWCR_TWINT      0x07
#define TWCR_TWEA       0x06
#define TWCR_TWSTA      0x05
#define TWCR_TWSTO      0x04
#define TWCR_TWWC       0x03
#define TWCR_TWEN       0x02
#define TWCR_TWIE       0x00

/*     	Status Register   		*/
#define TWSR       *((volatile u8*)0x21)

#define TWDR       *((volatile u8*)0x23)

#define TWAR       *((volatile u8*)0x22)
#define TWAR_TWGCE       0x00   //to select read or write

#endif /* I2C_PRIVATE_H_ */
