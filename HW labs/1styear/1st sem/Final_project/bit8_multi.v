module bit8_multi(
    input [7:0] i1,     
    input [7:0] i2,     
    input s1,          
    input s2,           
    output [7:0] o,    
    output s            
);

    assign s = s1 ^ s2;

    wire [7:0] partial_product[7:0];

    assign partial_product[0] = i2[0] ? i1 : 8'b0;
    assign partial_product[1] = i2[1] ? {i1[6:0], 1'b0} : 8'b0;
    assign partial_product[2] = i2[2] ? {i1[5:0], 2'b00} : 8'b0;
    assign partial_product[3] = i2[3] ? {i1[4:0], 3'b000} : 8'b0;
    assign partial_product[4] = i2[4] ? {i1[3:0], 4'b0000} : 8'b0;
    assign partial_product[5] = i2[5] ? {i1[2:0], 5'b00000} : 8'b0;
    assign partial_product[6] = i2[6] ? {i1[1:0], 6'b000000} : 8'b0;
    assign partial_product[7] = i2[7] ? {i1[0], 7'b0000000} : 8'b0;


    wire [7:0] sum1, sum2, sum3, sum4;

    bit8_adder adder1 (
        .i1(partial_product[0]),
        .i2(partial_product[1]),
        .o(sum1)
    );

    bit8_adder adder2 (
        .i1(partial_product[2]),
        .i2(partial_product[3]),
        .o(sum2)
    );

    bit8_adder adder3 (
        .i1(partial_product[4]),
        .i2(partial_product[5]),
        .o(sum3)
    );

    bit8_adder adder4 (
        .i1(partial_product[6]),
        .i2(partial_product[7]),
        .o(sum4)
    );

    wire [7:0] final_sum1, final_sum2;

    bit8_adder adder5 (
        .i1(sum1),
        .i2(sum2),
        .o(final_sum1)
    );

    bit8_adder adder6 (
        .i1(sum3),
        .i2(sum4),
        .o(final_sum2)
    );

    bit8_adder adder7 (
        .i1(final_sum1),
        .i2(final_sum2),
        .o(o)
    );

endmodule