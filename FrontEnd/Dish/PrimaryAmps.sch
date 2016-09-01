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
Sheet 2 5
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
U 1 1 57C97F61
P 2600 1550
F 0 "U1" H 2500 1550 60  0000 C CNN
F 1 "PMA-545G1_Amp" H 2200 1650 60  0000 C CNN
F 2 "Minicircuits:MC_DQ849" H 2700 1550 60  0001 C CNN
F 3 "" H 2700 1550 60  0001 C CNN
	1    2600 1550
	1    0    0    -1  
$EndComp
$Comp
L L_Small L1
U 1 1 57C97F62
P 2750 2100
F 0 "L1" H 2780 2140 50  0000 L CNN
F 1 "36nH" V 2700 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2750 2100 50  0001 C CNN
F 3 "" H 2750 2100 50  0000 C CNN
	1    2750 2100
	-1   0    0    1   
$EndComp
$Comp
L C_Small C2
U 1 1 57C97F63
P 2750 1300
F 0 "C2" H 2760 1370 50  0000 L CNN
F 1 "100pF" H 2650 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2750 1300 50  0001 C CNN
F 3 "" H 2750 1300 50  0000 C CNN
	1    2750 1300
	1    0    0    -1  
$EndComp
$Comp
L R_Small R1
U 1 1 57C97F64
P 3100 2100
F 0 "R1" H 3130 2120 50  0000 L CNN
F 1 "0R" V 3100 2050 50  0000 L CNN
F 2 "Resistors_SMD:R_2512" H 3100 2100 50  0001 C CNN
F 3 "" H 3100 2100 50  0000 C CNN
	1    3100 2100
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 57C97F65
P 2950 1300
F 0 "C4" H 2960 1370 50  0000 L CNN
F 1 "1uF" H 2950 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2950 1300 50  0001 C CNN
F 3 "" H 2950 1300 50  0000 C CNN
	1    2950 1300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 57C97F66
P 3250 1800
F 0 "C6" H 3260 1870 50  0000 L CNN
F 1 "100pF" H 3000 1750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3250 1800 50  0001 C CNN
F 3 "" H 3250 1800 50  0000 C CNN
	1    3250 1800
	0    1    1    0   
$EndComp
$Comp
L C_Small C1
U 1 1 57C97F67
P 2250 1750
F 0 "C1" H 2260 1820 50  0000 L CNN
F 1 "100pF" H 2260 1670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2250 1750 50  0001 C CNN
F 3 "" H 2250 1750 50  0000 C CNN
	1    2250 1750
	0    1    1    0   
$EndComp
$Comp
L L_Small L2
U 1 1 57C97F68
P 2950 2100
F 0 "L2" H 2980 2140 50  0000 L CNN
F 1 "47nH" V 2900 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2950 2100 50  0001 C CNN
F 3 "" H 2950 2100 50  0000 C CNN
	1    2950 2100
	-1   0    0    1   
$EndComp
$Comp
L C_Small C3
U 1 1 57C97F69
P 2750 2300
F 0 "C3" H 2760 2370 50  0000 L CNN
F 1 "100pF" H 2500 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2750 2300 50  0001 C CNN
F 3 "" H 2750 2300 50  0000 C CNN
	1    2750 2300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 57C97F6A
P 2950 2300
F 0 "C5" H 2960 2370 50  0000 L CNN
F 1 "1uF" H 2960 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2950 2300 50  0001 C CNN
F 3 "" H 2950 2300 50  0000 C CNN
	1    2950 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 57C97F6B
P 2850 2400
F 0 "#PWR01" H 2850 2150 50  0001 C CNN
F 1 "GND" H 2850 2250 50  0000 C CNN
F 2 "" H 2850 2400 50  0000 C CNN
F 3 "" H 2850 2400 50  0000 C CNN
	1    2850 2400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 57C97F6C
P 3350 2150
F 0 "#PWR02" H 3350 2000 50  0001 C CNN
F 1 "+5V" H 3350 2290 50  0000 C CNN
F 2 "" H 3350 2150 50  0000 C CNN
F 3 "" H 3350 2150 50  0000 C CNN
	1    3350 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 57C97F6D
P 2850 1400
F 0 "#PWR03" H 2850 1150 50  0001 C CNN
F 1 "GND" H 2850 1250 50  0000 C CNN
F 2 "" H 2850 1400 50  0000 C CNN
F 3 "" H 2850 1400 50  0000 C CNN
	1    2850 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1400 2950 1400
Connection ~ 2850 1400
Wire Wire Line
	2650 1200 3100 1200
Wire Wire Line
	2650 1200 2650 1600
Connection ~ 2750 1200
Wire Wire Line
	3100 1200 3100 2000
Connection ~ 2950 1200
Wire Wire Line
	2900 1800 3150 1800
Wire Wire Line
	2750 2200 3350 2200
Connection ~ 2950 2200
Wire Wire Line
	2750 2000 2750 2000
Wire Wire Line
	2950 2000 2950 1800
Connection ~ 2950 1800
Wire Wire Line
	2950 2200 2950 2200
Wire Wire Line
	2750 2400 2950 2400
Wire Wire Line
	2850 2400 2850 2400
Connection ~ 2850 2400
Connection ~ 2750 2200
NoConn ~ 2400 1850
Wire Wire Line
	3350 2200 3350 2150
Connection ~ 3100 2200
Wire Wire Line
	2350 1750 2400 1750
$Comp
L GND #PWR04
U 1 1 57C97F6E
P 2600 2050
F 0 "#PWR04" H 2600 1800 50  0001 C CNN
F 1 "GND" H 2600 1900 50  0000 C CNN
F 2 "" H 2600 2050 50  0000 C CNN
F 3 "" H 2600 2050 50  0000 C CNN
	1    2600 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2000 2600 2050
$Comp
L HSWA2-30DR_switch U2
U 1 1 57C765DD
P 2400 4450
F 0 "U2" H 2350 4600 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 2400 4500 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 2150 4500 60  0001 C CNN
F 3 "" H 2150 4500 60  0001 C CNN
	1    2400 4450
	-1   0    0    -1  
$EndComp
$Comp
L MC_HQ1157_Bandpass U5
U 1 1 57C76C09
P 5250 3300
F 0 "U5" H 5250 3450 60  0000 C CNN
F 1 "MC_HQ1157_Bandpass" H 5250 3350 60  0000 C CNN
F 2 "Minicircuits:MC_HQ1157" H 5250 3300 60  0001 C CNN
F 3 "" H 5250 3300 60  0001 C CNN
	1    5250 3300
	1    0    0    -1  
$EndComp
$Comp
L HSWA2-30DR_switch U3
U 1 1 57C76D9D
P 4000 3700
F 0 "U3" H 3950 3850 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 4000 3750 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 3750 3750 60  0001 C CNN
F 3 "" H 3750 3750 60  0001 C CNN
	1    4000 3700
	-1   0    0    -1  
$EndComp
$Comp
L HSWA2-30DR_switch U4
U 1 1 57C76E02
P 4000 5200
F 0 "U4" H 3950 5350 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 4000 5250 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 3750 5250 60  0001 C CNN
F 3 "" H 3750 5250 60  0001 C CNN
	1    4000 5200
	-1   0    0    -1  
$EndComp
$Comp
L MC_HQ1157_Bandpass U6
U 1 1 57C76EEE
P 5200 4250
F 0 "U6" H 5200 4400 60  0000 C CNN
F 1 "MC_HQ1157_Bandpass" H 5200 4300 60  0000 C CNN
F 2 "Minicircuits:MC_HQ1157" H 5200 4250 60  0001 C CNN
F 3 "" H 5200 4250 60  0001 C CNN
	1    5200 4250
	1    0    0    -1  
$EndComp
$Comp
L MC_HQ1157_Bandpass U7
U 1 1 57C76FF5
P 5250 5000
F 0 "U7" H 5250 5150 60  0000 C CNN
F 1 "MC_HQ1157_Bandpass" H 5250 5050 60  0000 C CNN
F 2 "Minicircuits:MC_HQ1157" H 5250 5000 60  0001 C CNN
F 3 "" H 5250 5000 60  0001 C CNN
	1    5250 5000
	1    0    0    -1  
$EndComp
$Comp
L MC_HQ1157_Bandpass U8
U 1 1 57C7703F
P 5200 5750
F 0 "U8" H 5300 5900 60  0000 C CNN
F 1 "MC_HQ1157_Bandpass" H 5200 5800 60  0000 C CNN
F 2 "Minicircuits:MC_HQ1157" H 5200 5750 60  0001 C CNN
F 3 "" H 5200 5750 60  0001 C CNN
	1    5200 5750
	1    0    0    -1  
$EndComp
$Comp
L HSWA2-30DR_switch U11
U 1 1 57C77897
P 8300 4700
F 0 "U11" H 8250 4850 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 8300 4750 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 8050 4750 60  0001 C CNN
F 3 "" H 8050 4750 60  0001 C CNN
	1    8300 4700
	1    0    0    1   
$EndComp
$Comp
L HSWA2-30DR_switch U10
U 1 1 57C7789D
P 6550 4050
F 0 "U10" H 6500 4200 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 6550 4100 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 6300 4100 60  0001 C CNN
F 3 "" H 6300 4100 60  0001 C CNN
	1    6550 4050
	1    0    0    1   
$EndComp
Wire Wire Line
	2950 4700 3100 4700
Wire Wire Line
	3100 4700 3100 5300
Wire Wire Line
	3100 5300 3500 5300
Wire Wire Line
	4550 3950 4750 3950
Wire Wire Line
	4750 3950 4750 4350
Wire Wire Line
	4750 4350 4900 4350
Wire Wire Line
	4550 5450 4800 5450
Wire Wire Line
	4800 5450 4800 5850
Wire Wire Line
	4800 5850 4900 5850
Wire Wire Line
	5750 3950 5750 4350
Wire Wire Line
	5750 4350 5500 4350
$Comp
L GND #PWR05
U 1 1 57C7BDD8
P 3400 3950
F 0 "#PWR05" H 3400 3700 50  0001 C CNN
F 1 "GND" H 3400 3800 50  0000 C CNN
F 2 "" H 3400 3950 50  0000 C CNN
F 3 "" H 3400 3950 50  0000 C CNN
	1    3400 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 5300 4800 5300
Wire Wire Line
	4800 5300 4800 5100
Wire Wire Line
	4800 5100 4950 5100
Wire Wire Line
	5750 3800 5750 3400
Wire Wire Line
	5750 3400 5550 3400
Wire Wire Line
	4950 3400 4750 3400
Wire Wire Line
	4750 3400 4750 3800
Wire Wire Line
	4750 3800 4550 3800
$Comp
L GND #PWR06
U 1 1 57C7E2A2
P 3350 5450
F 0 "#PWR06" H 3350 5200 50  0001 C CNN
F 1 "GND" H 3350 5300 50  0000 C CNN
F 2 "" H 3350 5450 50  0000 C CNN
F 3 "" H 3350 5450 50  0000 C CNN
	1    3350 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 57C7E451
P 1750 4700
F 0 "#PWR07" H 1750 4450 50  0001 C CNN
F 1 "GND" H 1750 4550 50  0000 C CNN
F 2 "" H 1750 4700 50  0000 C CNN
F 3 "" H 1750 4700 50  0000 C CNN
	1    1750 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 57C7E4DE
P 7000 5650
F 0 "#PWR08" H 7000 5400 50  0001 C CNN
F 1 "GND" H 7000 5500 50  0000 C CNN
F 2 "" H 7000 5650 50  0000 C CNN
F 3 "" H 7000 5650 50  0000 C CNN
	1    7000 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 57C7E6A1
P 8900 4800
F 0 "#PWR09" H 8900 4550 50  0001 C CNN
F 1 "GND" H 8900 4650 50  0000 C CNN
F 2 "" H 8900 4800 50  0000 C CNN
F 3 "" H 8900 4800 50  0000 C CNN
	1    8900 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 57C7E828
P 7150 4100
F 0 "#PWR010" H 7150 3850 50  0001 C CNN
F 1 "GND" H 7150 3950 50  0000 C CNN
F 2 "" H 7150 4100 50  0000 C CNN
F 3 "" H 7150 4100 50  0000 C CNN
	1    7150 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 57C7E99B
P 5050 4700
F 0 "#PWR011" H 5050 4450 50  0001 C CNN
F 1 "GND" H 5050 4550 50  0000 C CNN
F 2 "" H 5050 4700 50  0000 C CNN
F 3 "" H 5050 4700 50  0000 C CNN
	1    5050 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 57C7EB86
P 5100 3750
F 0 "#PWR012" H 5100 3500 50  0001 C CNN
F 1 "GND" H 5100 3600 50  0000 C CNN
F 2 "" H 5100 3750 50  0000 C CNN
F 3 "" H 5100 3750 50  0000 C CNN
	1    5100 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 57C7ECF9
P 5100 5450
F 0 "#PWR013" H 5100 5200 50  0001 C CNN
F 1 "GND" H 5100 5300 50  0000 C CNN
F 2 "" H 5100 5450 50  0000 C CNN
F 3 "" H 5100 5450 50  0000 C CNN
	1    5100 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 57C7EEF8
P 5050 6200
F 0 "#PWR014" H 5050 5950 50  0001 C CNN
F 1 "GND" H 5050 6050 50  0000 C CNN
F 2 "" H 5050 6200 50  0000 C CNN
F 3 "" H 5050 6200 50  0000 C CNN
	1    5050 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 6200 5050 6150
Wire Wire Line
	5100 5450 5100 5400
Wire Wire Line
	5050 4700 5050 4650
Wire Wire Line
	5100 3750 5100 3700
Wire Wire Line
	3400 3950 3500 3950
Wire Wire Line
	3350 5450 3500 5450
Wire Wire Line
	1900 4700 1750 4700
Wire Wire Line
	2950 4550 3100 4550
Wire Wire Line
	3100 4550 3100 3800
Wire Wire Line
	3100 3800 3500 3800
Wire Wire Line
	8800 4450 8900 4450
Wire Wire Line
	8900 4450 8900 4800
Wire Wire Line
	7150 4100 7150 3800
Wire Wire Line
	7150 3800 7050 3800
Wire Wire Line
	6900 5300 7000 5300
Wire Wire Line
	7000 5300 7000 5650
Wire Wire Line
	6900 5450 7450 5450
Wire Wire Line
	7450 5450 7450 4600
Wire Wire Line
	7450 4600 7750 4600
Wire Wire Line
	5750 3800 6000 3800
Wire Wire Line
	5750 3950 6000 3950
Wire Wire Line
	5550 5100 5600 5100
Wire Wire Line
	5600 5100 5600 5300
Wire Wire Line
	5600 5300 5850 5300
$Comp
L HSWA2-30DR_switch U9
U 1 1 57C778A3
P 6400 5550
F 0 "U9" H 6350 5700 60  0000 C CNN
F 1 "HSWA2-30DR_switch" H 6400 5600 60  0000 C CNN
F 2 "Minicircuits:MC_DG983-1" H 6150 5600 60  0001 C CNN
F 3 "" H 6150 5600 60  0001 C CNN
	1    6400 5550
	1    0    0    1   
$EndComp
Wire Wire Line
	5850 5450 5600 5450
Wire Wire Line
	5600 5450 5600 5850
Wire Wire Line
	5600 5850 5500 5850
Wire Wire Line
	7050 3950 7450 3950
Wire Wire Line
	7450 3950 7450 4450
Wire Wire Line
	7450 4450 7750 4450
Text GLabel 1900 4950 0    60   Input ~ 0
S1C1
Text GLabel 1900 5050 0    60   Input ~ 0
S1C2
Text GLabel 3500 4200 0    60   Input ~ 0
S2C1
Text GLabel 3500 4300 0    60   Input ~ 0
S2C2
Text GLabel 3500 5700 0    60   Input ~ 0
S3C1
Text GLabel 3500 5800 0    60   Input ~ 0
S3C2
Text GLabel 7050 3550 2    60   Input ~ 0
S5C2
Text GLabel 7050 3450 2    60   Input ~ 0
S5C1
Text GLabel 6900 4950 2    60   Input ~ 0
S4C1
Text GLabel 6900 5050 2    60   Input ~ 0
S4C2
Text GLabel 8800 4100 2    60   Input ~ 0
S6C1
Text GLabel 8800 4200 2    60   Input ~ 0
S6C2
$Comp
L +3.3V #PWR015
U 1 1 57C7EC86
P 4600 3700
F 0 "#PWR015" H 4600 3550 50  0001 C CNN
F 1 "+3.3V" H 4600 3840 50  0000 C CNN
F 2 "" H 4600 3700 50  0000 C CNN
F 3 "" H 4600 3700 50  0000 C CNN
	1    4600 3700
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR016
U 1 1 57C7EEA0
P 4650 5200
F 0 "#PWR016" H 4650 5050 50  0001 C CNN
F 1 "+3.3V" H 4650 5340 50  0000 C CNN
F 2 "" H 4650 5200 50  0000 C CNN
F 3 "" H 4650 5200 50  0000 C CNN
	1    4650 5200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR017
U 1 1 57C7F2BB
P 3000 4450
F 0 "#PWR017" H 3000 4300 50  0001 C CNN
F 1 "+3.3V" H 3000 4590 50  0000 C CNN
F 2 "" H 3000 4450 50  0000 C CNN
F 3 "" H 3000 4450 50  0000 C CNN
	1    3000 4450
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR018
U 1 1 57C7F550
P 5900 3350
F 0 "#PWR018" H 5900 3200 50  0001 C CNN
F 1 "+3.3V" H 5900 3490 50  0000 C CNN
F 2 "" H 5900 3350 50  0000 C CNN
F 3 "" H 5900 3350 50  0000 C CNN
	1    5900 3350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR019
U 1 1 57C7F6FF
P 5750 4800
F 0 "#PWR019" H 5750 4650 50  0001 C CNN
F 1 "+3.3V" H 5750 4940 50  0000 C CNN
F 2 "" H 5750 4800 50  0000 C CNN
F 3 "" H 5750 4800 50  0000 C CNN
	1    5750 4800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR020
U 1 1 57C7FA52
P 7600 4000
F 0 "#PWR020" H 7600 3850 50  0001 C CNN
F 1 "+3.3V" H 7600 4140 50  0000 C CNN
F 2 "" H 7600 4000 50  0000 C CNN
F 3 "" H 7600 4000 50  0000 C CNN
	1    7600 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 4000 7600 4300
Wire Wire Line
	7600 4300 7750 4300
Wire Wire Line
	5850 5150 5750 5150
Wire Wire Line
	5750 5150 5750 4800
Wire Wire Line
	4550 5600 4650 5600
Wire Wire Line
	4650 5600 4650 5200
Wire Wire Line
	4550 4100 4600 4100
Wire Wire Line
	4600 4100 4600 3700
Wire Wire Line
	6000 3650 5900 3650
Wire Wire Line
	5900 3650 5900 3350
Wire Wire Line
	2950 4850 3000 4850
Wire Wire Line
	3000 4850 3000 4450
$Comp
L GND #PWR?
U 1 1 57C80E35
P 4600 5900
F 0 "#PWR?" H 4600 5650 50  0001 C CNN
F 1 "GND" H 4600 5750 50  0000 C CNN
F 2 "" H 4600 5900 50  0000 C CNN
F 3 "" H 4600 5900 50  0000 C CNN
	1    4600 5900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57C80ECC
P 3000 5200
F 0 "#PWR?" H 3000 4950 50  0001 C CNN
F 1 "GND" H 3000 5050 50  0000 C CNN
F 2 "" H 3000 5200 50  0000 C CNN
F 3 "" H 3000 5200 50  0000 C CNN
	1    3000 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57C80FEF
P 4600 4400
F 0 "#PWR?" H 4600 4150 50  0001 C CNN
F 1 "GND" H 4600 4250 50  0000 C CNN
F 2 "" H 4600 4400 50  0000 C CNN
F 3 "" H 4600 4400 50  0000 C CNN
	1    4600 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57C811EE
P 5800 5550
F 0 "#PWR?" H 5800 5300 50  0001 C CNN
F 1 "GND" H 5800 5400 50  0000 C CNN
F 2 "" H 5800 5550 50  0000 C CNN
F 3 "" H 5800 5550 50  0000 C CNN
	1    5800 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57C81451
P 5950 4100
F 0 "#PWR?" H 5950 3850 50  0001 C CNN
F 1 "GND" H 5950 3950 50  0000 C CNN
F 2 "" H 5950 4100 50  0000 C CNN
F 3 "" H 5950 4100 50  0000 C CNN
	1    5950 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57C8168C
P 7700 4750
F 0 "#PWR?" H 7700 4500 50  0001 C CNN
F 1 "GND" H 7700 4600 50  0000 C CNN
F 2 "" H 7700 4750 50  0000 C CNN
F 3 "" H 7700 4750 50  0000 C CNN
	1    7700 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4100 7700 4100
Wire Wire Line
	7700 4100 7700 4750
Wire Wire Line
	7750 4200 7700 4200
Connection ~ 7700 4200
Wire Wire Line
	5850 4950 5800 4950
Wire Wire Line
	5800 4950 5800 5550
Wire Wire Line
	5850 5050 5800 5050
Connection ~ 5800 5050
Wire Wire Line
	4600 5700 4600 5900
Wire Wire Line
	4600 5700 4550 5700
Wire Wire Line
	4550 5800 4600 5800
Connection ~ 4600 5800
Wire Wire Line
	3000 5200 3000 4950
Wire Wire Line
	3000 4950 2950 4950
Wire Wire Line
	2950 5050 3000 5050
Connection ~ 3000 5050
Wire Wire Line
	4550 4200 4600 4200
Wire Wire Line
	4600 4200 4600 4400
Wire Wire Line
	4550 4300 4600 4300
Connection ~ 4600 4300
Wire Wire Line
	6000 3450 5950 3450
Wire Wire Line
	5950 3450 5950 4100
Wire Wire Line
	6000 3550 5950 3550
Connection ~ 5950 3550
Text GLabel 3500 1800 2    60   Input ~ 0
AMP1_Out
Text GLabel 1650 4550 0    60   Input ~ 0
AMP1_Out
Wire Wire Line
	1650 4550 1900 4550
Wire Wire Line
	3350 1800 3500 1800
Text GLabel 9150 4600 2    60   Input ~ 0
AMP2_In
Wire Wire Line
	8800 4600 9150 4600
$EndSCHEMATC
