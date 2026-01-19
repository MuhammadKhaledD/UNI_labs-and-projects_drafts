    library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity digital_lock_tb is
end digital_lock_tb;

architecture behavior of digital_lock_tb is

    component digital_lock is
        generic(
            CLK_PERIOD_NS : integer := 10; 
            UNLOCK_TIME_NS : integer := 5000;
            LOCK_TIME_NS   : integer := 15000
        );
        port(
            clk         : in std_logic;
            reset       : in std_logic;
            code_input  : in std_logic_vector(3 downto 0);
            enter       : in std_logic;
            LOCK        : out std_logic;
            UNLOCK      : out std_logic;
            seg_units   : out std_logic_vector(6 downto 0);
            seg_tens    : out std_logic_vector(6 downto 0)
        );
    end component;

    signal clk        : std_logic := '0';
    signal reset      : std_logic := '0';
    signal code_input : std_logic_vector(3 downto 0) := (others => '0');
    signal enter      : std_logic := '0';

    signal LOCK       : std_logic;
    signal UNLOCK     : std_logic;
    signal seg_units  : std_logic_vector(6 downto 0);
    signal seg_tens   : std_logic_vector(6 downto 0);

    constant CLK_PERIOD : time := 10 ns;
    
    constant UNLOCK_TIME : time := 5000 ns;
    constant LOCK_TIME   : time := 15000 ns;

begin

    uut: digital_lock
    generic map (
        CLK_PERIOD_NS  => 10,
        UNLOCK_TIME_NS => 5000,
        LOCK_TIME_NS   => 15000
    )
    port map (
        clk         => clk,
        reset       => reset,
        code_input  => code_input,
        enter       => enter,
        LOCK        => LOCK,
        UNLOCK      => UNLOCK,
        seg_units   => seg_units,
        seg_tens    => seg_tens
    );

    clk_process :process
    begin
        clk <= '0';
        wait for CLK_PERIOD/2;
        clk <= '1';
        wait for CLK_PERIOD/2;
    end process;

    stim_proc: process
    begin
        -- =========================================================
        -- 1. SETUP & RESET
        -- =========================================================

        wait for 100 ns;
        
        -- Set the correct password to "1010" (Decimal 10)
        code_input <= "1010"; 
        reset <= '1';
        wait for 20 ns; 
        reset <= '0';
        
        wait for CLK_PERIOD * 2;

        -- =========================================================
        -- 2. TEST CASE: SUCCESSFUL UNLOCK
        -- =========================================================
        report "Test Case 1: Attempting Correct Code";
        
        code_input <= "1010";
        enter <= '1';
        wait for CLK_PERIOD;
        enter <= '0';
        
        wait for CLK_PERIOD; 
        assert UNLOCK = '1' report "Error: Should be UNLOCKED" severity error;
        
        wait for UNLOCK_TIME;
        wait for CLK_PERIOD * 5;
        
        -- =========================================================
        -- 3. TEST CASE: WRONG CODE (1st Attempt)
        -- =========================================================
        report "Test Case 2: Wrong Code (Attempt 1)";
        
        code_input <= "0000";
        enter <= '1';
        wait for CLK_PERIOD;
        enter <= '0';
        

        wait for CLK_PERIOD * 2;
        assert LOCK = '0' and UNLOCK = '0' report "Error: Should be in WRONG_1 state" severity error;

        -- =========================================================
        -- 4. TEST CASE: WRONG CODE (2nd Attempt)
        -- =========================================================
        report "Test Case 3: Wrong Code (Attempt 2)";
        
        code_input <= "0001";
        enter <= '1';
        wait for CLK_PERIOD;
        enter <= '0';
        
        wait for CLK_PERIOD * 2;
        assert LOCK = '0' and UNLOCK = '0' report "Error: Should be in WRONG_2 state" severity error;

        -- =========================================================
        -- 5. TEST CASE: LOCKOUT (3rd Attempt)
        -- =========================================================
        report "Test Case 4: Wrong Code (Attempt 3) -> LOCKOUT";
        
        code_input <= "0010";
        enter <= '1';
        wait for CLK_PERIOD;
        enter <= '0';
        
        wait for CLK_PERIOD * 2;
        
        assert LOCK = '1' report "Error: System should be LOCKED" severity error;
        
        wait for LOCK_TIME;
        wait for CLK_PERIOD * 10;
        
        -- Should be back to IDLE now
        assert LOCK = '0' report "Error: Should have returned to IDLE" severity error;

        report "Simulation Finished Successfully";
        wait;
    end process;

end behavior;