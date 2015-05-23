
#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <xc.h>
#include <p32xxxx.h>
#include "SPICOMM.h"


// ---------------------------------
//         Utility Functions
// ---------------------------------

uchar InitSPI(uint baud)
{
    uchar dummy;

    SPICOMM_BITS.ON      = 0;        // disable SPI to reset any previous state
    dummy                = SPICOMM_BUFF;  // clear receive buffer
    SPICOMM_BRG          = PBCLK_FREQUENCY / (16 *(  baud - 1 ) );
    SPICOMM_BITS.MSTEN   = 1;        // enable master mode
    SPICOMM_BITS.CKE     = 1;        // set clock-to-data timing
    SPICOMM_BITS.CKP     = 0;            //SPI Clock Edge Select bit
    SPICOMM_BITS.ON      = 1;        // turn SPI on

    return 1;
}

uchar SPIWrite (uchar c)
{
    while (SPICOMM_STAT.SPIBUSY);
    SPICOMM_BUFF = c;                   // send data to slave
    while (SPICOMM_STAT.SPIBUSY);  // wait until SPI transmission complete
    c = SPICOMM_BUFF;
    return c;
}

uchar SPIRead (void)
{
    return SPIWrite (0);
}
