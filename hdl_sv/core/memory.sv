/*
 * COREX: Co-modeling RISC-V Example Core
 * 
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 * 
 * Author: Ran Ji
 */
module memory_unit #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
) (
    input cLk,
    input rst,
    input stall,
    input load,
    input store,
    input opSel,
    input [ADDRESS_BITS-1:0] address,
    input [DATA_WIDTH-1:0] store_data,
    input [DATA_WIDTH-1:0] ALU_Result,
    
    output [ADDRESS_BITS-1:0] data_addr,
    output [DATA_WIDTH-1:0] load_data,
    output [DATA_WIDTH-1:0] bypass_data,


);

DMemTop #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
) dmem (
    .clk(cLk),
    .rst(rst),
    .read(),
    .write(),
    .addr(),
    .wdata(),
    .wbe(),
    
    .gnt(),
    .rack(),
    .wack(),
    .err(),
    .rdata()

);

//mux for bypassing
assign bypass_data = (opSel)? load_data :ALU_Result; 

endmodule
