/*
 * KeyPad.h
 *
 * Created: 9/13/2020 1:30:55 AM
 *  Author: Amr Mahmoud
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_CFG.h"

#define KeyPad_DDR_Reg DDRD_reg
#define KeyPad_PortReg PORTD_reg

#define C1 DIO_ChannelD0
#define C2 DIO_ChannelD1
#define C3 DIO_ChannelD2
#define C4 DIO_ChannelD3
#define R1 DIO_ChannelD4
#define R2 DIO_ChannelD5
#define R3 DIO_ChannelD6
#define R4 DIO_ChannelD7


void KeyPad_Init(void);
void KeyPad_Check1(char *IP, STD_Level *state);
void KeyPad_Check2(char *IP, STD_Level *state);
void KeyPad_Check3(char *IP, STD_Level *state);
void KeyPad_Check4(char *IP, STD_Level *state);
char KeyPad_Input(void);
 



#endif /* KEYPAD_H_ */