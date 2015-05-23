/* 
 * File:   SPICOMM.h
 * Author: Owner
 *
 * Created on January 17, 2015, 6:46 PM
 */

#ifndef SPICOMM_H
#define	SPICOMM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Types.h"

// ---------------------------------
//         A Few Definitions
// ---------------------------------

#define SPICOMM_BITS SPI2CONbits
#define SPICOMM_BUFF SPI2BUF
#define SPICOMM_BRG  SPI2BRG
#define SPICOMM_STAT SPI2STATbits

// ---------------------------------
//         Utility Functions
// ---------------------------------

uchar InitSPI(uint baud);
uchar SPIWrite (uchar c);
uchar SPIRead (void);


#ifdef	__cplusplus
}
#endif

#endif	/* SPICOMM_H */

