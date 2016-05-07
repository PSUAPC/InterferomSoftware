/*
 *  I2C Example Bit Expander:
 *  The following is an example of using a MCP23017 I2C bit expander 
 *  with the Raspberry Pi.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Tested Setup:
 *
 * ______        ____________
 *   3V3|-------|VCC     A.0|----LED----GND
 *   GND|-------|GND     A.1|----LED----GND
 *   SDA|-------|SDA     A.2|----LED----GND
 *   SCL|-------|SCL     A.3|----LED----GND
 *      |       |           |
 * R. Pi|       | MCP23017  |            
 * _____|       |___________|
 *
 *
 *
 */     

//#include <stdio.h>
//#include <unistd.h>
//#include <rpiGpio.h>
//#include <linux/i2c-dev.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>


#define ADDR_MAG 0x1E
#define ADDR_ACC 0x4C

class I2CDevice
{
public:
	I2CDevice() :
		m_Fd(0), m_Addr(0) {}

	void SetFD( int fd ) { m_Fd = fd; }
	void SetAddr( unsigned char addr ) { m_Addr = addr; }
	
	virtual void DumpRegisters() = 0;
	
protected:
	
	bool WriteByte(unsigned char byte)
	{
		unsigned char buff = byte;

		if( write(m_Fd, &buff, 1) != 1)
                {
                	printf("Recieved NAK\n");
                       	// NAK recieved
                       	return false;
                }

		return true;
	}

	bool ReadByte(unsigned char* byte)
	{
		*byte = 0;
		if( read(m_Fd, byte, 1) != 1)
		{
			printf("Read error\n");
			return false;
		}

		return true;
	}

	bool ReadAddressByte( unsigned char addr, unsigned char* data )
	{
		bool success = true;
		success = WriteByte(addr);
		
		success = ReadByte(data) && success;

		return success;
	}
	bool WriteAddressByte( unsigned char addr, unsigned char data)
	{
		bool success = true;
		success = WriteByte(addr);
		success = WriteByte(data) && success;
		return success;
	}

	bool MakeActive()
	{
		if( ioctl( m_Fd, I2C_SLAVE, m_Addr) < 0 )
		{
			printf("Error access I2C Buss");
			return false;
		}
		
		return true;
	}
	
	int m_Fd;
	unsigned char m_Addr;

};

class HMC5983DigitalCompass : public I2CDevice
{
public:

	HMC5983DigitalCompass() : I2CDevice() {}

	virtual void DumpRegisters()
	{
		printf("Dumping Registers for device at Address %#04x\n", m_Addr);

		MakeActive();
		unsigned char regs[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,49,50};
		int nRegs = 15;
		unsigned char buff;

		for( int ii = 0; ii < nRegs; ii++ )
		{
			if( ReadAddressByte( regs[ii], &buff ) )
				printf("@[%#04x] = %#04x\n", regs[ii], buff);	
			else
				printf("@[%#04x] Read Error", regs[ii]);
		}

		//MakeActive();
		//unsigned char ddt[] = {0x02,0x00};
		//write(m_Fd, &ddt, 2);
		//WriteAddressByte(0x02, 0x00);

	}
private:

};

class MMA7660FCAccelerometer : public I2CDevice
{
public:

	MMA7660FCAccelerometer() : I2CDevice() {}

	virtual void DumpRegisters()
        {
                printf("Dumping Registers for device at Address %#04x\n", m_Addr);

                MakeActive();
                unsigned char regs[] = {0,1,2,3,4,5,6,7,8,9,10};
                int nRegs = 11;
                unsigned char buff;

		if( !WriteByte(0x00) )
			printf("WriteError\n");

		unsigned char buffs[nRegs];
		read(m_Fd, &buffs, nRegs);

                for( int ii = 0; ii < nRegs; ii++ )
                {
                        //if( ReadByte( &buff ) )
                                printf("@[%#04x] = %#04x\n", regs[ii], buffs[ii]);
                        //else
                         //       printf("@[%#04x] Read Error", regs[ii]);
                }
		
		//sleep(1);
		//MakeActive();
		//{
		//unsigned char ddts[] = {0x07, 0x01, 0x00};
		//write(m_Fd, &ddts,2);
		//}
//		WriteAddressByte(0x07, 0x01);
        }


private:
};

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

	HMC5983DigitalCompass mag;
	MMA7660FCAccelerometer acc;
	mag.SetFD( fd );
	acc.SetFD( fd );
	mag.SetAddr( ADDR_MAG );
	acc.SetAddr( ADDR_ACC );

	mag.DumpRegisters();
	//sleep(1);
	//mag.DumpRegisters();
	acc.DumpRegisters();
	//sleep(1);
	acc.DumpRegisters();

		
	close(fd);
    
	return 0;
} 



