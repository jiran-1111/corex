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
    output logic [1:0] operand_A,  // 00:rs1, 01:PC, 10:PC+4, 11:0
    output logic       operand_B,  // 0:rs2, 1:imm
    output logic [2:0] extend_sel,     
    output logic       regWrite,        //是否需要写寄存器

    output logic branch_op,
    output logic memRead,//内存读使能 dmem
    output logic memWrite,//内存写使能 dmem
    output logic memtoReg,//内存读结果写入寄存器
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
    localparam [6:0] FENCES  = 7'b0001111;  // FENCE：不匹配上述 case，控制信号全 0，作 NOP 流过
    localparam [6:0] SYSCALL = 7'b1110011;  // ECALL/EBREAK：同样作 NOP（本设计无异常处理）

    // Control signal assignments
    //assign jump_flush = (opcode == 7'b1101111) || (opcode == 7'b1100111) ;   // JAL JALR 
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
    assign extend_sel  = ((opcode == I_TYPE) | (opcode == LOAD) | (opcode == JALR)) ? 3'b000 :
                         (opcode == STORE)  ? 3'b001 :
                         (opcode == BRANCH) ? 3'b010 :
                         ((opcode == AUIPC) | (opcode == LUI)) ? 3'b011 :
                         (opcode == JAL)    ? 3'b100 : 3'b000;
                         
    assign memWrite      = (opcode == STORE)?   1 : 0;
    assign branch_op     = (opcode == BRANCH)?  1 : 0;
    assign memRead       = (opcode == LOAD)?    1 : 0;
    assign memtoReg      = (opcode == LOAD)?    1 : 0;
    assign next_PC_sel   = (opcode == BRANCH)?  2'b01 :
                           (opcode == JAL)?     2'b10 :
                           (opcode == JALR)?    2'b11 : 0;

endmodule
