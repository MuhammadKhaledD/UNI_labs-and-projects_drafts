library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity machine_tb is
end entity machine_tb;

architecture behavior of machine_tb is
    -- Component declaration for the coffee machine controller
    component machine is
        port (
            clk : in std_logic;
            reset : in std_logic;
            en : in std_logic;
            grind : out std_logic;
            brew : out std_logic;
            pour : out std_logic;
            clean : out std_logic
        );
    end component;

    -- Signals for the testbench
    signal clk : std_logic := '0';
    signal reset : std_logic := '0';
    signal en : std_logic := '1';
    signal grind : std_logic;
    signal brew : std_logic;
    signal pour : std_logic;
    signal clean : std_logic;

    constant CLK_PERIOD : time := 20 ns;

    begin

    -- Instantiate the machine controller
    uut: machine
        port map (
            clk => clk,
            reset => reset,
            en => en,
            grind => grind,
            brew => brew,
            pour => pour,
            clean => clean
        );

    clk_process :process
        begin
            clk <= '0';
            wait for CLK_PERIOD/2;
            clk <= '1';
            wait for CLK_PERIOD/2;
        end process;

    -- Test process
    test_process: process
        begin
            -- Apply reset
        wait for 200 ns;
-- -----------------------------------------------------------------------------------------------------------
        report "Test Case 0: reset test";
        reset <= '1';
        wait for 40 ns;
        assert (grind = '1' and brew = '0' and pour = '0' and clean = '0')
        report "Test0 failed: Reset" severity error; 
        reset <= '0';
        
        wait for CLK_PERIOD * 2; -- -40 ns from grindtime

-- ---------------------------------------------------------------------------------------

        report "Test Case 1: grind must = 1 and the rest = 0";
        wait for CLK_PERIOD * 8; -- -200 ns from grindtime
        assert (grind = '1' and brew = '0' and pour = '0' and clean = '0')
        report "Test1 failed: Reset" severity error; 
        wait for CLK_PERIOD * 142; -- -40 ns from brewtime

-- ---------------------------------------------------------------------------------------

        report "Test Case 2: brew must = 1 and the rest = 0";
        wait for CLK_PERIOD * 8; -- -200 ns from brewtime
        assert (grind = '0' and brew = '1' and pour = '0' and clean = '0')
        report "Test2 failed: Reset" severity error; 
        wait for CLK_PERIOD * 242; -- -40 ns from pourtime

-- ---------------------------------------------------------------------------------------

        report "Test Case 3: pour must = 1 and the rest = 0";
        wait for CLK_PERIOD * 8; -- -200 ns from pourtime
        assert (grind = '0' and brew = '0' and pour = '1' and clean = '0')
        report "Test3 failed: Reset" severity error; 
        wait for CLK_PERIOD * 92; -- -40 ns from cleantime

-- ---------------------------------------------------------------------------------------

        report "Test Case 4: clean = 1 and the rest = 0";
        wait for CLK_PERIOD * 8; -- -200 ns from cleantime
        assert (grind = '0' and brew = '0' and pour = '0' and clean = '1')
        report "Test4 failed: Reset" severity error; 
        wait for CLK_PERIOD * 192; -- -40 ns from grindtime

-- ---------------------------------------------------------------------------------------

        report "Test Case 5: grind = 1 and the rest = 0";
        wait for CLK_PERIOD * 8; -- -200 ns from grindntime
        assert (grind = '1' and brew = '0' and pour = '0' and clean = '0')
        report "Test5 failed: Reset" severity error;

-- -----------------------------------------------------------------------------------------

        report "Test Case 6: test en we must stay in grind state until en = 1 again";
        en <= '0';
        wait for CLK_PERIOD * 142; -- -time w 5las kda kda el en = 0 msh far2a ns from grindtime
        assert (grind = '1' and brew = '0' and pour = '0' and clean = '0')
        report "Test6 failed: Reset" severity error;

-- -----------------------------------------------------------------------------------------

        report "Test Case 7: test en we made en = 1 again must go to brew state";
        en <= '1';
        wait for CLK_PERIOD * 152; -- -400 ns from brewtime
        assert (grind = '0' and brew = '1' and pour = '0' and clean = '0')
        report "Test7 failed: Reset" severity error;
            wait;
        end process test_process;
end architecture behavior;

