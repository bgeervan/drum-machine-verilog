module top (
  // I/O ports
  input  logic hz2m, hz100, reset,
  input  logic [20:0] pb,
  /* verilator lint_off UNOPTFLAT */
  output logic [7:0] left, right,
         ss7, ss6, ss5, ss4, ss3, ss2, ss1, ss0,
  output logic red, green, blue,

  // UART ports
  output logic [7:0] txdata,
  input  logic [7:0] rxdata,
  output logic txclk, rxclk,
  input  logic txready, rxready
);

//EDIT MODE
  logic [4:0] keycode;
  logic strobe;
  logic [1:0]mode;
  logic bpm_clk;
  
  scankey sk1(.clk(hz2m), .rst(reset), .in(pb[19:0]), .out(keycode), .strobe(strobe));

  controller c1(.clk(strobe), .rst(reset), .set_edit(pb[19]), .set_play(pb[18]), .set_raw(pb[16]), .mode(mode));
  
  //assign mode = 0;

  
  always_comb begin 
  if (mode == 0) begin
    blue = 1'b1;
    green = 0;
    red = 0;
  end
  else if (mode == 1) begin 
    green = 1'b1;
    red = 0;
    blue = 0;
  end
  else if (mode == 2) begin
    red = 1'b1;
    green = 0;
    blue = 0;
  end 
  else begin
    blue = 0;
    green = 0;
    red = 0;
  end 
end 


logic not_edit;
assign not_edit = ~(mode == 0);

logic [7:0] edit_seq_out,x;

// assign edit_seq_out = 0;
sequencer seq_edit1(.clk(strobe), .rst(reset), .srst(not_edit), .go_left(pb[11]), .go_right(pb[8]), .seq_out(edit_seq_out));

logic [2:0] encoder_value;
prienc8to3 enc1(.in(seq_out), .out(encoder_value));

logic [3:0]edit_play_smpl[7:0];

sequence_editor se1 (.clk(strobe), .rst(reset), .mode(mode), .set_time_idx(encoder_value), .tgl_play_smpl(pb[3:0]), .seq_smpl_1(edit_play_smpl[0]), 
.seq_smpl_2(edit_play_smpl[1]), .seq_smpl_3(edit_play_smpl[2]), .seq_smpl_4(edit_play_smpl[3]), .seq_smpl_5(edit_play_smpl[4]), .seq_smpl_6(edit_play_smpl[5]),
.seq_smpl_7(edit_play_smpl[6]), .seq_smpl_8(edit_play_smpl[7]));

assign {ss7[5], ss7[1], ss7[4], ss7[2]} = edit_play_smpl[7];
assign {ss6[5], ss6[1], ss6[4], ss6[2]} = edit_play_smpl[6];
assign {ss5[5], ss5[1], ss5[4], ss5[2]} = edit_play_smpl[5];
assign {ss4[5], ss4[1], ss4[4], ss4[2]} = edit_play_smpl[4];
assign {ss3[5], ss3[1], ss3[4], ss3[2]} = edit_play_smpl[3];
assign {ss2[5], ss2[1], ss2[4], ss2[2]} = edit_play_smpl[2];
assign {ss1[5], ss1[1], ss1[4], ss1[2]} = edit_play_smpl[1];
assign {ss0[5], ss0[1], ss0[4], ss0[2]} = edit_play_smpl[0];


//PLAY MODE
logic [7:0]play_seq_out;
logic [7:0] seq_out;

logic [7:0] temp;
logic not_edit1;
logic not_play1;

assign not_play1= ~(mode == 1); 

clkdiv#(20) cd1(.clk(hz2m), .rst(reset), .lim(20'd499999), .hzX(bpm_clk));
sequencer play(.clk(bpm_clk), .rst(reset), .srst(not_play1), .go_left(1'b0), .go_right(1'b1), .seq_out(play_seq_out));
//assign play_seq_out = 0;

always_ff @ (posedge hz2m, posedge reset) begin 
  if (reset) begin 
    seq_out <= 0;
    //temp <= 0;
  end
  else begin 
    if (mode == 2'd1) begin 
      seq_out <= play_seq_out;
      //seq_out <= temp;
    end
    else if (mode == 2'd0) begin 
      seq_out <= edit_seq_out;
      //seq_out <= temp;
    end
  end
end

assign {left[7], left[5], left[3], left[1], right[7], right[5], right[3], right[1]} = seq_out;


//RAW MODE 
logic [3:0] raw_play_smpl;

assign raw_play_smpl = pb[3:0];

logic [3:0] play_smpl;

always_ff @ (posedge hz2m, posedge reset) begin 
  if (reset) begin 
    play_smpl <= 0;
  end 
  //If in EDIT mode
  else if (mode == 2'd0) begin 
    play_smpl <= 0;
  end
  //If in PLAY mode
  else if (mode == 2'd1) begin 
    play_smpl <= ((enable_ctr <= 900000) ? edit_play_smpl[encoder_value] : 4'b0) | raw_play_smpl;
  end
  //IF in RAW mode
  else if (mode == 2'd2) begin 
    play_smpl <= raw_play_smpl;
  end
end

// Integrating Work 

//Setting up Audio Samples 
logic sample_clk;
clkdiv #(8) cd2(.clk(hz2m), .rst(reset), .lim(8'd128), .hzX(sample_clk));
//assign sample_clk = 0;
logic [7:0] sample_data [3:0];

sample #(
    .SAMPLE_FILE("../audio/kick.mem"),
    .SAMPLE_LEN(4000)
) sample_kick (
    .clk(sample_clk),
    .rst(reset),
    .enable(play_smpl[3]),
    .out(sample_data[0])
);

sample #(
    .SAMPLE_FILE("../audio/clap.mem"),
    .SAMPLE_LEN(4000)
) sample_clap (
    .clk(sample_clk),
    .rst(reset),
    .enable(play_smpl[2]),
    .out(sample_data[1])
);

sample #(
    .SAMPLE_FILE("../audio/hihat.mem"),
    .SAMPLE_LEN(4000)
) sample_hihat (
    .clk(sample_clk),
    .rst(reset),
    .enable(play_smpl[1]),
    .out(sample_data[2])
);

sample #(
    .SAMPLE_FILE("../audio/snare.mem"),
    .SAMPLE_LEN(4000)
) sample_snare (
    .clk(sample_clk),
    .rst(reset),
    .enable(play_smpl[0]),
    .out(sample_data[3])
);

//Checking for Underflow or Overflow
logic [7:0]sample_sum1;
logic [7:0]sample_sum2;
logic [7:0]overall_sum;

always_comb begin 
 sample_sum1 = sample_data[0] + sample_data[1]; //sum of kick and hihat
 sample_sum2 = sample_data[2] + sample_data[3]; //sum of clap and snare 
 
 //Sum 1 (kick and hihat)
 if (sample_data[1][7] == 1'b1 & sample_data[0][7] == 1'b1 & sample_sum1[7] == 1'b0) begin 
  sample_sum1 = -128;//8'b10000000; 
 end
 else if (sample_data[1][7] == 1'b0 & sample_data[0][7] == 1'b0 & sample_sum1[7] == 1'b1) begin 
  sample_sum1 = 127;//8'b01111111;
 end
 
 //Sum 2 (clap and snare)
 if (sample_data[2][7] == 1'b1 & sample_data[3][7] == 1'b1 & sample_sum2[7] == 1'b0) begin 
  sample_sum2 = -128;//8'b10000000;
 end
 else if (sample_data[2][7] == 1'b0 & sample_data[3][7] == 1'b0 & sample_sum2[7] == 1'b1) begin 
  sample_sum2 = 127;//8'b01111111;
 end
  overall_sum = (sample_sum1 + sample_sum2);// ^ 8'd128; //sum of both 

 //Overall sum
 if (sample_sum1[7] == 1'b1 & sample_sum2[7] == 1'b1 & overall_sum[7] == 1'b0) begin 
  overall_sum = -128;//8'b10000000;
 end
 else if (sample_sum1[7] == 1'b0 & sample_sum2[7] == 1'b0 & overall_sum[7] == 1'b1) begin 
  overall_sum = 127;//8'b01111111
 end
end
logic [7:0] overall_sum1;
assign overall_sum1 = overall_sum ^ 8'd128;

//Instantiating PWM
//logic enable;
pwm #(64) pwm_inst(.clk(hz2m), .rst(reset), .enable(1), .duty_cycle(overall_sum1[7:2]), 
.counter(),
.pwm_out(right[0])
);


   logic prev_bpm_clk;
   logic [31:0] enable_ctr;
   always_ff @(posedge hz2m, posedge reset)
   if (reset) begin
       prev_bpm_clk <= 0;
       enable_ctr <= 0;
   end
   // otherwise, if we're in PLAY mode
   else if (mode == 1) begin
       // if we're on a rising edge of bpm_clk, indicating 
       // the beginning of the beat, reset the counter.
       if (~prev_bpm_clk && bpm_clk) begin
       enable_ctr <= 0;
       prev_bpm_clk <= 1;
       end
       // if we're on a falling edge of bpm_clk, indicating 
       // the middle of the beat, set the counter to half its value
       // to correct for drift.
       else if (prev_bpm_clk && ~bpm_clk) begin
           enable_ctr <= 499999;
           prev_bpm_clk <= 0;
       end
       // otherwise count to 1 million, and reset to 0 when that value is reached.
       else begin
           enable_ctr <= (enable_ctr == 999999) ? 0 : enable_ctr + 1;
       end
   end
   // reset the counter so we start on time again.
   else begin
       prev_bpm_clk <= 0;
       enable_ctr <= 0;
   end


endmodule
