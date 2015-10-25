LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
use IEEE.numeric_std.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

entity ShiftRegister is
generic (N : integer);
port(
	input: in std_logic;
	latch: in std_logic;
	data : out std_logic_vector(N-1 downto 0)
 );
end entity ShiftRegister;

architecture RTL of ShiftRegister is

signal reg : std_logic_vector(N-1 downto 0);
begin

	-- shifting process
	shifter: process(latch)
	begin
	
		if( rising_edge(latch) ) then
			-- shift the bits
			for i in 0 to N-2 loop
				reg(i+1) <= reg(i);
			end loop;
			
			-- assign the data value
			reg(0) <= input;
			
		end if;
	end process;
	
	-- assign the output
	data <= reg;
	
end architecture RTL;