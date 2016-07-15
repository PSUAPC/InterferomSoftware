/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#include "Includes.h"

// --------- memory layout ------------
// primary registers (550 Bytes)
volatile uint8  FIFOReady;
volatile uint16 FIFORdPtr;
volatile uint16 FIFOWrPtr;
volatile uint16 FIFOTpPtr;
volatile uint8  FIFOBuffer[FIFO_SIZE];
volatile uint8  checksum;
volatile uint8  currentOp;
volatile uint8  tempOp;
volatile uint8  packetSize;
volatile uint8  packetCount;
volatile int16  argStart;
volatile uint16 tempMag;
volatile uint16 temp0;
volatile uint16 temp1;
volatile uint16 temp2;
volatile uint16 temp3;
volatile uint16 temp4;
volatile uint16 temp5;
volatile uint8  peltierTSel;
volatile uint8  peltierTgt0;
volatile uint8  peltierTgt1;
volatile uint16 xMag;
volatile uint16 yMag;
volatile uint16 zMag;
volatile uint16 xAcc;
volatile uint16 yAcc;
volatile uint16 zAcc;
volatile uint8  outFlags;
volatile uint8  FEStatus;

// I2C Passthrough (256 Bytes)
volatile uint8 numMSGs;
volatile uint8 msgBuffer[255];

// PID variables (24 bytes)
volatile float prevError0;
volatile float prevError1;
volatile float accT0;
volatile float accT1;
volatile uint8 newVal0;
volatile uint8 newVal1;
volatile float PIDpConst;
volatile float PIDiConst;
volatile float PIDdConst;
volatile uint8 magAddr;
volatile uint8 accAddr;
volatile uint8 tempAddr0;
volatile uint8 tempAddr1;
volatile uint8 tempAddr2;
volatile uint8 tempAddr3;
volatile uint8 tempAddr4;
volatile uint8 tempAddr5;


// non-volatile memory(26 bytes)
__eeprom float  sPIDpConst = 1.0;
__eeprom float  sPIDiConst = 1.0;
__eeprom float  sPIDdConst = 1.0;
__eeprom int8   temp0_Off = 0;
__eeprom int8   temp1_Off = 0;
__eeprom int8   temp2_Off = 0;
__eeprom int8   temp3_Off = 0;
__eeprom int8   temp4_Off = 0;
__eeprom int8   temp5_Off = 0;
__eeprom int8   temp0_Scale = 1;
__eeprom int8   temp1_Scale = 1;
__eeprom int8   temp2_Scale = 1;
__eeprom int8   temp3_Scale = 1;
__eeprom int8   temp4_Scale = 1;
__eeprom int8   temp5_Scale = 1;


// Communication Utility Functions




/* *****************************************************************************
 End of File
 */

