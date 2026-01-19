library ieee;
use ieee.std_logic_1164.all;

ENTITY partC IS
GENERIC(N: integer := 16);
	PORT(A: IN std_logic_vector (N-1 DOWNTO 0);
		Cin: IN std_logic;
		S: IN std_logic_vector (1 DOWNTO 0);
		F: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic);
END partC;

ARCHITECTURE archpartC OF partC IS

COMPONENT mux4 IS
	PORT(in0,in1,in2,in3: IN std_logic_vector (N-1 DOWNTO 0);
		s: IN std_logic_vector(1 DOWNTO 0);
		out1: OUT std_logic_vector(N-1 DOWNTO 0));
END COMPONENT;

SIGNAL x0,x1,x2,x3: std_logic_vector (N-1 DOWNTO 0);

BEGIN
	x0 <=  '0' & A(N-1 DOWNTO 1);
	x1 <= A(0) & A(N-1 DOWNTO 1);
	x2 <= Cin & A(N-1 DOWNTO 1);
	x3 <= A(N-1) & A(N-1 DOWNTO 1);
	u0: mux4 GENERIC MAP (N) PORT MAP (x0,x1,x2,x3,S,F);
	Cout <= A(0);


END archpartC;