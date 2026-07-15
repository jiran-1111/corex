/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ziqing Lin
 */

// Data memory
// Features:
// - Supports one asynchronous word read port and one synchronous byte-write port.
// - Reset suppresses bus responses and memory writes.
// - Use INIT_FILE to initialize memory content for simulation.
// - Use separated read and write acknowledge signals.
module DMem #(
    parameter int DATA_WIDTH = 32,
    parameter int SIZE_BYTES = 16384,
    parameter string INIT_FILE = ""
) (
    input logic clk,
    input logic rst,
    DBusIf.slave dbus
);

    localparam int BYTES_PER_WORD = DATA_WIDTH / 8;
    localparam int MEM_DEPTH = SIZE_BYTES / BYTES_PER_WORD;
    localparam int MEM_ADDR_WIDTH = $clog2(MEM_DEPTH);
    localparam int BYTE_OFFSET = $clog2(BYTES_PER_WORD);

    // Memory array
    logic [DATA_WIDTH-1:0] mem[0:MEM_DEPTH-1];

    initial begin
        for (int i = 0; i < MEM_DEPTH; i++) begin
            mem[i] = '0;
        end

        if (INIT_FILE != "") begin
            $readmemh(INIT_FILE, mem);
        end
    end

    // Control signals (not yet fully supported)
    logic gnt;
    logic err;
    assign gnt = 1;
    assign err = 0;

    // Address decoding
    logic [MEM_ADDR_WIDTH-1:0] mem_addr;
    assign mem_addr = dbus.addr[MEM_ADDR_WIDTH+BYTE_OFFSET-1:BYTE_OFFSET];

    logic [DATA_WIDTH-1:0] write_data;

    // Prepare write data based on write byte enable.
    always_comb begin
        write_data = mem[mem_addr];
        for (int i = 0; i < BYTES_PER_WORD; i++) begin
            if (dbus.wbe[i]) begin
                write_data[i*8 +: 8] = dbus.wdata[i*8 +: 8];
            end
        end
    end

    // Read data from memory.
    assign dbus.rdata = mem[mem_addr];

    // Write data to memory on request and acknowledge it after the write edge.
    always_ff @(posedge clk) begin
        if (rst) begin
            dbus.wack <= 0;
        end else begin
            if (dbus.write && gnt) begin
                mem[mem_addr] <= write_data;
            end

            dbus.wack <= dbus.write && gnt;
        end
    end

    // Bus response
    assign dbus.gnt = gnt;
    assign dbus.err = err;
    assign dbus.rack = !rst && dbus.read && gnt;

endmodule


// Top-level module for unit test
module DMemTop #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int SIZE_BYTES = 16384,
    parameter string INIT_FILE = "",
    localparam int BYTES_PER_WORD = DATA_WIDTH / 8
) (
    input logic clk,
    input logic rst,

    // Address request
    input logic read,
    input logic write,
    input logic [ADDR_WIDTH-1:0] addr,
    input logic [DATA_WIDTH-1:0] wdata,
    input logic [BYTES_PER_WORD-1:0] wbe,

    // Bus response
    output logic gnt,
    output logic rack,
    output logic wack,
    output logic err,
    output logic [DATA_WIDTH-1:0] rdata
);
    DBusIf #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dbus();

    assign dbus.read = read;
    assign dbus.write = write;
    assign dbus.addr = addr;
    assign dbus.wdata = wdata;
    assign dbus.wbe = wbe;
    assign gnt = dbus.gnt;
    assign rack = dbus.rack;
    assign wack = dbus.wack;
    assign err = dbus.err;
    assign rdata = dbus.rdata;

    DMem #(
        .DATA_WIDTH(DATA_WIDTH),
        .SIZE_BYTES(SIZE_BYTES),
        .INIT_FILE(INIT_FILE)
    ) dmem (
        .clk(clk),
        .rst(rst),
        .dbus(dbus.slave)
    );

endmodule
