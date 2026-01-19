module shift_add3(i, o);

    input [7:0] i;
    output reg [11:0] o;
    integer j;
    reg [3:0] temp [2:0];

    always @ (*) begin

        temp[0] = 4'd0;
        temp[1] = 4'd0;
        temp[2] = 4'd0;

        for (j = 7; j >= 0; j = j - 1) begin
         temp[2] = {temp[2][2:0], temp[1][3]};
         temp[1] = {temp[1][2:0], temp[0][3]};
         temp[0] = {temp[0][2:0], i[j]};

            if(temp[0] > 4)
                temp[0] = temp[0] + 3;
            if(temp[1] > 4)
                temp[1] = temp[1] + 3;
        end

        o = {temp[2], temp[1], temp[0]};

    end


endmodule