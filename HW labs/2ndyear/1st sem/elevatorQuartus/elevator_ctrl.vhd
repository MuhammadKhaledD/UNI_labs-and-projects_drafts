library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY elevator_ctrl IS 
    GENERIC(N : integer := 4);
    PORT (
        clk       : in std_logic;
        rst       : in std_logic;
        en        : in std_logic; -- push button from fpga (not used here, used in resolver)
        bn        : in std_logic_vector(N-1 DOWNTO 0); -- switches (not used here)
        
        -- Outputs to LEDs
        mv_up     : out std_logic;
        mv_dn     : out std_logic;
        door_open : out std_logic;
        
        -- Outputs to pass info to request resolver
        curr_floor_out : out integer range 0 to 9;
        state_out      : out std_logic_vector(1 downto 0); -- 00=idle, 01=up, 10=down, 11=door
        
        -- Inputs from request resolver
        up_input   : in std_logic;
        down_input : in std_logic;
        reached    : in std_logic
    );
END elevator_ctrl;

ARCHITECTURE arch1 OF elevator_ctrl IS 
    type ELEVATOR_STATE IS (idle_state, up_state, down_state, opendoor_state);
    signal state_reg : ELEVATOR_STATE := idle_state;
    signal curr_floor : integer range 0 to 9 := 0;

    -- Clock divider signals for 1 second timing
    constant CLK_FREQ : integer := 50000000; -- 50 MHz
    constant COUNT_1SEC : integer := CLK_FREQ - 1; -- Count for 1 second
    signal clk_counter : integer range 0 to COUNT_1SEC := 0;
    signal clk_1sec_enable : std_logic := '0';
    
    -- Timer for elevator movements and door
    signal timer : integer range 0 to 2 := 0; -- 0 to 2 for counting 2 seconds

BEGIN
    
    -- Clock divider: creates 1-second enable pulse
    PROCESS(clk, rst)
    BEGIN
        if rst = '1' then
            clk_counter <= 0;
            clk_1sec_enable <= '0';
        elsif rising_edge(clk) then
            if clk_counter = COUNT_1SEC then
                clk_counter <= 0;
                clk_1sec_enable <= '1'; -- Pulse high for one clock cycle
            else
                clk_counter <= clk_counter + 1;
                clk_1sec_enable <= '0';
            end if;
        end if;
    END PROCESS;

    -- Main FSM: controls elevator state transitions
    PROCESS (clk, rst)
    BEGIN
        if(rst='1') then
            state_reg <= idle_state;
            timer <= 0;
            
        elsif rising_edge(clk) then
            CASE state_reg IS
                WHEN idle_state => 
                    timer <= 0;
                    -- Check which direction to go based on request resolver
                    if reached = '1' then 
                        -- There's a request at current floor
                        state_reg <= opendoor_state;
                    elsif up_input = '1' then 
                        -- There are requests above
                        state_reg <= up_state;
                    elsif down_input = '1' then
                        -- There are requests below
                        state_reg <= down_state;
                    else 
                        -- No requests, stay idle
                        state_reg <= idle_state;
                    end if;

                WHEN up_state =>
                    -- Move up every 2 seconds
                    if clk_1sec_enable = '1' then
                        if timer < 2 then 
                            timer <= timer + 1;
                        else
                            -- 2 seconds passed, move to next floor
                            timer <= 0;
                            if curr_floor < 9 then
                                curr_floor <= curr_floor + 1;
                            end if;
                        end if;
                    end if;
                    
                    -- Check if we reached a requested floor (only check after floor changes)
                    if reached = '1' and timer = 0 then 
                        state_reg <= opendoor_state;
                        timer <= 0;
                    elsif up_input = '0' and down_input = '0' and reached = '0' then
                        -- No more requests anywhere
                        state_reg <= idle_state;
                        timer <= 0;
                    elsif up_input = '0' and down_input = '1' then
                        -- No more up requests, but there are down requests
                        state_reg <= down_state;
                        timer <= 0;
                    end if;
                    
                WHEN down_state =>
                    -- Move down every 2 seconds
                    if clk_1sec_enable = '1' then
                        if timer < 2 then 
                            timer <= timer + 1;
                        else
                            -- 2 seconds passed, move to next floor
                            timer <= 0;
                            if curr_floor > 0 then
                                curr_floor <= curr_floor - 1;
                            end if;
                        end if;
                    end if;
                    
                    -- Check if we reached a requested floor (only check after floor changes)
                    if reached = '1' and timer = 0 then 
                        state_reg <= opendoor_state;
                        timer <= 0;
                    elsif down_input = '0' and up_input = '0' and reached = '0' then
                        -- No more requests anywhere
                        state_reg <= idle_state;
                        timer <= 0;
                    elsif down_input = '0' and up_input = '1' then
                        -- No more down requests, but there are up requests
                        state_reg <= up_state;
                        timer <= 0;
                    end if;
                    
                WHEN opendoor_state => 
                    -- Keep door open for 2 seconds
                    if clk_1sec_enable = '1' then
                        if timer < 2 then 
                            timer <= timer + 1;
                        else
                            -- 2 seconds passed, close door and check for next request
                            timer <= 0;
                            -- Directly transition based on pending requests (more efficient)
                            if up_input = '1' then
                                state_reg <= up_state;
                            elsif down_input = '1' then
                                state_reg <= down_state;
                            else
                                state_reg <= idle_state;
                            end if;
                        end if;
                    end if;

            END CASE;
        END IF;
    END PROCESS;
    
    -- Output assignments for LEDs
    mv_up <= '1' WHEN state_reg = up_state else '0';
    mv_dn <= '1' WHEN state_reg = down_state else '0';
    door_open <= '1' WHEN state_reg = opendoor_state else '0';
    
    -- Pass current floor to request resolver
    curr_floor_out <= curr_floor;
    
    -- Encode state as std_logic_vector for request resolver
    -- This is a concurrent statement, not inside process
    with state_reg select
        state_out <= "00" when idle_state,
                     "01" when up_state,
                     "10" when down_state,
                     "11" when opendoor_state,
                     "00" when others;

END arch1;