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
extern volatile uint8  checksum;
extern volatile uint8  currentOp;
extern volatile uint8  tempOp;
extern volatile uint8  packetSize;
extern volatile uint8  packetCount;
extern volatile int16  argStart;
extern volatile uint16 tempMag;
extern volatile uint16 temp0;
extern volatile uint16 temp1;
extern volatile uint16 temp2;
extern volatile uint16 temp3;
extern volatile uint16 temp4;
extern volatile uint16 temp5;
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
extern volatile uint8 magAddr;
extern volatile uint8 accAddr;
extern volatile uint8 tempAddr0;
extern volatile uint8 tempAddr1;
extern volatile uint8 tempAddr2;
extern volatile uint8 tempAddr3;
extern volatile uint8 tempAddr4;
extern volatile uint8 tempAddr5;


// non-volatile memory(26 bytes)
extern __eeprom float  sPIDpConst;
extern __eeprom float  sPIDiConst;
extern __eeprom float  sPIDdConst;
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

// FIFO macros
#define NEXT_PTR(c) ((c) == (FIFO_SIZE-1))? 0 : (c) + 1
#define FIFO_EMPTY() (FIFORdPtr == FIFOWrPtr)? 1 : 0
#define FIFO_PTR_DIFF (FIFOWrPtr > FIFORdPtr)? FIFOWrPtr-FIFORdPtr : \
                        ((FIFOWrPtr != 0)? (FIFO_SIZE - FIFORdPtr) + FIFOWrPtr : 0)
#define FIFO_FULL() ((FIFO_PTR_DIFF) == (FIFO_SIZE-1))? 1 : 0

// Timer Macros
// - Delay timer on TMR4
// - Timeout timer on TMR2
#define PAUSE_DELAY_TMR() {T4CONbits.TMR4ON = 0;}
#define PAUSE_TO_TMR()    {T2CONbits.TMR2ON = 0;}
#define PLAY_DELAY_TMR()  {T4CONbits.TMR4ON = 1;}
#define PLAY_TO_TMR()     {T2CONbits.TMR2ON = 1;}
#define RESET_DELAY_TMR() {T4CONbits.TMR4ON = 0; TMR4 = 0;}
#define RESET_TO_TMR()    {T2CONbits.TMR2ON = 0; TMR2 = 0;}
// set the delay timer to the maximum - 16 ms [PR4= 255]
#define SET_DELAY_MAX()   {RESET_DELAY_TMR(); PR4 = 0xFF;}
// set the delay timer to 1ms (1.024ms) [PR4 = 16]
#define SET_DELAY_1MS()   {RESET_DELAY_TMR(); PR4 = 0x10;}

// status register definitions
#define STATUS_TEMP1_STABLE     0x80
#define STATUS_TEMP0_STABLE     0x40
#define STATUS_UART_REQUEST     0x20
#define STATUS_DELAY_COMPLETE   0x10
#define STATUS_PACKET_ERROR     0x08
#define STATUS_TIMEOUT_ERROR    0x04
#define STATUS_TIMEOUT_SET      0x02
#define STATUS_SLEW_SET         0x01

// outflag register definitions
#define STATUS_PASSTHROUGH_SET  0x80
#define STATUS_UART_READ_SET    0x40
#define STATUS_TEMP_SET         0x20
#define OUT_SOLAR_CAL_EN        0x10
#define OUT_CAL_EN              0x08
#define OUT_T1_EN               0x04
#define OUT_T0_EN               0x02

// operation definitions
#define OP_NOP                  0x00
#define OP_RESET_SENSORS        0x01
#define OP_POLL_TEMP_IMMED      0x02
#define OP_POLL_ORIENT_IMMED    0x02
#define OP_REQ_ALL_DATA         0x03
#define OP_SET_CAL              0x04
#define OP_SET_SOL_CAL          0x05
#define OP_SET_SLEW             0x06
#define OP_SET_T0               0x07
#define OP_SET_T1               0x07
#define OP_SET_PID_CONSTS       0x08
#define OP_SET_TEMP_SRC         0x09
#define OP_SET_TEMP_FACTORS     0x0A
#define OP_I2C_PASSSTHROUGH     0x0B
#define OP_GET_RST_REG          0x0C


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* INCLUDES_H */

