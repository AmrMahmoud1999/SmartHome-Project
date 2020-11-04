/*
* UART.c
*
* Created: 10/9/2020 2:19:17 AM
* Author : Amr Mahmoud
*/

#define SetOCR0(d) (OCR0_reg = ( ((256*d)/100))-1 )
#define F_CPU 16000000UL
#include <util/delay.h>
#include "SPI.h"
#include "DIO_CFG.h"
#include "LCD.h"
#include "ADC.h"
#include "Timers_Counters.h"

int main(void)
{
	DIO_Init();
	SetBit(DDRC_reg,7);
	//timer cfg
	WGM0_Write(3);
	COM0_Write(0b00);
	CS0_Write(0b011);
	SetOCR0(50);
	//
	SPI_Init(Slave);
	ADC_Init();
	LCD_Init();
	uint16 temp=100;
	uint8 fn,duty=50 ;
	while (1)
	{
		fn = SPI_TxRx(0x55);
		//Toggle Led
		if(fn == '1')	{
			ToggleBit(PORTC_reg,7);
		}
		//Read Temperature
		else if(fn == '2'){
			temp = ADC_ReadData(1);
			SPI_TxRx(temp);//send low 8 bits
			SPI_TxRx(temp>>8);//send high 8 bits
		}
		//Motor On/Off
		else if(fn == '3')	{
			ToggleBit(TCCR0_reg,5);
			if(GetBit(TCCR0_reg,5)){
				LCD_Init();
				LCD_Print("motor power: ");
				LCD_PrintNum(duty);
			}
			else{
				LCD_Init();
				LCD_Print("motor is off!");
			}
		}
		// Motor increase duty cycle
		else if(fn == '+')	{
			if(GetBit(TCCR0_reg,5)){
				if(duty < 100){
					duty += 25;
					SetOCR0(duty);
					LCD_Init();
					LCD_Print("motor power: ");
					LCD_PrintNum(duty);
				}
				else{
					LCD_Init();
					LCD_Print("motor is 100% !");
				}
			}
			else{
				LCD_Init();
				LCD_Print("motor is off !");
			}
		}
		// Motor decrease duty cycle
		else if(fn == '-')	{
			if(GetBit(TCCR0_reg,5)){
				if(duty > 0){
					duty -= 25;
					SetOCR0(duty);
					LCD_Init();
					LCD_Print("motor power: ");
					LCD_PrintNum(duty);
				}
				else{
					LCD_Init();
					LCD_Print("motor is 0% !");
				}
			}
			else{
				LCD_Init();
				LCD_Print("motor is off !");
			}
		}
		
	}
}