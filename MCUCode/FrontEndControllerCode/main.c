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

void init()
{
    // OSCON setup
    OSCCONbits.IRCF = 0b00001101; // 4 MHz
    
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
    
    sci_Init(0,0);
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
 
    int a = 0;
    int b = 0;
    char str[20];
    
    init();
    
    PORTEbits.RE0 = 1;
    
    while(1)
    {
        //a++;
        //b--;
    
       PORTEbits.RE0 = ~PORTEbits.RE0;
       a++;
       sprintf(str, "Alt: Az: 0x%02X\n\r", a);
       PrintStrToUART(str, 20);
        __delay_ms(1000);
    }
    return;
}
