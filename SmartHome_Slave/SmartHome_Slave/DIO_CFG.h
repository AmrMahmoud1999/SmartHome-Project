/*
 * DIO_CFG.h
 *
 * Created: 9/8/2020 4:36:16 AM
 *  Author: Amr Mahmoud
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct{
	DIO_Dir ChannelDir;
	STD_Level ChannelLevel;
	}PIN_CFG;

#define PIN_Num 32


void DIO_Init(void);



#endif /* DIO_CFG_H_ */