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
// - Read-after-write to the same address returns the write data.
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
    (* ram_style = "distributed" *)
    logic [REG_DATA_WIDTH-1:0] regs[0:REG_COUNT-1];

    logic write_fire;
    assign write_fire = !rst && wen && (!ZERO_X0 || (waddr != '0));

    assign rdata1 = (ZERO_X0 && (raddr1 == '0)) ? '0 :
                    (write_fire && (waddr == raddr1)) ? wdata :
                    regs[raddr1];
    assign rdata2 = (ZERO_X0 && (raddr2 == '0)) ? '0 :
                    (write_fire && (waddr == raddr2)) ? wdata :
                    regs[raddr2];

    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < REG_COUNT; i++) begin
                regs[i] <= '0;
            end
        end else if (write_fire) begin
            regs[waddr] <= wdata;
        end
    end

endmodule
