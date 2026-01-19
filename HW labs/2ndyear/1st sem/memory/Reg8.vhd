library ieee;
use ieee.std_logic_1164.all;

entity Reg8 is
    port(
        clk : in std_logic;
        rst : in std_logic;
        we  : in std_logic;
        d   : in std_logic_vector(7 downto 0);
        q   : out std_logic_vector(7 downto 0)
    );
end entity;

architecture rtl of Reg8 is
    signal q_int : std_logic_vector(7 downto 0);
begin
    -- synchronous D register with enable and synchronous reset
    process(clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                q_int <= (others => '0');
            else
                if we = '1' then
                    q_int <= d;
                else
                    q_int <= q_int; -- retain
                end if;
            end if;
        end if;
    end process;

    q <= q_int;
end architecture;

