/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

// Main Control Unit
// Generates control signals based on the instruction opcode.
// Optimized for arithmetic and logic execution only.
// Branch, jump, load, and store instructions are not supported.

module ControlUnit #(
    // Reserved for future extensions
)(
    input  logic       clk,
    input  logic       rst,
    input  logic [6:0] opcode,

    output logic [2:0] ALUOp,          // ALU operation class
    output logic [1:0] operand_A,  // 00:rs1, 01:PC, 11:0
    output logic       operand_B,  // 0:rs2, 1:imm
    output logic       extend_sel,     // 0:I-type, 1:U-type
    output logic       regWrite        // Register write enable
);

    // Opcode definitions (Base RV32I arithmetic subset)
    localparam [6:0] R_TYPE  = 7'b0110011;  // 寄存器算术/逻辑
    localparam [6:0] I_TYPE  = 7'b0010011;  // 立即数算术/逻辑
    localparam [6:0] AUIPC   = 7'b0010111;  // u type
    localparam [6:0] LUI     = 7'b0110111;  // u type
    // Control signal assignments
    assign regWrite      = ((opcode == R_TYPE) | (opcode == I_TYPE) | 
                            (opcode == AUIPC)| (opcode == LUI))? 1 : 0;
    assign ALUOp         = (opcode == R_TYPE)?  3'b000 :
                           (opcode == I_TYPE)?  3'b001 :
                           ((opcode == AUIPC) | (opcode == LUI))? 3'b110 : 3'b000;
    assign operand_A = (opcode == AUIPC)?  2'b01 :(opcode == LUI)?    2'b11 : 2'b00;
    assign operand_B = ((opcode == I_TYPE) | (opcode == AUIPC) | 
                            (opcode == LUI))? 1'b1 : 1'b0;
    assign extend_sel    = ((opcode == AUIPC) | (opcode == LUI))? 1'b1 : 1'b0;

endmodule
