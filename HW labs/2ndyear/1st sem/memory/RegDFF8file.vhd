library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity RegFile_DFF is
    port(
        clk, rst, we : in std_logic;
        RAddress1, RAddress2, WAddress : in std_logic_vector(2 downto 0);
        writePort : in std_logic_vector(7 downto 0);
        readPort1, readPort2 : out std_logic_vector(7 downto 0)
    );
end entity RegFile_DFF;

architecture struct of RegFile_DFF is
    component Reg8
        port(
            clk : in std_logic;
            rst : in std_logic;
            we  : in std_logic;
            d   : in std_logic_vector(7 downto 0);
            q   : out std_logic_vector(7 downto 0)
        );
    end component;

    type reg_array_type is array (0 to 7) of std_logic_vector(7 downto 0);
    signal regs : reg_array_type := (others => (others => '0'));
    signal we_signals : std_logic_vector(7 downto 0) := (others => '0');
begin
    -- Decoder (combinational) ? explicit sensitivity list for older VHDL
    process(we, WAddress)
    begin
        we_signals <= (others => '0');
        if we = '1' then
            -- safe index conversion
            we_signals(to_integer(unsigned(WAddress))) <= '1';
        end if;
    end process;

    -- Instantiate 8 registers
    gen_regs: for i in 0 to 7 generate
        r_inst: Reg8
            port map(
                clk => clk,
                rst => rst,
                we  => we_signals(i),
                d   => writePort,
                q   => regs(i)
            );
    end generate;

    -- Asynchronous read ports (instant on address change)
    readPort1 <= regs(to_integer(unsigned(RAddress1)));
    readPort2 <= regs(to_integer(unsigned(RAddress2)));
end architecture;

