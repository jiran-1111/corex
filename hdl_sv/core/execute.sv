/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

module execute #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
)(
    input logic clk,
    input logic rst,
    input logic stall,
    input logic [2:0] ALU_Operation,//decoder_pipe_reg的输出
    input logic [6:0] funct7,// From instruction [31:25]
    input logic [2:0] funct3,// From instruction [14:12]
    input logic [1:0] ALU_ASrc, // 00: rs1, 01: PC, 10: PC+4
    input logic ALU_BSrc,// 0: rs2,  1: Immediate extend

    input logic [ADDR_WIDTH-1:0] PC,
    input logic [DATA_WIDTH-1:0] regRead_1,
    input logic [DATA_WIDTH-1:0] regRead_2,
    input logic [DATA_WIDTH-1:0] extend,// Immediate value
    input logic branch_op,

    output logic [DATA_WIDTH-1:0] ALU_result,// Computation output
    output logic branch_taken,
    output logic [ADDR_WIDTH-1:0] JALR_target
);
    logic [5:0] ALU_Control;
    logic alu_cmp_out;
    always_comb begin
        if ({ALU_Operation, funct7} == {3'b000, 7'b0000000}) begin
            // R-Type standard operations (ADD, SLL, SLT, SLTU, XOR, SRL, OR, AND)
            ALU_Control = {3'b000, funct3};
        end 
        else if ({ALU_Operation, funct7} == {3'b000, 7'b0100000}) begin
            // R-Type alternative operations (SUB, SRA)
            ALU_Control = {3'b001, funct3};
        end 
        else if ({ALU_Operation, funct3, funct7} == {3'b001, 3'b101, 7'b0000000}) begin
            // I-Type Logical Right Shift (SRLI)
            ALU_Control = {3'b000, funct3};
        end 
        else if ({ALU_Operation, funct3, funct7} == {3'b001, 3'b101, 7'b0100000}) begin
            // I-Type Arithmetic Right Shift (SRAI)
            ALU_Control = {3'b001, funct3};
        end 
        else if (ALU_Operation == 3'b001) begin
            // I-Type standard immediates (ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI)
            ALU_Control = {3'b000, funct3};
        end 
        else if (ALU_Operation == 3'b010) begin
            // B-Type branches (BEQ, BNE, BLT, BGE, BLTU, BGEU)
            ALU_Control = {3'b010, funct3}; 
        end
        else if (ALU_Operation == 3'b011) begin
            // JAL JALR
            ALU_Control = 6'b011_111; 
        end
        else begin
            // Default to ADD for AUIPC, LUI, or safety fallback
            ALU_Control = 6'b000_000; 
        end
    end

    assign branch_taken  = branch_op & alu_cmp_out;
    logic [DATA_WIDTH-1:0] alu_in_a;
    logic [DATA_WIDTH-1:0] alu_in_b;
    

    // Mux for Operand A
    assign alu_in_a =  (ALU_ASrc == 2'b01) ? PC : 
                       (ALU_ASrc == 2'b10) ? (PC + 4) :
                       (ALU_ASrc == 2'b11) ? '0 :       // 显式为 LUI 提供 0
                                     regRead_1; 

    // Mux for Operand B
    assign alu_in_b = ALU_BSrc ? extend : regRead_2;

    assign JALR_target = (regRead_1 + extend) & 32'hffff_fffe;

    ALU #(
        .DATA_WIDTH(DATA_WIDTH)
    ) u_alu (
        .ALU_Control(ALU_Control), 
        .alu_in_a  (alu_in_a), 
        .alu_in_b  (alu_in_b), 
        .ALU_result (ALU_result),
        //.zero(zero), 
        .cmp_out(alu_cmp_out)
    );

endmodule
