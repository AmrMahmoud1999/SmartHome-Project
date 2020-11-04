/*
* KeyPad.c
*
* Created: 9/13/2020 1:31:10 AM
*  Author: Amr Mahmoud
*/ //oi

#include "KeyPad.h"


void KeyPad_Init(){
	KeyPad_DDR_Reg = 0xf0;
	KeyPad_PortReg = 0xff;
}

void KeyPad_Check1(char *IP, STD_Level *state){
	KeyPad_PortReg = 0b11101111; //R1
	if (DIO_Read(C1) == 0){
		while(DIO_Read(C1) == 0);
		*IP =  '7';
		*state = STD_Low;
	}
	if (DIO_Read(C2) == 0){
		while(DIO_Read(C2) == 0);
		*IP =  '8';
		*state = STD_Low;
	}
	if (DIO_Read(C3) == 0){
		while(DIO_Read(C3) == 0);
		*IP =  '9';
		*state = STD_Low;
	}
	if (DIO_Read(C4) == 0){
		while(DIO_Read(C4) == 0);
		*IP =  '/';
		*state = STD_Low;
	}
}

void KeyPad_Check2(char *IP, STD_Level *state){
	KeyPad_PortReg = 0b11011111; //R2
	if (DIO_Read(C1) == 0){
		while(DIO_Read(C1) == 0);
		*IP =  '4';
		*state = STD_Low;
	}
	if (DIO_Read(C2) == 0){
		while(DIO_Read(C2) == 0);
		*IP =  '5';
		*state = STD_Low;
	}
	if (DIO_Read(C3) == 0){
		while(DIO_Read(C3) == 0);
		*IP =  '6';
		*state = STD_Low;
	}
	if (DIO_Read(C4) == 0){
		while(DIO_Read(C4) == 0);
		*IP =  '*';
		*state = STD_Low;
	}
}

void KeyPad_Check3(char *IP, STD_Level *state){
	KeyPad_PortReg = 0b10111111; //R3
	if (DIO_Read(C1) == 0){
		while(DIO_Read(C1) == 0);
		*IP =  '1';
		*state = STD_Low;
	}
	if (DIO_Read(C2) == 0){
		while(DIO_Read(C2) == 0);
		*IP =  '2';
		*state = STD_Low;
	}
	if (DIO_Read(C3) == 0){
		while(DIO_Read(C3) == 0);
		*IP = '3';
		*state = STD_Low;
	}
	if (DIO_Read(C4) == 0){
		while(DIO_Read(C4) == 0);
		*IP =  '-';
		*state = STD_Low;
	}
}

void KeyPad_Check4(char *IP, STD_Level *state){
	KeyPad_PortReg = 0b01111111; //R4
	if (DIO_Read(C1) == 0){
		while(DIO_Read(C1) == 0);
		*IP =  '!';
		*state = STD_Low;
	}
	if (DIO_Read(C2) == 0){
		while(DIO_Read(C2) == 0);
		*IP =  '0';
		*state = STD_Low;
	}
	if (DIO_Read(C3) == 0){
		while(DIO_Read(C3) == 0);
		*IP =  '=';
		*state = STD_Low;
	}
	if (DIO_Read(C4) == 0){
		while(DIO_Read(C4) == 0);
		*IP =  '+';
		*state = STD_Low;
	}
}

char KeyPad_Input(){
	STD_Level state = STD_High;
	char IP=0;
	while(state){
		 KeyPad_Check1(&IP,&state);
		 KeyPad_Check2(&IP,&state);
		 KeyPad_Check3(&IP,&state);
		 KeyPad_Check4(&IP,&state);
	}
	return IP;
}
