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

// define the interface function to deal with peripherals
typedef void(*init_fcn)();
const init_fcn init_mag = &LSM303DLHCDigitalCompass_init;
const init_fcn init_acc = &LSM303DLHCAccelerometer_init;



uint8
sci_Init(uint16 baud, uint8 ninebits)
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

void interrupt ISR(void)
{
    // disable interrupts
    GIE = 0;
    
    // check who called
    if( RCIF ) //  USART1 Receive Interrupt Flag bit
    {
        // reset the interrupt to 0
        RCIF = 0;
    }
    else if( RC2IF ) //  USART2 Receive Interrupt Flag bit
    {
        // reset the interrupt to 0    
        RC2IF = 0;
    }
    else if( TMR1GIF ) // Timer1 Gate Interrupt Flag bit
    {
        // reset the interrupt to 0
        TMR1GIF = 0;
    }
    else if( SSPIF ) //  Synchronous Serial Port (MSSP1) Interrupt Flag bit
    {
        // reset the interrupt to 0    
        SSPIF = 0;
    }
    else if( SSP2IF ) //  Synchronous Serial Port (MSSP2) Interrupt Flag bit
    {
        // reset the interrupt to 0   
        SSP2IF = 0;
    }
    else if( TMR2IF ) // Timer2 to PR2 Interrupt Flag bit
    {
        // reset the interrupt to 0
        TMR2IF = 0;
    }
    else if( TMR1IF  ) // Timer1 Overflow Interrupt Flag bit
    {
        // reset the interrupt to 0        
        TMR1IF = 0;
    }
    else if ( TMR6IF ) // TMR6 to PR6 Match Interrupt Flag bit
    {
        // reset the interrupt to 0     
        TMR6IF = 0;
    }
    else if( TMR4IF ) // TMR4 to PR4 Match Interrupt Flag bit
    {
        // reset the interrupt to 0    
        TMR4IF = 0;
    }
    else if ( OSFIF ) // Oscillator Fail Interrupt Flag bit
    {
        // reset the interrupt to 0       
        OSFIF = 0;
    }
    
    // re-enable interrupts
    GIE = 1;
}

void init()
{
    // start by disabling global interrupts
    GIE = 0;
    
    // OSCON setup
    OSCCONbits.IRCF = 0b00001101; // 4 MHz
    
    // initialize the I2C addresses
    magAddr = LSM303DLHCDigitalCompass_ADDR;
    accAddr = LSM303DLHCAccelerometer_ADDR;
    tempAddr0 = 0x00;
    tempAddr1 = 0x00;
    tempAddr2 = 0x00;
    tempAddr3 = 0x00;
    tempAddr4 = 0x00;
    tempAddr5 = 0x00;
    
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
    sci_Init(0,0);
    
    I2C_init2();
    
    // initialize the compass 
    init_mag();
    
    // initialize the accelerometer
    init_acc();
    
    
    // enable interrupts
    
    
    
    // enable the global interrupt
    GIE = 1;
}
void putch(unsigned char data)
{
    //unsigned char parity = 0;
    while (!TX1IF);           // wait until TXREG empty
        
    // get the parity bit
    //TX1STAbits.TX9D = data % 2;
    TX1REG = data;           // send character
}

void PrintStrToUART(char* str, unsigned char len)
{
    unsigned char ii;
    for( ii = 0; ii < len; ii++)
    {
        putch(str[ii]);
        
        if( (str[ii] == '\0') || (str[ii] == '\r') )
            return;
    }
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
        //a++;
        //b--;
    
       PORTEbits.RE0 = ~PORTEbits.RE0;
       //a++;
       //sprintf(str, "Alt: Az: 0x%02X\n\r", a);
       //PrintStrToUART(str, 20);
        __delay_ms(1000);
    }
    return;
}
