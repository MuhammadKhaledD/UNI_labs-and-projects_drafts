library ieee;
use ieee.std_logic_1164.all;

ENTITY partD IS
GENERIC(N: integer := 16);
	PORT(
		A: IN std_logic_vector (N-1 DOWNTO 0);
		Cin: IN std_logic;
		S: IN std_logic_vector (1 DOWNTO 0);
		F: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic
	);
END partD;

ARCHITECTURE archpartD OF partD IS

COMPONENT mux4 IS
	PORT(
		in0,in1,in2,in3: IN std_logic_vector (N-1 DOWNTO 0);
		s: IN std_logic_vector(1 DOWNTO 0);
		out1: OUT std_logic_vector(N-1 DOWNTO 0)
	);
END COMPONENT;

SIGNAL x0,x1,x2,x3: std_logic_vector (N-1 DOWNTO 0);

BEGIN
	x0 <= A(N-2 DOWNTO 0) & '0';
	x1 <= A(N-2 DOWNTO 0) & A(N-1);
	x2 <= A(N-2 DOWNTO 0) & Cin;
	x3 <= (OTHERS => '0'); -- it was written like this which is not generic x3 <= "0000000000000000";
	u0: mux4 GENERIC MAP (N) PORT MAP (x0,x1,x2,x3,S,F);
	COUT <= '0' WHEN S(0) = '1' AND S(1) = '1'
	ELSE  A(N-1);


END archpartD;
