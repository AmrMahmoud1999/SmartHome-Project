/*
 * SPI.h
 *
 * Created: 10/20/2020 8:16:17 PM
 *  Author: Laptop-Academy.com
 */ 


#ifndef SPI_H_
#define SPI_H_


#include "DIO.h"

#define SPCR_reg  (*((volatile uint8*)(0x2d)))
#define SPSR_reg  (*((volatile uint8*)(0x2e)))
#define SPDR_reg  (*((volatile uint8*)(0x2f)))

#define SPIPort PORTB_reg
#define SPIDDR DDRB_reg
#define SPIF 7



enum SPI_Pins{SS=4, MOSI, MISO, SCK};
enum SPCR{SPR0=0,SPR1,CPHA,CPOL,MSTR,DORD,SPE,SPIE};
typedef enum{Master=0,Slave}SPI_Mode;	
#define Slave_EN() (SPIPort &=~ (1<<SS))
#define Slave_DIS() (SPIPort |= (1<<SS))

void SPI_Init(SPI_Mode); 
uint8 SPI_TxRx(uint8);

#endif /* SPI_H_ */