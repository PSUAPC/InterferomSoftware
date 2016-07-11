#define _SUPPRESS_PLIB_WARNING 

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <xc.h>
#include <p32xxxx.h>
#include "W5100.h"
#include "delay.h"
#if USING_SPI
#include "SPICOMM.h"
#endif


#define ER(c) if(c) return 1;

// --------------------- Basic Function ------------------------
#if (ENABLE_TCP || ENABLE_UDP || ENABLE_MULTI)

uchar W5100WriteData(uint16 address, uchar data, uchar retry)
{
#if USING_SPI
    // SPI Communications
    uchar addr1 = (address & 0xFF00) >> 8;
    uchar addr2 = (address & 0x00FF);

    uchar erno[4];

    // enable the chip
    SS_PIN = 0;

    // write flag
    SPIWrite(0xF0);

    // write the address
    erno[0] = SPIWrite(addr1);
    erno[1] = SPIWrite(addr2);

    // write the data
    erno[2] = SPIWrite(data);

    // write extra data to push the byte
    erno[3] = SPIWrite(data);

    // disable the chip
    SS_PIN = 1;

    // let the write cycle go
    delay_millis(1);
    
    // check for errors
    if( (erno[0] != 0x00) ||
        (erno[1] != 0x01) ||
        (erno[2] != 0x02) ||
        (erno[3] != 0x03) )
    {
        // failure
        if( retry != 0)
        {
            uchar try = 0;
            for( try = 0; try < retry; try++ )
            {
                if( !W5100WriteData(address, data, 0))
                    return 0;
            }
        }
        return 1;
    }
    else
    {
        // success
        return 0;
    }
#else
    // set the data pins as output
    SET_OUT;
    
    // Parallel Communications
    // (1) set the address
    P_WrA_Reg(address);
    // (2) Delay by t>7ns 
    ShortDelay_20ns;
    // (3) Select the Chip
    P_CS_BitL;
    // (4) set the data
    P_WrD_Reg(data);
    // (5) hold write low
    P_Wr_BitL;
    // (6) delay for 1us
    ShortDelay_80ns;
    // (7) bring write high
    P_Wr_BitH;
    // (8) bring the CS high
    P_CS_BitH;
    
    return 1;
#endif

}

uchar W5100ReadData(uint16 address, uchar *data, uchar retry)
{

#if USING_SPI
    // SPI Communications

    uchar addr1 = (address & 0xFF00) >> 8;
    uchar addr2 = (address & 0x00FF);

    uchar erno[3];
    
    
    // enable the chip
    SS_PIN = 0;

    // read flag
    SPIWrite(0x0F);

    // write the address
    erno[0] = SPIWrite(addr1);
    erno[1] = SPIWrite(addr2);

    // read the data
    erno[2] = SPIRead();

    // read an extra data to push the byte
    *data = SPIRead();

    // disable the chip
    SS_PIN = 1;

    // let the write cycle go
    delay_millis(1);

    // check for errors
    if( (erno[0] != 0x00) ||
        (erno[1] != 0x01) ||
        (erno[2] != 0x02) )
    {
        uchar try = 0;
        // failure
        if( retry != 0)
        {
            for( try = 0; try < retry; try++ )
            {
                if( !W5100ReadData(address, data, 0))
                    return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
#else
    // Parallel Communications
    
    TRISE;
    // set the data pins as input
    SET_IN;
    
    TRISE;
    
    
    // (1) set the address
    P_WrA_Reg(address);
    // (2) delay for t>7ns
    ShortDelay_20ns;
    // (3) lower chip select
    P_CS_BitL;
    // (4) hold read low
    P_Rd_BitL;
    // (5) wait for 100ns
    ShortDelay_100ns;
    // (6) Read the data
    *data = P_RdD_Reg;
    // (7) bring read high
    P_Rd_BitH;
    // (8) bring the CS high
    P_CS_BitH;
    
    return 1;
#endif

}

uchar W5100ReadData16(uint16 address, uint16 *data, uchar retry)
{
    // due to eddianness, we have [LSB MSB]
    // the W5100 is [MSB LSB]
    uchar temp = 0;
    W5100ReadData(address, &temp, retry);
    *data = temp << 8;
    W5100ReadData(address + 1, &temp, retry);
    *data += temp;

    return 0;
}

uchar W5100ReadDataU(uint16 startAddr, uchar* buff, uint16 len, uchar retry)
{
    uint16 addr;
    uchar temp;
    for( addr = 0; addr < len; addr++ )
    {
        // read the address
        if( W5100ReadData(startAddr + addr, &temp, retry) )
            return 1;

        // copy the data
        memcpy(buff + addr, &temp, 1);
    }

    return 0;
}

uchar W5100WriteDataU(uint16 startAddr, uchar* buff, uint16 len, uchar retry)
{
    uint16 addr;
    uchar temp;
    for( addr = 0; addr < len; addr++ )
    {
        // set the data val
        memcpy(&temp, buff + addr, 1);

        // read the address
        if( W5100WriteData(startAddr + addr, temp, retry) )
            return 1;
    }

    return 0;
}

inline uint16 Mem2Uint(uint8 mem)
{
    switch( mem )
    {
        case MEM_1K:
            return 1024;
            break;
        case MEM_2K:
            return 2*1024;
            break;
        case MEM_4K:
            return 4*1024;
            break;
        case MEM_8K:
            return 8*1024;
            break;
    }

    return 0;
}

uchar W5100Init(struct W5100Context_t *context)
{ 
    uchar temp;
    // ------------- BASIC INFO ----------------

    // Mode
    W5100WriteData(MR, context->Mode, RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // Interrupt Mask
    W5100WriteData(IMR, context->InterruptMask, RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // Retry Time
    W5100WriteData(RTR0, (context->RetryTimeValue & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(RTR1, context->RetryTimeValue & 0x00FF, RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // Retry Count
    W5100WriteData(RCR, context->RetryCount, RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // ------------- NETWORK INFO -----------------

    // Gateway Address
    W5100WriteData(GAR0, context->GateAdd[0], RETRY_NUM);
    W5100WriteData(GAR1, context->GateAdd[1], RETRY_NUM);
    W5100WriteData(GAR2, context->GateAdd[2], RETRY_NUM);
    W5100WriteData(GAR3, context->GateAdd[3], RETRY_NUM);
    
    // let things settle
    ShortDelay_ms(1);
    
    // Source Hardware Address
    W5100WriteData(SHAR0, context->SHardAdd[0], RETRY_NUM);
    W5100WriteData(SHAR1, context->SHardAdd[1], RETRY_NUM);
    W5100WriteData(SHAR2, context->SHardAdd[2], RETRY_NUM);
    W5100WriteData(SHAR3, context->SHardAdd[3], RETRY_NUM);
    W5100WriteData(SHAR4, context->SHardAdd[4], RETRY_NUM);
    W5100WriteData(SHAR5, context->SHardAdd[5], RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // Subnet Mask
    W5100WriteData(SUBR0, context->Subnet[0], RETRY_NUM);
    W5100WriteData(SUBR1, context->Subnet[1], RETRY_NUM);
    W5100WriteData(SUBR2, context->Subnet[2], RETRY_NUM);
    W5100WriteData(SUBR3, context->Subnet[3], RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // Source IP Address
    W5100WriteData(SIPR0, context->SourceIP[0], RETRY_NUM);
    W5100WriteData(SIPR1, context->SourceIP[1], RETRY_NUM);
    W5100WriteData(SIPR2, context->SourceIP[2], RETRY_NUM);
    W5100WriteData(SIPR3, context->SourceIP[3], RETRY_NUM);

    // let things settle
    ShortDelay_ms(1);
    
    // ------------- SOCKET INFO -------------------
    
    // Socket Memory
    temp = SOC_MEM(0, context->sockets[0].Mem);
    temp |= SOC_MEM(1, context->sockets[1].Mem);
    temp |= SOC_MEM(2, context->sockets[2].Mem);
    temp |= SOC_MEM(3, context->sockets[3].Mem);

    W5100WriteData(RMSR, temp, RETRY_NUM);
    W5100WriteData(TMSR, temp, RETRY_NUM);

    // set the socket memory addresses
    // do the base one first
    context->sockets[0].RXBase = 0x6000;
    context->sockets[0].TXBase = 0x4000;
    context->sockets[0].RXMask = Mem2Uint(context->sockets[0].Mem) - 1;
    context->sockets[0].TXMask = Mem2Uint(context->sockets[0].Mem) - 1;

    for(temp = 1; temp < 4; temp++)
    {
        context->sockets[temp].RXBase = context->sockets[temp-1].RXBase \
                                      + context->sockets[temp-1].RXMask + 1;
        context->sockets[temp].TXBase = context->sockets[temp-1].TXBase \
                                      + context->sockets[temp-1].TXMask + 1;

        context->sockets[temp].RXMask = Mem2Uint(context->sockets[temp].Mem) - 1;
        context->sockets[temp].TXMask = Mem2Uint(context->sockets[temp].Mem) - 1;

    }

    return 0;
}

uchar W5100Close(struct W5100Context_t *context, uchar socket)
{
    // close the socket
    W5100WriteData(S_CR(socket), S_CLOSE, RETRY_NUM);

    // Set the socket mode in the context to null
    context->sockets[socket].Mode = 0;

    return 0;
}

// return the status
uchar W5100PollStatus(struct W5100Context_t *context, uchar socket)
{
    uchar stat = 0;

    // read the status bits
    W5100ReadData(S_SR(socket), &stat, RETRY_NUM);

    return stat;
}
uint16 W5100GetRXBufLen(uchar socket)
{
    uint16 size = 0;

    // read the uint16 value
    W5100ReadData16(S_RX_RSR0(socket), &size, RETRY_NUM);

    return size;
}

void WaitForIdle(uchar socket)
{
    uchar status = 0;
    do{

        W5100ReadData( S_CR(socket), &status, RETRY_NUM);
    }while( status != 0x00 );
}
#endif

// --------- TCP Functions -----------------
#if ENABLE_TCP

uchar W5100SetTCP(struct W5100Context_t *context, uchar socket, uint16 port)
{
    uchar temp;

    // Set the socket mode in the context to null
    context->sockets[socket].Mode = 0;

    // Set TCP mode
    W5100WriteData(S_MR(socket), S_MR_TCP, RETRY_NUM);

    // set the source port
    W5100WriteData(S_PORT0(socket), (port & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_PORT1(socket), port & 0x00FF, RETRY_NUM);

    // lets send the open command
    W5100WriteData(S_CR(socket), S_OPEN, RETRY_NUM);

    // verify that we succeded
    W5100ReadData(S_SR(socket), &temp, RETRY_NUM);

    if( temp != SOCK_INIT )
    {
        // close the socket and return failure
        W5100WriteData(S_CR(socket), S_CLOSE, RETRY_NUM);
        return 1;
    }

    // Set the socket mode in the context to TCP
    context->sockets[socket].Mode = S_MR_TCP;

    // return success
    return 0;

}

uchar W5100Connect(struct W5100Context_t *context, uchar socket, uint16 port,
                     uchar IP0, uchar IP1, uchar IP2, uchar IP3)
{
    uchar temp;

    // write the IP
    W5100WriteData(S_DIPR0(socket), IP0, RETRY_NUM);
    W5100WriteData(S_DIPR1(socket), IP1, RETRY_NUM);
    W5100WriteData(S_DIPR2(socket), IP2, RETRY_NUM);
    W5100WriteData(S_DIPR3(socket), IP3, RETRY_NUM);

    // write the port
    W5100WriteData(S_DPORT0(socket), (port & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_DPORT1(socket), port & 0x00FF, RETRY_NUM);

    // send the connect command
    W5100WriteData(S_CR(socket), S_CONNECT, RETRY_NUM);

    // check for connection established
    W5100ReadData(S_SR(socket), &temp, RETRY_NUM);

    if( temp == SOCK_ESTABLISH )
        return 0;

    // check for timeout
    delay_millis(10);
    W5100ReadData(S_SR(socket), &temp, RETRY_NUM);

    if( temp == SOCK_CLOSED )
    {
        // Set the socket mode in the context to null
        context->sockets[socket].Mode = 0;
        return 1;
    }
    // success
    return 0;
}
uchar W5100Disconnect(struct W5100Context_t *context, uchar socket)
{
    W5100WriteData(S_CR(socket), S_DISCON, RETRY_NUM);

    return W5100Close(context, socket);
}
uchar W5100Listen(struct W5100Context_t *context, uchar socket)
{
    uchar temp;

    // try starting the listen
    W5100WriteData(S_CR(socket), S_LISTEN, RETRY_NUM);

    delay_millis(100);

    // get the socket status
    W5100ReadData(S_SR(socket), &temp, RETRY_NUM);

    if( temp != SOCK_LISTEN)
    {
        // close the socket and return failure
        W5100WriteData(S_CR(socket), S_CLOSE, RETRY_NUM);
        context->sockets[socket].Mode = 0;

        return 1;
    }

    return 0;
}

uint16 W5100RecvTCP(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len)
{
    uint16 size = 0;
    uint16 offset = 0;
    uint16 startAddr = 0;
    uint16 RXrd0 = 0;
    uint16 RXMask = context->sockets[socket].RXMask;
    uint16 RXBase = context->sockets[socket].RXBase;
    
    // check to make sure the socket is idle
    WaitForIdle(socket);

    // get the size (read the data directly to save function calls)
    size = 0;
    W5100ReadData16(S_RX_RSR0(socket), &size , RETRY_NUM);


    // get the offset
    W5100ReadData16(S_RX_RD0(socket), &RXrd0, RETRY_NUM);
    offset = RXrd0 & (RXMask);

    // get the start address
    startAddr = RXBase + offset;


    // now we need to cap the read size
    if( size > len )
        size = len;
    
    // check for memory overflow
    if( (offset + size) > (RXMask + 1) )
    {
        uint16 upperSize;
        uint16 leftSize;

        // coppy the uper size bytes
        upperSize = (RXMask + 1) - offset;
        W5100ReadDataU(startAddr, buff, upperSize, RETRY_NUM);

        // copy the left size bytes
        leftSize = size - upperSize;
        W5100ReadDataU(RXBase, buff + upperSize, leftSize, RETRY_NUM);

    }
    else
    {
        W5100ReadDataU(startAddr, buff, size, RETRY_NUM);
    }

    // obtain the new read pointer (use startAddr since it is no longer needed)
    //W5100ReadData16(S_RX_RSR0(socket), &startAddr, RETRY_NUM);
    RXrd0 = RXrd0 + size; // We must hold size to return

    // rewrite the size variable
    W5100WriteData(S_RX_RD0(socket), (RXrd0&0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_RX_RD1(socket), RXrd0&0x00FF, RETRY_NUM);

    // set the RECV command
    W5100WriteData(S_CR(socket), S_RECV, RETRY_NUM);

    // clear the interrupt
    W5100WriteData(S_IR(socket), S_IR_RECV, RETRY_NUM);

    WaitForIdle(socket);
    
    return size;
}
uint16 W5100SendTCP(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len)
{
    uint16 size = 0;
    uint16 offset = 0;
    uint16 startAddr = 0;
    uint16 TXwr0 = 0;
    uint16 TXMask = context->sockets[socket].TXMask;
    uint16 TXBase = context->sockets[socket].TXBase;

    // check to make sure the socket is idle
     WaitForIdle(socket);

    // get the free size in the TX buffer
    W5100ReadData16(S_TX_FSR0(socket), &size, RETRY_NUM);

    if( size < len )
        return 0; // send data is too large to fit in the TX buffer

    // calculate the offset
    W5100ReadData16(S_TX_WR0(socket), &TXwr0, RETRY_NUM);
    offset = TXwr0 & TXMask;

    // calculate the start address
    startAddr = TXBase + offset;

    // check for socket TX memory overflow
    if( (offset + len) > (TXMask + 1) )
    {
        uint16 upperSize;
        uint16 leftSize;

        // compute the upper size
        upperSize = (TXMask +1) - offset;
        W5100WriteDataU(startAddr, buff, upperSize, RETRY_NUM);

        // copy the remainder
        leftSize = len - upperSize;
        W5100WriteDataU(TXBase, buff + upperSize, leftSize, RETRY_NUM);

    }
    else
    {
        // write the data
        W5100WriteDataU(startAddr, buff, len, RETRY_NUM);
    }

    // update the TX WR pointer
    //W5100ReadData16(S_TX_WR0(socket), &size, RETRY_NUM);
    TXwr0 = TXwr0 + len;

    // rewrite the size variable
    W5100WriteData(S_TX_WR0(socket), (TXwr0&0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_TX_WR1(socket), TXwr0&0x00FF, RETRY_NUM);

    // set the SEND command
    W5100WriteData(S_CR(socket), S_SEND, RETRY_NUM);

    return len;
}

#endif

// --------- UDP Function ------------------
#if (ENABLE_UDP || ENABLE_MULTI)
uchar W5100SetUDP(struct W5100Context_t *context, uchar socket, uint16 port)
{
    uchar temp;

    // Set the socket mode in the context to null
    context->sockets[socket].Mode = 0;

    // Set UDP mode
    W5100WriteData(S_MR(socket), S_MR_UDP, RETRY_NUM);

    // set the source port
    W5100WriteData(S_PORT0(socket), (port & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_PORT1(socket), port & 0x00FF, RETRY_NUM);

    // lets send the open command
    W5100WriteData(S_CR(socket), S_OPEN, RETRY_NUM);

    // verify that we succeded
    W5100ReadData(S_SR(socket), &temp, RETRY_NUM);

    if( temp != SOCK_UDP )
    {
        // close the socket and return failure
        W5100WriteData(S_CR(socket), S_CLOSE, RETRY_NUM);
        return 1;
    }

    // Set the socket mode in the context to UDP
    context->sockets[socket].Mode = S_MR_UDP;
    
    // return success
    return 0;
}

uint16 W5100RecvUDP(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len)
{
    uint16 size = 0;
    uint16 offset = 0;
    uint16 startAddr = 0;
    uint16 RXrd0 = 0;
    uchar  header[UDP_HEADER];
    uint16 RXMask = context->sockets[socket].RXMask;
    uint16 RXBase = context->sockets[socket].RXBase;

    // check to make sure the socket is idle
    WaitForIdle(socket);

    // get the size (read the data directly to save function calls)
    W5100ReadData16(S_RX_RSR0(socket), &size, RETRY_NUM);

    // get the offset
    W5100ReadData16(S_RX_RD0(socket), &RXrd0, RETRY_NUM);
    offset = RXrd0 & (RXMask);

    // get the start address
    startAddr = (RXBase) + offset;

    // check for overflow condition
    if( (offset + UDP_HEADER) > (RXMask + 1) )
    {
        uint16 upperSize;
        uint16 leftSize;

        // coppy the uper size bytes
        upperSize = (RXMask + 1) - offset;
        W5100ReadDataU(startAddr, header, upperSize, RETRY_NUM);

        // copy the left size bytes
        leftSize = UDP_HEADER - upperSize;
        W5100ReadDataU(RXBase, header + upperSize, leftSize, RETRY_NUM);

        // update the offset
        offset = leftSize;

    }
    else
    {
        // copy the header bytes to the header
        W5100ReadDataU(startAddr, header, UDP_HEADER, RETRY_NUM);

        offset += UDP_HEADER;
    }

    // update the start address
    startAddr = (RXBase) + offset;

    // We now have a header with the following data
    // Peer IP [0 to 3]
    // Peer Port [4 to 5]
    // size [6 to 7]
    memcpy(&size, header + 6, 2);

    // verify that the size is not larger than the memory in the socket
    if( (size == 0) || (size >  Mem2Uint(context->sockets[socket].Mem)) )
            return 0;

    // now we need to cap the read size
    if( size > len )
        size = len;
    
    // check for overflow again
    if( (offset + size) > (RXMask + 1) )
    {
        uint16 upperSize;
        uint16 leftSize;

        // coppy the uper size bytes
        upperSize = (RXMask + 1) - offset;
        W5100ReadDataU(startAddr, buff, upperSize, RETRY_NUM);

        // copy the left size bytes
        leftSize = size - upperSize;
        W5100ReadDataU(RXBase, buff + upperSize, leftSize, RETRY_NUM);

    }
    else
    {
        W5100ReadDataU(startAddr, buff, size, RETRY_NUM);
    }

    // obtain the new read pointer (use startAddr since it is no longer needed)
    //W5100ReadData16(S_RX_RSR0(socket), &startAddr, RETRY_NUM);
    RXrd0 = RXrd0 + size + UDP_HEADER; // We must hold size to return

    // rewrite the size variable
    W5100WriteData(S_RX_RD0(socket), (RXrd0&0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_RX_RD1(socket), RXrd0&0x00FF, RETRY_NUM);

    // set the RECV command
    W5100WriteData(S_CR(socket), S_RECV, RETRY_NUM);

    return size;
}
uint16 W5100SendUDP(struct W5100Context_t *context, uchar socket, uchar port, uchar IP0,
                    uchar IP1, uchar IP2, uchar IP3, uchar* buff, uint16 len)
{
    // set the destination port
    W5100WriteData(S_DPORT0(socket), (port & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_DPORT1(socket), port & 0x00FF, RETRY_NUM);

    // set the destination ip
    W5100WriteData(S_DIPR0(socket), IP0, RETRY_NUM);
    W5100WriteData(S_DIPR1(socket), IP1, RETRY_NUM);
    W5100WriteData(S_DIPR2(socket), IP2, RETRY_NUM);
    W5100WriteData(S_DIPR3(socket), IP3, RETRY_NUM);

    // this function contains the rest of the UDP send protocol
    return W5100SendMutli(context, socket, buff, len);
}

uint16 W5100SendMutli(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len)
{
    uint16 size = 0;
    uint16 offset = 0;
    uint16 startAddr = 0;
    uint16 TXwr0 = 0;
    uint16 TXMask = context->sockets[socket].TXMask;
    uint16 TXBase = context->sockets[socket].TXBase;

    // check to make sure the socket is idle
    WaitForIdle(socket);

    // get the free size in the TX buffer
    W5100ReadData16(S_TX_FSR0(socket), &size, RETRY_NUM);

    if( size < len )
        return 0; // send data is too large to fit in the TX buffer

    // calculate the offset
    W5100ReadData16(S_TX_WR0(socket), &TXwr0, RETRY_NUM);
    offset = TXwr0 & TXMask;

    // calculate the start address
    startAddr = TXBase + offset;

    // check for socket TX memory overflow
    if( (offset + len) > (TXMask + 1) )
    {
        uint16 upperSize;
        uint16 leftSize;

        // compute the upper size
        upperSize = (TXMask +1) - offset;
        W5100WriteDataU(startAddr, buff, upperSize, RETRY_NUM);

        // copy the remainder
        leftSize = len - upperSize;
        W5100WriteDataU(TXBase, buff + upperSize, leftSize, RETRY_NUM);

    }
    else
    {
        // write the data
        W5100WriteDataU(startAddr, buff, len, RETRY_NUM);
    }

    // update the TX WR pointer
    //W5100ReadData16(S_TX_WR0(socket), &size, RETRY_NUM);
    TXwr0 = TXwr0 + len; // We must hold size to return

    // rewrite the size variable
    W5100WriteData(S_TX_WR0(socket), (TXwr0&0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_TX_WR1(socket), TXwr0&0x00FF, RETRY_NUM);

    // set the SEND command
    W5100WriteData(S_CR(socket), S_SEND, RETRY_NUM);

    return len;
}

#endif

// --------- MultiCast Function ------------
#if ENABLE_MULTI
uchar W5100SetMulti(struct W5100Context_t *context, uchar socket, uint16 port,
                    uchar IP0, uchar IP1, uchar IP2, uchar IP3)
{
    uchar temp;

    // Set the socket mode in the context to null
    context->sockets[socket].Mode = 0;
    
    // Set UDP Multicast mode
    W5100WriteData(S_MR(socket), S_MR_UDP | S_MR_MULTI, RETRY_NUM);

    // set the source port
    W5100WriteData(S_PORT0(socket), (port & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_PORT1(socket), port & 0x00FF, RETRY_NUM);

    // set the destination port
    W5100WriteData(S_DPORT0(socket), (port & 0xFF00) >> 8, RETRY_NUM);
    W5100WriteData(S_DPORT1(socket), port & 0x00FF, RETRY_NUM);

    // set the destination ip
    W5100WriteData(S_DIPR0(socket), IP0, RETRY_NUM);
    W5100WriteData(S_DIPR1(socket), IP1, RETRY_NUM);
    W5100WriteData(S_DIPR2(socket), IP2, RETRY_NUM);
    W5100WriteData(S_DIPR3(socket), IP3, RETRY_NUM);

    // lets send the open command
    W5100WriteData(S_CR(socket), S_OPEN, RETRY_NUM);

    // verify that we succeded
    W5100ReadData(S_SR(socket), &temp, RETRY_NUM);

    if( temp != SOCK_UDP )
    {
        // close the socket and return failure
        W5100WriteData(S_CR(socket), S_CLOSE, RETRY_NUM);
        return 1;
    }

    // Set the socket mode in the context to UDP Multi
    context->sockets[socket].Mode = S_MR_UDP | S_MR_MULTI;

    // return success
    return 0;
}

uint16 W5100RecvMulti(struct W5100Context_t *context, uchar socket, uchar* buff, uint16 len)
{
    // the reading functionality is entirely in the UDP function
    return W5100RecvUDP(context, socket, buff, len);
}


#endif




