LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
use IEEE.numeric_std.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

entity TopLevelMux is
port(
 -- port mux
  sel : in std_logic;
  dataB : in std_logic_vector(15 downto 0);
  aux0 : out std_logic;
  aux1 : out std_logic;
  aux2 : out std_logic;

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
end entity TopLevelMux;

component IntegratorCLPD is
port(
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
end component IntegratorCLPD;

component ArrayMux is
generic (N : integer);
port(
	inA: in std_logic_vector(N-1 downto 0);
	inB: in std_logic_vector(N-1 downto 0);
	sel : in std_logic;
	
	outVal : out std_logic_vector(N-1 downto 0)
 );
end component ArrayMux;

signal tlatch : std_logic;
signal tdataIn : std_logic;
signal tWordSel : std_logic;
signal tdatOut : std_logic_vector(15 downto 0);

architecture RTL of TopLevelMux is

	auxMux : process (sel)
	begin
		if( sel = '0' ) then
			tlatch <= latch;
			tdataIn <= dataIn;
			tWordSel <= wordSelect;
		else
			aux0 <= latch;
			aux1 <= dataIn;
			aux2 <= wordSelect;
		end if;
	end process;
	
	sigMux : ArrayMux generic map( N => 16 ) port map( inA => tdatOut, inB => dataB, sel => sel);
	
	integ : IntegratorCLPD port map( )

end architecture RTL;