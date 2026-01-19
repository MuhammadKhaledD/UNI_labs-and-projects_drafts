library ieee;
use ieee.std_logic_1164.all;

ENTITY partB IS
GENERIc(N: integer :=16);
	PORT(A,B: IN std_logic_vector (N-1 DOWNTO 0);
		S: IN std_logic_vector (1 DOWNTO 0);
		F: OUT std_logic_vector (N-1 DOWNTO 0));
END partB;

ARCHITECTURE archpartB OF partB IS

COMPONENT mux4 IS
	PORT(in0,in1,in2,in3: IN std_logic_vector (N-1 DOWNTO 0);
		s: IN std_logic_vector(1 DOWNTO 0);
		out1: OUT std_logic_vector(N-1 DOWNTO 0));
END COMPONENT;

SIGNAL x0,x1,x2,x3: std_logic_vector (N-1 DOWNTO 0);

BEGIN
	x0 <= A and B;
	x1 <= A or B;
	x2 <= A xor B;
	x3 <= not A;
	u0: mux4 GENERIC MAP (N) PORT MAP (x0,x1,x2,x3,S,F);
	

END archpartB;
