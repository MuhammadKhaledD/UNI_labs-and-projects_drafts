module arithmetic_operations(
    input [8:0] a,
    input [8:0] b,
    input [1:0] op,
    output reg [8:0] result,
    output reg sign,
    output reg div_by_zero
);
    // Operation codes
    localparam ADD = 2'b00;
    localparam SUB = 2'b01;
    localparam MUL = 2'b10;
    localparam DIV = 2'b11;

    // Extract magnitudes and signs
    wire a_sign = a[8];
    wire b_sign = b[8];
    wire [7:0] a_mag = a[7:0];
    wire [7:0] b_mag = b[7:0];

    // Temporary variables for calculations
    reg [7:0] temp_result;
    reg [15:0] mul_temp;

    always @(*) begin
        // Default values
        div_by_zero = 0;
        sign = 0;
        result = 9'b0;
        
        case(op)
            ADD: begin
                if (a_sign == b_sign) begin
                    // Same signs - add magnitudes, keep sign
                    temp_result = bit8_adder(a_mag , b_mag);
                    sign = a_sign;
                    result = {sign, temp_result};
                end else begin
                    // Different signs - subtract smaller from larger
                    if (a_mag >= b_mag) begin
                        temp_result = bit8_subtractor(a_mag , b_mag);
                        sign = a_sign;
                    end else begin
                        temp_result = bit8_subtractor(b_mag , a_mag);
                        sign = b_sign;
                    end
                    result = {sign, temp_result};
                end
            end
            
            SUB: begin
                if (a_sign != b_sign) begin
                    // Different signs - add magnitudes
                    temp_result = bit8_adder(a_mag , b_mag);
                    sign = a_sign;
                    result = {sign, temp_result};
                end else begin
                    // Same signs - subtract magnitudes
                    if (a_mag >= b_mag) begin
                        temp_result = bit8_subtractor(a_mag , b_mag);
                        sign = a_sign;
                    end else begin
                        temp_result = bit8_subtractor(b_mag , a_mag);
                        sign = !a_sign;
                    end
                    result = {sign, temp_result};
                end
            end
            
            MUL: begin
                // Multiply magnitudes
                mul_temp = bit8_multiply(a_mag , b_mag);
                // Result sign is XOR of input signs
                sign = a_sign ^ b_sign;
                // Take the lower 8 bits for the result
                result = {sign, mul_temp[7:0]};
            end
            
            DIV: begin
                if (b_mag == 0) begin
                    result = 9'd0;
                    div_by_zero = 1;
                    sign = 0;
                end else begin
                    // Divide magnitudes
                    temp_result = divide_8bit(a_mag , b_mag);
                    // Result sign is XOR of input signs
                    sign = a_sign ^ b_sign;
                    result = {sign, temp_result};
                end
            end
        endcase
    end


function [1:0] full_subtractor;
        input A, B, Bin;
        reg D, Bout;

        begin
            // Calculate the Difference (D)
            D = A ^ B ^ Bin;

            // Calculate the Borrow (Bout)
            Bout = (~A & (B | Bin)) | (B & Bin);

            // Return both the Borrow (Bout) and Difference (D) as a 2-bit vector
            full_subtractor = {Bout, D};
        end
endfunction

    // 8-bit subtractor function that performs bitwise subtraction
function [7:0] bit8_subtractor;
        input [7:0] A, B; // 8-bit inputs A and B
        reg [7:0] Diff;    // Register for storing the difference
        reg [7:0] Borrow;  // Register for storing the borrow
        reg [7:0] A_eff, B_eff; // Effective A and B after sign handling
        integer i;

        begin
            // Swap inputs to ensure non-negative subtraction result
            A_eff = (A < B) ? B : A;  // Effective A (swap if A < B)
            B_eff = (A < B) ? A : B;  // Effective B (swap if A < B)

            // Initialize the difference and borrow
            Diff = 8'b0;
            Borrow = 8'b0;

            // Perform bitwise subtraction
            for (i = 0; i < 8; i = i + 1) begin
                if (i == 0) begin
                    {Borrow[i], Diff[i]} = full_subtractor(A_eff[i], B_eff[i], 1'b0);
                end else begin
                    {Borrow[i], Diff[i]} = full_subtractor(A_eff[i], B_eff[i], Borrow[i-1]);
                end
            end

            // Return the final 8-bit difference
            bit8_subtractor = Diff;
        end
endfunction


// Full adder function: calculates the sum and carry for each bit
function [1:0] full_adder;
        input A, B, Cin;
        reg S, Cout;
        begin
            // Calculate the sum (S)
            S = A ^ B ^ Cin;

            // Calculate the carry (Cout)
            Cout = (A & B) | (Cin & (A ^ B));

            // Return both the Carry (Cout) and Sum (S) as a 2-bit vector
            full_adder = {Cout, S};
        end
endfunction

    // 8-bit adder function that performs bitwise addition
function [7:0] bit8_adder;
        input [7:0] A, B; // 8-bit inputs A and B
        reg [7:0] sum;    // Register for storing the sum
        reg [7:0] carry;  // Register for storing the carry
        integer i;
        begin
            // Initialize sum and carry
            sum = 8'b0;
            carry = 8'b0;

            // Perform bitwise addition
            for (i = 0; i < 8; i = i + 1) begin
                if (i == 0) begin
                    {carry[i], sum[i]} = full_adder(A[i], B[i], 1'b0);
                end else begin
                    {carry[i], sum[i]} = full_adder(A[i], B[i], carry[i-1]);
                end
            end

            // Return the final 8-bit sum
            bit8_adder = sum;
        end
endfunction

 // Function to compute 8-bit multiplication
    function [7:0] bit8_multiply;
        input [7:0] A, B;
        reg [7:0] partial_product[7:0];
        reg [7:0] temp_sum;
        integer i;
        begin
            // Generate partial products
            partial_product[0] = B[0] ? A : 8'b0;
            partial_product[1] = B[1] ? {A[6:0], 1'b0} : 8'b0;
            partial_product[2] = B[2] ? {A[5:0], 2'b00} : 8'b0;
            partial_product[3] = B[3] ? {A[4:0], 3'b000} : 8'b0;
            partial_product[4] = B[4] ? {A[3:0], 4'b0000} : 8'b0;
            partial_product[5] = B[5] ? {A[2:0], 5'b00000} : 8'b0;
            partial_product[6] = B[6] ? {A[1:0], 6'b000000} : 8'b0;
            partial_product[7] = B[7] ? {A[0], 7'b0000000} : 8'b0;

            // Sum up partial products using a nested function for addition
            temp_sum = 8'b0;
            for (i = 0; i < 8; i = i + 1) begin
                temp_sum = bit8_adder(temp_sum, partial_product[i]);
            end
            
            // Return the final product
            bit8_multiply = temp_sum;
        end
endfunction

// Function that performs division using a full subtractor
function [15:0] divide_8bit;
        input [7:0] dividend;
        input [7:0] divisor;
        reg [7:0] quotient;
        reg [7:0] partial_remainder;
        reg [7:0] temp_remainder;
        reg borrow;
        reg [1:0] sub_result;
        integer i, j;

        begin
            // Initialize outputs
            quotient = 8'b0;
            partial_remainder = 8'b0;

            if (divisor != 0) begin
                for (i = 7; i >= 0; i = i - 1) begin
                    // Shift left partial remainder and bring down next bit
                    partial_remainder = {partial_remainder[6:0], dividend[i]};

                    // Perform bit-by-bit subtraction
                    temp_remainder = partial_remainder;
                    borrow = 0;
                    for (j = 0; j < 8; j = j + 1) begin
                        sub_result = full_subtractor(temp_remainder[j], divisor[j], borrow);
                        temp_remainder[j] = sub_result[0];  // Difference
                        borrow = sub_result[1];            // Borrow out
                    end

                    // If subtraction successful, update remainder and set quotient bit
                    if (!borrow) begin
                        partial_remainder = temp_remainder;
                        quotient[i] = 1; 
                    end
                end
            end else begin
                // Division by zero case
                quotient = 8'b11111111;
                partial_remainder = dividend;
            end

            // Return concatenated quotient and remainder
            divide_8bit = {quotient};
        end
endfunction
 
endmodule

