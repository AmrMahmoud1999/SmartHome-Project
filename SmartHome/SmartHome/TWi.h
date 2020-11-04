/*
 * TWi.h
 *
 * Created: 10/13/2020 2:09:32 AM
 *  Author: Amr Mahmoud
 */ 


#ifndef TWI_H_
#define TWI_H_

#define F_CPU 16000000UL
#define SCL_freq 400000UL
#define MyTWPS 1

#include <util/delay.h>
#include "DIO_CFG.h"

#define TWBR_reg  (*((volatile uint8*)(0x20)))
#define TWCR_reg  (*((volatile uint8*)(0x56)))
#define TWAR_reg  (*((volatile uint8*)(0x22)))
#define TWSR_reg  (*((volatile uint8*)(0x21)))
#define TWDR_reg  (*((volatile uint8*)(0x23)))

#define TWINT_Write(x) TWCR_reg=((TWCR_reg & 0x7f) | ((x<<7) & 0x80))
#define TWEA_Write(x) TWCR_reg=((TWCR_reg & 0xbf) | ((x<<6) & 0x40))
#define TWSTA_Write(x) TWCR_reg=((TWCR_reg & 0xdf) | ((x<<5) & 0x20))
#define TWSTO_Write(x) TWCR_reg=((TWCR_reg & 0xef) | ((x<<4) & 0x10))
#define TWWC_Write(x) TWCR_reg=((TWCR_reg & 0xf7) | ((x<<3) & 0x08))
#define TWEN_Write(x) TWCR_reg=((TWCR_reg & 0xfb) | ((x<<2) & 0x04))
#define TWIE_Write(x) TWCR_reg=((TWCR_reg & 0xfe) | ((x) & 0x01))

#define TWINT_Read GetBit(TWCR_reg,7)

#define TWI_Status (TWSR_reg & 0xf8)
#define TWPS_Write(x) TWSR_reg=((TWSR_reg & 0xfc) | ((x) & 0x03))


void TWI_Init(uint8);
uint8 TWI_Start(void);
void TWI_Stop(void);
uint8 TWI_Data(uint8);
uint8 TWI_ReadData(uint8 *);


#endif /* TWI_H_ */