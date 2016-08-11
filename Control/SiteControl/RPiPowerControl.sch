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
Sheet 7 8
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
L USB_A J7
U 1 1 57ABFDB4
P 1700 1950
F 0 "J7" H 1900 1750 50  0000 C CNN
F 1 "USB_A" H 1650 2150 50  0000 C CNN
F 2 "Connect:USB_A" V 1650 1850 50  0001 C CNN
F 3 "" V 1650 1850 50  0000 C CNN
	1    1700 1950
	0    -1   1    0   
$EndComp
NoConn ~ 2000 1850
NoConn ~ 2000 1950
$Comp
L GND #PWR063
U 1 1 57ABFEE2
P 1750 2350
F 0 "#PWR063" H 1750 2100 50  0001 C CNN
F 1 "GND" H 1750 2200 50  0000 C CNN
F 2 "" H 1750 2350 50  0000 C CNN
F 3 "" H 1750 2350 50  0000 C CNN
	1    1750 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2250 1600 2300
Wire Wire Line
	1600 2300 2050 2300
Wire Wire Line
	1750 2300 1750 2350
Wire Wire Line
	2000 2050 2050 2050
Wire Wire Line
	2050 2050 2050 2300
Connection ~ 1750 2300
Wire Wire Line
	2000 1750 3100 1750
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
Wire Wire Line
	3050 1850 3100 1850
Wire Wire Line
	3050 1550 3050 1850
Wire Wire Line
	3050 1650 3100 1650
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
Wire Wire Line
	3700 1650 4250 1650
Wire Wire Line
	4150 1850 4150 1650
Connection ~ 4150 1650
Wire Wire Line
	3700 1850 3950 1850
$Comp
L GND #PWR064
U 1 1 57AC1F73
P 4050 2150
F 0 "#PWR064" H 4050 1900 50  0001 C CNN
F 1 "GND" H 4050 2000 50  0000 C CNN
F 2 "" H 4050 2150 50  0000 C CNN
F 3 "" H 4050 2150 50  0000 C CNN
	1    4050 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2150 4150 2150
Connection ~ 4050 2150
$Comp
L +5V #PWR065
U 1 1 57AC243A
P 3050 1550
F 0 "#PWR065" H 3050 1400 50  0001 C CNN
F 1 "+5V" H 3050 1690 50  0000 C CNN
F 2 "" H 3050 1550 50  0000 C CNN
F 3 "" H 3050 1550 50  0000 C CNN
	1    3050 1550
	1    0    0    -1  
$EndComp
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
Text Notes 1450 1350 0    60   ~ 0
Solid-State Switch and Connector for Pi
$Comp
L MC34063 U9
U 1 1 57AD6FE6
P 4100 4350
F 0 "U9" H 3900 4550 50  0000 C CNN
F 1 "MC34063" H 4100 4550 50  0000 L CNN
F 2 "DigitalLogic:MC34063" H 4100 4450 50  0001 C CIN
F 3 "" H 4100 4350 50  0000 C CNN
	1    4100 4350
	1    0    0    -1  
$EndComp
$Comp
L CP1 C17
U 1 1 57AD710D
P 3400 4450
F 0 "C17" H 3425 4550 50  0000 L CNN
F 1 "680uF" H 3425 4350 50  0000 L CNN
F 2 "DigitalLogic:c_elec_13x13" H 3400 4450 50  0001 C CNN
F 3 "" H 3400 4450 50  0000 C CNN
F 4 "35TLV680M12.5X13.5" H 3250 3750 60  0000 C CNN "Model"
	1    3400 4450
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 57AD7172
P 5150 4450
F 0 "R26" V 5230 4450 50  0000 C CNN
F 1 "10R" V 5150 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5080 4450 50  0001 C CNN
F 3 "" H 5150 4450 50  0000 C CNN
	1    5150 4450
	1    0    0    -1  
$EndComp
$Comp
L Q_PJFET_GSD Q2
U 1 1 57AD71D9
P 5450 4300
F 0 "Q2" H 5750 4350 50  0000 R CNN
F 1 "Q_PJFET_GSD" H 6100 4250 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:TO-252-2Lead" H 5650 4400 50  0001 C CNN
F 3 "" H 5450 4300 50  0000 C CNN
F 4 "FQD13N10LTM" H 5900 4550 60  0000 C CNN "Model"
	1    5450 4300
	1    0    0    -1  
$EndComp
$Comp
L L_Small L1
U 1 1 57AD727F
P 5800 4550
F 0 "L1" V 5850 4600 50  0000 L CNN
F 1 "100uH" V 5850 4250 50  0000 L CNN
F 2 "DigitalLogic:SRP1770TA-101M" H 5800 4550 50  0001 C CNN
F 3 "" H 5800 4550 50  0000 C CNN
F 4 "SRP1770TA-101M" V 6100 4050 60  0000 C CNN "Model"
	1    5800 4550
	0    -1   -1   0   
$EndComp
$Comp
L D_Schottky_Small D1
U 1 1 57AD72EC
P 5550 4650
F 0 "D1" H 5500 4730 50  0000 L CNN
F 1 "~" H 5270 4570 50  0001 L CNN
F 2 "Diodes_SMD:DO-214AB" V 5550 4650 50  0001 C CNN
F 3 "" V 5550 4650 50  0000 C CNN
F 4 "VSSC8L45-M3/9T" V 6050 4200 60  0000 C CNN "Model"
	1    5550 4650
	0    1    1    0   
$EndComp
$Comp
L C C18
U 1 1 57AD7512
P 4650 4700
F 0 "C18" H 4675 4800 50  0000 L CNN
F 1 "1nF" H 4675 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4688 4550 50  0001 C CNN
F 3 "" H 4650 4700 50  0000 C CNN
	1    4650 4700
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 57AD75BD
P 5150 4150
F 0 "R25" V 5230 4150 50  0000 C CNN
F 1 "560R" V 5150 4150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5080 4150 50  0001 C CNN
F 3 "" H 5150 4150 50  0000 C CNN
	1    5150 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4300 5250 4300
Connection ~ 5150 4300
$Comp
L R R27
U 1 1 57AD7AF2
P 5550 3850
F 0 "R27" V 5630 3850 50  0000 C CNN
F 1 "R18" V 5550 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 5480 3850 50  0001 C CNN
F 3 "" H 5550 3850 50  0000 C CNN
	1    5550 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4000 5550 4100
Wire Wire Line
	3650 4000 5550 4000
Connection ~ 5550 4000
Wire Wire Line
	2700 3950 2750 3950
Wire Wire Line
	3700 4500 3600 4500
Wire Wire Line
	3600 4500 3600 3700
Wire Wire Line
	3700 4400 3650 4400
Wire Wire Line
	3650 4400 3650 4000
Wire Wire Line
	5150 4000 5150 4000
Wire Wire Line
	4500 4300 4950 4300
Wire Wire Line
	4950 4100 4950 4600
Wire Wire Line
	4950 4600 5150 4600
Wire Wire Line
	3700 4300 3700 4100
Wire Wire Line
	3700 4100 4950 4100
Connection ~ 4950 4300
$Comp
L GND #PWR066
U 1 1 57AD7E35
P 4050 5000
F 0 "#PWR066" H 4050 4750 50  0001 C CNN
F 1 "GND" H 4050 4850 50  0000 C CNN
F 2 "" H 4050 5000 50  0000 C CNN
F 3 "" H 4050 5000 50  0000 C CNN
	1    4050 5000
	1    0    0    -1  
$EndComp
Connection ~ 3600 3700
Wire Wire Line
	3400 4600 3400 5000
Wire Wire Line
	3050 5000 7000 5000
Wire Wire Line
	4500 4400 4850 4400
Wire Wire Line
	4850 4400 4850 5000
Connection ~ 4050 5000
Wire Wire Line
	4500 5000 4500 4600
Connection ~ 4500 5000
Wire Wire Line
	4650 4550 4650 4500
Wire Wire Line
	4650 4500 4500 4500
Connection ~ 4850 5000
Wire Wire Line
	5550 4550 5550 4500
Wire Wire Line
	5550 4550 5700 4550
Wire Wire Line
	5550 5000 5550 4750
Connection ~ 5550 4550
$Comp
L CP1 C19
U 1 1 57AD85E4
P 6050 4750
F 0 "C19" H 6075 4850 50  0000 L CNN
F 1 "1000uF" H 6075 4650 50  0000 L CNN
F 2 "DigitalLogic:c_elec_13x13" H 6050 4750 50  0001 C CNN
F 3 "" H 6050 4750 50  0000 C CNN
F 4 "25SEV1000M12.5X16" H 6100 4350 60  0000 C CNN "Model"
	1    6050 4750
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 57AD8904
P 6500 4850
F 0 "R29" V 6580 4850 50  0000 C CNN
F 1 "2K2" V 6500 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6430 4850 50  0001 C CNN
F 3 "" H 6500 4850 50  0000 C CNN
	1    6500 4850
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 57AD8972
P 6500 4450
F 0 "R28" V 6580 4450 50  0000 C CNN
F 1 "6K8" V 6500 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6430 4450 50  0001 C CNN
F 3 "" H 6500 4450 50  0000 C CNN
	1    6500 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4550 6150 4550
Wire Wire Line
	6050 4550 6050 4600
Wire Wire Line
	6150 4550 6150 4300
Wire Wire Line
	6150 4300 7000 4300
Connection ~ 6050 4550
Wire Wire Line
	6500 4600 6500 4700
Connection ~ 5550 5000
Wire Wire Line
	6050 4900 6050 5000
Connection ~ 6050 5000
Wire Wire Line
	6500 4650 6400 4650
Wire Wire Line
	6400 4650 6400 4900
Wire Wire Line
	3600 4900 3600 4600
Wire Wire Line
	3600 4600 3700 4600
Connection ~ 6500 4650
$Comp
L +BATT #PWR067
U 1 1 57AD9368
P 2750 3650
F 0 "#PWR067" H 2750 3500 50  0001 C CNN
F 1 "+BATT" H 2750 3790 50  0000 C CNN
F 2 "" H 2750 3650 50  0000 C CNN
F 3 "" H 2750 3650 50  0000 C CNN
	1    2750 3650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR068
U 1 1 57AD9437
P 7000 4150
F 0 "#PWR068" H 7000 4000 50  0001 C CNN
F 1 "+5V" H 7000 4290 50  0000 C CNN
F 2 "" H 7000 4150 50  0000 C CNN
F 3 "" H 7000 4150 50  0000 C CNN
	1    7000 4150
	1    0    0    -1  
$EndComp
Connection ~ 3400 3700
$Comp
L C C20
U 1 1 57ADA01E
P 6700 4700
F 0 "C20" H 6725 4800 50  0000 L CNN
F 1 "0.47uF" H 6725 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6738 4550 50  0001 C CNN
F 3 "" H 6700 4700 50  0000 C CNN
	1    6700 4700
	1    0    0    -1  
$EndComp
$Comp
L C C21
U 1 1 57ADA0B2
P 7000 4700
F 0 "C21" H 7025 4800 50  0000 L CNN
F 1 "0.1uF" H 7025 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7038 4550 50  0001 C CNN
F 3 "" H 7000 4700 50  0000 C CNN
	1    7000 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4150 7000 4550
Connection ~ 6500 4300
Wire Wire Line
	6700 4550 6700 4300
Connection ~ 6700 4300
Wire Wire Line
	6700 5000 6700 4850
Connection ~ 6500 5000
Wire Wire Line
	7000 5000 7000 4850
Connection ~ 6700 5000
$Comp
L C C16
U 1 1 57ADA6A3
P 3050 4450
F 0 "C16" H 3075 4550 50  0000 L CNN
F 1 "0.47uF/50V" H 2600 4350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3088 4300 50  0001 C CNN
F 3 "" H 3050 4450 50  0000 C CNN
	1    3050 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4600 3050 5000
Connection ~ 3400 5000
Connection ~ 7000 4300
Connection ~ 3050 3700
Wire Wire Line
	3400 3700 3400 4300
Wire Wire Line
	6400 4900 3600 4900
Wire Wire Line
	4650 4850 4650 5000
Connection ~ 4650 5000
Connection ~ 5150 4000
Text Notes 3950 3450 0    60   ~ 0
5V Buck Converter Supply [ 62 KHz ]
$Comp
L SS_Relay_VO14642AT U10
U 1 1 57AEB2BF
P 2400 4050
F 0 "U10" H 2200 4250 50  0000 L CNN
F 1 "SS_Relay_VO14642AT" H 2200 3850 50  0000 L CNN
F 2 "DigitalLogic:SS_Relay_VO14642AT" H 2200 3850 50  0001 L CIN
F 3 "" H 2350 4050 50  0000 L CNN
	1    2400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4150 2700 4150
Wire Wire Line
	2750 3650 2750 4150
$Comp
L R R31
U 1 1 57AEB2C8
P 2050 4300
F 0 "R31" V 2130 4300 50  0000 C CNN
F 1 "450R" V 2050 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1980 4300 50  0001 C CNN
F 3 "" H 2050 4300 50  0000 C CNN
	1    2050 4300
	1    0    0    1   
$EndComp
Text GLabel 1750 3950 0    60   Input ~ 0
RPi_5v_En
$Comp
L R R30
U 1 1 57AEB2CF
P 1850 4300
F 0 "R30" V 1930 4300 50  0000 C CNN
F 1 "10K" V 1850 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1780 4300 50  0001 C CNN
F 3 "" H 1850 4300 50  0000 C CNN
	1    1850 4300
	1    0    0    1   
$EndComp
Wire Wire Line
	1750 3950 2100 3950
Wire Wire Line
	1850 4150 1850 3950
Connection ~ 1850 3950
Wire Wire Line
	2100 4150 2050 4150
$Comp
L GND #PWR069
U 1 1 57AEB2D9
P 1950 4450
F 0 "#PWR069" H 1950 4200 50  0001 C CNN
F 1 "GND" H 1950 4300 50  0000 C CNN
F 2 "" H 1950 4450 50  0000 C CNN
F 3 "" H 1950 4450 50  0000 C CNN
	1    1950 4450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1850 4450 2050 4450
Connection ~ 1950 4450
Connection ~ 2750 3950
Wire Wire Line
	3050 4300 3050 3700
Wire Wire Line
	2700 4050 2950 4050
Wire Wire Line
	2950 3700 5550 3700
Wire Wire Line
	2950 4050 2950 3700
Wire Notes Line
	950  5300 7300 5300
Wire Notes Line
	7300 5300 7300 3300
Wire Notes Line
	7300 3300 950  3300
Wire Notes Line
	950  3300 950  5300
Wire Notes Line
	3300 4450 3250 4450
Wire Notes Line
	3250 4450 3250 5050
Wire Notes Line
	5100 5050 5100 4650
Wire Notes Line
	5100 4650 5500 4650
Wire Notes Line
	5800 5100 5800 4750
Wire Notes Line
	5800 4750 5900 4750
Wire Notes Line
	5850 4250 5800 4250
Wire Notes Line
	5800 4250 5800 4450
Wire Notes Line
	5850 4100 5850 4200
Wire Notes Line
	5850 4200 5650 4200
Text Notes 7150 6800 0    60   ~ 0
Applied Physics Club\nThe Pennsylvania State University
Text Notes 9000 7650 2    60   ~ 0
August 11, 2016
Text Notes 9050 7500 2    60   ~ 0
Telescope Base Station Control Board
Text Notes 1150 7000 0    60   ~ 0
NOTES: This power supply should supply up to 1.8 A @ 5 VDC. The \nRaspberry Pi B+ only consumes 350 mA under heavy load, however, \nthe Raspberry Pi 3 consumes 1.2 A under heavy load. Allowing for up to \n1.8 A supply allows for a future move to a Raspberry Pi 3 without replacing \nthis circuit.\n\nThe buck converter circuit was taken from\n http://forum.allaboutcircuits.com/threads/12v-to-5v-dc-high-efficiency-smps-buck-converter-using-34063-ic.78805/\n\nThere are two relay switches placed in this circuit, one controls the activation \nof the buck converter (it will still dissipate power even under no load), and \none for the Pi itself. The former can be used to conserve battery power, and \nallow for the buck converter to equalize a stable voltage before connecting \nthe Pi. The latter allows for the Pi to be turned off when not needed, and to \nbe hard power cycled.
$EndSCHEMATC
