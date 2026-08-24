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
    input logic [ADDR_WIDTH-1:0]   PC,

    input  logic [2:0]             extend_sel,  
    input  logic                   reg_write,   // WB stage write enable
    input  logic [4:0]             write_reg,   // WB stage rd address
    input  logic [DATA_WIDTH-1:0]  write_data,  // WB stage write data

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
    //output logic [ADDR_WIDTH-1:0] JALR_target,

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
    logic rs1_data_bypass;
    logic rs2_data_bypass;
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
    assign u_imm      = instruction[31:12];

    // S, B, J Type immediate extraction
    assign s_imm_msb   = instruction[31:25];
    assign s_imm_lsb   = instruction[11:7];
    assign s_imm_orig  = {s_imm_msb, s_imm_lsb};
    assign sb_imm_orig = {s_imm_msb[6], s_imm_lsb[0], s_imm_msb[5:0], s_imm_lsb[4:1], 1'b0};

    // Immediate Sign-Extension Calculations
    assign i_imm_32  = {{20{i_imm_orig[11]}}, i_imm_orig};     // I-Type
    assign s_imm_32  = {{20{s_imm_orig[11]}}, s_imm_orig};     // S-Type
    assign sb_imm_32 = {{19{sb_imm_orig[12]}}, sb_imm_orig};   // B-Type
    assign u_imm_32  = {u_imm, 12'b0};                         // U-Type
    assign uj_imm_32 = {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0}; // J-Type


    // 3'b000: I-Type, 3'b001: S-Type, 3'b010: B-Type, 3'b011: U-Type, 3'b100: J-Type
    assign extend_imm = (extend_sel == 3'b001) ? s_imm_32  :
                        (extend_sel == 3'b010) ? sb_imm_32 :
                        (extend_sel == 3'b011) ? u_imm_32  :
                        (extend_sel == 3'b100) ? uj_imm_32 :
                                                 i_imm_32;

    assign branch_target = PC+sb_imm_32;
    assign JAL_target = uj_imm_32 + PC;

    //assign JALR_target = (rs1_data + i_imm_32) & 32'hffff_fffe;
    assign rs1_data_bypass = (rs1 == write_reg) && (write_reg != 5'd0) && reg_write && (rs1 != 5'd0);
    assign rs2_data_bypass = (rs2 == write_reg) && reg_write && (rs2 != 5'd0);

    assign rs1_data = (rs1_data_bypass == 0) ? rs1_data_decode: write_data;
    assign rs2_data = (rs2_data_bypass == 0) ? rs2_data_decode: write_data;                
    
    // Store 字节使能（wbe）不再在 ID 段生成：改为在 MEM 阶段按访存地址
    // addr[1:0] 计算字节偏移（见 core.sv 的 MEM 段组合逻辑），以正确支持
    // SB/SH/SW 对未对齐地址的字节/半字写入。
    // Register File instantiation
    RegFile #(
        .REG_DATA_WIDTH(DATA_WIDTH),
        .REG_SEL_WIDTH(5)
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