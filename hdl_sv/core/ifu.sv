/*
 * COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

module Ifu #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
) (
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  start,
    input  logic                  stall,
    input  logic [ADDR_WIDTH-1:0] program_address,

    input  logic [ADDR_WIDTH-1:0] JAL_target,
    input  logic [ADDR_WIDTH-1:0] JALR_target,
    input  logic [ADDR_WIDTH-1:0] branch_target,
    input  logic [1:0]            pc_sel_execute,
    input  logic                  branch_taken,

    output logic [DATA_WIDTH-1:0] instruction,
    output logic [ADDR_WIDTH-1:0] inst_PC,
    output logic                  valid
);
    logic [ADDR_WIDTH-1:0] PC_reg;
    logic [ADDR_WIDTH-1:0] PC_plus4;
    logic [ADDR_WIDTH-1:0] inst_PC_reg;
    logic [ADDR_WIDTH-1:0] next_PC;

    logic imem_gnt;
    logic imem_err;
    logic fetch;
    logic jump_or_branch_taken;

    assign PC_plus4 = PC_reg + 4;
    assign inst_PC  = inst_PC_reg;

    assign jump_or_branch_taken = (pc_sel_execute == 2'b01 && branch_taken) ||
                                  (pc_sel_execute == 2'b10)                  ||
                                  (pc_sel_execute == 2'b11);

    // Next PC selection logic
    always_comb begin
        case (pc_sel_execute)
            2'b01:   next_PC = branch_taken ? branch_target : PC_plus4;
            2'b10:   next_PC = JAL_target;
            2'b11:   next_PC = JALR_target;
            default: next_PC = PC_plus4;
        endcase
    end

    // Instruction memory instance
    IMemTop #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) IMem (
        .clk  (clk),
        .rst  (rst),
        .req  (fetch),
        .addr (PC_reg),
        .ack  (valid),
        .gnt  (imem_gnt),
        .err  (imem_err),
        .rdata(instruction)
    );

    // Instruction fetch request control
    always_ff @(posedge clk) begin
        if (rst) begin
            fetch <= 1'b0;
        end else if (start || stall) begin
            fetch <= 1'b1;
        end else begin
            fetch <= 1'b1;
        end
    end

    // Program Counter (PC) register logic
    always_ff @(posedge clk) begin
        if (rst || start) begin
            PC_reg <= program_address;
        end else if (stall) begin
            PC_reg <= PC_reg;
        end else if (jump_or_branch_taken) begin
            PC_reg <= next_PC;
        end else if (fetch && imem_gnt) begin
            PC_reg <= PC_plus4;
        end
    end

    // Latch PC aligned with fetched instruction
    always_ff @(posedge clk) begin
        if (rst || start) begin
            inst_PC_reg <= program_address;
        end else if (stall) begin
            inst_PC_reg <= inst_PC_reg;
        end else if (fetch && imem_gnt) begin
            inst_PC_reg <= PC_reg;
        end
    end

endmodule