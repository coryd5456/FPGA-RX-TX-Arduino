module timing (
    input clk,  // clock
    output clk_out
  );
//25_000_000
  reg [24:0] counter;//register to keep track of counting index
  reg clk_out;
  
  /* Sequential Logic */
  always @(posedge clk) begin
    counter <= counter + 1'b1;
    if (counter == 2_500_000) begin // underscores are ignored
      counter <= 0;
      clk_out <= ~clk_out;
    end
  end
  
endmodule