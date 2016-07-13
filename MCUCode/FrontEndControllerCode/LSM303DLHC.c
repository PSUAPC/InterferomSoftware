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

//LSM303DLHCAccelerometer
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


/* *****************************************************************************
 End of File
 */

