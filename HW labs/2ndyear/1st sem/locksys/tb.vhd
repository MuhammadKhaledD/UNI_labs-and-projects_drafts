-- tb_design.vhd (cleaned)
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_design is
end entity tb_design;

architecture tb of tb_design is
  -- Testbench signals
  signal clk  : std_logic := '0';
  signal rst        : std_logic := '0';
  signal en : std_logic := '0';
  signal lock        : std_logic := '0';
  signal unlock    : std_logic := '0';
  signal cin    : std_logic_vector(2 downto 0);
  signal sddU  : std_logic_vector(6 downto 0);
  signal sevenT  : std_logic_vector(6 downto 0);

  -- Simulation-friendly divider input frequency (override default inside top_demo)
  constant locktime : time := 15000 ns; -- small for fast sim
  constant unlocktime : time := 5000 ns; -- small for fast sim

  constant CLK50_PERIOD : time := 1000 ns; -- corresponds to 50 MHz (20 ns period)
begin
  clkgen_proc: process
  begin
    clk <= '0';
    wait for CLK50_PERIOD/2;
    clk <= '1';
    wait for CLK50_PERIOD/2;
  end process clkgen_proc;

    uut: entity work.locksys
        port map (
        clk     => clk,
        rst     => rst,
        en      => en,
        cin     => cin,
        lock    => lock,
        unlock  => unlock,
        ssdU    => sddU,
        ssdT    => sevenT
        );

    stim_proc: process
    begin
    -- initial reset pulse
    rst <= '1';
    wait for 20000 ns;
    rst <= '0';
    wait for 10000 ns;

    cin <= "001"; -- correct passcode
    rst <= '1'; -- 3
    wait for 2000 ns;
    rst <= '0';
    wait for 1000 ns;

    en <= '1';
    cin <= "001"; -- correct passcode
    wait for 1000 ns;
    en <= '0';


    -- quick check of adder output
    assert unlock = '1'
      report "must be unlock = 1 first test" severity error;

    -- allow slow counter (and 7-seg) to tick a few times
    -- since SIM_DIV_INPUT_FREQ is small, waiting ms is acceptable
    wait for 20000 ns;

    en <= '1';
    cin <= "011"; -- correct passcode
    wait for 1000 ns;
    en <= '0';
    wait for 1000 ns;
    en <= '1';
    cin <= "011"; -- correct passcode
    wait for 1000 ns;
    en <= '0';
    wait for 1000 ns;
    en <= '1';
    cin <= "011"; -- correct passcode
    wait for 1000 ns;
    en <= '0';
    wait for 1000 ns;

    assert lock = '1'
    report "must be lock = 1 2nd test" severity error;

    -- allow slow counter (and 7-seg) to tick a few times
    -- since SIM_DIV_INPUT_FREQ is small, waiting ms is acceptable
    wait for 20000 ns;

    report "Simulation Finished Successfully";
        wait;
    end process;

end architecture tb;
