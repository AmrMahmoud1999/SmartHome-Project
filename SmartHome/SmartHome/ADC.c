/*
 * ADC.c
 *
 * Created: 9/24/2020 9:01:13 PM
 *  Author: Amr Mahmoud
 */ 

#include "ADC.h"
#include "LCD.h"

void ADC_Init(){
	REFS_Write(0b11);
	ADPS_Write(0b111);
	ADEN_Write(1);
}

uint16 ADC_ReadData(uint8 channel){
	uint16 data=0;
	MUX_Write(channel);
	ADSC_Write(1);
	while(ADIF_Read);
	ADIF_Write(1);
	data = ADCL_reg;
	data |= (ADCH_reg<<8);
	return data;
}

