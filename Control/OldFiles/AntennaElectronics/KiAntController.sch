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
LIBS:AntennaElectronics-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
Title ""
Date "27 jun 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 8PINPLUG P?
U 1 1 57A9A098
P 1600 1400
F 0 "P?" H 1500 2100 60  0000 C CNN
F 1 "8PINPLUG" H 1600 1350 60  0000 C CNN
F 2 "~" H 1600 1400 60  0000 C CNN
F 3 "~" H 1600 1400 60  0000 C CNN
	1    1600 1400
	0    -1   -1   0   
$EndComp
$Comp
L 8PINPLUG P?
U 1 1 57A9A099
P 2450 1400
F 0 "P?" H 2350 2100 60  0000 C CNN
F 1 "8PINPLUG" H 2450 1350 60  0000 C CNN
F 2 "~" H 2450 1400 60  0000 C CNN
F 3 "~" H 2450 1400 60  0000 C CNN
	1    2450 1400
	0    -1   -1   0   
$EndComp
$Comp
L 6PINCONN J?
U 1 1 57A9A09A
P 10300 2150
F 0 "J?" H 10300 3200 60  0000 C CNN
F 1 "6PINCONN" H 10300 2050 60  0000 C CNN
F 2 "~" H 10300 2150 60  0000 C CNN
F 3 "~" H 10300 2150 60  0000 C CNN
	1    10300 2150
	1    0    0    -1  
$EndComp
$Comp
L 6PINCONN J?
U 1 1 57A9A09B
P 9950 2150
F 0 "J?" H 9950 3200 60  0000 C CNN
F 1 "6PINCONN" H 9950 2050 60  0000 C CNN
F 2 "~" H 9950 2150 60  0000 C CNN
F 3 "~" H 9950 2150 60  0000 C CNN
	1    9950 2150
	-1   0    0    -1  
$EndComp
Text HLabel 1050 950  1    60   Input ~ 0
W1
Text HLabel 1200 950  1    60   Input ~ 0
W2
Text HLabel 1350 950  1    60   Input ~ 0
W3
Text HLabel 1500 950  1    60   Input ~ 0
W4
Text HLabel 1500 1900 3    60   Input ~ 0
W5
Text HLabel 1350 1900 3    60   Input ~ 0
W6
Text HLabel 1200 1900 3    60   Input ~ 0
W7
Text HLabel 1050 1900 3    60   Input ~ 0
W8
Wire Wire Line
	1050 1900 1050 1800
Wire Wire Line
	1200 1800 1200 1900
Wire Wire Line
	1350 1900 1350 1800
Wire Wire Line
	1500 1800 1500 1900
Wire Wire Line
	1500 950  1500 1000
Wire Wire Line
	1350 950  1350 1000
Wire Wire Line
	1200 950  1200 1000
Wire Wire Line
	1050 950  1050 1000
Text HLabel 10700 1300 2    60   Input ~ 0
M1
Text HLabel 10700 1450 2    60   Input ~ 0
M2
Text HLabel 10700 1600 2    60   Input ~ 0
M3
Text HLabel 10700 1750 2    60   Input ~ 0
M4
Text HLabel 10700 1900 2    60   Input ~ 0
M5
Text HLabel 10700 2050 2    60   Input ~ 0
M6
Wire Wire Line
	10600 1300 10700 1300
Wire Wire Line
	10700 1450 10600 1450
Wire Wire Line
	10700 1600 10600 1600
Wire Wire Line
	10700 1750 10600 1750
Wire Wire Line
	10700 1900 10600 1900
Wire Wire Line
	10700 2050 10600 2050
Wire Notes Line
	900  7400 900  7300
Wire Notes Line
	900  7300 750  7450
Wire Notes Line
	750  7450 900  7600
Wire Notes Line
	900  7600 900  7500
Wire Notes Line
	900  7500 1000 7500
Wire Notes Line
	1000 7500 1000 7600
Wire Notes Line
	1000 7600 1150 7450
Wire Notes Line
	1150 7450 1000 7300
Wire Notes Line
	1000 7300 1000 7400
Wire Notes Line
	1000 7400 900  7400
Wire Notes Line
	1650 1350 1650 1250
Wire Notes Line
	1650 1250 1500 1400
Wire Notes Line
	1500 1400 1650 1550
Wire Notes Line
	1650 1550 1650 1450
Wire Notes Line
	1650 1450 1750 1450
Wire Notes Line
	1750 1450 1750 1550
Wire Notes Line
	1750 1550 1900 1400
Wire Notes Line
	1900 1400 1750 1250
Wire Notes Line
	1750 1250 1750 1350
Wire Notes Line
	1750 1350 1650 1350
Wire Notes Line
	10100 1600 10100 1500
Wire Notes Line
	10100 1500 9950 1650
Wire Notes Line
	9950 1650 10100 1800
Wire Notes Line
	10100 1800 10100 1700
Wire Notes Line
	10100 1700 10200 1700
Wire Notes Line
	10200 1700 10200 1800
Wire Notes Line
	10200 1800 10350 1650
Wire Notes Line
	10350 1650 10200 1500
Wire Notes Line
	10200 1500 10200 1600
Wire Notes Line
	10200 1600 10100 1600
$EndSCHEMATC
