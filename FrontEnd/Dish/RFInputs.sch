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
LIBS:DishFront-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
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
L BNC P1
U 1 1 57C9C71D
P 1800 2200
F 0 "P1" H 1810 2320 50  0000 C CNN
F 1 "BNC" V 1910 2140 50  0000 C CNN
F 2 "DigitalLogic:UMCC_PCB" H 1800 2200 50  0001 C CNN
F 3 "" H 1800 2200 50  0000 C CNN
	1    1800 2200
	-1   0    0    -1  
$EndComp
$Comp
L MC_DBTC-17-5_Coupler U24
U 1 1 57C9C7F0
P 2500 1600
F 0 "U24" H 2500 1750 60  0000 C CNN
F 1 "MC_DBTC-17-5_Coupler" H 2550 1650 60  0000 C CNN
F 2 "Minicircuits:MC_AT790-1" H 2500 1600 60  0001 C CNN
F 3 "" H 2500 1600 60  0001 C CNN
	1    2500 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR049
U 1 1 57C9C8F6
P 1800 2500
F 0 "#PWR049" H 1800 2250 50  0001 C CNN
F 1 "GND" H 1800 2350 50  0000 C CNN
F 2 "" H 1800 2500 50  0000 C CNN
F 3 "" H 1800 2500 50  0000 C CNN
	1    1800 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR050
U 1 1 57C9C92C
P 2950 1850
F 0 "#PWR050" H 2950 1600 50  0001 C CNN
F 1 "GND" H 2950 1700 50  0000 C CNN
F 2 "" H 2950 1850 50  0000 C CNN
F 3 "" H 2950 1850 50  0000 C CNN
	1    2950 1850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2800 1800 2950 1800
Wire Wire Line
	2950 1800 2950 1850
Wire Wire Line
	1800 2400 1800 2500
Wire Wire Line
	2500 2200 2500 2050
NoConn ~ 2800 1900
Text Notes 2350 2350 2    60   ~ 0
Injection
$Comp
L C_Small C7
U 1 1 57C9DC48
P 2200 2200
F 0 "C7" V 2000 2100 50  0000 L CNN
F 1 "100pF" V 2100 2100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2200 2200 50  0001 C CNN
F 3 "" H 2200 2200 50  0000 C CNN
	1    2200 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 2200 2500 2200
Wire Wire Line
	2100 2200 1950 2200
$EndSCHEMATC
