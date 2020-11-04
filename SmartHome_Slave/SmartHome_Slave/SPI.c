/*
* SPI.c
*
* Created: 10/20/2020 8:16:31 PM
*  Author: Laptop-Academy.com
*/

#include "SPI.h"

void SPI_Init(SPI_Mode mode){
	switch(mode){
		case Master:
		SPIDDR |= (1<<SS)|(1<<SCK)|(1<<MOSI);
		SPIDDR &=~ (1<<MISO);
		SPCR_reg |= (1<<MSTR)|(1<<SPE);
		Slave_DIS();
		break;
		case Slave:
		SPIDDR &=~ (1<<SS)|(1<<SCK)|(1<<MOSI);
		SPIDDR |= (1<<MISO);
		SPCR_reg |= (1<<SPE);
		break;
	}
}


uint8 SPI_TxRx(uint8 data){
	SPDR_reg = data;
	while(!GetBit(SPSR_reg,SPIF));
	return SPDR_reg;
}