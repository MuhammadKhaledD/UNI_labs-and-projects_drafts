library ieee;
use ieee.std_logic_1164.all;
use IEEE.numeric_std.all;

ENTITY RegFileMemArray IS PORT (
	clk,rst,we: IN std_logic;
	RAddress1,RAddress2,WAddress: IN std_logic_vector (2 DOWNTO 0);
	writePort: IN std_logic_vector (7 DOWNTO 0);
	readPort1,readPort2: OUT std_logic_vector (7 DOWNTO 0));
END ENTITY RegFileMemArray;

Architecture arch1 OF RegFileMemArray IS 
	TYPE reg_file_type IS ARRAY(0 TO 7) OF std_logic_vector(7 DOWNTO 0);
	SIGNAL regfile : reg_file_type;
BEGIN
	PROCESS(clk) IS
	BEGIN
	IF rising_edge(clk)  THEN
		IF rst = '1'  THEN
		 	FOR i IN 0 TO 7 loop
		 		regfile(i) <= (OTHERS => '0');
		 	END loop;
		 	readPort1 <= (OTHERS => '0');
		 	readPort2 <= (OTHERS => '0');
		ELSE
			readPort1 <= regfile(to_integer(unsigned(RAddress1)));
			readPort2 <= regfile(to_integer(unsigned(RAddress2)));
			IF we = '1' THEN
				regfile(to_integer(unsigned(wAddress))) <= writePort;
			END IF;
		END IF;
	END IF;
	END PROCESS;

END arch1;