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
Sheet 7 9
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
L GND #PWR64
U 1 1 57ABFEE2
P 1600 2150
F 0 "#PWR64" H 1600 1900 50  0001 C CNN
F 1 "GND" H 1600 2000 50  0000 C CNN
F 2 "" H 1600 2150 50  0000 C CNN
F 3 "" H 1600 2150 50  0000 C CNN
	1    1600 2150
	1    0    0    -1  
$EndComp
$Comp
L SS_Relay_VO14642AT U8
U 1 1 57AC0A90
P 3400 1750
F 0 "U8" H 3200 1950 50  0000 L CNN
F 1 "SS_Relay_VO14642AT" H 3000 1550 50  0000 L CNN
F 2 "DigitalLogic:SS_Relay_VO14642AT" H 3200 1550 50  0001 L CIN
F 3 "" H 3350 1750 50  0000 L CNN
	1    3400 1750
	-1   0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 57AC1D42
P 3950 2000
F 0 "R23" V 4030 2000 50  0000 C CNN
F 1 "450R" V 3950 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3880 2000 50  0001 C CNN
F 3 "" H 3950 2000 50  0000 C CNN
	1    3950 2000
	-1   0    0    1   
$EndComp
Text GLabel 4250 1650 2    60   Input ~ 0
RPi_En
$Comp
L R R24
U 1 1 57AC1E59
P 4150 2000
F 0 "R24" V 4230 2000 50  0000 C CNN
F 1 "10K" V 4150 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4080 2000 50  0001 C CNN
F 3 "" H 4150 2000 50  0000 C CNN
	1    4150 2000
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR72
U 1 1 57AC1F73
P 4050 2150
F 0 "#PWR72" H 4050 1900 50  0001 C CNN
F 1 "GND" H 4050 2000 50  0000 C CNN
F 2 "" H 4050 2150 50  0000 C CNN
F 3 "" H 4050 2150 50  0000 C CNN
	1    4050 2150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR69
U 1 1 57AC243A
P 3050 1550
F 0 "#PWR69" H 3050 1400 50  0001 C CNN
F 1 "+5V" H 3050 1690 50  0000 C CNN
F 2 "" H 3050 1550 50  0000 C CNN
F 3 "" H 3050 1550 50  0000 C CNN
	1    3050 1550
	1    0    0    -1  
$EndComp
Text Notes 1450 1350 0    60   ~ 0
Solid-State Switch and Connector for Pi
$Comp
L +BATT #PWR67
U 1 1 57AD9368
P 2300 3800
F 0 "#PWR67" H 2300 3650 50  0001 C CNN
F 1 "+BATT" H 2300 3940 50  0000 C CNN
F 2 "" H 2300 3800 50  0000 C CNN
F 3 "" H 2300 3800 50  0000 C CNN
	1    2300 3800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR78
U 1 1 57AD9437
P 5950 3950
F 0 "#PWR78" H 5950 3800 50  0001 C CNN
F 1 "+5V" H 5950 4090 50  0000 C CNN
F 2 "" H 5950 3950 50  0000 C CNN
F 3 "" H 5950 3950 50  0000 C CNN
	1    5950 3950
	1    0    0    -1  
$EndComp
$Comp
L C C20
U 1 1 57ADA01E
P 5650 4500
F 0 "C20" H 5675 4600 50  0000 L CNN
F 1 "47uF" H 5675 4400 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 5688 4350 50  0001 C CNN
F 3 "" H 5650 4500 50  0000 C CNN
	1    5650 4500
	1    0    0    -1  
$EndComp
$Comp
L C C21
U 1 1 57ADA0B2
P 5950 4500
F 0 "C21" H 5975 4600 50  0000 L CNN
F 1 "0.1uF" H 5975 4400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5988 4350 50  0001 C CNN
F 3 "" H 5950 4500 50  0000 C CNN
	1    5950 4500
	1    0    0    -1  
$EndComp
Text Notes 2800 3500 0    60   ~ 0
5V Buck Converter Supply [ 51 KHz ]
Text GLabel 1800 4200 0    60   Input ~ 0
RPi_5v_En
$Comp
L GND #PWR66
U 1 1 57AEB2D9
P 2100 4800
F 0 "#PWR66" H 2100 4550 50  0001 C CNN
F 1 "GND" H 2100 4650 50  0000 C CNN
F 2 "" H 2100 4800 50  0000 C CNN
F 3 "" H 2100 4800 50  0000 C CNN
	1    2100 4800
	-1   0    0    -1  
$EndComp
Text Notes 7150 6800 0    60   ~ 0
Applied Physics Club\nThe Pennsylvania State University
Text Notes 9075 7650 2    60   ~ 0
September 27, 2016
Text Notes 9050 7500 2    60   ~ 0
Telescope Base Station Control Board
Text Notes 1150 7000 0    60   ~ 0
NOTES: This power supply should supply up to 1.8 A @ 5 VDC. The \nRaspberry Pi B+ only consumes 350 mA under heavy load, however, \nthe Raspberry Pi 3 consumes 1.2 A under heavy load. Allowing for up to \n1.8 A supply allows for a future move to a Raspberry Pi 3 without replacing \nthis circuit.\n\nThe buck converter circuit was taken obtained via the Texas Instruments\nWebBench design and optimization software.\n\nThe relay control of the buck converter has been changed given the enable\nsignal in the converter controller. This allowed us to remove the 5V enable relay,\nwhile maintaining the output relay to quickly hard cycle the Pi, as well as allow\nfor a soft start without prematurely powering the Pi. The PGood signal will be\nused to determine when the Pi can be safely powered on.
$Comp
L LM43602 U9
U 1 1 57EAFF1D
P 3900 4150
F 0 "U9" H 3700 4350 50  0000 C CNN
F 1 "LM43602" H 3900 4350 50  0000 L CNN
F 2 "DigitalLogic:TI_HTSSOP-PWP-16" H 3900 4250 50  0001 C CIN
F 3 "" H 3900 4150 50  0000 C CNN
	1    3900 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR71
U 1 1 57EB01C4
P 3300 4800
F 0 "#PWR71" H 3300 4550 50  0001 C CNN
F 1 "GND" H 3300 4650 50  0000 C CNN
F 2 "" H 3300 4800 50  0000 C CNN
F 3 "" H 3300 4800 50  0000 C CNN
	1    3300 4800
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR74
U 1 1 57EB01ED
P 4400 4800
F 0 "#PWR74" H 4400 4550 50  0001 C CNN
F 1 "GND" H 4400 4650 50  0000 C CNN
F 2 "" H 4400 4800 50  0000 C CNN
F 3 "" H 4400 4800 50  0000 C CNN
	1    4400 4800
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR73
U 1 1 57EB0216
P 4200 3700
F 0 "#PWR73" H 4200 3450 50  0001 C CNN
F 1 "GND" H 4200 3550 50  0000 C CNN
F 2 "" H 4200 3700 50  0000 C CNN
F 3 "" H 4200 3700 50  0000 C CNN
	1    4200 3700
	-1   0    0    -1  
$EndComp
NoConn ~ 3400 4400
$Comp
L R R27
U 1 1 57EB04B9
P 3100 4650
F 0 "R27" V 3180 4650 50  0000 C CNN
F 1 "205K" V 3100 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3030 4650 50  0001 C CNN
F 3 "" H 3100 4650 50  0000 C CNN
	1    3100 4650
	1    0    0    1   
$EndComp
$Comp
L GND #PWR70
U 1 1 57EB0562
P 3100 4800
F 0 "#PWR70" H 3100 4550 50  0001 C CNN
F 1 "GND" H 3100 4650 50  0000 C CNN
F 2 "" H 3100 4800 50  0000 C CNN
F 3 "" H 3100 4800 50  0000 C CNN
	1    3100 4800
	-1   0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 57EB0794
P 2100 4600
F 0 "R26" V 2180 4600 50  0000 C CNN
F 1 "10K" V 2100 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2030 4600 50  0001 C CNN
F 3 "" H 2100 4600 50  0000 C CNN
	1    2100 4600
	1    0    0    1   
$EndComp
$Comp
L R R25
U 1 1 57EB07F1
P 1900 4600
F 0 "R25" V 1980 4600 50  0000 C CNN
F 1 "10K" V 1900 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1830 4600 50  0001 C CNN
F 3 "" H 1900 4600 50  0000 C CNN
	1    1900 4600
	1    0    0    1   
$EndComp
$Comp
L GND #PWR65
U 1 1 57EB0829
P 1900 4800
F 0 "#PWR65" H 1900 4550 50  0001 C CNN
F 1 "GND" H 1900 4650 50  0000 C CNN
F 2 "" H 1900 4800 50  0000 C CNN
F 3 "" H 1900 4800 50  0000 C CNN
	1    1900 4800
	-1   0    0    -1  
$EndComp
Text GLabel 1800 4300 0    60   Input ~ 0
RPi_5v_PGood
$Comp
L C_Small C19
U 1 1 57EB0E11
P 4000 3700
F 0 "C19" H 4010 3770 50  0000 L CNN
F 1 "2.2uF" V 3900 3650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4000 3700 50  0001 C CNN
F 3 "" H 4000 3700 50  0000 C CNN
	1    4000 3700
	0    1    1    0   
$EndComp
$Comp
L C_Small C37
U 1 1 57EB0F56
P 4550 4250
F 0 "C37" H 4560 4320 50  0000 L CNN
F 1 "0.47uF" H 4560 4170 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4550 4250 50  0001 C CNN
F 3 "" H 4550 4250 50  0000 C CNN
	1    4550 4250
	-1   0    0    1   
$EndComp
$Comp
L L_Small L1
U 1 1 57EB0FDE
P 4700 4100
F 0 "L1" H 4730 4140 50  0000 L CNN
F 1 "22uH" H 4730 4060 50  0000 L CNN
F 2 "Inductors:SELF-WE-PD-XXL" H 4700 4100 50  0001 C CNN
F 3 "" H 4700 4100 50  0000 C CNN
F 4 "CDRH125NP" V 4950 4000 60  0000 C CNN "Model"
	1    4700 4100
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C38
U 1 1 57EB1091
P 4850 4700
F 0 "C38" H 4860 4770 50  0000 L CNN
F 1 "4.7uF" H 4860 4620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4850 4700 50  0001 C CNN
F 3 "" H 4850 4700 50  0000 C CNN
	1    4850 4700
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR75
U 1 1 57EB1189
P 4850 4800
F 0 "#PWR75" H 4850 4550 50  0001 C CNN
F 1 "GND" H 4850 4650 50  0000 C CNN
F 2 "" H 4850 4800 50  0000 C CNN
F 3 "" H 4850 4800 50  0000 C CNN
	1    4850 4800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1300 2100 1900 2100
Wire Wire Line
	1600 2100 1600 2150
Wire Wire Line
	1850 1850 1900 1850
Wire Wire Line
	1900 1850 1900 2100
Connection ~ 1600 2100
Wire Wire Line
	1850 1750 3100 1750
Wire Wire Line
	3050 1850 3100 1850
Wire Wire Line
	3050 1550 3050 1850
Wire Wire Line
	3050 1650 3100 1650
Wire Wire Line
	3700 1650 4250 1650
Wire Wire Line
	4150 1850 4150 1650
Connection ~ 4150 1650
Wire Wire Line
	3700 1850 3950 1850
Wire Wire Line
	3950 2150 4150 2150
Connection ~ 4050 2150
Connection ~ 3050 1650
Wire Notes Line
	1300 1250 4850 1250
Wire Notes Line
	4850 1250 4850 2650
Wire Notes Line
	4850 2650 1050 2650
Wire Notes Line
	1050 2650 1050 1250
Wire Notes Line
	1050 1250 1350 1250
Wire Wire Line
	5950 3950 5950 4350
Wire Wire Line
	5650 4100 5650 4350
Connection ~ 5650 4100
Wire Wire Line
	5650 4800 5650 4650
Wire Wire Line
	5950 4800 5950 4650
Connection ~ 5950 4100
Wire Notes Line
	950  5300 6300 5300
Wire Notes Line
	6300 5300 6300 3300
Wire Notes Line
	6300 3300 950  3300
Wire Notes Line
	950  3300 950  5300
Wire Wire Line
	3900 3700 3900 3850
Wire Wire Line
	4100 3700 4200 3700
Wire Wire Line
	3400 4700 3300 4700
Wire Wire Line
	3300 4600 3300 4800
Wire Wire Line
	4400 4700 4400 4800
Wire Wire Line
	3400 4600 3300 4600
Connection ~ 3300 4700
Wire Wire Line
	3400 4500 3100 4500
Wire Wire Line
	2300 4100 3400 4100
Wire Wire Line
	1800 4200 3400 4200
Wire Wire Line
	1900 4200 1900 4450
Wire Wire Line
	1800 4300 3400 4300
Wire Wire Line
	2100 4300 2100 4450
Wire Wire Line
	2100 4750 2100 4800
Wire Wire Line
	1900 4750 1900 4800
Connection ~ 1900 4200
Connection ~ 2100 4300
Wire Wire Line
	4400 4450 4850 4450
Wire Wire Line
	4850 4100 4850 4600
Wire Wire Line
	4400 4350 4550 4350
Wire Wire Line
	4400 4100 4600 4100
Wire Wire Line
	4550 4150 4550 4100
Connection ~ 4550 4100
Wire Wire Line
	4800 4100 5950 4100
Connection ~ 4850 4450
$Comp
L R_Small R28
U 1 1 57EB15A7
P 5250 4250
F 0 "R28" H 5280 4270 50  0000 L CNN
F 1 "1M" H 5280 4210 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5250 4250 50  0001 C CNN
F 3 "" H 5250 4250 50  0000 C CNN
	1    5250 4250
	1    0    0    -1  
$EndComp
$Comp
L R_Small R29
U 1 1 57EB16A9
P 5250 4700
F 0 "R29" H 5280 4720 50  0000 L CNN
F 1 "255K" H 5280 4660 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5250 4700 50  0001 C CNN
F 3 "" H 5250 4700 50  0000 C CNN
	1    5250 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR76
U 1 1 57EB1703
P 5250 4800
F 0 "#PWR76" H 5250 4550 50  0001 C CNN
F 1 "GND" H 5250 4650 50  0000 C CNN
F 2 "" H 5250 4800 50  0000 C CNN
F 3 "" H 5250 4800 50  0000 C CNN
	1    5250 4800
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C39
U 1 1 57EB17CA
P 5100 4250
F 0 "C39" H 5110 4320 50  0000 L CNN
F 1 "33pF" H 5110 4170 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5100 4250 50  0001 C CNN
F 3 "" H 5100 4250 50  0000 C CNN
	1    5100 4250
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR77
U 1 1 57EB19A3
P 5800 4800
F 0 "#PWR77" H 5800 4550 50  0001 C CNN
F 1 "GND" H 5800 4650 50  0000 C CNN
F 2 "" H 5800 4800 50  0000 C CNN
F 3 "" H 5800 4800 50  0000 C CNN
	1    5800 4800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5650 4800 5950 4800
Connection ~ 5800 4800
Connection ~ 4850 4100
Wire Wire Line
	5100 4100 5100 4150
Connection ~ 5100 4100
Wire Wire Line
	5100 4350 5100 4550
Wire Wire Line
	4400 4550 5250 4550
Wire Wire Line
	5250 4350 5250 4600
Connection ~ 5100 4550
Connection ~ 5250 4550
Wire Wire Line
	5250 4150 5250 4100
Connection ~ 5250 4100
$Comp
L C_Small C17
U 1 1 57EB2626
P 2550 4600
F 0 "C17" V 2500 4350 50  0000 L CNN
F 1 "1uF" V 2450 4550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2550 4600 50  0001 C CNN
F 3 "" H 2550 4600 50  0000 C CNN
	1    2550 4600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR68
U 1 1 57EB2715
P 2700 4800
F 0 "#PWR68" H 2700 4550 50  0001 C CNN
F 1 "GND" H 2700 4650 50  0000 C CNN
F 2 "" H 2700 4800 50  0000 C CNN
F 3 "" H 2700 4800 50  0000 C CNN
	1    2700 4800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2800 4750 2800 4700
Wire Wire Line
	2300 4750 2800 4750
Wire Wire Line
	2550 4750 2550 4700
Wire Wire Line
	2700 4800 2700 4750
Connection ~ 2700 4750
Connection ~ 2550 4100
Wire Wire Line
	2800 4500 2800 4100
Connection ~ 2800 4100
$Comp
L C_Small C18
U 1 1 57EB2EEF
P 2800 4600
F 0 "C18" V 2750 4325 50  0000 L CNN
F 1 "22uF" V 2700 4550 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 2800 4600 50  0001 C CNN
F 3 "" H 2800 4600 50  0000 C CNN
	1    2800 4600
	-1   0    0    1   
$EndComp
Text Notes 4150 3650 0    30   ~ 0
Cvcc
Text Notes 3150 4600 0    30   ~ 0
Rt
Text Notes 2550 4550 0    30   ~ 0
Cinx
Text Notes 2800 4550 0    30   ~ 0
Cin
Text Notes 4550 4200 0    30   ~ 0
Cboot
Text Notes 4800 4050 0    30   ~ 0
L1
Text Notes 5100 4200 0    30   ~ 0
Cfl
Text Notes 5300 4200 0    30   ~ 0
Rfbt
Text Notes 5300 4600 0    30   ~ 0
Rfbb
Text Notes 4900 4650 0    30   ~ 0
CBias
Text Notes 5650 4350 0    30   ~ 0
Cout
$Comp
L CP1_Small C16
U 1 1 57EB4C32
P 2300 4600
F 0 "C16" H 2310 4670 50  0000 L CNN
F 1 "47uF" H 2310 4520 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.8" H 2300 4600 50  0001 C CNN
F 3 "" H 2300 4600 50  0000 C CNN
	1    2300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3800 2300 4500
Wire Wire Line
	2300 4700 2300 4750
Connection ~ 2550 4750
Connection ~ 2300 4100
Wire Wire Line
	2550 4100 2550 4500
Text Notes 2300 4500 0    30   ~ 0
4mm OD
$Comp
L CONN_02X02 P1
U 1 1 57ECB26C
P 1600 1800
F 0 "P1" H 1600 1950 50  0000 C CNN
F 1 "Molex Minifit-JR 4.2mm" H 1600 1650 50  0000 C CNN
F 2 "Connectors_Molex:Molex_MiniFit-JR-5556-04A_2x02x4.20mm_Straight" H 1600 600 50  0001 C CNN
F 3 "" H 1600 600 50  0000 C CNN
	1    1600 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2100 1300 1750
Wire Wire Line
	1300 1750 1350 1750
Wire Wire Line
	1350 1850 1300 1850
Connection ~ 1300 1850
Text Notes 10575 7650 0    60   ~ 0
B
$EndSCHEMATC
