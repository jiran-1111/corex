/*
 * COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

module CoreTop #(
    parameter int DATA_WIDTH = 32,
    parameter int ADDR_WIDTH = 32,
    parameter string IMEM_INIT_FILE = "",
    parameter string DMEM_INIT_FILE = ""
)(
    input logic                  clk,
    input logic                  rst,
    input logic                  start,
    input logic [ADDR_WIDTH-1:0] program_address
);

    localparam NOP = 32'h00000013;

    // Pipeline control
    logic stall;
    logic flush;

    assign stall = 1'b0;
    assign flush = (id_pc_sel == 2'b01 && ex_branch_taken) ||
                   (id_pc_sel == 2'b10)                  ||
                   (id_pc_sel == 2'b11);

    // IF stage signals
    logic [DATA_WIDTH-1:0] if_instruction;
    logic [ADDR_WIDTH-1:0] if_pc;
    logic                  if_valid;

    // Control/branch feedback signals
    logic [1:0]            id_pc_sel;
    logic                  ex_branch_taken;
    logic [ADDR_WIDTH-1:0] id_branch_target;
    logic [ADDR_WIDTH-1:0] id_jal_target;
    logic [ADDR_WIDTH-1:0] ex_jalr_target;

    // IF/ID pipeline register outputs
    logic [DATA_WIDTH-1:0] id_instruction;
    logic [ADDR_WIDTH-1:0] id_pc;
    logic                  id_valid;
    logic [DATA_WIDTH-1:0] id_instruction_real;

    // ID/EX control and decoder signals
    logic [2:0]              id_alu_op;
    logic [1:0]              id_operand_a;
    logic                    id_operand_b;
    logic [2:0]              id_extend_sel;
    logic                    id_reg_write;
    logic                    id_branch_op;
    logic                    id_mem_read;
    logic                    id_mem_write;
    logic                    id_mem_to_reg;

    logic [6:0]              id_opcode;
    logic [6:0]              id_funct7;
    logic [2:0]              id_funct3;
    logic [4:0]              id_rs1;
    logic [4:0]              id_rs2;
    logic [4:0]              id_rd;
    logic [DATA_WIDTH-1:0]   id_extend_imm;
    logic [DATA_WIDTH-1:0]   id_rs1_data;
    logic [DATA_WIDTH-1:0]   id_rs2_data;
    logic [DATA_WIDTH/8-1:0] id_mem_wbe;

    // EX stage signals
    logic [DATA_WIDTH-1:0] ex_alu_result;

    // WB stage signals
    logic                  wb_reg_write;
    logic [4:0]            wb_write_reg;
    logic [DATA_WIDTH-1:0] wb_write_data;

    // EX/MEM pipeline struct
    typedef struct packed {
        logic                    reg_write;
        logic                    mem_to_reg;
        logic                    mem_read;
        logic                    mem_write;
        logic [DATA_WIDTH/8-1:0] mem_wbe;
        logic [4:0]              rd;
        logic [DATA_WIDTH-1:0]   alu_result;
        logic [DATA_WIDTH-1:0]   rs2_data;
    } ex_mem_data_t;

    logic         mem_ctrl_out;
    ex_mem_data_t id_ex_data_in, mem_data_out;

    // MEM stage signals
    logic [DATA_WIDTH-1:0] mem_rdata;
    logic                  dmem_gnt, dmem_rack, dmem_wack, dmem_err;

    // Flush extension logic (2-cycle window)
    logic flush_d;
    logic real_if_id_flush;

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            flush_d <= 1'b0;
        else
            flush_d <= flush;
    end

    assign real_if_id_flush = flush || flush_d;

    // =========================================================================
    // Stage 1: Instruction Fetch (IF)
    // =========================================================================
    Ifu #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_ifu (
        .clk             (clk),
        .rst             (rst),
        .start           (start),
        .stall           (stall),
        .program_address (program_address),
        .JAL_target      (id_jal_target),
        .JALR_target     (ex_jalr_target),
        .branch_target   (id_branch_target),
        .pc_sel_execute  (id_pc_sel),
        .branch_taken    (ex_branch_taken),
        .instruction     (if_instruction),
        .inst_PC         (if_pc),
        .valid           (if_valid)
    );

    // IF/ID Pipeline Register
    PipelineReg #(
        .CTRL_WIDTH (1),
        .DATA_WIDTH (ADDR_WIDTH + DATA_WIDTH),
        .RESET_VALUE(1'b0)
    ) u_if_id_reg (
        .clk      (clk),
        .rst      (rst),
        .flush    (real_if_id_flush),
        .en       (!stall),
        .ctrl_in  (if_valid),
        .ctrl_out (id_valid),
        .data_in  ({if_pc, if_instruction}),
        .data_out ({id_pc, id_instruction})
    );

    assign id_instruction_real = id_valid ? id_instruction : NOP;

    // =========================================================================
    // Stage 2: Instruction Decode & Execute (ID / EX)
    // =========================================================================
    ControlUnit #(
        .DATA_WIDTH(DATA_WIDTH)
    ) u_control_unit (
        .clk        (clk),
        .rst        (rst),
        .opcode     (id_opcode),
        .ALUOp      (id_alu_op),
        .operand_A  (id_operand_a),
        .operand_B  (id_operand_b),
        .extend_sel (id_extend_sel),
        .regWrite   (id_reg_write),
        .branch_op  (id_branch_op),
        .memRead    (id_mem_read),
        .memWrite   (id_mem_write),
        .memtoReg   (id_mem_to_reg),
        .next_PC_sel(id_pc_sel)
    );

    Decoder #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_decoder (
        .clk          (clk),
        .rst          (rst),
        .instruction  (id_instruction_real),
        .PC           (id_pc),
        .extend_sel   (id_extend_sel),
        .reg_write    (wb_reg_write),
        .write_reg    (wb_write_reg),
        .write_data   (wb_write_data),
        .opcode       (id_opcode),
        .funct7       (id_funct7),
        .funct3       (id_funct3),
        .rs1          (id_rs1),
        .rs2          (id_rs2),
        .rd           (id_rd),
        .extend_imm   (id_extend_imm),
        .rs1_data     (id_rs1_data),
        .rs2_data     (id_rs2_data),
        .branch_target(id_branch_target),
        .JAL_target   (id_jal_target),
        .mem_wbe      (id_mem_wbe)
    );

    execute #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_execute (
        .clk          (clk),
        .rst          (rst),
        .stall        (stall),
        .ALU_Operation(id_alu_op),
        .funct7       (id_funct7),
        .funct3       (id_funct3),
        .ALU_ASrc     (id_operand_a),
        .ALU_BSrc     (id_operand_b),
        .PC           (id_pc),
        .regRead_1    (id_rs1_data),
        .regRead_2    (id_rs2_data),
        .extend       (id_extend_imm),
        .branch_op    (id_branch_op),
        .ALU_result   (ex_alu_result),
        .branch_taken (ex_branch_taken),
        .JALR_target  (ex_jalr_target)
    );

    // EX/MEM Pipeline Register Input Assignment
    assign id_ex_data_in.reg_write  = id_valid ? id_reg_write  : 1'b0;
    assign id_ex_data_in.mem_write  = id_valid ? id_mem_write  : 1'b0;
    assign id_ex_data_in.mem_read   = id_valid ? id_mem_read   : 1'b0;
    assign id_ex_data_in.mem_to_reg = id_valid ? id_mem_to_reg : 1'b0;
    assign id_ex_data_in.mem_wbe    = id_mem_wbe;
    assign id_ex_data_in.rd         = id_rd;
    assign id_ex_data_in.alu_result = ex_alu_result;
    assign id_ex_data_in.rs2_data   = id_rs2_data;

    PipelineReg #(
        .CTRL_WIDTH (1),
        .DATA_WIDTH ($bits(ex_mem_data_t)),
        .RESET_VALUE(1'b0)
    ) u_ex_mem_reg (
        .clk      (clk),
        .rst      (rst),
        .flush    (1'b0),
        .en       (!stall),
        .ctrl_in  (id_valid),
        .ctrl_out (mem_ctrl_out),
        .data_in  (id_ex_data_in),
        .data_out (mem_data_out)
    );

    // =========================================================================
    // Stage 3: Memory Access & Writeback (MEM / WB)
    // =========================================================================
    DMemTop #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .INIT_FILE (DMEM_INIT_FILE)
    ) u_dmem (
        .clk  (clk),
        .rst  (rst),
        .read (mem_data_out.mem_read),
        .write(mem_data_out.mem_write),
        .addr (mem_data_out.alu_result),
        .wdata(mem_data_out.rs2_data),
        .wbe  (mem_data_out.mem_wbe),
        .gnt  (dmem_gnt),
        .rack (dmem_rack),
        .wack (dmem_wack),
        .err  (dmem_err),
        .rdata(mem_rdata)
    );

    // Writeback Mux Logic
    assign wb_reg_write  = mem_data_out.reg_write && mem_ctrl_out;
    assign wb_write_reg  = mem_data_out.rd;
    assign wb_write_data = mem_data_out.mem_to_reg ? mem_rdata : mem_data_out.alu_result;

    // =========================================================================
    // Debug Monitor
    // =========================================================================


endmodule
