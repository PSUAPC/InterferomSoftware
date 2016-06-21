CC = g++
CFLAGS = -g -Wall
LIBS = #-L../../RaspberryPi-GPIO/library
INC = #-I../../RaspberryPi-GPIO/include
BUILDDIR := build
BINDIR := bin
SRCDIR := src
SRCEXT := cpp

I2COrient3: $(BUILDDIR)/main_i2cOrient3.o
	@mkdir -p $(BINDIR)
	@echo $(CC) $(CFLAGS) $(LIBS) -o $(BINDIR)/I2COrient3 $(BUILDDIR)/main_i2cOrient3.o


I2COrient2: $(BUILDDIR)/main_i2cOrient2.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) -o $(BINDIR)/I2COrient2 $(BUILDDIR)/main_i2cOrient2.o


I2CKernTest: $(BUILDDIR)/main_i2cKernTest.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) -o $(BINDIR)/I2CKernTest  $(BUILDDIR)/main_i2cKernTest.o


I2COrient: $(BUILDDIR)/main_i2cOrient.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) -o $(BINDIR)/I2COrient  $(BUILDDIR)/main_i2cOrient.o


I2CSniff: $(BUILDDIR)/main_i2cSniffer.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) -o $(BINDIR)/I2CSniffer  $(BUILDDIR)/main_i2cSniffer.o

I2CTest: $(BUILDDIR)/main_i2c.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) -o $(BINDIR)/I2CProg  $(BUILDDIR)/main_i2c.o #-lm -lrpigpio

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR)"; $(RM) -r $(BUILDDIR)



.PHONY: clean 
