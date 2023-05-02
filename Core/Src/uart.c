/*
 * UART.c
 *
 *  Created on: 1 íîÿá. 2018 ã.
 *      Author: VasinS
 */

#include "uart.h"
#include "stm32f1xx_hal.h"

char InCbMemory[SizeInCb];
CircularBuffer InCb;

char OutCbMemory[SizeOutCb];
CircularBuffer OutCb;

void UART_WriteByte(char b)
{
	CBuff_AddChar(&OutCb, b);
}

void UART_WriteString(char* SendBuf, int len)
{
	for(int i=0; i<len; i++)
	{
		UART_WriteByte(SendBuf[i]);
	}
}

void UART_StartTransmit() // MP3 player
{
	if(!CBuff_IsEmpty(&OutCb))
	{
		USART1->DR = CBuff_GetChar(&OutCb);
		HAL_Delay(200);
	}
}

void UART_Recive()
{
	if(USART1->SR & USART_SR_RXNE)
	{
		CBuff_AddChar(&InCb, USART1->DR);
	}
}

void UART_Transmit()
{
	if((USART1->SR & USART_SR_TC)!=0)
	{
	    USART1->SR &= ~USART_SR_TC;

		if(!CBuff_IsEmpty(&OutCb))
		{
			USART1->DR = CBuff_GetChar(&OutCb);
		}
	}
}

void UART_Init()
{
	USART1->CR1 |= USART_CR1_TCIE;
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART1->CR3 |= USART_CR3_EIE;

    CBuff_Init(&InCb,  (char*)InCbMemory,  SizeInCb);
	CBuff_Init(&OutCb, (char*)OutCbMemory, SizeOutCb);
}
