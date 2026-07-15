/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

module ALU #(
    parameter DATA_WIDTH = 32
)(
    input  logic [5:0]            ALU_Control, 
    input  logic [DATA_WIDTH-1:0] operand_A,  
    input  logic [DATA_WIDTH-1:0] operand_B,   
    output logic [DATA_WIDTH-1:0] ALU_result   
);

    // shift width: 5 bits for RV32, 6 bits for RV64
    localparam int SHIFT_WIDTH = $clog2(DATA_WIDTH);
    logic [SHIFT_WIDTH-1:0] shamt; 
    logic [DATA_WIDTH-1:0] arithmetic_right_shift;
    logic [DATA_WIDTH-1:0] signed_less_than;
    logic [DATA_WIDTH-1:0] unsigned_less_than;
    assign shamt = operand_B[SHIFT_WIDTH-1:0];
    assign arithmetic_right_shift = $signed(operand_A) >>> shamt;
    assign signed_less_than       = DATA_WIDTH'($signed(operand_A) < $signed(operand_B));
    assign unsigned_less_than     = DATA_WIDTH'(operand_A < operand_B);

    assign ALU_result =
            (ALU_Control == 6'b000_000)? operand_A + operand_B:                /* ADD, ADDI */
            (ALU_Control == 6'b001_000)? operand_A - operand_B:                /* SUB */
            
            (ALU_Control == 6'b000_100)? operand_A ^ operand_B:                /* XOR, XORI */
            (ALU_Control == 6'b000_110)? operand_A | operand_B:                /* OR, ORI */
            (ALU_Control == 6'b000_111)? operand_A & operand_B:                /* AND, ANDI */
            
            (ALU_Control == 6'b000_010)? signed_less_than:                     /* SLT, SLTI */
            (ALU_Control == 6'b000_011)? unsigned_less_than:                   /* SLTU, SLTIU */
            
            (ALU_Control == 6'b000_001)? operand_A << shamt:                   /* SLL, SLLI (Logic left shift, zero-filled) */
            (ALU_Control == 6'b000_101)? operand_A >> shamt:                   /* SRL, SRLI (Logic right shift, zero-filled) */
            (ALU_Control == 6'b001_101)? arithmetic_right_shift:               /* SRA, SRAI (Arithmetic right shift) */
            {DATA_WIDTH{1'b0}};                                                /* Default zero fallback */

endmodule