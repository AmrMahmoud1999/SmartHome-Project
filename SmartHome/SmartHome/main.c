/*
* SmartHome.c
*
* Created: 10/20/2020 8:03:12 PM
* Author : Amr Mahmoud
*/

#define F_CPU 16000000UL
#include <util/delay.h>
#include "UART.h"
#include "LCD.h"
#include "SPI.h"

int main(void)
{
	LCD_Init();
	UART_Init();
	SPI_Init(Master);
	Slave_EN();
	uint8 fn ;
	uint16 temp=0 ;
	
	while (1)
	{
		fn = UART_Receive();
		// Toggle led
		if(fn == '1'){
			UART_Send('w'); //wait
			if(SPI_TxRx('1') == 0x55){
				UART_Send('D'); //done
			}
		}
		//Read Temperature
		else if(fn == '2' ){
			UART_Send('w');
			uint8 i =0;
			for(i=0;i<=1;i++){
				if(SPI_TxRx('2') == 0x55){
					_delay_ms(150);
					temp = SPI_TxRx('2'); //receive low 8 bits
					_delay_ms(50);
					temp |= (SPI_TxRx('2')<<8); //receive high 8 bits
				}
			}
			LCD_Init();
			LCD_Print("temperature: ");
			LCD_PrintNum(temp/4);
			UART_Send('D');
		}
		//Motor On/Off
		else if(fn == '3'){
			UART_Send('w');
			if(SPI_TxRx('3') == 0x55){
				UART_Send('D');
			}
		}
		// Motor increase duty cycle
		else if(fn == '+'){
			UART_Send('w');
			if(SPI_TxRx('+') == 0x55){
				UART_Send('D');
			}
		}
		// Motor decrease duty cycle
		else if(fn == '-'){
			UART_Send('w');
			if(SPI_TxRx('-') == 0x55){
				UART_Send('D');
			}
		}
	}
}
