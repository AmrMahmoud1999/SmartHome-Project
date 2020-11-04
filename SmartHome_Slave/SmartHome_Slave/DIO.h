/*
 * DIO.h
 *
 * Created: 9/8/2020 3:57:19 AM
 *  Author: Amr Mahmoud
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMaths.h"
#include "STD_Types.h"
#include "DIO_Types.h"
#include "DIO_HW.h"

void DIO_Write(DIO_ChannelTypes ChannelNo,STD_Level Level);
STD_Level DIO_Read(DIO_ChannelTypes ChannelNo);
void DIO_PortWrite(DIO_PortTypes PORTx,uint8 data);




#endif /* DIO_H_ */