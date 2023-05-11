module clkdiv #(
    parameter BITLEN = 8
) (
    input logic clk, rst, 
    input logic [BITLEN-1:0] lim,
    output logic hzX
);

logic [BITLEN - 1: 0] counter;

always_ff @(posedge clk, posedge rst) begin
    if (rst) begin
    	hzX<= 0;
        counter <= 0;
    end
    else begin
      counter <= counter + 1;
      if (counter == lim) begin
      	hzX <= ~hzX;
      	counter <= 0;
      end
    end
end

endmodule
