/*
 * BitMaths.h
 *
 * Created: 9/4/2020 9:50:10 AM
 *  Author: Amr Mahmoud
 */ 


#ifndef BITMATHS_H_
#define BITMATHS_H_

#define SetBit(REG,BIT) REG|=(1<<BIT)
#define GetBit(REG,BIT) ((REG>>BIT) & 1)
#define ClrBit(REG,BIT) REG&=~(1<<BIT)
#define ToggleBit(REG,BIT) REG^=(1<<BIT)



#endif /* BITMATHS_H_ */