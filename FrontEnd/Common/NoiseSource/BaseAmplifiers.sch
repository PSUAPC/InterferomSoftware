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
LIBS:NoiseSource-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L PMA-545G1_Amp U1
U 1 1 57C62AAC
P 2000 1600
F 0 "U1" H 1900 1600 60  0000 C CNN
F 1 "PMA-545G1_Amp" H 1600 1700 60  0000 C CNN
F 2 "Minicircuits:MC_DQ849" H 2100 1600 60  0001 C CNN
F 3 "" H 2100 1600 60  0001 C CNN
	1    2000 1600
	1    0    0    -1  
$EndComp
$Comp
L L_Small L1
U 1 1 57C62AAD
P 2150 2150
F 0 "L1" H 2180 2190 50  0000 L CNN
F 1 "36nH" V 2100 2000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2150 2150 50  0001 C CNN
F 3 "" H 2150 2150 50  0000 C CNN
	1    2150 2150
	-1   0    0    1   
$EndComp
$Comp
L C_Small C2
U 1 1 57C62AAE
P 2150 1350
F 0 "C2" H 2160 1420 50  0000 L CNN
F 1 "100pF" H 2050 1500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2150 1350 50  0001 C CNN
F 3 "" H 2150 1350 50  0000 C CNN
	1    2150 1350
	1    0    0    -1  
$EndComp
$Comp
L R_Small R1
U 1 1 57C62AAF
P 2500 2150
F 0 "R1" H 2530 2170 50  0000 L CNN
F 1 "0R" V 2500 2100 50  0000 L CNN
F 2 "Resistors_SMD:R_2512" H 2500 2150 50  0001 C CNN
F 3 "" H 2500 2150 50  0000 C CNN
	1    2500 2150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 57C62AB0
P 2350 1350
F 0 "C4" H 2360 1420 50  0000 L CNN
F 1 "1uF" H 2350 1500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2350 1350 50  0001 C CNN
F 3 "" H 2350 1350 50  0000 C CNN
	1    2350 1350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 57C62AB1
P 2650 1850
F 0 "C6" H 2660 1920 50  0000 L CNN
F 1 "100pF" H 2400 1800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2650 1850 50  0001 C CNN
F 3 "" H 2650 1850 50  0000 C CNN
	1    2650 1850
	0    1    1    0   
$EndComp
$Comp
L C_Small C1
U 1 1 57C62AB2
P 1650 1800
F 0 "C1" H 1660 1870 50  0000 L CNN
F 1 "100pF" H 1660 1720 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1650 1800 50  0001 C CNN
F 3 "" H 1650 1800 50  0000 C CNN
	1    1650 1800
	0    1    1    0   
$EndComp
$Comp
L L_Small L2
U 1 1 57C62AB3
P 2350 2150
F 0 "L2" H 2380 2190 50  0000 L CNN
F 1 "47nH" V 2300 2000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2350 2150 50  0001 C CNN
F 3 "" H 2350 2150 50  0000 C CNN
	1    2350 2150
	-1   0    0    1   
$EndComp
$Comp
L C_Small C3
U 1 1 57C62AB4
P 2150 2350
F 0 "C3" H 2160 2420 50  0000 L CNN
F 1 "100pF" H 1900 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2150 2350 50  0001 C CNN
F 3 "" H 2150 2350 50  0000 C CNN
	1    2150 2350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 57C62AB5
P 2350 2350
F 0 "C5" H 2360 2420 50  0000 L CNN
F 1 "1uF" H 2360 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2350 2350 50  0001 C CNN
F 3 "" H 2350 2350 50  0000 C CNN
	1    2350 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 57C62AB6
P 2250 2450
F 0 "#PWR01" H 2250 2200 50  0001 C CNN
F 1 "GND" H 2250 2300 50  0000 C CNN
F 2 "" H 2250 2450 50  0000 C CNN
F 3 "" H 2250 2450 50  0000 C CNN
	1    2250 2450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 57C62AB7
P 2750 2200
F 0 "#PWR02" H 2750 2050 50  0001 C CNN
F 1 "+5V" H 2750 2340 50  0000 C CNN
F 2 "" H 2750 2200 50  0000 C CNN
F 3 "" H 2750 2200 50  0000 C CNN
	1    2750 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 57C62AB8
P 2250 1450
F 0 "#PWR03" H 2250 1200 50  0001 C CNN
F 1 "GND" H 2250 1300 50  0000 C CNN
F 2 "" H 2250 1450 50  0000 C CNN
F 3 "" H 2250 1450 50  0000 C CNN
	1    2250 1450
	1    0    0    -1  
$EndComp
NoConn ~ 1800 1900
$Comp
L GND #PWR04
U 1 1 57C62AB9
P 2000 2100
F 0 "#PWR04" H 2000 1850 50  0001 C CNN
F 1 "GND" H 2000 1950 50  0000 C CNN
F 2 "" H 2000 2100 50  0000 C CNN
F 3 "" H 2000 2100 50  0000 C CNN
	1    2000 2100
	1    0    0    -1  
$EndComp
$Comp
L PMA-545G1_Amp U2
U 1 1 57C61FB4
P 3500 1650
F 0 "U2" H 3400 1650 60  0000 C CNN
F 1 "PMA-545G1_Amp" H 3100 1750 60  0000 C CNN
F 2 "Minicircuits:MC_DQ849" H 3600 1650 60  0001 C CNN
F 3 "" H 3600 1650 60  0001 C CNN
	1    3500 1650
	1    0    0    -1  
$EndComp
$Comp
L L_Small L3
U 1 1 57C61FBA
P 3650 2200
F 0 "L3" H 3680 2240 50  0000 L CNN
F 1 "36nH" V 3600 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3650 2200 50  0001 C CNN
F 3 "" H 3650 2200 50  0000 C CNN
	1    3650 2200
	-1   0    0    1   
$EndComp
$Comp
L C_Small C8
U 1 1 57C61FC0
P 3650 1400
F 0 "C8" H 3660 1470 50  0000 L CNN
F 1 "100pF" H 3550 1550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3650 1400 50  0001 C CNN
F 3 "" H 3650 1400 50  0000 C CNN
	1    3650 1400
	1    0    0    -1  
$EndComp
$Comp
L R_Small R2
U 1 1 57C61FC6
P 4000 2200
F 0 "R2" H 4030 2220 50  0000 L CNN
F 1 "0R" V 4000 2150 50  0000 L CNN
F 2 "Resistors_SMD:R_2512" H 4000 2200 50  0001 C CNN
F 3 "" H 4000 2200 50  0000 C CNN
	1    4000 2200
	1    0    0    -1  
$EndComp
$Comp
L C_Small C10
U 1 1 57C61FCC
P 3850 1400
F 0 "C10" H 3860 1470 50  0000 L CNN
F 1 "1uF" H 3850 1550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3850 1400 50  0001 C CNN
F 3 "" H 3850 1400 50  0000 C CNN
	1    3850 1400
	1    0    0    -1  
$EndComp
$Comp
L C_Small C12
U 1 1 57C61FD2
P 4150 1900
F 0 "C12" H 4160 1970 50  0000 L CNN
F 1 "100pF" H 3900 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4150 1900 50  0001 C CNN
F 3 "" H 4150 1900 50  0000 C CNN
	1    4150 1900
	0    1    1    0   
$EndComp
$Comp
L L_Small L4
U 1 1 57C61FDE
P 3850 2200
F 0 "L4" H 3880 2240 50  0000 L CNN
F 1 "47nH" V 3800 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3850 2200 50  0001 C CNN
F 3 "" H 3850 2200 50  0000 C CNN
	1    3850 2200
	-1   0    0    1   
$EndComp
$Comp
L C_Small C9
U 1 1 57C61FE4
P 3650 2400
F 0 "C9" H 3660 2470 50  0000 L CNN
F 1 "100pF" H 3400 2300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3650 2400 50  0001 C CNN
F 3 "" H 3650 2400 50  0000 C CNN
	1    3650 2400
	1    0    0    -1  
$EndComp
$Comp
L C_Small C11
U 1 1 57C61FEA
P 3850 2400
F 0 "C11" H 3860 2470 50  0000 L CNN
F 1 "1uF" H 3860 2320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3850 2400 50  0001 C CNN
F 3 "" H 3850 2400 50  0000 C CNN
	1    3850 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 57C61FF0
P 3750 2500
F 0 "#PWR05" H 3750 2250 50  0001 C CNN
F 1 "GND" H 3750 2350 50  0000 C CNN
F 2 "" H 3750 2500 50  0000 C CNN
F 3 "" H 3750 2500 50  0000 C CNN
	1    3750 2500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 57C61FF6
P 4200 2250
F 0 "#PWR06" H 4200 2100 50  0001 C CNN
F 1 "+5V" H 4200 2390 50  0000 C CNN
F 2 "" H 4200 2250 50  0000 C CNN
F 3 "" H 4200 2250 50  0000 C CNN
	1    4200 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 57C61FFC
P 3750 1500
F 0 "#PWR07" H 3750 1250 50  0001 C CNN
F 1 "GND" H 3750 1350 50  0000 C CNN
F 2 "" H 3750 1500 50  0000 C CNN
F 3 "" H 3750 1500 50  0000 C CNN
	1    3750 1500
	1    0    0    -1  
$EndComp
NoConn ~ 3300 1950
$Comp
L GND #PWR08
U 1 1 57C62018
P 3500 2150
F 0 "#PWR08" H 3500 1900 50  0001 C CNN
F 1 "GND" H 3500 2000 50  0000 C CNN
F 2 "" H 3500 2150 50  0000 C CNN
F 3 "" H 3500 2150 50  0000 C CNN
	1    3500 2150
	1    0    0    -1  
$EndComp
$Comp
L PMA-545G1_Amp U3
U 1 1 57C639B4
P 6400 1850
F 0 "U3" H 6300 1850 60  0000 C CNN
F 1 "PMA-545G1_Amp" H 6000 1950 60  0000 C CNN
F 2 "Minicircuits:MC_DQ849" H 6500 1850 60  0001 C CNN
F 3 "" H 6500 1850 60  0001 C CNN
	1    6400 1850
	1    0    0    -1  
$EndComp
$Comp
L L_Small L5
U 1 1 57C639BA
P 6550 2400
F 0 "L5" H 6580 2440 50  0000 L CNN
F 1 "36nH" V 6500 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6550 2400 50  0001 C CNN
F 3 "" H 6550 2400 50  0000 C CNN
	1    6550 2400
	-1   0    0    1   
$EndComp
$Comp
L C_Small C14
U 1 1 57C639C0
P 6550 1600
F 0 "C14" H 6560 1670 50  0000 L CNN
F 1 "100pF" H 6450 1750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6550 1600 50  0001 C CNN
F 3 "" H 6550 1600 50  0000 C CNN
	1    6550 1600
	1    0    0    -1  
$EndComp
$Comp
L R_Small R3
U 1 1 57C639C6
P 6900 2400
F 0 "R3" H 6930 2420 50  0000 L CNN
F 1 "0R" V 6900 2350 50  0000 L CNN
F 2 "Resistors_SMD:R_2512" H 6900 2400 50  0001 C CNN
F 3 "" H 6900 2400 50  0000 C CNN
	1    6900 2400
	1    0    0    -1  
$EndComp
$Comp
L C_Small C16
U 1 1 57C639CC
P 6750 1600
F 0 "C16" H 6760 1670 50  0000 L CNN
F 1 "1uF" H 6750 1750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6750 1600 50  0001 C CNN
F 3 "" H 6750 1600 50  0000 C CNN
	1    6750 1600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C18
U 1 1 57C639D2
P 7050 2100
F 0 "C18" H 7060 2170 50  0000 L CNN
F 1 "100pF" H 6800 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7050 2100 50  0001 C CNN
F 3 "" H 7050 2100 50  0000 C CNN
	1    7050 2100
	0    1    1    0   
$EndComp
$Comp
L C_Small C13
U 1 1 57C639D8
P 6050 2050
F 0 "C13" H 6060 2120 50  0000 L CNN
F 1 "100pF" H 6060 1970 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6050 2050 50  0001 C CNN
F 3 "" H 6050 2050 50  0000 C CNN
	1    6050 2050
	0    1    1    0   
$EndComp
$Comp
L L_Small L6
U 1 1 57C639DE
P 6750 2400
F 0 "L6" H 6780 2440 50  0000 L CNN
F 1 "47nH" V 6700 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6750 2400 50  0001 C CNN
F 3 "" H 6750 2400 50  0000 C CNN
	1    6750 2400
	-1   0    0    1   
$EndComp
$Comp
L C_Small C15
U 1 1 57C639E4
P 6550 2600
F 0 "C15" H 6560 2670 50  0000 L CNN
F 1 "100pF" H 6300 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6550 2600 50  0001 C CNN
F 3 "" H 6550 2600 50  0000 C CNN
	1    6550 2600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C17
U 1 1 57C639EA
P 6750 2600
F 0 "C17" H 6760 2670 50  0000 L CNN
F 1 "1uF" H 6760 2520 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6750 2600 50  0001 C CNN
F 3 "" H 6750 2600 50  0000 C CNN
	1    6750 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 57C639F0
P 6650 2700
F 0 "#PWR09" H 6650 2450 50  0001 C CNN
F 1 "GND" H 6650 2550 50  0000 C CNN
F 2 "" H 6650 2700 50  0000 C CNN
F 3 "" H 6650 2700 50  0000 C CNN
	1    6650 2700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 57C639F6
P 7150 2450
F 0 "#PWR010" H 7150 2300 50  0001 C CNN
F 1 "+5V" H 7150 2590 50  0000 C CNN
F 2 "" H 7150 2450 50  0000 C CNN
F 3 "" H 7150 2450 50  0000 C CNN
	1    7150 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 57C639FC
P 6650 1700
F 0 "#PWR011" H 6650 1450 50  0001 C CNN
F 1 "GND" H 6650 1550 50  0000 C CNN
F 2 "" H 6650 1700 50  0000 C CNN
F 3 "" H 6650 1700 50  0000 C CNN
	1    6650 1700
	1    0    0    -1  
$EndComp
NoConn ~ 6200 2150
$Comp
L GND #PWR012
U 1 1 57C63A18
P 6400 2350
F 0 "#PWR012" H 6400 2100 50  0001 C CNN
F 1 "GND" H 6400 2200 50  0000 C CNN
F 2 "" H 6400 2350 50  0000 C CNN
F 3 "" H 6400 2350 50  0000 C CNN
	1    6400 2350
	1    0    0    -1  
$EndComp
$Comp
L R_Small R4
U 1 1 57C65BD2
P 1250 1950
F 0 "R4" H 1280 1970 50  0000 L CNN
F 1 "50R" H 1280 1910 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" H 1250 1950 50  0001 C CNN
F 3 "" H 1250 1950 50  0000 C CNN
	1    1250 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 57C66054
P 1250 2100
F 0 "#PWR013" H 1250 1850 50  0001 C CNN
F 1 "GND" H 1250 1950 50  0000 C CNN
F 2 "" H 1250 2100 50  0000 C CNN
F 3 "" H 1250 2100 50  0000 C CNN
	1    1250 2100
	1    0    0    -1  
$EndComp
$Comp
L HSWA2-30DR_switch U4
U 1 1 57C68571
P 5100 1800
F 0 "U4" H 5050 1950 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 5100 1850 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 4850 1850 60  0001 C CNN
F 3 "" H 4850 1850 60  0001 C CNN
	1    5100 1800
	-1   0    0    -1  
$EndComp
$Comp
L HSWA2-30DR_switch U5
U 1 1 57C68D0F
P 7950 2200
F 0 "U5" H 7900 2350 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 7950 2250 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 7700 2250 60  0001 C CNN
F 3 "" H 7700 2250 60  0001 C CNN
	1    7950 2200
	1    0    0    1   
$EndComp
$Comp
L C_Small C7
U 1 1 57C6C76D
P 10250 2100
F 0 "C7" H 10260 2170 50  0000 L CNN
F 1 "100pF" H 10000 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 10250 2100 50  0001 C CNN
F 3 "" H 10250 2100 50  0000 C CNN
	1    10250 2100
	0    1    1    0   
$EndComp
$Comp
L BNC P1
U 1 1 57C6C7F1
P 10750 2100
F 0 "P1" H 10760 2220 50  0000 C CNN
F 1 "BNC" V 10860 2040 50  0000 C CNN
F 2 "DigitalLogic:UMCC_PCB" H 10750 2100 50  0001 C CNN
F 3 "" H 10750 2100 50  0000 C CNN
	1    10750 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 57C6D915
P 10750 2400
F 0 "#PWR014" H 10750 2150 50  0001 C CNN
F 1 "GND" H 10750 2250 50  0000 C CNN
F 2 "" H 10750 2400 50  0000 C CNN
F 3 "" H 10750 2400 50  0000 C CNN
	1    10750 2400
	1    0    0    -1  
$EndComp
$Comp
L HSWA2-30DR_switch U6
U 1 1 57C6F424
P 9250 2000
F 0 "U6" H 9200 2150 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 9250 2050 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 9000 2050 60  0001 C CNN
F 3 "" H 9000 2050 60  0001 C CNN
	1    9250 2000
	-1   0    0    -1  
$EndComp
$Comp
L R_Small R5
U 1 1 57C70E3C
P 10250 2350
F 0 "R5" H 10280 2370 50  0000 L CNN
F 1 "50R" H 10280 2310 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" H 10250 2350 50  0001 C CNN
F 3 "" H 10250 2350 50  0000 C CNN
	1    10250 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 57C7141A
P 10250 2500
F 0 "#PWR015" H 10250 2250 50  0001 C CNN
F 1 "GND" H 10250 2350 50  0000 C CNN
F 2 "" H 10250 2500 50  0000 C CNN
F 3 "" H 10250 2500 50  0000 C CNN
	1    10250 2500
	1    0    0    -1  
$EndComp
Text Notes 2550 3150 0    60   ~ 0
Primary Noise Source
Text Notes 6400 3250 0    60   ~ 0
Solar Amplifier
Text Notes 6250 900  0    60   ~ 0
Bypass Trace
Text Notes 9300 3200 0    60   ~ 0
Shunt Switch
Text GLabel 7400 1800 0    60   Input ~ 0
TVDD
Text GLabel 5650 2200 2    60   Input ~ 0
TVDD
Text GLabel 4600 2400 0    60   Input ~ 0
TCTRL1
Text GLabel 4600 2300 0    60   Input ~ 0
TCTRL2
Text GLabel 8450 1700 2    60   Input ~ 0
TCTRL1
Text GLabel 8450 1600 2    60   Input ~ 0
TCTRL2
Text GLabel 9400 3800 0    60   Input ~ 0
TVDD
Text GLabel 9400 3900 0    60   Input ~ 0
TCTRL1
Text GLabel 9400 4000 0    60   Input ~ 0
TCTRL2
$Comp
L R_Small R9
U 1 1 57C7A13E
P 9550 3800
F 0 "R9" V 9600 3600 50  0000 L CNN
F 1 "0R" V 9550 3750 50  0000 L CNN
F 2 "Resistors_SMD:R_2010" H 9550 3800 50  0001 C CNN
F 3 "" H 9550 3800 50  0000 C CNN
	1    9550 3800
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R10
U 1 1 57C7A629
P 9550 3900
F 0 "R10" V 9600 3700 50  0000 L CNN
F 1 "0R" V 9550 3850 50  0000 L CNN
F 2 "Resistors_SMD:R_2010" H 9550 3900 50  0001 C CNN
F 3 "" H 9550 3900 50  0000 C CNN
	1    9550 3900
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R11
U 1 1 57C7A6AF
P 9550 4000
F 0 "R11" V 9600 3800 50  0000 L CNN
F 1 "0R" V 9550 3950 50  0000 L CNN
F 2 "Resistors_SMD:R_2010" H 9550 4000 50  0001 C CNN
F 3 "" H 9550 4000 50  0000 C CNN
	1    9550 4000
	0    -1   -1   0   
$EndComp
Text GLabel 9900 3900 2    60   Input ~ 0
CTRL1
Text GLabel 9900 4000 2    60   Input ~ 0
CTRL2
$Comp
L +3.3V #PWR016
U 1 1 57C7BCEA
P 9900 3800
F 0 "#PWR016" H 9900 3650 50  0001 C CNN
F 1 "+3.3V" H 9900 3940 50  0000 C CNN
F 2 "" H 9900 3800 50  0000 C CNN
F 3 "" H 9900 3800 50  0000 C CNN
	1    9900 3800
	1    0    0    -1  
$EndComp
Text Notes 4300 2600 0    60   ~ 0
*Switched due to trace switch
$Comp
L GND #PWR017
U 1 1 57C7E048
P 5800 2500
F 0 "#PWR017" H 5800 2250 50  0001 C CNN
F 1 "GND" H 5800 2350 50  0000 C CNN
F 2 "" H 5800 2500 50  0000 C CNN
F 3 "" H 5800 2500 50  0000 C CNN
	1    5800 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 57C7E200
P 4600 2050
F 0 "#PWR018" H 4600 1800 50  0001 C CNN
F 1 "GND" H 4600 1900 50  0000 C CNN
F 2 "" H 4600 2050 50  0000 C CNN
F 3 "" H 4600 2050 50  0000 C CNN
	1    4600 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 57C7E3B8
P 8500 2250
F 0 "#PWR019" H 8500 2000 50  0001 C CNN
F 1 "GND" H 8500 2100 50  0000 C CNN
F 2 "" H 8500 2250 50  0000 C CNN
F 3 "" H 8500 2250 50  0000 C CNN
	1    8500 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 57C7E4D4
P 7250 1450
F 0 "#PWR020" H 7250 1200 50  0001 C CNN
F 1 "GND" H 7250 1300 50  0000 C CNN
F 2 "" H 7250 1450 50  0000 C CNN
F 3 "" H 7250 1450 50  0000 C CNN
	1    7250 1450
	1    0    0    -1  
$EndComp
Text GLabel 9350 4250 0    60   Input ~ 0
TVDD
Text GLabel 9350 4350 0    60   Input ~ 0
TCTRL1
Text GLabel 9350 4450 0    60   Input ~ 0
TCTRL2
$Comp
L R_Small R6
U 1 1 57C7FA60
P 9500 4250
F 0 "R6" V 9550 4050 50  0000 L CNN
F 1 "0R" V 9500 4200 50  0000 L CNN
F 2 "Resistors_SMD:R_2010" H 9500 4250 50  0001 C CNN
F 3 "" H 9500 4250 50  0000 C CNN
	1    9500 4250
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R7
U 1 1 57C7FA66
P 9500 4350
F 0 "R7" V 9550 4150 50  0000 L CNN
F 1 "0R" V 9500 4300 50  0000 L CNN
F 2 "Resistors_SMD:R_2010" H 9500 4350 50  0001 C CNN
F 3 "" H 9500 4350 50  0000 C CNN
	1    9500 4350
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R8
U 1 1 57C7FA6C
P 9500 4450
F 0 "R8" V 9550 4250 50  0000 L CNN
F 1 "0R" V 9500 4400 50  0000 L CNN
F 2 "Resistors_SMD:R_2010" H 9500 4450 50  0001 C CNN
F 3 "" H 9500 4450 50  0000 C CNN
	1    9500 4450
	0    -1   -1   0   
$EndComp
Text GLabel 9850 4350 2    60   Input ~ 0
CTRL1
Text GLabel 9850 4450 2    60   Input ~ 0
CTRL2
$Comp
L +3.3V #PWR021
U 1 1 57C7FA74
P 9850 4250
F 0 "#PWR021" H 9850 4100 50  0001 C CNN
F 1 "+3.3V" H 9850 4390 50  0000 C CNN
F 2 "" H 9850 4250 50  0000 C CNN
F 3 "" H 9850 4250 50  0000 C CNN
	1    9850 4250
	1    0    0    -1  
$EndComp
Text Notes 9150 3600 0    60   ~ 0
RF Trace Jumpers
$Comp
L GND #PWR022
U 1 1 57C84E58
P 8700 2250
F 0 "#PWR022" H 8700 2000 50  0001 C CNN
F 1 "GND" H 8700 2100 50  0000 C CNN
F 2 "" H 8700 2250 50  0000 C CNN
F 3 "" H 8700 2250 50  0000 C CNN
	1    8700 2250
	1    0    0    -1  
$EndComp
Text GLabel 8750 2500 0    60   Input ~ 0
ShuntCTRL1
Text GLabel 8750 2600 0    60   Input ~ 0
ShuntCTRL2
Text GLabel 4350 4450 2    60   Input ~ 0
ShuntCTRL1
Text GLabel 4350 5700 2    60   Input ~ 0
ShuntCTRL2
Text GLabel 2700 4400 2    60   Input ~ 0
CTRL1
Text GLabel 2700 5650 2    60   Input ~ 0
CTRL2
Text GLabel 1400 5050 0    60   Input ~ 0
SolarSel
Text GLabel 3100 4950 0    60   Input ~ 0
ShuntSel
Wire Wire Line
	2150 1450 2350 1450
Connection ~ 2250 1450
Wire Wire Line
	2050 1250 2500 1250
Wire Wire Line
	2050 1250 2050 1650
Connection ~ 2150 1250
Wire Wire Line
	2500 1250 2500 2050
Connection ~ 2350 1250
Wire Wire Line
	2300 1850 2550 1850
Wire Wire Line
	2150 2250 2750 2250
Connection ~ 2350 2250
Wire Wire Line
	2150 2050 2150 2050
Wire Wire Line
	2350 2050 2350 1850
Connection ~ 2350 1850
Wire Wire Line
	2350 2250 2350 2250
Wire Wire Line
	2150 2450 2350 2450
Wire Wire Line
	2250 2450 2250 2450
Connection ~ 2250 2450
Connection ~ 2150 2250
Wire Wire Line
	2750 2250 2750 2200
Connection ~ 2500 2250
Wire Wire Line
	1750 1800 1800 1800
Wire Wire Line
	2000 2050 2000 2100
Wire Wire Line
	3650 1500 3850 1500
Connection ~ 3750 1500
Wire Wire Line
	3550 1300 4000 1300
Wire Wire Line
	3550 1300 3550 1700
Connection ~ 3650 1300
Wire Wire Line
	4000 1300 4000 2100
Connection ~ 3850 1300
Wire Wire Line
	3800 1900 4050 1900
Wire Wire Line
	3650 2300 4200 2300
Connection ~ 3850 2300
Wire Wire Line
	3650 2100 3650 2100
Wire Wire Line
	3850 2100 3850 1900
Connection ~ 3850 1900
Wire Wire Line
	3850 2300 3850 2300
Wire Wire Line
	3650 2500 3850 2500
Wire Wire Line
	3750 2500 3750 2500
Connection ~ 3750 2500
Connection ~ 3650 2300
Wire Wire Line
	4200 2300 4200 2250
Connection ~ 4000 2300
Wire Wire Line
	3500 2100 3500 2150
Wire Wire Line
	6550 1700 6750 1700
Connection ~ 6650 1700
Wire Wire Line
	6450 1500 6900 1500
Wire Wire Line
	6450 1500 6450 1900
Connection ~ 6550 1500
Wire Wire Line
	6900 1500 6900 2300
Connection ~ 6750 1500
Wire Wire Line
	6700 2100 6950 2100
Wire Wire Line
	6550 2500 7150 2500
Connection ~ 6750 2500
Wire Wire Line
	6550 2300 6550 2300
Wire Wire Line
	6750 2300 6750 2100
Connection ~ 6750 2100
Wire Wire Line
	6750 2500 6750 2500
Wire Wire Line
	6550 2700 6750 2700
Wire Wire Line
	6650 2700 6650 2700
Connection ~ 6650 2700
Connection ~ 6550 2500
Wire Wire Line
	7150 2500 7150 2450
Connection ~ 6900 2500
Wire Wire Line
	6150 2050 6200 2050
Wire Wire Line
	6400 2300 6400 2350
Wire Wire Line
	1250 2050 1250 2100
Wire Wire Line
	1250 1850 1250 1800
Wire Wire Line
	1250 1800 1550 1800
Wire Wire Line
	2750 1850 3300 1850
Wire Wire Line
	4250 1900 4600 1900
Wire Wire Line
	10350 2100 10600 2100
Wire Wire Line
	10750 2400 10750 2300
Wire Wire Line
	5650 2050 5950 2050
Wire Wire Line
	7150 2100 7400 2100
Wire Wire Line
	8450 2100 8750 2100
Wire Wire Line
	9800 2100 10150 2100
Wire Wire Line
	10250 2500 10250 2450
Wire Wire Line
	10250 2250 9800 2250
Wire Wire Line
	7400 1950 7100 1950
Wire Wire Line
	7100 1950 7100 1250
Wire Wire Line
	7100 1250 5950 1250
Wire Wire Line
	5950 1250 5950 1900
Wire Wire Line
	5950 1900 5650 1900
Wire Notes Line
	5700 1350 5700 950 
Wire Notes Line
	5700 950  7350 950 
Wire Notes Line
	7350 950  7350 1350
Wire Notes Line
	6050 2450 6050 3050
Wire Notes Line
	6050 3050 7350 3050
Wire Notes Line
	7350 3050 7350 2500
Wire Notes Line
	8750 2850 8750 3100
Wire Notes Line
	8750 3100 10450 3100
Wire Notes Line
	10450 3100 10450 2800
Wire Notes Line
	4400 2700 4400 3000
Wire Notes Line
	4400 3000 1700 3000
Wire Notes Line
	1700 3000 1700 2700
Wire Wire Line
	9650 3800 9900 3800
Wire Wire Line
	9650 3900 9900 3900
Wire Wire Line
	9900 4000 9650 4000
Wire Wire Line
	9450 4000 9400 4000
Wire Wire Line
	9400 3900 9450 3900
Wire Wire Line
	9450 3800 9400 3800
Wire Wire Line
	7400 1400 7400 1700
Wire Wire Line
	7400 1400 7250 1400
Wire Wire Line
	7250 1400 7250 1450
Connection ~ 7400 1600
Wire Wire Line
	8450 1950 8500 1950
Wire Wire Line
	8500 1950 8500 2250
Wire Wire Line
	5650 2300 5800 2300
Wire Wire Line
	5800 2300 5800 2500
Wire Wire Line
	5650 2400 5800 2400
Connection ~ 5800 2400
Wire Wire Line
	9600 4250 9850 4250
Wire Wire Line
	9600 4350 9850 4350
Wire Wire Line
	9850 4450 9600 4450
Wire Wire Line
	9400 4450 9350 4450
Wire Wire Line
	9350 4350 9400 4350
Wire Wire Line
	9400 4250 9350 4250
Wire Notes Line
	8800 4650 10400 4650
Wire Notes Line
	10400 4650 10400 3450
Wire Notes Line
	10400 3450 8800 3450
Wire Notes Line
	8800 3450 8800 4650
Connection ~ 4600 2050
Wire Wire Line
	8750 2250 8700 2250
$Comp
L SN74AUP1T86_Schmitt_XOR U7
U 1 1 57C9307A
P 2100 4400
F 0 "U7" H 1750 4650 50  0000 C CNN
F 1 "SN74AUP1T86_Schmitt_XOR" H 2150 4800 50  0000 C CNN
F 2 "DigitalLogic:TI_DCK" H 2100 4400 50  0001 C CNN
F 3 "" H 2100 4400 50  0000 C CNN
	1    2100 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 57C9329C
P 2050 4750
F 0 "#PWR023" H 2050 4500 50  0001 C CNN
F 1 "GND" H 2050 4600 50  0000 C CNN
F 2 "" H 2050 4750 50  0000 C CNN
F 3 "" H 2050 4750 50  0000 C CNN
	1    2050 4750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR024
U 1 1 57C937DC
P 2050 3900
F 0 "#PWR024" H 2050 3750 50  0001 C CNN
F 1 "+3.3V" H 2050 4040 50  0000 C CNN
F 2 "" H 2050 3900 50  0000 C CNN
F 3 "" H 2050 3900 50  0000 C CNN
	1    2050 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 3900 2050 4100
Wire Wire Line
	2050 4750 2050 4700
$Comp
L SN74AUP1T86_Schmitt_XOR U8
U 1 1 57C93EF4
P 2100 5650
F 0 "U8" H 1750 5900 50  0000 C CNN
F 1 "SN74AUP1T86_Schmitt_XOR" H 2150 6050 50  0000 C CNN
F 2 "DigitalLogic:TI_DCK" H 2100 5650 50  0001 C CNN
F 3 "" H 2100 5650 50  0000 C CNN
	1    2100 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 57C93EFA
P 2050 6000
F 0 "#PWR025" H 2050 5750 50  0001 C CNN
F 1 "GND" H 2050 5850 50  0000 C CNN
F 2 "" H 2050 6000 50  0000 C CNN
F 3 "" H 2050 6000 50  0000 C CNN
	1    2050 6000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR026
U 1 1 57C93F00
P 2050 5150
F 0 "#PWR026" H 2050 5000 50  0001 C CNN
F 1 "+3.3V" H 2050 5290 50  0000 C CNN
F 2 "" H 2050 5150 50  0000 C CNN
F 3 "" H 2050 5150 50  0000 C CNN
	1    2050 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5150 2050 5350
Wire Wire Line
	2050 6000 2050 5950
Wire Wire Line
	1500 5750 1500 6000
Wire Wire Line
	1500 6000 2050 6000
Wire Wire Line
	1500 4300 1500 4050
Wire Wire Line
	1500 4050 2050 4050
Connection ~ 2050 4050
Wire Wire Line
	1500 4500 1500 5550
$Comp
L SN74AUP1T86_Schmitt_XOR U9
U 1 1 57C955A8
P 3750 4450
F 0 "U9" H 3400 4700 50  0000 C CNN
F 1 "SN74AUP1T86_Schmitt_XOR" H 3800 4850 50  0000 C CNN
F 2 "DigitalLogic:TI_DCK" H 3750 4450 50  0001 C CNN
F 3 "" H 3750 4450 50  0000 C CNN
	1    3750 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 57C955AE
P 3700 4800
F 0 "#PWR027" H 3700 4550 50  0001 C CNN
F 1 "GND" H 3700 4650 50  0000 C CNN
F 2 "" H 3700 4800 50  0000 C CNN
F 3 "" H 3700 4800 50  0000 C CNN
	1    3700 4800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR028
U 1 1 57C955B4
P 3700 3950
F 0 "#PWR028" H 3700 3800 50  0001 C CNN
F 1 "+3.3V" H 3700 4090 50  0000 C CNN
F 2 "" H 3700 3950 50  0000 C CNN
F 3 "" H 3700 3950 50  0000 C CNN
	1    3700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3950 3700 4150
Wire Wire Line
	3700 4800 3700 4750
$Comp
L SN74AUP1T86_Schmitt_XOR U10
U 1 1 57C955BC
P 3750 5700
F 0 "U10" H 3400 5950 50  0000 C CNN
F 1 "SN74AUP1T86_Schmitt_XOR" H 3800 6100 50  0000 C CNN
F 2 "DigitalLogic:TI_DCK" H 3750 5700 50  0001 C CNN
F 3 "" H 3750 5700 50  0000 C CNN
	1    3750 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 57C955C2
P 3700 6050
F 0 "#PWR029" H 3700 5800 50  0001 C CNN
F 1 "GND" H 3700 5900 50  0000 C CNN
F 2 "" H 3700 6050 50  0000 C CNN
F 3 "" H 3700 6050 50  0000 C CNN
	1    3700 6050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR030
U 1 1 57C955C8
P 3700 5200
F 0 "#PWR030" H 3700 5050 50  0001 C CNN
F 1 "+3.3V" H 3700 5340 50  0000 C CNN
F 2 "" H 3700 5200 50  0000 C CNN
F 3 "" H 3700 5200 50  0000 C CNN
	1    3700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 5200 3700 5400
Wire Wire Line
	3700 6050 3700 6000
Wire Wire Line
	3150 5800 3150 6050
Wire Wire Line
	3150 6050 3700 6050
Wire Wire Line
	3150 4350 3150 4100
Wire Wire Line
	3150 4100 3700 4100
Connection ~ 3700 4100
Wire Wire Line
	3150 4550 3150 5600
Wire Wire Line
	1400 5050 1500 5050
Connection ~ 1500 5050
Wire Wire Line
	3100 4950 3150 4950
Connection ~ 3150 4950
$Comp
L C_Small C?
U 1 1 57C97671
P 6250 4650
F 0 "C?" H 6260 4720 50  0000 L CNN
F 1 "0.1Uf" H 6300 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6250 4650 50  0001 C CNN
F 3 "" H 6250 4650 50  0000 C CNN
	1    6250 4650
	-1   0    0    1   
$EndComp
$Comp
L C_Small C?
U 1 1 57C97EDE
P 6500 4650
F 0 "C?" H 6510 4720 50  0000 L CNN
F 1 "0.1Uf" H 6300 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6500 4650 50  0001 C CNN
F 3 "" H 6500 4650 50  0000 C CNN
	1    6500 4650
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 57C97F84
P 6350 4800
F 0 "#PWR?" H 6350 4550 50  0001 C CNN
F 1 "GND" H 6350 4650 50  0000 C CNN
F 2 "" H 6350 4800 50  0000 C CNN
F 3 "" H 6350 4800 50  0000 C CNN
	1    6350 4800
	1    0    0    -1  
$EndComp
Text GLabel 6000 4550 0    60   Input ~ 0
TVDD
Wire Wire Line
	6000 4550 6500 4550
Wire Wire Line
	6250 4750 6500 4750
Wire Wire Line
	6350 4800 6350 4750
Connection ~ 6350 4750
Connection ~ 6250 4550
$Comp
L C_Small C?
U 1 1 57C9A535
P 7000 4700
F 0 "C?" H 7010 4770 50  0000 L CNN
F 1 "0.1Uf" H 7050 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7000 4700 50  0001 C CNN
F 3 "" H 7000 4700 50  0000 C CNN
	1    7000 4700
	-1   0    0    1   
$EndComp
$Comp
L C_Small C?
U 1 1 57C9A5E2
P 7300 4700
F 0 "C?" H 7310 4770 50  0000 L CNN
F 1 "0.1Uf" H 7350 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7300 4700 50  0001 C CNN
F 3 "" H 7300 4700 50  0000 C CNN
	1    7300 4700
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 57C9B40A
P 7150 4850
F 0 "#PWR?" H 7150 4600 50  0001 C CNN
F 1 "GND" H 7150 4700 50  0000 C CNN
F 2 "" H 7150 4850 50  0000 C CNN
F 3 "" H 7150 4850 50  0000 C CNN
	1    7150 4850
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 57C9B7CB
P 7150 4550
F 0 "#PWR?" H 7150 4400 50  0001 C CNN
F 1 "+3.3V" H 7150 4690 50  0000 C CNN
F 2 "" H 7150 4550 50  0000 C CNN
F 3 "" H 7150 4550 50  0000 C CNN
	1    7150 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4600 7000 4550
Wire Wire Line
	7000 4550 7300 4550
Wire Wire Line
	7300 4550 7300 4600
Connection ~ 7150 4550
Wire Wire Line
	7000 4800 7000 4850
Wire Wire Line
	7000 4850 7300 4850
Wire Wire Line
	7300 4850 7300 4800
Connection ~ 7150 4850
$EndSCHEMATC
