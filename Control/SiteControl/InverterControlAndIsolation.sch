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
LIBS:SiteControl-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
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
L RJ50 J1
U 1 1 57AA9980
P 2300 1800
F 0 "J1" H 2500 2300 50  0000 C CNN
F 1 "RJ50" H 2150 2300 50  0000 C CNN
F 2 "DigitalLogic:RJ50_RJE051AA1310" H 2300 1800 50  0001 C CNN
F 3 "" H 2300 1800 50  0000 C CNN
F 4 "RJE051AA1310" V 1850 1900 60  0000 C CNN "Model"
	1    2300 1800
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR01
U 1 1 57AA9C99
P 1950 2600
F 0 "#PWR01" H 1950 2350 50  0001 C CNN
F 1 "GND" H 1950 2450 50  0000 C CNN
F 2 "" H 1950 2600 50  0000 C CNN
F 3 "" H 1950 2600 50  0000 C CNN
	1    1950 2600
	1    0    0    -1  
$EndComp
$Comp
L Opto_H11L1M U5
U 1 1 57AAA2EC
P 6150 1900
F 0 "U5" H 5950 2100 50  0000 L CNN
F 1 "Opto_H11L1M" H 6150 2100 50  0000 L CNN
F 2 "DigitalLogic:H11L1M" H 5950 1700 50  0001 L CIN
F 3 "" H 6125 1930 50  0000 L CNN
	1    6150 1900
	-1   0    0    -1  
$EndComp
$Comp
L Opto_H11L1M U1
U 1 1 57AAA5BD
P 3400 3850
F 0 "U1" H 3200 4050 50  0000 L CNN
F 1 "Opto_H11L1M" H 3400 4050 50  0000 L CNN
F 2 "DigitalLogic:H11L1M" H 3200 3650 50  0001 L CIN
F 3 "" H 3375 3880 50  0000 L CNN
	1    3400 3850
	1    0    0    -1  
$EndComp
$Comp
L Opto_H11L1M U2
U 1 1 57AAA609
P 3400 4250
F 0 "U2" H 3200 4450 50  0000 L CNN
F 1 "Opto_H11L1M" H 3400 4450 50  0000 L CNN
F 2 "DigitalLogic:H11L1M" H 3200 4050 50  0001 L CIN
F 3 "" H 3375 4280 50  0000 L CNN
	1    3400 4250
	1    0    0    -1  
$EndComp
$Comp
L Opto_H11L1M U3
U 1 1 57AAA677
P 3400 4650
F 0 "U3" H 3200 4850 50  0000 L CNN
F 1 "Opto_H11L1M" H 3400 4850 50  0000 L CNN
F 2 "DigitalLogic:H11L1M" H 3200 4450 50  0001 L CIN
F 3 "" H 3375 4680 50  0000 L CNN
	1    3400 4650
	1    0    0    -1  
$EndComp
$Comp
L Opto_H11L1M U4
U 1 1 57AAA67D
P 3400 5050
F 0 "U4" H 3200 5250 50  0000 L CNN
F 1 "Opto_H11L1M" H 3400 5250 50  0000 L CNN
F 2 "DigitalLogic:H11L1M" H 3200 4850 50  0001 L CIN
F 3 "" H 3375 5080 50  0000 L CNN
	1    3400 5050
	1    0    0    -1  
$EndComp
$Comp
L BC817-40 Q1
U 1 1 57AAA77C
P 5500 2000
F 0 "Q1" H 5700 2075 50  0000 L CNN
F 1 "BC817-40" H 5700 2000 50  0000 L CNN
F 2 "SOT-23" H 5700 1925 50  0000 L CIN
F 3 "" H 5500 2000 50  0000 L CNN
F 4 "MMBT2222LT1G" H 6050 1850 60  0000 C CNN "Model"
	1    5500 2000
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 57AAABAC
P 5400 1600
F 0 "R1" V 5480 1600 50  0000 C CNN
F 1 "10K" V 5400 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5330 1600 50  0001 C CNN
F 3 "" H 5400 1600 50  0000 C CNN
	1    5400 1600
	1    0    0    -1  
$EndComp
Text GLabel 2950 2350 2    60   Input ~ 0
INV_LCD_GND
Text GLabel 2950 1450 2    60   Input ~ 0
INV_TOGGLE
Text GLabel 2950 1550 2    60   Input ~ 0
INV_AVCC
Text GLabel 2950 1650 2    60   Input ~ 0
INV_LCD_GND
Text GLabel 2950 1750 2    60   Input ~ 0
INV_VCC
Text GLabel 2950 1850 2    60   Input ~ 0
INV_LED_PowerOn
Text GLabel 2950 1950 2    60   Input ~ 0
INV_LED_OverTemp
Text GLabel 2950 2050 2    60   Input ~ 0
INV_LED_Overload
Text GLabel 2950 2150 2    60   Input ~ 0
INV_LCD_Light
Text GLabel 2950 2250 2    60   Input ~ 0
INV_LCD_Data
Text GLabel 5500 1350 2    60   Input ~ 0
INV_VCC
Text GLabel 5450 2300 2    60   Input ~ 0
INV_LCD_GND
Text GLabel 5100 1800 0    60   Input ~ 0
INV_TOGGLE
Text GLabel 9150 2800 2    60   Input ~ 0
INV_VCC
Text GLabel 9150 3150 2    60   Input ~ 0
INV_LCD_GND
$Comp
L CP1 C9
U 1 1 57AAC877
P 8950 2950
F 0 "C9" H 8975 3050 50  0000 L CNN
F 1 "0.1uF" H 8975 2850 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeR_EIA-2012" H 8950 2950 50  0001 C CNN
F 3 "" H 8950 2950 50  0000 C CNN
	1    8950 2950
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 57AAE425
P 8850 1750
F 0 "C10" H 8875 1850 50  0000 L CNN
F 1 "0.1uF" H 8875 1650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8888 1600 50  0001 C CNN
F 3 "" H 8850 1750 50  0000 C CNN
	1    8850 1750
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 57AAE644
P 9100 1750
F 0 "C11" H 9125 1850 50  0000 L CNN
F 1 "0.1uF" H 9125 1650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9138 1600 50  0001 C CNN
F 3 "" H 9100 1750 50  0000 C CNN
	1    9100 1750
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 57AAE6B9
P 9350 1750
F 0 "C12" H 9375 1850 50  0000 L CNN
F 1 "0.1uF" H 9375 1650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9388 1600 50  0001 C CNN
F 3 "" H 9350 1750 50  0000 C CNN
	1    9350 1750
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 57AAE6BF
P 9600 1750
F 0 "C13" H 9625 1850 50  0000 L CNN
F 1 "0.1uF" H 9625 1650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9638 1600 50  0001 C CNN
F 3 "" H 9600 1750 50  0000 C CNN
	1    9600 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 57AAE874
P 9200 2000
F 0 "#PWR02" H 9200 1750 50  0001 C CNN
F 1 "GND" H 9200 1850 50  0000 C CNN
F 2 "" H 9200 2000 50  0000 C CNN
F 3 "" H 9200 2000 50  0000 C CNN
	1    9200 2000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 57AAE8A2
P 9200 1500
F 0 "#PWR03" H 9200 1350 50  0001 C CNN
F 1 "+3.3V" H 9200 1650 50  0000 C CNN
F 2 "" H 9200 1500 50  0000 C CNN
F 3 "" H 9200 1500 50  0000 C CNN
	1    9200 1500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR04
U 1 1 57AAEEEF
P 4000 3700
F 0 "#PWR04" H 4000 3550 50  0001 C CNN
F 1 "+3.3V" H 4000 3850 50  0000 C CNN
F 2 "" H 4000 3700 50  0000 C CNN
F 3 "" H 4000 3700 50  0000 C CNN
	1    4000 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 57AAEF89
P 3850 5200
F 0 "#PWR05" H 3850 4950 50  0001 C CNN
F 1 "GND" H 3850 5050 50  0000 C CNN
F 2 "" H 3850 5200 50  0000 C CNN
F 3 "" H 3850 5200 50  0000 C CNN
	1    3850 5200
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 57AB00AA
P 6700 2000
F 0 "R20" V 6780 2000 50  0000 C CNN
F 1 "450R" V 6700 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6630 2000 50  0001 C CNN
F 3 "" H 6700 2000 50  0000 C CNN
	1    6700 2000
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 57AB03B1
P 6650 1650
F 0 "R19" V 6730 1650 50  0000 C CNN
F 1 "1K" V 6650 1650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6580 1650 50  0001 C CNN
F 3 "" H 6650 1650 50  0000 C CNN
	1    6650 1650
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 57AB0418
P 6650 1450
F 0 "#PWR06" H 6650 1300 50  0001 C CNN
F 1 "+3.3V" H 6650 1600 50  0000 C CNN
F 2 "" H 6650 1450 50  0000 C CNN
F 3 "" H 6650 1450 50  0000 C CNN
	1    6650 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 57AB0450
P 6900 2050
F 0 "#PWR07" H 6900 1800 50  0001 C CNN
F 1 "GND" H 6900 1900 50  0000 C CNN
F 2 "" H 6900 2050 50  0000 C CNN
F 3 "" H 6900 2050 50  0000 C CNN
	1    6900 2050
	1    0    0    -1  
$EndComp
Text GLabel 6900 1800 2    60   Input ~ 0
INV_Toggle_Safe
$Comp
L R R18
U 1 1 57AB13FE
P 4600 4100
F 0 "R18" V 4680 4100 50  0000 C CNN
F 1 "1K" V 4600 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4530 4100 50  0001 C CNN
F 3 "" H 4600 4100 50  0000 C CNN
	1    4600 4100
	-1   0    0    1   
$EndComp
$Comp
L R R17
U 1 1 57AB1632
P 4450 4500
F 0 "R17" V 4530 4500 50  0000 C CNN
F 1 "1K" V 4450 4500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 4500 50  0001 C CNN
F 3 "" H 4450 4500 50  0000 C CNN
	1    4450 4500
	-1   0    0    1   
$EndComp
$Comp
L R R16
U 1 1 57AB1681
P 4300 4900
F 0 "R16" V 4380 4900 50  0000 C CNN
F 1 "1K" V 4300 4900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4230 4900 50  0001 C CNN
F 3 "" H 4300 4900 50  0000 C CNN
	1    4300 4900
	-1   0    0    1   
$EndComp
$Comp
L R R15
U 1 1 57AB1875
P 4150 5300
F 0 "R15" V 4230 5300 50  0000 C CNN
F 1 "1K" V 4150 5300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4080 5300 50  0001 C CNN
F 3 "" H 4150 5300 50  0000 C CNN
	1    4150 5300
	-1   0    0    1   
$EndComp
Wire Wire Line
	1950 2550 1950 2600
Wire Wire Line
	9150 2800 8950 2800
Wire Wire Line
	8950 3100 8950 3150
Wire Wire Line
	8950 3150 9150 3150
Wire Wire Line
	5500 1350 5400 1350
Wire Wire Line
	5400 1350 5400 1450
Wire Wire Line
	5400 1450 5600 1450
Wire Wire Line
	5600 1450 5600 1800
Wire Wire Line
	5600 1800 5850 1800
Connection ~ 5400 1450
Wire Wire Line
	5400 2200 5400 2300
Wire Wire Line
	5400 2300 5450 2300
Wire Wire Line
	5400 2200 5750 2200
Wire Wire Line
	5750 2200 5750 1900
Wire Wire Line
	5750 1900 5850 1900
Wire Wire Line
	5850 2000 5700 2000
Wire Wire Line
	5400 1800 5400 1750
Wire Wire Line
	5100 1800 5400 1800
Connection ~ 5400 2200
Connection ~ 5400 1800
Wire Wire Line
	2750 1450 2950 1450
Wire Wire Line
	2950 1550 2750 1550
Wire Wire Line
	2750 1650 2950 1650
Wire Wire Line
	2950 1750 2750 1750
Wire Wire Line
	2750 1850 2950 1850
Wire Wire Line
	2950 1950 2750 1950
Wire Wire Line
	2750 2050 2950 2050
Wire Wire Line
	2950 2150 2750 2150
Wire Wire Line
	2750 2250 2950 2250
Wire Wire Line
	2950 2350 2750 2350
Wire Wire Line
	8850 1600 8850 1550
Wire Wire Line
	8850 1550 9600 1550
Wire Wire Line
	9600 1550 9600 1600
Wire Wire Line
	9100 1600 9100 1550
Connection ~ 9100 1550
Wire Wire Line
	9350 1600 9350 1550
Connection ~ 9350 1550
Wire Wire Line
	9200 1500 9200 1550
Connection ~ 9200 1550
Wire Wire Line
	8850 1900 8850 1950
Wire Wire Line
	8850 1950 9600 1950
Wire Wire Line
	9600 1950 9600 1900
Wire Wire Line
	9200 2000 9200 1950
Connection ~ 9200 1950
Wire Wire Line
	9100 1900 9100 1950
Connection ~ 9100 1950
Wire Wire Line
	9350 1900 9350 1950
Connection ~ 9350 1950
Wire Wire Line
	3700 3750 4000 3750
Wire Wire Line
	4000 3700 4000 4950
Wire Wire Line
	4000 4150 3700 4150
Connection ~ 4000 3750
Wire Wire Line
	4000 4550 3700 4550
Connection ~ 4000 4150
Wire Wire Line
	4000 4950 3700 4950
Connection ~ 4000 4550
Wire Wire Line
	3850 3850 3850 5200
Wire Wire Line
	3850 5050 3700 5050
Wire Wire Line
	3850 4650 3700 4650
Connection ~ 3850 5050
Wire Wire Line
	3850 4250 3700 4250
Connection ~ 3850 4650
Wire Wire Line
	3850 3850 3700 3850
Connection ~ 3850 4250
Wire Wire Line
	6450 1800 6900 1800
Connection ~ 6650 1800
Wire Wire Line
	6650 1500 6650 1450
Wire Wire Line
	6450 2000 6550 2000
Wire Wire Line
	6850 2000 6900 2000
Wire Wire Line
	6900 2000 6900 2050
Wire Wire Line
	3700 4750 4750 4750
Wire Wire Line
	3700 5150 4750 5150
Wire Wire Line
	3700 4350 4750 4350
Wire Wire Line
	3700 3950 4750 3950
$Comp
L GND #PWR08
U 1 1 57AB2454
P 4150 5450
F 0 "#PWR08" H 4150 5200 50  0001 C CNN
F 1 "GND" H 4150 5300 50  0000 C CNN
F 2 "" H 4150 5450 50  0000 C CNN
F 3 "" H 4150 5450 50  0000 C CNN
	1    4150 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 57AB2498
P 4300 5050
F 0 "#PWR09" H 4300 4800 50  0001 C CNN
F 1 "GND" H 4300 4900 50  0000 C CNN
F 2 "" H 4300 5050 50  0000 C CNN
F 3 "" H 4300 5050 50  0000 C CNN
	1    4300 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 57AB25BF
P 4450 4650
F 0 "#PWR010" H 4450 4400 50  0001 C CNN
F 1 "GND" H 4450 4500 50  0000 C CNN
F 2 "" H 4450 4650 50  0000 C CNN
F 3 "" H 4450 4650 50  0000 C CNN
	1    4450 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 57AB26C4
P 4600 4250
F 0 "#PWR011" H 4600 4000 50  0001 C CNN
F 1 "GND" H 4600 4100 50  0000 C CNN
F 2 "" H 4600 4250 50  0000 C CNN
F 3 "" H 4600 4250 50  0000 C CNN
	1    4600 4250
	1    0    0    -1  
$EndComp
Text GLabel 2400 3750 0    60   Input ~ 0
INV_LED_PowerOn
Text GLabel 2400 4150 0    60   Input ~ 0
INV_LED_OverTemp
Text GLabel 2400 4550 0    60   Input ~ 0
INV_LED_Overload
Text GLabel 2400 4950 0    60   Input ~ 0
INV_LCD_Data
$Comp
L R R11
U 1 1 57AB3CF7
P 2900 4050
F 0 "R11" V 2800 4050 50  0000 C CNN
F 1 "100R" V 2900 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2830 4050 50  0001 C CNN
F 3 "" H 2900 4050 50  0000 C CNN
	1    2900 4050
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 57AB52A8
P 2600 3900
F 0 "R7" V 2680 3900 50  0000 C CNN
F 1 "10K" V 2600 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2530 3900 50  0001 C CNN
F 3 "" H 2600 3900 50  0000 C CNN
	1    2600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 57AB56DF
P 2950 4450
F 0 "R12" V 2850 4450 50  0000 C CNN
F 1 "100R" V 2950 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2880 4450 50  0001 C CNN
F 3 "" H 2950 4450 50  0000 C CNN
	1    2950 4450
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 57AB56E5
P 2650 4300
F 0 "R8" V 2730 4300 50  0000 C CNN
F 1 "10K" V 2650 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 4300 50  0001 C CNN
F 3 "" H 2650 4300 50  0000 C CNN
	1    2650 4300
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 57AB5941
P 2950 4850
F 0 "R13" V 2850 4850 50  0000 C CNN
F 1 "100R" V 2950 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2880 4850 50  0001 C CNN
F 3 "" H 2950 4850 50  0000 C CNN
	1    2950 4850
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 57AB5947
P 2650 4700
F 0 "R9" V 2730 4700 50  0000 C CNN
F 1 "10K" V 2650 4700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 4700 50  0001 C CNN
F 3 "" H 2650 4700 50  0000 C CNN
	1    2650 4700
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 57AB59B1
P 2950 5250
F 0 "R14" V 2850 5250 50  0000 C CNN
F 1 "100R" V 2950 5250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2880 5250 50  0001 C CNN
F 3 "" H 2950 5250 50  0000 C CNN
	1    2950 5250
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 57AB59B7
P 2650 5100
F 0 "R10" V 2730 5100 50  0000 C CNN
F 1 "10K" V 2650 5100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 5100 50  0001 C CNN
F 3 "" H 2650 5100 50  0000 C CNN
	1    2650 5100
	1    0    0    -1  
$EndComp
Text GLabel 2400 5300 0    60   Input ~ 0
INV_LCD_GND
Wire Wire Line
	2400 5300 2650 5300
Wire Wire Line
	2650 5300 2650 5250
Wire Wire Line
	2650 5250 2800 5250
Wire Wire Line
	3100 5250 3100 5150
Wire Wire Line
	2400 4950 3100 4950
Connection ~ 2650 4950
Wire Wire Line
	2550 4850 2800 4850
Wire Wire Line
	2550 4050 2550 5300
Connection ~ 2550 5300
Connection ~ 2650 4850
Wire Wire Line
	3100 4850 3100 4750
Connection ~ 2650 5250
Wire Wire Line
	2400 4550 3100 4550
Connection ~ 2650 4550
Wire Wire Line
	2550 4450 2800 4450
Wire Wire Line
	3100 4450 3100 4350
Connection ~ 2550 4850
Connection ~ 2650 4450
Wire Wire Line
	2400 4150 3100 4150
Connection ~ 2650 4150
Wire Wire Line
	3050 4050 3050 3950
Wire Wire Line
	3050 3950 3100 3950
Wire Wire Line
	2550 4050 2750 4050
Connection ~ 2550 4450
Connection ~ 2600 4050
Wire Wire Line
	2400 3750 3100 3750
Connection ~ 2600 3750
Text GLabel 4750 3950 2    60   Input ~ 0
INV_Temp_Safe
Text GLabel 4750 4350 2    60   Input ~ 0
INV_Power_Safe
Text GLabel 4750 4750 2    60   Input ~ 0
INV_Overload_Safe
Text GLabel 4750 5150 2    60   Input ~ 0
INV_Data_Safe
Connection ~ 4600 3950
Connection ~ 4450 4350
Connection ~ 4300 4750
Connection ~ 4150 5150
Wire Notes Line
	8600 2600 8600 3400
Wire Notes Line
	8600 3400 9950 3400
Wire Notes Line
	9950 3400 9950 2600
Wire Notes Line
	9950 2600 8600 2600
Wire Notes Line
	4400 1100 4400 2550
Wire Notes Line
	4400 2550 8050 2550
Wire Notes Line
	8050 2550 8050 1100
Wire Notes Line
	8050 1100 4400 1100
Wire Notes Line
	8450 1100 8450 2350
Wire Notes Line
	8450 2350 10100 2350
Wire Notes Line
	10100 2350 10100 1100
Wire Notes Line
	10100 1100 8450 1100
Wire Notes Line
	1550 2850 4000 2850
Wire Notes Line
	4000 2850 4000 1150
Wire Notes Line
	4000 1150 1550 1150
Wire Notes Line
	1550 1150 1550 2850
Wire Notes Line
	1200 3250 1200 5850
Wire Notes Line
	1200 5850 5950 5850
Wire Notes Line
	5950 5850 5950 3250
Wire Notes Line
	5950 3250 1200 3250
Text Notes 7100 1200 2    60   ~ 0
Toggle Isolation Circuit
Text Notes 8700 2700 0    60   ~ 0
Toggle Power Decoupling
Text Notes 2050 1250 0    60   ~ 0
Inverter Input Jack
Text Notes 2500 3400 0    60   ~ 0
Inverter Output Signal Isolation
Text Notes 8650 1250 0    60   ~ 0
Inverter Isolation Decoupling
Text Notes 7200 6800 0    60   ~ 0
Applied Physics Club\nThe Pennsylvania State University
Text Notes 9050 7650 2    60   ~ 0
August 11, 2016
Text Notes 9100 7500 2    60   ~ 0
Telescope Base Station Control Board
Text Notes 6500 4900 0    60   ~ 0
NOTES: The Samlex PST2000-12 inverter contains an RJ50 jack for interfacing \nwith the RC-200 remote control. The engineers at Samlex have kindly provided \napplication circuits for the basic circuitry within the RC-200 which will allow us \nto improvise our own controller which can be directly connected to the PIC 16 \nand thus the Raspberry Pi and RF Modem. This will allow us to remotely \n(from a distance of several km) activate and de-activate the inverter, as well \nas monitor information such as voltage, temperature, and power consumption.\n\nSince the inverter RJ50 jack contains inverter main board level voltages \n(supposedly VBATT), the circuit will be isolated from the rest of the control \nboard via opto-isolators. The metal case of the RJ50 jack will, however, be \ngrounded to the chassis ground.
$EndSCHEMATC