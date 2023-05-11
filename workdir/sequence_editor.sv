module sequence_editor (
  input logic clk,
  input logic rst,
  input logic [1:0] mode,
  input logic [2:0] set_time_idx,
  input logic [3:0] tgl_play_smpl,
  output logic [3:0] seq_smpl_1,
  output logic [3:0] seq_smpl_2,
  output logic [3:0] seq_smpl_3,
  output logic [3:0] seq_smpl_4,
  output logic [3:0] seq_smpl_5,
  output logic [3:0] seq_smpl_6,
  output logic [3:0] seq_smpl_7,
  output logic [3:0] seq_smpl_8
);

  logic [3:0] seq_smpl [7:0];

  always @(posedge clk, posedge rst) begin
    if (rst) begin
      for (integer i = 0; i < 8; i++) begin
        seq_smpl[i] <= 4'b0000;
      end
    end 
    else if (mode == 0) begin
      // If in EDIT mode
      seq_smpl[set_time_idx] <= tgl_play_smpl ^ seq_smpl[set_time_idx];
    end
  end

  assign seq_smpl_1 = seq_smpl[0];
  assign seq_smpl_2 = seq_smpl[1];
  assign seq_smpl_3 = seq_smpl[2];
  assign seq_smpl_4 = seq_smpl[3];
  assign seq_smpl_5 = seq_smpl[4];
  assign seq_smpl_6 = seq_smpl[5];
  assign seq_smpl_7 = seq_smpl[6];
  assign seq_smpl_8 = seq_smpl[7];

endmodule
