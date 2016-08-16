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
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>


#define ADDR 0x4C
static int set_i2c_register(int file,
                            unsigned char addr,
                            unsigned char reg,
                            unsigned char value) {

    unsigned char outbuf[2];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];

    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = sizeof(outbuf);
    messages[0].buf   = outbuf;

    /* The first byte indicates which register we'll write */
    outbuf[0] = reg;

    /* 
     * The second byte indicates the value to write.  Note that for many
     * devices, we can write multiple, sequential registers at once by
     * simply making outbuf bigger.
     */
    outbuf[1] = value;

    /* Transfer the i2c packets to the kernel and verify it worked */
    packets.msgs  = messages;
    packets.nmsgs = 1;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return 0;
}


static int get_i2c_register(int file,
                            unsigned char addr,
                            unsigned char reg,
                            unsigned char *val) {
    unsigned char inbuf, outbuf;
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    /*
     * In order to read a register, we first do a "dummy write" by writing
     * 0 bytes to the register we want to read from.  This is similar to
     * the packet in set_i2c_register, except it's 1 byte rather than 2.
     */
    outbuf = reg;
    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = sizeof(outbuf);
    messages[0].buf   = &outbuf;

    /* The data will get returned in this structure */
    messages[1].addr  = addr;
    messages[1].flags = I2C_M_RD;// | I2C_M_NOSTART;
    messages[1].len   = sizeof(inbuf);
    messages[1].buf   = &inbuf;

    /* Send the request to the kernel and get the result back */
    packets.msgs      = messages;
    packets.nmsgs     = 2;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }
    *val = inbuf;

    return 0;
}


int main(void)
{ 

	int fd, i;
	const char* fileName = "/dev/i2c-1";

	if( (fd = open(fileName, O_RDWR)) < 0 )
        {

                printf("Failed to open i2c port\n");
                return 1;
        }
        else
        {
                printf("i2c Port opened\n");
        }


	if( ioctl( fd, I2C_SLAVE, ADDR) < 0 )
	{
		printf("Unable to get bus access to talk to slave\n");
		
	}
	else
	{
		printf("Opened port to slave %#04x\n", ADDR);
	}

	unsigned char val = 0;
	unsigned char reg = 0x07;
	get_i2c_register( fd, ADDR, reg, &val); 
	printf(" @[%#04x] = %#04x\n", reg, val );
  	sleep(1);
	ioctl( fd, I2C_SLAVE, ADDR);
	unsigned char tts[] = {0x07, 0x01  | 0x08};
	write(fd, tts, 2);
	//set_i2c_register( fd, ADDR, reg, 0x00);
	sleep(1);
	val = 0;
	get_i2c_register( fd, ADDR, reg, &val);
        printf(" @[%#04x] = %#04x\n", reg, val );


	close(fd);
    
	return 0;
} 



