library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ssd is
    generic (
    n : integer := 10
    );
    Port (
        timer : IN integer range 0 to n-1;
        seg_output: OUT std_logic_vector(6 downto 0)
    );
end entity ssd;

architecture Behavioral of ssd is
begin

    process(timer)
    begin
        case timer is
            when 0 => seg_output <= "1000000";  -- 0
            when 1 => seg_output <= "1111001";  -- 1
            when 2 => seg_output <= "0100100";  -- 2
            when 3 => seg_output <= "0110000";  -- 3
            when 4 => seg_output <= "0011001";  -- 4
            when 5 => seg_output <= "0010010";  -- 5
            when 6 => seg_output <= "0000010";  -- 6
            when 7 => seg_output <= "1111000";  -- 7
            when 8 => seg_output <= "0000000";  -- 8
            when 9 => seg_output <= "0010000";  -- 9
            when others => seg_output <= "1111111";  -- Blank for invalid inputs
        end case;
    end process;

end Behavioral;