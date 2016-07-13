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
#ifndef I2C_H
#define	I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "Includes.h"

// Read/nWrite
#define I2C_WRITE 0x00
#define I2C_READ  0x01

// ------------ MSSP1 --------------------
// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait1(void);

// i2c_Start - Start I2C communication
void i2c_Start1(void);

// i2c_Restart - Re-Start I2C communication
void i2c_Restart1(void);

// i2c_Stop - Stop I2C communication
void i2c_Stop1(void);

// i2c_Write - Sends one byte of data
void i2c_Write1(uint8 data);

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address1(uint8 address, uint8 mode);

// i2c_Read - Reads a byte from Slave device
uint8 i2c_Read1(uint8 ack);

uint8 read_i2c_reg_byte1(uint8 addr, uint8 reg, uint8* value);

uint8 write_i2c_reg_byte1(uint8 addr, uint8 reg, uint8 value);

// ------------ MSSP2 -------------------

// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait2(void);

// i2c_Start - Start I2C communication
void i2c_Start2(void);

// i2c_Restart - Re-Start I2C communication
void i2c_Restart2(void);

// i2c_Stop - Stop I2C communication
void i2c_Stop2(void);

// i2c_Write - Sends one byte of data
void i2c_Write2(uint8 data);

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address2(uint8 address, uint8 mode);

// i2c_Read - Reads a byte from Slave device
uint8 i2c_Read2(uint8 ack);

uint8 read_i2c_reg_byte2(uint8 addr, uint8 reg, uint8* value);

uint8 write_i2c_reg_byte2(uint8 addr, uint8 reg, uint8 value);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

