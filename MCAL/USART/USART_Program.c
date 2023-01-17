/*
 * USART_Program.c
 *
 *  Created on: Nov 15, 2022
 *      Author: Windows 10
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "USRT_Interface.h"
#include "USAR_Private.h"

void USART_INIT(u16 baud)
{
	/*Atomic access (must to set or reset the bits then = to register)*/
	u8 local_UCSRC ;

	/* Set baud rate */
	UBRRH = (u8)(BAUD_PRESCALE>>8);
	UBRRL = (u8)BAUD_PRESCALE;

	/* Enable receiver and transmitter */
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	//UCSRB = (1<<UCSRB_RXEN)|(1<<UCSRB_TXEN);

	/* Set frame format: 8data, 2stop bit */
	SET_BIT(local_UCSRC,UCSRC_URSEL);   //to choice UCSRC register not UBRRH Register
	SET_BIT(local_UCSRC,UCSRC_UCSZ1);
	SET_BIT(local_UCSRC,UCSRC_UCSZ0);
	/*atomic access(bytes access) should access the whole register not by bit*/
	UCSRC = local_UCSRC;

}

void USART_Disable(void)
{
	/* Disable receiver and transmitter */
	CLR_BIT(UCSRB,UCSRB_RXEN);
	CLR_BIT(UCSRB,UCSRB_TXEN);
}

void USART_Transmitter(u8 data)
{
	/* Wait for empty transmit buffer */
	//pollig on UCSRA_UDRE pin to be sure it is empty
	//while ( !( UCSRA & (1<<UCSRA_UDRE)) );
	while (GET_BIT(UCSRA,UCSRA_UDRE) == 0);

	/* Put data into buffer, sends the data */
	UDR = data;          //TX to write data

}

u8 USART_Receive( void )
{
/* Wait for data to be received */
	//while ( ! (UCSRA & (1<<UCSRA_RXC)) );
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);

/* Get and return received data from buffer */
	return UDR;
}

void UART_SendString(char *str)
{
	u8 j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		USART_Transmitter(str[j]);
		j++;
	}
}
