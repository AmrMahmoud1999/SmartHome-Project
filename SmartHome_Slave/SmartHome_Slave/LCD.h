/*
 * LCD.h
 *
 * Created: 9/11/2020 12:53:20 PM
 *  Author: Amr Mahmoud
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL

#include "DIO_CFG.h"
#include <util/delay.h>

#define LCD_CmdPort PORTB_reg
#define LCD_DataReg PORTA_reg
#define LCD_DataDDR DDRA_reg
#define LCD_DataPort DIO_PORTA

#define LCD_CMD_Reg PORTB_reg
#define LCD_CMD_DDR DDRB_reg
#define LCD_RS DIO_ChannelB0 
#define LCD_RW DIO_ChannelB1
#define LCD_E DIO_ChannelB2


void LCD_Init(void);
void LCD_CMD(uint8 cmd);
void LCD_PrintChar(char data);
void LCD_Print(char *data );
void LCD_SetPos(uint8 line,uint8 pos);
void LCD_Custom_Char (unsigned char loc, unsigned char *msg);
void tostring(char str[], long num);
void LCD_PrintNum(double number);




#endif /* LCD_H_ */