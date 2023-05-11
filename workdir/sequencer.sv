module sequencer(
  input logic clk,
  input logic rst,
  input logic srst,
  input logic go_left,
  input logic go_right,
  output logic [7:0] seq_out
);

  logic [7:0] next_seq_out;

  always @(posedge clk, posedge rst) begin
    if (rst) begin
      next_seq_out <= 8'h80;
    end else if (srst) begin
      next_seq_out <= 8'h80;
    end else if (go_left) begin
      next_seq_out <= {next_seq_out[6:0], next_seq_out[7]};
    end else if (go_right) begin
      next_seq_out <= {next_seq_out[0], next_seq_out[7:1]};
    end
  end

  assign seq_out = next_seq_out;

endmodule

