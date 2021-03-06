/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "LSM303DLHC.h"
#include "I2C.h"

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */

#if (MSSP_MODULE == 1) // MSSP1

#define read_i2c_reg_byte read_i2c_reg_byte1
#define write_i2c_reg_byte write_i2c_reg_byte1

#else // MSSP2

#define read_i2c_reg_byte read_i2c_reg_byte2
#define write_i2c_reg_byte write_i2c_reg_byte2

#endif


//LSM303DLHCDigitalCompass
        // ----------------------------- Register Configuration --------------------------------
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | ADDR | R/W | NAME | BIT 7 | BIT 6 | BIT 5 | BIT 4 | BIT 3 | BIT 2 | BIT 1 | BIT 0 |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x00 | R/W | CRA  | TEMPEN|   0   |   0   |        DO( 2 : 0 )    |   0   |   0   |   
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x01 | R/W | CRB  |     GN( 2 : 0 )       |   0   |   0   |   0   |   0   |   0   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x02 | R/W |  MR  |   0   |   0   |   0   |   0   |   0   |   0   |  MD( 1 : 0 )  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x03 |  R  | XMSB |                XDA( 15 : 8 )                                  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +        
        // | 0x04 |  R  | XLSB |                XDA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x05 |  R  | ZMSB |                ZDA( 15 : 8 )                                  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x06 |  R  | ZLSB |                ZDA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x07 |  R  | YMSB |                YDA( 15 : 8 )                                  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x08 |  R  | YLSB |                YDA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x09 |  R  |  SR  |   --  |   --  |   --  |   --  |   --  |   --  |  LOCK |  DRDY |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x0A |  R  | IRA  |   0   |   1   |   0   |   0   |   1   |   0   |   0   |   0   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x0B |  R  | IRB  |   0   |   0   |   1   |   1   |   0   |   1   |   0   |   0   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x0C |  R  | IRC  |   0   |   0   |   1   |   1   |   0   |   0   |   1   |   1   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x0D |  -  |                                                                      |
        // |  -   |  -  |               RESERVED (DO NOT MODIFY)                               |
        // | 0x30 |  -  |                                                                      |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x31 |  R  | TMSB |        TMP( 11 : 4 )                                          |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x32 |  R  | TLSB |        TMP( 3 : 0 )           |   --  |   --  |   --  |   --  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x33 |  -  |                                                                      |
        // |  -   |  -  |               RESERVED (DO NOT MODIFY)                               |
        // | 0x3A |  -  |                                                                      |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +

void LSM303DLHCDigitalCompass_init()
{
    uint8 cfg = 0x00;

    // ######## Write configuration data to registers ##############
    // @[0x00] (CRA) ---------------------------------------------
    cfg = 0x00; // clear the bits
    // TEMP_EN : Temperature Enable (1/0)
    cfg |= (0x01 << 7);
    // DO : Data output
    // - 0x00 for 0.75 Hz
    // - 0x01 for 1.50 Hz
    // - 0x02 for 3.00 Hz
    // - 0x03 for 7.50 Hz
    // - 0x04 for 15.0 Hz
    // - 0x05 for 30.0 Hz
    cfg |= (0x04 << 2); // set 15 Hz
    // write to the register
    write_i2c_reg_byte( magAddr, 0x00, cfg );

    // @[0x01] (CRB) ---------------------------------------------
    cfg = 0x00; // clear the bits
    // (Note* Earth's magnetic field strength is 0.25-0.65 Gauss)
    // GN : Gain Register [-2048 : 2047 ] [XY LSB/G, Z LSB/G]
    // - 0x01 for +/- 1.3 G [1100 / 980 ]
    // - 0x02 for +/- 1.9 G [ 855 / 760 ]
    // - 0x03 for +/- 2.5 G [ 670 / 600 ]
    // - 0x04 for +/- 4.0 G [ 450 / 400 ]
    // - 0x05 for +/- 4.7 G [ 400 / 355 ]
    // - 0x06 for +/- 5.6 G [ 330 / 295 ]
    // - 0x07 for +/- 8.1 G [ 230 / 205 ]
    cfg |= (0x04 << 5); // set +/- 4G
    //m_XScale = 1.0f/450.0f;
    //m_YScale = 1.0f/450.0f;
    //m_ZScale = 1.0f/400.0f;
    write_i2c_reg_byte( magAddr, 0x01, cfg );

    // @[0x02] (MR) ---------------------------------------------
    cfg = 0x00; // clear the bits
    // MD : Mode select
    // - 0x00 for continous mode
    // - 0x01 for single-conversion
    // - 0x02 for sleep-mode
    // - 0x03 for sleep-mode
    //cfg |= 0x00; // set continous mode
    write_i2c_reg_byte( magAddr, 0x02, cfg );

}

void LSM303DLHCDigitalCompass_get_tword()
{
    uint8 msb = 0;
    uint8 lsb = 0;

    read_i2c_reg_byte( magAddr, 0x31, &msb );
    read_i2c_reg_byte( magAddr, 0x32, &lsb );

    // temperature is contradictory on this device
    // according to the datasheet, it should be a 12-bit
    // value, aligned via the register table above
    // this would be as follows:
    // m_T = (short) ( (msb << 8) | lsb ) >> 4;
    // however, ST's example driver only uses the MSB 
    // effectively making it an 8-bit value.
    // this would simply be:
    // m_T = (short) msb;
    // let's go with the one that ST gives us for safety
    
    tempMag = (uint16) msb;
}

void LSM303DLHCDigitalCompass_get_xword()
{
    uint8 msb = 0;
    uint8 lsb = 0;

    read_i2c_reg_byte( magAddr, 0x03, &msb );
    read_i2c_reg_byte( magAddr, 0x04, &lsb );

    xMag = (uint16)( (msb << 8) | lsb ) / 16;
}

void LSM303DLHCDigitalCompass_get_yword()
{
    uint8 msb = 0;
    uint8 lsb = 0;

    read_i2c_reg_byte( magAddr, 0x07, &msb );
    read_i2c_reg_byte( magAddr, 0x08, &lsb );

    yMag = (uint16)( (msb << 8) | lsb ) / 16;

}

void LSM303DLHCDigitalCompass_get_zword()
{
    uint8 msb = 0;
    uint8 lsb = 0;

    read_i2c_reg_byte( magAddr, 0x05, &msb );
    read_i2c_reg_byte( magAddr, 0x06, &lsb );

    zMag = (uint16)( (msb << 8) | lsb ) / 16;
}
 

//LSM303DLHCAccelerometer
        // ----------------------------- Register Configuration --------------------------------
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | ADDR | R/W | NAME | BIT 7 | BIT 6 | BIT 5 | BIT 4 | BIT 3 | BIT 2 | BIT 1 | BIT 0 |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x00 |  -  |                                                                      |
        // |   -  |  -  |               RESERVED (DO NOT MODIFY)                               |
        // | 0x1F |  -  |                                                                      |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x20 | R/W | CTL1 |          ORD( 3 : 0 )         | LPEN  |  ZEN  |  YEN  |  XEN  | 
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x21 | R/W | CTL2 | HMP( 1 : 0 )  | HPCF2 | HPCF1 |  FDS  | HPCLK | HPIS2 | HPIS1 |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x22 | R/W | CTL3 | I1CLK | I1AO1 | I1AO2 | I1RDY1| I1RDY2| I1WTM | I1OVR |  --   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x23 | R/W | CTL4 |  BDU  |  BLE  | FS( 1: 0 )    |  HR   |   0   |   0   |  SIM  | 
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x24 | R/W | CTL5 |  BOOT | FIFEN |  --   |  --   | LIRI1 | D4DI1 | LIRI2 | D4DI2 |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +        
        // | 0x25 | R/W | CTL6 | I2CLK | I2IN1 | I2IN2 | BOOTI1| P2ACT |  --   | HLACT |   --  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x26 | R/W | REFF |                REF( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x27 |  R  | STAT | ZYXOR |  ZOR  |  YOR  |  XOR  | ZTXDA |  ZDA  |  YDA  |  XDA  | 
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x28 |  R  | xLSB |                XDA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x29 |  R  | XMSB |                XDA( 15 : 8 )                                  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x2A |  R  | YLSB |                YDA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x2B |  R  | YMSB |                YDA( 15 : 8 )                                  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x2C |  R  | ZLSB |                ZDA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x2D |  R  | ZMSB |                ZDA( 15 : 8 )                                  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x2E | R/W | FCTL |   FM( 1 : 0 ) |   TR  |        FTH( 4 : 0 )                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x2F |  R  | FSCR |  WTM  | OVRN  | EMPTY |        FSS( 4 : 0 )                   |        
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x30 | R/W | IN1C |  AOI  |   6D  | ZHIE  |  ZLIE | YHIE  | YLIE  | XHIE  | XLIE  |   
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x35 |  R  | IN2S |   0   |  IA   |  ZH   |  ZL   |  YH   |  YL   |  XH   |   XL  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x36 | R/W | IN2T |   0   |        THS( 6 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x37 | R/W | IN2D |   0   |        DIR( 6 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x38 | R/W | CLKC |   --  |  --   |   ZD  |   ZS  |   YD  |   YS  |   XD  |   XS  |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x39 | R/W | CLKS |   --  |   IA  | DCLCK | SCLCK |  SGN  |   Z   |   Y   |   X   |  
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x3A | R/W | CLKT |   --  |        THS( 6 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x3B | R/W | TLIM |   --  |        TLI( 6 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x3C | R/W | TLAT |                TLA( 7 : 0 )                                   |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x3D | R/W | TWIN |                TW( 7 : 0 )                                    |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x3E |  -  |               RESERVED (DO NOT MODIFY)                               |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | 0x3F |  -  |               RESERVED (DO NOT MODIFY)                               |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +

void LSM303DLHCAccelerometer_init()
{
    uint8 cfg = 0x00;

    // ######## Write configuration data to registers ##############
    // @[0x20] (CTRL1) ----------------------------
    cfg = 0x00;
    // ORD: Data Rate Selection (7 : 4)
    //  - 0x00 for power down
    //  - 0x01 for normal 1 Hz
    //  - 0x02 for normal 10 Hz
    //  - 0x03 for normal 25 Hz
    //  - 0x04 for normal 50 Hz
    //  - 0x05 for normal 100 Hz
    //  - 0x06 for normal 200 Hz
    //  - 0x07 for normal 400 Hz
    //  - 0x08 for low 1.629 KHz
    //  - 0x09 for normal 1.344 KHz or low 5.376 KHz
    cfg |= ( 0x02 << 4 ); // set 10 Hz
    // LPEN: Low power enable (1/0)
    //cfg |= (0x00 << 3 ); // set normal power
    // ZEN, YEN, XEN
    cfg |= 0x07; // enable all X,Y,Z
    write_i2c_reg_byte( accAddr, 0x20, cfg );

    // @[0x23] (CTRL4) -----------------------------
    cfg = 0x00;
    // BDU : Block data update
    //  - 0 for continuous
    //  - 1 for update after read
    //cfg |= (0x01 << 7); // set to update after read
    //  BLE : Big/Little Edian select
    //  - 0 for LSB @ Lower Address
    //  - 1 for MSB @ Lower Address
    //cfg |= (0x00 << 6); // keep at 0 to match regs
    //  FS : Full Scale Select
    //  - 0x00 for +/- 2G
    //  - 0x01 for +/- 4G
    //  - 0x02 for +/- 8G
    //  - 0x03 for +/- 16G
    //cfg |= (0x00 << 4); // keep at +/- 2G for most accuracy
    //m_AccScale = 2.0f;
    //  HR : High Resolution
    //  - 0 for disabled
    //  - 1 for enabled
    //cfg |= (0x01 << 3); // enable
    //  SIM: SPH Serial Interface Mode
    //  - 0 for 4-wire
    //  - 1 for 3-wire
    //  -- don't care, just leave at 0      
    write_i2c_reg_byte( accAddr, 0x23, cfg );


}

void LSM303DLHCAccelerometer_get_xword()
{
    uint8 msb = 0;
    uint8 lsb = 0;
    read_i2c_reg_byte( accAddr, 0x28, &lsb);
    read_i2c_reg_byte( accAddr, 0x29, &msb);
    
    xAcc = (uint16)( (msb << 8) | lsb );
}

void LSM303DLHCAccelerometer_get_yword()
{
    uint8 msb = 0;
    uint8 lsb = 0;
    read_i2c_reg_byte( accAddr, 0x2A, &lsb);
    read_i2c_reg_byte( accAddr, 0x2B, &msb);
    
    yAcc = (uint16)( (msb << 8) | lsb );
}

void LSM303DLHCAccelerometer_get_zword()
{
    uint8 msb = 0;
    uint8 lsb = 0;
    read_i2c_reg_byte( accAddr, 0x2C, &lsb);
    read_i2c_reg_byte( accAddr, 0x2D, &msb);
    
    zAcc = (uint16)( (msb << 8) | lsb );
}

/* *****************************************************************************
 End of File
 */

