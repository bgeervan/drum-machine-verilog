module controller (
  input logic clk, //also used as strobe
  input logic rst,
  input logic set_edit,
  input logic set_play,
  input logic set_raw,
  output logic [1:0] mode
 );
 
  typedef enum logic [1:0] { EDIT=2'd0, PLAY=2'd1, RAW=2'd2 } sysmode_t;
 
  logic [1:0] current_mode;
  //logic [1:0] next_mode;
  
  always @(posedge clk) begin
    if (rst) begin
      current_mode <= EDIT;
    end
    else begin
      if (set_edit) begin
        current_mode <= EDIT;
      end
      else if (set_play) begin
        current_mode <= PLAY;
      end
      else if (set_raw) begin
        current_mode <= RAW;
      end
    end
  end
   
 assign mode = current_mode;
   
endmodule
