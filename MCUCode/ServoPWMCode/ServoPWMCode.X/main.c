/*
 * File:   main.c
 * Author: jfixelle
 *
 * Created on June 3, 2016, 4:16 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16lf1508.h>


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF    // Clock Out Enable (CLKOUT function is enabled on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// Definitions
#define _XTAL_FREQ  2000000        // this is used by the __delay_ms(xx) and __delay_us(xx) functions

#define SCI_EIGHT (0)
#define SCI_NINE (1)
unsigned char sci_Init(unsigned long int, unsigned char);
void    sci_PutByte(unsigned char);
unsigned char sci_GetByte(void);
void    sci_PutNinth(unsigned char);
unsigned char sci_GetNinth(void);
unsigned char sci_GetFERR(void);
unsigned char sci_CheckOERR(void);
 


/* Routines for initialisation and use of the SCI
 * for the PIC processor.
 */

/* other options:
 * frame errors
 */

unsigned char
sci_Init(unsigned long int baud, unsigned char ninebits)
{
 int X;
 unsigned long tmp;

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
 
 SPBRG = 207;
 BRGH = 1;
 BRG16 = 0;
 
 SYNC = 0; /* asynchronous */
 SPEN = 1; /* enable serial port pins */
 CREN = 1; /* enable reception */
 SREN = 0; /* no effect */
 TXIE = 0; /* disable tx interrupts */
 RCIE = 0; /* disable rx interrupts */
 TX9 = ninebits?1:0; /* 8- or 9-bit transmission */
 RX9 = ninebits?1:0; /* 8- or 9-bit reception */
 TXEN = 1; /* enable the transmitter */

 
//    TXSTA = 0b00100000;     // 8-bit, TXEN, async, BRGH=0
//    RCSTA = 0b10010000;     // SPEN, 8-bit, CREN
 //   BAUDCON = 0b00000000;   // BRG16=0
 //   BRG16 = 1;
 //   SPBRG = 52;
 //   BRGH = 1;
 
 return 0;
}

void
sci_PutByte(unsigned char byte)
{
 while(!TXIF) /* set when register is empty */
  continue;
 TXREG = byte;

 return;
}

unsigned char
sci_GetByte(void)
{
 while(!RCIF) /* set when register is not empty */
  continue;

 return RCREG; /* RXD9 and FERR are gone now */
}

unsigned char
sci_CheckOERR(void)
{
 if(OERR) /* re-enable after overrun error */
 {
  CREN = 0;
  CREN = 1;
  return 1;
 }
 
 return 0;
}

#define sci_PutNinth(bitnine) (TX9D = bitnine?1:0;)

unsigned char
sci_GetNinth(void)
{
 while(!RCIF)
  continue;
 
 return RX9D; /* RCIF is not cleared until RCREG is read */
}

unsigned char
sci_GetFERR(void)
{
 while(!RCIF)
  continue;
 
 return FERR; /* RCIF is not cleared until RCREG is read */
}

void putch(unsigned char data)
{
    while (!TXIF)           // wait until TXREG empty
        ;
    TXREG = data;           // send character
}

#define AZ_CW   0x2D
#define AZ_CCW  0x30
#define AZ_NEUT 0x00

#define ALT_90     0x10
#define ALT_UP_LIM 0x2F
#define ALT_LO_LIM 0x10

//TRISCbits.TRISC0 = 1; // RC0 = Az+ input
#define AZ_INC  PORTCbits.RC0
//TRISCbits.TRISC1 = 1; // RC1 = Az- input
#define AZ_DEC  PORTCbits.RC1
//TRISCbits.TRISC2 = 1; // RC2 = Alt+ input
#define ALT_INC PORTCbits.RC2
//TRISCbits.TRISC6 = 1; // RC6 = Alt- input 
#define ALT_DEC PORTCbits.RC6
//TRISAbits.TRISA2 = 0; // RA2 = AltLim+ output
#define ALT_LIM_P PORTAbits.RA2
//TRISAbits.TRISA4 = 0; // RA4 = AltLim- output
#define ALT_LIM_N PORTAbits.RA4
//TRISAbits.TRISA5 = 0; // RA5 = AzLim+ output
#define AZ_LIM_P PORTAbits.RA5
//TRISCbits.TRISC7 = 0; // RC7 = AzLim- output
#define AZ_LIM_N PORTCbits.RC7

void SetAltVal(char val)
{
    PWM1DCH = (val>>2);
    PWM1DCL = (val<<6);
}

void SetAzVal(char val)
{
    PWM2DCH = (val>>2);
    PWM2DCL = (val<<6);
}

void init()
{
    //set the main oscillator to 2 MHz
    OSCCON = 0b01100011;
    
    //	PORT C Assignments
    TRISCbits.TRISC0 = 1; // RC0 = Az+ input
    TRISCbits.TRISC1 = 1; // RC1 = Az- input
    TRISCbits.TRISC2 = 1; // RC2 = Alt+ input
    TRISCbits.TRISC3 = 0; // RC3 = PWM2 output
    TRISCbits.TRISC4 = 0; // RC4 = LED, output
    TRISCbits.TRISC5 = 0; // RC5 = PWM1 output
    TRISCbits.TRISC6 = 1; // RC6 = Alt- input
    TRISCbits.TRISC7 = 0; // RC7 = AzLim- output
    ANSELCbits.ANSELC = 0b00000000;
    
    // PORT A Assignments
    TRISAbits.TRISA2 = 0; // RA2 = AltLim+ output
    TRISAbits.TRISA4 = 0; // RA4 = AltLim- output
    TRISAbits.TRISA5 = 0; // RA5 = AzLim+ output
    
    ANSELAbits.ANSELA = 0b00000000;
    
    // PWM basis
    T2CON = 0x07; // prescaler + turn on TMR2;
    PR2 = 0x9B;
    
    // set the 1st PWM [ALT]
    PWM1CON = 0b11010000;
    PWM1DCH = 0; // set duty MSB
    PWM1DCL = 0b00000000; // duty lowest bits
    // set the alt to 90 degrees
    SetAltVal(ALT_90);
    
    
    // set the 2nd PWM [AZ]
    PWM2CON = 0b11010000;
    PWM2DCH = 0; // set duty MSB
    PWM2DCL = 0b00000000; // duty lowest bits
    // set the az value to not moving
    SetAzVal(AZ_NEUT);

    // init the UART
    sci_Init(0, 0);
}




 
/// NOTES:
///    Top Servo [SEROV 1] - high bits are: 0x04 - 0x0B
///                FINAL: 0x10 (90 deg) - 2C (0 deg)
///    Bot Servo [SERVO 2] - high bits are: 0x00 (stop), 0x0C for slow CCW, 
///                 0x0B for slow CW
///                 -- 2C --> 2F(0) | 30(!=0)
///                 FINAL: 2D(CW) 2F(0) 30(CCW)

void PrintStrToUART(char* str, unsigned char len)
{
    unsigned char ii;
    for( ii = 0; ii < len; ii++)
    {
        putch(str[ii]);
        
        if( (str[ii] == '\0') || (str[ii] == '\r') )
            break;
    }
}

void main(void) 
{
    char altDir = 0;
    char azDir = 0;
    char wasMove = 0;
    char altVal = ALT_90;
    char str[20];
    char azstr[3] = "  ";
    
    
    init();
    PORTCbits.RC4 = 1;
    __delay_ms(1000);
    PORTCbits.RC4 = 0;
    
    while(1)
    {
        // set values to zero
        wasMove = 0;
        altDir = 0;
        azDir = 0;
        
        ALT_LIM_P = 0;
        ALT_LIM_N = 0;
        AZ_LIM_P = 0;
        AZ_LIM_N = 0;
        
        // ---- poll the inputs -----
        if( ALT_INC != 0 ) 
            altDir++;
        if( ALT_DEC != 0 ) 
            altDir--;
        if( AZ_INC != 0 ) 
            azDir++;
        if( AZ_DEC != 0 ) 
            azDir--;
        
        // set move
        if( (azDir != 0) || (altDir != 0) )
            wasMove = 1;
        
        // now check to see if it was an alt move
        switch( altDir )
        {
            case 1:
                // need to decrement the alt to go up
                // since the higher value is mapped to
                // a lower angle
                if( altVal > ALT_LO_LIM)
                    altVal--;
                break;

            case -1:
                if( altVal < ALT_UP_LIM)
                    altVal++;
                break;
            default:
                // do nothing
                break;
        }
        
        // set the new alt value
        SetAltVal(altVal);
        
        if( altVal <= ALT_LO_LIM)
            ALT_LIM_N = 1;
        else
            ALT_LIM_N = 0;
        
        if( altVal >= ALT_UP_LIM )
            ALT_LIM_P = 1;
        else
            ALT_LIM_P = 0;
        
        // check to see if we have an az move
        switch( azDir )
        {
            case 1:
                SetAzVal(AZ_CW);
                break;
            case -1:
                SetAzVal(AZ_CCW);
                break;
            default:
                // don't move
                SetAzVal(AZ_NEUT);
                break;
        }
        
        // if the az is moving, we need
        // to delay and then shut it off
        if( azDir != 0 )
        {
            __delay_ms(40);
            SetAzVal(AZ_NEUT);
        }
        
        // check to see if we updated the positing
        if( wasMove != 0 )
        {
            if( (azDir != 1) && (azDir != 0))
                azstr[0] = '-';
            else
                azstr[0] = ' ';
            
            if( azDir != 0)
                azstr[1] = '1';
            else
                azstr[1] = '0';
            
            sprintf(str, "Alt: 0x%02X Az: %s \n\r", altVal, azstr );
            PrintStrToUART(str, 20);
        }
        
        // delay for 1000 ms and repoll
        __delay_ms(1000);
    }
    return;
}


