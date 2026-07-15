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

    input  logic                   extend_sel,  // 0:I-type, 1:U-type
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
    output logic [DATA_WIDTH-1:0]  rs2_data
);

    // Field extractions
    assign opcode = instruction[6:0];
    assign rd     = instruction[11:7];
    assign funct3 = instruction[14:12];
    assign rs1    = instruction[19:15];
    assign rs2    = instruction[24:20];
    assign funct7 = instruction[31:25];
    
    // Immediate extraction and expansion
    logic [11:0] i_imm_orig; 
    logic [19:0] u_imm;    
    logic [31:0] i_imm_32;
    logic [31:0] u_imm_32;
    assign i_imm_orig = instruction[31:20];  
    assign u_imm = instruction[31:12];

    assign i_imm_32 = {{20{i_imm_orig[11]}}, i_imm_orig}; // 12-bit sign extension
    assign u_imm_32   = {u_imm, 12'b0};                    // 20-bit upper layout

    assign extend_imm = (extend_sel == 1'b1) ? u_imm_32 : i_imm_32;

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
        .rdata1(rs1_data),
        .rdata2(rs2_data)
    );

endmodule