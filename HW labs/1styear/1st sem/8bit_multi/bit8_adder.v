module bit8_adder(
    input [7:0] i1,    
    input [7:0] i2,      
    output [7:0] o       
);
    wire [7:0] sum;
    wire [7:0] carry;

    half_adder HA0 (
        .a(i1[0]),
        .b(i2[0]),
        .sum(sum[0]),
        .carry(carry[0])
    );

    full_adder FA1 (
        .a(i1[1]),
        .b(i2[1]),
        .cin(carry[0]),
        .sum(sum[1]),
        .carry(carry[1])
    );

    full_adder FA2 (
        .a(i1[2]),
        .b(i2[2]),
        .cin(carry[1]),
        .sum(sum[2]),
        .carry(carry[2])
    );

    full_adder FA3 (
        .a(i1[3]),
        .b(i2[3]),
        .cin(carry[2]),
        .sum(sum[3]),
        .carry(carry[3])
    );

    full_adder FA4 (
        .a(i1[4]),
        .b(i2[4]),
        .cin(carry[3]),
        .sum(sum[4]),
        .carry(carry[4])
    );

    full_adder FA5 (
        .a(i1[5]),
        .b(i2[5]),
        .cin(carry[4]),
        .sum(sum[5]),
        .carry(carry[5])
    );

    full_adder FA6 (
        .a(i1[6]),
        .b(i2[6]),
        .cin(carry[5]),
        .sum(sum[6]),
        .carry(carry[6])
    );

    full_adder FA7 (
        .a(i1[7]),
        .b(i2[7]),
        .cin(carry[6]),
        .sum(sum[7]),
        .carry(carry[7])
    );

    assign o = sum;

endmodule





// ------------------------------------------------------------------------------------------------------





module half_adder(
    input a,      
    input b,      
    output sum,   
    output carry  
);
    assign sum = a ^ b;  // Sum is the XOR of the inputs
    assign carry = a & b;  // Carry is the AND of the inputs
endmodule






// ------------------------------------------------------------------------------------------------------





module full_adder(
    input a,      
    input b,      
    input cin,    
    output sum,   
    output carry  
);
    wire sum_half, carry_half1, carry_half2;

    half_adder HA1 (
        .a(a),
        .b(b),
        .sum(sum_half),
        .carry(carry_half1)
    );

    half_adder HA2 (
        .a(sum_half),
        .b(cin),
        .sum(sum),
        .carry(carry_half2)
    );

    assign carry = carry_half1 | carry_half2;
endmodule


