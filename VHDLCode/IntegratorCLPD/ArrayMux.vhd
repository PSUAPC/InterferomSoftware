LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
use IEEE.numeric_std.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

entity ArrayMux is
generic (N : integer);
port(
	inA: in std_logic_vector(N-1 downto 0);
	inB: in std_logic_vector(N-1 downto 0);
	sel : in std_logic;
	
	outVal : out std_logic_vector(N-1 downto 0)
 );
end entity ArrayMux;

architecture RTL of ArrayMux is

signal reg : std_logic_vector(N-1 downto 0);
begin

	process( sel, inA, inB )
	begin
		if( sel = '1' ) then
			outVal <= inB;
		else
			outVal <= inA;
		end if;
	end process;

end architecture RTL;