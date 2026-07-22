/* COREX: Co-modeling RISC-V Example Core
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
    input logic clk,
    input logic rst,
    input logic start,
    input logic [ADDR_WIDTH-1:0] program_address
);

    // =========================================================================
    // 信号定义
    // =========================================================================

    // 流水线控制信号
    logic stall;
    logic flush;
    assign stall = 1'b0; // 基础三级流水线暂未加入 Hazard Unit 时固定为 0
    assign flush =  (id_pc_sel == 2'b01 && ex_branch_taken) || // Branch 且成功跳转
                    (id_pc_sel == 2'b10) ||                  // JAL
                    (id_pc_sel == 2'b11);                    // JALR


    localparam NOP = 32'h00000013;
    // -------------------------------------------------------------------------
    // Stage 1: IF 阶段信号
    // -------------------------------------------------------------------------
    logic [DATA_WIDTH-1:0] if_instruction;
    logic [ADDR_WIDTH-1:0] if_pc;
    logic if_valid;

    // 反馈跳转信号 (来自 ID/EX 阶段)
    logic [1:0]            id_pc_sel;
    logic                  ex_branch_taken;
    logic [ADDR_WIDTH-1:0] id_branch_target;
    logic [ADDR_WIDTH-1:0] id_jal_target;
    logic [ADDR_WIDTH-1:0] ex_jalr_target;

    // -------------------------------------------------------------------------
    // IF/ID 流水线寄存器输出
    // -------------------------------------------------------------------------
    logic [DATA_WIDTH-1:0] id_instruction;
    logic [ADDR_WIDTH-1:0] id_pc;
   
    logic id_valid;

    logic [DATA_WIDTH-1:0] id_instruction_real;
    // -------------------------------------------------------------------------
    // Stage 2: ID/EX 阶段信号
    // -------------------------------------------------------------------------
    // Control Unit 输出
    logic [2:0] id_alu_op;
    logic [1:0] id_operand_a;
    logic       id_operand_b;
    logic [2:0] id_extend_sel;
    logic       id_reg_write;
    logic       id_branch_op;
    logic       id_mem_read;
    logic       id_mem_write;
    logic       id_mem_to_reg;
    
    // Decoder 输出
    logic [6:0]            id_opcode;
    logic [6:0]            id_funct7;
    logic [2:0]            id_funct3;
    logic [4:0]            id_rs1;
    logic [4:0]            id_rs2;
    logic [4:0]            id_rd;
    logic [DATA_WIDTH-1:0] id_extend_imm;
    logic [DATA_WIDTH-1:0] id_rs1_data;
    logic [DATA_WIDTH-1:0] id_rs2_data;
    logic [DATA_WIDTH/8-1:0] id_mem_wbe;

    // Execute 模块输出
    logic [DATA_WIDTH-1:0] ex_alu_result;

    // 写回阶段反馈信号 (来自 MEM/WB 阶段)
    logic                  wb_reg_write;
    logic [4:0]            wb_write_reg;
    logic [DATA_WIDTH-1:0] wb_write_data;

    // -------------------------------------------------------------------------
    // Forwarding (前向传递/旁路) 信号
    // -------------------------------------------------------------------------
    logic [DATA_WIDTH-1:0] forward_a_data;
    logic [DATA_WIDTH-1:0] forward_b_data;

    // -------------------------------------------------------------------------
    // EX/MEM 流水线寄存器数据打包与解包
    // -------------------------------------------------------------------------

    // 数据总线打拍 (EX/MEM)
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

    logic mem_ctrl_out;
    ex_mem_data_t id_ex_data_in, mem_data_out;

    // -------------------------------------------------------------------------
    // Stage 3: MEM/WB 阶段信号
    // -------------------------------------------------------------------------
    logic [DATA_WIDTH-1:0] mem_rdata;
    logic                  dmem_gnt, dmem_rack, dmem_wack, dmem_err;
    
    
    logic flush_d;//flush两拍
    logic real_if_id_flush;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) 
            flush_d <= 1'b0;
        else 
            flush_d <= flush; // 锁存上一拍的 flush
    end

    // 2. 最终给 IF/ID 寄存器的 flush 信号，要覆盖“当前拍”和“下一拍”
    assign real_if_id_flush = flush || flush_d;
    
    
    // =========================================================================
    // 1. IF 阶段 (Instruction Fetch)
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

    // =========================================================================
    // Pipeline Reg 1: IF / ID
    // =========================================================================
    // 打拍保存 IF 阶段读出的指令与当前指令对应的 PC 地址

    PipelineReg #(
        .CTRL_WIDTH (1),            
        .DATA_WIDTH (ADDR_WIDTH + DATA_WIDTH),
        .RESET_VALUE(1'b0)

    ) u_if_id_reg (
        .clk      (clk),
        .rst      (rst),
        .flush    (real_if_id_flush),
        //.flush    (flush),
        .en       (!stall),
        .ctrl_in  (if_valid),
        .ctrl_out (id_valid),
        .data_in  ({if_pc,if_instruction}),
        .data_out ({id_pc,id_instruction})
    );

    assign id_instruction_real = id_valid ? id_instruction : NOP;


    // =========================================================================
    // 2. ID / EX 阶段 (Decode & Execute)
    // =========================================================================
    
    // 主控制器
    ControlUnit #(
        .DATA_WIDTH(DATA_WIDTH)
    ) u_control_unit (
        .clk          (clk),
        .rst          (rst),
        .opcode       (id_opcode),

        .ALUOp        (id_alu_op),
        .operand_A    (id_operand_a),
        .operand_B    (id_operand_b),
        .extend_sel   (id_extend_sel),
        .regWrite     (id_reg_write),
        .branch_op    (id_branch_op),
        .memRead      (id_mem_read),
        .memWrite     (id_mem_write),
        .memtoReg     (id_mem_to_reg),
        .next_PC_sel  (id_pc_sel)
    );

    // 指令译码器 & 寄存器堆
    Decoder #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_decoder (
        .clk           (clk),
        .rst           (rst),
        .instruction   (id_instruction_real),
        .PC            (id_pc),
        .extend_sel    (id_extend_sel),     // control_unit
        .reg_write     (wb_reg_write),      // 来自 MEM/WB 阶段写回使能
        .write_reg     (wb_write_reg),      // 来自 MEM/WB 阶段写回地址
        .write_data    (wb_write_data),     // 来自 MEM/WB 阶段写回数据

        .opcode        (id_opcode),
        .funct7        (id_funct7),
        .funct3        (id_funct3),
        .rs1           (id_rs1),
        .rs2           (id_rs2),
        .rd            (id_rd),
        .extend_imm    (id_extend_imm),
        .rs1_data      (id_rs1_data),
        .rs2_data      (id_rs2_data),
        .branch_target (id_branch_target),
        .JAL_target    (id_jal_target),
        .mem_wbe       (id_mem_wbe)
    );


    
    // 执行单元 (ALU) - 传入经过前向传递选择后的操作数
    execute #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_execute (
        .clk           (clk),
        .rst           (rst),
        .stall         (stall),
        .ALU_Operation (id_alu_op),
        .funct7        (id_funct7),
        .funct3        (id_funct3),
        .ALU_ASrc      (id_operand_a),
        .ALU_BSrc      (id_operand_b),
        .PC            (id_pc),
        .regRead_1     (id_rs1_data), 
        .regRead_2     (id_rs2_data),  
        .extend        (id_extend_imm),
        .branch_op     (id_branch_op),

        .ALU_result    (ex_alu_result),
        .branch_taken  (ex_branch_taken),
        .JALR_target   (ex_jalr_target)
    );
    
    // =========================================================================
    // Pipeline Reg 2: EX / MEM
    // =========================================================================
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
    // 3. MEM / WB 阶段 (Memory Access & Writeback)
    // =========================================================================

    // 数据存储器 (DMemTop)
    DMemTop #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .INIT_FILE(DMEM_INIT_FILE)
    ) u_dmem (
        .clk   (clk),
        .rst   (rst),
        .read  (mem_data_out.mem_read),
        .write (mem_data_out.mem_write),
        .addr  (mem_data_out.alu_result),
        .wdata (mem_data_out.rs2_data),
        .wbe   (mem_data_out.mem_wbe),
        
        .gnt   (dmem_gnt),
        .rack  (dmem_rack),
        .wack  (dmem_wack),
        .err   (dmem_err),
        .rdata (mem_rdata)
    );

    // 写回控制逻辑 (WB Multiplexer)
    assign wb_reg_write  = mem_data_out.reg_write && mem_ctrl_out;;
    assign wb_write_reg  = mem_data_out.rd;
    // 选择把内存读取结果还是 ALU 运算结果写回 RegFile
    assign wb_write_data = mem_data_out.mem_to_reg ? mem_rdata : mem_data_out.alu_result;


    // =========================================================================
    // 调试日志 (Debug Monitor)
    // =========================================================================
    
    `define DEBUG_CORE

    `ifdef DEBUG_CORE
    initial begin
        $display("===============================================================================================================================================");
        $display(" Time(ns) | Cycle | [IF] pc_sel | [IF] next_PC | [IF] PC_reg | [IF] inst_PC | [IF] Instr | [ID] PC | [ID] Real_Inst | [EX] WB_Data | RegW | Flush");
        $display("===============================================================================================================================================");
    end

    int cycle_cnt = 0;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) cycle_cnt <= 0;
        else cycle_cnt <= cycle_cnt + 1;
    end

    always @(posedge clk) if (!rst) begin
        $display("%8t | %5d |      2'b%b |   %h |   %h |   %h |  %h | %h |   %h   |   %h   |  %b   |   %b", 
                 $time, 
                 cycle_cnt,
                 id_pc_sel,               // 跳转选择控制信号 (01:Branch, 10:JAL, 11:JALR)
                 u_ifu.next_PC,           // 组合逻辑计算出的下一个 PC 地址
                 u_ifu.PC_reg,            // IFU 当前时序锁存的 PC 寄存器
                 if_pc,                   // IFU 输出的与当前指令对齐的 inst_PC
                 if_instruction,          // IMem 读出的原始指令
                 id_pc,                   // 进入 ID 阶段的指令 PC 地址
                 id_instruction_real,     // ID 阶段实际执行的指令（Flush 时会自动变为 NOP）
                 wb_write_data,           // 当前 WB 阶段写入寄存器的数据
                 wb_reg_write,            // 当前 WB 阶段写回使能
                 real_if_id_flush         // IF/ID 寄存器清空信号
        );
                 
        if (flush) begin
            $display("          >>> [FLUSH DETECTED] Branch/Jump Taken at Time %0t ns | Target PC: %h <<<", $time, u_ifu.next_PC);
        end
    end
    `endif
endmodule
