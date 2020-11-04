/*
 * Timers_Counters.c
 *
 * Created: 9/28/2020 11:49:09 PM
 *  Author: Amr Mahmoud
 */ 

#include "Timers_Counters.h"


void WGM0_Write(DIO_PortTypes mode){
	switch(mode){
		case 0:
		TCCR0_reg=((TCCR0_reg & 0xb7));
		break;
		case 1:
		TCCR0_reg=((TCCR0_reg & 0xb7) | (0x40));
		break;
		case 2:
		TCCR0_reg=((TCCR0_reg & 0xb7) | (0x08));
		break;
		case 3:
		TCCR0_reg=((TCCR0_reg & 0xb7) | (0x48));
		break;
	}
}

void WGM2_Write(DIO_PortTypes mode){
	switch(mode){
		case 0:
		TCCR2_reg=((TCCR2_reg & 0xb7));
		break;
		case 1:
		TCCR2_reg=((TCCR2_reg & 0xb7) | (0x40));
		break;
		case 2:
		TCCR2_reg=((TCCR2_reg & 0xb7) | (0x08));
		break;
		case 3:
		TCCR2_reg=((TCCR2_reg & 0xb7) | (0x48));
		break;
	}
}