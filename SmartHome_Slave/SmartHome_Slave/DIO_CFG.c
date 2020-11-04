/*
* DIO_CFG.c
*
* Created: 9/8/2020 4:36:38 AM
*  Author: Amr Mahmoud
*/

#include "DIO_CFG.h"

const PIN_CFG ChannelsInit[] = {
	//portA
	{Output,STD_Low},
	{Input,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
				
	//portB		
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
				
	//portC		
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
				
	//portD		
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low},
	{Output,STD_Low}
};


void DIO_Init(){
	DIO_PortTypes PORTx;
	uint8 BitNo, count;
	
	//DDR_reg initialization
	for(count=DIO_ChannelA0; count<PIN_Num;count++){
		PORTx=count/8;
		BitNo=count%8;
		
		switch (PORTx){
			case DIO_PORTA:
			if (ChannelsInit[count].ChannelDir == Output){
				SetBit(DDRA_reg,BitNo);
			}
			else{
				ClrBit(DDRA_reg,BitNo);
			}
			break;
			
			case DIO_PORTB:
			if (ChannelsInit[count].ChannelDir == Output){
				SetBit(DDRB_reg,BitNo);
			}
			else{
				ClrBit(DDRB_reg,BitNo);
			}
			break;
			
			case DIO_PORTC:
			if (ChannelsInit[count].ChannelDir == Output){
				SetBit(DDRC_reg,BitNo);
			}
			else{
				ClrBit(DDRC_reg,BitNo);
			}
			break;
			
			case DIO_PORTD:
			if (ChannelsInit[count].ChannelDir == Output){
				SetBit(DDRD_reg,BitNo);
			}
			else{
				ClrBit(DDRD_reg,BitNo);
			}
			break;
		}
		
	} 
	
	//PORT_reg initialization
	for(count=DIO_ChannelA0; count<PIN_Num;count++){
		PORTx=count/8;
		BitNo=count%8;
		
		switch (PORTx){
			case DIO_PORTA:
			if (ChannelsInit[count].ChannelLevel == STD_High){
				SetBit(PORTA_reg,BitNo);
			}
			else{
				ClrBit(PORTA_reg,BitNo);
			}
			break;
			
			case DIO_PORTB:
			if (ChannelsInit[count].ChannelLevel == STD_High){
				SetBit(PORTB_reg,BitNo);
			}
			else{
				ClrBit(PORTB_reg,BitNo);
			}
			break;
			
			case DIO_PORTC:
			if (ChannelsInit[count].ChannelLevel == STD_High){
				SetBit(PORTC_reg,BitNo);
			}
			else{
				ClrBit(PORTC_reg,BitNo);
			}
			break;
			
			case DIO_PORTD:
			if (ChannelsInit[count].ChannelLevel == STD_High){
				SetBit(PORTD_reg,BitNo);
			}
			else{
				ClrBit(PORTD_reg,BitNo);
			}
			break;
		}
		
	}
	
	
}