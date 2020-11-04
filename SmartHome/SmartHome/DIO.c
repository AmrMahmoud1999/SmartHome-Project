/*
 * DIO.c
 *
 * Created: 9/8/2020 3:57:31 AM
 *  Author: Amr Mahmoud
 */ 

#include "DIO.h"

void DIO_Write(DIO_ChannelTypes ChannelNo,STD_Level Level){
	DIO_PortTypes PORTx = ChannelNo/8;
	uint8 BitNo = ChannelNo%8;
	
	switch (PORTx){
		case DIO_PORTA:
		if (Level == STD_High){
			SetBit(PORTA_reg,BitNo);
		}
		else{
			ClrBit(PORTA_reg,BitNo);
		}
		break;
		
		case DIO_PORTB:
		if (Level == STD_High){
			SetBit(PORTB_reg,BitNo);
		}
		else{
			ClrBit(PORTB_reg,BitNo);
		}
		break;
		
		case DIO_PORTC:
		if (Level == STD_High){
			SetBit(PORTC_reg,BitNo);
		}
		else{
			ClrBit(PORTC_reg,BitNo);
		}
		break;
		
		case DIO_PORTD:
		if (Level == STD_High){
			SetBit(PORTD_reg,BitNo);
		}
		else{
			ClrBit(PORTD_reg,BitNo);
		}
		break;
	}   
	
}

STD_Level DIO_Read(DIO_ChannelTypes ChannelNo){
	DIO_PortTypes PORTx = ChannelNo/8;
	uint8 BitNo = ChannelNo%8;
	
	switch (PORTx){
		case DIO_PORTA:
		return GetBit(PINA_reg,BitNo);
		break;
		
		case DIO_PORTB:
		return GetBit(PINB_reg,BitNo);
		break;
		
		case DIO_PORTC:
		return GetBit(PINC_reg,BitNo);
		break;
		
		case DIO_PORTD:
		return GetBit(PIND_reg,BitNo);
		break;
	}
	return STD_Low;
}

void DIO_PortWrite(DIO_PortTypes PORTx,uint8 data){
	switch(PORTx){
		case DIO_PORTA:
		PORTA_reg = data;
		break;
		
		case DIO_PORTB:
		PORTB_reg = data;
		break;
		
		case DIO_PORTC:
		PORTC_reg = data;
		break;
		
		case DIO_PORTD:
		PORTD_reg = data;
		break;
	}
}

