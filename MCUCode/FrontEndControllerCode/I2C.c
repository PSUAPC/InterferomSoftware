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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "I2C.h"
/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */

// ------------------- MSSP1 -----------------------------------

// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait1(void)
{
    while ( ( SSP1CON2 & 0x1F ) || ( SSP1STAT & 0x04 ) );
}

// i2c_Start - Start I2C communication
void i2c_Start1(void)
{
    i2c_Wait1();
    SSP1CON2bits.SEN=1;
}

// i2c_Restart - Re-Start I2C communication
void i2c_Restart1(void)
{
    i2c_Wait1();
    SSP1CON2bits.RSEN=1;
}

// i2c_Stop - Stop I2C communication
void i2c_Stop1(void)
{
    i2c_Wait1();
    SSP1CON2bits.PEN=1;
}

// i2c_Write - Sends one byte of data
void i2c_Write1(uint8 data)
{
    i2c_Wait1();
    SSP1BUF = data;
}

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address1(uint8 address, uint8 mode)
{
    uint8 l_address;

    l_address=address<<1;
    l_address+=mode;
    i2c_Wait1();
    SSP1BUF = l_address;
}

// i2c_Read - Reads a byte from Slave device
uint8 i2c_Read1(uint8 ack)
{
    // Read data from slave
    // ack should be 1 if there is going to be more data read
    // ack should be 0 if this is the last byte of data read
    uint8 i2cReadData;

    i2c_Wait1();
    SSP1CON2bits.RCEN=1;
    i2c_Wait1();
    i2cReadData = SSP1BUF;
    i2c_Wait1();
    if ( ack ) 
        SSP1CON2bits.ACKDT=0;	        // Ack
    else       
        SSP1CON2bits.ACKDT=1;	        // NAck
    
    SSP1CON2bits.ACKEN=1;                    // send acknowledge sequence

    return( i2cReadData );
}


uint8 read_i2c_reg_byte1(uint8 addr, uint8 reg, uint8* value)
{
    i2c_Start1();                     // send Start
    i2c_Address1(addr, I2C_WRITE);    // Send slave address - write operation
    i2c_Write1(reg);	              // Set register
    i2c_Restart1();                   // Restart
    i2c_Address1(addr, I2C_READ);     // Send slave address - read operation	
    *value = i2c_Read1(0);            // Read one byte
                          // If more than one byte to be read, (0) should
                          // be on last byte only
                          // e.g.3 bytes= i2c_Read(1); i2c_Read(1); i2c_Read(0);
    i2c_Stop1();                      // send Stop
    
    return 1;
}

uint8 write_i2c_reg_byte1(uint8 addr, uint8 reg, uint8 value)
{
    i2c_Start1();                       // send Start
    i2c_Address1(addr, I2C_WRITE);      // Send slave address - write operation
    i2c_Write1(reg);	                // the register address
    i2c_Write1(value);	                // the value
    i2c_Stop1();	                    // send Stop
    
    return 1;
}

// ------------------- MSSP2 -----------------------------------


// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait2(void)
{
    while ( ( SSP2CON2 & 0x1F ) || ( SSP2STAT & 0x04 ) );
}

// i2c_Start - Start I2C communication
void i2c_Start2(void)
{
    i2c_Wait2();
    SSP2CON2bits.SEN=1;
}

// i2c_Restart - Re-Start I2C communication
void i2c_Restart2(void)
{
    i2c_Wait2();
    SSP2CON2bits.RSEN=1;
}

// i2c_Stop - Stop I2C communication
void i2c_Stop2(void)
{
    i2c_Wait2();
    SSP2CON2bits.PEN=1;
}

// i2c_Write - Sends one byte of data
void i2c_Write2(uint8 data)
{
    i2c_Wait2();
    SSP2BUF = data;
}

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address2(uint8 address, uint8 mode)
{
    uint8 l_address;

    l_address=address<<1;
    l_address+=mode;
    i2c_Wait2();
    SSP2BUF = l_address;
}

// i2c_Read - Reads a byte from Slave device
uint8 i2c_Read2(uint8 ack)
{
    // Read data from slave
    // ack should be 1 if there is going to be more data read
    // ack should be 0 if this is the last byte of data read
    uint8 i2cReadData;

    i2c_Wait2();
    SSP2CON2bits.RCEN=1;
    i2c_Wait2();
    i2cReadData = SSP2BUF;
    i2c_Wait2();
    if ( ack ) 
        SSP2CON2bits.ACKDT=0;	        // Ack
    else       
        SSP2CON2bits.ACKDT=1;	        // NAck
    
    SSP2CON2bits.ACKEN=1;                    // send acknowledge sequence

    return( i2cReadData );
}


uint8 read_i2c_reg_byte2(uint8 addr, uint8 reg, uint8* value)
{
    i2c_Start2();                     // send Start
    i2c_Address2(addr, I2C_WRITE);    // Send slave address - write operation
    i2c_Write2(reg);	              // Set register
    i2c_Restart2();                   // Restart
    i2c_Address2(addr, I2C_READ);     // Send slave address - read operation	
    *value = i2c_Read2(0);            // Read one byte
                          // If more than one byte to be read, (0) should
                          // be on last byte only
                          // e.g.3 bytes= i2c_Read(1); i2c_Read(1); i2c_Read(0);
    i2c_Stop2();                      // send Stop
    
    return 1;
}

uint8 write_i2c_reg_byte2(uint8 addr, uint8 reg, uint8 value)
{
    i2c_Start2();                       // send Start
    i2c_Address2(addr, I2C_WRITE);      // Send slave address - write operation
    i2c_Write2(reg);	                // the register address
    i2c_Write2(value);	                // the value
    i2c_Stop2();	                    // send Stop
    
    return 1;
}

/* *****************************************************************************
 End of File
 */

