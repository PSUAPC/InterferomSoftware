/* 
 * File:   newmain.c
 * Author: Owner
 *
 * Created on April 11, 2015, 4:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <xc.h>
#include <p32xxxx.h>
#include "delay.h"
//#include "W5100.h"
//#include "SPICOMM.h"
//#include "TPM/Astro.h"

// DEVCFG3
// USERID = No Setting
#pragma config FSRSSEL = PRIORITY_7     // SRS Select (SRS Priority 7)
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config FCANIO = ON              // CAN I/O Pin Select (Default CAN I/O)
#pragma config FUSBIDIO = ON            // USB USID Selection (Controlled by the USB Module)
#pragma config FVBUSONIO = ON           // USB VBUS ON Selection (Controlled by USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_2         // USB PLL Input Divider (2x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (PLL Divide by 2)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = XT             // Primary Oscillator Configuration (XT osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_4           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/4)
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
#define _XTAL_FREQ  2000000        // this is used by the __delay_ms(xx) and __delay_us(xx) functions
#define GetSystemClock()       (20000000ul)
#define GetPeripheralClock()    (GetSystemClock())
int main(int argc, char** argv) {

    mPORTAClearBits(BIT_6);           //Clear bits to ensure the LED is off.
    mPORTASetPinsDigitalOut(BIT_6);   //Set port as output
  
     while(1)
     {
        //PORTAbits.RA2 = ~PORTAbits.RA2;
        mPORTAToggleBits(BIT_6);
         delay_millis(100);
     }
     
    return (EXIT_SUCCESS);
}

