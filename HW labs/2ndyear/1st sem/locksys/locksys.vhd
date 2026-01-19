
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY locksys IS
    PORT (
        clk        : in std_logic;  -- 1000ns clock
        rst        : in std_logic;  -- Reset button
        en         : in std_logic;  -- Push button to register floor request
        cin         : in std_logic_vector(2 DOWNTO 0); -- Floor switches (0-9)
        
        -- Outputs to LEDs
        lock      : out std_logic; -- LED: moving up
        unlock      : out std_logic; -- LED: moving down
        ssdU       : out std_logic_vector(6 downto 0);
        ssdT       : out std_logic_vector(6 downto 0)
    );
END locksys;

ARCHITECTURE idk OF locksys IS 
    
    -- Internal signals
    type state IS (idle_state, wrong1_state, wrong2_state, locked_state, unlocked_state);
    signal state_reg : state := idle_state;
    signal passcode : std_logic_vector(2 downto 0) := "000";
    constant locktime : time := 15000 ns;
    constant unlocktime : time := 5000 ns;
    signal lt : time := 0 ns;
    signal ut : time := 0 ns;
    signal unitseg : integer range 0 to 9;
    signal tensseg : integer range 0 to 9;

    -- Seven Segment Display Decoder Component
    COMPONENT ssd_decoder IS 
        PORT (
            binary_in : in integer range 0 to 9;
            ssd_out   : out std_logic_vector(6 downto 0)
        );
    END COMPONENT;
    
BEGIN

    PROCESS(clk, rst)
    BEGIN
        if rst = '1' then
            state_reg <= idle_state;
            passcode <= cin;
            lt <= 0 ns;
            ut <= 0 ns;
            lock <= '0';
            unlock <= '0';
        elsif rising_edge(clk) then
            CASE state_reg IS
                WHEN idle_state =>
                    IF en = '1' THEN
                        IF cin = passcode THEN
                            state_reg <= unlocked_state;
                        ELSE
                            state_reg <= wrong1_state;
                        END IF;
                    END IF;
                WHEN wrong1_state =>
                    IF en = '1' THEN
                        IF cin = passcode THEN
                            state_reg <= unlocked_state;
                        ELSE
                            state_reg <= wrong2_state;
                        END IF;
                    END IF;
                WHEN wrong2_state =>
                    IF en = '1' THEN
                        IF cin = passcode THEN
                            state_reg <= unlocked_state;
                        ELSE
                            state_reg <= locked_state;
                        END IF;
                    END IF;
                WHEN locked_state =>
                        unlock <= '1';
                        lock <= '0';
                        if(lt <= locktime) then
                            lt <= lt + 1000 ns;  -- assuming clk period is 1000 ns
                            if (lt < 10000 ns) then
                                unitseg <= lt / 1000 ns;  -- display seconds on unit segment
                                tensseg <= 0;
                            else
                                unitseg <= (lt / 1000 ns) mod 10;
                                tensseg <= 1;
                            end if;
                        else
                            lt <= 0 ns;
                            state_reg <= idle_state;
                        end if;
                WHEN unlocked_state =>
                        lock <= '1';
                        unlock <= '0';
                        if(ut <= unlocktime) then
                            ut <= ut + 1000 ns;  -- assuming clk period is 1000 ns
                            unitseg <= ut / 1000 ns;  -- display seconds on unit segment
                            tensseg <= 0;
                        else
                            ut <= 0 ns;
                            state_reg <= idle_state;
                        end if;
                WHEN OTHERS =>
                    state_reg <= idle_state;
            END CASE;
        END IF;

    END PROCESS;
    
    -- Instantiate Seven Segment Display Decoder
    sdd_ten: ssd_decoder
        PORT MAP (
            binary_in => tensseg,
            ssd_out   => ssdT
        );

    sdd_units: ssd_decoder
        PORT MAP (
            binary_in => unitseg,
            ssd_out   => ssdU    
        );
END idk;
