/*
 * USRT_Interface.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Windows 10
 */

#ifndef USRT_INTERFACE_H_
#define USRT_INTERFACE_H_

#define F_CPU 16000000UL			/* Define frequency here its 16MHz */

//#define USART_BAUDRATE 9600
#define BAUD_PRESCALE       (((F_CPU / (baud * 16UL))) - 1)


void USART_INIT(u16 baud);

void USART_Disable(void);

void USART_Transmitter(u8 data);

u8 USART_Receive(void);

void UART_SendString(char *str);


#endif /* USRT_INTERFACE_H_ */
