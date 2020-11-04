/*
 * LCD.c
 *
 * Created: 9/11/2020 12:53:35 PM
 *  Author: Amr Mahmoud
 */ 

#include "LCD.h"

void LCD_Init(void){
	LCD_DataDDR |= 0xf0;   // DDR initialization
	SetBit(LCD_CMD_DDR,1); // DDR initialization
	SetBit(LCD_CMD_DDR,2); // DDR initialization
	SetBit(LCD_CMD_DDR,3); // DDR initialization

	_delay_ms(20);
	DIO_Write(LCD_RW,STD_Low);
	LCD_CMD(0x33);
	LCD_CMD(0x32); // 4-bit mode
	LCD_CMD(0x28); //set function
	LCD_CMD(0x06); //entry mode
	LCD_CMD(0x0f); //Display on
	LCD_CMD(0x01); //Clear LCD
}

void LCD_CMD(uint8 cmd){
	DIO_Write(LCD_RS,STD_Low);
	// sending High Nipple
	DIO_PortWrite(LCD_DataPort,((LCD_DataReg & 0x0f) | (cmd & 0xf0))); 
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(5);
	// sending Low Nipple
	DIO_PortWrite(LCD_DataPort,((LCD_DataReg & 0x0f) | (cmd<<4)));	
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
}

void LCD_PrintChar(char data){
	DIO_Write(LCD_RS,STD_High);
	// sending High Nipple
	DIO_PortWrite(LCD_DataPort,((LCD_DataReg & 0x0f) | (data & 0xf0)));
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(5);
	// sending Low Nipple
	DIO_PortWrite(LCD_DataPort,((LCD_DataReg & 0x0f) | (data<<4)));
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
}

void LCD_Print(char *data ){
	uint8 count = 0;
	while(data[count] != '\0'){
		LCD_PrintChar(data[count]);
		count++;
		if(count==16){
			LCD_SetPos(2,0);
		}
		else if(count==32){
			return;
		}
	}
}

void LCD_SetPos(uint8 line,uint8 pos){
	switch(line){
		case 1:
		LCD_CMD(0x80 | (pos & 0x0F));
		break;
		
		case 2:
		LCD_CMD(0xC0 | (pos & 0x0F));
		break;
	}
}

void LCD_Custom_Char (unsigned char loc, unsigned char *msg){
    unsigned char i;
    if(loc<8){
     LCD_CMD (0x40 + (loc*8));  /* Command 0x40 and onwards forces 
                                       the device to point CGRAM address */
       for(i=0;i<8;i++){  /* Write 8 byte for generation of 1 character */
           LCD_PrintChar(msg[i]);
	   }
	}
	LCD_Init();   
}

void tostring(char str[], long num)
{
	long i, rem, len = 0, n;
	n = num;
	
	do{
		len++;
		n /= 10;
	}while (n != 0);
	
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}


void LCD_PrintNum(double number){
	uint8 s=0;
	float f;
	if(number<0){
		s = 1;
		number *= -1;
	}
	f = (number - (long)number)*1000;
	char Snumber[12], Fnumber[5];
	tostring(Fnumber, f);
	tostring(Snumber,number);
	if (s==1){
		LCD_PrintChar('-');
	}
	LCD_Print(Snumber);
	if (f != 0)
	{
		LCD_PrintChar('.');
		LCD_Print(Fnumber);
	}
}