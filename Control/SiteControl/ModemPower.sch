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
Sheet 6 9
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
L GND #PWR62
U 1 1 57AC3452
P 2300 1850
F 0 "#PWR62" H 2300 1600 50  0001 C CNN
F 1 "GND" H 2300 1700 50  0000 C CNN
F 2 "" H 2300 1850 50  0000 C CNN
F 3 "" H 2300 1850 50  0000 C CNN
	1    2300 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1650 3500 1650
$Comp
L SS_Relay_VO14642AT U7
U 1 1 57AC3468
P 3800 1650
F 0 "U7" H 3600 1850 50  0000 L CNN
F 1 "SS_Relay_VO14642AT" H 3400 1450 50  0000 L CNN
F 2 "DigitalLogic:SS_Relay_VO14642AT" H 3600 1450 50  0001 L CIN
F 3 "" H 3750 1650 50  0000 L CNN
	1    3800 1650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3450 1750 3500 1750
Wire Wire Line
	3450 1450 3450 1750
Wire Wire Line
	3450 1550 3500 1550
$Comp
L R R21
U 1 1 57AC3473
P 4350 1900
F 0 "R21" V 4430 1900 50  0000 C CNN
F 1 "450R" V 4350 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4280 1900 50  0001 C CNN
F 3 "" H 4350 1900 50  0000 C CNN
	1    4350 1900
	-1   0    0    1   
$EndComp
$Comp
L R R22
U 1 1 57AC347B
P 4550 1900
F 0 "R22" V 4630 1900 50  0000 C CNN
F 1 "10K" V 4550 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4480 1900 50  0001 C CNN
F 3 "" H 4550 1900 50  0000 C CNN
	1    4550 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4100 1550 4650 1550
Wire Wire Line
	4550 1750 4550 1550
Connection ~ 4550 1550
Wire Wire Line
	4100 1750 4350 1750
$Comp
L GND #PWR65
U 1 1 57AC3486
P 4450 2050
F 0 "#PWR65" H 4450 1800 50  0001 C CNN
F 1 "GND" H 4450 1900 50  0000 C CNN
F 2 "" H 4450 2050 50  0000 C CNN
F 3 "" H 4450 2050 50  0000 C CNN
	1    4450 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2050 4550 2050
Connection ~ 4450 2050
Connection ~ 3450 1550
Wire Notes Line
	1700 1150 5250 1150
Wire Notes Line
	5250 1150 5250 2550
Wire Notes Line
	5250 2550 1450 2550
Wire Notes Line
	1450 2550 1450 1150
Wire Notes Line
	1450 1150 1750 1150
Text Notes 1850 1250 0    60   ~ 0
Solid-State Switch and Connector for Modem
$Comp
L CONN_01X02 J6
U 1 1 57AC36DE
P 2000 1700
F 0 "J6" H 2000 1850 50  0000 C CNN
F 1 "CONN_01X02" V 2100 1700 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_2pol" H 2000 1700 50  0001 C CNN
F 3 "" H 2000 1700 50  0000 C CNN
	1    2000 1700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2200 1750 2300 1750
Wire Wire Line
	2300 1750 2300 1850
Text GLabel 4650 1550 2    60   Input ~ 0
Modem_En
$Comp
L +BATT #PWR64
U 1 1 57AC3F1A
P 3450 1450
F 0 "#PWR64" H 3450 1300 50  0001 C CNN
F 1 "+BATT" H 3450 1590 50  0000 C CNN
F 2 "" H 3450 1450 50  0000 C CNN
F 3 "" H 3450 1450 50  0000 C CNN
	1    3450 1450
	1    0    0    -1  
$EndComp
$Comp
L CP1 C14
U 1 1 57AC722B
P 2550 1850
F 0 "C14" H 2575 1950 50  0000 L CNN
F 1 "0.47uF" H 2575 1750 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeR_EIA-2012" H 2550 1850 50  0001 C CNN
F 3 "" H 2550 1850 50  0000 C CNN
	1    2550 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1700 2550 1650
Connection ~ 2550 1650
$Comp
L GND #PWR63
U 1 1 57AC73BF
P 2550 2050
F 0 "#PWR63" H 2550 1800 50  0001 C CNN
F 1 "GND" H 2550 1900 50  0000 C CNN
F 2 "" H 2550 2050 50  0000 C CNN
F 3 "" H 2550 2050 50  0000 C CNN
	1    2550 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 2000 2550 2050
$Comp
L CP1 C15
U 1 1 57AC76BF
P 6300 1900
F 0 "C15" H 6325 2000 50  0000 L CNN
F 1 "22uF" H 6325 1800 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeR_EIA-2012" H 6300 1900 50  0001 C CNN
F 3 "" H 6300 1900 50  0000 C CNN
	1    6300 1900
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR66
U 1 1 57AC788C
P 6300 1700
F 0 "#PWR66" H 6300 1550 50  0001 C CNN
F 1 "+BATT" H 6300 1840 50  0000 C CNN
F 2 "" H 6300 1700 50  0000 C CNN
F 3 "" H 6300 1700 50  0000 C CNN
	1    6300 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR67
U 1 1 57AC78AC
P 6300 2100
F 0 "#PWR67" H 6300 1850 50  0001 C CNN
F 1 "GND" H 6300 1950 50  0000 C CNN
F 2 "" H 6300 2100 50  0000 C CNN
F 3 "" H 6300 2100 50  0000 C CNN
	1    6300 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1700 6300 1750
Wire Wire Line
	6300 2050 6300 2100
Wire Notes Line
	5900 2450 6700 2450
Wire Notes Line
	6700 2450 6700 1100
Wire Notes Line
	6700 1100 5900 1100
Wire Notes Line
	5900 1100 5900 2450
Text Notes 5900 1200 0    60   ~ 0
Relay Decoupling
Text Notes 1450 3200 0    60   ~ 0
NOTES: The modem can be powered by anything between 9 VDC and 16 VDC\nindicating an internal power supply / regulator. This means that we can simply \npipe battery power directly to the modem (after a switch / relay allowing for \nhard reset / power consumption)
Text Notes 7200 6800 0    60   ~ 0
Applied Physics Club\nThe Pennsylvania State University
Text Notes 9125 7650 2    60   ~ 0
September 27, 2016
Text Notes 9100 7500 2    60   ~ 0
Telescope Base Station Control Board
Text Notes 10625 7650 0    60   ~ 0
B
$EndSCHEMATC
