/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ziqing Lin
 */

// Integer register file
// Features:
// - Two combinational read ports and one synchronous write port.
// - Synchronous reset clears all registers.
// - x0 is hardwired to zero when ZERO_X0 is set.
module RegFile #(
    parameter int REG_DATA_WIDTH = 32,
    parameter int REG_SEL_WIDTH = 5,
    parameter bit ZERO_X0 = 1'b1
) (
    input logic clk,
    input logic rst,

    input logic wen,
    input logic [REG_SEL_WIDTH-1:0] waddr,
    input logic [REG_DATA_WIDTH-1:0] wdata,

    input logic [REG_SEL_WIDTH-1:0] raddr1,
    input logic [REG_SEL_WIDTH-1:0] raddr2,
    output logic [REG_DATA_WIDTH-1:0] rdata1,
    output logic [REG_DATA_WIDTH-1:0] rdata2
);

    localparam int REG_COUNT = 2 ** REG_SEL_WIDTH;

    // Register array
    logic [REG_DATA_WIDTH-1:0] regs[0:REG_COUNT-1];

    generate
        if (ZERO_X0) begin : gen_zero_x0
            assign rdata1 = (raddr1 == '0) ? '0 : regs[raddr1];
            assign rdata2 = (raddr2 == '0) ? '0 : regs[raddr2];
        end else begin : gen_writable_x0
            assign rdata1 = regs[raddr1];
            assign rdata2 = regs[raddr2];
        end
    endgenerate

    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < REG_COUNT; i++) begin
                regs[i] <= '0;
            end
        end else if (!rst && wen) begin
            regs[waddr] <= wdata;
        end
    end

endmodule
