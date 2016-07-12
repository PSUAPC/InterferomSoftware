/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INCLUDES_H
#define	INCLUDES_H

#include <xc.h> // include processor files - each processor file is guarded.  

typedef unsigned char           uint8;  // 8 bits
typedef signed char             int8;   // 8 bits
typedef unsigned short          uint16; // 16 bits
typedef signed short            int16;  // 16 bits
typedef unsigned short long     uint24; // 24 bits
typedef signed short long       int24;  // 24 bits
typedef unsigned long           uint32; // 32 bits
typedef unsigned long           int32;  // 32 bits


#define FIFO_SIZE 512

// --------- memory layout ------------
// primary registers (550 Bytes)
extern volatile uint8  FIFOReady;
extern volatile uint16 FIFORdPtr;
extern volatile uint16 FIFOWrPtr;
extern volatile uint16 FIFOTpPtr;
extern volatile uint8  FIFOBuffer[FIFO_SIZE];
extern volatile uint16 tempMag;
extern volatile uint16 temp0;
extern volatile uint16 temp1;
extern volatile uint16 temp2;
extern volatile uint16 temp3;
extern volatile uint16 temp4;
extern volatile uint16 temp4;
extern volatile uint8  peltierTSel;
extern volatile uint8  peltierTgt0;
extern volatile uint8  peltierTgt1;
extern volatile uint16 xMag;
extern volatile uint16 yMag;
extern volatile uint16 zMag;
extern volatile uint16 xAcc;
extern volatile uint16 yAcc;
extern volatile uint16 zAcc;
extern volatile uint8  outFlags;
extern volatile uint8  FEStatus;

// I2C Passthrough (256 Bytes)
extern volatile uint8 numMSGs;
extern volatile uint8 msgBuffer[255];

// PID variables (24 bytes)
extern volatile float prevError0;
extern volatile float prevError1;
extern volatile float accT0;
extern volatile float accT1;
extern volatile uint8 newVal0;
extern volatile uint8 newVal1;
extern volatile float PIDpConst;
extern volatile float PIDiConst;
extern volatile float PIDdConst;

// non-volatile memory(26 bytes)
extern __eeprom float  sPIDpConst;
extern __eeprom float  sPIDiConst;
extern __eeprom float  sPIDdConst;
extern __eeprom uint8  magAddr;
extern __eeprom uint8  accAddr;
extern __eeprom uint8  tempAddr0;
extern __eeprom uint8  tempAddr1;
extern __eeprom uint8  tempAddr2;
extern __eeprom uint8  tempAddr3;
extern __eeprom uint8  tempAddr4;
extern __eeprom uint8  tempAddr5;
extern __eeprom int8   temp0_Off;
extern __eeprom int8   temp1_Off;
extern __eeprom int8   temp2_Off;
extern __eeprom int8   temp3_Off;
extern __eeprom int8   temp4_Off;
extern __eeprom int8   temp5_Off;
extern __eeprom int8   temp0_Scale;
extern __eeprom int8   temp1_Scale;
extern __eeprom int8   temp2_Scale;
extern __eeprom int8   temp3_Scale;
extern __eeprom int8   temp4_Scale;
extern __eeprom int8   temp5_Scale;

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* INCLUDES_H */

