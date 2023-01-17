/*
 * USAR_Private.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Windows 10
 */

#ifndef USAR_PRIVATE_H_
#define USAR_PRIVATE_H_

#define UDR        *((volatile u8*)0x2C)

#define UCSRA        *((volatile u8*)0x2B)
#define UCSRA_RXC    0x07
#define UCSRA_TXC    0x06
#define UCSRA_UDRE   0x05
#define UCSRA_FE     0x04
#define UCSRA_DOR    0x03
#define UCSRA_PE     0x02
#define UCSRA_U2X    0x01
#define UCSRA_MPCM   0x00


#define UCSRB          *((volatile u8*)0x2A)
#define UCSRB_RXCIE    0x07
#define UCSRB_TXCIE    0x06
#define UCSRB_UDRIE    0x05
#define UCSRB_RXEN     0x04
#define UCSRB_TXEN     0x03
#define UCSRB_UCSZ2    0x02
#define UCSRB_RXB8     0x01
#define UCSRB_TXB8     0x00

#define UCSRC          *((volatile u8*)0x40)
#define UCSRC_URSEL     0x07   /*bit to choose the UCSRC_Reg or UBRRH_Reg*/
#define UCSRC_UMSEL     0x06
#define UCSRC_UPM1      0x05
#define UCSRC_UPM0      0x04
#define UCSRC_USBS      0x03
#define UCSRC_UCSZ1     0x02
#define UCSRC_UCSZ0     0x01
#define UCSRC_UCPOL     0x00

#define UBRRL          *((volatile u8*)0x29)
#define UBRRL_UBRR7     0x07
#define UBRRL_UBRR6     0x06
#define UBRRL_UBRR5     0x05
#define UBRRL_UBRR4     0x04
#define UBRRL_UBRR3     0x03
#define UBRRL_UBRR2     0x02
#define UBRRL_UBRR1     0x01
#define UBRRL_UBRR0     0x00


#define UBRRH            *((volatile u8*)0x40)  /*the address is the same UCSRC register*/
#define UBRRL_UBRR8      0x08
#define UBRRL_UBRR9      0x09
#define UBRRL_UBRR10     0x0A
#define UBRRL_UBRR11     0x0B



#endif /* USAR_PRIVATE_H_ */
