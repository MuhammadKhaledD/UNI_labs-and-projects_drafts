module example_module(
   input clk,
   input [7:0] operand_a,
   input [7:0] operand_b,
   input sign_a,
   input sign_b,
   output reg [7:0] result,
   output reg result_sign
);

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


   // Always block for synchronous operation
   always @(posedge clk) begin
       bit8_multi(operand_a, operand_b, sign_a, sign_b, result, result_sign);
   end

endmodule
