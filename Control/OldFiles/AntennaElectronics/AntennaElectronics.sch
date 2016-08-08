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
Sheet 1 4
Title "noname.sch"
Date "27 jun 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 600  600  550  800 
U 57A973ED
F0 "Ki_Pre-Amp" 50
F1 "Ki_Pre-Amp.sch" 50
F2 "W1" I R 1150 650 60 
F3 "W2" I R 1150 750 60 
F4 "W3" I R 1150 850 60 
F5 "W4" I R 1150 950 60 
F6 "W8" I R 1150 1350 60 
F7 "W7" I R 1150 1250 60 
F8 "W6" I R 1150 1150 60 
F9 "W5" I R 1150 1050 60 
$EndSheet
Text Notes 550  1600 0    60   ~ 0
Pre-Amplifier Block
Text Notes 600  700  0    60   ~ 0
P-\nP+\nNC\nGND\n+5 Vcc\nVsense\nFAN+\nFAN-
$Sheet
S 2050 600  900  900 
U 57A973EE
F0 "KiAntController" 50
F1 "KiAntController.sch" 50
F2 "W1" I L 2050 650 60 
F3 "W2" I L 2050 750 60 
F4 "W3" I L 2050 850 60 
F5 "W4" I L 2050 950 60 
F6 "W5" I L 2050 1050 60 
F7 "W6" I L 2050 1150 60 
F8 "W7" I L 2050 1250 60 
F9 "W8" I L 2050 1350 60 
F10 "M1" I R 2950 650 60 
F11 "M2" I R 2950 750 60 
F12 "M3" I R 2950 850 60 
F13 "M4" I R 2950 950 60 
F14 "M5" I R 2950 1050 60 
F15 "M6" I R 2950 1150 60 
$EndSheet
Wire Wire Line
	2050 650  1150 650 
Wire Wire Line
	1150 750  2050 750 
Wire Wire Line
	2050 850  1150 850 
Wire Wire Line
	1150 950  2050 950 
Wire Wire Line
	2050 1050 1150 1050
Wire Wire Line
	1150 1150 2050 1150
Wire Wire Line
	2050 1250 1150 1250
Wire Wire Line
	1150 1350 2050 1350
$Sheet
S 3400 600  1050 900 
U 57A973EF
F0 "Ki_MotorControl" 50
F1 "Ki_MotorController.sch" 50
F2 "M1" I L 3400 650 60 
F3 "M2" I L 3400 750 60 
F4 "M3" I L 3400 850 60 
F5 "M4" I L 3400 950 60 
F6 "M5" I L 3400 1050 60 
F7 "M6" I L 3400 1150 60 
$EndSheet
Wire Wire Line
	2950 650  3400 650 
Wire Wire Line
	3400 750  2950 750 
Wire Wire Line
	2950 850  3400 850 
Wire Wire Line
	3400 950  2950 950 
Wire Wire Line
	2950 1050 3400 1050
Wire Wire Line
	3400 1150 2950 1150
$EndSCHEMATC
