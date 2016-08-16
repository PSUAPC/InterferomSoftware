/// ########################################################################
/// 
///     Name: 	main_i2cOrient2.cpp
///	Purpose: Define the I2C Testfile for the orientation sensor
///	
/// #######################################################################


// ########### I2C Driver Fix ##################
// (Found at: https://www.raspberrypi.org/forums/viewtopic.php?f=44&t=15840&p=603520&hilit=i2c%2brepeated%2bstart#p603520 )
//
// once one has the i2c driver installed (insmod i2c-dev.ko, insmod i2c-bcm2708.ko), 
// and made available (chmod 666 /dev/i2c-*), 
// then one needs to turn on the combined transactions 
// (chmod 666 /sys/module/i2c_bcm2708/parameters/combined, 
// echo -n 1 > /sys/module/i2c_bcm2708/parameters/combined).
// This has to be done at startup

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>
#include <math.h>
#include <ctime>
#include <iostream>

using std::list;

// current configuration info
// +Z pointing down (expext ~+1g)

#define ADDR_MAG 0x1E
#define ADDR_ACC 0x19


#define ITS 200

void msleep( size_t mSec )
{
	usleep( mSec*1000 );
}

bool InRange( int x, int min, int max )
{
	if( (x >= min) && (x <= max) )
		return true;
	else
		return false;
}

class I2CDevice
{
public:
	I2CDevice() :
		m_Fd(0), m_Addr(0) {}

	void SetFD( int fd ) { m_Fd = fd; }
	void SetAddr( unsigned char addr ) { m_Addr = addr; }
	
	virtual void DumpRegisters() = 0;
	virtual void Init() = 0;

	virtual void TakeSnapshot() = 0;
protected:
	
	
	int ReadRegisterByte(	unsigned char reg,
                            	unsigned char *val) 
	{
    		unsigned char inbuf, outbuf;
    		struct i2c_rdwr_ioctl_data packets;
    		struct i2c_msg messages[2];

    
    		// In order to read a register, we first do a "dummy write" by writing
    		// 0 bytes to the register we want to read from.  This is similar to
    		// the packet in set_i2c_register, except it's 1 byte rather than 2.
    
    		outbuf = reg; 				// set the register address
    		messages[0].addr  = m_Addr;
    		messages[0].flags = 0; 			// write flag
    		messages[0].len   = sizeof(outbuf);
    		messages[0].buf   = &outbuf;

    		// The data will get returned in this structure 
    		messages[1].addr  = m_Addr;
    		messages[1].flags = I2C_M_RD;// | I2C_M_NOSTART;
    		messages[1].len   = sizeof(inbuf);
    		messages[1].buf   = &inbuf;

    		// Send the request to the kernel and get the result back 
    		packets.msgs      = messages;
    		packets.nmsgs     = 2;
    		if(ioctl(m_Fd, I2C_RDWR, &packets) < 0) 
		{
        		printf("Unable to send data, Device: %#04x @[%#04x]\n", m_Addr, reg);
        		return 1;
    		}
    		*val = inbuf;

    		return 0;
	}
	
	int ReadRegisterBlock(	unsigned char reg,
				size_t        len,
                            	unsigned char *val) 
	{
    		unsigned char outbuf;
    		struct i2c_rdwr_ioctl_data packets;
    		struct i2c_msg messages[2];
		unsigned char* inbuf = new unsigned char [len];

    
    		// In order to read a register, we first do a "dummy write" by writing
    		// 0 bytes to the register we want to read from.  This is similar to
    		// the packet in set_i2c_register, except it's 1 byte rather than 2.
    
    		outbuf = reg; 				// set the register address
    		messages[0].addr  = m_Addr;
    		messages[0].flags = 0; 			// write flag
    		messages[0].len   = sizeof(outbuf);
    		messages[0].buf   = &outbuf;

    		// The data will get returned in this structure 
    		messages[1].addr  = m_Addr;
    		messages[1].flags = I2C_M_RD;// | I2C_M_NOSTART;
    		messages[1].len   = len;
    		messages[1].buf   = inbuf;

    		// Send the request to the kernel and get the result back 
    		packets.msgs      = messages;
    		packets.nmsgs     = 2;
    		if(ioctl(m_Fd, I2C_RDWR, &packets) < 0) 
		{
        		printf("Unable to send data, Device: %#04x @[%#04x]\n", m_Addr, reg);
			delete [] inbuf;

        		return 1;
    		}
		memcpy( val, inbuf, len );

		delete [] inbuf;
    		return 0;
	}

	int WriteRegisterByte( 	unsigned char reg,
                            	unsigned char value) 
	{

    		unsigned char outbuf[2];
    		struct i2c_rdwr_ioctl_data packets;
    		struct i2c_msg messages[1];

    		messages[0].addr  = m_Addr;
    		messages[0].flags = 0;
    		messages[0].len   = sizeof(outbuf);
    		messages[0].buf   = outbuf;

    		// The first byte indicates which register we'll write 
    		outbuf[0] = reg;

   
 		// The second byte indicates the value to write.  Note that for many
 		// devices, we can write multiple, sequential registers at once by
		// simply making outbuf bigger.
 
    		outbuf[1] = value;

    		// Transfer the i2c packets to the kernel and verify it worked 
    		packets.msgs  = messages;
    		packets.nmsgs = 1;
    		if(ioctl(m_Fd, I2C_RDWR, &packets) < 0) 
		{
        		printf("Unable to send data, Device: %#04x @[%#04x]\n", m_Addr, reg);
        		return 1;
    		}

    		return 0;
	}
	
	int m_Fd;
	unsigned char m_Addr;

};

class LSM303DLHCDigitalCompass : public I2CDevice
{
public:

 	// ----------------------------- Register Configuration --------------------------------
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // | ADDR | R/W | NAME | BIT 7 | BIT 6 | BIT 5 | BIT 4 | BIT 3 | BIT 2 | BIT 1 | BIT 0 |
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
        // + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x00 | R/W | CRA  | TEMPEN|   0   |   0   |  	DO( 2 : 0 )    |   0   |   0   |   
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x01 | R/W | CRB  |     GN( 2 : 0 )       |   0   |   0   |   0   |   0   |   0   |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x02 | R/W |  MR  |   0   |   0   |   0   |   0   |   0   |   0   |  MD( 1 : 0 )  |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x03 |  R  | XMSB | 		XDA( 15 : 8 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +	
	// | 0x04 |  R  | XLSB |		XDA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x05 |  R  | ZMSB |		ZDA( 15 : 8 ) 				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x06 |  R  | ZLSB |		ZDA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x07 |  R  | YMSB |		YDA( 15 : 8 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x08 |  R  | YLSB |		YDA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x09 |  R  |  SR  |   --  |   --  |   --  |   --  |   --  |   --  |  LOCK |  DRDY |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x0A |  R  | IRA  |   0   |   1   |   0   |   0   |   1   |   0   |   0   |   0   |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
  	// | 0x0B |  R  | IRB  |   0   |   0   |   1   |   1   |   0   |   1   |   0   |   0   |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x0C |  R  | IRC  |   0   |   0   |   1   |   1   |   0   |   0   |   1   |   1   |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x0D |  -  |								       |
	// |  -   |  -  |		RESERVED (DO NOT MODIFY)			       |
	// | 0x30 |  -  |								       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x31 |  R  | TMSB |  	TMP( 11 : 4 )				               |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x32 |  R  | TLSB |	TMP( 3 : 0 )           |   --  |   --  |   --  |   --  |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x33 |  -  |								       |
	// |  -   |  -  |		RESERVED (DO NOT MODIFY)			       |
	// | 0x3A |  -  |								       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	
	LSM303DLHCDigitalCompass() : I2CDevice() {}

	virtual void DumpRegisters()
	{
		printf("Dumping Registers for device at Address %#04x\n", m_Addr);

		unsigned char regs[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,
					0x0A,0x0B,0x0C,0x31,0x32};
		int nRegs = 15;
		unsigned char buff;

		for( int ii = 0; ii < nRegs; ii++ )
		{
			if( ReadRegisterByte( regs[ii], &buff ) == 0)
				printf("@[%#04x] = %#04x\n", regs[ii], buff);	
			else
				printf("@[%#04x] Read Error", regs[ii]);
		}
	}

	virtual void Init()
	{
		unsigned char cfg = 0x00;

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
		cfg |= (0x05 << 2); // set 30 Hz
		// write to the register
		WriteRegisterByte( 0x00, cfg );
		
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
		m_XScale = 1.0f/450.0f;
		m_YScale = 1.0f/450.0f;
		m_ZScale = 1.0f/400.0f;
		WriteRegisterByte( 0x01, cfg );
	
		// @[0x02] (MR) ---------------------------------------------
		cfg = 0x00; // clear the bits
		// MD : Mode select
		// - 0x00 for continous mode
		// - 0x01 for single-conversion
		// - 0x02 for sleep-mode
		// - 0x03 for sleep-mode
		//cfg |= 0x00; // set continous mode
		WriteRegisterByte( 0x02, cfg );		
	}

	virtual void TakeSnapshot()
	{

		// read the words
		// register map has them in X,Z,Y order
		
		m_X = GetXWord();
		m_Z = GetZWord();
		m_Y = GetYWord();

		// sleep for 1 ms
		usleep( 1000 );
		

		m_T = GetTempWord();

	}


	bool SelfTest()
	{
		bool pass = true;

		// self testing is not defined for this device

		return pass;
	}

	float GetTemp()
	{
		

		// temperature conversion is not clear here...
		// accoding to the datasheet, the real temp (degC) should 
		// be given by the 12-bit value via:
		// T = m_T * (125/4096) + 22.5
		// accoding to the sample driver by ST, temp is an 8-bit value
		// and the real temp (degC) and is given by:
		// T = m_T + 25
		// for safety, let's use the one ST gives us
		
		return (float) m_T + 25.0f; // degC
	}

	float GetX()
	{
		float ratio = m_XScale;

		return (float) m_X * ratio;
	}

	float GetY()
	{
		float ratio = m_YScale;

		return (float) m_Y * ratio;
	
	}

	float GetZ()
	{
		float ratio = m_ZScale;

		return (float) m_Z * ratio;
	
	}



	short GetTempWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		unsigned short output = 0;

		ReadRegisterByte( 0x31, &msb );
		ReadRegisterByte( 0x32, &lsb );
		
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

		output = (short) msb;

		
		return output;
	}

	short GetXWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		short output = 0;

		ReadRegisterByte( 0x03, &msb );
		ReadRegisterByte( 0x04, &lsb );
		
		output = (short)( (msb << 8) | lsb );
		
		return output;

	}

	short GetYWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		short output = 0;

		ReadRegisterByte( 0x07, &msb );
		ReadRegisterByte( 0x08, &lsb );
		
		output = (short)( (msb << 8) | lsb );

		
		return output;

	}
	
	short GetZWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		short output = 0;

		ReadRegisterByte( 0x05, &msb );
		ReadRegisterByte( 0x06, &lsb );
		
		output = (short)( (msb << 8) | lsb );

		return output;

	}

private:

	unsigned short FormWord( unsigned char msb, unsigned char lsb )
	{
		unsigned short output;

		output = (unsigned short)( msb ) * (unsigned short)( 256 ) + (unsigned short)( lsb );

                return output;
	}

	int ConvertToSigned(unsigned short input)
	{
		unsigned short sgn = 0x8000 & input;
		unsigned short wrd = 0x7FFF & input;
		short outputS = input;

		if( input > 0x07FF )
		{
			outputS = 0xFFFF - input;
		}

		int outputI = outputS;
		return outputI;
	}

	float m_XScale;
	float m_YScale;
	float m_ZScale;
	short m_X;
	short m_Y;
	short m_Z;
	short m_T;

};

class LSM303DLHCAccelerometer : public I2CDevice
{
public:

	// ----------------------------- Register Configuration --------------------------------
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | ADDR | R/W | NAME | BIT 7 | BIT 6 | BIT 5 | BIT 4 | BIT 3 | BIT 2 | BIT 1 | BIT 0 |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x00 |  -  |                                                                      |
	// |   -  |  -  |		RESERVED (DO NOT MODIFY)			       |
	// | 0x1F |  -	|								       |
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
	// | 0x26 | R/W | REFF |     		REF( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x27 |  R  | STAT | ZYXOR |  ZOR  |  YOR  |  XOR  | ZTXDA |  ZDA  |  YDA  |  XDA  | 
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x28 |  R  | xLSB |        	XDA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x29 |  R  | XMSB |		XDA( 15 : 8 ) 				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x2A |  R  | YLSB |		YDA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x2B |  R  | YMSB |		YDA( 15 : 8 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x2C |  R  | ZLSB |		ZDA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x2D |  R  | ZMSB |		ZDA( 15 : 8 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x2E | R/W | FCTL |   FM( 1 : 0 ) |   TR  |    	FTH( 4 : 0 )		       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x2F |  R  | FSCR |  WTM  | OVRN  | EMPTY |   	FSS( 4 : 0 )		       |	
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x30 | R/W | IN1C |  AOI  |   6D  | ZHIE  |  ZLIE | YHIE  | YLIE  | XHIE  | XLIE  |   
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x31 |  R  | IN1S |   0   |   IA  |  ZH   |  ZL   |  YH   |  YL   |   XH  |  XL   |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x32 | R/W | IN1T |   0   |  	THS( 6 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x33 | R/W | IN2D |   0   |    	DUR( 6 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x34 | R/W | IN2C |  AOI  |  6D   | ZHIE  | ZLIE  |  YHIE |  YLIE | XHIE  | XLIE  |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +	
  	// | 0x35 |  R  | IN2S |   0   |  IA   |  ZH   |  ZL   |  YH   |  YL   |  XH   |   XL  |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x36 | R/W | IN2T |   0   |    	THS( 6 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x37 | R/W | IN2D |   0   | 	DIR( 6 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x38 | R/W | CLKC |   --  |  --   |   ZD  |   ZS  |   YD  |   YS  |   XD  |   XS  |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x39 | R/W | CLKS |   --  |   IA  | DCLCK | SCLCK |  SGN  |   Z   |   Y   |   X   |  
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x3A | R/W | CLKT |   --  |   	THS( 6 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x3B | R/W | TLIM |   --  |   	TLI( 6 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x3C | R/W | TLAT | 		TLA( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x3D | R/W | TWIN |		TW( 7 : 0 )				       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x3E |  -  |		RESERVED (DO NOT MODIFY)			       |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	// | 0x3F |  -  |		RESERVED (DO NOT MODIFY)                               |
	// + ---- + --- + ---- + ----- + ----- + ----- + ----- + ----- + ----- + ----- + ----- +
	
	LSM303DLHCAccelerometer() : m_XWord(0), m_YWord(0), m_ZWord(0), m_XFilter(0), m_YFilter(0),
		m_ZFilter(0), I2CDevice() {}

	virtual void DumpRegisters()
        {
                printf("Dumping Registers for device at Address %#04x\n", m_Addr);

                unsigned char regs[] = {0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,
					0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,
					0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D};
                int nRegs = 30;
                unsigned char buff;

                for( int ii = 0; ii < nRegs; ii++ )
                {
                        if( ReadRegisterByte( regs[ii], &buff ) == 0 )
                                printf("@[%#04x] = %#04x\n", regs[ii], buff);
                        else
                                printf("@[%#04x] Read Error", regs[ii]);
                }
		
		        
	}

	virtual void Init()
	{

		unsigned char cfg = 0x00;

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
		WriteRegisterByte( 0x20, cfg );
				
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
		m_AccScale = 2.0f;
		//  HR : High Resolution
		//  - 0 for disabled
		//  - 1 for enabled
		//cfg |= (0x01 << 3); // enable
		//  SIM: SPH Serial Interface Mode
		//  - 0 for 4-wire
		//  - 1 for 3-wire
		//  -- don't care, just leave at 0	
		WriteRegisterByte( 0x23, cfg );


	}	

	virtual void TakeSnapshot()
	{
		//usleep(100);
		short ax = GetXWord();
		//usleep(100);
		short ay = GetYWord();
		//usleep(100);
		short az = GetZWord();

		m_XFilter = ax + m_XWord;//( m_XFilter >> 6 );
		m_YFilter = ay + m_YWord;//( m_YFilter >> 6 );
		m_ZFilter = az + m_ZWord;//( m_ZFilter >> 6 );
		m_XWord = ax;
		m_YWord = ay;
		m_ZWord = az;
		//usleep(100);
	}

	short GetXWord()
	{
		short datS = 0;
		ReadRegisterByte( 0x28, (unsigned char*)&datS);
		ReadRegisterByte( 0x29, (unsigned char*)(&datS) + 1);

		return datS;	
	}

	short GetYWord()
	{
		short datS = 0;
		ReadRegisterByte( 0x2A, (unsigned char*)&datS);
		ReadRegisterByte( 0x2B, (unsigned char*)(&datS) + 1);
		
		return datS;	
	
	}

	short GetZWord()
	{
		short datS = 0;
		ReadRegisterByte( 0x2C, (unsigned char*)&datS);
		ReadRegisterByte( 0x2D, (unsigned char*)(&datS) + 1);

		return datS;	
	
	}

	float GetX()
	{
		float ratio = m_AccScale / float(32767);
		
		return (float) m_XWord * ratio;
	}
	
	float GetY()
	{
		float ratio = m_AccScale / float(32767);
		
		return (float) m_YWord * ratio;		
	}
	
	float GetZ()
	{
		float ratio = m_AccScale / float(32767);
		
		return (float) m_ZWord * ratio;
	}

private:
	int ConvertToSignedShort( unsigned short input )
	{
		// need to convert the lower 6 bits in 2's complement to unsigned char
		int outputI = input;
		if( (input&0x8000) != 0x0000 )
			outputI = 0xFFFF00000 | (outputI & 0x0000FFFF);

		return outputI;
	}


	float m_AccScale;
	short m_XWord;
	short m_YWord;
	short m_ZWord;
	long m_XFilter;
	long m_YFilter;
	long m_ZFilter;
};
#include <termios.h>

    
char PrintPrompt(bool q_n)
{
	char buff;
        printf(" skip(s)");
	if(!q_n)
	{
		printf(" quit(q)");
	}
	printf(" continue(other)\n");

        fflush(stdout);
        //fgets(&buff, 1, stdin);
        //fflush(stdin);
	std::cin >> buff;

	return buff;
}


int main(void)
{ 


	int fd, i;
	const char* fileName = "/dev/i2c-1";
	int address = 0x01;
	unsigned char buff = 0;
	unsigned char rbuff = 0;
	
	if( (fd = open(fileName, O_RDWR)) < 0 )
        {

                printf("Failed to open i2c port\n");
                return 1;
        }
        else
        {
                printf("i2c Port opened\n");
        }


	//struct termios tio;
	//tcgetattr(fd, &tio);
	//speed_t spd = cfgetospeed(&tio);
	//printf("%i\n", spd);
	LSM303DLHCDigitalCompass mag;
	LSM303DLHCAccelerometer acc;
	
	// set the files and addr
	mag.SetFD( fd );
	acc.SetFD( fd );
	mag.SetAddr( ADDR_MAG );
	acc.SetAddr( ADDR_ACC );
	// self test the mag
	
	//mag.SelfTest();

	// init devices
	acc.Init(); // must init acc first
	mag.Init();
	sleep(1);

	//mag.DumpRegisters();
	//sleep(1);
	//mag.DumpRegisters();
	//acc.DumpRegisters();
	//sleep(1);
	//acc.DumpRegisters();

	
	//float magAve = 0;
	//float magStd = 0;

	list<short> xvals;
	list<short> yvals;
	list<short> zvals;
	


	// temp variable for stdin

	// time varaibles
	time_t start = time(NULL);
	time_t end = time(NULL);	

	// calibration begin
	printf(" ----------------------------------------------- \n");
	printf("          LSM303 Calibration Program             \n");
	printf(" ----------------------------------------------- \n");
	printf(" results will be logged to acal.log and mcal.log\n");

	FILE* logfile; 	
	printf(" Beginning Accelerometer Calibration \n");
	buff = PrintPrompt(false);
	
	if( buff == 'q' )
	{
		close(fd);
		return 0;
	}
	if( buff != 's' )
	{
		logfile = fopen("acal.log", "w");

		printf("Accelerometer: Step 1) Z-up position \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();
			
			start = time(NULL);
			end = time(NULL);

			while( difftime(end, start) < 10.0 )
			{
				xvals.push_back( acc.GetXWord() );
				yvals.push_back( acc.GetYWord() );
				zvals.push_back( acc.GetZWord() );

				usleep(10.0E3);
				end = time(NULL);
			}			
			
			list<short>::iterator xit = xvals.begin();
			list<short>::iterator yit = yvals.begin();
			list<short>::iterator zit = zvals.begin();

			fprintf(logfile, "# --------- Z-up Acc --------- \n");
			double xave = 0;
			double yave = 0; 
			double zave = 0;

			for( int ii = 0; ii < xvals.size(); ii++ )
			{
				fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
				xave += *xit;
				yave += *yit;
				zave += *zit;

                                xit++;
                                yit++;
                                zit++;




			}	

			xave /= double(xvals.size());		
			yave /= double(xvals.size());
			zave /= double(xvals.size());

			fprintf(logfile, "# ave: %f %f %f \n", xave, yave, zave);

			printf(" Test Complete \n");
			printf( " ave: %f %f %f \n", xave, yave, zave);

		}
		
		printf("Accelerometer: Step 2) Z-down position \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();
			
			start = time(NULL);
			end = time(NULL);

			while( difftime(end, start) < 10.0 )
			{
				xvals.push_back( acc.GetXWord() );
				yvals.push_back( acc.GetYWord() );
				zvals.push_back( acc.GetZWord() );

				usleep(10.0E3);
				end = time(NULL);
			}			
			
			list<short>::iterator xit = xvals.begin();
			list<short>::iterator yit = yvals.begin();
			list<short>::iterator zit = zvals.begin();

			fprintf(logfile, "# --------- Z-down Acc --------- \n");
			double xave = 0;
			double yave = 0; 
			double zave = 0;

			for( int ii = 0; ii < xvals.size(); ii++ )
			{
				fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
				xave += *xit;
				yave += *yit;
				zave += *zit;

                                xit++;
                                yit++;
                                zit++;



			}	

			xave /= double(xvals.size());		
			yave /= double(xvals.size());
			zave /= double(xvals.size());

			fprintf(logfile, "# ave: %f %f %f \n", xave, yave, zave);

			printf(" Test Complete \n");
			printf( " ave: %f %f %f \n", xave, yave, zave);
		}


		printf("Accelerometer: Step 3) X-up position \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();
			
			start = time(NULL);
			end = time(NULL);

			while( difftime(end, start) < 10.0 )
			{
				xvals.push_back( acc.GetXWord() );
				yvals.push_back( acc.GetYWord() );
				zvals.push_back( acc.GetZWord() );

				usleep(10.0E3);
				end = time(NULL);
			}			
			
			list<short>::iterator xit = xvals.begin();
			list<short>::iterator yit = yvals.begin();
			list<short>::iterator zit = zvals.begin();

			fprintf(logfile, "# --------- X-up Acc --------- \n");
			double xave = 0;
			double yave = 0; 
			double zave = 0;

			for( int ii = 0; ii < xvals.size(); ii++ )
			{
				fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
				xave += *xit;
				yave += *yit;
				zave += *zit;



                                xit++;
                                yit++;
                                zit++;

			}	

			xave /= double(xvals.size());		
			yave /= double(xvals.size());
			zave /= double(xvals.size());

			fprintf(logfile, "# ave: %f %f %f \n", xave, yave, zave);

			printf(" Test Complete \n");
			printf( " ave: %f %f %f \n", xave, yave, zave);
		}
		
		printf("Accelerometer: Step 4) X-down position \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();
			
			start = time(NULL);
			end = time(NULL);

			while( difftime(end, start) < 10.0 )
			{
				xvals.push_back( acc.GetXWord() );
				yvals.push_back( acc.GetYWord() );
				zvals.push_back( acc.GetZWord() );

				usleep(10.0E3);
				end = time(NULL);
			}			
			
			list<short>::iterator xit = xvals.begin();
			list<short>::iterator yit = yvals.begin();
			list<short>::iterator zit = zvals.begin();

			fprintf(logfile, "# --------- X-down Acc --------- \n");
			double xave = 0;
			double yave = 0; 
			double zave = 0;

			for( int ii = 0; ii < xvals.size(); ii++ )
			{
				fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
				xave += *xit;
				yave += *yit;
				zave += *zit;
                                xit++;
                                yit++;
                                zit++;



			}	

			xave /= double(xvals.size());		
			yave /= double(xvals.size());
			zave /= double(xvals.size());

			fprintf(logfile, "# ave: %f %f %f \n", xave, yave, zave);

			printf(" Test Complete \n");
			printf( " ave: %f %f %f \n", xave, yave, zave);
		}
		
		printf("Accelerometer: Step 5) Y-up position \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();
			
			start = time(NULL);
			end = time(NULL);

			while( difftime(end, start) < 10.0 )
			{
				xvals.push_back( acc.GetXWord() );
				yvals.push_back( acc.GetYWord() );
				zvals.push_back( acc.GetZWord() );

				usleep(10.0E3);
				end = time(NULL);
			}			
			
			list<short>::iterator xit = xvals.begin();
			list<short>::iterator yit = yvals.begin();
			list<short>::iterator zit = zvals.begin();

			fprintf(logfile,"# --------- Y-up Acc --------- \n");
			double xave = 0;
			double yave = 0; 
			double zave = 0;

			for( int ii = 0; ii < xvals.size(); ii++ )
			{
				fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
				xave += *xit;
				yave += *yit;
				zave += *zit;

                                xit++;
                                yit++;
                                zit++;



			}	

			xave /= double(xvals.size());		
			yave /= double(xvals.size());
			zave /= double(xvals.size());

			fprintf(logfile, "# ave: %f %f %f \n", xave, yave, zave);

			printf(" Test Complete \n");
			printf( " ave: %f %f %f \n", xave, yave, zave);
		}
		
		printf("Accelerometer: Step 6) Y-down position \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();
			
			start = time(NULL);
			end = time(NULL);

			while( difftime(end, start) < 10.0 )
			{
				xvals.push_back( acc.GetXWord() );
				yvals.push_back( acc.GetYWord() );
				zvals.push_back( acc.GetZWord() );

				usleep(10.0E3);
				end = time(NULL);
			}			
			
			list<short>::iterator xit = xvals.begin();
			list<short>::iterator yit = yvals.begin();
			list<short>::iterator zit = zvals.begin();

			fprintf(logfile, "# --------- Y-down Acc --------- \n");
			double xave = 0;
			double yave = 0; 
			double zave = 0;

			for( int ii = 0; ii < xvals.size(); ii++ )
			{
				fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
				xave += *xit;
				yave += *yit;
				zave += *zit;

                                xit++;
                                yit++;
                                zit++;

			}	

			xave /= double(xvals.size());		
			yave /= double(xvals.size());
			zave /= double(xvals.size());

			fprintf(logfile, "# ave: %f %f %f \n", xave, yave, zave);

			printf(" Test Complete \n");
			printf( " ave: %f %f %f \n", xave, yave, zave);
		}
		
		printf("Accelerometer: Step 7) Shake test \n");
		buff = PrintPrompt(true);
		if( buff != 's')
		{

			start = time(NULL);
                        end = time(NULL);

			short minx = 0;
			short miny = 0;
			short minz = 0;
			short maxx = 0;
			short maxy = 0;
			short maxz = 0;

                        while( difftime(end, start) < 30.0 )
                        {
                                short x = acc.GetXWord();
                                short y = acc.GetYWord();
                                short z = acc.GetZWord();
				
				if( x > maxx )
					maxx = x;
				if( x < minx )
					minx = x;

				if( y > maxy )
					maxy = y;
				if( y < miny )
					miny = y;

				if( z > maxz )
					maxz = z;
				if( z < minz )
					minz = z;


                                usleep(10.0E3);
                                end = time(NULL);
                        }

			fprintf(logfile, "# ---- Shake Acc ---------\n");
			fprintf(logfile, "#mins: x) %d y) %d z) %d \n", minx, miny, minz);
			fprintf(logfile, "#maxs: x) %d y) %d z) %d \n", maxx, maxy, maxz);

			printf(" Test complete\n");
			printf( "mins: x) %d y) %d z) %d \n", minx, miny, minz);
			printf( "maxs: x) %d y) %d z) %d \n", maxx, maxy, maxz);


		}
	
	

 	}
	fclose(logfile);

	printf(" Beginning Magnetometer Calibration \n");

	buff = PrintPrompt(false);

	if( buff == 'q' )
	{
		close(fd);
		return 0;
	}

	if( buff != 's' )
	{
		logfile = fopen("mcal.log", "w");

		printf(" Magnetometer calibration: Step 1) Rotation Test\n");
		buff = PrintPrompt(true);
		if( buff != 's' )
		{
			xvals.clear();
			yvals.clear();
			zvals.clear();

			time_t start = time(NULL);
			time_t end = time(NULL);
			
			while( difftime(end, start) < 30.0 )
                        {
                                xvals.push_back( mag.GetXWord() );
                                yvals.push_back( mag.GetYWord() );
                                zvals.push_back( mag.GetZWord() );

                                usleep(10.0E3);
                                end = time(NULL);
                        }

                        list<short>::iterator xit = xvals.begin();
                        list<short>::iterator yit = yvals.begin();
                        list<short>::iterator zit = zvals.begin();

                        fprintf(logfile, "# --------- Mag x,y,z --------- \n");
                        double xave = 0;
                        double yave = 0;
                        double zave = 0;

                        for( int ii = 0; ii < xvals.size(); ii++ )
                        {
                                fprintf(logfile, "%d %d %d %d\n", ii, *xit, *yit, *zit);
                                xave += *xit;
                                yave += *yit;
                                zave += *zit;

				xit++;
				yit++;
				zit++;
                        }

			printf(" Test Complete \n");

		}

		fclose(logfile);	
	}

	printf(" Calibration program complete \n");

	//mag.TakeSnapshot();
	//acc.TakeSnapshot();		
#if 0
		printf("A: %8.2f %8.2f %8.2f M: %8.6f %8.6f %8.6f T: %4.2f", acc.GetX(),  acc.GetY(), acc.GetZ(),
										mag.GetX(), mag.GetY(), mag.GetZ(), 
										mag.GetTemp() );	
		
		// lets get the magnitude of the Acc and the Mag field
		float aNorm = acc.GetX()*acc.GetX();
		aNorm += acc.GetY()*acc.GetY();
		aNorm += acc.GetZ()*acc.GetZ();

		aNorm = sqrt( aNorm );
		
		float mX = mag.GetX();
		float mY = mag.GetY();
		float mZ = mag.GetZ();

		float mNorm = mX*mX;
		mNorm += mY*mY;
		mNorm += mZ*mZ;

		mNorm = sqrt( mNorm );


		float heading = 0;
	
		if( mY == 0.0f && mX > 0.0f) heading = 180.0f;	
		if( mY == 0.0f && mX <= 0.0f) heading = 0.0f;
		if( mY > 0 ) heading = 90.0f - atan( mX / mY ) * 180.0f / 3.14159f;
		if( mY < 0 ) heading = 280.0f - atan( mX / mY ) * 180.0f / 3.14159f;


		printf("\t A:|%4.2f| M:|%8.6f| @%6.3f \n", aNorm, mNorm, heading);
		
		magAve += heading;
		magStd += heading*heading;
#endif
		// flush stdout to display the cr
//		fflush(stdout);	
		
		// sleep
//		usleep(100000);

		
		
	printf("\n");

	
	close(fd);
    
	return 0;
} 



