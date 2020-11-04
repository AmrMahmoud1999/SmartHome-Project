/*
 * Timers_Counters.h
 *
 * Created: 9/28/2020 11:48:45 PM
 *  Author: Amr Mahmoud
 */ 


#ifndef TIMERS_COUNTERS_H_
#define TIMERS_COUNTERS_H_

#include "DIO_CFG.h"

#define TCCR0_reg  (*((volatile uint8*)(0x53)))
#define TCNT0_reg  (*((volatile uint8*)(0x52)))
#define OCR0_reg  (*((volatile uint8*)(0x5c)))

#define TCCR1A_reg  (*((volatile uint8*)(0x4f)))
#define TCCR1B_reg  (*((volatile uint8*)(0x4b)))
#define TCNT1H_reg  (*((volatile uint8*)(0x4d)))
#define TCNT1L_reg  (*((volatile uint8*)(0x4c)))
#define OCR1AH_reg  (*((volatile uint8*)(0x4b)))
#define OCR1AL_reg  (*((volatile uint8*)(0x4a)))
#define OCR1BH_reg  (*((volatile uint8*)(0x49)))
#define OCR1BL_reg  (*((volatile uint8*)(0x48)))
#define ICR1H_reg  (*((volatile uint8*)(0x47)))
#define ICR1L_reg  (*((volatile uint8*)(0x46)))

#define TCCR2_reg  (*((volatile uint8*)(0x45)))
#define TCNT2_reg  (*((volatile uint8*)(0x44)))
#define OCR2_reg  (*((volatile uint8*)(0x43)))

#define TIMSK_reg  (*((volatile uint8*)(0x59)))
#define TIFR_reg  (*((volatile uint8*)(0x58)))

// counter/timer #0
#define FOC0_Write(x) TCCR0_reg=((TCCR0_reg & 0x7f) | ((x<<7) & 0x80))
#define COM0_Write(x) TCCR0_reg=((TCCR0_reg & 0xcf) | ((x<<4) & 0x30))
#define CS0_Write(x) TCCR0_reg=((TCCR0_reg & 0xf8) | ((x) & 0x07))
#define TOIE0_Write(x) TIMSK_reg=((TIMSK_reg & 0xfe) | ((x) & 0x01))
#define OCIE0_Write(x) TIMSK_reg=((TIMSK_reg & 0xfD) | ((x<<1) & 0x02))
#define TOV0_Write(x) TIFR_reg=((TIFR_reg & 0xfe) | ((x) & 0x01))
#define OCF0_Write(x) TIFR_reg=((TIFR_reg & 0xfD) | ((x<<1) & 0x02))

// counter/timer #1
#define WGM1_Write(x) TCCR1A_reg=((TCCR1A_reg & 0xfc) | ((x) & 0x03)), TCCR1B_reg=((TCCR1B_reg & 0xfc) | ((x<<1) & 0x18))
#define FOC1A_Write(x) TCCR1A_reg=((TCCR1A_reg & 0xf7) | ((x<<3) & 0x08))
#define FOC1B_Write(x) TCCR1A_reg=((TCCR1A_reg & 0xfb) | ((x<<2) & 0x04))
#define COM1A_Write(x) TCCR1A_reg=((TCCR1A_reg & 0x3f) | ((x<<7) & 0xc0))
#define COM1B_Write(x) TCCR1A_reg=((TCCR1A_reg & 0xcf) | ((x<<4) & 0x30))
#define CS1_Write(x) TCCR1B_reg=((TCCR1B_reg & 0xf8) | ((x) & 0x07))
#define OCR1A_Write(x) OCR1AH_reg= (x>>8)  ,OCR1AL_reg = x
#define OCR1A_Data ((OCR1AH_reg<<8) | OCR1AL_reg)
#define OCR1B_Write(x) OCR1BH_reg= (x>>8)  ,OCR1BL_reg = x
#define OCR1B_Data ((OCR1BH_reg<<8) | OCR1BL_reg)
#define TOIE1_Write(x) TIMSK_reg=((TIMSK_reg & 0xfb) | ((x<<2) & 0x04))
#define OCIE1A_Write(x) TIMSK_reg=((TIMSK_reg & 0xef) | ((x<<4) & 0x10))
#define OCIE1B_Write(x) TIMSK_reg=((TIMSK_reg & 0xf7) | ((x<<3) & 0x08))
#define TOV1_Write(x) TIFR_reg=((TIFR_reg & 0xfb) | ((x<<2) & 0x04))
#define OCF1A_Write(x) TIFR_reg=((TIFR_reg & 0xef) | ((x<<4) & 0x10))
#define OCF1B_Write(x) TIFR_reg=((TIFR_reg & 0xf7) | ((x<<3) & 0x08))

// counter/timer #2
#define FOC2_Write(x) TCCR2_reg=((TCCR2_reg & 0x7f) | ((x<<7) & 0x80))
#define COM2_Write(x) TCCR2_reg=((TCCR2_reg & 0xcf) | ((x<<4) & 0x30))
#define CS2_Write(x) TCCR2_reg=((TCCR2_reg & 0xf8) | ((x) & 0x07))
#define TOIE2_Write(x) TIMSK_reg=((TIMSK_reg & 0xfe) | ((x<<6) & 0x01))
#define OCIE2_Write(x) TIMSK_reg=((TIMSK_reg & 0xfD) | ((x<<7) & 0x02))
#define TOV2_Write(x) TIFR_reg=((TIFR_reg & 0xfe) | ((x<<6) & 0x01))
#define OCF2_Write(x) TIFR_reg=((TIFR_reg & 0xfD) | ((x<<7) & 0x02))








void WGM0_Write(DIO_PortTypes);



#endif /* TIMERS_COUNTERS_H_ */