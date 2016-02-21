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

#define CPU_CLOCK_HZ             (80000000UL)    // CPU Clock Speed in Hz 
#define CPU_CT_HZ            (CPU_CLOCK_HZ/2)    // CPU CoreTimer   in Hz 
#define PERIPHERAL_CLOCK_HZ      (40000000UL)    // Peripheral Bus  in Hz 
#define US_TO_CT_TICKS  (CPU_CT_HZ/1000000UL)    // uS to CoreTimer Ticks 

void ShortDelay(uint32 DelayCount); // Delay Time (CoreTimer Ticks) [=20ns ]

#define ShortDelay_us( us ) ShortDelay( (us)*US_TO_CT_TICKS )
#define ShortDelay_ms( ms ) ShortDelay( (ms)*US_TO_CT_TICKS*1000 )
//#define ShortDelay_ns( ns ) ShortDelay( (ns)*US_TO_CT_TICKS/1000 )
#define ShortDelay_20ns ShortDelay(1)
#define ShortDelay_80ns ShortDelay(4)
#define ShortDelay_100ns ShortDelay(5)

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

