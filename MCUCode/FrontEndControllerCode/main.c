/*
 * File:   main.c
 * Author: jfixelle
 *
 * Created on July 9, 2016, 3:07 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16lf1947.h>
#include "Includes.h"
#include "LSM303DLHC.h"

// CONFIG1
#pragma config FOSC = INTOSC       // Oscillator Selection (ECH, External Clock, High Power Mode (4-32 MHz): device clock supplied to CLKIN pin)
#pragma config WDTE = ON        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)


// Definitions
#define _XTAL_FREQ  4000000        // this is used by the __delay_ms(xx) and __delay_us(xx) functions

// -------------- PIN LAYOUT ---------------------
// UART communication (UART1)
//  RC6(31) - UART TX1
//  RC7(32) - UART RX1
// I2C communication (MSSP2)
//  RD5(52) - I2C SDA2
//  RD6(50) - I2C SCL2

void null_fcn(){}

// define the interface function to deal with peripherals
// if no function is defined, use the null_fcn
// this will allow for the pointer to be called without a null ptr check

typedef void(*init_fcn)();
const init_fcn init_mag = &LSM303DLHCDigitalCompass_init;
const init_fcn init_acc = &LSM303DLHCAccelerometer_init;
const init_fcn init_temp0 = &null_fcn;
const init_fcn init_temp1 = &null_fcn;
const init_fcn init_temp2 = &null_fcn;
const init_fcn init_temp3 = &null_fcn;
const init_fcn init_temp4 = &null_fcn;
const init_fcn init_temp5 = &null_fcn;

typedef void(*get_word_fcn)();
const get_word_fcn acc_get_xword = &LSM303DLHCAccelerometer_get_xword;
const get_word_fcn acc_get_yword = &LSM303DLHCAccelerometer_get_yword;
const get_word_fcn acc_get_zword = &LSM303DLHCAccelerometer_get_zword;

const get_word_fcn mag_get_xword = &LSM303DLHCDigitalCompass_get_xword;
const get_word_fcn mag_get_yword = &LSM303DLHCDigitalCompass_get_yword;
const get_word_fcn mag_get_zword = &LSM303DLHCDigitalCompass_get_zword;
const get_word_fcn mag_get_tword = &LSM303DLHCDigitalCompass_get_tword;

const get_word_fcn temp0_get_word = &null_fcn;
const get_word_fcn temp1_get_word = &null_fcn;
const get_word_fcn temp2_get_word = &null_fcn;
const get_word_fcn temp3_get_word = &null_fcn;
const get_word_fcn temp4_get_word = &null_fcn;
const get_word_fcn temp5_get_word = &null_fcn;

uint8 UART_init(uint16 baud, uint8 ninebits)
{
 int16 X;
 uint16 tmp;

#if 0
 /* calculate and set baud rate register */
 /* for asynchronous mode */
 tmp = 16UL * baud;
 X = (int)(FOSC/tmp) - 1;
 if((X>255) || (X<0))
 {
  tmp = 64UL * baud;
  X = (int)(FOSC/tmp) - 1;
  if((X>255) || (X<0))
  {
   return 1; /* panic - baud rate unobtainable */
  }
  else
   BRGH = 0; /* low baud rate */
 }
 else
  BRGH = 1; /* high baud rate */
 SPBRG = X; /* set the baud rate */

#endif
 
 SP1BRGL = 25; // 4800 baud
 SP1BRGH = 0;
 TX1STAbits.BRGH = 1;
 BAUD1CONbits.BRG16 = 0;
 
 TX1STAbits.SYNC = 0; /* asynchronous */
 RC1STAbits.SPEN = 1; /* enable serial port pins */
 RC1STAbits.CREN = 1; /* enable reception */
 RC1STAbits.SREN = 0; /* no effect */
 TX1IE = 0; /* disable tx interrupts */
 RC1IE = 0; /* disable rx interrupts */
 TX1STAbits.TX9 = ninebits?1:0; /* 8- or 9-bit transmission */
 RC1STAbits.RX9 = ninebits?1:0; /* 8- or 9-bit reception */
 TX1STAbits.TXEN = 1; /* enable the transmitter */

 
//    TXSTA = 0b00100000;     // 8-bit, TXEN, async, BRGH=0
//    RCSTA = 0b10010000;     // SPEN, 8-bit, CREN
 //   BAUDCON = 0b00000000;   // BRG16=0
 //   BRG16 = 1;
 //   SPBRG = 52;
 //   BRGH = 1;
 
 return 0;
}

void I2C_init2()
{
    // initialize I2C on MSSP2
    SSP2CON1bits.SSPEN = 1; // enable the MSSP
    SSP2CON1 = (SSP2CON1&0xF0)| 0b00001000; // set to I2C master mode
    SSP2CON2 = 0x00; // clear the SSPCON2 register
    SSP2ADD = 0x09;  // set the clock frequency to 100 KHz (based on 4MHz clk)
    SSP2STAT = 0b11000000; 	// Slew rate disabled and input threshold compliant
}

void I2C_init1()
{
    // initialize I2C on MSSP2
    SSP1CON1bits.SSPEN = 1; // enable the MSSP
    SSP1CON1 = (SSP1CON1&0xF0)| 0b00001000; // set to I2C master mode
    SSP1CON2 = 0x00; // clear the SSPCON2 register
    SSP1ADD = 0x09;  // set the clock frequency to 100 KHz (based on 4MHz clk)
    SSP1STAT = 0b11000000; 	// Slew rate disabled and input threshold compliant
}


uint8 UART_TX_Empty()
{
  return TX1STAbits.TRMT;
}

uint8 UART_Data_Ready()
{
  return RC1IF;
}

void UART_Write(uint8 data)
{
    //unsigned char parity = 0;
    while (!TX1IF);           // wait until TXREG empty
    //while(!TX1STAbits.TRMT); 
    // get the parity bit
    //TX1STAbits.TX9D = data % 2;
    TX1REG = data;           // send character
}

void PrintStrToUART(int8* str, uint8 len)
{
    uint8 ii;
    for( ii = 0; ii < len; ii++)
    {
        UART_Write(str[ii]);
        
        if( (str[ii] == '\0') || (str[ii] == '\r') )
            return;
    }
}

uint8 UART_Read()
{
  while(!RC1IF);
  return RC1REG;
}



// 
// -------------------------------- Interrupt Table ---------------------------------------
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 
// | BINDING |  FLAG  | PRIORITY |  FUNCTION   |     DESCRIPTION                          | 
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 
// |  OSCF   | OSFIF  |    0     |      --     | Set the Oscillator fail error flag       |  
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 
// |  TMR2   | TMR2IF |    1     | timeout_isr | Handle Timeout assertion                 |
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 
// |  UART   | RCIF   |    2     | uart_isr    | Handle UART RX signal                    |
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 
// |  TMR4   | TMR4IF |    3     | delay_isr   | Handle Timeout for delay signal - repoll |
// + ------- + ------ + -------- + ----------- + ---------------------------------------- + 

inline void timeout_isr()
{
    // set the timeout
    FEStatus |= STATUS_TIMEOUT_SET;
}

inline void uart_isr()
{
    // check to see if the FIFO is full
    uint8 isFull = FIFO_FULL();
    
    // increment the FIFOptr
    FIFOWrPtr = NEXT_PTR(FIFOWrPtr);
    
    // if full, make sure to drag the rdptr
    if( isFull )
    {
        FIFORdPtr = FIFOWrPtr;
    }
    
    // ignore overwriting
    FIFOBuffer[FIFOWrPtr] = UART_Read();
    
    // set new data flag
    FIFOReady = 1;
}

inline void delay_isr()
{
    FEStatus |= STATUS_DELAY_COMPLETE;
}

void interrupt ISR(void)
{
    // disable interrupts
    GIE = 0;
    
    // check who called
    if ( OSFIF ) // Oscillator Fail Interrupt Flag bit
    {
        // @@TODO Capture this
        // not captured right now
        // reset the interrupt to 0       
        OSFIF = 0;
    }
    else if( TMR2IF ) // Timer2 to PR2 Interrupt Flag bit
    {
        timeout_isr();
        
        // reset the interrupt to 0
        TMR2IF = 0;
    }
    else if( RCIF ) //  USART1 Receive Interrupt Flag bit
    {
        uart_isr();
        // reset the interrupt to 0
        RCIF = 0;
    }
    else if( TMR4IF ) // TMR4 to PR4 Match Interrupt Flag bit
    {
        delay_isr();
        // reset the interrupt to 0    
        TMR4IF = 0;
    }
     
    // re-enable interrupts
    GIE = 1;
}

void init_all_sensors()
{
    init_mag();
    init_acc();
    init_temp0();
    init_temp1();
    init_temp2();
    init_temp3();
    init_temp4();
    init_temp5();
    
    // delay for 1 ms
    __delay_ms(1);
}

void poll_temp_data()
{
    mag_get_tword();
    temp0_get_word();
    temp1_get_word();
    temp2_get_word();
    temp3_get_word();
    temp4_get_word();
    temp5_get_word();
    
}

void poll_orient_data()
{
    acc_get_xword();
    acc_get_yword();
    acc_get_zword();
    mag_get_xword();
    mag_get_yword();
    mag_get_zword();
}

void poll_all_data()
{
    poll_orient_data();
    poll_temp_data();
}

void init()
{
    // start by disabling global interrupts
    GIE = 0;
    
    // OSCON setup
    OSCCONbits.IRCF = 0b00001101; // 4 MHz
    

    
    // ---- Port assignments ------
    // For TRIS : output(0), input(1)
    // For ANSEL: digital(0), analog(1)
    
    // PORT A Assignments
    TRISAbits.TRISA0 = 0; // RA0 = 
    TRISAbits.TRISA1 = 0; // RA1 = 
    TRISAbits.TRISA2 = 0; // RA2 = 
    TRISAbits.TRISA3 = 0; // RA3 = 
    TRISAbits.TRISA4 = 0; // RA4 = 
    TRISAbits.TRISA5 = 0; // RA5 = 
   
    ANSELAbits.ANSELA = 0b00000000;
    
    // PORT B Assignments
    TRISBbits.TRISB4 = 0; // RB4 = 
    TRISBbits.TRISB5 = 0; // RB5 = 
    TRISBbits.TRISB6 = 0; // RB6 = 
    TRISBbits.TRISB7 = 0; // RB7 = 
    
    // no ANSEL option for PORT B
    
    // PORT C Assignments
    TRISCbits.TRISC0 = 0; // RC0 = 
    TRISCbits.TRISC1 = 0; // RC1 = 
    TRISCbits.TRISC2 = 0; // RC2 = 
    TRISCbits.TRISC3 = 0; // RC3 = 
    TRISCbits.TRISC4 = 0; // RC4 = 
    TRISCbits.TRISC5 = 0; // RC5 = 
    TRISCbits.TRISC6 = 0; // RC6 = TX1
    TRISCbits.TRISC7 = 1; // RC7 = RX1
        
    //  no ANSEL option for PORT C
    
    // PORT D Assignments
    TRISDbits.TRISD0 = 0; // RD0 = 
    TRISDbits.TRISD1 = 0; // RD1 = 
    TRISDbits.TRISD2 = 0; // RD2 = 
    TRISDbits.TRISD3 = 0; // RD3 = 
    TRISDbits.TRISD4 = 0; // RD4 = 
    TRISDbits.TRISD5 = 1; // RD5 = I2C SDA2
    TRISDbits.TRISD6 = 1; // RD6 = I2C SDL2
    TRISDbits.TRISD7 = 0; // RD7 = 
    
    // no ANSEL option for PORT D
    
    //	PORT E Assignments
    TRISEbits.TRISE0 = 0; // RE0 = 
    TRISEbits.TRISE1 = 0; // RE1 = LED blink
    TRISEbits.TRISE2 = 0; // RE2 = 
    TRISEbits.TRISE3 = 0; // RE3 = 
    TRISEbits.TRISE4 = 0; // RE4 = 
    TRISEbits.TRISE5 = 0; // RE5 = 
    TRISEbits.TRISE6 = 0; // RE6 = 
    TRISEbits.TRISE7 = 0; // RE7 = 
    ANSELEbits.ANSELE = 0b00000000;
    
    // PORT F Assignments
    TRISFbits.TRISF0 = 0; // RF0 = 
    TRISFbits.TRISF1 = 0; // RF1 = 
    TRISFbits.TRISF2 = 0; // RF2 = 
    TRISFbits.TRISF3 = 0; // RF3 = 
    TRISFbits.TRISF4 = 0; // RF4 = 
    TRISFbits.TRISF5 = 0; // RF5 = 
    TRISFbits.TRISF6 = 0; // RF6 = 
    TRISFbits.TRISF7 = 0; // RF7 = 
    
    ANSELFbits.ANSELF = 0b00000000;
    
    // PORT G Assignments
    TRISGbits.TRISG0 = 0; // RG0 = 
    TRISGbits.TRISG1 = 0; // RG1 = 
    TRISGbits.TRISG2 = 0; // RG2 = 
    TRISGbits.TRISG3 = 0; // RG3 = 
    TRISGbits.TRISG4 = 0; // RG4 = 
    TRISGbits.TRISG5 = 0; // RG5 = 
    
    ANSELGbits.ANSELG = 0b00000000;
    
    // initialize the UART1 module
    UART_init(0,0);
    
    // initialize the MSSP2 module
    I2C_init2();
    
    // ---- initialize timers ---------
    // make sure they are off
    T2CONbits.TMR2ON = 0;
    T4CONbits.TMR4ON = 0;
    T6CONbits.TMR6ON = 0;
    // timer 2
    T2CONbits.T2OUTPS = 0x00; // 1:1 post-scaler
    T2CONbits.T2CKPS = 0x02;  // 1:64 pre-scaler
    // timer 4
    T4CONbits.T4OUTPS = 0x00; // 1:1 post-scaler
    T4CONbits.T4CKPS = 0x02;  // 1:64 pre-scaler
    // timer 6 not used
    
    // set the timeout timer to 16ms
    PR2 = 0xFF;
    
    // --- set default memory variables -----
    // FIFO variables
    FIFOReady = 0;
    FIFORdPtr = 0;
    FIFOWrPtr = 0;
    FIFOTpPtr = 0;
    
    // general registers
    currentOp = 0; // NOP
    tempMag = 0;
    temp0 = 0;
    temp1 = 0;
    temp2 = 0;
    temp3 = 0;
    temp4 = 0;
    temp4 = 0;
    peltierTSel = 0xFF; // for none
    peltierTgt0 = 0;
    peltierTgt1 = 0;
    xMag = 0;
    yMag = 0;
    zMag = 0;
    xAcc = 0;
    yAcc = 0;
    zAcc = 0;
    outFlags = 0x00;
    FEStatus = 0x00;
    
    // I2C passthrough variables
    numMSGs = 0;
    
    // PID variables
    prevError0 = 0.0f;
    prevError1 = 0.0f;
    accT0 = 0.0f;
    accT1 = 0.0f;
    newVal0 = 0;
    newVal1 = 0;
    PIDpConst = sPIDpConst;
    PIDiConst = sPIDiConst;
    PIDdConst = sPIDdConst;
    
    // I2C addresses
    magAddr = LSM303DLHCDigitalCompass_ADDR;
    accAddr = LSM303DLHCAccelerometer_ADDR;
    tempAddr0 = 0x00;
    tempAddr1 = 0x00;
    tempAddr2 = 0x00;
    tempAddr3 = 0x00;
    tempAddr4 = 0x00;
    tempAddr5 = 0x00;
    
    // ------ begin data setup --------
    // initialize all sensor
    init_all_sensors();
    
    // poll all data
    poll_all_data();
    
    
    // --- enable interrupts --------
    // INTCON
    PEIE = 1;   // enable peripheral interrupts (for UART)
    TMR0IE = 0; // timer0 overflow disable
    INTE = 0;   // disable external interrupts
    IOCIE = 0;  // disable interrupt on change
    
    //  PIE1 (Peripheral 1)
    TMR1GIE = 0; // Timer1 Gate Interrupt Enable bit
    ADIE = 0;    // Disable A/D Converter (ADC) Interrupt Enable bit
    RCIE = 1;    // Enable USART1 Receive Interrupt Enable bit
    TXIE = 0;    // Disable USART1 Transmit Interrupt Enable bit
    SSPIE = 0;   // Synchronous Serial Port (MSSP1) Interrupt Enable bit
    CCP1IE = 0;  // CCP1 Interrupt Enable bit
    TMR2IE = 1;  // TMR2 to PR2 Match Interrupt Enable bit
    TMR1IE = 0;  // Timer1 Overflow Interrupt Enable bit
    
    //  PIE2 (Peripheral 2)
    OSFIE = 1; // Enable Oscillator Fail Interrupt Enable bit (just in case)
    C2IE = 0;  // Disable Comparator C2 Interrupt Enable bit
    C1IE = 0;  // Disable Comparator C1 Interrupt Enable bit
    EEIE = 0;  // Disable EEPROM Write Completion Interrupt Enable bit
    BCLIE = 0; // Disable MSSP1 Bus Collision Interrupt Enable bit
    LCDIE = 0; // Disable LCD Module Interrupt Enable bit
    C3IE = 0;  // Disable Comparator C3 Interrupt Enable bit
    CCP2IE = 0;// Disable CCP2 Interrupt Enable bit

    //  PIE3 (Peripheral 3)
    CCP5IE = 0;// Disable CCP5 Interrupt Enable bit
    CCP4IE = 0;// Disable CCP4 Interrupt Enable bit
    CCP3IE = 0;// Disable CCP3 Interrupt Enable bit
    TMR6IE = 0;// Disable TMR6 to PR6 Match Interrupt Enable bit
    TMR4IE = 1;// Enable TMR4 to PR4 Match Interrupt Enable bit
    
    //  PIE4 (Peripheral 4)
    RC2IE = 0; // Disable USART2 Receive Interrupt Enable bit
    TX2IE = 0; // Disable USART2 Transmit Interrupt Enable bit
    BCL2IE = 0;// Disable MSSP2 Bus Collision Interrupt Enable bit
    SSP2IE = 0;// Disable Synchronous Serial Port (MSSP2) Interrupt Enable bit
    
    // initialize the delay timer to max
    SET_DELAY_MAX();
    
    // enable the global interrupt
    GIE = 1;
}

void check_FIFO()
{
    if(!FIFOReady)
        return; // the FIFO has no data for us
    
    // set the temp ptr to the read ptr
    FIFOTpPtr = FIFORdPtr;
    // set the temp op to max 0xFF to mark invalid
    tempOp = 0xFF;
    
    // invalidate the checksum
    checksum = 0xFF;
    
    // reset the packet count
    packetCount = 0;
    
    // reset the packet size
    packetSize = 0;
    
    // start cycling through the FIFO
    while(FIFOTpPtr != FIFOWrPtr)
    {
        // look for escape character
        if( FIFOBuffer[FIFOTpPtr] == 0x1B ) // escape character
        {
            // increment the FIFO again
            FIFOTpPtr = NEXT_PTR(FIFOTpPtr);
            
            // now check to see if the next ptr is valid
            if( FIFOTpPtr == FIFOWrPtr )
            {
                // exit early, the escape character is invalid
                return;
            }
            else
            {
                // switch on the char case
                switch(FIFOBuffer[FIFOTpPtr])
                {
                case 0x01: // start of packet
                    // increment the next pointer
                    FIFOTpPtr = NEXT_PTR(FIFOTpPtr);
                    packetSize = FIFOBuffer[FIFOTpPtr];
                    // set the packet count to 0
                    packetCount = 0;
                    checksum = packetSize; // checksum includes size
                    break;
                case 0x04: // end of packet
                    // verify that we have the correct number
                    if( (packetCount == packetSize) && (checksum == 0) )
                    {
                        // copy the values over
                        currentOp = tempOp;
                        
                        // backstep the ptr, skip the first element for the arg
                        argStart = FIFOTpPtr-packetSize+1; 
                        if( argStart < 0 )
                        {
                            argStart = argStart + FIFO_SIZE;
                        }
                        
                        // reassign the read pointer (the message has been read)
                        FIFORdPtr = FIFOTpPtr;
                        
                        // we finished this packet
                        return; 
                    }
                    else
                    {
                        // move the read pointer, the previous message is bad
                        FIFORdPtr = FIFOTpPtr;
                    }
                    break;
                case 0x1B: // data in field
                    // add it to the checksum and move on
                    checksum = checksum + 0x1B;
                    packetCount = packetCount + 2;
                    break;
                default: // unknwon escape sequence
                    
                    // move the read pointer and return
                    FIFORdPtr = FIFOTpPtr;
                    return;
                }
            }
        }
        else // no escape character
        {
            // check to see if we are in a packet
            if( packetSize != 0 )
            {
                // check for overrun
                if( packetCount > packetSize )
                {
                    // reset the read pointer and return
                    FIFORdPtr = FIFOTpPtr;
                    return;
                }
                
                // otherwise, just add the checksum and continue
                checksum = checksum + FIFOBuffer[FIFOTpPtr];
                
            }
            // otherwise, do nothing
            
        }
        
        // increment the temp ptr
        FIFOTpPtr = NEXT_PTR(FIFOTpPtr);
    }
    
}

#define WRITE_ESCD_BYTE(c) if( (c) == 0x1B ){   UART_Write(0x1B); } \
                            UART_Write((c));

#define WRITE_BYTE(c) WRITE_ESCD_BYTE((c)); \
            checksum += (c);

#define WRITE_SHORT(c)  WRITE_ESCD_BYTE((c)>>8); \
            checksum += ((c)>>8); \
            WRITE_ESCD_BYTE((c)&0x00FF); \
            checksum += (c)&0x00FF;

#define CHECK_ESCAPE_BYTE(c) if( (c) == 0x1B ){ packetSize += 1; } 
#define CHECK_ESCAPE_SHORT(c) CHECK_ESCAPE_BYTE((c)>>8); \
                              CHECK_ESCAPE_BYTE((c)&0x0FF);


void send_UART_packet(uint8 op)
{
    // verify that we have a valid op
    switch(op)
    {
        case (OP_POLL_TEMP_IMMED|0x80): 
        case OP_POLL_ORIENT_IMMED:
        case OP_REQ_ALL_DATA:
        case OP_GET_RST_REG:
            // valid ops
            break;
        default:
            // invalid op
            return;
    }
    
    // send start of packet
    UART_Write(0x1B);
    UART_Write(0x01);
    
    // branch of operation
    switch(op)
    {
        case (OP_POLL_TEMP_IMMED|0x80): 
            // going to send ---
            // uint8 op
            // uint16 tempMag;
            // uint16 temp0;
            // uint16 temp1;
            // uint16 temp2;
            // uint16 temp3;
            // uint16 temp4;
            // uint16 temp5;
            // size of 15
            packetSize = 15;
            
            // check variables for escape characters
            CHECK_ESCAPE_BYTE(op);
            CHECK_ESCAPE_SHORT(tempMag);
            CHECK_ESCAPE_SHORT(temp0);
            CHECK_ESCAPE_SHORT(temp1);
            CHECK_ESCAPE_SHORT(temp2);
            CHECK_ESCAPE_SHORT(temp3);
            CHECK_ESCAPE_SHORT(temp4);
            CHECK_ESCAPE_SHORT(temp5);
            
            // write the packet size
            UART_Write(packetSize);
            checksum = packetSize;
            
            // write the packet data
            WRITE_BYTE(op);
            WRITE_SHORT(tempMag);
            WRITE_SHORT(temp0);
            WRITE_SHORT(temp1);
            WRITE_SHORT(temp2);
            WRITE_SHORT(temp3);
            WRITE_SHORT(temp4);
            WRITE_SHORT(temp5);
            
            // negate the checksum
            checksum = ~checksum;
            checksum += 1;
            
            // write the checksum
            UART_Write(checksum);
            
            break;
        case OP_POLL_ORIENT_IMMED:
            // going to send ---
            // uint8 op
            // uint16 xMag;
            // uint16 yMag;
            // uint16 zMag;
            // uint16 xAcc;
            // uint16 yAcc;
            // uint16 zAcc;
            // size of 13
            packetSize = 13;
            
            // check variables for escape characters
            CHECK_ESCAPE_BYTE(op);
            CHECK_ESCAPE_SHORT(xMag);
            CHECK_ESCAPE_SHORT(yMag);
            CHECK_ESCAPE_SHORT(zMag);
            CHECK_ESCAPE_SHORT(xAcc);
            CHECK_ESCAPE_SHORT(yAcc);
            CHECK_ESCAPE_SHORT(zAcc);

            // write the packet size
            UART_Write(packetSize);
            checksum = packetSize;
            
            // write the packet data
            WRITE_BYTE(op);
            WRITE_SHORT(xMag);
            WRITE_SHORT(yMag);
            WRITE_SHORT(zMag);
            WRITE_SHORT(xAcc);
            WRITE_SHORT(yAcc);
            WRITE_SHORT(zAcc);

            
            // negate the checksum
            checksum = ~checksum;
            checksum += 1;
            
            // write the checksum
            UART_Write(checksum);
            
            break;
        case OP_REQ_ALL_DATA:
            // going to send ---
            // uint8 op
            // uint16 xMag;
            // uint16 yMag;
            // uint16 zMag;
            // uint16 xAcc;
            // uint16 yAcc;
            // uint16 zAcc;
            // uint16 tempMag;
            // uint16 temp0;
            // uint16 temp1;
            // uint16 temp2;
            // uint16 temp3;
            // uint16 temp4;
            // uint16 temp5;
            // size of 27
            packetSize = 27;
            
            // check variables for escape characters
            CHECK_ESCAPE_BYTE(op);
            CHECK_ESCAPE_SHORT(xMag);
            CHECK_ESCAPE_SHORT(yMag);
            CHECK_ESCAPE_SHORT(zMag);
            CHECK_ESCAPE_SHORT(xAcc);
            CHECK_ESCAPE_SHORT(yAcc);
            CHECK_ESCAPE_SHORT(zAcc);
            CHECK_ESCAPE_SHORT(tempMag);
            CHECK_ESCAPE_SHORT(temp0);
            CHECK_ESCAPE_SHORT(temp1);
            CHECK_ESCAPE_SHORT(temp2);
            CHECK_ESCAPE_SHORT(temp3);
            CHECK_ESCAPE_SHORT(temp4);
            CHECK_ESCAPE_SHORT(temp5);
            
            // write the packet size
            UART_Write(packetSize);
            checksum = packetSize;
            
            // write the packet data
            WRITE_BYTE(op);
            WRITE_SHORT(xMag);
            WRITE_SHORT(yMag);
            WRITE_SHORT(zMag);
            WRITE_SHORT(xAcc);
            WRITE_SHORT(yAcc);
            WRITE_SHORT(zAcc);
            WRITE_SHORT(tempMag);
            WRITE_SHORT(temp0);
            WRITE_SHORT(temp1);
            WRITE_SHORT(temp2);
            WRITE_SHORT(temp3);
            WRITE_SHORT(temp4);
            WRITE_SHORT(temp5);
            
            // negate the checksum
            checksum = ~checksum;
            checksum += 1;
            
            // write the checksum
            UART_Write(checksum);
            
            break;
        case OP_GET_RST_REG:
            // going to send ---
            // uint8 op
            // uint8 PCON;
            // size of 2
            packetSize = 2;
            
            // check variables for escape characters
            CHECK_ESCAPE_BYTE(op);
            CHECK_ESCAPE_BYTE(PCON);
            
            UART_Write(packetSize);
            checksum = packetSize;
            
            WRITE_BYTE(op);
            WRITE_BYTE(PCON);
            
            // negate the checksum
            checksum = ~checksum;
            checksum += 1;
            
            // write the checksum
            UART_Write(checksum);
            
            break;
        default:
            // default is NOP
            break;
    }
    
    // write the checksum
    
    // write the end of packet
    UART_Write(0x1B);
    UART_Write(0x04);
    
}

void main(void) 
{
 
    //int a = 0;
    //int b = 0;
    //char str[20];
    
    init();
    
    PORTEbits.RE0 = 1;
    
    while(1)
    {

       PORTEbits.RE0 = ~PORTEbits.RE0;
       
       
       // always check the FIFO
       check_FIFO();
       
       // branch on slew mode
       if( FEStatus & STATUS_SLEW_SET )
       {
           // slew mode - check for valid commands
           switch( currentOp&0x7F )
           {
               case OP_SET_SLEW:
                   // check the enable bit
                   if(currentOp&0x80)
                   {
                       // enable set -- do nothing
                   }
                   else
                   {
                       // disable set - disable the mode
                       FEStatus &= (~STATUS_SLEW_SET);
                       SET_DELAY_MAX();
                   }
                   break;
               default:
                   // do nothing - ignore all other commands
                   break;
           }
       }
       else
       {
           // parse the command
           switch( currentOp&0x7F )
           {
               case OP_RESET_SENSORS:
                   break;
               case OP_POLL_TEMP_IMMED: //OP_POLL_ORIENT_IMMED  
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       //OP_POLL_TEMP_IMMED
                       poll_temp_data();
                       send_UART_packet(OP_POLL_TEMP_IMMED|0x80); 
                   }
                   else
                   {
                       //OP_POLL_ORIENT_IMMED
                       poll_orient_data();
                       send_UART_packet(OP_POLL_ORIENT_IMMED); 
                   }
                   break;
               case OP_REQ_ALL_DATA:
                   // return the UART packet
                   send_UART_packet(OP_REQ_ALL_DATA); 
                   break;
               case OP_SET_CAL:
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // set
                       outFlags |= OUT_CAL_EN;
                   }
                   else
                   {
                       // unset
                       outFlags &= ~OUT_CAL_EN;
                   }
                   break;
               case OP_SET_SOL_CAL:
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // set
                       outFlags |= OUT_SOLAR_CAL_EN;
                   }
                   else
                   {
                       // unset
                       outFlags &= ~OUT_SOLAR_CAL_EN;
                   }
                   break;
               case OP_SET_SLEW:
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // set
                       FEStatus |= STATUS_SLEW_SET;
                       SET_DELAY_1MS();
                   }
                   else
                   {
                       // unset
                       FEStatus &= ~STATUS_SLEW_SET;
                       SET_DELAY_MAX();
                   }
                   break;
               case OP_SET_T0: //OP_SET_T1   
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // OP_SET_T1
                   }
                   else
                   {
                       // OP_SET_T0
                   }
                   break;
               case OP_SET_PID_CONSTS:
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // save
                   }
                   else
                   {
                       // temp
                   }
                   break;
               case OP_SET_TEMP_SRC:
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // Temp1
                   }
                   else
                   {
                       // Temp2
                   }
                   break;
               case OP_SET_TEMP_FACTORS:
                   // check bit 7
                   if(currentOp&0x80)
                   {
                       // save
                   }
                   else
                   {
                       // temp
                   }
                   break;
               case OP_I2C_PASSSTHROUGH:
                   // @@TODO Implement this
                   break;
               case OP_GET_RST_REG:
                   
                   // return the UART packet
                   send_UART_packet(OP_GET_RST_REG); 
                   
                   break;
               default:
                   // default is NOP
                   break;
           }
       }
       
       // clear the op
       currentOp = 0x00; // NOP
       
       // pause the delay timer
       PAUSE_DELAY_TMR();
           
       // check to see if woken from delay
       if( FEStatus&STATUS_DELAY_COMPLETE )
       {
           
           // branch on mode
           if( !(FEStatus & STATUS_SLEW_SET) )
           {
               // poll the temp sensors
               poll_temp_data();
           }
           
           // poll the orient sensors
           poll_orient_data();
           
           // return orient data (bit 7 not set)
           send_UART_packet(OP_POLL_ORIENT_IMMED); 
           
           // clear the delay bit
           FEStatus &= ~STATUS_DELAY_COMPLETE;
           
           // clear the delay timer
           RESET_DELAY_TMR();
       }
       
       // restart the delay timer
       PLAY_DELAY_TMR();
       
    }
    return;
}
