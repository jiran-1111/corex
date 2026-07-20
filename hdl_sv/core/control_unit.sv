/*
 * COREX: Co-modeling RISC-V Example Core
 * 
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 * 
 * Author: Ran Ji
 */
/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

// Main Control Unit


module ControlUnit #(
    // Reserved for future extensions
    parameter int DATA_WIDTH = 32
)(
    input  logic       clk,
    input  logic       rst,
    input  logic [6:0] opcode,

    output logic [2:0] ALUOp,          // ALU operation class
    output logic [1:0] operand_A,  // 00:rs1, 01:PC, 11:0
    output logic       operand_B,  // 0:rs2, 1:imm
    output logic [1:0] extend_sel,     
    output logic       regWrite,        // Register write enable

    output logic branch_op,
    output logic memRead,//内存读写控制 dmemtop
    output logic memWrite,
    output logic memtoReg,
    output logic [1:0] next_PC_sel

);

    // Opcode definitions (Base RV32I arithmetic subset)
    localparam [6:0] R_TYPE  = 7'b0110011;  // 寄存器算术/逻辑
    localparam [6:0] I_TYPE  = 7'b0010011;  // 立即数算术/逻辑
    localparam [6:0] AUIPC   = 7'b0010111;  // u type
    localparam [6:0] LUI     = 7'b0110111;  // u type

    localparam [6:0] STORE   = 7'b0100011;
    localparam [6:0] LOAD    = 7'b0000011;
    localparam [6:0] BRANCH  = 7'b1100011;
    localparam [6:0] JALR    = 7'b1100111;
    localparam [6:0] JAL     = 7'b1101111;
    localparam [6:0] FENCES  = 7'b0001111;
    localparam [6:0] SYSCALL = 7'b1110011;

    // Control signal assignments
    assign regWrite      = ((opcode == R_TYPE) | (opcode == I_TYPE) |(opcode == LOAD)
                            | (opcode == JALR) | (opcode == JAL) | 
                            (opcode == AUIPC)| (opcode == LUI))? 1 : 0;
    assign ALUOp         = (opcode == R_TYPE)?  3'b000 :
                           (opcode == I_TYPE)?  3'b001 :
                           (opcode == STORE)?   3'b101 :
                           (opcode == LOAD)?    3'b100 :
                           (opcode == BRANCH)?  3'b010 :
                           ((opcode == JALR)  | (opcode == JAL))? 3'b011 :
                           ((opcode == AUIPC) | (opcode == LUI))? 3'b110 : 0;

    assign operand_A = (opcode == AUIPC)?  2'b01 :
                        (opcode == LUI) ?  2'b11 :
                        ((opcode == JALR)  || (opcode == JAL))?  2'b10 : 0;

    assign operand_B = ((opcode == I_TYPE) | (opcode == STORE)|
                           (opcode == LOAD) | (opcode == AUIPC) |
                           (opcode == LUI))? 1 : 0;
    assign extend_sel    = ((opcode == I_TYPE)  | (opcode == LOAD))?  2'b00 :
                           (opcode == STORE)?   2'b01  :
                           ((opcode == AUIPC) | (opcode == LUI))? 2'b10 : 0;

    assign memWrite      = (opcode == STORE)?   1 : 0;
    assign branch_op     = (opcode == BRANCH)?  1 : 0;
    assign memRead       = (opcode == LOAD)?    1 : 0;
    assign memtoReg      = (opcode == LOAD)?    1 : 0;
    assign next_PC_sel   = (opcode == BRANCH)?  2'b01 :
                           (opcode == JAL)?     2'b10 :
                           (opcode == JALR)?    2'b11 : 0;

endmodule
