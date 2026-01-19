module seven_seg_display (I, S);
    input [7:0] I;
    output [20:0] S;
    wire [11:0] O;

    shift_add3 shift_add3_inst (.i(I), .o(O));
    seven_seg seven_seg_inst (.I(O), .S(S));
endmodule

module shift_add3(i, o);
    input [7:0] i;
    output reg [11:0] o;
    integer j;
    reg [3:0] temp [2:0];

    always @(*) begin
        temp[0] = 4'd0;
        temp[1] = 4'd0;
        temp[2] = 4'd0;
        
        for (j = 7; j >= 0; j = j - 1) begin
            temp[2] = {temp[2][2:0], temp[1][3]};
            temp[1] = {temp[1][2:0], temp[0][3]};
            temp[0] = {temp[0][2:0], i[j]};

            if (temp[0] > 4'd4)
                temp[0] = temp[0] + 4'd3;
            if (temp[1] > 4'd4)
                temp[1] = temp[1] + 4'd3;
            if (temp[2] > 4'd4)
                temp[2] = temp[2] + 4'd3;
        end

        o = {temp[2], temp[1], temp[0]};
    end
endmodule

module seven_seg (I, S);
    input [11:0] I;
    output reg [20:0] S;

    reg [3:0] i [2:0];
    reg [6:0] s [2:0];
    integer j;

function [6:0] get_7seg;
    input [3:0] digit;
    begin
        case (digit)
            4'd0: get_7seg = 7'b1000000; // All segments on except g
            4'd1: get_7seg = 7'b1111001; // Only b and c on
            4'd2: get_7seg = 7'b0100100; // a, b, g, e, d on
            4'd3: get_7seg = 7'b0110000; // a, b, g, c, d on
            4'd4: get_7seg = 7'b0011001; // f, g, b, c on
            4'd5: get_7seg = 7'b0010010; // a, f, g, c, d on
            4'd6: get_7seg = 7'b0000010; // All except b on
            4'd7: get_7seg = 7'b1111000; // a, b, c on
            4'd8: get_7seg = 7'b0000000; // All segments on
            4'd9: get_7seg = 7'b0010000; // a, b, g, f, c on
            default: get_7seg = 7'b1111111; // All off (error state)
        endcase
    end
endfunction

    always @(*) begin
        i[2] = I[11:8];
        i[1] = I[7:4];
        i[0] = I[3:0];

        s[2] = get_7seg(i[2]);
        s[1] = get_7seg(i[1]);
        s[0] = get_7seg(i[0]);

        S = {s[2], s[1], s[0]};
    end
endmodule 