/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

// Instruction Decoder Unit (IDU)
module Decoder #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
)(
    input  logic                   clk,
    input  logic                   rst,
    input  logic [DATA_WIDTH-1:0]  instruction,
    // PC用于跳转
    input logic [ADDR_WIDTH-1:0] PC,

    input  logic [1:0]             extend_sel,  // 0:I-type, 1:U-type
    input  logic                   reg_write,   // WB stage write enable
    input  logic [4:0]             write_reg,   // WB stage rd address
    input  logic [DATA_WIDTH-1:0]  write_data,  // WB stage write data

    input logic rs1_data_bypass,// 1：有冲突 上一条指令还在mem/wb  0: 没有冲突
    input logic rs2_data_bypass,//冲突检测单元（Hazard/Forwarding Unit）控制的选择开关（2位宽的 MUX 选择信号）。
    input logic [DATA_WIDTH-1:0] ALU_result_writeback,
    output logic [6:0]             opcode,
    output logic [6:0]             funct7,
    output logic [2:0]             funct3,
    output logic [4:0]             rs1,
    output logic [4:0]             rs2,
    output logic [4:0]             rd,
    output logic [DATA_WIDTH-1:0]  extend_imm,  // Extended immediate value
    output logic [DATA_WIDTH-1:0]  rs1_data,
    output logic [DATA_WIDTH-1:0]  rs2_data,

    output logic [ADDR_WIDTH-1:0] branch_target, //跳转目标地址
    output logic [ADDR_WIDTH-1:0] JAL_target

);

    // Immediate extraction and expansion
    logic [11:0] i_imm_orig; 
    logic [19:0] u_imm;    
    logic [31:0] i_imm_32;
    logic [31:0] u_imm_32;
    
    logic [6:0]  s_imm_msb;
    logic [4:0]  s_imm_lsb;
    logic [11:0] s_imm_orig;
    logic [31:0] s_imm_32;
    logic [12:0] sb_imm_orig;
    logic [31:0] sb_imm_32;
    logic [19:0] uj_imm;
    logic [31:0] uj_imm_32;

    logic [DATA_WIDTH-1:0] rs1_data_decode;
    logic [DATA_WIDTH-1:0] rs2_data_decode;


    // Field extractions
    assign opcode = instruction[6:0];
    assign rd     = instruction[11:7];
    assign funct3 = instruction[14:12];
    assign rs1    = instruction[19:15];
    assign rs2    = instruction[24:20];
    assign funct7 = instruction[31:25];
    
    assign i_imm_orig = instruction[31:20];  
    assign u_imm = instruction[31:12];

    // s uj sb extraction
    assign s_imm_msb = instruction[31:25];
    assign s_imm_lsb = instruction[11:7];
    assign uj_imm = {instruction[31],instruction[19:12],instruction[20],instruction[30:21]};
    assign s_imm_orig = {s_imm_msb,s_imm_lsb};
    assign sb_imm_orig = {s_imm_msb[6],s_imm_lsb[0],s_imm_msb[5:0],s_imm_lsb[4:1],1'b0};

    assign i_imm_32 = {{20{i_imm_orig[11]}}, i_imm_orig}; // 12-bit sign extension
    assign u_imm_32   = {u_imm, 12'b0};                    // 20-bit upper layout
    assign s_imm_32 = {{20{s_imm_orig[11]}},s_imm_orig};

    assign extend_imm = (extend_sel == 2'b01)? s_imm_32 : 
                        (extend_sel == 2'b10)? u_imm_32 : i_imm_32;

    // 跳转和分支地址BEQ
    assign sb_imm_32 = {{19{sb_imm_orig[12]}},sb_imm_orig};
    assign branch_target = PC+sb_imm_32;
    //assign uj_imm_32 = { {12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0 };

    assign uj_imm_32 = {{11{uj_imm[19]}},uj_imm[19:0],1'b0};
    assign JAL_target = uj_imm_32 + PC;

    assign rs1_data = (rs1_data_bypass == 0) ? rs1_data_decode: ALU_result_writeback;
    assign rs2_data = (rs2_data_bypass == 0) ? rs2_data_decode: ALU_result_writeback;                
    
    // Register File instantiation
    RegFile #(
        .DATA_WIDTH(DATA_WIDTH),
        .SEL_WIDTH(5)
    ) u_regfile (
        .clk(clk),
        .rst(rst),
        .wen(reg_write),
        .waddr(write_reg),
        .wdata(write_data),
        .raddr1(rs1),
        .raddr2(rs2),
        .rdata1(rs1_data_decode),
        .rdata2(rs2_data_decode)
    );

endmodule