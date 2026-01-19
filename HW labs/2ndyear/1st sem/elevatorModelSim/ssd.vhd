library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY ssd_decoder IS 
    PORT (
        binary_in : in integer range 0 to 9;  -- Floor number 0-9
        ssd_out   : out std_logic_vector(6 downto 0)  -- 7-segment output (active low)
                                                        -- Segments: gfedcba
    );
END ssd_decoder;

ARCHITECTURE rtl OF ssd_decoder IS 
BEGIN
    PROCESS(binary_in)
    BEGIN
        CASE binary_in IS
            -- Format: gfedcba
            WHEN 0 => ssd_out <= "1000000"; -- 0: all on except g
            WHEN 1 => ssd_out <= "1111001"; -- 1: b,c on
            WHEN 2 => ssd_out <= "0100100"; -- 2: a,b,g,e,d on
            WHEN 3 => ssd_out <= "0110000"; -- 3: a,b,g,c,d on
            WHEN 4 => ssd_out <= "0011001"; -- 4: f,g,b,c on
            WHEN 5 => ssd_out <= "0010010"; -- 5: a,f,g,c,d on
            WHEN 6 => ssd_out <= "0000010"; -- 6: a,f,g,e,d,c on
            WHEN 7 => ssd_out <= "1111000"; -- 7: a,b,c on
            WHEN 8 => ssd_out <= "0000000"; -- 8: all segments on
            WHEN 9 => ssd_out <= "0010000"; -- 9: a,b,c,d,f,g on
            WHEN OTHERS => ssd_out <= "1111111"; -- blank (all off)
        END CASE;
    END PROCESS;
    
END rtl;
