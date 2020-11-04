/*
 * TWi.c
 *
 * Created: 10/13/2020 2:09:50 AM
 *  Author: Amr Mahmoud
 */ 

#include "TWI.h"

void TWI_Init(uint8 address_TWGCE){
	if (MyTWPS == 1){
		TWPS_Write(0b00);
	}
	else if (MyTWPS == 4){
		TWPS_Write(0b01);
	}
	else if (MyTWPS == 16){
		TWPS_Write(0b10);
	}
	else if (MyTWPS == 64){
		TWPS_Write(0b11);
	}
	
	TWBR_reg = ((F_CPU/SCL_freq)-16)/(2*(4^MyTWPS));
	TWAR_reg = address_TWGCE;
	TWINT_Write(1);
	TWEN_Write(1);
}

uint8 TWI_Start(void){
	TWINT_Write(1);
	TWSTA_Write(1);
	TWEN_Write(1);
	while(!(TWINT_Read));
	return TWI_Status;
}

void TWI_Stop(void){
	TWINT_Write(1);
	TWSTO_Write(1);
	TWEN_Write(1);
}

uint8 TWI_Data(uint8 data){
	TWDR_reg = data;
	TWINT_Write(1);
	TWEN_Write(1);
	while(!(TWINT_Read));
	return TWI_Status;
}

uint8 TWI_ReadData( uint8 * data){
	TWINT_Write(1);
	TWEA_Write(1);
	TWEN_Write(1);
	while(!(TWINT_Read));
	* data = TWDR_reg;
	return TWI_Status;
	}
	
	
