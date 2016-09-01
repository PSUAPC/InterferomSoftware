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
Sheet 5 5
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
L MC_TCBT-2R5G_BiasT U26
U 1 1 57C9E17C
P 3600 1400
F 0 "U26" H 3600 1550 60  0000 C CNN
F 1 "MC_TCBT-2R5G_BiasT" H 3750 1450 60  0000 C CNN
F 2 "Minicircuits:MC_GU1604" H 3600 1450 60  0001 C CNN
F 3 "" H 3600 1450 60  0001 C CNN
	1    3600 1400
	1    0    0    -1  
$EndComp
$Comp
L PSA4-5043_Amp U25
U 1 1 57C9E1AB
P 2450 1350
F 0 "U25" H 2450 1500 60  0000 C CNN
F 1 "PSA4-5043_Amp" H 2550 1400 60  0000 C CNN
F 2 "Minicircuits:MC_MMM1362" H 2450 1350 60  0001 C CNN
F 3 "" H 2450 1350 60  0001 C CNN
	1    2450 1350
	1    0    0    -1  
$EndComp
NoConn ~ 3950 1600
$Comp
L GND #PWR051
U 1 1 57C9E304
P 2400 1750
F 0 "#PWR051" H 2400 1500 50  0001 C CNN
F 1 "GND" H 2400 1600 50  0000 C CNN
F 2 "" H 2400 1750 50  0000 C CNN
F 3 "" H 2400 1750 50  0000 C CNN
	1    2400 1750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C8
U 1 1 57C9E32D
P 1950 1500
F 0 "C8" H 1960 1570 50  0000 L CNN
F 1 "100pF" H 1960 1420 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1950 1500 50  0001 C CNN
F 3 "" H 1950 1500 50  0000 C CNN
	1    1950 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 1500 3250 1500
Wire Wire Line
	2400 1750 2400 1700
Wire Wire Line
	2200 1500 2050 1500
$Comp
L +5V #PWR052
U 1 1 57C9E428
P 3200 1250
F 0 "#PWR052" H 3200 1100 50  0001 C CNN
F 1 "+5V" H 3200 1390 50  0000 C CNN
F 2 "" H 3200 1250 50  0000 C CNN
F 3 "" H 3200 1250 50  0000 C CNN
	1    3200 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1250 3200 1650
Wire Wire Line
	3200 1600 3250 1600
$Comp
L C_Small C9
U 1 1 57C9EABB
P 3200 1750
F 0 "C9" H 3210 1820 50  0000 L CNN
F 1 "0.1uF" H 3210 1670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3200 1750 50  0001 C CNN
F 3 "" H 3200 1750 50  0000 C CNN
	1    3200 1750
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR053
U 1 1 57C9EB7B
P 3200 1900
F 0 "#PWR053" H 3200 1650 50  0001 C CNN
F 1 "GND" H 3200 1750 50  0000 C CNN
F 2 "" H 3200 1900 50  0000 C CNN
F 3 "" H 3200 1900 50  0000 C CNN
	1    3200 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1850 3200 1900
Connection ~ 3200 1600
Text GLabel 1700 1500 0    60   Input ~ 0
AMP2_In
Wire Wire Line
	1700 1500 1850 1500
$EndSCHEMATC
