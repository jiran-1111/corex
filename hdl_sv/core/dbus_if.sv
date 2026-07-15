/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ziqing Lin
 */

// Data bus interface between LSU and memory
interface DBusIf #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
)();

    localparam int BYTES_PER_WORD = DATA_WIDTH / 8;

    // Address request
    logic read;
    logic write;
    logic [ADDR_WIDTH-1:0] addr;
    logic [DATA_WIDTH-1:0] wdata;
    logic [BYTES_PER_WORD-1:0] wbe;

    // Bus response
    logic gnt;
    logic rack;
    logic wack;
    logic err;
    logic [DATA_WIDTH-1:0] rdata;

    // From LSU to memory
    modport master (
        output read, write, addr, wdata, wbe,
        input gnt, rack, wack, err, rdata
    );

    // From memory to LSU
    modport slave (
        input read, write, addr, wdata, wbe,
        output gnt, rack, wack, err, rdata
    );

endinterface
