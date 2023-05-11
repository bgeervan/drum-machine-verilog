module prienc8to3 (
  input logic [7:0] in,
  output logic [2:0] out
);

  logic [2:0] out_int;
always_comb begin
    if (in[7]) begin
      out_int = 3'b111;
    end else if (in[6]) begin
      out_int = 3'b110;
    end else if (in[5]) begin
      out_int = 3'b101;
    end else if (in[4]) begin
      out_int = 3'b100;
    end else if (in[3]) begin
      out_int = 3'b011;
    end else if (in[2]) begin
      out_int = 3'b010;
    end else if (in[1]) begin
      out_int = 3'b001;
    end else begin
      out_int = 3'b000;
    end
  end

  assign out = out_int;

endmodule
