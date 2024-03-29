module mojo_top(
    // 50MHz clock input
    input clk,
    // Input from reset button (active low)
    input rst_n,
    // cclk input from AVR, high when AVR is ready
    input cclk,
    // Outputs to the 8 onboard LEDs
    output[7:0]led,
    // AVR SPI connections
    output spi_miso,
    input spi_ss,
    input spi_mosi,
    input spi_sck,
    // AVR ADC channel select
    output [3:0] spi_channel,
    // Serial connections
    input avr_tx, // AVR Tx => FPGA Rx
    output avr_rx, // AVR Rx => FPGA Tx
    input avr_rx_busy, // AVR Rx buffer full
    
    output TX,
    output check
    );

wire rst = ~rst_n; // make reset active high

// these signals should be high-z when not used
assign spi_miso = 1'bz;
assign avr_rx = 1'bz;
assign spi_channel = 4'bzzzz;

assign led[6:0] = 7'b0;
assign led[7] = busy;
wire block = 1'b0;
wire busy;
reg [7:0] data = 8'b11111111;
wire new_data = 1'b1;
wire Q;
assign check = busy;
timing one (
  .clk(clk),
  .clk_out(Q)
);
//assign Q = busy;

always @(negedge busy) begin
data <= ~data;
end

serial_TX  #(250) txBlock (
         .clk(clk),
         .rst(rst),
         .tx(TX),
         .block(block),
         .busy(busy),
         .data(data),
         .new_data(new_data)
    );

endmodule