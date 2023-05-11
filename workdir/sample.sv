module sample #(
    parameter SAMPLE_FILE = "../audio/kick.mem",
    parameter SAMPLE_LEN = 4000
)
(
    input clk, rst, enable,
    output logic [7:0] out
);

logic [7:0] audio_mem [4095:0];
initial $readmemh(SAMPLE_FILE, audio_mem, 0, SAMPLE_LEN);

logic [11:0]next_counter;
logic prev_en;
logic [7:0] sample;

// always @ (posedge clk) begin 
//    prev_en <= enable;
// end

always @(posedge clk, posedge rst) begin
  if (rst) begin
    next_counter <= 0;
    out <= 0;
  end
  else begin
    prev_en <= enable;
    out <= audio_mem[next_counter];
    //out <= sample;
  
  if (prev_en && enable) begin
     next_counter <= next_counter + 1;
    if (next_counter == SAMPLE_LEN) begin
      next_counter <= 0;
    end
  end
  else if (prev_en && ~enable) begin
    next_counter <= 0;
  end
  else begin
    next_counter <= next_counter;
  end
  end
end

// always @(posedge clk) begin
//     sample <= audio_mem[next_counter];
//     out <= sample;
// end

//assign prev_en = enable;
   
endmodule
