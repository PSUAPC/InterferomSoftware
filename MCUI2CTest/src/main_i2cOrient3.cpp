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

		unsigned char regs[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,49,50};
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
		// @[0x00] (CFGA) ---------------------------------------------
		cfg = 0x00;
		// MS (Measurment Mode)
		//  - 00 Normal Measurement  (DEFAULT)
		//  - 01 Positive Current forced
		//  - 10 Negative Current forced
		//  - 11 Temp Sensor Only
		cfg |= 0x00;
		
		// DO (Data Output )
		//  - 000 Rate   0.75 Hz
		//  - 001 Rate   1.50 Hz
		//  - 010 Rate   3.00 Hz
		//  - 011 Rate   7.50 Hz
		//  - 100 Rate  15.00 Hz  (DEFAULT)
		//  - 101 Rate  30.00 Hz
		//  - 110 Rate  75.00 Hz
		//  - 111 Rate 220.00 Hz
		unsigned char dO = 0x07;//0x04;
		cfg |= ( dO << 2 ); // shift D0
		
		// MA (Measurment Samples Averaged)
		// - 00 Samples 1 (DEFAULT)
		// - 01 Samples 2
		// - 10 Samples 4
		// - 11	Samples 8
		unsigned char ma = 0x03; // 8 measurement samples
		cfg |= ( ma << 5 ); // shift MA

		// TS (Temperature)
		// - 0 Disable
		// - 1 Enable
		cfg |= ( 0x01 << 7 );
	        WriteRegisterByte( 0x00, cfg );
		
		// @[0x01] (CFGB) ---------------------------------------------
		cfg = 0x00; // clear the bit
		// GAIN
		//  - 000  Range 0.9 Ga  Resolution 0.73 mGa
		//  - 001  Range 1.3 Ga  Resolution 0.92 mGa  (DEFAULT)
		//  - 010  Range 1.9 Ga  Resolution 1.22 mGa
		//  - 011  Range 2.5 Ga  Resolution 1.52 mGa
		//  - 100  Range 4.0 Ga  Resolution 2.27 mGa
		//  - 101  Range 4.7 Ga  Resolution 2.56 mGa
		//  - 110  Range 5.6 Ga  Resolution 3.03 mGa
		//  - 111  Range 8.1 Ga  Resolution 4.35 mGa
		unsigned char gain = 0x01; // default gain value
		m_Scale = 0.92E-3;
		cfg |= ( gain << 5 ); // shift to gain location
		WriteRegisterByte( 0x01, cfg );
	
		// @[0x02] (CFGC) ---------------------------------------------
		// MODE
		//  - 00  Continuous measurements at fDO
		//  - 01  Single Shot, hold until all 6 data read (DEFAULT)
		//  - 1x  Idle Mode
		cfg = 0x01; // set single shot mode
		//cfg = 0x00; // set continuous mode
		WriteRegisterByte( 0x02, cfg );		
	}

	virtual void TakeSnapshot()
	{

		// write snapshot request to register
		unsigned char cfgc = 0x01;
		WriteRegisterByte( 0x02, cfgc );

		bool ready = false;
	#if 0	
		// read the status register
		// timeout after 20 ms
		for( int ii = 0; (ii < 20) && (!ready); ii++ )
		{
			cfgc = 0;

			// pause for 1 ms
			usleep( 1000 );

			// status register
			ReadRegisterByte( 0x09 , &cfgc);
			
			// check for ready
			if( cfgc & 0x01 != 0x00 )
			{
				ready = true;
			}

		}

		usleep( 1000 );
		if( !ready )
			printf(" warning, not ready\n");
		// read the words
#endif
		usleep( 1000 );
		unsigned char tblock [6];
		// read the memory as a block
		ReadRegisterBlock(0x03, 6, tblock);

		m_X = FormWord( tblock[0], tblock[1] ); 		
		m_Y = FormWord( tblock[2], tblock[3] );
		m_Z = FormWord( tblock[4], tblock[5] );

		// sleep for 1 ms
		usleep( 1000 );
		
		ReadRegisterBlock(0x31, 2, tblock);
		m_T = FormWord( tblock[0], tblock[1] );
	}


	bool SelfTest()
	{
		bool pass = true;

		// 1) CRA - place the device into self test mode
		WriteRegisterByte( 0x00, 0x71 );
		// 2) CRB - set gain to 5
		WriteRegisterByte( 0x01, 0xA0 );
		// 3) MODE - Continuous Measurement mode
		WriteRegisterByte( 0x02, 0x00 );
		// 4) pause for 6 mS
		msleep( 6 );
		
		unsigned char tblock [6];
		// read the memory as a block
		ReadRegisterBlock(0x03, 6, tblock);

		m_X = FormWord( tblock[0], tblock[1] ); 		
		m_Y = FormWord( tblock[2], tblock[3] );
		m_Z = FormWord( tblock[4], tblock[5] );
		
		msleep(67);

		// convert all to signed
		int x = ConvertToSigned( m_X );
		int y = ConvertToSigned( m_Y );
		int z = ConvertToSigned( m_Z );

		// check the limits
		if( !InRange( x, 243, 575 ) )
		{
			printf( "X failed %i\n", x);
			pass = false;
		}
		if( !InRange( y, 243, 575 ) )
		{
			printf( "Y failed %i\n", y);
			pass = false;
		}
		if( !InRange( z, 243, 575 ) )
		{
			printf( "Z failed %i\n", z);
			pass = false;
		}
	
		// reset the mode
		WriteRegisterByte( 0x00, 0x70 );
			
		if( pass ) printf( "All passed \n");
		
		msleep( 67 );
		return pass;
	}

	float GetTemp()
	{
		float val = ConvertToSigned( m_T );
		val = val / (128.0f) + 25.0f; // convert to degrees C
		
		return val;
	}

	float GetX()
	{
		float ratio = m_Scale;// / float(2047.0f);
		float val = ConvertToSigned( m_X );
		val = val*ratio;

		return val;
	}

	float GetY()
	{
		float ratio = m_Scale;// / float(2047.0f);
		float val = ConvertToSigned( m_Y );
		val = val*ratio;

		return val;
	
	}

	float GetZ()
	{
		float ratio = m_Scale;// / float(2047.0f);
		float val = ConvertToSigned( m_Z );
		val = val*ratio;

		return val;
	
	}

private:

	unsigned short GetTempWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		unsigned short output = 0;

		ReadRegisterByte( 0x31, &msb );
		ReadRegisterByte( 0x32, &lsb );
		
		output = (unsigned short)( msb ) * (unsigned short)( 256 ) + (unsigned short)( lsb );
		
		return output;
	}

	unsigned short GetXWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		unsigned short output = 0;

		ReadRegisterByte( 0x03, &msb );
		ReadRegisterByte( 0x04, &lsb );
		
		output = (unsigned short)( msb ) * (unsigned short)( 256 ) + (unsigned short)( lsb );
		
		return output;

	}

	unsigned short GetYWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		unsigned short output = 0;

		ReadRegisterByte( 0x05, &msb );
		ReadRegisterByte( 0x06, &lsb );
		
		output = (unsigned short)( msb ) * (unsigned short)( 256 ) + (unsigned short)( lsb );
		
		return output;

	}
	
	unsigned short GetZWord()
	{
		unsigned char msb = 0;
		unsigned char lsb = 0;
		unsigned short output = 0;

		ReadRegisterByte( 0x07, &msb );
		ReadRegisterByte( 0x08, &lsb );
		
		output = (unsigned short)( msb ) * (unsigned short)( 256 ) + (unsigned short)( lsb );
		
		return output;

	}

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

	float m_Scale;
	unsigned short m_X;
	unsigned short m_Y;
	unsigned short m_Z;
	unsigned short m_T;

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
	
	LSM303DLHCAccelerometer() : m_XByte(0), m_YByte(0), m_ZByte(0), I2CDevice() {}

	virtual void DumpRegisters()
        {
                printf("Dumping Registers for device at Address %#04x\n", m_Addr);

                unsigned char regs[] = {0,1,2,3,4,5,6,7,8,9,10};
                int nRegs = 11;
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
		// @[0x05] (SPCNT) ----------------------------
		cfg = 0x00; // sleep count = 0
		WriteRegisterByte( 0x05, cfg );
				
		// @[0x07] (MODE) -----------------------------
		cfg = 0x01; // turn on / make active
		// SCPS 
		//  - 0 for divide by  1 => clk \in [120 , 1] Hz
		//  - 1 for divide by 16 => clk \in [0, 0.0625] Hz
		//cfg |= 0x20; // SCPS (0 for divide by 1, 1 for divide by 16)		
		WriteRegisterByte( 0x07, cfg );

		// @[0x08] (SR) -------------------------------
		// DONT CARE --- Only valid for sleep mode, Tilt Not Used
		
		// @[0x09] (PDET) -----------------------------
		// DONT CARE --- Not caring about tap mode
		
		// @[0x0A] (PD) -------------------------------
		// DONT CARE --- Not Caring about tap mode

	}	

	virtual void TakeSnapshot()
	{
		usleep(100);
		m_XByte = GetXByte();
		usleep(100);
		m_YByte = GetYByte();
		usleep(100);
		m_ZByte = GetZByte();
		usleep(100);
	}

	unsigned char GetXByte()
	{
		unsigned char dat = 0;
		ReadRegisterByte( 0x00, &dat);

		// mask the byte
		dat = dat & 0x3F;

		return dat;	
	}

	unsigned char GetYByte()
	{
		unsigned char dat = 0;
		ReadRegisterByte( 0x01, &dat);

		// mask the byte
		dat = dat & 0x3F;

		return dat;	

	}

	unsigned char GetZByte()
	{
		unsigned char dat = 0;
		ReadRegisterByte( 0x02, &dat);

		// mask the byte
		dat = dat & 0x3F;

		return dat;	

	}

	float GetX()
	{
		float ratio = 1.5f / 32.0f;

		int sValue = ConvertToSignedByte( m_XByte );
		return sValue*ratio;		
	}
	
	float GetY()
	{
		float ratio = 1.5f / 32.0f;

		int sValue = ConvertToSignedByte( m_YByte );
		return sValue*ratio;		
	}
	
	float GetZ()
	{
		float ratio = 1.5f / 32.0f;

		int sValue = ConvertToSignedByte( m_ZByte );
		return sValue*ratio;		
	}

private:
	int ConvertToSignedByte( unsigned char input )
	{
		// need to convert the lower 6 bits in 2's complement to unsigned char
		unsigned char msb = input & 0x20;
		unsigned char lsb = input & 0x1F;
		int outputI = lsb;

		if( msb != 0x00 )
		{
			// negative number
			// subtract 32 from it to get the negative value
			outputI = outputI - 32;
		}

		return outputI;
	}

	unsigned char m_XByte;
	unsigned char m_YByte;
	unsigned char m_ZByte;
};
#include <termios.h>
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
	
	mag.SelfTest();

	// init devices
	mag.Init();
	acc.Init();
	sleep(1);

	mag.DumpRegisters();
	//sleep(1);
	//mag.DumpRegisters();
	acc.DumpRegisters();
	//sleep(1);
	//acc.DumpRegisters();

	
	float magAve = 0;
	float magStd = 0;

	// enter a loop
	for( int i = 0; i < ITS; i++ )
	{

		mag.TakeSnapshot();
		acc.TakeSnapshot();		
		printf("A: %4.2f %4.2f %4.2f M: %8.6f %8.6f %8.6f T: %4.2f", acc.GetX(),  acc.GetY(), acc.GetZ(),
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


		printf("\t A:|%4.2f| M:|%8.6f| @%6.3f \r", aNorm, mNorm, heading);
		
		magAve += heading;
		magStd += heading*heading;

		// flush stdout to display the cr
		fflush(stdout);	
		
		// sleep
		usleep(100000);

		if( i == ITS/2 )
		{
			printf("\n");
			mag.DumpRegisters();
 			acc.DumpRegisters();
		}
	}
		
	printf("\n");

	magStd = sqrt(fabs(magStd - magAve*magAve));
	printf("H: <%f> +/- %f \n", magAve/float(ITS), magStd/float(ITS));
	
	close(fd);
    
	return 0;
} 



