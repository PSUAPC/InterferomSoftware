/* 
 * File:   main.c
 * Author: Owner
 *
 * Created on December 9, 2014, 3:33 PM
 */
typedef unsigned char byte;

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f1503.h>


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = ON       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF    // Clock Out Enable (CLKOUT function is enabled on the CLKOUT pin)


// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// Definitions
#define _XTAL_FREQ  16000000        // this is used by the __delay_ms(xx) and __delay_us(xx) functions
#define device_control_code  0b1010 // All I2C devices have a control code assigned to them.
                                    // and the control code for a serial eeprom is b'1010'


// ----------------- SOME GLOBALS ---------------------------------
volatile byte m_status = 0;
volatile byte m_DevSCL = 0;

#define SDADIR PORTCbits.RC1
#define SCLDIR PORTCbits.RC0


//**************************************************************************************
// Send one byte to SEE
//**************************************************************************************
void Send_I2C_Data(unsigned int databyte)
{
    PIR1bits.SSP1IF=0;          // clear SSP interrupt bit
    SSPBUF = databyte;              // send databyte
    while(!PIR1bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}


//**************************************************************************************
// Read one byte from SEE
//**************************************************************************************
unsigned int Read_I2C_Data(void)
{
    PIR1bits.SSP1IF=0;          // clear SSP interrupt bit
    SSPCON2bits.RCEN=1;         // set the receive enable bit to initiate a read of 8 bits from the serial eeprom
    while(!PIR1bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
    return (SSPBUF);            // Data from eeprom is now in the SSPBUF so return that value
}

//**************************************************************************************
// Send control byte to SEE (this includes 4 bits of device code, block select bits and the R/W bit)
//**************************************************************************************
// Notes:
// 1) The device code for serial eeproms is defined as '1010' which we are using in this example
// 2) RW_bit can only be a one or zero
// 3) Block address is only used for SEE devices larger than 4K, however on
// some other devices these bits may become the hardware address bits that allow you
// to put multiple devices of the same type on the same bus.  Read the datasheet
// on your particular serial eeprom device to be sure.
//**************************************************************************************
void Send_I2C_ControlByte(unsigned int BlockAddress,unsigned int RW_bit)
{
    PIR1bits.SSP1IF=0;          // clear SSP interrupt bit

    // Assemble the control byte from device code, block address bits and R/W bit
    // so it looks like this: CCCCBBBR
    // where 'CCCC' is the device control code
    // 'BBB' is the block address
    // and 'R' is the Read/Write bit

    SSPBUF = ((device_control_code << 4) | (BlockAddress <<1)) + RW_bit;  // send the control byte
    while(!PIR1bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}

//**************************************************************************************
// Send start bit to SEE
//**************************************************************************************
void Send_I2C_StartBit(void)
{
    PIR1bits.SSP1IF=0;          // clear SSP interrupt bit
    SSPCON2bits.SEN=1;          // send start bit
    while(!PIR1bits.SSP1IF);    // Wait for the SSPIF bit to go back high before we load the data buffer
}

//**************************************************************************************
// Send stop bit to SEE
//**************************************************************************************
void Send_I2C_StopBit(void)
{
    PIR1bits.SSP1IF=0;          // clear SSP interrupt bit
    SSPCON2bits.PEN=1;          // send stop bit
    while(!PIR1bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}


//**************************************************************************************
// Send ACK bit to SEE
//**************************************************************************************
void Send_I2C_ACK(void)
{
   PIR1bits.SSP1IF=0;          // clear SSP interrupt bit
   SSPCON2bits.ACKDT=0;        // clear the Acknowledge Data Bit - this means we are sending an Acknowledge or 'ACK'
   SSPCON2bits.ACKEN=1;        // set the ACK enable bit to initiate transmission of the ACK bit to the serial eeprom
   while(!PIR1bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}

//**************************************************************************************
// Send NAK bit to SEE
//**************************************************************************************
void Send_I2C_NAK(void)
{
    PIR1bits.SSP1IF=0;           // clear SSP interrupt bit
    SSPCON2bits.ACKDT=1;        // set the Acknowledge Data Bit- this means we are sending a No-Ack or 'NAK'
    SSPCON2bits.ACKEN=1;        // set the ACK enable bit to initiate transmission of the ACK bit to the serial eeprom
    while(!PIR1bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}

//*************************************************************************************
//***********************      main rouitine     **************************************
//*************************************************************************************

// command map
// 0x01 - Get status
// 0x02 - power on
// 0x03 - power off
// 0x04 - reset

// status map
// 0x00 - Unknown status / Standby
// 0x01 - Not Connected
// 0x02 - Power Up Successful
// 0x03 - Power Up Failure
// 0x04 - Power Down Successful
// 0x05 - Power Down Failure


// Port Map
// PORTC0 - SCL
// PORTC1 - SDA
// PORTC2 - I2C Serial Address Input
// PORTC3 - Reset Out (reset on high)
// PORTC4 - Output to toggle device status
// PORTC5 - Input for Device Connectivity
// PORTA0 - ADC IN , < 50% off, >= 50% on 
// PORTA1 - NPL
// PORTA2 - NC (status LED)
// PORTA3 - NC (Off limits for programming)
// PORTA4 - CLK Output for Serial Address Read
// PORTA5 - TTL check In 0 - off, 1 - on / NC


void MainInit()
{
    //  Set the ADC reference to be VDD
    ADCON1bits.ADPREF = 0x00;
    
    //  PORT A Assignments
    TRISAbits.TRISA0 = 1; // RA0 = ADC IN , < 50% off, >= 50% on
    TRISAbits.TRISA1 = 1; // RA1 = NPL
    TRISAbits.TRISA2 = 0; // RA2 = NC (status LED)
    TRISAbits.TRISA3 = 0; // RA3 = NC (Off limits for programming)
    TRISAbits.TRISA4 = 0; // RA4 = CLK Output for Serial Address Read
    TRISAbits.TRISA5 = 0; // RA5 = TTL check In 0 - off, 1 - on / NC

    ANSELAbits.ANSELA = 0b00000001;

    //	PORT C Assignments
    TRISCbits.TRISC0 = 1; // RC0 = SCL signal to SEE (must be set as input)
    TRISCbits.TRISC1 = 1; // RC1 = SDA signal to SEE (must be set as input)
    TRISCbits.TRISC2 = 0; // RC2 = Set this port to read the i2c address
    TRISCbits.TRISC3 = 1; // RC3 = Reset Out (reset on high)
    TRISCbits.TRISC4 = 0; // RC4 = Output to toggle device status
    TRISCbits.TRISC5 = 1; // RC5 = Input for Device Connectivity
    ANSELCbits.ANSELC = 0b00000000;

    // set the device to be turned off
    PORTCbits.RC4 = 0;
    // set the reset to be low
    PORTCbits.RC2 = 0;

    // enable the ADC
    ADCON1bits.ADFM = 1;    //Result right justified
    ADCON0bits.ADON = 1;    //Turns on ADC module
    ADCON0bits.CHS = 0;     //Selects channel 0 ( AN0 )
}

void Blink()
{
    PORTAbits.RA2 = 0;
    __delay_ms(100);
    PORTAbits.RA2 = 1;
    __delay_ms(100);
    PORTAbits.RA2 = 0;
    __delay_ms(100);
}



#define RX_ELMNTS	1

// array for master to read from
volatile unsigned char I2C_Array_Tx[RX_ELMNTS] = {0x00};

// array for master to write to
volatile unsigned char I2C_Array_Rx[RX_ELMNTS] = {0x00};

unsigned char junk = 0;          // used to place unnecessary data

void initialize(void);           // initialize routine
void DoWork(void);

/**************************** MAIN ROUTINE ************************************/
void main(void)
{
    int i;
    byte i2cAdd = 0x00;

    initialize();               // call initialize routine

    // load the DIP address into the register
    PORTAbits.RA5 = 0; // set the clock pin to low
    PORTAbits.RA4 = 1; // set hold
     __delay_ms(1);
    PORTAbits.RA4 = 0; // load the bits
    __delay_ms(1);
    PORTAbits.RA4 = 1; // hold the bits
    __delay_ms(1);

    if( PORTCbits.RC3 == 1)
        m_DevSCL = 1;

    // read the I2C address [only 7 bits], loaded as MSB
    for( i = 7; i > 0; i-- )
    {

         // cycle the clock signal
        PORTAbits.RA5 = 1;
         __delay_ms(1);
        PORTAbits.RA5 = 0;
         __delay_ms(1);

         if( PORTCbits.RC3 == 1)
         {
              i2cAdd = i2cAdd | (0x01 << i);
         }

    }

    // set the i2c address
    SSPADD = i2cAdd;
    
    Blink();
    Blink();
    Blink();
    
    while(1)                    // main while() loop
    {                           // program will wait here for ISR to be called
        asm("CLRWDT");          // clear WDT

        if( I2C_Array_Rx[0] != 0x00) // check to see if we recieved a command
        {
            PORTAbits.RA2 = 1;
            DoWork();               // do some work
            PORTAbits.RA2 = 0;
        }
    }
}// end main
/******************************************************************************/

/****************************** DO WORK ROUTINE *******************************/
void DoWork(void)
{
    byte poweredOn = 0;
    unsigned short ADCResult = 0;
    byte inputCom = I2C_Array_Rx[0];
    I2C_Array_Rx[0] = 0x00; // mark as read

    // we now have a command
    switch( inputCom )
    {
        case 0x01: // get status
            // do nothing
            break;
        case 0x02: // power on
            PORTCbits.RC4 = 1;

            break;
        case 0x03: // power off
            PORTCbits.RC4 = 0;

            break;
       case 0x04: // reset

           // toggle the reset
           PORTCbits.RC2 = 1;
           __delay_ms(100);
           PORTCbits.RC2 = 0;

           break;
       default: // unknown command
           inputCom = 0x00; // set to unknown value
      }

         // update the status
         if( !PORTAbits.RA1 && (inputCom != 0x00 )) // not connected to a device
         {
             m_status = 0x01;
         }
         else if( inputCom != 0x00 )
         {
              __delay_ms(100); // let the device boot

              poweredOn = 0;

              // check device status
              if( m_DevSCL == 1)
              {
                  // TTL check
                  poweredOn = PORTCbits.RC5;
              }
              else
              {
                  // read the adc
                   ADCON0bits.GO = 1;   //Starts ADC conversion
                   while (ADCON0bits.GO_nDONE) continue;   //wait till ADC conversion is over

                   ADCResult = (ADRESH<<8) + ADRESL ;   //Merging the MSB and LSB

                   if( ADCResult > 512 )
                       poweredOn = 1;
                   else
                       poweredOn = 0;
              }

              // check for powered on conflict
              switch(inputCom)
              {
              case 0x01: // status
                  m_status = 0x00;
                  break;
              case 0x02: // power on
              case 0x04: // reset
                  if( poweredOn )
                      m_status = 0x02; //  Power Up Successful
                  else
                      m_status = 0x03; //  Power Up Failure

                 break;
              case 0x03: // power off

                  if( poweredOn )
                      m_status = 0x05; // power down failure
                  else
                      m_status = 0x04; // Power Down Successful
                 break;
              }
         }


         // send the status
         I2C_Array_Tx[0] = m_status;
}
/******************************************************************************/

/**************************** INITIALIZE ROUTINE ******************************/
void initialize(void)
{
    //uC SET UP
    MainInit();

    OSCCON = 0b01111010; 	// Internal OSC @ 16MHz
    OPTION_REG = 0b11010111;    // WPU disabled, INT on rising edge, FOSC/4
                                // Prescaler assigned to TMR0, rate @ 1:256
    WDTCON = 0b00010111;        // Prescaler 1:65536
                                // period is 2 sec (RESET value)
    PORTC = 0x00;               // Clear PORTC
    LATC = 0x00;                // Clear PORTC latches
    //TRISC = 0b00011000;         // Set RC3, RC4 as inputs for I2C
    //I2C SLAVE MODULE SET UP
    SSPSTAT = 0b10000000;       // Slew rate control disabled for standard
                                // speed mode (100 kHz and 1 MHz)
    SSPCON1 = 0b00110110; 	// Enable serial port, I2C slave mode,
                                // 7-bit address
    SSPCON2bits.SEN = 1;        // Clock stretching is enabled
    SSPCON3bits.BOEN = 1;       // SSPBUF is updated and NACK is generated
                                // for a received address/data byte,
                                // ignoring the state of the SSPOV bit
                                // only if the BF bit = 0
    SSPCON3bits.SDAHT = 1;	// Minimum of 300 ns hold time on SDA after
                                // the falling edge of SCL
    SSPCON3bits.SBCDE = 1;	// Enable slave bus collision detect interrupts
    //SSPADD = I2C_slave_address; // Load the slave address - written elsewhere
    SSP1IF = 0;                 // Clear the serial port interrupt flag
    BCL1IF = 0;                 // Clear the bus collision interrupt flag
    BCL1IE = 1;                 // Enable bus collision interrupts
    SSP1IE = 1;                 // Enable serial port interrupts
    PEIE = 1;                   // Enable peripheral interrupts
    GIE = 1;                    // Enable global interrupts
}//end initialize
/******************************************************************************/

/*************************** ISR ROUTINE **************************************/
void interrupt ISR(void)
{
    
    if(SSP1IF)                                  // check to see if SSP interrupt
    {
        
        if(SSPSTATbits.R_nW)                    // Master read (R_nW = 1)
        {
            
            if(!SSPSTATbits.D_nA)               // last byte was an address (D_nA = 0)
            {
                junk = SSPBUF;                  // dummy read to clear BF bit

            }
            // otherwise do nothing // last byte was data

            // report the value in the Tx Array
            SSPBUF = I2C_Array_Tx[0];

            SSPCON1bits.CKP = 1;                // release CLK
           
        }

        if(!SSPSTATbits.R_nW)			// master write (R_nW = 0)
        {
            
            if(!SSPSTATbits.D_nA)               // last byte was an address (D_nA = 0)
            {
                junk = SSPBUF;			// read buffer to clear BF
		SSPCON1bits.CKP = 1;            // release CLK
            }
            if(SSPSTATbits.D_nA)                // last byte was data (D_nA = 1)
            {

                // store the data in the Rx Array
               I2C_Array_Rx[0] = SSPBUF;

                if(SSPCON1bits.WCOL)		// Did a write collision occur?
		{
                    SSPCON1bits.WCOL = 0;       // clear WCOL bit
                    junk = SSPBUF;              // clear SSPBUF
		}

		SSPCON1bits.CKP = 1;    	// release CLK
            }
    	}
    }
    if(BCL1IF)                       // Did a bus collision occur?
    {
        
        junk = SSPBUF;              // clear SSPBUF
	BCL1IF = 0;                 // clear BCLIF
	SSPCON1bits.CKP = 1;        // Release CLK
    }
    SSP1IF = 0;                      // clear SSPIF

}