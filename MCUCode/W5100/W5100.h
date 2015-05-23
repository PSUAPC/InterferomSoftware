/* 
 * File:   W5100.h
 * Author: Owner
 *
 * Created on January 17, 2015, 2:13 AM
 */

#ifndef W5100_H
#define	W5100_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Types.h"
// ------------------------------
//       CONSTANTS
// -------------------------------
// Chip Select Pin if using SPI
#define SS_PIN          PORTBbits.RB15
#define USING_SPI       1                   /* Enables SPI instead of parallel*/
#define RETRY_NUM       4                   /* Number of SPI Retires */
// Dissabling all of the below will Disable this library
#define ENABLE_UDP      1                   /* Enables UDP Functions */
#define ENABLE_MULTI    1                   /* Enables MultiCast Functions */
#define ENABLE_TCP      1                   /* Enabled TCP Functions */
#define W5100_GLOBAL_C  1                   /* The global context */

// internally used constants
#define CH_SIZE         0x0100
#define CH_BASE         0x0400
#define UDP_HEADER      8
#define	MAX_SOCK_NUM    4

// ***************************************
// ****  R E G I S T E R    M A P S   ****
// ***************************************

// ------------------------------
//       Common Registers
// -------------------------------
// ---- MODE [R/W] -----
#define MR      0x0000
// S/W Reset (internal register init if 1)
#define MR_RST  0x80
// Ping Block Mode (1 enables Ping Block)
#define MR_PB   0x08
// PPPoE Mode (1 Enabled PPPoE)
#define MR_PPPoE 0x04
// Address Auto-Increment (1 enables Auto Increment)
#define MR_AI    0x02
// Indirect Bus I/F Mode (1 enables)
#define MR_IND   0x01
// ----- Gateway Address [R/W] ----
#define GAR0    0x0001
#define GAR1    0x0002
#define GAR2    0x0003
#define GAR3    0x0004
// ------ Subnet mask Address [R/W] -----
#define SUBR0   0x0005
#define SUBR1   0x0006
#define SUBR2   0x0007
#define SUBR3   0x0008
// ----- Source Hardware Address [R/W] -----
#define SHAR0   0x0009
#define SHAR1   0x000A
#define SHAR2   0x000B
#define SHAR3   0x000C
#define SHAR4   0x000D
#define SHAR5   0x000E
// ----- Source IP Address [R/W] -----
#define SIPR0   0x000F
#define SIPR1   0x0010
#define SIPR2   0x0011
#define SIPR3   0x0012
// ----- Interrupt [R] ------
#define IR      0x0015
// IP COnflict, set to 1 when request same address as Source IP
#define IR_CONFLICT 0x80
// Destination Unreachable (Non-existent destination IP)
#define IR_UNREACH  0x40
// PPPoE Connection Close (cleared by writing 1 to bit)
#define IR_PPPoE    0x20
// Occurence of Socket 3 Interrupt (cleared when S_IR is set to NULL)
#define IR_S3INT    0x08
#define IR_S2INT    0x04
#define IR_S1INT    0x02
#define IR_S0INT    0x01
// ----- Interrupt Mask [R/W] -----
#define IMR     0x0016
// if bit is 1, it will send an interrupt signal
#define IMR_IR7 0x80
#define IMR_IR6 0x40
#define IMR_IR5 0x20
#define IMR_IR3 0x08
#define IMR_IR2 0x04
#define IMR_IR1 0x02
#define IMR_IR0 0x01
// ----- Retry time [R/W] -----
// period of timeout, 1 means 100us (DEFAULT is 200ms)
// MSB in RTR0   
#define RTR0    0x0017
#define RTR1    0x0018
// ----- Retry Count [R/W] ------
// Number of re-transmissions before timeout set
#define RCR     0x0019
// ---- RX Memory Size [R/W] -----
// There is a maximum of 8KB to allocate
// If no memory left, the socket should not be used
// The default is 2K each
#define RMSR    0x001A
// Memory values
#define MEM_1K  0x00
#define MEM_2K  0x01
#define MEM_4K  0x02
#define MEM_8K  0x03
// Macro for sockets (s = socket, v = value)
#define SOC_MEM(s,v) (v << 2*s )
// ------- TX Memory Size [R/W] -------
// Identical to the RX Memory Allocation
#define TMSR    0x001B
// ------- Authentication Type in PPPoE [R] -----
#define PATR0   0x001C
#define PATR1   0x001D
// PAP modes (0xC023)
#define PATR_PAP0 0xC0
#define PATR_PAP1 0x23
// CHAP modes (0xC223)
#define PATR_CHAP0 0xC2
#define PATR_CHAP1 0x23
// -------- PPP LCP Request Timer [R/W] ------
// A value of 1 is 25ms
#define PTIMER  0x0028
// ------ PPP LCP Magic Number [R/W] ------
#define PMAGIC  0x0029
// ----- Unreachable IP Address [R] -------
#define UIPR0   0x002A
#define UIPR1   0x002B
#define UIPR2   0x002C
#define UIPR3   0x002D
// ------ Unreachable Port [R] -------
#define UPORT0  0x002E
#define UPORT1  0x002F

// -------------------------------
//          Socket Registers
// -------------------------------
// ------ Socket Mode [R/W] -------
#define S_MR(n)         (n*CH_SIZE + 0x0400)
// MultiCasting (1 for enable)
#define S_MR_MULTI      0x80
// Use No Delayed ACK (1 for enable)
#define S_MR_NDMC       0x20
// protocols
// - Closed
#define S_MR_CLOSED     0x00
// - TCP
#define S_MR_TCP        0x01
// - UDP
#define S_MR_UDP        0x02
// - IPRAW
#define S_MR_IPRAW      0x03
// - MACRAW (only socket 0)
#define S_MR_MACRAW     0x04
// - PPPoE (only socket 0)
#define S_MR_PPPoE      0x05
// ----- Socket Command [R/W] ---------
// this register will be set to 0x00 after executing the command
#define S_CR(n)         (n*CH_SIZE + 0x0401)
#define S_OPEN          0x01
#define S_LISTEN        0x02
#define S_CONNECT       0x04
#define S_DISCON        0x08
#define S_CLOSE         0x10
#define S_SEND          0x20
#define S_SEND_MAC      0x21
#define S_SEND_KEEP     0x22
#define S_RECV          0x40
// ------ Socket Interrupt [R] ------------
#define S_IR(n)         (n*CH_SIZE + 0x0402)
// send operation completed (1)
#define S_IR_OK         0x10
// Timeout Occured (1)
#define S_IR_TIMEOUT    0x08
// Received data or CMD_RECV command executed
#define S_IR_RECV       0x04
// Disconnect (1 for connection terminated)
#define S_IR_DISCON     0x02
// Connection (1 for established)
#define S_IR_CON        0x01
// -------- Socket Status [R] -------------
#define S_SR(n)         (n*CH_SIZE + 0x0403)
#define SOCK_CLOSED     0x00
#define SOCK_INIT       0x13
#define SOCK_LISTEN     0x14
#define SOCK_ESTABLISH  0x17
#define SOCK_CLOSE_WAIT 0x1C
#define SOCK_UDP        0x22
#define SOCK_IPRAW      0x32
#define SOCK_MACRAW     0x42
#define SOCK_PPPOE      0x5F
#define SOCK_SYNSENT    0x15
#define SOCK_SYNRECV    0x16
#define SOCK_FIN_WAIT   0x18
#define SOCK_CLOSING    0x1A
#define SOCK_TIME_WAIT  0x1B
#define SOCK_LAST_ACK   0x1D
#define SOCK_ARP0       0x11
#define SOCK_ARP1       0x21
#define SOCK_ARP2       0x31
// ------- Socket Source Port [R/W] --------
#define S_PORT0(n)      (n*CH_SIZE + 0x0404)
#define S_PORT1(n)      (n*CH_SIZE + 0x0405)
// ----- Socket Destination Hardware Address [R/W] -----
#define S_DHAR0(n)      (n*CH_SIZE + 0x0406)
#define S_DHAR1(n)      (n*CH_SIZE + 0x0407)
#define S_DHAR2(n)      (n*CH_SIZE + 0x0408)
#define S_DHAR3(n)      (n*CH_SIZE + 0x0409)
#define S_DHAR4(n)      (n*CH_SIZE + 0x040A)
#define S_DHAR5(n)      (n*CH_SIZE + 0x040B)
// ------ Socket Destination IP Address [R/W] ------
#define S_DIPR0(n)      (n*CH_SIZE + 0x040C)
#define S_DIPR1(n)      (n*CH_SIZE + 0x040D)
#define S_DIPR2(n)      (n*CH_SIZE + 0x040E)
#define S_DIPR3(n)      (n*CH_SIZE + 0x040F)
// ----- Socket Destination Port [R/W] -------
#define S_DPORT0(n)     (n*CH_SIZE + 0x0410)
#define S_DPORT1(n)     (n*CH_SIZE + 0x0411)
// ----- Socket Maximum Segment Size [R/W] ------
#define S_MSSR0(n)      (n*CH_SIZE + 0x0412)
#define S_MSSR1(n)      (n*CH_SIZE + 0x0413)
// ----- Socket Protocol IP Raw mode [R/W] ------
#define S_PROTO(n)      (n*CH_SIZE + 0x0414)
// ----- Socket IP TOS [R/W] ----------------
#define S_TOS(n)        (n*CH_SIZE + 0x0415)
// ----- Socket IP TTL [R/W] ----------------
#define S_TTL(n)        (n*CH_SIZE + 0x0416)
// ----- Socket TX Free Size [R] ------------
// Read the MSB first
#define S_TX_FSR0(n)    (n*CH_SIZE + 0x0420)
#define S_TX_FSR1(n)    (n*CH_SIZE + 0x0421)
// ----- Socket TX Read Pointer [R] ---------
#define S_TX_RD0(n)     (n*CH_SIZE + 0x0422)
#define S_TX_RD1(n)     (n*CH_SIZE + 0x0423)
// ----- Socket TX Write Pointer [R/W] -------
#define S_TX_WR0(n)     (n*CH_SIZE + 0x0424)
#define S_TX_WR1(n)     (n*CH_SIZE + 0x0425)
// ----- Socket RX Recieved Size [R] ---------
// Read MSB first 
#define S_RX_RSR0(n)    (n*CH_SIZE + 0x0426)
#define S_RX_RSR1(n)    (n*CH_SIZE + 0x0427)
// ----- Socket RX Read Pointer [R/W] -------
#define S_RX_RD0(n)     (n*CH_SIZE + 0x0428)
#define S_RX_RD1(n)     (n*CH_SIZE + 0x0429)

// -----------------------------------------
//          Device Context
// -----------------------------------------

#if (ENABLE_TCP || ENABLE_UDP || ENABLE_MULTI)

struct W5100Socket_t
{
    uchar   Mode;
    uchar   Mem;
    uint16  RXBase;
    uint16  RXMask;
    uint16  TXBase;
    uint16  TXMask;
};

struct W5100Context_t
{
    // Basic Settings
    uchar   Mode;
    uchar   InterruptMask;
    uint16  RetryTimeValue;
    uchar   RetryCount;
    // Network Info
    uchar   GateAdd[4];
    uchar   SHardAdd[6];
    uchar   Subnet[4];
    uchar   SourceIP[4];
    // Sockets
    struct W5100Socket_t sockets[4];
};

#if W5100_GLOBAL_C
struct W5100Context_t W5100Context;
#endif

#endif

// -----------------------------------------
//          Utility Functions
// -----------------------------------------

// ------------ Basic Functions -------------
#if (ENABLE_TCP || ENABLE_UDP || ENABLE_MULTI)
uchar W5100Init(struct W5100Context_t *context);
uchar W5100WriteData(uint16 address, uchar data, uchar retry);
uchar W5100ReadData(uint16 address, uchar *data, uchar retry);
uchar W5100ReadData16(uint16 address, uint16 *data, uchar retry);
uchar W5100ReadDataU(uint16 startAddr, uchar* buff, uint16 len, uchar retry);
uchar W5100WriteDataU(uint16 startAddr, uchar* buff, uint16 len, uchar retry);
// Basic Socket Functions
uchar W5100Close(struct W5100Context_t *context, uchar socket);
uchar W5100PollStatus(struct W5100Context_t *context, uchar socket);
uint16 W5100GetRXBufLen(uchar socket);
void WaitForIdle(uchar socket);

#endif

// Communication Function Notes:
// - RX Functions
//   + buff will be allocated by the function based on mem size in RX buffer
//   + The size of allocated buff will be returned (bytes read)
// - TX Functions
//   + buff is expected to be a pointer to the data to write of length len
//   + Bytes sent will be returned

// --------- TCP Functions -----------------
#if ENABLE_TCP
// Initialization
uchar W5100SetTCP(struct W5100Context_t *context, uchar socket, uint16 port);
// Server-client
uchar W5100Connect(struct W5100Context_t *context, uchar socket, uint16 port,
                     uchar IP0, uchar IP1, uchar IP2, uchar IP3);
uchar W5100Disconnect(struct W5100Context_t *context, uchar socket);
uchar W5100Listen(struct W5100Context_t *context, uchar socket);
// RX/TX
uint16 W5100ReadTCP(struct W5100Context_t *context, uchar socket, uchar** buff);
uint16 W5100SendTCP(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len);
#endif
// --------- UDP Function ------------------
// Multi requires UDP
#if (ENABLE_UDP || ENABLE_MULTI)
// Initialize
uchar W5100SetUDP(struct W5100Context_t *context, uchar socket, uint16 port);
// RX / TX
uint16 W5100ReadUDP(struct W5100Context_t *context, uchar socket, uchar** buff);
uint16 W5100SendUDP(struct W5100Context_t *context, uchar socket, uchar port, uchar IP0,
                    uchar IP1, uchar IP2, uchar IP3, uchar* buff, uint16 len);
// the base send UDP functionality is here
uint16 W5100SendMutli(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len);
#endif
// --------- MultiCast Function ------------
#if ENABLE_MULTI
// Initialize
uchar W5100SetMulti(struct W5100Context_t *context, uchar socket, uint16 port,
                    uchar IP0, uchar IP1, uchar IP2, uchar IP3);
// RX / TX
uint16 W5100ReadMulti(struct W5100Context_t *context, uchar socket, uchar** buff);
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* W5100_H */

