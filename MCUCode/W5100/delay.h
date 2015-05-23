//  File:   delay.h
//  Author: Yuri Panchul

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "Types.h"

void delay_for_1000_nops_x (uint n);
void delay_for_1000_nops   ();
void delay_micros          (uint n);
void delay_millis          (uint n);
void delay_seconds         (uint n);




#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

