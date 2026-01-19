module tb;

    reg [7:0] i1, i2;
    wire [7:0] o;  // Output
    wire s;        // Sign bit (not used here)

    // Instantiate the multiplier
    bit8_multi uut (
        .i1(i1),
        .i2(i2),
        .s1(1'b0),   // Assume unsigned inputs
        .s2(1'b0),   // Assume unsigned inputs
        .o(o),
        .s(s)
    );

    initial begin
        // Test Case 1: 3 * 2 = 6
        i1 = 8'd3;
        i2 = 8'd2;
        #10;
        $display("Test Case 1: i1 = %d, i2 = %d, o = %d", i1, i2, o);

        // Test Case 2: 3 * 81 = 243 (maximum output within 8 bits)
        i1 = 8'd3;
        i2 = 8'd81;
        #10;
        $display("Test Case 2: i1 = %d, i2 = %d, o = %d", i1, i2, o);

        // Test Case 3: 100 * 50 = 5000 (output truncated to 8 bits)
        i1 = 8'd100;
        i2 = 8'd50;
        #10;
        $display("Test Case 3: i1 = %d, i2 = %d, o = %d", i1, i2, o);

        // Test Case 4: 1 * 1 = 1
        i1 = 8'd1;
        i2 = 8'd1;
        #10;
        $display("Test Case 4: i1 = %d, i2 = %d, o = %d", i1, i2, o);

        $finish;
    end
endmodule

