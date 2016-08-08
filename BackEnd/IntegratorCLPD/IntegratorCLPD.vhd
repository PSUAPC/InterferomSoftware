LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
use IEEE.numeric_std.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

entity IntegratorCLPD is
port(

 -- flag variables
 clrReg : in std_logic;
 flgIn : in std_logic_vector(5 downto 0);
 flgOut : out std_logic_vector(5 downto 0);
 
 -- comparison variables
 pulse : in std_logic;
 latch : in std_logic;
 dataIn : in std_logic;
 output : out std_logic;
 loaded : out std_logic;
 
 -- count variables
 fvcIn : in std_logic;
 wordSelect : in std_logic;
 dataOut : out std_logic_vector(15 downto 0)
 
 
 );
end entity IntegratorCLPD;
architecture RTL of IntegratorCLPD is
--Signals and components go here
component Counter is
generic (N : integer);
port(
 -- comparison variables
 pulse : in std_logic;
 reset : in std_logic;
 
 data : out std_logic_vector(N-1 downto 0)
 );
end component Counter;

component ShiftRegister is
generic (N : integer);
port(
	input: in std_logic;
	latch: in std_logic;
	data : out std_logic_vector(N-1 downto 0)
 );
end component ShiftRegister;

component ArrayMux is
generic (N : integer);
port(
	inA: in std_logic_vector(N-1 downto 0);
	inB: in std_logic_vector(N-1 downto 0);
	sel : in std_logic;
	
	outVal : out std_logic_vector(N-1 downto 0)
 );
end component ArrayMux;

component FlagRegister is
generic (N : integer);
port(
 -- comparison variables
 clk : in std_logic;
 reset : in std_logic;
 regIn : in std_logic_vector(N-1 downto 0);
 
 regOut : out std_logic_vector(N-1 downto 0)
 );
end component FlagRegister;

signal compareRegister : std_logic_vector(31 downto 0);
signal cycleCount : std_logic_vector(31 downto 0);
signal fvcCount : std_logic_vector(31 downto 0);
signal fvcCountReg : std_logic_vector(31 downto 0);
signal bitCount : std_logic_vector(4 downto 0) := "00000";
signal eq : std_logic;
signal teq : std_logic;
signal rst : std_logic;

begin

   -- enable reset of counters on integration time change
   rst <= eq or latch;
  
	-- instantiate the counters
	fvcCounter : Counter generic map (N => 32) port map( pulse => fvcIn, reset => rst, data => fvcCount);
	cycleCounter : Counter generic map (N => 32) port map( pulse => pulse, reset => rst, data => cycleCount);
	shiftCounter : Counter generic map (N => 5) port map( pulse => latch, reset=>'0', data=> bitCount);
	
	-- instantiate the shift register
	shiftReg : ShiftRegister generic map (N => 32) port map( input => dataIn, latch => latch, data => compareRegister);
	
	-- instantiate the mux for the upper / lower word
	wordMux : ArrayMux generic map( N => 16) port map( inA => fvcCountReg(15 downto 0), inB => fvcCountReg(31 downto 16), 
																			sel => wordSelect, outVal => dataOut);
																			
	-- instantiate the glag register
	flgs : FlagRegister generic map( N => 6 ) port map( clk => pulse, reset => clrReg, regIn => flgIn, regOut => flgOut );
	-- integeration time latching
	intTimeSet: process(bitCount) 
	begin		
		-- loaded flag
		 if( bitCount = "11111" ) then
			 loaded <= '1';
		 else
			 loaded <= '0';
		 end if;
			 
	end process;
	
	-- process to check for equality
	eqCheck: process( cycleCount, compareRegister )
	
	begin
		if( cycleCount = compareRegister ) then
			teq <= '1';
		else
			teq <= '0';
		end if;
		
	end process;
	
	-- process to latch the count register
	countLatch: process ( eq )
	begin
	
		if( rising_edge( eq ) ) then
			fvcCountReg <= fvcCount;
		end if;
		
	end process;
	
	-- process for eq latching
	eqLatch: process(pulse)
	begin
	
		if( rising_edge(pulse) ) then
			eq <= teq;
		end if;
			
	end process;
	
	-- link the eq and output
	output <= eq;
	
end architecture RTL;