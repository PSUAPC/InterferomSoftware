/* 
 * File:   newmain.c
 * Author: Owner
 *
 * Created on April 11, 2015, 4:24 PM
 */
#define _SUPPRESS_PLIB_WARNING 
#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <xc.h>
#include <p32xxxx.h>
#include "delay.h"
#include "W5100.h"
//#include "W5100.h"
//#include "SPICOMM.h"
//#include "TPM/Astro.h"

// DEVCFG3
// USERID = No Setting
#pragma config FSRSSEL = PRIORITY_7     // SRS Select (SRS Priority 7)
#pragma config FMIIEN = OFF              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = OFF              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config FCANIO = ON              // CAN I/O Pin Select (Default CAN I/O)
#pragma config FUSBIDIO = OFF            // USB USID Selection (Controlled by the USB Module)
#pragma config FVBUSONIO = OFF           // USB VBUS ON Selection (Controlled by USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_2         // USB PLL Input Divider (2x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 2)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = OFF                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = XT             // Primary Oscillator Configuration (XT osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/4)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)

// DEVCFG0
#pragma config DEBUG = ON              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)            // Code Protect (Protection Disabled)
/*
 *
 */
#define _XTAL_FREQ  80000000        // this is used by the __delay_ms(xx) and __delay_us(xx) functions
#define GetSystemClock()       (80000000ul)
#define GetPeripheralClock()    (GetSystemClock())

// Ethernet Module Address RB0-15
// Ethernet Module Data RE0-7
// Ethernet Module Interrupt RE8
// Ethernet Module Write RA0 -- Active Low (now RA7 due to bodge)
// Ethernet Module Read  RG9 -- Active Low
// Ethernet Module Reset RG8 -- Active Low
// Ethernet Module CS   RG14 -- Active Low

// Aux Data RD0-15
// Aux Ctrl 0 RF0 
// Aux Ctrl 1 RF3
// Aux Ctrl 2 RF1
// Aux Ctrl 3 RG1

void EstablishServer(struct W5100Context_t *context)
{
    // create TCP socket 0 on port 1492
    W5100SetTCP( &context, 0, 1492);
    //status = W5100PollStatus(&context, 0);
    // set the socket to listen 
    W5100Listen( &context, 0 );
    //status = W5100PollStatus(&context, 0);
}


int main(int argc, char** argv) {

    uchar status = 0;
    
    mPORTAClearBits(BIT_6);           //Clear bits to ensure the LED is off.
    //mPORTASetPinsDigitalOut(BIT_6);   //Set port as output
  
    // lets set the digital IO bits for the ethernet module
    mPORTASetPinsDigitalOut(BIT_7|BIT_6);
    mPORTGSetPinsDigitalOut(BIT_8 | BIT_9 | BIT_14 | BIT_0);
    mPORTBSetPinsDigitalOut(0x0000FFFF);
    mPORTESetPinsDigitalOut(0x000000FF);
    
    // set the control bits high
    mPORTASetBits(BIT_7);
    mPORTGSetBits(BIT_8 | BIT_9 | BIT_14);
    mPORTGClearBits(BIT_0);
    //mPORTGClearBits(BIT_0);
    //mPORTGClearBits(0x0000FFFF);
    //mPORTEClearBits(0x0000FFFF);
    //mPORTAClearBits(0x0000FFFF);
    //mPORTBClearBits(0x0000FFFF);
    
    //while(1){}

    // lets init the W5100
    struct W5100Context_t context;
    context.Mode = MR_RST;
    context.InterruptMask = 0xFF;
    context.RetryTimeValue = 0x0FA0; // 400 ms
    context.RetryCount = 1;
    
    context.GateAdd[0] = 10;
    context.GateAdd[1] = 1;
    context.GateAdd[2] = 1;
    context.GateAdd[3] = 3;
    
    context.SHardAdd[0] = 0;
    context.SHardAdd[1] = 1;
    context.SHardAdd[2] = 2;
    context.SHardAdd[3] = 3;
    context.SHardAdd[4] = 4;
    context.SHardAdd[5] = 5;
    
    context.Subnet[0] = 255;
    context.Subnet[1] = 255;
    context.Subnet[2] = 255;
    context.Subnet[3] = 0;
    
    context.SourceIP[0] = 10;
    context.SourceIP[1] = 1;
    context.SourceIP[2] = 1;
    context.SourceIP[3] = 2;
    
    context.sockets[0].Mem = MEM_2K;
    context.sockets[1].Mem = MEM_2K;
    context.sockets[2].Mem = MEM_2K;
    context.sockets[3].Mem = MEM_2K;
    
    ShortDelay_ms(100);
    
    W5100Init( &context );
  
    W5100ReadData(SHAR0, &status, 1);
    W5100ReadData(SHAR1, &status, 1);
    W5100ReadData(SHAR2, &status, 1);
    W5100ReadData(SHAR3, &status, 1);
    W5100ReadData(SHAR4, &status, 1);
    W5100ReadData(SHAR5, &status, 1);
    
    EstablishServer(&context);
    
    // lets try a random write
    //W5100WriteData(0x001A, 0x07, 1);
    //mPORTEWrite(0x07);
    
    
  
    
     while(1)
     {
     
        status = W5100PollStatus(&context, 0);
        if( status == SOCK_ESTABLISH)
            mPORTGSetBits(BIT_0);
        else
            mPORTGClearBits(BIT_0);
        
        if( status == SOCK_CLOSE_WAIT)
            EstablishServer(&context);
        
        
         //PORTAbits.RA2 = ~PORTAbits.RA2;
        mPORTAToggleBits(BIT_6);
        ShortDelay(US_TO_CT_TICKS*1000000);
        //delay_millis(1000);
   
     }
     
    return (EXIT_SUCCESS);
}

