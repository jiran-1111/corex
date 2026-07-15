/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

module Ifu #(
    parameter DATA_WIDTH = 32, // 指令的数据位宽
    parameter ADDR_WIDTH = 32  // 地址总线位宽
) (
    input logic clk,
    input logic rst,
    input logic start,
    input logic stall, // 暂停
    input logic [ADDR_WIDTH-1:0] program_address,
    output logic [DATA_WIDTH-1:0] instruction, // 从内存读出的32位指令
    output logic [ADDR_WIDTH-1:0] inst_PC      // 当前返回指令对应的PC地址
);
    logic [ADDR_WIDTH-1:0] PC_reg;   // 当前要发给IMem的取指地址（字节地址）
    logic [ADDR_WIDTH-1:0] PC_plus4;
    logic [ADDR_WIDTH-1:0] inst_PC_reg; // 专门用于同步锁存当前读出指令对应PC的寄存器

    logic imem_ack;
    logic imem_gnt;
    logic imem_err; // err一直为0
    logic fetch;    // 指令读取使能，表示IFU正在请求Instruction Memory取指

    assign PC_plus4 = PC_reg + 4; 

    // 指令memory
    IMemTop #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) IMem (
        .clk(clk),
        .rst(rst),
        .req(fetch),
        .addr(PC_reg),
        
        .ack(imem_ack),
        .gnt(imem_gnt),
        .err(imem_err),
        .rdata(instruction)
    );

    // ==========================================================================
    // 1. IMem 请求使能 (fetch) 控制逻辑
    // ==========================================================================
    always_ff @(posedge clk) begin
        if (rst) begin
            fetch <= 1'b0;
        end else if (start) begin
            fetch <= 1'b1;
        end else begin
            fetch <= 1'b1; // 启动后保持取指请求
        end
    end

    // ==========================================================================
    // 2. 核心：PC_reg 递增逻辑
    // ==========================================================================
    always_ff @(posedge clk) begin
        if (rst) begin
            PC_reg <= program_address;
        end else if (start) begin
            PC_reg <= program_address; // start 阶段保持在起始地址
        end else begin
            // 只有当 fetch 为 1 且没有被 stall，并且 IMem 给了 gnt 响应时，PC_reg 才能自增
            if (fetch && !stall && imem_gnt) begin
                PC_reg <= PC_plus4;
            end else begin
                PC_reg <= PC_reg; // 发生 stall 或没有 gnt 时，保持 PC 不变
            end
        end
    end

    // ==========================================================================
    // 3. 核心：锁存当前有效取回指令对应的真实 PC (与 instruction 严格对准)
    // ==========================================================================
    always_ff @(posedge clk) begin
        if (rst) begin
            inst_PC_reg <= program_address;
        end else if (start) begin
            inst_PC_reg <= program_address;
        end else begin
            // 只有在 IMem 成功接收请求(fetch & imem_gnt) 且流水线没有 stall 的时候，
            // 才会把正在请求的 PC_reg 锁存到 inst_PC_reg 中。
            // 这样在下一个时钟周期，当指令读出来时，inst_PC_reg 里的 PC 刚好和它匹配。
            if (fetch && !stall && imem_gnt) begin
                inst_PC_reg <= PC_reg;
            end
        end
    end

    // 输出锁存后的 PC，确保其与 instruction 完全同拍更新
    assign inst_PC = inst_PC_reg;

endmodule