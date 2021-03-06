/*
 Copyright (C) 1991-2014 Altera Corporation. All rights reserved.
 Your use of Altera Corporation's design tools, logic functions 
 and other software and tools, and its AMPP partner logic 
 functions, and any output files from any of the foregoing 
 (including device programming or simulation files), and any 
 associated documentation or information are expressly subject 
 to the terms and conditions of the Altera Program License 
 Subscription Agreement, the Altera Quartus II License Agreement,
 the Altera MegaCore Function License Agreement, or other 
 applicable license agreement, including, without limitation, 
 that your use is for the sole purpose of programming logic 
 devices manufactured by Altera and sold by Altera or its 
 authorized distributors.  Please refer to the applicable 
 agreement for further details.
*/
MODEL
/*MODEL HEADER*/
/*
 This file contains Slow Corner delays for the design using part 5M160ZT100C5
 with speed grade 5, core voltage Auto, and temperature 2147483647 Celsius

*/
MODEL_VERSION "1.0";
DESIGN "IntegratorCLPD";
DATE "10/11/2015 00:15:54";
PROGRAM "Quartus II 64-Bit";



INPUT clrReg;
INPUT flgIn[0];
INPUT pulse;
INPUT flgIn[1];
INPUT flgIn[2];
INPUT flgIn[3];
INPUT flgIn[4];
INPUT flgIn[5];
INPUT latch;
INPUT wordSelect;
INPUT dataIn;
INPUT fvcIn;
OUTPUT flgOut[0];
OUTPUT flgOut[1];
OUTPUT flgOut[2];
OUTPUT flgOut[3];
OUTPUT flgOut[4];
OUTPUT flgOut[5];
OUTPUT output;
OUTPUT loaded;
OUTPUT dataOut[0];
OUTPUT dataOut[1];
OUTPUT dataOut[2];
OUTPUT dataOut[3];
OUTPUT dataOut[4];
OUTPUT dataOut[5];
OUTPUT dataOut[6];
OUTPUT dataOut[7];
OUTPUT dataOut[8];
OUTPUT dataOut[9];
OUTPUT dataOut[10];
OUTPUT dataOut[11];
OUTPUT dataOut[12];
OUTPUT dataOut[13];
OUTPUT dataOut[14];
OUTPUT dataOut[15];

/*Arc definitions start here*/
pos_dataIn__latch__setup:		SETUP (POSEDGE) dataIn latch ;
pos_clrReg__pulse__setup:		SETUP (POSEDGE) clrReg pulse ;
pos_flgIn[0]__pulse__setup:		SETUP (POSEDGE) flgIn[0] pulse ;
pos_flgIn[1]__pulse__setup:		SETUP (POSEDGE) flgIn[1] pulse ;
pos_flgIn[2]__pulse__setup:		SETUP (POSEDGE) flgIn[2] pulse ;
pos_flgIn[3]__pulse__setup:		SETUP (POSEDGE) flgIn[3] pulse ;
pos_flgIn[4]__pulse__setup:		SETUP (POSEDGE) flgIn[4] pulse ;
pos_flgIn[5]__pulse__setup:		SETUP (POSEDGE) flgIn[5] pulse ;
pos_dataIn__latch__hold:		HOLD (POSEDGE) dataIn latch ;
pos_clrReg__pulse__hold:		HOLD (POSEDGE) clrReg pulse ;
pos_flgIn[0]__pulse__hold:		HOLD (POSEDGE) flgIn[0] pulse ;
pos_flgIn[1]__pulse__hold:		HOLD (POSEDGE) flgIn[1] pulse ;
pos_flgIn[2]__pulse__hold:		HOLD (POSEDGE) flgIn[2] pulse ;
pos_flgIn[3]__pulse__hold:		HOLD (POSEDGE) flgIn[3] pulse ;
pos_flgIn[4]__pulse__hold:		HOLD (POSEDGE) flgIn[4] pulse ;
pos_flgIn[5]__pulse__hold:		HOLD (POSEDGE) flgIn[5] pulse ;
pos_eq__dataOut[0]__delay:		DELAY (POSEDGE) eq dataOut[0] ;
pos_eq__dataOut[1]__delay:		DELAY (POSEDGE) eq dataOut[1] ;
pos_eq__dataOut[2]__delay:		DELAY (POSEDGE) eq dataOut[2] ;
pos_eq__dataOut[3]__delay:		DELAY (POSEDGE) eq dataOut[3] ;
pos_eq__dataOut[4]__delay:		DELAY (POSEDGE) eq dataOut[4] ;
pos_eq__dataOut[5]__delay:		DELAY (POSEDGE) eq dataOut[5] ;
pos_eq__dataOut[6]__delay:		DELAY (POSEDGE) eq dataOut[6] ;
pos_eq__dataOut[7]__delay:		DELAY (POSEDGE) eq dataOut[7] ;
pos_eq__dataOut[8]__delay:		DELAY (POSEDGE) eq dataOut[8] ;
pos_eq__dataOut[9]__delay:		DELAY (POSEDGE) eq dataOut[9] ;
pos_eq__dataOut[10]__delay:		DELAY (POSEDGE) eq dataOut[10] ;
pos_eq__dataOut[11]__delay:		DELAY (POSEDGE) eq dataOut[11] ;
pos_eq__dataOut[12]__delay:		DELAY (POSEDGE) eq dataOut[12] ;
pos_eq__dataOut[13]__delay:		DELAY (POSEDGE) eq dataOut[13] ;
pos_eq__dataOut[14]__delay:		DELAY (POSEDGE) eq dataOut[14] ;
pos_eq__dataOut[15]__delay:		DELAY (POSEDGE) eq dataOut[15] ;
pos_eq__output__delay:		DELAY (POSEDGE) eq output ;
pos_eq__output__delay:		DELAY (POSEDGE) eq output ;
pos_latch__loaded__delay:		DELAY (POSEDGE) latch loaded ;
pos_pulse__flgOut[0]__delay:		DELAY (POSEDGE) pulse flgOut[0] ;
pos_pulse__flgOut[1]__delay:		DELAY (POSEDGE) pulse flgOut[1] ;
pos_pulse__flgOut[2]__delay:		DELAY (POSEDGE) pulse flgOut[2] ;
pos_pulse__flgOut[3]__delay:		DELAY (POSEDGE) pulse flgOut[3] ;
pos_pulse__flgOut[4]__delay:		DELAY (POSEDGE) pulse flgOut[4] ;
pos_pulse__flgOut[5]__delay:		DELAY (POSEDGE) pulse flgOut[5] ;
___17.741__delay:		DELAY  17.741 ;
___20.403__delay:		DELAY  20.403 ;
___21.895__delay:		DELAY  21.895 ;
___21.461__delay:		DELAY  21.461 ;
___16.783__delay:		DELAY  16.783 ;
___14.702__delay:		DELAY  14.702 ;
___12.716__delay:		DELAY  12.716 ;
___19.615__delay:		DELAY  19.615 ;
___19.646__delay:		DELAY  19.646 ;
___19.756__delay:		DELAY  19.756 ;
___17.969__delay:		DELAY  17.969 ;
___19.541__delay:		DELAY  19.541 ;
___19.996__delay:		DELAY  19.996 ;
___20.411__delay:		DELAY  20.411 ;
___17.828__delay:		DELAY  17.828 ;
___17.930__delay:		DELAY  17.930 ;

ENDMODEL
