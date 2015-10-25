LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
use IEEE.numeric_std.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

entity Counter is
generic (N : integer);
port(
 -- comparison variables
 pulse : in std_logic;
 reset : in std_logic;
 
 data : out std_logic_vector(N-1 downto 0)
 );
end entity Counter;

architecture RTL of Counter is

signal count : std_logic_vector(N-1 downto 0) :=  (others =>'0');


begin
	-- count process
	process(pulse,reset)
		variable tempCount : integer := 0;
	begin
		if( reset = '1' ) then
			-- clear the count
			count <= (others => '0');
		elsif( rising_edge(pulse) ) then
			-- increment the count
			tempCount := to_integer(unsigned(count));
			tempCount := tempCount + 1;
			count <= std_logic_vector(to_unsigned(tempCount,N));
		end if;
	
	end process;
	data <= count;
	
end architecture RTL;