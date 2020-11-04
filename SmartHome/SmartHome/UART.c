/*
 * UART.c
 *
 * Created: 10/16/2020 2:25:51 AM
 *  Author: Laptop-Academy.com
 */ 

#include "UART.h"
#include <avr/io.h>
void UART_Init(void){
	UCSRB_reg |= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL = MyUBRR;
	UBRRH = MyUBRR>>8;
	
}

void UART_Send(uint8 data){
	while(!GetBit(UCSRA_reg,5));
	UDR_reg = data;
}

uint8 UART_Receive(void){
	while(!GetBit(UCSRA_reg,7));
	return UDR_reg;
}
