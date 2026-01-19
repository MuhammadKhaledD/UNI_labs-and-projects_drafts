library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY request_resolver IS 
    GENERIC(N : integer := 4); -- N=4 means 4 bits, can represent 0-15, we use 0-9
    PORT (
        clk         : in std_logic;
        rst         : in std_logic;
        en          : in std_logic; -- push button to register request
        bn          : in std_logic_vector(N-1 DOWNTO 0); -- floor buttons (switches)
        curr_floor  : in integer range 0 to 9; -- current floor from controller
        curr_state  : in std_logic_vector(1 downto 0); -- 00=idle, 01=up, 10=down, 11=door
        
        -- Outputs to elevator controller
        up_input    : out std_logic; -- there are requests above current floor
        down_input  : out std_logic; -- there are requests below current floor
        reached     : out std_logic  -- current floor has a request
    );
END request_resolver;

ARCHITECTURE rtl OF request_resolver IS 
    -- Request queue: 10 bits for floors 0-9
    -- Bit i = '1' means floor i has a pending request
    signal request_queue : std_logic_vector(9 downto 0) := (others => '0');
    signal last_direction : std_logic := '1'; -- 0=down, 1=up (for when idle)
    
    -- Edge detection for enable button
    signal en_prev : std_logic := '0';
    signal en_rising : std_logic;
    
BEGIN

    -- Detect rising edge of enable button
    en_rising <= '1' when (en = '1' and en_prev = '0') else '0';

    -- Process 1: Capture floor requests and clear completed requests
    PROCESS(clk, rst)
        variable floor_num : integer;
    BEGIN
        if rst = '1' then
            request_queue <= (others => '0');
            en_prev <= '0';
            
        elsif rising_edge(clk) then
            -- Update edge detection
            en_prev <= en;
            
            -- Capture new request when enable button is pressed (rising edge)
            if en_rising = '1' then
                floor_num := to_integer(unsigned(bn));
                if floor_num >= 0 and floor_num <= 9 then
                    request_queue(floor_num) <= '1';
                end if;
            end if;
            
            -- Clear request when door opens at that floor
            -- curr_state = "11" means opendoor_state
            if curr_state = "11" then
                request_queue(curr_floor) <= '0';
            end if;
        end if;
    END PROCESS;
    
    -- Process 2: Track last direction for intelligent idle decisions
    PROCESS(clk, rst)
    BEGIN
        if rst = '1' then
            last_direction <= '1'; -- default to up
        elsif rising_edge(clk) then
            -- curr_state: 01=up, 10=down
            if curr_state = "01" then
                last_direction <= '1'; -- was going up
            elsif curr_state = "10" then
                last_direction <= '0'; -- was going down
            end if;
        end if;
    END PROCESS;

    -- Process 3: Combinational logic - Resolve requests based on SCAN algorithm
    -- This implements the elevator scheduling algorithm
    PROCESS(request_queue, curr_floor, curr_state, last_direction)
        variable has_request_above : std_logic;
        variable has_request_below : std_logic;
        variable has_request_here : std_logic;
    BEGIN
        -- Initialize
        has_request_above := '0';
        has_request_below := '0';
        has_request_here := request_queue(curr_floor);
        
        -- Check for requests above current floor (static loop bounds)
        for i in 0 to 9 loop
            if i > curr_floor and request_queue(i) = '1' then
                has_request_above := '1';
            end if;
        end loop;
        
        -- Check for requests below current floor (static loop bounds)
        for i in 0 to 9 loop
            if i < curr_floor and request_queue(i) = '1' then
                has_request_below := '1';
            end if;
        end loop;
        
        -- Default outputs
        up_input <= '0';
        down_input <= '0';
        reached <= '0';
        
        -- Output logic based on current state (SCAN algorithm)
        case curr_state is
            when "01" => -- up_state
                -- SCAN: Continue going up if there are requests above
                -- Only change direction if no more requests above
                if has_request_here = '1' then
                    reached <= '1';
                elsif has_request_above = '1' then
                    up_input <= '1';
                elsif has_request_below = '1' then
                    -- No more up requests, but there are down requests
                    down_input <= '1';
                end if;
                
            when "10" => -- down_state
                -- SCAN: Continue going down if there are requests below
                -- Only change direction if no more requests below
                if has_request_here = '1' then
                    reached <= '1';
                elsif has_request_below = '1' then
                    down_input <= '1';
                elsif has_request_above = '1' then
                    -- No more down requests, but there are up requests
                    up_input <= '1';
                end if;
                
            when "00" => -- idle_state
                -- Check if there's a request at current floor first
                if has_request_here = '1' then
                    reached <= '1';
                -- Choose direction based on last direction for efficiency
                elsif last_direction = '1' then -- was going up
                    if has_request_above = '1' then
                        up_input <= '1';
                    elsif has_request_below = '1' then
                        down_input <= '1';
                    end if;
                else -- was going down
                    if has_request_below = '1' then
                        down_input <= '1';
                    elsif has_request_above = '1' then
                        up_input <= '1';
                    end if;
                end if;
                
            when "11" => -- opendoor_state
                -- While door is open, don't signal any movement
                -- The request at current floor will be cleared
                up_input <= '0';
                down_input <= '0';
                reached <= '0';
                
            when others =>
                up_input <= '0';
                down_input <= '0';
                reached <= '0';
        end case;
        
    END PROCESS;

END rtl;