EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:DigitalLogic
LIBS:Minicircuits
LIBS:SiteControl-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PIC16LF1947 U6
U 1 1 57A9B825
P 9700 1850
F 0 "U6" H 9650 2450 60  0000 C CNN
F 1 "PIC16LF1947" H 9650 2300 60  0000 C CNN
F 2 "DigitalLogic:PIC16_TDQFP64_pcb" H 9750 800 60  0001 C CNN
F 3 "" H 9750 800 60  0000 C CNN
	1    9700 1850
	1    0    0    -1  
$EndComp
$Comp
L PIC16LF1947 U6
U 2 1 57A9B8B0
P 3850 1950
F 0 "U6" H 3800 2550 60  0000 C CNN
F 1 "PIC16LF1947" H 3800 2400 60  0000 C CNN
F 2 "DigitalLogic:PIC16_TDQFP64_pcb" H 3900 900 60  0001 C CNN
F 3 "" H 3900 900 60  0000 C CNN
	2    3850 1950
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR35
U 1 1 57A9BBC7
P 8850 1250
F 0 "#PWR35" H 8850 1100 50  0001 C CNN
F 1 "+3.3V" H 8850 1390 50  0000 C CNN
F 2 "" H 8850 1250 50  0000 C CNN
F 3 "" H 8850 1250 50  0000 C CNN
	1    8850 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR39
U 1 1 57A9BC01
P 10200 2150
F 0 "#PWR39" H 10200 1900 50  0001 C CNN
F 1 "GND" H 10200 2000 50  0000 C CNN
F 2 "" H 10200 2150 50  0000 C CNN
F 3 "" H 10200 2150 50  0000 C CNN
	1    10200 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR36
U 1 1 57A9BC3D
P 8850 2000
F 0 "#PWR36" H 8850 1750 50  0001 C CNN
F 1 "GND" H 8850 1850 50  0000 C CNN
F 2 "" H 8850 2000 50  0000 C CNN
F 3 "" H 8850 2000 50  0000 C CNN
	1    8850 2000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR37
U 1 1 57A9BC52
P 9100 1350
F 0 "#PWR37" H 9100 1200 50  0001 C CNN
F 1 "+3.3V" H 9100 1490 50  0000 C CNN
F 2 "" H 9100 1350 50  0000 C CNN
F 3 "" H 9100 1350 50  0000 C CNN
	1    9100 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 1350 9100 2000
Wire Wire Line
	9100 2000 9200 2000
Wire Wire Line
	9200 1900 9100 1900
Connection ~ 9100 1900
Wire Wire Line
	9200 1800 9100 1800
Connection ~ 9100 1800
Wire Wire Line
	9200 1700 9100 1700
Connection ~ 9100 1700
Wire Wire Line
	10150 1700 10200 1700
Wire Wire Line
	10200 1600 10200 2150
Wire Wire Line
	10150 1800 10200 1800
Connection ~ 10200 1800
Wire Wire Line
	10150 1900 10200 1900
Connection ~ 10200 1900
Wire Wire Line
	10150 2000 10200 2000
Connection ~ 10200 2000
Wire Wire Line
	10150 1600 10200 1600
Connection ~ 10200 1700
$Comp
L C C6
U 1 1 57A9BD20
P 8850 1800
F 0 "C6" H 8875 1900 50  0000 L CNN
F 1 "100nF" H 8875 1700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8888 1650 50  0001 C CNN
F 3 "" H 8850 1800 50  0000 C CNN
	1    8850 1800
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 57A9BD87
P 8850 1450
F 0 "R4" V 8930 1450 50  0000 C CNN
F 1 "10R" V 8850 1450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 8780 1450 50  0001 C CNN
F 3 "" H 8850 1450 50  0000 C CNN
	1    8850 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1600 8850 1650
Wire Wire Line
	8850 1300 8850 1250
Wire Wire Line
	8850 1950 8850 2000
Connection ~ 8850 1600
Wire Wire Line
	9200 1600 8850 1600
$Comp
L R R3
U 1 1 57A9C213
P 1650 2350
F 0 "R3" V 1730 2350 50  0000 C CNN
F 1 "100R" V 1650 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1580 2350 50  0001 C CNN
F 3 "" H 1650 2350 50  0000 C CNN
	1    1650 2350
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 57A9C390
P 1300 2100
F 0 "R2" V 1380 2100 50  0000 C CNN
F 1 "10K" V 1300 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1230 2100 50  0001 C CNN
F 3 "" H 1300 2100 50  0000 C CNN
	1    1300 2100
	-1   0    0    1   
$EndComp
$Comp
L C C1
U 1 1 57A9C483
P 1300 2550
F 0 "C1" H 1325 2650 50  0000 L CNN
F 1 "100nF" H 1325 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1338 2400 50  0001 C CNN
F 3 "" H 1300 2550 50  0000 C CNN
	1    1300 2550
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR28
U 1 1 57A9C7AB
P 1300 1850
F 0 "#PWR28" H 1300 1700 50  0001 C CNN
F 1 "+3.3V" H 1300 1990 50  0000 C CNN
F 2 "" H 1300 1850 50  0000 C CNN
F 3 "" H 1300 1850 50  0000 C CNN
	1    1300 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR29
U 1 1 57A9C7CB
P 1300 2800
F 0 "#PWR29" H 1300 2550 50  0001 C CNN
F 1 "GND" H 1300 2650 50  0000 C CNN
F 2 "" H 1300 2800 50  0000 C CNN
F 3 "" H 1300 2800 50  0000 C CNN
	1    1300 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2350 1800 2350
Wire Wire Line
	1150 2350 1500 2350
Wire Wire Line
	1300 2250 1300 2400
Connection ~ 1300 2350
Wire Wire Line
	1300 2700 1300 2800
Wire Wire Line
	1300 1950 1300 1850
Text GLabel 1150 2350 0    60   Input ~ 0
MCLR
Text GLabel 5600 2850 2    60   Input ~ 0
RPi_En
Text GLabel 2650 2050 0    60   Input ~ 0
CMOS_TX
Text GLabel 2650 2150 0    60   Input ~ 0
CMOS_RX
Text GLabel 2600 2850 0    60   Input ~ 0
INV_Toggle_Safe
Text GLabel 2600 3050 0    60   Input ~ 0
INV_Temp_Safe
Text GLabel 2600 2750 0    60   Input ~ 0
INV_Power_Safe
Text GLabel 2600 2950 0    60   Input ~ 0
INV_Overload_Safe
Text GLabel 5600 2750 2    60   Input ~ 0
CMOS_CTS
Text GLabel 5600 2550 2    60   Input ~ 0
CMOS_RTS
Text GLabel 2600 4250 0    60   Input ~ 0
INV_Data_Safe
Text GLabel 2600 4350 0    60   Input ~ 0
Pi_VSense
Text GLabel 5600 1750 2    60   Input ~ 0
PiSCL
Text GLabel 5600 1850 2    60   Input ~ 0
PiSDA
Text GLabel 5600 2050 2    60   Input ~ 0
PGED
Text GLabel 5600 2350 2    60   Input ~ 0
PGEC
Text GLabel 5600 2150 2    60   Input ~ 0
CLKIN
Text GLabel 5350 3450 2    60   Input ~ 0
ADC_nCS
Text GLabel 5350 3150 2    60   Input ~ 0
SCLK
Text GLabel 5350 3250 2    60   Input ~ 0
SDI
Text GLabel 5350 3350 2    60   Input ~ 0
SDO
Text GLabel 2600 4150 0    60   Input ~ 0
Modem_En
Wire Wire Line
	2750 2050 2650 2050
Wire Wire Line
	2650 2150 2750 2150
Wire Wire Line
	2750 4250 2600 4250
Wire Wire Line
	2600 4350 2750 4350
Wire Wire Line
	5350 3350 5100 3350
Wire Wire Line
	5100 3250 5350 3250
Wire Wire Line
	5350 3150 5100 3150
Wire Wire Line
	5600 2350 5100 2350
Wire Wire Line
	5100 2150 5600 2150
Wire Wire Line
	5600 2050 5100 2050
Wire Wire Line
	5100 1850 5600 1850
Wire Wire Line
	5100 1750 5600 1750
$Comp
L CONN_01X06 J4
U 1 1 57A9D8BD
P 7550 3750
F 0 "J4" H 7550 4100 50  0000 C CNN
F 1 "CONN_01X06" V 7650 3750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 7550 3750 50  0001 C CNN
F 3 "" H 7550 3750 50  0000 C CNN
	1    7550 3750
	1    0    0    -1  
$EndComp
Text GLabel 7200 3900 0    60   Input ~ 0
PGEC
Text GLabel 7200 3800 0    60   Input ~ 0
PGED
Text GLabel 7150 3500 0    60   Input ~ 0
MCLR
$Comp
L GND #PWR32
U 1 1 57A9DD08
P 7250 4100
F 0 "#PWR32" H 7250 3850 50  0001 C CNN
F 1 "GND" H 7250 3950 50  0000 C CNN
F 2 "" H 7250 4100 50  0000 C CNN
F 3 "" H 7250 4100 50  0000 C CNN
	1    7250 4100
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR31
U 1 1 57A9DD2B
P 7250 3350
F 0 "#PWR31" H 7250 3200 50  0001 C CNN
F 1 "+3.3V" H 7250 3490 50  0000 C CNN
F 2 "" H 7250 3350 50  0000 C CNN
F 3 "" H 7250 3350 50  0000 C CNN
	1    7250 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3500 7350 3500
Wire Wire Line
	7250 3350 7250 3600
Wire Wire Line
	7250 3600 7350 3600
Wire Wire Line
	7350 3700 7250 3700
Wire Wire Line
	7250 3700 7250 4100
Wire Wire Line
	7200 3800 7350 3800
Wire Wire Line
	7350 3900 7200 3900
$Comp
L C C2
U 1 1 57A9E2E7
P 7000 1550
F 0 "C2" H 7025 1650 50  0000 L CNN
F 1 "100nF" H 7025 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7038 1400 50  0001 C CNN
F 3 "" H 7000 1550 50  0000 C CNN
	1    7000 1550
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 57A9E4DC
P 7250 1550
F 0 "C3" H 7275 1650 50  0000 L CNN
F 1 "100nF" H 7275 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7288 1400 50  0001 C CNN
F 3 "" H 7250 1550 50  0000 C CNN
	1    7250 1550
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 57A9E550
P 7500 1550
F 0 "C4" H 7525 1650 50  0000 L CNN
F 1 "100nF" H 7525 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7538 1400 50  0001 C CNN
F 3 "" H 7500 1550 50  0000 C CNN
	1    7500 1550
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 57A9E556
P 7750 1550
F 0 "C5" H 7775 1650 50  0000 L CNN
F 1 "100nF" H 7775 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7788 1400 50  0001 C CNN
F 3 "" H 7750 1550 50  0000 C CNN
	1    7750 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR34
U 1 1 57A9E72E
P 7400 1800
F 0 "#PWR34" H 7400 1550 50  0001 C CNN
F 1 "GND" H 7400 1650 50  0000 C CNN
F 2 "" H 7400 1800 50  0000 C CNN
F 3 "" H 7400 1800 50  0000 C CNN
	1    7400 1800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR33
U 1 1 57A9E8C5
P 7400 1300
F 0 "#PWR33" H 7400 1150 50  0001 C CNN
F 1 "+3.3V" H 7400 1440 50  0000 C CNN
F 2 "" H 7400 1300 50  0000 C CNN
F 3 "" H 7400 1300 50  0000 C CNN
	1    7400 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1400 7000 1350
Wire Wire Line
	7000 1350 7750 1350
Wire Wire Line
	7750 1350 7750 1400
Wire Wire Line
	7400 1300 7400 1350
Connection ~ 7400 1350
Wire Wire Line
	7500 1350 7500 1400
Connection ~ 7500 1350
Wire Wire Line
	7250 1400 7250 1350
Connection ~ 7250 1350
Wire Wire Line
	7000 1700 7000 1750
Wire Wire Line
	7000 1750 7750 1750
Wire Wire Line
	7750 1750 7750 1700
Wire Wire Line
	7500 1700 7500 1750
Connection ~ 7500 1750
Wire Wire Line
	7250 1700 7250 1750
Connection ~ 7250 1750
Wire Wire Line
	7400 1800 7400 1750
Connection ~ 7400 1750
$Comp
L Crystal_Small Y1
U 1 1 57A9EF19
P 9150 3700
F 0 "Y1" H 9150 3800 50  0000 C CNN
F 1 "4MHz" H 9150 3600 50  0000 C CNN
F 2 "Crystals:Q_49U3HMS" H 9150 3700 50  0001 C CNN
F 3 "" H 9150 3700 50  0000 C CNN
F 4 "ATS040SM" H 8650 3700 60  0000 C CNN "Part Number"
	1    9150 3700
	-1   0    0    1   
$EndComp
$Comp
L CP1 C7
U 1 1 57A9F1E8
P 8900 3900
F 0 "C7" H 8925 4000 50  0000 L CNN
F 1 "30-36pF" H 8925 3800 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeR_EIA-2012" H 8900 3900 50  0001 C CNN
F 3 "" H 8900 3900 50  0000 C CNN
	1    8900 3900
	1    0    0    -1  
$EndComp
$Comp
L CP1 C8
U 1 1 57A9F34B
P 9400 3900
F 0 "C8" H 9425 4000 50  0000 L CNN
F 1 "30-36pF" H 9425 3800 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeR_EIA-2012" H 9400 3900 50  0001 C CNN
F 3 "" H 9400 3900 50  0000 C CNN
	1    9400 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR38
U 1 1 57A9F3A0
P 9150 4200
F 0 "#PWR38" H 9150 3950 50  0001 C CNN
F 1 "GND" H 9150 4050 50  0000 C CNN
F 2 "" H 9150 4200 50  0000 C CNN
F 3 "" H 9150 4200 50  0000 C CNN
	1    9150 4200
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 57A9F5E5
P 9150 3450
F 0 "R5" V 9230 3450 50  0000 C CNN
F 1 "R" V 9150 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 9080 3450 50  0001 C CNN
F 3 "" H 9150 3450 50  0000 C CNN
	1    9150 3450
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 57A9F906
P 9650 3450
F 0 "R6" V 9730 3450 50  0000 C CNN
F 1 "0R" V 9650 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 9580 3450 50  0001 C CNN
F 3 "" H 9650 3450 50  0000 C CNN
	1    9650 3450
	0    -1   -1   0   
$EndComp
Text GLabel 9850 3450 2    60   Input ~ 0
CLKOUT
Text GLabel 8850 3450 0    60   Input ~ 0
CLKIN
Wire Wire Line
	8850 3450 9000 3450
Wire Wire Line
	8900 3450 8900 3750
Wire Wire Line
	8900 3700 9050 3700
Connection ~ 8900 3700
Connection ~ 8900 3450
Wire Wire Line
	9300 3450 9500 3450
Wire Wire Line
	9400 3450 9400 3750
Wire Wire Line
	9400 3700 9250 3700
Connection ~ 9400 3700
Connection ~ 9400 3450
Wire Wire Line
	9800 3450 9850 3450
Wire Wire Line
	8900 4050 8900 4150
Wire Wire Line
	8900 4150 9400 4150
Wire Wire Line
	9400 4150 9400 4050
Wire Wire Line
	9150 4200 9150 4150
Connection ~ 9150 4150
NoConn ~ 9150 3450
Wire Notes Line
	6650 2850 8050 2850
Wire Notes Line
	8050 2850 8050 4550
Wire Notes Line
	8050 4550 6650 4550
Wire Notes Line
	6650 4550 6650 2850
Wire Notes Line
	8300 2850 10450 2850
Wire Notes Line
	10450 2850 10450 4550
Wire Notes Line
	10450 4550 8300 4550
Wire Notes Line
	8300 4550 8300 2850
Wire Notes Line
	8300 900  8300 2550
Wire Notes Line
	8300 2550 10450 2550
Wire Notes Line
	10450 2550 10450 900 
Wire Notes Line
	10450 900  8300 900 
Wire Notes Line
	6650 2550 8050 2550
Wire Notes Line
	8050 2550 8050 900 
Wire Notes Line
	8050 900  6650 900 
Wire Notes Line
	6650 900  6650 2550
Text GLabel 5600 2250 2    60   Input ~ 0
CLKOUT
Wire Wire Line
	5600 2250 5100 2250
Text Notes 8750 3000 0    60   ~ 0
Crystal Oscillator
Text Notes 6800 3000 0    60   ~ 0
Programming Header\n
Text Notes 6850 1050 0    60   ~ 0
Decoupling
Text Notes 9350 1050 0    60   ~ 0
Power
NoConn ~ 2750 1850
NoConn ~ 2750 1950
NoConn ~ 2750 2450
NoConn ~ 2750 2550
NoConn ~ 2750 2650
NoConn ~ 2750 3150
NoConn ~ 2750 3250
NoConn ~ 2750 3750
NoConn ~ 2750 3850
NoConn ~ 5100 4250
NoConn ~ 5100 4150
NoConn ~ 5100 4050
NoConn ~ 5100 3950
NoConn ~ 5100 3750
NoConn ~ 5100 3850
NoConn ~ 5100 3650
NoConn ~ 5100 3050
NoConn ~ 5100 1950
NoConn ~ 7350 4000
NoConn ~ 2750 2250
Wire Wire Line
	1500 4250 1750 4250
Wire Wire Line
	1750 4250 1700 4200
Wire Wire Line
	1750 4250 1700 4300
Connection ~ 1750 4250
Wire Wire Line
	800  2150 1050 2150
Wire Wire Line
	1050 2150 1000 2100
Wire Wire Line
	1050 2150 1000 2200
Connection ~ 1050 2150
Wire Wire Line
	1000 2050 750  2050
Wire Wire Line
	750  2050 800  2100
Wire Wire Line
	750  2050 800  2000
Connection ~ 750  2050
Text Notes 9200 3400 0    60   ~ 0
DNP
$Comp
L R R37
U 1 1 57B01919
P 5200 1500
F 0 "R37" V 5280 1500 50  0000 C CNN
F 1 "1K5" V 5200 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5130 1500 50  0001 C CNN
F 3 "" H 5200 1500 50  0000 C CNN
	1    5200 1500
	-1   0    0    1   
$EndComp
$Comp
L R R38
U 1 1 57B01B67
P 5400 1500
F 0 "R38" V 5480 1500 50  0000 C CNN
F 1 "1K5" V 5400 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5330 1500 50  0001 C CNN
F 3 "" H 5400 1500 50  0000 C CNN
	1    5400 1500
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR30
U 1 1 57B01D69
P 5300 1300
F 0 "#PWR30" H 5300 1150 50  0001 C CNN
F 1 "+3.3V" H 5300 1440 50  0000 C CNN
F 2 "" H 5300 1300 50  0000 C CNN
F 3 "" H 5300 1300 50  0000 C CNN
	1    5300 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1350 5200 1300
Wire Wire Line
	5200 1300 5400 1300
Wire Wire Line
	5400 1300 5400 1350
Connection ~ 5300 1300
Wire Wire Line
	5200 1650 5200 1750
Connection ~ 5200 1750
Wire Wire Line
	5400 1650 5400 1850
Connection ~ 5400 1850
Text Notes 5900 1100 2    60   ~ 0
SCL/SDA Pullup Resistors
Wire Wire Line
	2750 3050 2600 3050
NoConn ~ 2750 3650
NoConn ~ 2750 3550
NoConn ~ 2750 3450
Wire Wire Line
	2600 2750 2750 2750
Wire Wire Line
	2750 2850 2600 2850
Wire Wire Line
	2600 2950 2750 2950
Wire Wire Line
	2750 4150 2600 4150
Text GLabel 5600 2450 2    60   Input ~ 0
RPi_5V_En
Wire Wire Line
	5600 2450 5100 2450
NoConn ~ 5100 4350
NoConn ~ 2750 3950
NoConn ~ 2750 4050
NoConn ~ 2750 1750
Wire Wire Line
	5600 2550 5100 2550
Wire Wire Line
	5100 2750 5600 2750
Wire Wire Line
	5600 2850 5100 2850
NoConn ~ 5100 2650
Wire Wire Line
	5100 2950 5350 2950
Text GLabel 5350 3550 2    60   Input ~ 0
RTC_nCS
Wire Wire Line
	5100 3450 5350 3450
Wire Wire Line
	5350 3550 5100 3550
Text GLabel 5350 2950 2    60   Input ~ 0
RTC_MFP
Text Notes 7175 6800 0    60   ~ 0
Applied Physics Club\nThe Pennsylvania State University
Text Notes 9100 7650 2    60   ~ 0
September 27, 2016
Text Notes 9075 7500 2    60   ~ 0
Telescope Base Station Control Board
Text Notes 10600 7650 0    60   ~ 0
B
$EndSCHEMATC
