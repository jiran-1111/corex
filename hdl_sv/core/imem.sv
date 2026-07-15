/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Chun Yang
 */

// Instruction memory
// Use synchronous reset for FPGA BRAM.

//在没有cache的情况下用一个ram为存储
//该文件实现了一个只读的存储器RAM

module IMem #(
    parameter int DATA_WIDTH = 32, // 指令宽度
    parameter int SIZE_BYTES = 16384  //存储器的总容量 
) ( // 端口列表 对外接口
    input logic clk,  // 时钟输入
    input logic rst,  // 同步复位输入
    IBusIf.slave ibus
);

    localparam int BYTES_PER_WORD = DATA_WIDTH / 8;
    localparam int MEM_DEPTH = SIZE_BYTES / BYTES_PER_WORD;
    localparam int MEM_ADDR_WIDTH = $clog2(MEM_DEPTH);
    localparam int BYTE_OFFSET = $clog2(BYTES_PER_WORD);

    // Memory array
    logic [DATA_WIDTH-1:0] mem[0:MEM_DEPTH-1] /*verilator public*/;


    // Control signals (not yet fully supported)
    logic gnt;
    logic err;
    assign gnt = 1;
    assign err = 0;

    // Address decoding
    logic [MEM_ADDR_WIDTH-1:0] mem_addr;
    assign mem_addr = ibus.addr[MEM_ADDR_WIDTH+BYTE_OFFSET-1:BYTE_OFFSET];

    // Data register
    logic [DATA_WIDTH-1:0] rdata_q;
    assign ibus.rdata = rdata_q;

    // Read data from memory on request.
    // No reset to enable Vivado BRAM optional output register inference for
    // better resource utilization.
    always_ff @(posedge clk) begin
        if (ibus.req && gnt) begin
            rdata_q <= mem[mem_addr];
        end
    end

    // Bus response
    assign ibus.gnt = gnt;
    assign ibus.err = err;
    always_ff @(posedge clk) begin
        if (rst) begin
            ibus.ack <= 0;
        end else begin
            ibus.ack <= ibus.req && gnt;
        end
    end

endmodule

//顶层模块
// Top-level module for unit test
module IMemTop #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int SIZE_BYTES = 16384
) (
    input logic clk,
    input logic rst,

    // Address request
    input logic req,
    input logic [ADDR_WIDTH-1:0] addr,

    // Data response
    output logic gnt,
    output logic ack,
    output logic err,
    output logic [DATA_WIDTH-1:0] rdata
);
    IBusIf #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) ibus();

    assign ibus.req = req;
    assign ibus.addr = addr;
    assign gnt = ibus.gnt;
    assign ack = ibus.ack;
    assign err = ibus.err;
    assign rdata = ibus.rdata;

    IMem #(
        .DATA_WIDTH(DATA_WIDTH),
        .SIZE_BYTES(SIZE_BYTES)
    ) imem (
        .clk(clk),
        .rst(rst),
        .ibus(ibus.slave)
    );

endmodule
