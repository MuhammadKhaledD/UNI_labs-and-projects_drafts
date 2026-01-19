library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity machine is
        port (
            clk : in std_logic;
            reset : in std_logic;
            en : in std_logic;
            grind : out std_logic;
            brew : out std_logic;
            pour : out std_logic;
            clean : out std_logic
        );
end machine;


architecture fsm of machine is

    type state_type is (GRIND_STATE, BREW_STATE, POUR_STATE, CLEAN_STATE);
    signal state_reg : state_type;

    constant grindtime : integer := 3000;
    constant brewtime : integer := 5000;
    constant pourtime : integer := 2000;
    constant cleantime : integer := 4000;

    signal timer_count : integer := 0;


begin
  process(clk, reset) is
  begin
    if reset = '1' then
        state_reg   <= GRIND_STATE;
        timer_count     <= 0;
        grind            <= '1';
        brew          <= '0';
        pour          <= '0';
        clean          <= '0';
    elsif rising_edge(clk) and en = '1' then
      case state_reg is
        when GRIND_STATE =>
            grind <= '1';
            brew          <= '0';
            pour          <= '0';
            clean         <= '0';
            if timer_count <= grindtime then
                timer_count <= timer_count + 20;
            else
                state_reg <= BREW_STATE;
                timer_count <= 0;
                grind <= '0';
                brew          <= '1';
                pour          <= '0';
                clean         <= '0';
            end if;
        when BREW_STATE =>
                grind <= '0';
                brew          <= '1';
                pour          <= '0';
                clean         <= '0';
                if timer_count <= brewtime then
                    timer_count <= timer_count + 20;
                else
                    state_reg <= POUR_STATE;
                    timer_count <= 0;
                    grind <= '0';
                    brew          <= '0';
                    pour          <= '1';
                    clean         <= '0';
            end if;
        when POUR_STATE =>
                grind <= '0';
                brew          <= '0';
                pour          <= '1';
                clean         <= '0';
                if timer_count <= pourtime then
                    timer_count <= timer_count + 20;
                else
                    state_reg <= CLEAN_STATE;
                    timer_count <= 0;
                    grind <= '0';
                    brew          <= '0';
                    pour          <= '0';
                    clean         <= '1';
            end if;
        when CLEAN_STATE =>
                grind <= '0';
                brew          <= '0';
                pour          <= '0';
                clean         <= '1';
                if timer_count <= cleantime then
                    timer_count <= timer_count + 20;
                else
                    state_reg <= GRIND_STATE;
                    timer_count <= 0;
                    grind <= '0';
                    brew          <= '0';
                    pour          <= '0';
                    clean         <= '0';
                end if;
        end case;
    end if;
  end process;

end architecture fsm;

