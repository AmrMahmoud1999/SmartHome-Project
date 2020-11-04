/*
 * ADC.h
 *
 $07 ($ 27 ) ADMUX REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0 214
 $06 ($ 26 ) ADCSRA ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0 216
 $05 ($ 25 ) ADCH ADC Data Register High Byte 217
 $04 ($ 24 ) ADCL
 
 * Created: 9/24/2020 9:01:02 PM
 *  Author: Amr Mahmoud
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "DIO_CFG.h"

#define ADMUX_reg  (*((volatile uint8*)(0x27)))
#define ADCSRA_reg  (*((volatile uint8*)(0x26)))
#define ADCH_reg  (*((volatile uint8*)(0x25)))
#define ADCL_reg  (*((volatile uint8*)(0x24)))

#define REFS_Write(x) ADMUX_reg=((ADMUX_reg & 0x3f) | ((x<<6) & 0xc0))
#define MUX_Write(x) ADMUX_reg=((ADMUX_reg & 0xe0) | (x & 0x1f))
#define ADPS_Write(x) ADCSRA_reg=((ADCSRA_reg & 0xf8) | (x & 0x07))
#define ADEN_Write(x) ADCSRA_reg=((ADCSRA_reg & 0x7F) | ((x<<7) & 0x80))
#define ADSC_Write(x) ADCSRA_reg=((ADCSRA_reg & 0xbf) | ((x<<6) & 0x40))
#define ADATE_Write(x) ADCSRA_reg=((ADCSRA_reg & 0xdf) | ((x<<5) & 0x20))
#define ADIF_Write(x) ADCSRA_reg=((ADCSRA_reg & 0xef) | ((x<<4) & 0x10))
#define ADIE_Write(x) ADCSRA_reg=((ADCSRA_reg & 0xf7) | ((x<<3) & 0x08))

#define ADIF_Read GetBit(ADCSRA_reg,4)

#define ADC_Data ((ADCH_reg<<8) | ADCL_reg)

void ADC_Init(void);
uint16 ADC_ReadData(uint8 channel);






#endif /* ADC_H_ */