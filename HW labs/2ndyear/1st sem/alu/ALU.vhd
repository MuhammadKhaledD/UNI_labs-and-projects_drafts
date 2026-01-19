library ieee;
use ieee.std_logic_1164.all;

ENTITY ALU IS
GENERIC(N : integer := 16);
	PORT(
		A,B: IN std_logic_vector (N-1 DOWNTO 0);
		S: IN std_logic_vector (3 DOWNTO 0);
		Cin: IN std_logic;
		F: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic
	);
END ALU;

ARCHITECTURE archALU OF ALU IS

COMPONENT mux4 IS
	PORT(
		in0,in1,in2,in3: IN std_logic_vector (N-1 DOWNTO 0);
		s: IN std_logic_vector(1 DOWNTO 0);
		out1: OUT std_logic_vector(N-1 DOWNTO 0)
	);
END COMPONENT;

COMPONENT partA IS
	PORT (
		A,B: IN std_logic_vector (N-1 DOWNTO 0);
		S: IN std_logic_vector (1 DOWNTO 0);
		cin: IN std_logic;
		F: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic
	);
END COMPONENT;

COMPONENT partB IS
	PORT(
		A,B: IN std_logic_vector (N-1 DOWNTO 0);
		S: IN std_logic_vector (1 DOWNTO 0);
		F: OUT std_logic_vector (N-1 DOWNTO 0)
	);
END COMPONENT;

COMPONENT partC IS
	PORT(
		A: IN std_logic_vector (N-1 DOWNTO 0);
		Cin: IN std_logic;
		S: IN std_logic_vector (1 DOWNTO 0);
		F: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic
	);
END COMPONENT;

COMPONENT partD IS
	PORT(
		A: IN std_logic_vector (N-1 DOWNTO 0);
		Cin: IN std_logic;
		S: IN std_logic_vector (1 DOWNTO 0);
		F: OUT std_logic_vector (N-1 DOWNTO 0);
		Cout: OUT std_logic
	);
END COMPONENT;

SIGNAL x0,x1,x2,x3: std_logic_vector (N-1 DOWNTO 0);
SIGNAL y0,y1, y2: std_logic;

BEGIN
	u0: partA GENERIC MAP (N) PORT MAP (A, B, S(1 DOWNTO 0), Cin, x0, y2);
	u1: partB GENERIC MAP (N) PORT MAP (A,B,S(1 DOWNTO 0),x1);
	u2: partC GENERIC MAP (N) PORT MAP (A,Cin,S(1 DOWNTO 0),x2,y0);
	u3: partD GENERIC MAP (N) PORT MAP (A,Cin,S(1 DOWNTO 0),x3,y1);
	u4: mux4 GENERIC MAP (N) PORT MAP (x0,x1,x2,x3,S(3 DOWNTO 2),F);
	Cout <= y0 WHEN S(3) = '1' AND S(2) = '0' 
	ELSE y1 WHEN S(3) = '1' AND S(2) = '1'
	ELSE y2 WHEN S(3) = '0' AND S(2) = '0'
	ELSE 'U';

END archALU;