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
    input  logic [DATA_WIDTH-1:0] alu_in_a,  
    input  logic [DATA_WIDTH-1:0] alu_in_b,   
    output logic [DATA_WIDTH-1:0] ALU_result,
    output logic cmp_out
    //output logic zero   
);

    // shift width: 5 bits for RV32, 6 bits for RV64
    localparam int SHIFT_WIDTH = $clog2(DATA_WIDTH);
    logic [SHIFT_WIDTH-1:0] shamt; 
    logic [DATA_WIDTH-1:0] arithmetic_right_shift;
    logic [DATA_WIDTH-1:0] signed_less_than;
    logic [DATA_WIDTH-1:0] unsigned_less_than;
    logic [DATA_WIDTH-1:0] signed_greater_than_equal;

    assign shamt = alu_in_b[SHIFT_WIDTH-1:0];
    assign arithmetic_right_shift = $signed(alu_in_a) >>> shamt;
    assign signed_less_than       = DATA_WIDTH'($signed(alu_in_a) < $signed(alu_in_b));
    assign unsigned_less_than     = DATA_WIDTH'(alu_in_a < alu_in_b);
    //assign zero   = (ALU_result==0);
    assign signed_greater_than_equal = DATA_WIDTH'($signed(alu_in_a) >= $signed(alu_in_b));
    // B型指令跳转条件是否满足
    assign cmp_out = ALU_result[0];
    

    assign ALU_result =
            (ALU_Control == 6'b000_000)? alu_in_a + alu_in_b:                /* ADD, ADDI */
            (ALU_Control == 6'b001_000)? alu_in_a - alu_in_b:                /* SUB */
            
            (ALU_Control == 6'b000_100)? alu_in_a ^ alu_in_b:                /* XOR, XORI */
            (ALU_Control == 6'b000_110)? alu_in_a | alu_in_b:                /* OR, ORI */
            (ALU_Control == 6'b000_111)? alu_in_a & alu_in_b:                /* AND, ANDI */
            
            (ALU_Control == 6'b000_010)? signed_less_than:                   /* SLT, SLTI */
            (ALU_Control == 6'b000_011)? unsigned_less_than:                 /* SLTU, SLTIU */
            
            (ALU_Control == 6'b000_001)? alu_in_a << shamt:                  /* SLL, SLLI (Logic left shift, zero-filled) */
            (ALU_Control == 6'b000_101)? alu_in_a >> shamt:                  /* SRL, SRLI (Logic right shift, zero-filled) */
            (ALU_Control == 6'b001_101)? arithmetic_right_shift:             /* SRA, SRAI (Arithmetic right shift) */
            
            (ALU_Control == 6'b011_111)? alu_in_a:                           /* operand_A = PC+4 for JAL   and JALR */
            (ALU_Control == 6'b010_000)? DATA_WIDTH'(alu_in_a == alu_in_b):               /* BEQ */
            (ALU_Control == 6'b010_001)? DATA_WIDTH'(alu_in_a != alu_in_b):               /* BNE */
            (ALU_Control == 6'b010_100)? signed_less_than:                   /* BLT */
            (ALU_Control == 6'b010_101)? signed_greater_than_equal:          /* BGE */
            (ALU_Control == 6'b010_110)? DATA_WIDTH'(alu_in_a < alu_in_b):                /* BLTU */
            (ALU_Control == 6'b010_111)? DATA_WIDTH'(alu_in_a >= alu_in_b):               /* BGEU */
            {DATA_WIDTH{1'b0}};                                              /* Default zero fallback */

endmodule