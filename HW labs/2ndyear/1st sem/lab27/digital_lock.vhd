library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity digital_lock is
  generic(
    CLK_PERIOD_NS : integer := 10; 
    UNLOCK_TIME_NS : integer := 5000;
    LOCK_TIME_NS   : integer := 15000
  );
  port(
    clk   : in std_logic;
    reset : in std_logic;
    code_input  : in std_logic_vector(3 downto 0);
    enter   : in std_logic;
    LOCK    : out std_logic;
    UNLOCK  : out std_logic;
    seg_units  : out std_logic_vector(6 downto 0);
    seg_tens  : out std_logic_vector(6 downto 0)
  );
end entity digital_lock;

architecture rtl of digital_lock is

  type state_type is (IDLE, WRONG_1, WRONG_2, LOCKED, UNLOCKED);
  signal state_reg : state_type;
  signal correct_code : std_logic_vector(3 downto 0) := "0000";
  signal next_lock, next_unlock : std_logic := '0';
  signal timer_count : integer := 0;
  signal display_units : integer := 0;
  signal display_tens : integer := 0;

  component ssd is
    Port (
        timer : IN integer range 0 to 9;
        seg_output: OUT std_logic_vector(6 downto 0)
    );
  end component;
begin

  ssd_units: ssd 
  generic map ( n => 10 )
  port map (
    timer => display_units,
    seg_output => seg_units
  );
  ssd_tens: ssd
  generic map ( n => 10 )
  port map (
  timer => display_tens,
  seg_output => seg_tens
  );

  process(clk, reset) is
  begin
    if reset = '1' then
        state_reg   <= IDLE;
        correct_code     <= code_input;
        timer_count     <= 0;
        LOCK            <= '0';
        UNLOCK          <= '0';
        display_tens <= 0;
        display_units <= 0;
    elsif rising_edge(clk) then
      
      LOCK   <= '0';
      UNLOCK <= '0';

      case state_reg is
        when IDLE =>
          display_tens <= 0;
          display_units <= 0;
          if enter = '1' then
            if code_input = correct_code then
               state_reg <= UNLOCKED;
               timer_count    <= UNLOCK_TIME_NS / CLK_PERIOD_NS;
            else
              state_reg <= WRONG_1;
            end if;
          end if;
        when WRONG_1 =>
          display_tens <= 0;
          display_units <= 0;
          if enter = '1' then
            if code_input = correct_code then
               state_reg <= UNLOCKED;
               timer_count    <= UNLOCK_TIME_NS / CLK_PERIOD_NS;
            else
              state_reg <= WRONG_2;
            end if;
          end if;
        when WRONG_2 =>
          display_tens <= 0;
          display_units <= 0;
          if enter = '1' then
            if code_input = correct_code then
               state_reg <= UNLOCKED;
               timer_count    <= UNLOCK_TIME_NS / CLK_PERIOD_NS;
            else
              state_reg <= LOCKED;
              timer_count     <= LOCK_TIME_NS / CLK_PERIOD_NS;
            end if;
          end if;
        when LOCKED =>
          LOCK <= '1';
          display_tens <= timer_count / 1000;
          display_units <= (timer_count / 100) mod 10;
          if timer_count > 0 then
             timer_count <= timer_count - 1;
          else
             state_reg <= IDLE;
          end if;
        when UNLOCKED =>
          UNLOCK <= '1';
          display_tens <= timer_count / 1000;
          display_units <= (timer_count / 100) mod 10;
          if timer_count > 0 then
             timer_count <= timer_count - 1;
          else
             state_reg <= IDLE;
          end if;
        end case;
      end if;
  end process;

end architecture rtl;
