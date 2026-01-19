library ieee;
use ieee.std_logic_1164.all;

ENTITY fullAdder IS
GENERIC (N : integer := 16);
	PORT(
		A,B: IN std_logic_vector (N-1 DOWNTO 0);
		S, Cin: IN std_logic;			-- S  = 0 add S = 1 sub
		R: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic

	);
END fullAdder;


ARCHITECTURE archFullAdder OF fullAdder IS
COMPONENT adder IS
	PORT(
		A, B, S, Cin: IN std_logic;    	 	-- S  = 0 add S = 1 sub
		R, Cout: OUT std_logic
	);
END COMPONENT;
SIGNAL temp : std_logic_vector(N DOWNTO 0);
BEGIN

	temp(0) <= Cin;
 	loop1: FOR i IN 0 TO N-1 GENERATE
 		fx: adder PORT MAP(A(i), B(i), S, temp(i), R(i), temp(i+1));
 	END GENERATE;
 	Cout <= temp(N);

END archFullAdder;	
