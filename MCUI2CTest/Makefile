CC = g++
FLAGS = -g -Wall
LIBS = #-L../../RaspberryPi-GPIO/library
INC = #-I../../RaspberryPi-GPIO/include

I2COrient3: main_i2cOrient3.o
	$(CC) $(FLAGS) $(LIBS) -o I2COrient3 main_i2cOrient3.o


I2COrient2: main_i2cOrient2.o
	$(CC) $(FLAGS) $(LIBS) -o I2COrient2 main_i2cOrient2.o


I2CKernTest: main_i2cKernTest.o
	$(CC) $(FLAGS) $(LIBS) -o I2CKernTest main_i2cKernTest.o


I2COrient: main_i2cOrient.o
	$(CC) $(FLAGS) $(LIBS) -o I2COrient main_i2cOrient.o


I2CSniff: main_i2cSniffer.o
	$(CC) $(FLAGS) $(LIBS) -o I2CSniffer main_i2cSniffer.o

I2CTest: main_i2c.o
	$(CC) $(FLAGS) $(LIBS) -o I2CProg main_i2c.o #-lm -lrpigpio

main_i2c.o: main_i2c.cpp
	$(CC) $(FLAGS) $(INC) -c main_i2c.cpp
