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

#define MCP23017_IODIRA     0x00
#define MCP23017_GPIOA      0x12
#define MCP23017_ADDRESS    0x20

using std::list;

int main(void)
{ 

	int fd, i;
	char* fileName = "/dev/i2c-1";
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



	for( address = 0x01; address < 128; address++ )
	{

		// check to see if the address is reserved


		if( ioctl( fd, I2C_SLAVE, address) < 0 )
		{
			// unable to get bus access to talk to slave
			continue;
		}
		else
		{	// successfully opened
			//printf("Opened port to slave %#04x\n", address);
		}

		buff = 0x01;
		if( write(fd, &buff, 1) != 1)
       		 {
			// NAK recieved
			continue;
	        }
		else
		{
			printf("Recieved ACK from slave @ port %#04x\n", address);
		}

	}
	
	close(fd);
    
	return 0;
} 



