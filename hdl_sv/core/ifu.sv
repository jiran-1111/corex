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

    input logic [ADDR_WIDTH-1:0] JAL_target,
    input logic [ADDR_WIDTH-1:0] JALR_target,
    input logic [ADDR_WIDTH-1:0] branch_target,
    input logic [1:0] pc_sel_execute,
    input logic branch_taken,
    
    output logic [DATA_WIDTH-1:0] instruction, // 从内存读出的32位指令
    output logic [ADDR_WIDTH-1:0] inst_PC,      // 当前返回指令对应的PC地址
    output logic valid
);
    logic [ADDR_WIDTH-1:0] PC_reg;   // pc寄存器
    logic [ADDR_WIDTH-1:0] PC_plus4;
    logic [ADDR_WIDTH-1:0] inst_PC_reg; // 专门用于同步锁存当前读出指令对应PC的寄存器

    logic [ADDR_WIDTH-1:0] next_PC;


    logic imem_gnt;
    logic imem_err; // err一直为0
    logic fetch;    // 指令读取使能，表示IFU正在请求Instruction Memory取指
    logic jump_or_branch_taken; // 用于判断是否需要更新 PC


    assign PC_plus4 = PC_reg + 4; 
    assign inst_PC = inst_PC_reg;// 输出锁存后的 PC，确保其与 instruction 完全同拍更新

    assign jump_or_branch_taken = (pc_sel_execute == 2'b01 && branch_taken) || // Branch 且成功跳转
                                  (pc_sel_execute == 2'b10) ||                  // JAL
                                  (pc_sel_execute == 2'b11);                    // JALR


    always_comb begin
        case(pc_sel_execute)
            2'b01:  next_PC = (branch_taken) ? branch_target : PC_plus4;
            2'b10:  next_PC = JAL_target;
            2'b11:  next_PC = JALR_target;
            default: next_PC = PC_plus4;
        endcase
    end

    // 指令memory
    IMemTop #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) IMem (
        .clk(clk),
        .rst(rst),
        .req(fetch),
        .addr(PC_reg),
        
        .ack(valid), // 数据响应有效
        .gnt(imem_gnt),// 地址授权 
        .err(imem_err), // 如果访问一个非法地址 会伴随ack一起返回
        .rdata(instruction)
    );

    // IMem 请求使能 (fetch) 控制逻辑
    always_ff @(posedge clk) begin
        if (rst) begin
            fetch <= 1'b0;
        end else if (start) begin
            fetch <= 1'b1;
        end else if (stall) begin
            fetch <= 1'b1; // 如果设置为0 需要等一拍stall下降
        end else begin
            fetch <= 1'b1; // 正常运行，保持取指请求
        end
    end

    // PC_reg 递增逻辑
    always_ff @(posedge clk) begin
        if (rst) begin
            PC_reg <= program_address;
        end else if (start) begin
            PC_reg <= program_address; // start 阶段保持在起始地址
        end else if(stall) begin
            PC_reg <= PC_reg;
        end else begin
            if (jump_or_branch_taken) begin
                PC_reg <= next_PC;
            end else if (fetch && imem_gnt) begin // 握手成功 pc更新 后续需要测试如果访问地址不合法
                PC_reg <= PC_plus4;
            end
        end
    end

    // 锁存当前有效取回指令对应的真实 PC (与 instruction 严格对准)
    always_ff @(posedge clk) begin
        if (rst) begin
            inst_PC_reg <= program_address;
        end else if (start) begin
            inst_PC_reg <= program_address;
        end else if(stall) begin
            inst_PC_reg <= inst_PC_reg;
        end else if (fetch && imem_gnt) begin
            inst_PC_reg <= PC_reg;
        end
        
    end

    


endmodule