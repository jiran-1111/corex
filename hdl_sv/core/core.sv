/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 */

module corex #(
    parameter int DATA_WIDTH = 32,
    parameter int ADDR_WIDTH = 32
)(
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  start,
    input  logic                  stall,
    input  logic [ADDR_WIDTH-1:0] program_address,

    output logic                  monitor_valid,      // 当前时钟周期是否有有效指令写回
    output logic [ADDR_WIDTH-1:0] monitor_pc,         // 当前写回指令对应的 PC
    output logic [4:0]            monitor_waddr,      // 写回的目的寄存器号 (rd)
    output logic [DATA_WIDTH-1:0] monitor_wdata       // 写回寄存器的真实数据
);

    // ==========================================================================
    // 1. Instruction Fetch (IF) Stage
    // ==========================================================================
    logic [DATA_WIDTH-1:0] if_instruction;// imem输出 32位指令
    logic [ADDR_WIDTH-1:0] if_pc;         // pc_reg 当前指令对应的pc地址

    Ifu #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_ifu (
        .clk(clk),
        .rst(rst),
        .start(start),
        .stall(stall),
        .program_address(program_address),
        
        .instruction(if_instruction),
        .inst_PC(if_pc)
    );

    // ==========================================================================
    // 2. IF/ID Pipeline Register
    // ==========================================================================
    localparam int IF_ID_CTRL_W = 1;
    localparam int IF_ID_DATA_W = ADDR_WIDTH + DATA_WIDTH;

    logic [IF_ID_CTRL_W-1:0] if_id_ctrl_out;
    logic [IF_ID_DATA_W-1:0] if_id_data_out;

    logic [ADDR_WIDTH-1:0]   id_pc;
    logic [DATA_WIDTH-1:0]   id_instruction;

    PipelineReg #(
        .CTRL_WIDTH(IF_ID_CTRL_W),
        .DATA_WIDTH(IF_ID_DATA_W)
    ) u_pipe_if_id (
        .clk(clk),
        .rst(rst),
        .flush(1'b0),
        .en(!stall),

        .ctrl_in(1'b1), 
        .ctrl_out(if_id_ctrl_out),
        .data_in({if_pc, if_instruction}),
        .data_out(if_id_data_out)
    );

    assign {id_pc, id_instruction} = if_id_data_out;

    // ==========================================================================
    // 3. Instruction Decode (ID) Stage
    // ==========================================================================
    logic [6:0]            id_opcode;
    logic [6:0]            id_funct7;
    logic [2:0]            id_funct3;
    logic [4:0]            id_rs1;
    logic [4:0]            id_rs2;
    logic [4:0]            id_rd;
    logic [DATA_WIDTH-1:0] id_extend_imm;
    logic [DATA_WIDTH-1:0] id_rs1_data;
    logic [DATA_WIDTH-1:0] id_rs2_data;

    logic [2:0]            id_alu_op;
    logic [1:0]            id_operand_A_sel;
    logic                  id_operand_B_sel;
    logic                  id_extend_sel;
    logic                  id_reg_write;

    // Feedback signals from EX stage
    logic                  ex_reg_write;
    logic [4:0]            ex_rd;
    logic [DATA_WIDTH-1:0] ex_alu_result;

    ControlUnit u_control (
        .clk(clk),
        .rst(rst),
        .opcode(id_opcode),//decoder的输出

        .ALUOp(id_alu_op),
        .operand_A(id_operand_A_sel),
        .operand_B(id_operand_B_sel),
        .extend_sel(id_extend_sel),
        .regWrite(id_reg_write)
    );

    Decoder #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_decoder (
        .clk(clk),
        .rst(rst),
        .instruction(id_instruction),

        .extend_sel(id_extend_sel),// controlunitshuchu 
        .reg_write(ex_reg_write),
        .write_reg(ex_rd),
        .write_data(ex_alu_result),

        .opcode(id_opcode),
        .funct7(id_funct7),
        .funct3(id_funct3),
        .rs1(id_rs1),
        .rs2(id_rs2),
        .rd(id_rd),
        .extend_imm(id_extend_imm),
        .rs1_data(id_rs1_data),
        .rs2_data(id_rs2_data)
    );

    // ==========================================================================
    // 4. ID/EX Pipeline Register
    // ==========================================================================
    //localparam int ID_EX_CTRL_W = 7;
    localparam int ID_EX_CTRL_W = 7 + ADDR_WIDTH;// 7 + 32 = 39 位
    // 数据包中增加一路传递当前指令的 PC，用于 debug 追溯
    //localparam int ID_EX_DATA_W = ADDR_WIDTH + DATA_WIDTH*3 + 5;
    localparam int ID_EX_DATA_W = DATA_WIDTH*3 + 5; // 32*3 + 5 = 101 位

    logic [ID_EX_CTRL_W-1:0] id_ex_ctrl_out;
    logic [ID_EX_DATA_W-1:0] id_ex_data_out;

    logic [2:0]            ex_alu_op;
    //logic [1:0]            ex_alu_asrc;
    //logic                  ex_alu_bsrc;
    logic [1:0] ex_operand_A_sel;
    logic ex_operand_B_sel;
    logic [ADDR_WIDTH-1:0] ex_pc;
    logic [DATA_WIDTH-1:0] ex_rs1_data;
    logic [DATA_WIDTH-1:0] ex_rs2_data;
    logic [DATA_WIDTH-1:0] ex_extend_imm;
    logic [6:0]            ex_funct7;
    logic [2:0]            ex_funct3;

    PipelineReg #(
        .CTRL_WIDTH(ID_EX_CTRL_W),
        .DATA_WIDTH(ID_EX_DATA_W)
    ) u_pipe_id_ex (
        .clk(clk),
        .rst(rst),
        .flush(1'b0),
        .en(!stall),

        //.ctrl_in({id_alu_op, id_operand_A_sel, id_operand_B_sel, id_reg_write, id_pc}),
        //.ctrl_out(id_ex_ctrl_out),
        //.data_in({id_rs1_data, id_rs2_data, id_extend_imm, id_rd}),
        //.data_out(id_ex_data_out)

        .ctrl_in({id_alu_op, id_operand_A_sel, id_operand_B_sel, id_reg_write, id_pc}),
        .ctrl_out(id_ex_ctrl_out),
        .data_in({id_rs1_data, id_rs2_data, id_extend_imm, id_rd}),
        .data_out(id_ex_data_out)
    );

    //assign {ex_alu_op, ex_alu_asrc, ex_alu_bsrc, ex_reg_write,ex_pc} = id_ex_ctrl_out;
    //assign {ex_rs1_data, ex_rs2_data, ex_extend_imm, ex_rd} = id_ex_data_out;
    
    assign {ex_alu_op, ex_operand_A_sel, ex_operand_B_sel, ex_reg_write, ex_pc} = id_ex_ctrl_out;
    assign {ex_rs1_data, ex_rs2_data, ex_extend_imm, ex_rd} = id_ex_data_out;

    always_ff @(posedge clk) begin
        if (rst) begin
            ex_funct7 <= 7'd0;
            ex_funct3 <= 3'd0;
        end else if (!stall) begin
            ex_funct7 <= id_funct7;
            ex_funct3 <= id_funct3;
        end
    end

    // ==========================================================================
    // 5. Execution (EX) Stage
    // ==========================================================================
    execute #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_execute (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .ALU_Operation(ex_alu_op),
        .funct7(ex_funct7),
        .funct3(ex_funct3),
        //.ALU_ASrc(ex_alu_asrc),
        //.ALU_BSrc(ex_alu_bsrc),
        .ALU_ASrc(ex_operand_A_sel), // 修改这里，使用刚刚解包出的 ex_operand_A_sel
        .ALU_BSrc(ex_operand_B_sel), // 修改这里，使用刚刚解包出的 ex_operand_B_sel
        .PC(ex_pc),
        .regRead_1(ex_rs1_data),
        .regRead_2(ex_rs2_data),
        .extend(ex_extend_imm),
        
        .ALU_result(ex_alu_result)
    );

    // ==========================================================================
    // 6. Connect Outputs to Monitor Interface
    // ==========================================================================
    // 当指令有效、未被 stall 且寄存器写使能有效时，输出写回监视
    logic is_running;
    assign monitor_valid = ex_reg_write && !stall && !rst;
    assign monitor_pc    = ex_pc;
    assign monitor_waddr = ex_rd;
    assign monitor_wdata = ex_alu_result;
    
    assign is_running = !rst && (u_ifu.fetch || stall);

    always_ff @(posedge clk) begin
        if (is_running) begin
            $display("\n======================= [COREX CYCLE @ %0t] =======================", $time);
            $display("  [GLOBAL STATUS]  stall: %b | start: %b", stall, start);
            $display("-----------------------------------------------------------------");
            
            // 1. IF 阶段监控
            $display("  [IF Stage]  PC_reg(ifu): 0x%h | if_pc(output): 0x%h | inst: 0x%h | gnt: %b",
                     u_ifu.PC_reg, if_pc, if_instruction, u_ifu.imem_gnt);
            
            // 2. IF/ID 寄存器输入与输出对比
            $display("  [IF/ID Reg] In_PC: 0x%h -> Out_PC: 0x%h (En: %b)",
                     if_pc, id_pc, !stall);
            
            // 3. ID 阶段监控 (译码出的指令信息)
            $display("  [ID Stage]  id_pc: 0x%h | id_inst: 0x%h | opcode: 7'b%b | rd: d%0d",
                     id_pc, id_instruction, id_opcode, id_rd);
            $display("              regWrite_sel: %b | rs1_data: 0x%h | rs2_data: 0x%h | imm: 0x%h",
                     id_reg_write, id_rs1_data, id_rs2_data, id_extend_imm);

            // 4. ID/EX 寄存器输入与输出对比
            $display("  [ID/EX Reg] In_PC: 0x%h -> Out_PC: 0x%h (En: %b)",
                     id_pc, ex_pc, !stall);

            // 5. EX 阶段监控 (执行与写回结果)
            $display("  [EX Stage]  ex_pc: 0x%h | alu_op: %b | rs1_val: 0x%h | rs2_val: 0x%h",
                     ex_pc, ex_alu_op, ex_rs1_data, ex_rs2_data);
            $display("              ALU_Result: 0x%h | ex_rd: d%0d | ex_reg_write: %b",
                     ex_alu_result, ex_rd, ex_reg_write);

            // 6. 最终写回 Monitor 监控
            $display("  [MONITOR]   valid: %b | pc: 0x%h | waddr(rd): d%0d | wdata: 0x%h",
                     monitor_valid, monitor_pc, monitor_waddr, monitor_wdata);
            $display("=================================================================");
        end
    end

endmodule