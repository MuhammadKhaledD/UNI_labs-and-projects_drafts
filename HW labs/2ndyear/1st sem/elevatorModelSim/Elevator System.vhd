library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY elevator_system IS 
    GENERIC(N : integer := 4); -- 4 bits for floor selection
    PORT (
        clk        : in std_logic;  -- 50 MHz from FPGA
        rst        : in std_logic;  -- Reset button
        en         : in std_logic;  -- Push button to register floor request
        bn         : in std_logic_vector(N-1 DOWNTO 0); -- Floor switches (0-9)
        
        -- Outputs to LEDs
        mv_up      : out std_logic; -- LED: moving up
        mv_dn      : out std_logic; -- LED: moving down
        door_open  : out std_logic; -- LED: door is open
        
        -- Output to 7-segment display (active low)
        ssd        : out std_logic_vector(6 downto 0) -- 7-segment display output
    );
END elevator_system;

ARCHITECTURE structural OF elevator_system IS 
    
    -- Internal signals
    signal curr_floor_int : integer range 0 to 9 := 0;
    signal state_encoded : std_logic_vector(1 downto 0); -- 00=idle, 01=up, 10=down, 11=dooropen
    signal up_sig, down_sig, reached_sig : std_logic;
    
    -- Elevator Controller Component
    COMPONENT elevator_ctrl IS 
        GENERIC(N : integer := 4);
        PORT (
            clk       : in std_logic;
            rst       : in std_logic;
            en        : in std_logic;
            bn        : in std_logic_vector(N-1 DOWNTO 0);
            mv_up     : out std_logic;
            mv_dn     : out std_logic;
            door_open : out std_logic;
            
            -- Additional ports for integration
            curr_floor_out : out integer range 0 to 9;
            state_out      : out std_logic_vector(1 downto 0);
            
            -- Inputs from request resolver
            up_input   : in std_logic;
            down_input : in std_logic;
            reached    : in std_logic
        );
    END COMPONENT;
    
    -- Request Resolver Component
    COMPONENT request_resolver IS 
        GENERIC(N : integer := 4);
        PORT (
            clk        : in std_logic;
            rst        : in std_logic;
            en         : in std_logic;
            bn         : in std_logic_vector(N-1 DOWNTO 0);
            curr_floor : in integer range 0 to 9;
            curr_state : in std_logic_vector(1 downto 0);
            up_input   : out std_logic;
            down_input : out std_logic;
            reached    : out std_logic
        );
    END COMPONENT;
    
    -- Seven Segment Display Decoder Component
    COMPONENT ssd_decoder IS 
        PORT (
            binary_in : in integer range 0 to 9;
            ssd_out   : out std_logic_vector(6 downto 0)
        );
    END COMPONENT;
    
BEGIN

    -- Instantiate Request Resolver
    req_resolver: request_resolver
        GENERIC MAP (N => N)
        PORT MAP (
            clk        => clk,
            rst        => rst,
            en         => en,
            bn         => bn,
            curr_floor => curr_floor_int,
            curr_state => state_encoded,
            up_input   => up_sig,
            down_input => down_sig,
            reached    => reached_sig
        );
    
    -- Instantiate Elevator Controller
    ctrl: elevator_ctrl
        GENERIC MAP (N => N)
        PORT MAP (
            clk            => clk,
            rst            => rst,
            en             => en,
            bn             => bn,
            mv_up          => mv_up,
            mv_dn          => mv_dn,
            door_open      => door_open,
            curr_floor_out => curr_floor_int,
            state_out      => state_encoded,
            up_input       => up_sig,
            down_input     => down_sig,
            reached        => reached_sig
        );
    
    -- Instantiate Seven Segment Display Decoder
    ssd_disp: ssd_decoder
        PORT MAP (
            binary_in => curr_floor_int,
            ssd_out   => ssd
        );
    
END structural;