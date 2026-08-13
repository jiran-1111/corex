/*
 * COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

// 
module Ifu #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
) (
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  start,
    input  logic                  stall,
    input  logic [ADDR_WIDTH-1:0] program_address,

    // ID 阶段跳转信号（JAL）
    input  logic [1:0]            id_pc_sel,
    input  logic [ADDR_WIDTH-1:0] id_jal_target,

    // EX 阶段跳转信号（Branch / JALR）
    input  logic [1:0]            ex_pc_sel,
    input  logic                  ex_branch_taken,
    input  logic [ADDR_WIDTH-1:0] ex_branch_target,
    input  logic [ADDR_WIDTH-1:0] ex_jalr_target,

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

    // 跳转判定：EX阶段分支/JALR 优先于 ID阶段JAL（更老的指令优先）
    assign jump_or_branch_taken = (ex_pc_sel == 2'b01 && ex_branch_taken) ||
                                  (ex_pc_sel == 2'b11)                  ||
                                  (id_pc_sel == 2'b10);

    // Next PC selection logic（优先级：EX跳转 > ID跳转 > PC+4）
    always_comb begin
        if (ex_pc_sel == 2'b01 && ex_branch_taken)
            next_PC = ex_branch_target;
        else if (ex_pc_sel == 2'b11)
            next_PC = ex_jalr_target;
        else if (id_pc_sel == 2'b10)
            next_PC = id_jal_target;
        else
            next_PC = PC_plus4;
    end

    // Instruction memory instance
    // hold=stall：流水线停顿时组合冻结 rdata_q。因为 PC_reg 超前 inst_PC_reg 一拍，
    // 停顿时 PC_reg 冻结在 X+4、inst_PC_reg 冻结在 X，若 rdata_q 继续随 req 锁存，
    // 会锁存 mem[X+4]（下一条指令），与 inst_PC=X 错位并覆盖 IF/ID 等待的指令。
    // hold 必须由组合逻辑驱动（req 是时序信号晚一拍生效，无法在一拍 stall 内抑制）。
    IMemTop #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH),
        .HAS_HOLD(1)
    ) IMem (
        .clk  (clk),
        .rst  (rst),
        .hold (stall),
        .req  (fetch),
        .addr (PC_reg),
        .ack  (valid),
        .gnt  (imem_gnt),
        .err  (imem_err),
        .rdata(instruction)
    );

    // Instruction fetch request control
    // rst：复位后无取指请求（下一拍才置 1，保证复位撤销后 PC 先稳定一拍）；
    //      其余时刻取指请求保持有效（start 时自动有效；stall 时流水线暂停，
    //      由下方 IMem 的 hold 门控组合冻结 rdata_q，而不是拉低 req——因为
    //      req 是时序信号晚一拍生效，无法在一拍 stall 内及时抑制锁存）。
    always_ff @(posedge clk) begin
        if (rst)
            fetch <= 1'b0;
        else
            fetch <= 1'b1;
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