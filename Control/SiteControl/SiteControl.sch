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
Sheet 1 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 825  750  1525 925 
U 57A9B806
F0 "InverterControlAndIsolation" 60
F1 "InverterControlAndIsolation.sch" 60
$EndSheet
$Sheet
S 2550 750  1200 925 
U 57A9B809
F0 "MscPowerInput" 60
F1 "MscPowerInput.sch" 60
$EndSheet
$Sheet
S 3925 750  1225 925 
U 57A9B80E
F0 "PIC16MCU" 60
F1 "PIC16MCU.sch" 60
$EndSheet
$Sheet
S 5325 750  1075 925 
U 57A9B811
F0 "RS232-UART" 60
F1 "RS232-UART.sch" 60
$EndSheet
$Sheet
S 800  1975 1125 850 
U 57A9B814
F0 "ModemPower" 60
F1 "ModemPower.sch" 60
$EndSheet
$Sheet
S 2075 1975 1275 850 
U 57A9B817
F0 "RPiPowerControl" 60
F1 "RPiPowerControl.sch" 60
$EndSheet
$Sheet
S 3475 1975 1225 850 
U 57A9B81A
F0 "BattVoltageDetect" 60
F1 "BattVoltageDetect.sch" 60
$EndSheet
$Sheet
S 4825 1975 1025 850 
U 57EAC4BC
F0 "RTCModule" 60
F1 "RTCModule.sch" 60
$EndSheet
Text Notes 7175 6800 0    60   ~ 0
Applied Physics Club\nThe Pennsylvania State University
Text Notes 9100 7650 2    60   ~ 0
September 27, 2016
Text Notes 9075 7500 2    60   ~ 0
Telescope Base Station Control Board
Text Notes 10600 7650 0    60   ~ 0
B
Text Notes 7525 2525 0    60   ~ 0
Revision Notes:\n--- REV B ---\nB1. Replaced USB connector with Molex Minifit-JR 4.2mm 2x2 socket\nB2. Replaced DB9 connector with 10 pin IDC Header (polarized)\nB3. Replaced Main Pi header with 16 pin IDC Header (polarized)\nB4. Replaced 5V Buck Converter with new controller as per TI Webench\nB5. Removed the 5V Buck Converter relay in place of controller enable pin\nB6. Added RTC Module with backup battery\nB7. Added Tri-state buffer to the common RTC/ADC/MCU/PI SPI bus \n   to prevent bus collisions (disabling MCU access to RTC while Pi is\n   active.\nB8. Changed voltage divider and added voltage buffer / amplifier \n    before ADC to provide safer reading\nB9. Added VBAT Inrush Current Limiter, 4A Min-Blade Auto Fuse,\n      24VDC MOV, and reverse voltage shutoff PMOS Transistor\nB10. Added low current indicator LEDs.\nB11. Replaced 3V3 Buck Converter with more efficient, higher power version.\nB12. Moved MCU net pins around for better routing.\n--- REV C ---\nC1. Replaced reverse polarity PMOS gate voltage divider with\n      a resistor biased diode clamp. Previous version did not work.
$EndSCHEMATC
