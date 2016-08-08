-- Copyright (C) 1991-2014 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 14.1.0 Build 186 12/03/2014 SJ Web Edition"

-- DATE "10/11/2015 00:15:54"

-- 
-- Device: Altera 5M160ZT100C5 Package TQFP100
-- 

-- 
-- This VHDL file should be used for ModelSim (VHDL) only
-- 

LIBRARY IEEE;
LIBRARY MAXV;
USE IEEE.STD_LOGIC_1164.ALL;
USE MAXV.MAXV_COMPONENTS.ALL;

ENTITY 	IntegratorCLPD IS
    PORT (
	clrReg : IN std_logic;
	flgIn : IN std_logic_vector(5 DOWNTO 0);
	flgOut : BUFFER std_logic_vector(5 DOWNTO 0);
	pulse : IN std_logic;
	latch : IN std_logic;
	dataIn : IN std_logic;
	output : BUFFER std_logic;
	loaded : BUFFER std_logic;
	fvcIn : IN std_logic;
	wordSelect : IN std_logic;
	dataOut : BUFFER std_logic_vector(15 DOWNTO 0)
	);
END IntegratorCLPD;

-- Design Ports Information
-- flgOut[0]	=>  Location: PIN_33,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- flgOut[1]	=>  Location: PIN_30,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- flgOut[2]	=>  Location: PIN_29,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- flgOut[3]	=>  Location: PIN_28,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- flgOut[4]	=>  Location: PIN_27,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- flgOut[5]	=>  Location: PIN_26,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- output	=>  Location: PIN_49,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- loaded	=>  Location: PIN_50,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[0]	=>  Location: PIN_74,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[1]	=>  Location: PIN_73,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[2]	=>  Location: PIN_72,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[3]	=>  Location: PIN_71,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[4]	=>  Location: PIN_70,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[5]	=>  Location: PIN_69,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[6]	=>  Location: PIN_68,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[7]	=>  Location: PIN_67,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[8]	=>  Location: PIN_66,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[9]	=>  Location: PIN_64,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[10]	=>  Location: PIN_61,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[11]	=>  Location: PIN_58,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[12]	=>  Location: PIN_57,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[13]	=>  Location: PIN_56,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[14]	=>  Location: PIN_55,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- dataOut[15]	=>  Location: PIN_54,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- wordSelect	=>  Location: PIN_51,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- flgIn[0]	=>  Location: PIN_100,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- clrReg	=>  Location: PIN_34,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- pulse	=>  Location: PIN_12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- flgIn[1]	=>  Location: PIN_99,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- flgIn[2]	=>  Location: PIN_98,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- flgIn[3]	=>  Location: PIN_97,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- flgIn[4]	=>  Location: PIN_96,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- flgIn[5]	=>  Location: PIN_95,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- latch	=>  Location: PIN_62,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- dataIn	=>  Location: PIN_52,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- fvcIn	=>  Location: PIN_14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF IntegratorCLPD IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clrReg : std_logic;
SIGNAL ww_flgIn : std_logic_vector(5 DOWNTO 0);
SIGNAL ww_flgOut : std_logic_vector(5 DOWNTO 0);
SIGNAL ww_pulse : std_logic;
SIGNAL ww_latch : std_logic;
SIGNAL ww_dataIn : std_logic;
SIGNAL ww_output : std_logic;
SIGNAL ww_loaded : std_logic;
SIGNAL ww_fvcIn : std_logic;
SIGNAL ww_wordSelect : std_logic;
SIGNAL ww_dataOut : std_logic_vector(15 DOWNTO 0);
SIGNAL \pulse~combout\ : std_logic;
SIGNAL \clrReg~combout\ : std_logic;
SIGNAL \latch~combout\ : std_logic;
SIGNAL \rst~combout\ : std_logic;
SIGNAL \cycleCounter|count[1]~1\ : std_logic;
SIGNAL \cycleCounter|count[1]~1COUT1_89\ : std_logic;
SIGNAL \cycleCounter|count[2]~5\ : std_logic;
SIGNAL \cycleCounter|count[2]~5COUT1_91\ : std_logic;
SIGNAL \cycleCounter|count[3]~3\ : std_logic;
SIGNAL \cycleCounter|count[3]~3COUT1_93\ : std_logic;
SIGNAL \cycleCounter|count[4]~9\ : std_logic;
SIGNAL \cycleCounter|count[4]~9COUT1_95\ : std_logic;
SIGNAL \cycleCounter|count[5]~7\ : std_logic;
SIGNAL \cycleCounter|count[6]~13\ : std_logic;
SIGNAL \cycleCounter|count[6]~13COUT1_97\ : std_logic;
SIGNAL \cycleCounter|count[7]~11\ : std_logic;
SIGNAL \cycleCounter|count[7]~11COUT1_99\ : std_logic;
SIGNAL \cycleCounter|count[8]~17\ : std_logic;
SIGNAL \cycleCounter|count[8]~17COUT1_101\ : std_logic;
SIGNAL \cycleCounter|count[9]~15\ : std_logic;
SIGNAL \cycleCounter|count[9]~15COUT1_103\ : std_logic;
SIGNAL \cycleCounter|count[10]~21\ : std_logic;
SIGNAL \cycleCounter|count[11]~19\ : std_logic;
SIGNAL \cycleCounter|count[11]~19COUT1_105\ : std_logic;
SIGNAL \cycleCounter|count[12]~25\ : std_logic;
SIGNAL \cycleCounter|count[12]~25COUT1_107\ : std_logic;
SIGNAL \dataIn~combout\ : std_logic;
SIGNAL \Equal1~7\ : std_logic;
SIGNAL \cycleCounter|count[13]~23\ : std_logic;
SIGNAL \cycleCounter|count[13]~23COUT1_109\ : std_logic;
SIGNAL \cycleCounter|count[14]~29\ : std_logic;
SIGNAL \cycleCounter|count[14]~29COUT1_111\ : std_logic;
SIGNAL \Equal1~8\ : std_logic;
SIGNAL \Equal1~5\ : std_logic;
SIGNAL \Equal1~6\ : std_logic;
SIGNAL \Equal1~9_combout\ : std_logic;
SIGNAL \cycleCounter|count[15]~27\ : std_logic;
SIGNAL \cycleCounter|count[16]~33\ : std_logic;
SIGNAL \cycleCounter|count[16]~33COUT1_113\ : std_logic;
SIGNAL \cycleCounter|count[17]~31\ : std_logic;
SIGNAL \cycleCounter|count[17]~31COUT1_115\ : std_logic;
SIGNAL \cycleCounter|count[18]~37\ : std_logic;
SIGNAL \cycleCounter|count[18]~37COUT1_117\ : std_logic;
SIGNAL \cycleCounter|count[19]~35\ : std_logic;
SIGNAL \cycleCounter|count[19]~35COUT1_119\ : std_logic;
SIGNAL \cycleCounter|count[20]~41\ : std_logic;
SIGNAL \cycleCounter|count[21]~39\ : std_logic;
SIGNAL \cycleCounter|count[21]~39COUT1_121\ : std_logic;
SIGNAL \cycleCounter|count[22]~45\ : std_logic;
SIGNAL \cycleCounter|count[22]~45COUT1_123\ : std_logic;
SIGNAL \cycleCounter|count[23]~43\ : std_logic;
SIGNAL \cycleCounter|count[23]~43COUT1_125\ : std_logic;
SIGNAL \cycleCounter|count[24]~49\ : std_logic;
SIGNAL \cycleCounter|count[24]~49COUT1_127\ : std_logic;
SIGNAL \cycleCounter|count[25]~47\ : std_logic;
SIGNAL \cycleCounter|count[26]~53\ : std_logic;
SIGNAL \cycleCounter|count[26]~53COUT1_129\ : std_logic;
SIGNAL \cycleCounter|count[27]~51\ : std_logic;
SIGNAL \cycleCounter|count[27]~51COUT1_131\ : std_logic;
SIGNAL \cycleCounter|count[28]~57\ : std_logic;
SIGNAL \cycleCounter|count[28]~57COUT1_133\ : std_logic;
SIGNAL \Equal1~17\ : std_logic;
SIGNAL \cycleCounter|count[29]~55\ : std_logic;
SIGNAL \cycleCounter|count[29]~55COUT1_135\ : std_logic;
SIGNAL \cycleCounter|count[30]~61\ : std_logic;
SIGNAL \Equal1~18\ : std_logic;
SIGNAL \Equal1~15\ : std_logic;
SIGNAL \Equal1~16\ : std_logic;
SIGNAL \Equal1~19_combout\ : std_logic;
SIGNAL \Equal1~12\ : std_logic;
SIGNAL \Equal1~13\ : std_logic;
SIGNAL \Equal1~11\ : std_logic;
SIGNAL \Equal1~10\ : std_logic;
SIGNAL \Equal1~14_combout\ : std_logic;
SIGNAL \Equal1~2\ : std_logic;
SIGNAL \Equal1~0\ : std_logic;
SIGNAL \Equal1~3\ : std_logic;
SIGNAL \Equal1~1\ : std_logic;
SIGNAL \Equal1~4_combout\ : std_logic;
SIGNAL \eq~regout\ : std_logic;
SIGNAL \shiftCounter|count[1]~3\ : std_logic;
SIGNAL \shiftCounter|count[1]~3COUT1_14\ : std_logic;
SIGNAL \shiftCounter|count[2]~5\ : std_logic;
SIGNAL \shiftCounter|count[2]~5COUT1_16\ : std_logic;
SIGNAL \shiftCounter|count[3]~7\ : std_logic;
SIGNAL \shiftCounter|count[3]~7COUT1_18\ : std_logic;
SIGNAL \Equal0~0_combout\ : std_logic;
SIGNAL \Equal0~1_combout\ : std_logic;
SIGNAL \wordSelect~combout\ : std_logic;
SIGNAL \fvcIn~combout\ : std_logic;
SIGNAL \fvcCounter|count[1]~5\ : std_logic;
SIGNAL \fvcCounter|count[1]~5COUT1_89\ : std_logic;
SIGNAL \fvcCounter|count[2]~9\ : std_logic;
SIGNAL \fvcCounter|count[2]~9COUT1_91\ : std_logic;
SIGNAL \fvcCounter|count[3]~13\ : std_logic;
SIGNAL \fvcCounter|count[3]~13COUT1_93\ : std_logic;
SIGNAL \fvcCounter|count[4]~17\ : std_logic;
SIGNAL \fvcCounter|count[4]~17COUT1_95\ : std_logic;
SIGNAL \fvcCounter|count[5]~21\ : std_logic;
SIGNAL \fvcCounter|count[6]~25\ : std_logic;
SIGNAL \fvcCounter|count[6]~25COUT1_97\ : std_logic;
SIGNAL \fvcCounter|count[7]~29\ : std_logic;
SIGNAL \fvcCounter|count[7]~29COUT1_99\ : std_logic;
SIGNAL \fvcCounter|count[8]~33\ : std_logic;
SIGNAL \fvcCounter|count[8]~33COUT1_101\ : std_logic;
SIGNAL \fvcCounter|count[9]~37\ : std_logic;
SIGNAL \fvcCounter|count[9]~37COUT1_103\ : std_logic;
SIGNAL \fvcCounter|count[10]~41\ : std_logic;
SIGNAL \fvcCounter|count[11]~45\ : std_logic;
SIGNAL \fvcCounter|count[11]~45COUT1_105\ : std_logic;
SIGNAL \fvcCounter|count[12]~49\ : std_logic;
SIGNAL \fvcCounter|count[12]~49COUT1_107\ : std_logic;
SIGNAL \fvcCounter|count[13]~53\ : std_logic;
SIGNAL \fvcCounter|count[13]~53COUT1_109\ : std_logic;
SIGNAL \fvcCounter|count[14]~57\ : std_logic;
SIGNAL \fvcCounter|count[14]~57COUT1_111\ : std_logic;
SIGNAL \fvcCounter|count[15]~61\ : std_logic;
SIGNAL \wordMux|outVal[0]~0\ : std_logic;
SIGNAL \fvcCounter|count[16]~1\ : std_logic;
SIGNAL \fvcCounter|count[16]~1COUT1_113\ : std_logic;
SIGNAL \wordMux|outVal[1]~1\ : std_logic;
SIGNAL \fvcCounter|count[17]~3\ : std_logic;
SIGNAL \fvcCounter|count[17]~3COUT1_115\ : std_logic;
SIGNAL \wordMux|outVal[2]~2\ : std_logic;
SIGNAL \fvcCounter|count[18]~7\ : std_logic;
SIGNAL \fvcCounter|count[18]~7COUT1_117\ : std_logic;
SIGNAL \wordMux|outVal[3]~3\ : std_logic;
SIGNAL \fvcCounter|count[19]~11\ : std_logic;
SIGNAL \fvcCounter|count[19]~11COUT1_119\ : std_logic;
SIGNAL \wordMux|outVal[4]~4\ : std_logic;
SIGNAL \fvcCounter|count[20]~15\ : std_logic;
SIGNAL \wordMux|outVal[5]~5\ : std_logic;
SIGNAL \fvcCounter|count[21]~19\ : std_logic;
SIGNAL \fvcCounter|count[21]~19COUT1_121\ : std_logic;
SIGNAL \wordMux|outVal[6]~6\ : std_logic;
SIGNAL \fvcCounter|count[22]~23\ : std_logic;
SIGNAL \fvcCounter|count[22]~23COUT1_123\ : std_logic;
SIGNAL \wordMux|outVal[7]~7\ : std_logic;
SIGNAL \fvcCounter|count[23]~27\ : std_logic;
SIGNAL \fvcCounter|count[23]~27COUT1_125\ : std_logic;
SIGNAL \wordMux|outVal[8]~8\ : std_logic;
SIGNAL \fvcCounter|count[24]~31\ : std_logic;
SIGNAL \fvcCounter|count[24]~31COUT1_127\ : std_logic;
SIGNAL \wordMux|outVal[9]~9\ : std_logic;
SIGNAL \fvcCounter|count[25]~35\ : std_logic;
SIGNAL \wordMux|outVal[10]~10\ : std_logic;
SIGNAL \fvcCounter|count[26]~39\ : std_logic;
SIGNAL \fvcCounter|count[26]~39COUT1_129\ : std_logic;
SIGNAL \wordMux|outVal[11]~11\ : std_logic;
SIGNAL \fvcCounter|count[27]~43\ : std_logic;
SIGNAL \fvcCounter|count[27]~43COUT1_131\ : std_logic;
SIGNAL \wordMux|outVal[12]~12\ : std_logic;
SIGNAL \fvcCounter|count[28]~47\ : std_logic;
SIGNAL \fvcCounter|count[28]~47COUT1_133\ : std_logic;
SIGNAL \wordMux|outVal[13]~13\ : std_logic;
SIGNAL \fvcCounter|count[29]~51\ : std_logic;
SIGNAL \fvcCounter|count[29]~51COUT1_135\ : std_logic;
SIGNAL \wordMux|outVal[14]~14\ : std_logic;
SIGNAL \fvcCounter|count[30]~55\ : std_logic;
SIGNAL \wordMux|outVal[15]~15\ : std_logic;
SIGNAL \flgs|reg\ : std_logic_vector(5 DOWNTO 0);
SIGNAL \fvcCounter|count\ : std_logic_vector(31 DOWNTO 0);
SIGNAL \shiftCounter|count\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \shiftReg|reg\ : std_logic_vector(31 DOWNTO 0);
SIGNAL fvcCountReg : std_logic_vector(31 DOWNTO 0);
SIGNAL \flgIn~combout\ : std_logic_vector(5 DOWNTO 0);
SIGNAL \cycleCounter|count\ : std_logic_vector(31 DOWNTO 0);

BEGIN

ww_clrReg <= clrReg;
ww_flgIn <= flgIn;
flgOut <= ww_flgOut;
ww_pulse <= pulse;
ww_latch <= latch;
ww_dataIn <= dataIn;
output <= ww_output;
loaded <= ww_loaded;
ww_fvcIn <= fvcIn;
ww_wordSelect <= wordSelect;
dataOut <= ww_dataOut;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: PIN_12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\pulse~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_pulse,
	combout => \pulse~combout\);

-- Location: PIN_100,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\flgIn[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_flgIn(0),
	combout => \flgIn~combout\(0));

-- Location: PIN_34,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\clrReg~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_clrReg,
	combout => \clrReg~combout\);

-- Location: LC_X2_Y2_N7
\flgs|reg[0]\ : maxv_lcell
-- Equation(s):
-- \flgs|reg\(0) = DFFEAS(((!\clrReg~combout\ & ((\flgIn~combout\(0)) # (\flgs|reg\(0))))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "00fa",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \flgIn~combout\(0),
	datac => \flgs|reg\(0),
	datad => \clrReg~combout\,
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \flgs|reg\(0));

-- Location: PIN_99,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\flgIn[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_flgIn(1),
	combout => \flgIn~combout\(1));

-- Location: LC_X3_Y1_N6
\flgs|reg[1]\ : maxv_lcell
-- Equation(s):
-- \flgs|reg\(1) = DFFEAS((!\clrReg~combout\ & ((\flgIn~combout\(1)) # ((\flgs|reg\(1))))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "5454",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \clrReg~combout\,
	datab => \flgIn~combout\(1),
	datac => \flgs|reg\(1),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \flgs|reg\(1));

-- Location: PIN_98,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\flgIn[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_flgIn(2),
	combout => \flgIn~combout\(2));

-- Location: LC_X2_Y1_N2
\flgs|reg[2]\ : maxv_lcell
-- Equation(s):
-- \flgs|reg\(2) = DFFEAS((!\clrReg~combout\ & (((\flgIn~combout\(2)) # (\flgs|reg\(2))))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "5550",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \clrReg~combout\,
	datac => \flgIn~combout\(2),
	datad => \flgs|reg\(2),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \flgs|reg\(2));

-- Location: PIN_97,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\flgIn[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_flgIn(3),
	combout => \flgIn~combout\(3));

-- Location: LC_X4_Y2_N3
\flgs|reg[3]\ : maxv_lcell
-- Equation(s):
-- \flgs|reg\(3) = DFFEAS(((!\clrReg~combout\ & ((\flgIn~combout\(3)) # (\flgs|reg\(3))))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "3330",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \clrReg~combout\,
	datac => \flgIn~combout\(3),
	datad => \flgs|reg\(3),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \flgs|reg\(3));

-- Location: PIN_96,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\flgIn[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_flgIn(4),
	combout => \flgIn~combout\(4));

-- Location: LC_X4_Y1_N3
\flgs|reg[4]\ : maxv_lcell
-- Equation(s):
-- \flgs|reg\(4) = DFFEAS(((!\clrReg~combout\ & ((\flgIn~combout\(4)) # (\flgs|reg\(4))))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0f0a",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \flgIn~combout\(4),
	datac => \clrReg~combout\,
	datad => \flgs|reg\(4),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \flgs|reg\(4));

-- Location: PIN_95,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\flgIn[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_flgIn(5),
	combout => \flgIn~combout\(5));

-- Location: LC_X4_Y2_N1
\flgs|reg[5]\ : maxv_lcell
-- Equation(s):
-- \flgs|reg\(5) = DFFEAS(((!\clrReg~combout\ & ((\flgIn~combout\(5)) # (\flgs|reg\(5))))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "3330",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \clrReg~combout\,
	datac => \flgIn~combout\(5),
	datad => \flgs|reg\(5),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \flgs|reg\(5));

-- Location: PIN_62,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\latch~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_latch,
	combout => \latch~combout\);

-- Location: LC_X4_Y2_N4
rst : maxv_lcell
-- Equation(s):
-- \rst~combout\ = ((\latch~combout\) # ((\eq~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "fcfc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \latch~combout\,
	datac => \eq~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \rst~combout\);

-- Location: LC_X4_Y2_N2
\cycleCounter|count[0]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(0) = DFFEAS((((!\cycleCounter|count\(0)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "00ff",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datad => \cycleCounter|count\(0),
	aclr => \rst~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(0));

-- Location: LC_X4_Y2_N5
\cycleCounter|count[1]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(1) = DFFEAS(\cycleCounter|count\(1) $ ((\cycleCounter|count\(0))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[1]~1\ = CARRY((\cycleCounter|count\(1) & (\cycleCounter|count\(0))))
-- \cycleCounter|count[1]~1COUT1_89\ = CARRY((\cycleCounter|count\(1) & (\cycleCounter|count\(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "6688",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(1),
	datab => \cycleCounter|count\(0),
	aclr => \rst~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(1),
	cout0 => \cycleCounter|count[1]~1\,
	cout1 => \cycleCounter|count[1]~1COUT1_89\);

-- Location: LC_X4_Y2_N6
\cycleCounter|count[2]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(2) = DFFEAS(\cycleCounter|count\(2) $ ((((\cycleCounter|count[1]~1\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[2]~5\ = CARRY(((!\cycleCounter|count[1]~1\)) # (!\cycleCounter|count\(2)))
-- \cycleCounter|count[2]~5COUT1_91\ = CARRY(((!\cycleCounter|count[1]~1COUT1_89\)) # (!\cycleCounter|count\(2)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(2),
	aclr => \rst~combout\,
	cin0 => \cycleCounter|count[1]~1\,
	cin1 => \cycleCounter|count[1]~1COUT1_89\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(2),
	cout0 => \cycleCounter|count[2]~5\,
	cout1 => \cycleCounter|count[2]~5COUT1_91\);

-- Location: LC_X4_Y2_N7
\cycleCounter|count[3]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(3) = DFFEAS((\cycleCounter|count\(3) $ ((!\cycleCounter|count[2]~5\))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[3]~3\ = CARRY(((\cycleCounter|count\(3) & !\cycleCounter|count[2]~5\)))
-- \cycleCounter|count[3]~3COUT1_93\ = CARRY(((\cycleCounter|count\(3) & !\cycleCounter|count[2]~5COUT1_91\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(3),
	aclr => \rst~combout\,
	cin0 => \cycleCounter|count[2]~5\,
	cin1 => \cycleCounter|count[2]~5COUT1_91\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(3),
	cout0 => \cycleCounter|count[3]~3\,
	cout1 => \cycleCounter|count[3]~3COUT1_93\);

-- Location: LC_X4_Y2_N8
\cycleCounter|count[4]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(4) = DFFEAS(\cycleCounter|count\(4) $ ((((\cycleCounter|count[3]~3\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[4]~9\ = CARRY(((!\cycleCounter|count[3]~3\)) # (!\cycleCounter|count\(4)))
-- \cycleCounter|count[4]~9COUT1_95\ = CARRY(((!\cycleCounter|count[3]~3COUT1_93\)) # (!\cycleCounter|count\(4)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(4),
	aclr => \rst~combout\,
	cin0 => \cycleCounter|count[3]~3\,
	cin1 => \cycleCounter|count[3]~3COUT1_93\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(4),
	cout0 => \cycleCounter|count[4]~9\,
	cout1 => \cycleCounter|count[4]~9COUT1_95\);

-- Location: LC_X4_Y2_N9
\cycleCounter|count[5]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(5) = DFFEAS((\cycleCounter|count\(5) $ ((!\cycleCounter|count[4]~9\))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[5]~7\ = CARRY(((\cycleCounter|count\(5) & !\cycleCounter|count[4]~9COUT1_95\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(5),
	aclr => \rst~combout\,
	cin0 => \cycleCounter|count[4]~9\,
	cin1 => \cycleCounter|count[4]~9COUT1_95\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(5),
	cout => \cycleCounter|count[5]~7\);

-- Location: LC_X5_Y2_N0
\cycleCounter|count[6]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(6) = DFFEAS((\cycleCounter|count\(6) $ ((\cycleCounter|count[5]~7\))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[6]~13\ = CARRY(((!\cycleCounter|count[5]~7\) # (!\cycleCounter|count\(6))))
-- \cycleCounter|count[6]~13COUT1_97\ = CARRY(((!\cycleCounter|count[5]~7\) # (!\cycleCounter|count\(6))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(6),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[5]~7\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(6),
	cout0 => \cycleCounter|count[6]~13\,
	cout1 => \cycleCounter|count[6]~13COUT1_97\);

-- Location: LC_X5_Y2_N1
\cycleCounter|count[7]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(7) = DFFEAS((\cycleCounter|count\(7) $ ((!(!\cycleCounter|count[5]~7\ & \cycleCounter|count[6]~13\) # (\cycleCounter|count[5]~7\ & \cycleCounter|count[6]~13COUT1_97\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[7]~11\ = CARRY(((\cycleCounter|count\(7) & !\cycleCounter|count[6]~13\)))
-- \cycleCounter|count[7]~11COUT1_99\ = CARRY(((\cycleCounter|count\(7) & !\cycleCounter|count[6]~13COUT1_97\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(7),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[5]~7\,
	cin0 => \cycleCounter|count[6]~13\,
	cin1 => \cycleCounter|count[6]~13COUT1_97\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(7),
	cout0 => \cycleCounter|count[7]~11\,
	cout1 => \cycleCounter|count[7]~11COUT1_99\);

-- Location: LC_X5_Y2_N2
\cycleCounter|count[8]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(8) = DFFEAS((\cycleCounter|count\(8) $ (((!\cycleCounter|count[5]~7\ & \cycleCounter|count[7]~11\) # (\cycleCounter|count[5]~7\ & \cycleCounter|count[7]~11COUT1_99\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[8]~17\ = CARRY(((!\cycleCounter|count[7]~11\) # (!\cycleCounter|count\(8))))
-- \cycleCounter|count[8]~17COUT1_101\ = CARRY(((!\cycleCounter|count[7]~11COUT1_99\) # (!\cycleCounter|count\(8))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(8),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[5]~7\,
	cin0 => \cycleCounter|count[7]~11\,
	cin1 => \cycleCounter|count[7]~11COUT1_99\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(8),
	cout0 => \cycleCounter|count[8]~17\,
	cout1 => \cycleCounter|count[8]~17COUT1_101\);

-- Location: LC_X5_Y2_N3
\cycleCounter|count[9]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(9) = DFFEAS(\cycleCounter|count\(9) $ ((((!(!\cycleCounter|count[5]~7\ & \cycleCounter|count[8]~17\) # (\cycleCounter|count[5]~7\ & \cycleCounter|count[8]~17COUT1_101\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[9]~15\ = CARRY((\cycleCounter|count\(9) & ((!\cycleCounter|count[8]~17\))))
-- \cycleCounter|count[9]~15COUT1_103\ = CARRY((\cycleCounter|count\(9) & ((!\cycleCounter|count[8]~17COUT1_101\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(9),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[5]~7\,
	cin0 => \cycleCounter|count[8]~17\,
	cin1 => \cycleCounter|count[8]~17COUT1_101\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(9),
	cout0 => \cycleCounter|count[9]~15\,
	cout1 => \cycleCounter|count[9]~15COUT1_103\);

-- Location: LC_X5_Y2_N4
\cycleCounter|count[10]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(10) = DFFEAS(\cycleCounter|count\(10) $ (((((!\cycleCounter|count[5]~7\ & \cycleCounter|count[9]~15\) # (\cycleCounter|count[5]~7\ & \cycleCounter|count[9]~15COUT1_103\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[10]~21\ = CARRY(((!\cycleCounter|count[9]~15COUT1_103\)) # (!\cycleCounter|count\(10)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(10),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[5]~7\,
	cin0 => \cycleCounter|count[9]~15\,
	cin1 => \cycleCounter|count[9]~15COUT1_103\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(10),
	cout => \cycleCounter|count[10]~21\);

-- Location: LC_X5_Y2_N5
\cycleCounter|count[11]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(11) = DFFEAS(\cycleCounter|count\(11) $ ((((!\cycleCounter|count[10]~21\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[11]~19\ = CARRY((\cycleCounter|count\(11) & ((!\cycleCounter|count[10]~21\))))
-- \cycleCounter|count[11]~19COUT1_105\ = CARRY((\cycleCounter|count\(11) & ((!\cycleCounter|count[10]~21\))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(11),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[10]~21\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(11),
	cout0 => \cycleCounter|count[11]~19\,
	cout1 => \cycleCounter|count[11]~19COUT1_105\);

-- Location: LC_X5_Y2_N6
\cycleCounter|count[12]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(12) = DFFEAS(\cycleCounter|count\(12) $ (((((!\cycleCounter|count[10]~21\ & \cycleCounter|count[11]~19\) # (\cycleCounter|count[10]~21\ & \cycleCounter|count[11]~19COUT1_105\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[12]~25\ = CARRY(((!\cycleCounter|count[11]~19\)) # (!\cycleCounter|count\(12)))
-- \cycleCounter|count[12]~25COUT1_107\ = CARRY(((!\cycleCounter|count[11]~19COUT1_105\)) # (!\cycleCounter|count\(12)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(12),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[10]~21\,
	cin0 => \cycleCounter|count[11]~19\,
	cin1 => \cycleCounter|count[11]~19COUT1_105\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(12),
	cout0 => \cycleCounter|count[12]~25\,
	cout1 => \cycleCounter|count[12]~25COUT1_107\);

-- Location: LC_X5_Y2_N7
\cycleCounter|count[13]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(13) = DFFEAS((\cycleCounter|count\(13) $ ((!(!\cycleCounter|count[10]~21\ & \cycleCounter|count[12]~25\) # (\cycleCounter|count[10]~21\ & \cycleCounter|count[12]~25COUT1_107\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[13]~23\ = CARRY(((\cycleCounter|count\(13) & !\cycleCounter|count[12]~25\)))
-- \cycleCounter|count[13]~23COUT1_109\ = CARRY(((\cycleCounter|count\(13) & !\cycleCounter|count[12]~25COUT1_107\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(13),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[10]~21\,
	cin0 => \cycleCounter|count[12]~25\,
	cin1 => \cycleCounter|count[12]~25COUT1_107\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(13),
	cout0 => \cycleCounter|count[13]~23\,
	cout1 => \cycleCounter|count[13]~23COUT1_109\);

-- Location: PIN_52,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\dataIn~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_dataIn,
	combout => \dataIn~combout\);

-- Location: LC_X3_Y1_N3
\shiftReg|reg[0]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(0) = DFFEAS(((\dataIn~combout\)), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "cccc",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datab => \dataIn~combout\,
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(0));

-- Location: LC_X3_Y1_N0
\shiftReg|reg[1]\ : maxv_lcell
-- Equation(s):
-- \Equal1~0\ = (\cycleCounter|count\(0) & (\shiftReg|reg\(0) & (\cycleCounter|count\(1) $ (!D1_reg[1])))) # (!\cycleCounter|count\(0) & (!\shiftReg|reg\(0) & (\cycleCounter|count\(1) $ (!D1_reg[1]))))
-- \shiftReg|reg\(1) = DFFEAS(\Equal1~0\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(0), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(0),
	datab => \cycleCounter|count\(1),
	datac => \shiftReg|reg\(0),
	datad => \shiftReg|reg\(0),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~0\,
	regout => \shiftReg|reg\(1));

-- Location: LC_X3_Y1_N7
\shiftReg|reg[2]\ : maxv_lcell
-- Equation(s):
-- \Equal1~1\ = (\cycleCounter|count\(2) & (D1_reg[2] & (\cycleCounter|count\(3) $ (!\shiftReg|reg\(3))))) # (!\cycleCounter|count\(2) & (!D1_reg[2] & (\cycleCounter|count\(3) $ (!\shiftReg|reg\(3)))))
-- \shiftReg|reg\(2) = DFFEAS(\Equal1~1\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(1), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(2),
	datab => \cycleCounter|count\(3),
	datac => \shiftReg|reg\(1),
	datad => \shiftReg|reg\(3),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~1\,
	regout => \shiftReg|reg\(2));

-- Location: LC_X3_Y1_N2
\shiftReg|reg[3]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(3) = DFFEAS(GND, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(2), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datac => \shiftReg|reg\(2),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(3));

-- Location: LC_X3_Y1_N5
\shiftReg|reg[4]\ : maxv_lcell
-- Equation(s):
-- \Equal1~2\ = (\cycleCounter|count\(4) & (D1_reg[4] & (\cycleCounter|count\(5) $ (!\shiftReg|reg\(5))))) # (!\cycleCounter|count\(4) & (!D1_reg[4] & (\cycleCounter|count\(5) $ (!\shiftReg|reg\(5)))))
-- \shiftReg|reg\(4) = DFFEAS(\Equal1~2\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(3), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(4),
	datab => \cycleCounter|count\(5),
	datac => \shiftReg|reg\(3),
	datad => \shiftReg|reg\(5),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~2\,
	regout => \shiftReg|reg\(4));

-- Location: LC_X3_Y1_N1
\shiftReg|reg[5]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(5) = DFFEAS(GND, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(4), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datac => \shiftReg|reg\(4),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(5));

-- Location: LC_X3_Y1_N4
\shiftReg|reg[6]\ : maxv_lcell
-- Equation(s):
-- \Equal1~3\ = (\cycleCounter|count\(6) & (D1_reg[6] & (\cycleCounter|count\(7) $ (!\shiftReg|reg\(7))))) # (!\cycleCounter|count\(6) & (!D1_reg[6] & (\cycleCounter|count\(7) $ (!\shiftReg|reg\(7)))))
-- \shiftReg|reg\(6) = DFFEAS(\Equal1~3\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(5), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(6),
	datab => \cycleCounter|count\(7),
	datac => \shiftReg|reg\(5),
	datad => \shiftReg|reg\(7),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~3\,
	regout => \shiftReg|reg\(6));

-- Location: LC_X3_Y1_N9
\shiftReg|reg[7]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(7) = DFFEAS((((\shiftReg|reg\(6)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(6),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(7));

-- Location: LC_X2_Y2_N6
\shiftReg|reg[8]\ : maxv_lcell
-- Equation(s):
-- \Equal1~5\ = (\cycleCounter|count\(9) & (\shiftReg|reg\(9) & (\cycleCounter|count\(8) $ (!D1_reg[8])))) # (!\cycleCounter|count\(9) & (!\shiftReg|reg\(9) & (\cycleCounter|count\(8) $ (!D1_reg[8]))))
-- \shiftReg|reg\(8) = DFFEAS(\Equal1~5\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(7), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(9),
	datab => \cycleCounter|count\(8),
	datac => \shiftReg|reg\(7),
	datad => \shiftReg|reg\(9),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~5\,
	regout => \shiftReg|reg\(8));

-- Location: LC_X2_Y2_N2
\shiftReg|reg[9]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(9) = DFFEAS((((\shiftReg|reg\(8)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(8),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(9));

-- Location: LC_X2_Y2_N3
\shiftReg|reg[10]\ : maxv_lcell
-- Equation(s):
-- \Equal1~6\ = (\cycleCounter|count\(11) & (\shiftReg|reg\(11) & (\cycleCounter|count\(10) $ (!D1_reg[10])))) # (!\cycleCounter|count\(11) & (!\shiftReg|reg\(11) & (\cycleCounter|count\(10) $ (!D1_reg[10]))))
-- \shiftReg|reg\(10) = DFFEAS(\Equal1~6\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(9), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(11),
	datab => \cycleCounter|count\(10),
	datac => \shiftReg|reg\(9),
	datad => \shiftReg|reg\(11),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~6\,
	regout => \shiftReg|reg\(10));

-- Location: LC_X2_Y2_N9
\shiftReg|reg[11]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(11) = DFFEAS((((\shiftReg|reg\(10)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(10),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(11));

-- Location: LC_X2_Y2_N4
\shiftReg|reg[12]\ : maxv_lcell
-- Equation(s):
-- \Equal1~7\ = (\cycleCounter|count\(13) & (\shiftReg|reg\(13) & (\cycleCounter|count\(12) $ (!D1_reg[12])))) # (!\cycleCounter|count\(13) & (!\shiftReg|reg\(13) & (\cycleCounter|count\(12) $ (!D1_reg[12]))))
-- \shiftReg|reg\(12) = DFFEAS(\Equal1~7\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(11), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(13),
	datab => \cycleCounter|count\(12),
	datac => \shiftReg|reg\(11),
	datad => \shiftReg|reg\(13),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~7\,
	regout => \shiftReg|reg\(12));

-- Location: LC_X2_Y2_N5
\shiftReg|reg[13]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(13) = DFFEAS((((\shiftReg|reg\(12)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(12),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(13));

-- Location: LC_X5_Y2_N8
\cycleCounter|count[14]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(14) = DFFEAS(\cycleCounter|count\(14) $ (((((!\cycleCounter|count[10]~21\ & \cycleCounter|count[13]~23\) # (\cycleCounter|count[10]~21\ & \cycleCounter|count[13]~23COUT1_109\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[14]~29\ = CARRY(((!\cycleCounter|count[13]~23\)) # (!\cycleCounter|count\(14)))
-- \cycleCounter|count[14]~29COUT1_111\ = CARRY(((!\cycleCounter|count[13]~23COUT1_109\)) # (!\cycleCounter|count\(14)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(14),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[10]~21\,
	cin0 => \cycleCounter|count[13]~23\,
	cin1 => \cycleCounter|count[13]~23COUT1_109\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(14),
	cout0 => \cycleCounter|count[14]~29\,
	cout1 => \cycleCounter|count[14]~29COUT1_111\);

-- Location: LC_X5_Y2_N9
\cycleCounter|count[15]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(15) = DFFEAS((\cycleCounter|count\(15) $ ((!(!\cycleCounter|count[10]~21\ & \cycleCounter|count[14]~29\) # (\cycleCounter|count[10]~21\ & \cycleCounter|count[14]~29COUT1_111\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[15]~27\ = CARRY(((\cycleCounter|count\(15) & !\cycleCounter|count[14]~29COUT1_111\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(15),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[10]~21\,
	cin0 => \cycleCounter|count[14]~29\,
	cin1 => \cycleCounter|count[14]~29COUT1_111\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(15),
	cout => \cycleCounter|count[15]~27\);

-- Location: LC_X2_Y2_N0
\shiftReg|reg[14]\ : maxv_lcell
-- Equation(s):
-- \Equal1~8\ = (\cycleCounter|count\(14) & (D1_reg[14] & (\cycleCounter|count\(15) $ (!\shiftReg|reg\(15))))) # (!\cycleCounter|count\(14) & (!D1_reg[14] & (\cycleCounter|count\(15) $ (!\shiftReg|reg\(15)))))
-- \shiftReg|reg\(14) = DFFEAS(\Equal1~8\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(13), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(14),
	datab => \cycleCounter|count\(15),
	datac => \shiftReg|reg\(13),
	datad => \shiftReg|reg\(15),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~8\,
	regout => \shiftReg|reg\(14));

-- Location: LC_X2_Y2_N8
\shiftReg|reg[15]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(15) = DFFEAS((((\shiftReg|reg\(14)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(14),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(15));

-- Location: LC_X2_Y2_N1
\Equal1~9\ : maxv_lcell
-- Equation(s):
-- \Equal1~9_combout\ = (\Equal1~7\ & (\Equal1~8\ & (\Equal1~5\ & \Equal1~6\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8000",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \Equal1~7\,
	datab => \Equal1~8\,
	datac => \Equal1~5\,
	datad => \Equal1~6\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~9_combout\);

-- Location: LC_X6_Y2_N0
\cycleCounter|count[16]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(16) = DFFEAS((\cycleCounter|count\(16) $ ((\cycleCounter|count[15]~27\))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[16]~33\ = CARRY(((!\cycleCounter|count[15]~27\) # (!\cycleCounter|count\(16))))
-- \cycleCounter|count[16]~33COUT1_113\ = CARRY(((!\cycleCounter|count[15]~27\) # (!\cycleCounter|count\(16))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(16),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[15]~27\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(16),
	cout0 => \cycleCounter|count[16]~33\,
	cout1 => \cycleCounter|count[16]~33COUT1_113\);

-- Location: LC_X6_Y2_N1
\cycleCounter|count[17]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(17) = DFFEAS((\cycleCounter|count\(17) $ ((!(!\cycleCounter|count[15]~27\ & \cycleCounter|count[16]~33\) # (\cycleCounter|count[15]~27\ & \cycleCounter|count[16]~33COUT1_113\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[17]~31\ = CARRY(((\cycleCounter|count\(17) & !\cycleCounter|count[16]~33\)))
-- \cycleCounter|count[17]~31COUT1_115\ = CARRY(((\cycleCounter|count\(17) & !\cycleCounter|count[16]~33COUT1_113\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(17),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[15]~27\,
	cin0 => \cycleCounter|count[16]~33\,
	cin1 => \cycleCounter|count[16]~33COUT1_113\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(17),
	cout0 => \cycleCounter|count[17]~31\,
	cout1 => \cycleCounter|count[17]~31COUT1_115\);

-- Location: LC_X6_Y2_N2
\cycleCounter|count[18]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(18) = DFFEAS((\cycleCounter|count\(18) $ (((!\cycleCounter|count[15]~27\ & \cycleCounter|count[17]~31\) # (\cycleCounter|count[15]~27\ & \cycleCounter|count[17]~31COUT1_115\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[18]~37\ = CARRY(((!\cycleCounter|count[17]~31\) # (!\cycleCounter|count\(18))))
-- \cycleCounter|count[18]~37COUT1_117\ = CARRY(((!\cycleCounter|count[17]~31COUT1_115\) # (!\cycleCounter|count\(18))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(18),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[15]~27\,
	cin0 => \cycleCounter|count[17]~31\,
	cin1 => \cycleCounter|count[17]~31COUT1_115\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(18),
	cout0 => \cycleCounter|count[18]~37\,
	cout1 => \cycleCounter|count[18]~37COUT1_117\);

-- Location: LC_X6_Y2_N3
\cycleCounter|count[19]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(19) = DFFEAS(\cycleCounter|count\(19) $ ((((!(!\cycleCounter|count[15]~27\ & \cycleCounter|count[18]~37\) # (\cycleCounter|count[15]~27\ & \cycleCounter|count[18]~37COUT1_117\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[19]~35\ = CARRY((\cycleCounter|count\(19) & ((!\cycleCounter|count[18]~37\))))
-- \cycleCounter|count[19]~35COUT1_119\ = CARRY((\cycleCounter|count\(19) & ((!\cycleCounter|count[18]~37COUT1_117\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(19),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[15]~27\,
	cin0 => \cycleCounter|count[18]~37\,
	cin1 => \cycleCounter|count[18]~37COUT1_117\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(19),
	cout0 => \cycleCounter|count[19]~35\,
	cout1 => \cycleCounter|count[19]~35COUT1_119\);

-- Location: LC_X6_Y2_N4
\cycleCounter|count[20]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(20) = DFFEAS(\cycleCounter|count\(20) $ (((((!\cycleCounter|count[15]~27\ & \cycleCounter|count[19]~35\) # (\cycleCounter|count[15]~27\ & \cycleCounter|count[19]~35COUT1_119\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[20]~41\ = CARRY(((!\cycleCounter|count[19]~35COUT1_119\)) # (!\cycleCounter|count\(20)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(20),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[15]~27\,
	cin0 => \cycleCounter|count[19]~35\,
	cin1 => \cycleCounter|count[19]~35COUT1_119\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(20),
	cout => \cycleCounter|count[20]~41\);

-- Location: LC_X6_Y2_N5
\cycleCounter|count[21]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(21) = DFFEAS(\cycleCounter|count\(21) $ ((((!\cycleCounter|count[20]~41\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[21]~39\ = CARRY((\cycleCounter|count\(21) & ((!\cycleCounter|count[20]~41\))))
-- \cycleCounter|count[21]~39COUT1_121\ = CARRY((\cycleCounter|count\(21) & ((!\cycleCounter|count[20]~41\))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(21),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[20]~41\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(21),
	cout0 => \cycleCounter|count[21]~39\,
	cout1 => \cycleCounter|count[21]~39COUT1_121\);

-- Location: LC_X6_Y2_N6
\cycleCounter|count[22]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(22) = DFFEAS(\cycleCounter|count\(22) $ (((((!\cycleCounter|count[20]~41\ & \cycleCounter|count[21]~39\) # (\cycleCounter|count[20]~41\ & \cycleCounter|count[21]~39COUT1_121\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[22]~45\ = CARRY(((!\cycleCounter|count[21]~39\)) # (!\cycleCounter|count\(22)))
-- \cycleCounter|count[22]~45COUT1_123\ = CARRY(((!\cycleCounter|count[21]~39COUT1_121\)) # (!\cycleCounter|count\(22)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(22),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[20]~41\,
	cin0 => \cycleCounter|count[21]~39\,
	cin1 => \cycleCounter|count[21]~39COUT1_121\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(22),
	cout0 => \cycleCounter|count[22]~45\,
	cout1 => \cycleCounter|count[22]~45COUT1_123\);

-- Location: LC_X6_Y2_N7
\cycleCounter|count[23]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(23) = DFFEAS((\cycleCounter|count\(23) $ ((!(!\cycleCounter|count[20]~41\ & \cycleCounter|count[22]~45\) # (\cycleCounter|count[20]~41\ & \cycleCounter|count[22]~45COUT1_123\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[23]~43\ = CARRY(((\cycleCounter|count\(23) & !\cycleCounter|count[22]~45\)))
-- \cycleCounter|count[23]~43COUT1_125\ = CARRY(((\cycleCounter|count\(23) & !\cycleCounter|count[22]~45COUT1_123\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(23),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[20]~41\,
	cin0 => \cycleCounter|count[22]~45\,
	cin1 => \cycleCounter|count[22]~45COUT1_123\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(23),
	cout0 => \cycleCounter|count[23]~43\,
	cout1 => \cycleCounter|count[23]~43COUT1_125\);

-- Location: LC_X6_Y2_N8
\cycleCounter|count[24]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(24) = DFFEAS(\cycleCounter|count\(24) $ (((((!\cycleCounter|count[20]~41\ & \cycleCounter|count[23]~43\) # (\cycleCounter|count[20]~41\ & \cycleCounter|count[23]~43COUT1_125\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[24]~49\ = CARRY(((!\cycleCounter|count[23]~43\)) # (!\cycleCounter|count\(24)))
-- \cycleCounter|count[24]~49COUT1_127\ = CARRY(((!\cycleCounter|count[23]~43COUT1_125\)) # (!\cycleCounter|count\(24)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(24),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[20]~41\,
	cin0 => \cycleCounter|count[23]~43\,
	cin1 => \cycleCounter|count[23]~43COUT1_125\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(24),
	cout0 => \cycleCounter|count[24]~49\,
	cout1 => \cycleCounter|count[24]~49COUT1_127\);

-- Location: LC_X6_Y2_N9
\cycleCounter|count[25]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(25) = DFFEAS((\cycleCounter|count\(25) $ ((!(!\cycleCounter|count[20]~41\ & \cycleCounter|count[24]~49\) # (\cycleCounter|count[20]~41\ & \cycleCounter|count[24]~49COUT1_127\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[25]~47\ = CARRY(((\cycleCounter|count\(25) & !\cycleCounter|count[24]~49COUT1_127\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(25),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[20]~41\,
	cin0 => \cycleCounter|count[24]~49\,
	cin1 => \cycleCounter|count[24]~49COUT1_127\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(25),
	cout => \cycleCounter|count[25]~47\);

-- Location: LC_X7_Y2_N0
\cycleCounter|count[26]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(26) = DFFEAS((\cycleCounter|count\(26) $ ((\cycleCounter|count[25]~47\))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[26]~53\ = CARRY(((!\cycleCounter|count[25]~47\) # (!\cycleCounter|count\(26))))
-- \cycleCounter|count[26]~53COUT1_129\ = CARRY(((!\cycleCounter|count[25]~47\) # (!\cycleCounter|count\(26))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(26),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[25]~47\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(26),
	cout0 => \cycleCounter|count[26]~53\,
	cout1 => \cycleCounter|count[26]~53COUT1_129\);

-- Location: LC_X7_Y2_N1
\cycleCounter|count[27]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(27) = DFFEAS((\cycleCounter|count\(27) $ ((!(!\cycleCounter|count[25]~47\ & \cycleCounter|count[26]~53\) # (\cycleCounter|count[25]~47\ & \cycleCounter|count[26]~53COUT1_129\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[27]~51\ = CARRY(((\cycleCounter|count\(27) & !\cycleCounter|count[26]~53\)))
-- \cycleCounter|count[27]~51COUT1_131\ = CARRY(((\cycleCounter|count\(27) & !\cycleCounter|count[26]~53COUT1_129\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(27),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[25]~47\,
	cin0 => \cycleCounter|count[26]~53\,
	cin1 => \cycleCounter|count[26]~53COUT1_129\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(27),
	cout0 => \cycleCounter|count[27]~51\,
	cout1 => \cycleCounter|count[27]~51COUT1_131\);

-- Location: LC_X7_Y2_N2
\cycleCounter|count[28]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(28) = DFFEAS((\cycleCounter|count\(28) $ (((!\cycleCounter|count[25]~47\ & \cycleCounter|count[27]~51\) # (\cycleCounter|count[25]~47\ & \cycleCounter|count[27]~51COUT1_131\)))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[28]~57\ = CARRY(((!\cycleCounter|count[27]~51\) # (!\cycleCounter|count\(28))))
-- \cycleCounter|count[28]~57COUT1_133\ = CARRY(((!\cycleCounter|count[27]~51COUT1_131\) # (!\cycleCounter|count\(28))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	datab => \cycleCounter|count\(28),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[25]~47\,
	cin0 => \cycleCounter|count[27]~51\,
	cin1 => \cycleCounter|count[27]~51COUT1_131\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(28),
	cout0 => \cycleCounter|count[28]~57\,
	cout1 => \cycleCounter|count[28]~57COUT1_133\);

-- Location: LC_X7_Y2_N3
\cycleCounter|count[29]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(29) = DFFEAS(\cycleCounter|count\(29) $ ((((!(!\cycleCounter|count[25]~47\ & \cycleCounter|count[28]~57\) # (\cycleCounter|count[25]~47\ & \cycleCounter|count[28]~57COUT1_133\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[29]~55\ = CARRY((\cycleCounter|count\(29) & ((!\cycleCounter|count[28]~57\))))
-- \cycleCounter|count[29]~55COUT1_135\ = CARRY((\cycleCounter|count\(29) & ((!\cycleCounter|count[28]~57COUT1_133\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(29),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[25]~47\,
	cin0 => \cycleCounter|count[28]~57\,
	cin1 => \cycleCounter|count[28]~57COUT1_133\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(29),
	cout0 => \cycleCounter|count[29]~55\,
	cout1 => \cycleCounter|count[29]~55COUT1_135\);

-- Location: LC_X2_Y1_N1
\shiftReg|reg[16]\ : maxv_lcell
-- Equation(s):
-- \Equal1~10\ = (\cycleCounter|count\(17) & (\shiftReg|reg\(17) & (\cycleCounter|count\(16) $ (!D1_reg[16])))) # (!\cycleCounter|count\(17) & (!\shiftReg|reg\(17) & (\cycleCounter|count\(16) $ (!D1_reg[16]))))
-- \shiftReg|reg\(16) = DFFEAS(\Equal1~10\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(15), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(17),
	datab => \cycleCounter|count\(16),
	datac => \shiftReg|reg\(15),
	datad => \shiftReg|reg\(17),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~10\,
	regout => \shiftReg|reg\(16));

-- Location: LC_X2_Y1_N3
\shiftReg|reg[17]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(17) = DFFEAS((((\shiftReg|reg\(16)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(16),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(17));

-- Location: LC_X2_Y1_N6
\shiftReg|reg[18]\ : maxv_lcell
-- Equation(s):
-- \Equal1~11\ = (\cycleCounter|count\(19) & (\shiftReg|reg\(19) & (\cycleCounter|count\(18) $ (!D1_reg[18])))) # (!\cycleCounter|count\(19) & (!\shiftReg|reg\(19) & (\cycleCounter|count\(18) $ (!D1_reg[18]))))
-- \shiftReg|reg\(18) = DFFEAS(\Equal1~11\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(17), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(19),
	datab => \cycleCounter|count\(18),
	datac => \shiftReg|reg\(17),
	datad => \shiftReg|reg\(19),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~11\,
	regout => \shiftReg|reg\(18));

-- Location: LC_X2_Y1_N8
\shiftReg|reg[19]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(19) = DFFEAS((((\shiftReg|reg\(18)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(18),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(19));

-- Location: LC_X2_Y1_N7
\shiftReg|reg[20]\ : maxv_lcell
-- Equation(s):
-- \Equal1~12\ = (\cycleCounter|count\(20) & (D1_reg[20] & (\cycleCounter|count\(21) $ (!\shiftReg|reg\(21))))) # (!\cycleCounter|count\(20) & (!D1_reg[20] & (\cycleCounter|count\(21) $ (!\shiftReg|reg\(21)))))
-- \shiftReg|reg\(20) = DFFEAS(\Equal1~12\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(19), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(20),
	datab => \cycleCounter|count\(21),
	datac => \shiftReg|reg\(19),
	datad => \shiftReg|reg\(21),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~12\,
	regout => \shiftReg|reg\(20));

-- Location: LC_X2_Y1_N4
\shiftReg|reg[21]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(21) = DFFEAS(GND, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(20), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datac => \shiftReg|reg\(20),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(21));

-- Location: LC_X2_Y1_N0
\shiftReg|reg[22]\ : maxv_lcell
-- Equation(s):
-- \Equal1~13\ = (\cycleCounter|count\(22) & (D1_reg[22] & (\cycleCounter|count\(23) $ (!\shiftReg|reg\(23))))) # (!\cycleCounter|count\(22) & (!D1_reg[22] & (\cycleCounter|count\(23) $ (!\shiftReg|reg\(23)))))
-- \shiftReg|reg\(22) = DFFEAS(\Equal1~13\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(21), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(22),
	datab => \cycleCounter|count\(23),
	datac => \shiftReg|reg\(21),
	datad => \shiftReg|reg\(23),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~13\,
	regout => \shiftReg|reg\(22));

-- Location: LC_X2_Y1_N9
\shiftReg|reg[23]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(23) = DFFEAS((((\shiftReg|reg\(22)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(22),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(23));

-- Location: LC_X3_Y2_N0
\shiftReg|reg[24]\ : maxv_lcell
-- Equation(s):
-- \Equal1~15\ = (\cycleCounter|count\(25) & (\shiftReg|reg\(25) & (\cycleCounter|count\(24) $ (!D1_reg[24])))) # (!\cycleCounter|count\(25) & (!\shiftReg|reg\(25) & (\cycleCounter|count\(24) $ (!D1_reg[24]))))
-- \shiftReg|reg\(24) = DFFEAS(\Equal1~15\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(23), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(25),
	datab => \cycleCounter|count\(24),
	datac => \shiftReg|reg\(23),
	datad => \shiftReg|reg\(25),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~15\,
	regout => \shiftReg|reg\(24));

-- Location: LC_X3_Y2_N9
\shiftReg|reg[25]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(25) = DFFEAS((((\shiftReg|reg\(24)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(24),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(25));

-- Location: LC_X3_Y2_N3
\shiftReg|reg[26]\ : maxv_lcell
-- Equation(s):
-- \Equal1~16\ = (\cycleCounter|count\(27) & (\shiftReg|reg\(27) & (\cycleCounter|count\(26) $ (!D1_reg[26])))) # (!\cycleCounter|count\(27) & (!\shiftReg|reg\(27) & (\cycleCounter|count\(26) $ (!D1_reg[26]))))
-- \shiftReg|reg\(26) = DFFEAS(\Equal1~16\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(25), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(27),
	datab => \cycleCounter|count\(26),
	datac => \shiftReg|reg\(25),
	datad => \shiftReg|reg\(27),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~16\,
	regout => \shiftReg|reg\(26));

-- Location: LC_X3_Y2_N4
\shiftReg|reg[27]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(27) = DFFEAS(GND, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(26), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datac => \shiftReg|reg\(26),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(27));

-- Location: LC_X3_Y2_N6
\shiftReg|reg[28]\ : maxv_lcell
-- Equation(s):
-- \Equal1~17\ = (\cycleCounter|count\(29) & (\shiftReg|reg\(29) & (\cycleCounter|count\(28) $ (!D1_reg[28])))) # (!\cycleCounter|count\(29) & (!\shiftReg|reg\(29) & (\cycleCounter|count\(28) $ (!D1_reg[28]))))
-- \shiftReg|reg\(28) = DFFEAS(\Equal1~17\, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(27), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8241",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(29),
	datab => \cycleCounter|count\(28),
	datac => \shiftReg|reg\(27),
	datad => \shiftReg|reg\(29),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~17\,
	regout => \shiftReg|reg\(28));

-- Location: LC_X3_Y2_N5
\shiftReg|reg[29]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(29) = DFFEAS((((\shiftReg|reg\(28)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftReg|reg\(28),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(29));

-- Location: LC_X7_Y2_N4
\cycleCounter|count[30]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(30) = DFFEAS(\cycleCounter|count\(30) $ (((((!\cycleCounter|count[25]~47\ & \cycleCounter|count[29]~55\) # (\cycleCounter|count[25]~47\ & \cycleCounter|count[29]~55COUT1_135\))))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )
-- \cycleCounter|count[30]~61\ = CARRY(((!\cycleCounter|count[29]~55COUT1_135\)) # (!\cycleCounter|count\(30)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \cycleCounter|count\(30),
	aclr => \rst~combout\,
	cin => \cycleCounter|count[25]~47\,
	cin0 => \cycleCounter|count[29]~55\,
	cin1 => \cycleCounter|count[29]~55COUT1_135\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(30),
	cout => \cycleCounter|count[30]~61\);

-- Location: LC_X7_Y2_N5
\cycleCounter|count[31]\ : maxv_lcell
-- Equation(s):
-- \cycleCounter|count\(31) = DFFEAS((((!\cycleCounter|count[30]~61\))), GLOBAL(\pulse~combout\), !\rst~combout\, , , , , , )

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "0f0f",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	aclr => \rst~combout\,
	cin => \cycleCounter|count[30]~61\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \cycleCounter|count\(31));

-- Location: LC_X3_Y2_N1
\shiftReg|reg[30]\ : maxv_lcell
-- Equation(s):
-- \shiftReg|reg\(30) = DFFEAS(GND, GLOBAL(\latch~combout\), VCC, , , \shiftReg|reg\(29), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datac => \shiftReg|reg\(29),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftReg|reg\(30));

-- Location: LC_X3_Y2_N2
\shiftReg|reg[31]\ : maxv_lcell
-- Equation(s):
-- \Equal1~18\ = (\cycleCounter|count\(31) & (D1_reg[31] & (\cycleCounter|count\(30) $ (!\shiftReg|reg\(30))))) # (!\cycleCounter|count\(31) & (!D1_reg[31] & (\cycleCounter|count\(30) $ (!\shiftReg|reg\(30)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8421",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \cycleCounter|count\(31),
	datab => \cycleCounter|count\(30),
	datac => \shiftReg|reg\(30),
	datad => \shiftReg|reg\(30),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~18\,
	regout => \shiftReg|reg\(31));

-- Location: LC_X3_Y2_N7
\Equal1~19\ : maxv_lcell
-- Equation(s):
-- \Equal1~19_combout\ = (\Equal1~17\ & (\Equal1~18\ & (\Equal1~15\ & \Equal1~16\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8000",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \Equal1~17\,
	datab => \Equal1~18\,
	datac => \Equal1~15\,
	datad => \Equal1~16\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~19_combout\);

-- Location: LC_X2_Y1_N5
\Equal1~14\ : maxv_lcell
-- Equation(s):
-- \Equal1~14_combout\ = (\Equal1~12\ & (\Equal1~13\ & (\Equal1~11\ & \Equal1~10\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8000",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \Equal1~12\,
	datab => \Equal1~13\,
	datac => \Equal1~11\,
	datad => \Equal1~10\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~14_combout\);

-- Location: LC_X3_Y1_N8
\Equal1~4\ : maxv_lcell
-- Equation(s):
-- \Equal1~4_combout\ = (\Equal1~2\ & (\Equal1~0\ & (\Equal1~3\ & \Equal1~1\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8000",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \Equal1~2\,
	datab => \Equal1~0\,
	datac => \Equal1~3\,
	datad => \Equal1~1\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal1~4_combout\);

-- Location: LC_X3_Y2_N8
eq : maxv_lcell
-- Equation(s):
-- \eq~regout\ = DFFEAS((\Equal1~9_combout\ & (\Equal1~19_combout\ & (\Equal1~14_combout\ & \Equal1~4_combout\))), GLOBAL(\pulse~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \pulse~combout\,
	dataa => \Equal1~9_combout\,
	datab => \Equal1~19_combout\,
	datac => \Equal1~14_combout\,
	datad => \Equal1~4_combout\,
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \eq~regout\);

-- Location: LC_X4_Y1_N2
\shiftCounter|count[0]\ : maxv_lcell
-- Equation(s):
-- \shiftCounter|count\(0) = DFFEAS((((!\shiftCounter|count\(0)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "00ff",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftCounter|count\(0),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftCounter|count\(0));

-- Location: LC_X4_Y1_N6
\shiftCounter|count[1]\ : maxv_lcell
-- Equation(s):
-- \shiftCounter|count\(1) = DFFEAS(\shiftCounter|count\(1) $ ((\shiftCounter|count\(0))), GLOBAL(\latch~combout\), VCC, , , , , , )
-- \shiftCounter|count[1]~3\ = CARRY((\shiftCounter|count\(1) & (\shiftCounter|count\(0))))
-- \shiftCounter|count[1]~3COUT1_14\ = CARRY((\shiftCounter|count\(1) & (\shiftCounter|count\(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "6688",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \shiftCounter|count\(1),
	datab => \shiftCounter|count\(0),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftCounter|count\(1),
	cout0 => \shiftCounter|count[1]~3\,
	cout1 => \shiftCounter|count[1]~3COUT1_14\);

-- Location: LC_X4_Y1_N7
\shiftCounter|count[2]\ : maxv_lcell
-- Equation(s):
-- \shiftCounter|count\(2) = DFFEAS((\shiftCounter|count\(2) $ ((\shiftCounter|count[1]~3\))), GLOBAL(\latch~combout\), VCC, , , , , , )
-- \shiftCounter|count[2]~5\ = CARRY(((!\shiftCounter|count[1]~3\) # (!\shiftCounter|count\(2))))
-- \shiftCounter|count[2]~5COUT1_16\ = CARRY(((!\shiftCounter|count[1]~3COUT1_14\) # (!\shiftCounter|count\(2))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datab => \shiftCounter|count\(2),
	aclr => GND,
	cin0 => \shiftCounter|count[1]~3\,
	cin1 => \shiftCounter|count[1]~3COUT1_14\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftCounter|count\(2),
	cout0 => \shiftCounter|count[2]~5\,
	cout1 => \shiftCounter|count[2]~5COUT1_16\);

-- Location: LC_X4_Y1_N8
\shiftCounter|count[3]\ : maxv_lcell
-- Equation(s):
-- \shiftCounter|count\(3) = DFFEAS(\shiftCounter|count\(3) $ ((((!\shiftCounter|count[2]~5\)))), GLOBAL(\latch~combout\), VCC, , , , , , )
-- \shiftCounter|count[3]~7\ = CARRY((\shiftCounter|count\(3) & ((!\shiftCounter|count[2]~5\))))
-- \shiftCounter|count[3]~7COUT1_18\ = CARRY((\shiftCounter|count\(3) & ((!\shiftCounter|count[2]~5COUT1_16\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	dataa => \shiftCounter|count\(3),
	aclr => GND,
	cin0 => \shiftCounter|count[2]~5\,
	cin1 => \shiftCounter|count[2]~5COUT1_16\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftCounter|count\(3),
	cout0 => \shiftCounter|count[3]~7\,
	cout1 => \shiftCounter|count[3]~7COUT1_18\);

-- Location: LC_X4_Y1_N9
\shiftCounter|count[4]\ : maxv_lcell
-- Equation(s):
-- \shiftCounter|count\(4) = DFFEAS(((\shiftCounter|count[3]~7\ $ (\shiftCounter|count\(4)))), GLOBAL(\latch~combout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "0ff0",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \latch~combout\,
	datad => \shiftCounter|count\(4),
	aclr => GND,
	cin0 => \shiftCounter|count[3]~7\,
	cin1 => \shiftCounter|count[3]~7COUT1_18\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \shiftCounter|count\(4));

-- Location: LC_X4_Y1_N1
\Equal0~0\ : maxv_lcell
-- Equation(s):
-- \Equal0~0_combout\ = ((\shiftCounter|count\(1) & ((\shiftCounter|count\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "cc00",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \shiftCounter|count\(1),
	datad => \shiftCounter|count\(0),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal0~0_combout\);

-- Location: LC_X4_Y1_N4
\Equal0~1\ : maxv_lcell
-- Equation(s):
-- \Equal0~1_combout\ = (\shiftCounter|count\(3) & (\shiftCounter|count\(4) & (\shiftCounter|count\(2) & \Equal0~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8000",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \shiftCounter|count\(3),
	datab => \shiftCounter|count\(4),
	datac => \shiftCounter|count\(2),
	datad => \Equal0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \Equal0~1_combout\);

-- Location: PIN_51,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\wordSelect~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_wordSelect,
	combout => \wordSelect~combout\);

-- Location: PIN_14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\fvcIn~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_fvcIn,
	combout => \fvcIn~combout\);

-- Location: LC_X7_Y3_N7
\fvcCounter|count[0]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(0) = DFFEAS((((!\fvcCounter|count\(0)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0f0f",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datac => \fvcCounter|count\(0),
	aclr => \rst~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(0));

-- Location: LC_X3_Y3_N5
\fvcCounter|count[1]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(1) = DFFEAS(\fvcCounter|count\(1) $ ((\fvcCounter|count\(0))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[1]~5\ = CARRY((\fvcCounter|count\(1) & (\fvcCounter|count\(0))))
-- \fvcCounter|count[1]~5COUT1_89\ = CARRY((\fvcCounter|count\(1) & (\fvcCounter|count\(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "6688",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(1),
	datab => \fvcCounter|count\(0),
	aclr => \rst~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(1),
	cout0 => \fvcCounter|count[1]~5\,
	cout1 => \fvcCounter|count[1]~5COUT1_89\);

-- Location: LC_X3_Y3_N6
\fvcCounter|count[2]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(2) = DFFEAS(\fvcCounter|count\(2) $ ((((\fvcCounter|count[1]~5\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[2]~9\ = CARRY(((!\fvcCounter|count[1]~5\)) # (!\fvcCounter|count\(2)))
-- \fvcCounter|count[2]~9COUT1_91\ = CARRY(((!\fvcCounter|count[1]~5COUT1_89\)) # (!\fvcCounter|count\(2)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(2),
	aclr => \rst~combout\,
	cin0 => \fvcCounter|count[1]~5\,
	cin1 => \fvcCounter|count[1]~5COUT1_89\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(2),
	cout0 => \fvcCounter|count[2]~9\,
	cout1 => \fvcCounter|count[2]~9COUT1_91\);

-- Location: LC_X3_Y3_N7
\fvcCounter|count[3]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(3) = DFFEAS((\fvcCounter|count\(3) $ ((!\fvcCounter|count[2]~9\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[3]~13\ = CARRY(((\fvcCounter|count\(3) & !\fvcCounter|count[2]~9\)))
-- \fvcCounter|count[3]~13COUT1_93\ = CARRY(((\fvcCounter|count\(3) & !\fvcCounter|count[2]~9COUT1_91\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(3),
	aclr => \rst~combout\,
	cin0 => \fvcCounter|count[2]~9\,
	cin1 => \fvcCounter|count[2]~9COUT1_91\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(3),
	cout0 => \fvcCounter|count[3]~13\,
	cout1 => \fvcCounter|count[3]~13COUT1_93\);

-- Location: LC_X3_Y3_N8
\fvcCounter|count[4]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(4) = DFFEAS((\fvcCounter|count\(4) $ ((\fvcCounter|count[3]~13\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[4]~17\ = CARRY(((!\fvcCounter|count[3]~13\) # (!\fvcCounter|count\(4))))
-- \fvcCounter|count[4]~17COUT1_95\ = CARRY(((!\fvcCounter|count[3]~13COUT1_93\) # (!\fvcCounter|count\(4))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(4),
	aclr => \rst~combout\,
	cin0 => \fvcCounter|count[3]~13\,
	cin1 => \fvcCounter|count[3]~13COUT1_93\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(4),
	cout0 => \fvcCounter|count[4]~17\,
	cout1 => \fvcCounter|count[4]~17COUT1_95\);

-- Location: LC_X3_Y3_N9
\fvcCounter|count[5]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(5) = DFFEAS((\fvcCounter|count\(5) $ ((!\fvcCounter|count[4]~17\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[5]~21\ = CARRY(((\fvcCounter|count\(5) & !\fvcCounter|count[4]~17COUT1_95\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(5),
	aclr => \rst~combout\,
	cin0 => \fvcCounter|count[4]~17\,
	cin1 => \fvcCounter|count[4]~17COUT1_95\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(5),
	cout => \fvcCounter|count[5]~21\);

-- Location: LC_X4_Y3_N0
\fvcCounter|count[6]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(6) = DFFEAS((\fvcCounter|count\(6) $ ((\fvcCounter|count[5]~21\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[6]~25\ = CARRY(((!\fvcCounter|count[5]~21\) # (!\fvcCounter|count\(6))))
-- \fvcCounter|count[6]~25COUT1_97\ = CARRY(((!\fvcCounter|count[5]~21\) # (!\fvcCounter|count\(6))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(6),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[5]~21\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(6),
	cout0 => \fvcCounter|count[6]~25\,
	cout1 => \fvcCounter|count[6]~25COUT1_97\);

-- Location: LC_X4_Y3_N1
\fvcCounter|count[7]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(7) = DFFEAS((\fvcCounter|count\(7) $ ((!(!\fvcCounter|count[5]~21\ & \fvcCounter|count[6]~25\) # (\fvcCounter|count[5]~21\ & \fvcCounter|count[6]~25COUT1_97\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[7]~29\ = CARRY(((\fvcCounter|count\(7) & !\fvcCounter|count[6]~25\)))
-- \fvcCounter|count[7]~29COUT1_99\ = CARRY(((\fvcCounter|count\(7) & !\fvcCounter|count[6]~25COUT1_97\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(7),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[5]~21\,
	cin0 => \fvcCounter|count[6]~25\,
	cin1 => \fvcCounter|count[6]~25COUT1_97\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(7),
	cout0 => \fvcCounter|count[7]~29\,
	cout1 => \fvcCounter|count[7]~29COUT1_99\);

-- Location: LC_X4_Y3_N2
\fvcCounter|count[8]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(8) = DFFEAS((\fvcCounter|count\(8) $ (((!\fvcCounter|count[5]~21\ & \fvcCounter|count[7]~29\) # (\fvcCounter|count[5]~21\ & \fvcCounter|count[7]~29COUT1_99\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[8]~33\ = CARRY(((!\fvcCounter|count[7]~29\) # (!\fvcCounter|count\(8))))
-- \fvcCounter|count[8]~33COUT1_101\ = CARRY(((!\fvcCounter|count[7]~29COUT1_99\) # (!\fvcCounter|count\(8))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(8),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[5]~21\,
	cin0 => \fvcCounter|count[7]~29\,
	cin1 => \fvcCounter|count[7]~29COUT1_99\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(8),
	cout0 => \fvcCounter|count[8]~33\,
	cout1 => \fvcCounter|count[8]~33COUT1_101\);

-- Location: LC_X4_Y3_N3
\fvcCounter|count[9]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(9) = DFFEAS(\fvcCounter|count\(9) $ ((((!(!\fvcCounter|count[5]~21\ & \fvcCounter|count[8]~33\) # (\fvcCounter|count[5]~21\ & \fvcCounter|count[8]~33COUT1_101\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[9]~37\ = CARRY((\fvcCounter|count\(9) & ((!\fvcCounter|count[8]~33\))))
-- \fvcCounter|count[9]~37COUT1_103\ = CARRY((\fvcCounter|count\(9) & ((!\fvcCounter|count[8]~33COUT1_101\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(9),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[5]~21\,
	cin0 => \fvcCounter|count[8]~33\,
	cin1 => \fvcCounter|count[8]~33COUT1_101\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(9),
	cout0 => \fvcCounter|count[9]~37\,
	cout1 => \fvcCounter|count[9]~37COUT1_103\);

-- Location: LC_X4_Y3_N4
\fvcCounter|count[10]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(10) = DFFEAS(\fvcCounter|count\(10) $ (((((!\fvcCounter|count[5]~21\ & \fvcCounter|count[9]~37\) # (\fvcCounter|count[5]~21\ & \fvcCounter|count[9]~37COUT1_103\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[10]~41\ = CARRY(((!\fvcCounter|count[9]~37COUT1_103\)) # (!\fvcCounter|count\(10)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(10),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[5]~21\,
	cin0 => \fvcCounter|count[9]~37\,
	cin1 => \fvcCounter|count[9]~37COUT1_103\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(10),
	cout => \fvcCounter|count[10]~41\);

-- Location: LC_X4_Y3_N5
\fvcCounter|count[11]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(11) = DFFEAS(\fvcCounter|count\(11) $ ((((!\fvcCounter|count[10]~41\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[11]~45\ = CARRY((\fvcCounter|count\(11) & ((!\fvcCounter|count[10]~41\))))
-- \fvcCounter|count[11]~45COUT1_105\ = CARRY((\fvcCounter|count\(11) & ((!\fvcCounter|count[10]~41\))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(11),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[10]~41\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(11),
	cout0 => \fvcCounter|count[11]~45\,
	cout1 => \fvcCounter|count[11]~45COUT1_105\);

-- Location: LC_X4_Y3_N6
\fvcCounter|count[12]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(12) = DFFEAS(\fvcCounter|count\(12) $ (((((!\fvcCounter|count[10]~41\ & \fvcCounter|count[11]~45\) # (\fvcCounter|count[10]~41\ & \fvcCounter|count[11]~45COUT1_105\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[12]~49\ = CARRY(((!\fvcCounter|count[11]~45\)) # (!\fvcCounter|count\(12)))
-- \fvcCounter|count[12]~49COUT1_107\ = CARRY(((!\fvcCounter|count[11]~45COUT1_105\)) # (!\fvcCounter|count\(12)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(12),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[10]~41\,
	cin0 => \fvcCounter|count[11]~45\,
	cin1 => \fvcCounter|count[11]~45COUT1_105\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(12),
	cout0 => \fvcCounter|count[12]~49\,
	cout1 => \fvcCounter|count[12]~49COUT1_107\);

-- Location: LC_X4_Y3_N7
\fvcCounter|count[13]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(13) = DFFEAS((\fvcCounter|count\(13) $ ((!(!\fvcCounter|count[10]~41\ & \fvcCounter|count[12]~49\) # (\fvcCounter|count[10]~41\ & \fvcCounter|count[12]~49COUT1_107\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[13]~53\ = CARRY(((\fvcCounter|count\(13) & !\fvcCounter|count[12]~49\)))
-- \fvcCounter|count[13]~53COUT1_109\ = CARRY(((\fvcCounter|count\(13) & !\fvcCounter|count[12]~49COUT1_107\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(13),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[10]~41\,
	cin0 => \fvcCounter|count[12]~49\,
	cin1 => \fvcCounter|count[12]~49COUT1_107\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(13),
	cout0 => \fvcCounter|count[13]~53\,
	cout1 => \fvcCounter|count[13]~53COUT1_109\);

-- Location: LC_X4_Y3_N8
\fvcCounter|count[14]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(14) = DFFEAS(\fvcCounter|count\(14) $ (((((!\fvcCounter|count[10]~41\ & \fvcCounter|count[13]~53\) # (\fvcCounter|count[10]~41\ & \fvcCounter|count[13]~53COUT1_109\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[14]~57\ = CARRY(((!\fvcCounter|count[13]~53\)) # (!\fvcCounter|count\(14)))
-- \fvcCounter|count[14]~57COUT1_111\ = CARRY(((!\fvcCounter|count[13]~53COUT1_109\)) # (!\fvcCounter|count\(14)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(14),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[10]~41\,
	cin0 => \fvcCounter|count[13]~53\,
	cin1 => \fvcCounter|count[13]~53COUT1_109\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(14),
	cout0 => \fvcCounter|count[14]~57\,
	cout1 => \fvcCounter|count[14]~57COUT1_111\);

-- Location: LC_X4_Y3_N9
\fvcCounter|count[15]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(15) = DFFEAS((\fvcCounter|count\(15) $ ((!(!\fvcCounter|count[10]~41\ & \fvcCounter|count[14]~57\) # (\fvcCounter|count[10]~41\ & \fvcCounter|count[14]~57COUT1_111\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[15]~61\ = CARRY(((\fvcCounter|count\(15) & !\fvcCounter|count[14]~57COUT1_111\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(15),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[10]~41\,
	cin0 => \fvcCounter|count[14]~57\,
	cin1 => \fvcCounter|count[14]~57COUT1_111\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(15),
	cout => \fvcCounter|count[15]~61\);

-- Location: LC_X5_Y3_N0
\fvcCounter|count[16]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(16) = DFFEAS((\fvcCounter|count\(16) $ ((\fvcCounter|count[15]~61\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[16]~1\ = CARRY(((!\fvcCounter|count[15]~61\) # (!\fvcCounter|count\(16))))
-- \fvcCounter|count[16]~1COUT1_113\ = CARRY(((!\fvcCounter|count[15]~61\) # (!\fvcCounter|count\(16))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(16),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[15]~61\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(16),
	cout0 => \fvcCounter|count[16]~1\,
	cout1 => \fvcCounter|count[16]~1COUT1_113\);

-- Location: LC_X7_Y3_N8
\fvcCountReg[0]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(0) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(0), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(0),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(0));

-- Location: LC_X7_Y3_N2
\fvcCountReg[16]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[0]~0\ = ((\wordSelect~combout\ & (fvcCountReg[16])) # (!\wordSelect~combout\ & ((fvcCountReg(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f3c0",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => \wordSelect~combout\,
	datac => \fvcCounter|count\(16),
	datad => fvcCountReg(0),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[0]~0\,
	regout => fvcCountReg(16));

-- Location: LC_X3_Y3_N0
\fvcCountReg[1]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(1) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(1), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(1),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(1));

-- Location: LC_X5_Y3_N1
\fvcCounter|count[17]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(17) = DFFEAS((\fvcCounter|count\(17) $ ((!(!\fvcCounter|count[15]~61\ & \fvcCounter|count[16]~1\) # (\fvcCounter|count[15]~61\ & \fvcCounter|count[16]~1COUT1_113\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[17]~3\ = CARRY(((\fvcCounter|count\(17) & !\fvcCounter|count[16]~1\)))
-- \fvcCounter|count[17]~3COUT1_115\ = CARRY(((\fvcCounter|count\(17) & !\fvcCounter|count[16]~1COUT1_113\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(17),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[15]~61\,
	cin0 => \fvcCounter|count[16]~1\,
	cin1 => \fvcCounter|count[16]~1COUT1_113\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(17),
	cout0 => \fvcCounter|count[17]~3\,
	cout1 => \fvcCounter|count[17]~3COUT1_115\);

-- Location: LC_X2_Y3_N0
\fvcCountReg[17]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[1]~1\ = ((\wordSelect~combout\ & ((fvcCountReg[17]))) # (!\wordSelect~combout\ & (fvcCountReg(1))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0aa",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	dataa => fvcCountReg(1),
	datac => \fvcCounter|count\(17),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[1]~1\,
	regout => fvcCountReg(17));

-- Location: LC_X3_Y3_N4
\fvcCountReg[2]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(2) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(2), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(2),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(2));

-- Location: LC_X5_Y3_N2
\fvcCounter|count[18]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(18) = DFFEAS((\fvcCounter|count\(18) $ (((!\fvcCounter|count[15]~61\ & \fvcCounter|count[17]~3\) # (\fvcCounter|count[15]~61\ & \fvcCounter|count[17]~3COUT1_115\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[18]~7\ = CARRY(((!\fvcCounter|count[17]~3\) # (!\fvcCounter|count\(18))))
-- \fvcCounter|count[18]~7COUT1_117\ = CARRY(((!\fvcCounter|count[17]~3COUT1_115\) # (!\fvcCounter|count\(18))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(18),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[15]~61\,
	cin0 => \fvcCounter|count[17]~3\,
	cin1 => \fvcCounter|count[17]~3COUT1_115\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(18),
	cout0 => \fvcCounter|count[18]~7\,
	cout1 => \fvcCounter|count[18]~7COUT1_117\);

-- Location: LC_X2_Y3_N3
\fvcCountReg[18]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[2]~2\ = ((\wordSelect~combout\ & ((fvcCountReg[18]))) # (!\wordSelect~combout\ & (fvcCountReg(2))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(2),
	datac => \fvcCounter|count\(18),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[2]~2\,
	regout => fvcCountReg(18));

-- Location: LC_X3_Y3_N2
\fvcCountReg[3]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(3) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(3), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(3),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(3));

-- Location: LC_X5_Y3_N3
\fvcCounter|count[19]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(19) = DFFEAS(\fvcCounter|count\(19) $ ((((!(!\fvcCounter|count[15]~61\ & \fvcCounter|count[18]~7\) # (\fvcCounter|count[15]~61\ & \fvcCounter|count[18]~7COUT1_117\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[19]~11\ = CARRY((\fvcCounter|count\(19) & ((!\fvcCounter|count[18]~7\))))
-- \fvcCounter|count[19]~11COUT1_119\ = CARRY((\fvcCounter|count\(19) & ((!\fvcCounter|count[18]~7COUT1_117\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(19),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[15]~61\,
	cin0 => \fvcCounter|count[18]~7\,
	cin1 => \fvcCounter|count[18]~7COUT1_117\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(19),
	cout0 => \fvcCounter|count[19]~11\,
	cout1 => \fvcCounter|count[19]~11COUT1_119\);

-- Location: LC_X2_Y3_N5
\fvcCountReg[19]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[3]~3\ = ((\wordSelect~combout\ & ((fvcCountReg[19]))) # (!\wordSelect~combout\ & (fvcCountReg(3))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(3),
	datac => \fvcCounter|count\(19),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[3]~3\,
	regout => fvcCountReg(19));

-- Location: LC_X3_Y3_N1
\fvcCountReg[4]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(4) = DFFEAS((((\fvcCounter|count\(4)))), GLOBAL(\eq~regout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datad => \fvcCounter|count\(4),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(4));

-- Location: LC_X5_Y3_N4
\fvcCounter|count[20]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(20) = DFFEAS(\fvcCounter|count\(20) $ (((((!\fvcCounter|count[15]~61\ & \fvcCounter|count[19]~11\) # (\fvcCounter|count[15]~61\ & \fvcCounter|count[19]~11COUT1_119\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[20]~15\ = CARRY(((!\fvcCounter|count[19]~11COUT1_119\)) # (!\fvcCounter|count\(20)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(20),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[15]~61\,
	cin0 => \fvcCounter|count[19]~11\,
	cin1 => \fvcCounter|count[19]~11COUT1_119\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(20),
	cout => \fvcCounter|count[20]~15\);

-- Location: LC_X7_Y3_N6
\fvcCountReg[20]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[4]~4\ = ((\wordSelect~combout\ & ((fvcCountReg[20]))) # (!\wordSelect~combout\ & (fvcCountReg(4))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(4),
	datac => \fvcCounter|count\(20),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[4]~4\,
	regout => fvcCountReg(20));

-- Location: LC_X3_Y3_N3
\fvcCountReg[5]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(5) = DFFEAS((((\fvcCounter|count\(5)))), GLOBAL(\eq~regout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datad => \fvcCounter|count\(5),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(5));

-- Location: LC_X5_Y3_N5
\fvcCounter|count[21]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(21) = DFFEAS(\fvcCounter|count\(21) $ ((((!\fvcCounter|count[20]~15\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[21]~19\ = CARRY((\fvcCounter|count\(21) & ((!\fvcCounter|count[20]~15\))))
-- \fvcCounter|count[21]~19COUT1_121\ = CARRY((\fvcCounter|count\(21) & ((!\fvcCounter|count[20]~15\))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(21),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[20]~15\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(21),
	cout0 => \fvcCounter|count[21]~19\,
	cout1 => \fvcCounter|count[21]~19COUT1_121\);

-- Location: LC_X7_Y3_N5
\fvcCountReg[21]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[5]~5\ = ((\wordSelect~combout\ & ((fvcCountReg[21]))) # (!\wordSelect~combout\ & (fvcCountReg(5))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(5),
	datac => \fvcCounter|count\(21),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[5]~5\,
	regout => fvcCountReg(21));

-- Location: LC_X2_Y3_N9
\fvcCountReg[6]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(6) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(6), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(6),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(6));

-- Location: LC_X5_Y3_N6
\fvcCounter|count[22]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(22) = DFFEAS(\fvcCounter|count\(22) $ (((((!\fvcCounter|count[20]~15\ & \fvcCounter|count[21]~19\) # (\fvcCounter|count[20]~15\ & \fvcCounter|count[21]~19COUT1_121\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[22]~23\ = CARRY(((!\fvcCounter|count[21]~19\)) # (!\fvcCounter|count\(22)))
-- \fvcCounter|count[22]~23COUT1_123\ = CARRY(((!\fvcCounter|count[21]~19COUT1_121\)) # (!\fvcCounter|count\(22)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(22),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[20]~15\,
	cin0 => \fvcCounter|count[21]~19\,
	cin1 => \fvcCounter|count[21]~19COUT1_121\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(22),
	cout0 => \fvcCounter|count[22]~23\,
	cout1 => \fvcCounter|count[22]~23COUT1_123\);

-- Location: LC_X7_Y3_N3
\fvcCountReg[22]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[6]~6\ = ((\wordSelect~combout\ & ((fvcCountReg[22]))) # (!\wordSelect~combout\ & (fvcCountReg(6))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(6),
	datac => \fvcCounter|count\(22),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[6]~6\,
	regout => fvcCountReg(22));

-- Location: LC_X2_Y3_N1
\fvcCountReg[7]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(7) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(7), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(7),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(7));

-- Location: LC_X5_Y3_N7
\fvcCounter|count[23]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(23) = DFFEAS((\fvcCounter|count\(23) $ ((!(!\fvcCounter|count[20]~15\ & \fvcCounter|count[22]~23\) # (\fvcCounter|count[20]~15\ & \fvcCounter|count[22]~23COUT1_123\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[23]~27\ = CARRY(((\fvcCounter|count\(23) & !\fvcCounter|count[22]~23\)))
-- \fvcCounter|count[23]~27COUT1_125\ = CARRY(((\fvcCounter|count\(23) & !\fvcCounter|count[22]~23COUT1_123\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(23),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[20]~15\,
	cin0 => \fvcCounter|count[22]~23\,
	cin1 => \fvcCounter|count[22]~23COUT1_123\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(23),
	cout0 => \fvcCounter|count[23]~27\,
	cout1 => \fvcCounter|count[23]~27COUT1_125\);

-- Location: LC_X2_Y3_N4
\fvcCountReg[23]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[7]~7\ = ((\wordSelect~combout\ & ((fvcCountReg[23]))) # (!\wordSelect~combout\ & (fvcCountReg(7))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(7),
	datac => \fvcCounter|count\(23),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[7]~7\,
	regout => fvcCountReg(23));

-- Location: LC_X2_Y3_N7
\fvcCountReg[8]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(8) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(8), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(8),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(8));

-- Location: LC_X5_Y3_N8
\fvcCounter|count[24]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(24) = DFFEAS(\fvcCounter|count\(24) $ (((((!\fvcCounter|count[20]~15\ & \fvcCounter|count[23]~27\) # (\fvcCounter|count[20]~15\ & \fvcCounter|count[23]~27COUT1_125\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[24]~31\ = CARRY(((!\fvcCounter|count[23]~27\)) # (!\fvcCounter|count\(24)))
-- \fvcCounter|count[24]~31COUT1_127\ = CARRY(((!\fvcCounter|count[23]~27COUT1_125\)) # (!\fvcCounter|count\(24)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(24),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[20]~15\,
	cin0 => \fvcCounter|count[23]~27\,
	cin1 => \fvcCounter|count[23]~27COUT1_125\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(24),
	cout0 => \fvcCounter|count[24]~31\,
	cout1 => \fvcCounter|count[24]~31COUT1_127\);

-- Location: LC_X2_Y3_N6
\fvcCountReg[24]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[8]~8\ = ((\wordSelect~combout\ & ((fvcCountReg[24]))) # (!\wordSelect~combout\ & (fvcCountReg(8))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(8),
	datac => \fvcCounter|count\(24),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[8]~8\,
	regout => fvcCountReg(24));

-- Location: LC_X2_Y3_N2
\fvcCountReg[9]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(9) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(9), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(9),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(9));

-- Location: LC_X5_Y3_N9
\fvcCounter|count[25]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(25) = DFFEAS((\fvcCounter|count\(25) $ ((!(!\fvcCounter|count[20]~15\ & \fvcCounter|count[24]~31\) # (\fvcCounter|count[20]~15\ & \fvcCounter|count[24]~31COUT1_127\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[25]~35\ = CARRY(((\fvcCounter|count\(25) & !\fvcCounter|count[24]~31COUT1_127\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(25),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[20]~15\,
	cin0 => \fvcCounter|count[24]~31\,
	cin1 => \fvcCounter|count[24]~31COUT1_127\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(25),
	cout => \fvcCounter|count[25]~35\);

-- Location: LC_X2_Y3_N8
\fvcCountReg[25]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[9]~9\ = ((\wordSelect~combout\ & ((fvcCountReg[25]))) # (!\wordSelect~combout\ & (fvcCountReg(9))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(9),
	datac => \fvcCounter|count\(25),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[9]~9\,
	regout => fvcCountReg(25));

-- Location: LC_X5_Y1_N2
\fvcCountReg[10]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(10) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(10), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(10),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(10));

-- Location: LC_X6_Y3_N0
\fvcCounter|count[26]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(26) = DFFEAS((\fvcCounter|count\(26) $ ((\fvcCounter|count[25]~35\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[26]~39\ = CARRY(((!\fvcCounter|count[25]~35\) # (!\fvcCounter|count\(26))))
-- \fvcCounter|count[26]~39COUT1_129\ = CARRY(((!\fvcCounter|count[25]~35\) # (!\fvcCounter|count\(26))))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(26),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[25]~35\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(26),
	cout0 => \fvcCounter|count[26]~39\,
	cout1 => \fvcCounter|count[26]~39COUT1_129\);

-- Location: LC_X6_Y3_N9
\fvcCountReg[26]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[10]~10\ = ((\wordSelect~combout\ & ((fvcCountReg[26]))) # (!\wordSelect~combout\ & (fvcCountReg(10))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0aa",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	dataa => fvcCountReg(10),
	datac => \fvcCounter|count\(26),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[10]~10\,
	regout => fvcCountReg(26));

-- Location: LC_X6_Y3_N1
\fvcCounter|count[27]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(27) = DFFEAS((\fvcCounter|count\(27) $ ((!(!\fvcCounter|count[25]~35\ & \fvcCounter|count[26]~39\) # (\fvcCounter|count[25]~35\ & \fvcCounter|count[26]~39COUT1_129\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[27]~43\ = CARRY(((\fvcCounter|count\(27) & !\fvcCounter|count[26]~39\)))
-- \fvcCounter|count[27]~43COUT1_131\ = CARRY(((\fvcCounter|count\(27) & !\fvcCounter|count[26]~39COUT1_129\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(27),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[25]~35\,
	cin0 => \fvcCounter|count[26]~39\,
	cin1 => \fvcCounter|count[26]~39COUT1_129\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(27),
	cout0 => \fvcCounter|count[27]~43\,
	cout1 => \fvcCounter|count[27]~43COUT1_131\);

-- Location: LC_X7_Y3_N9
\fvcCountReg[11]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(11) = DFFEAS((((\fvcCounter|count\(11)))), GLOBAL(\eq~regout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datad => \fvcCounter|count\(11),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(11));

-- Location: LC_X7_Y3_N0
\fvcCountReg[27]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[11]~11\ = ((\wordSelect~combout\ & (fvcCountReg[27])) # (!\wordSelect~combout\ & ((fvcCountReg(11)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f3c0",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => \wordSelect~combout\,
	datac => \fvcCounter|count\(27),
	datad => fvcCountReg(11),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[11]~11\,
	regout => fvcCountReg(27));

-- Location: LC_X6_Y3_N2
\fvcCounter|count[28]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(28) = DFFEAS((\fvcCounter|count\(28) $ (((!\fvcCounter|count[25]~35\ & \fvcCounter|count[27]~43\) # (\fvcCounter|count[25]~35\ & \fvcCounter|count[27]~43COUT1_131\)))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[28]~47\ = CARRY(((!\fvcCounter|count[27]~43\) # (!\fvcCounter|count\(28))))
-- \fvcCounter|count[28]~47COUT1_133\ = CARRY(((!\fvcCounter|count[27]~43COUT1_131\) # (!\fvcCounter|count\(28))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	datab => \fvcCounter|count\(28),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[25]~35\,
	cin0 => \fvcCounter|count[27]~43\,
	cin1 => \fvcCounter|count[27]~43COUT1_131\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(28),
	cout0 => \fvcCounter|count[28]~47\,
	cout1 => \fvcCounter|count[28]~47COUT1_133\);

-- Location: LC_X7_Y3_N1
\fvcCountReg[12]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(12) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(12), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(12),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(12));

-- Location: LC_X7_Y3_N4
\fvcCountReg[28]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[12]~12\ = ((\wordSelect~combout\ & (fvcCountReg[28])) # (!\wordSelect~combout\ & ((fvcCountReg(12)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f3c0",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => \wordSelect~combout\,
	datac => \fvcCounter|count\(28),
	datad => fvcCountReg(12),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[12]~12\,
	regout => fvcCountReg(28));

-- Location: LC_X5_Y1_N5
\fvcCountReg[13]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(13) = DFFEAS((((\fvcCounter|count\(13)))), GLOBAL(\eq~regout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datad => \fvcCounter|count\(13),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(13));

-- Location: LC_X6_Y3_N3
\fvcCounter|count[29]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(29) = DFFEAS(\fvcCounter|count\(29) $ ((((!(!\fvcCounter|count[25]~35\ & \fvcCounter|count[28]~47\) # (\fvcCounter|count[25]~35\ & \fvcCounter|count[28]~47COUT1_133\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[29]~51\ = CARRY((\fvcCounter|count\(29) & ((!\fvcCounter|count[28]~47\))))
-- \fvcCounter|count[29]~51COUT1_135\ = CARRY((\fvcCounter|count\(29) & ((!\fvcCounter|count[28]~47COUT1_133\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(29),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[25]~35\,
	cin0 => \fvcCounter|count[28]~47\,
	cin1 => \fvcCounter|count[28]~47COUT1_133\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(29),
	cout0 => \fvcCounter|count[29]~51\,
	cout1 => \fvcCounter|count[29]~51COUT1_135\);

-- Location: LC_X6_Y3_N6
\fvcCountReg[29]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[13]~13\ = ((\wordSelect~combout\ & ((fvcCountReg[29]))) # (!\wordSelect~combout\ & (fvcCountReg(13))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0aa",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	dataa => fvcCountReg(13),
	datac => \fvcCounter|count\(29),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[13]~13\,
	regout => fvcCountReg(29));

-- Location: LC_X4_Y2_N0
\fvcCountReg[14]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(14) = DFFEAS(GND, GLOBAL(\eq~regout\), VCC, , , \fvcCounter|count\(14), , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datac => \fvcCounter|count\(14),
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(14));

-- Location: LC_X6_Y3_N4
\fvcCounter|count[30]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(30) = DFFEAS(\fvcCounter|count\(30) $ (((((!\fvcCounter|count[25]~35\ & \fvcCounter|count[29]~51\) # (\fvcCounter|count[25]~35\ & \fvcCounter|count[29]~51COUT1_135\))))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )
-- \fvcCounter|count[30]~55\ = CARRY(((!\fvcCounter|count[29]~51COUT1_135\)) # (!\fvcCounter|count\(30)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	dataa => \fvcCounter|count\(30),
	aclr => \rst~combout\,
	cin => \fvcCounter|count[25]~35\,
	cin0 => \fvcCounter|count[29]~51\,
	cin1 => \fvcCounter|count[29]~51COUT1_135\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(30),
	cout => \fvcCounter|count[30]~55\);

-- Location: LC_X6_Y3_N7
\fvcCountReg[30]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[14]~14\ = ((\wordSelect~combout\ & ((fvcCountReg[30]))) # (!\wordSelect~combout\ & (fvcCountReg(14))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(14),
	datac => \fvcCounter|count\(30),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[14]~14\,
	regout => fvcCountReg(30));

-- Location: LC_X5_Y1_N0
\fvcCountReg[15]\ : maxv_lcell
-- Equation(s):
-- fvcCountReg(15) = DFFEAS((((\fvcCounter|count\(15)))), GLOBAL(\eq~regout\), VCC, , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "ff00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datad => \fvcCounter|count\(15),
	aclr => GND,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => fvcCountReg(15));

-- Location: LC_X6_Y3_N5
\fvcCounter|count[31]\ : maxv_lcell
-- Equation(s):
-- \fvcCounter|count\(31) = DFFEAS((((!\fvcCounter|count[30]~55\))), GLOBAL(\fvcIn~combout\), !\rst~combout\, , , , , , )

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "0f0f",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \fvcIn~combout\,
	aclr => \rst~combout\,
	cin => \fvcCounter|count[30]~55\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \fvcCounter|count\(31));

-- Location: LC_X6_Y3_N8
\fvcCountReg[31]\ : maxv_lcell
-- Equation(s):
-- \wordMux|outVal[15]~15\ = ((\wordSelect~combout\ & ((fvcCountReg[31]))) # (!\wordSelect~combout\ & (fvcCountReg(15))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f0cc",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \eq~regout\,
	datab => fvcCountReg(15),
	datac => \fvcCounter|count\(31),
	datad => \wordSelect~combout\,
	aclr => GND,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \wordMux|outVal[15]~15\,
	regout => fvcCountReg(31));

-- Location: PIN_33,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\flgOut[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \flgs|reg\(0),
	oe => VCC,
	padio => ww_flgOut(0));

-- Location: PIN_30,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\flgOut[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \flgs|reg\(1),
	oe => VCC,
	padio => ww_flgOut(1));

-- Location: PIN_29,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\flgOut[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \flgs|reg\(2),
	oe => VCC,
	padio => ww_flgOut(2));

-- Location: PIN_28,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\flgOut[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \flgs|reg\(3),
	oe => VCC,
	padio => ww_flgOut(3));

-- Location: PIN_27,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\flgOut[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \flgs|reg\(4),
	oe => VCC,
	padio => ww_flgOut(4));

-- Location: PIN_26,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\flgOut[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \flgs|reg\(5),
	oe => VCC,
	padio => ww_flgOut(5));

-- Location: PIN_49,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\output~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \eq~regout\,
	oe => VCC,
	padio => ww_output);

-- Location: PIN_50,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\loaded~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \Equal0~1_combout\,
	oe => VCC,
	padio => ww_loaded);

-- Location: PIN_74,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[0]~0\,
	oe => VCC,
	padio => ww_dataOut(0));

-- Location: PIN_73,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[1]~1\,
	oe => VCC,
	padio => ww_dataOut(1));

-- Location: PIN_72,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[2]~2\,
	oe => VCC,
	padio => ww_dataOut(2));

-- Location: PIN_71,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[3]~3\,
	oe => VCC,
	padio => ww_dataOut(3));

-- Location: PIN_70,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[4]~4\,
	oe => VCC,
	padio => ww_dataOut(4));

-- Location: PIN_69,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[5]~5\,
	oe => VCC,
	padio => ww_dataOut(5));

-- Location: PIN_68,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[6]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[6]~6\,
	oe => VCC,
	padio => ww_dataOut(6));

-- Location: PIN_67,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[7]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[7]~7\,
	oe => VCC,
	padio => ww_dataOut(7));

-- Location: PIN_66,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[8]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[8]~8\,
	oe => VCC,
	padio => ww_dataOut(8));

-- Location: PIN_64,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[9]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[9]~9\,
	oe => VCC,
	padio => ww_dataOut(9));

-- Location: PIN_61,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[10]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[10]~10\,
	oe => VCC,
	padio => ww_dataOut(10));

-- Location: PIN_58,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[11]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[11]~11\,
	oe => VCC,
	padio => ww_dataOut(11));

-- Location: PIN_57,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[12]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[12]~12\,
	oe => VCC,
	padio => ww_dataOut(12));

-- Location: PIN_56,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[13]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[13]~13\,
	oe => VCC,
	padio => ww_dataOut(13));

-- Location: PIN_55,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[14]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[14]~14\,
	oe => VCC,
	padio => ww_dataOut(14));

-- Location: PIN_54,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\dataOut[15]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \wordMux|outVal[15]~15\,
	oe => VCC,
	padio => ww_dataOut(15));
END structure;


