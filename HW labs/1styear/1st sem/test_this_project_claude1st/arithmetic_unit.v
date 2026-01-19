module arithmetic_unit(
    input wire [0:0] KEY,          // Clock input (push button)
    input wire [5:0] SW,           // SW[1:0] for number, SW[2] for sign, SW[5:4] for operator
    output reg [6:0] HEX0,         // Rightmost display (current input)
    output reg [6:0] HEX1,         // Result digit 1 (rightmost)
    output reg [6:0] HEX2,         // Result digit 2
    output reg [6:0] HEX3,         // Result digit 3 (leftmost)
    output reg [2:0] LEDR          // LEDR[0]:div_by_zero, LEDR[1]:sign, LEDR[2]:zero
);

    // Internal registers
    reg [19:0] numbers;            // 5 numbers, 4 bits each
    reg [7:0] operators;           // 4 operators, 2 bits each
    reg [2:0] counter;             // Track input sequence
    reg signed [7:0] current_result;
    reg bonus_mode;                // Flag for bonus calculation
    reg signed [7:0] precedence_result; 
    reg [3:0] current_number;
    reg [1:0] current_op;
    reg signed [7:0] operation_result;
    reg [6:0] seg_output;
    reg signed [7:0] temp_result0, temp_result1, temp_result2, temp_result3, temp_result4;

    // Seven-segment patterns
    parameter SEG_0 = 7'b1000000;
    parameter SEG_1 = 7'b1111001;
    parameter SEG_2 = 7'b0100100;
    parameter SEG_3 = 7'b0110000;
    parameter SEG_4 = 7'b0011001;
    parameter SEG_5 = 7'b0010010;
    parameter SEG_6 = 7'b0000010;
    parameter SEG_7 = 7'b1111000;
    parameter SEG_8 = 7'b0000000;
    parameter SEG_9 = 7'b0010000;
    parameter SEG_OFF = 7'b1111111;

    // Seven segment decoder - combinational
    always @(*) begin
        case(current_number)
            4'd0: seg_output = SEG_0;
            4'd1: seg_output = SEG_1;
            4'd2: seg_output = SEG_2;
            4'd3: seg_output = SEG_3;
            4'd4: seg_output = SEG_4;
            4'd5: seg_output = SEG_5;
            4'd6: seg_output = SEG_6;
            4'd7: seg_output = SEG_7;
            4'd8: seg_output = SEG_8;
            4'd9: seg_output = SEG_9;
            default: seg_output = SEG_OFF;
        endcase
    end

    // Extract number at index
    function [3:0] get_number;
        input [2:0] index;
        begin
            case(index)
                3'd0: get_number = numbers[3:0];
                3'd1: get_number = numbers[7:4];
                3'd2: get_number = numbers[11:8];
                3'd3: get_number = numbers[15:12];
                3'd4: get_number = numbers[19:16];
                default: get_number = 4'd0;
            endcase
        end
    endfunction

    // Extract operator at index
    function [1:0] get_operator;
        input [1:0] index;
        begin
            case(index)
                2'd0: get_operator = operators[1:0];
                2'd1: get_operator = operators[3:2];
                2'd2: get_operator = operators[5:4];
                2'd3: get_operator = operators[7:6];
                default: get_operator = 2'd0;
            endcase
        end
    endfunction

    // Arithmetic operations - combinational
    always @(*) begin
        case(current_op)
            2'b00: operation_result = current_result + current_number;  // Add
            2'b01: operation_result = current_result - current_number;  // Subtract
            2'b10: operation_result = current_result * current_number;  // Multiply
            2'b11: begin  // Divide
                if(current_number == 0) begin
                    operation_result = 0;
                end else begin
                    operation_result = current_result / current_number;
                end
            end
            default: operation_result = current_result;
        endcase
    end

    // Precedence calculation - combinational
    always @(*) begin
        if(counter == 4 && bonus_mode) begin
            // First pass: Handle multiplication and division
            temp_result0 = numbers[3:0];
            temp_result1 = numbers[7:4];
            temp_result2 = numbers[11:8];
            temp_result3 = numbers[15:12];
            temp_result4 = numbers[19:16];

            // Process * and / first
            if(operators[1:0] == 2'b10) temp_result1 = temp_result0 * temp_result1;
            if(operators[1:0] == 2'b11 && temp_result1 != 0) temp_result1 = temp_result0 / temp_result1;
            if(operators[3:2] == 2'b10) temp_result2 = temp_result1 * temp_result2;
            if(operators[3:2] == 2'b11 && temp_result2 != 0) temp_result2 = temp_result1 / temp_result2;
            if(operators[5:4] == 2'b10) temp_result3 = temp_result2 * temp_result3;
            if(operators[5:4] == 2'b11 && temp_result3 != 0) temp_result3 = temp_result2 / temp_result3;
            if(operators[7:6] == 2'b10) temp_result4 = temp_result3 * temp_result4;
            if(operators[7:6] == 2'b11 && temp_result4 != 0) temp_result4 = temp_result3 / temp_result4;

            // Then process + and -
            precedence_result = temp_result0;
            if(operators[1:0] == 2'b00) precedence_result = precedence_result + temp_result1;
            if(operators[1:0] == 2'b01) precedence_result = precedence_result - temp_result1;
            if(operators[3:2] == 2'b00) precedence_result = precedence_result + temp_result2;
            if(operators[3:2] == 2'b01) precedence_result = precedence_result - temp_result2;
            if(operators[5:4] == 2'b00) precedence_result = precedence_result + temp_result3;
            if(operators[5:4] == 2'b01) precedence_result = precedence_result - temp_result3;
            if(operators[7:6] == 2'b00) precedence_result = precedence_result + temp_result4;
            if(operators[7:6] == 2'b01) precedence_result = precedence_result - temp_result4;
        end
    end

    // Main sequential logic
    always @(posedge KEY[0]) begin
        if(counter == 0) begin
            // Reset
            LEDR <= 0;
            current_result <= 0;
            bonus_mode <= 0;
            HEX0 <= SEG_OFF;
            HEX1 <= SEG_OFF;
            HEX2 <= SEG_OFF;
            HEX3 <= SEG_OFF;
        end

        // Store input number and operator
        case(counter)
            3'd0: numbers[3:0] <= SW[2] ? -SW[1:0] : SW[1:0];
            3'd1: numbers[7:4] <= SW[2] ? -SW[1:0] : SW[1:0];
            3'd2: numbers[11:8] <= SW[2] ? -SW[1:0] : SW[1:0];
            3'd3: numbers[15:12] <= SW[2] ? -SW[1:0] : SW[1:0];
            3'd4: numbers[19:16] <= SW[2] ? -SW[1:0] : SW[1:0];
        endcase

        if(counter < 4) begin
            operators[counter*2 +: 2] <= SW[5:4];
        end

        // Display current input
        current_number <= SW[1:0];
        HEX0 <= seg_output;

        // Perform operation and show intermediate results
        if(counter > 0 && !bonus_mode) begin
            current_op <= get_operator(counter-1);
            current_result <= operation_result;
            
            // Display result
            current_number <= operation_result % 10;
            HEX1 <= seg_output;
            current_number <= (operation_result / 10) % 10;
            HEX2 <= seg_output;
            current_number <= (operation_result / 100) % 10;
            HEX3 <= seg_output;
            
            // Update flags
            LEDR[1] <= (operation_result < 0);  // sign flag
            LEDR[2] <= (operation_result == 0);  // zero flag
            LEDR[0] <= (current_op == 2'b11 && current_number == 0);  // div by zero
        end else begin
            current_result <= get_number(0);
        end

        // Handle bonus calculation
        if(counter == 4) begin
            if(!bonus_mode) begin
                bonus_mode <= 1;
            end else begin
                // Display precedence result
                current_number <= precedence_result % 10;
                HEX1 <= seg_output;
                current_number <= (precedence_result / 10) % 10;
                HEX2 <= seg_output;
                current_number <= (precedence_result / 100) % 10;
                HEX3 <= seg_output;
                
                // Update flags for precedence result
                LEDR[1] <= (precedence_result < 0);
                LEDR[2] <= (precedence_result == 0);
            end
        end

        // Increment counter
        if(counter < 4) begin
            counter <= counter + 1;
        end
    end

    // Initial block
    initial begin
        counter = 0;
        current_result = 0;
        LEDR = 0;
        numbers = 0;
        operators = 0;
        HEX0 = SEG_OFF;
        HEX1 = SEG_OFF;
        HEX2 = SEG_OFF;
        HEX3 = SEG_OFF;
        current_number = 0;
        current_op = 0;
        operation_result = 0;
        bonus_mode = 0;
        precedence_result = 0;
    end

endmodule