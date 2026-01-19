module MyCalc (
    input wire [0:0] KEY,          
    input wire [5:0] SW,           // SW[1:0] for number, SW[2] for sign, SW[5:4] for operator and SW[3] do nothing 
    output reg [6:0] HEX0,         
    output reg [6:0] HEX2,        
    output reg [6:0] HEX3,        
    output reg [6:0] HEX4,         
    output reg [2:0] LEDR,          // LEDR[0]:div_by_zero, LEDR[1]:sign, LEDR[2]:zero
);

    reg [39:0] numbers;              // 5 numbers, 8 bits each
    reg [7:0] operators;            // 4 operators, 2 bits each    00-> + | 01 -> - | 10 -> * | 11 -> / 
    reg [2:0] counter;             // Track input sequence 4 cycles exactly
    reg [7:0] current_result;
    reg bonus_mode;                
    reg [7:0] precedence_result; 
    reg [7:0] current_number;
    reg [1:0] current_op;
    reg [7:0] operation_result;
    reg [6:0] seg_output;        
    reg [7:0] temp_result0, temp_result1, temp_result2, temp_result3, temp_result4;

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

    function [7:0] get_number;
        input [2:0] index;
        begin
            case(index)
                3'd0: get_number = numbers[7:0];
                3'd1: get_number = numbers[15:8];
                3'd2: get_number = numbers[23:16];
                3'd3: get_number = numbers[31:24];
                3'd4: get_number = numbers[39:32];
                default: get_number = 8'd0;
            endcase
        end
    endfunction

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


//  OP tasks

    // Task definition for 8-bit subtractor
    task bit8_subtract;
        input [7:0] A;
        input [7:0] B;
        output [7:0] Diff;
        output sign;
        
        reg [7:0] A_eff, B_eff;
        reg [7:0] temp_diff;
        reg [7:0] borrow;
        integer i;
    begin
        sign = (A < B);
        A_eff = sign ? B : A;
        B_eff = sign ? A : B;
        
        borrow[0] = 0;
        
        for (i = 0; i < 8; i = i + 1) begin
            temp_diff[i] = A_eff[i] ^ B_eff[i] ^ borrow[i];
            
            if (i < 7) begin  // Don't calculate borrow for last bit becuse always A > B
                borrow[i+1] = (~A_eff[i] & B_eff[i]) | 
                            (B_eff[i] & borrow[i]) | 
                            (~A_eff[i] & borrow[i]);
            end
        end

        Diff = temp_diff;
    end
    endtask


    // Task definition for 8-bit divide
    task bit8_divide;
        input [7:0] dividend;      
        input [7:0] divisor;       
        input dividend_sign;
        input divisor_sign; 
        output [7:0] quotient;     
        output result_sign;
        output div_by_zero;  
        
        reg [7:0] temp_dividend;
        reg [7:0] count;
        reg [7:0] sub_result;
        reg sub_sign;
        reg done;
    begin

        result_sign = dividend_sign ^ divisor_sign;
        
        temp_dividend = dividend;
        count = 8'b0;
        done = 0;
        
        if (divisor == 8'b0) begin
            quotient = 8'hFF;      // Return max value for division by zero
            div_by_zero = 1'b1;    // Set division by zero flag
        end
        else begin
            div_by_zero = 1'b0;
            
            while (!done && (count < 8'hFF)) begin
                bit8_subtract(temp_dividend, divisor, sub_result, sub_sign);
                
                if (sub_sign) begin  
                    done = 1;        
                end
                else begin
                    temp_dividend = sub_result;
                    count = count + 1;
                end
            end
            
            quotient = count;
        end
    end
    endtask


    // Task definition for 8-bit adder
    task bit8_add;
        input [7:0] i1;      
        input [7:0] i2;     
        output [7:0] o;      
        
        reg [7:0] sum;
        reg [7:0] carry;
        reg a_sum, a_carry;    
        reg temp_sum, temp_carry1, temp_carry2; 
        integer i; 
    begin
        // Half adder for bit 0
        a_sum = i1[0] ^ i2[0];     
        a_carry = i1[0] & i2[0];   
        sum[0] = a_sum;
        carry[0] = a_carry;
        
        // Full adders for bits 1-7
        for (i = 1; i < 8; i = i + 1) begin
            a_sum = i1[i] ^ i2[i];
            a_carry = i1[i] & i2[i];
            
            temp_sum = a_sum ^ carry[i-1];
            temp_carry2 = a_sum & carry[i-1];
            
            carry[i] = a_carry | temp_carry2;
            sum[i] = temp_sum;
        end
        
        o = sum;
    end
    endtask


    task bit8_multi;
        input [7:0] i1;   
        input [7:0] i2;      
        input s1;            
        input s2;            
        output [7:0] o;      
        output s;            
        
        reg [7:0] partial_product[7:0];
        reg [7:0] sum1, sum2, sum3, sum4;
        reg [7:0] final_sum1, final_sum2;
    begin
        s = s1 ^ s2;

        partial_product[0] = i2[0] ? i1 : 8'b0;
        partial_product[1] = i2[1] ? {i1[6:0], 1'b0} : 8'b0;
        partial_product[2] = i2[2] ? {i1[5:0], 2'b00} : 8'b0;
        partial_product[3] = i2[3] ? {i1[4:0], 3'b000} : 8'b0;
        partial_product[4] = i2[4] ? {i1[3:0], 4'b0000} : 8'b0;
        partial_product[5] = i2[5] ? {i1[2:0], 5'b00000} : 8'b0;
        partial_product[6] = i2[6] ? {i1[1:0], 6'b000000} : 8'b0;
        partial_product[7] = i2[7] ? {i1[0], 7'b0000000} : 8'b0;

        bit8_add(partial_product[0], partial_product[1], sum1);
        bit8_add(partial_product[2], partial_product[3], sum2);
        bit8_add(partial_product[4], partial_product[5], sum3);
        bit8_add(partial_product[6], partial_product[7], sum4);

        bit8_add(sum1, sum2, final_sum1);
        bit8_add(sum3, sum4, final_sum2);

        bit8_add(final_sum1, final_sum2, o);
    end
    endtask



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






endmodule
