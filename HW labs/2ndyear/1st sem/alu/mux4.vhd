library ieee;
use ieee.std_logic_1164.all;

ENTITY mux4 IS
GENERIC (N: integer:= 16);
	PORT(in0,in1,in2,in3: IN std_logic_vector (N-1 DOWNTO 0);
		s: IN std_logic_vector(1 DOWNTO 0);
		out1: OUT std_logic_vector(N-1 DOWNTO 0));
END mux4;


ARCHITECTURE arch1 OF mux4 IS
BEGIN
	out1 <= in0 WHEN s(1) = '0' AND s(0) = '0'
	ELSE in1 WHEN s(1) = '0' AND s(0) = '1'
	ELSE in2 WHEN s(1) = '1' AND s(0) = '0'
	ELSE in3;

END arch1;	
