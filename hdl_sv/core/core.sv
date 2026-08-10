/*
 * COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ran Ji
 *
 * 五级流水线：IF → ID → EX → MEM → WB
 * - IF : 取指 (Ifu)
 * - ID : 译码 + 寄存器读取 (ControlUnit + Decoder)
 * - EX : ALU计算 + 分支判断 + JALR目标计算 (execute)
 * - MEM: 数据存储器访问 (DMemTop)
 * - WB : 写回多路选择 + 寄存器文件写入
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

    // =========================================================================
    // Pipeline control
    // =========================================================================
    logic stall;          // 流水线停顿（Load-Use 冒险）
    logic id_flush;       // ID 阶段 flush（JAL）
    logic ex_flush;       // EX 阶段 flush（Branch taken / JALR）
    logic if_id_flush;    // IF/ID 寄存器 flush
    logic id_ex_flush;    // ID/EX 寄存器 flush
    logic load_use_hazard;
    logic flush_any;      // ID/EX 任一阶段触发的跳转
    logic flush_d;        // flush 延迟 1 周期，形成 2 周期 flush 窗口

    // IF stage signals
    logic [DATA_WIDTH-1:0] if_instruction;
    logic [ADDR_WIDTH-1:0] if_pc;
    logic                  if_valid;

    // IF/ID pipeline register outputs
    logic [DATA_WIDTH-1:0] id_instruction;
    logic [ADDR_WIDTH-1:0] id_pc;
    logic                  id_valid;
    logic [DATA_WIDTH-1:0] id_instruction_real;

    // ID stage signals (ControlUnit outputs)
    logic [2:0]              id_alu_op;
    logic [1:0]              id_operand_a;
    logic                    id_operand_b;
    logic [2:0]              id_extend_sel;
    logic                    id_reg_write;
    logic                    id_branch_op;
    logic                    id_mem_read;
    logic                    id_mem_write;
    logic                    id_mem_to_reg;
    logic [1:0]              id_pc_sel;

    // ID stage signals (Decoder outputs)
    logic [6:0]              id_opcode;
    logic [6:0]              id_funct7;
    logic [2:0]              id_funct3;
    logic [4:0]              id_rs1;
    logic [4:0]              id_rs2;
    logic [4:0]              id_rd;
    logic [DATA_WIDTH-1:0]   id_extend_imm;
    logic [DATA_WIDTH-1:0]   id_rs1_data;
    logic [DATA_WIDTH-1:0]   id_rs2_data;
    logic [DATA_WIDTH-1:0]   id_branch_target;
    logic [DATA_WIDTH-1:0]   id_jal_target;
    logic [DATA_WIDTH/8-1:0] id_mem_wbe;

    // ID/EX pipeline register structs
    typedef struct packed {
        logic                    valid;
        logic                    reg_write;
        logic                    mem_read;
        logic                    mem_write;
        logic                    mem_to_reg;
        logic                    branch_op;
        logic [2:0]              alu_op;
        logic [1:0]              operand_a;
        logic                    operand_b;
        logic [1:0]              pc_sel;
        logic [DATA_WIDTH/8-1:0] mem_wbe;
    } id_ex_ctrl_t;

    typedef struct packed {
        logic [ADDR_WIDTH-1:0]   pc;
        logic [DATA_WIDTH-1:0]   rs1_data;
        logic [DATA_WIDTH-1:0]   rs2_data;
        logic [DATA_WIDTH-1:0]   extend_imm;
        logic [6:0]              funct7;
        logic [2:0]              funct3;
        logic [4:0]              rs1;
        logic [4:0]              rs2;
        logic [4:0]              rd;
        logic [ADDR_WIDTH-1:0]   branch_target;
    } id_ex_data_t;

    id_ex_ctrl_t id_ex_ctrl_in, id_ex_ctrl_out;
    id_ex_data_t id_ex_data_in, id_ex_data_out;

    // EX stage signals
    logic [DATA_WIDTH-1:0] ex_alu_result;
    logic                  ex_branch_taken;
    logic [ADDR_WIDTH-1:0] ex_jalr_target;

    // EX stage forwarding mux outputs
    logic [DATA_WIDTH-1:0] ex_rs1_data_fwd;
    logic [DATA_WIDTH-1:0] ex_rs2_data_fwd;

    // EX/MEM pipeline register
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
    ex_mem_data_t ex_mem_data_in, mem_data_out;

    // MEM stage signals
    logic [DATA_WIDTH-1:0] mem_rdata;
    logic                  dmem_gnt, dmem_rack, dmem_wack, dmem_err;

    // MEM/WB pipeline register
    typedef struct packed {
        logic                    reg_write;
        logic                    mem_to_reg;
        logic [4:0]              rd;
        logic [DATA_WIDTH-1:0]   alu_result;
        logic [DATA_WIDTH-1:0]   mem_rdata;
    } mem_wb_data_t;

    logic         mem_wb_ctrl_out;
    mem_wb_data_t mem_wb_data_in, mem_wb_data_out;

    // WB stage signals
    logic                  wb_reg_write;
    logic [4:0]            wb_write_reg;
    logic [DATA_WIDTH-1:0] wb_write_data;

    // =========================================================================
    // Hazard detection & pipeline control
    // =========================================================================

    // Load-Use hazard：EX 阶段的 Load 指令，其目标寄存器被 ID 阶段指令使用
    assign load_use_hazard = id_ex_ctrl_out.valid && id_ex_ctrl_out.mem_read &&
                             (id_ex_data_out.rd != 5'd0) &&
                             ((id_ex_data_out.rd == id_rs1) ||
                              (id_ex_data_out.rd == id_rs2));

    assign stall = load_use_hazard;

    // ID 阶段 flush：JAL 在 ID 阶段解析（1 个 bubble）
    assign id_flush = (id_pc_sel == 2'b10);

    // EX 阶段 flush：Branch taken / JALR 在 EX 阶段解析（2 个 bubbles）
    assign ex_flush = (id_ex_ctrl_out.pc_sel == 2'b01 && ex_branch_taken) ||
                      (id_ex_ctrl_out.pc_sel == 2'b11);

    // IMem 为同步读（rdata 滞后 addr 一拍），跳转解析的那个周期 IF 已按顺序
    // 取到跳转后的下一条（陈旧）指令，它会在下一周期才到达 IF/ID 锁存点，
    // 因此 IF/ID 需要 2 周期 flush 窗口（当前周期 + flush_d 延迟周期）。
    // ID/EX 寄存器锁存的指令已在跳转解析周期被覆盖，仅需 1 周期 flush。
    assign flush_any = id_flush || ex_flush;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) flush_d <= 1'b0;
        else     flush_d <= flush_any;
    end

    assign if_id_flush = flush_any || flush_d;
    assign id_ex_flush = ex_flush || stall;

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
        .id_pc_sel       (id_pc_sel),
        .id_jal_target   (id_jal_target),
        .ex_pc_sel       (id_ex_ctrl_out.pc_sel),
        .ex_branch_taken (ex_branch_taken),
        .ex_branch_target(id_ex_data_out.branch_target),
        .ex_jalr_target  (ex_jalr_target),
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
        .flush    (if_id_flush),
        .en       (!stall),
        .ctrl_in  (if_valid),
        .ctrl_out (id_valid),
        .data_in  ({if_pc, if_instruction}),
        .data_out ({id_pc, id_instruction})
    );

    assign id_instruction_real = id_valid ? id_instruction : NOP;

    // =========================================================================
    // Stage 2: Instruction Decode (ID)
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

    // ID/EX Pipeline Register Input Assignment
    assign id_ex_ctrl_in.valid      = id_valid;
    assign id_ex_ctrl_in.reg_write  = id_valid ? id_reg_write  : 1'b0;
    assign id_ex_ctrl_in.mem_read   = id_valid ? id_mem_read   : 1'b0;
    assign id_ex_ctrl_in.mem_write  = id_valid ? id_mem_write  : 1'b0;
    assign id_ex_ctrl_in.mem_to_reg = id_valid ? id_mem_to_reg : 1'b0;
    assign id_ex_ctrl_in.branch_op  = id_valid ? id_branch_op  : 1'b0;
    assign id_ex_ctrl_in.alu_op     = id_alu_op;
    assign id_ex_ctrl_in.operand_a  = id_operand_a;
    assign id_ex_ctrl_in.operand_b  = id_operand_b;
    assign id_ex_ctrl_in.pc_sel     = id_valid ? id_pc_sel : 2'b00;
    assign id_ex_ctrl_in.mem_wbe    = id_mem_wbe;

    assign id_ex_data_in.pc            = id_pc;
    assign id_ex_data_in.rs1_data      = id_rs1_data;
    assign id_ex_data_in.rs2_data      = id_rs2_data;
    assign id_ex_data_in.extend_imm    = id_extend_imm;
    assign id_ex_data_in.funct7        = id_funct7;
    assign id_ex_data_in.funct3        = id_funct3;
    assign id_ex_data_in.rs1           = id_rs1;
    assign id_ex_data_in.rs2           = id_rs2;
    assign id_ex_data_in.rd            = id_rd;
    assign id_ex_data_in.branch_target = id_branch_target;

    PipelineReg #(
        .CTRL_WIDTH ($bits(id_ex_ctrl_t)),
        .DATA_WIDTH ($bits(id_ex_data_t)),
        .RESET_VALUE('0)
    ) u_id_ex_reg (
        .clk      (clk),
        .rst      (rst),
        .flush    (id_ex_flush),
        .en       (1'b1),
        .ctrl_in  (id_ex_ctrl_in),
        .ctrl_out (id_ex_ctrl_out),
        .data_in  (id_ex_data_in),
        .data_out (id_ex_data_out)
    );

    // =========================================================================
    // Stage 3: Execute (EX)
    // =========================================================================

    // EX 阶段数据前推（Forwarding）
    // 源1: EX/MEM 寄存器（前一个周期 EX 的 ALU 结果，Load 除外）
    // 源2: MEM/WB 寄存器（写回数据）
    // 优先级: EX/MEM > MEM/WB > ID/EX 默认值
    always_comb begin
        if (mem_ctrl_out && mem_data_out.reg_write &&
            (mem_data_out.rd != 5'd0) && (mem_data_out.rd == id_ex_data_out.rs1) &&
            !mem_data_out.mem_read)
            ex_rs1_data_fwd = mem_data_out.alu_result;
        else if (mem_wb_ctrl_out && mem_wb_data_out.reg_write &&
                 (mem_wb_data_out.rd != 5'd0) && (mem_wb_data_out.rd == id_ex_data_out.rs1))
            ex_rs1_data_fwd = wb_write_data;
        else
            ex_rs1_data_fwd = id_ex_data_out.rs1_data;

        if (mem_ctrl_out && mem_data_out.reg_write &&
            (mem_data_out.rd != 5'd0) && (mem_data_out.rd == id_ex_data_out.rs2) &&
            !mem_data_out.mem_read)
            ex_rs2_data_fwd = mem_data_out.alu_result;
        else if (mem_wb_ctrl_out && mem_wb_data_out.reg_write &&
                 (mem_wb_data_out.rd != 5'd0) && (mem_wb_data_out.rd == id_ex_data_out.rs2))
            ex_rs2_data_fwd = wb_write_data;
        else
            ex_rs2_data_fwd = id_ex_data_out.rs2_data;
    end

    execute #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_execute (
        .clk          (clk),
        .rst          (rst),
        .stall        (stall),
        .ALU_Operation(id_ex_ctrl_out.alu_op),
        .funct7       (id_ex_data_out.funct7),
        .funct3       (id_ex_data_out.funct3),
        .ALU_ASrc     (id_ex_ctrl_out.operand_a),
        .ALU_BSrc     (id_ex_ctrl_out.operand_b),
        .PC           (id_ex_data_out.pc),
        .regRead_1    (ex_rs1_data_fwd),
        .regRead_2    (ex_rs2_data_fwd),
        .extend       (id_ex_data_out.extend_imm),
        .branch_op    (id_ex_ctrl_out.branch_op),
        .ALU_result   (ex_alu_result),
        .branch_taken (ex_branch_taken),
        .JALR_target  (ex_jalr_target)
    );

    // EX/MEM Pipeline Register Input Assignment
    assign ex_mem_data_in.reg_write  = id_ex_ctrl_out.valid ? id_ex_ctrl_out.reg_write  : 1'b0;
    assign ex_mem_data_in.mem_write  = id_ex_ctrl_out.valid ? id_ex_ctrl_out.mem_write  : 1'b0;
    assign ex_mem_data_in.mem_read   = id_ex_ctrl_out.valid ? id_ex_ctrl_out.mem_read   : 1'b0;
    assign ex_mem_data_in.mem_to_reg = id_ex_ctrl_out.valid ? id_ex_ctrl_out.mem_to_reg : 1'b0;
    assign ex_mem_data_in.mem_wbe    = id_ex_ctrl_out.mem_wbe;
    assign ex_mem_data_in.rd         = id_ex_data_out.rd;
    assign ex_mem_data_in.alu_result = ex_alu_result;
    assign ex_mem_data_in.rs2_data   = ex_rs2_data_fwd;

    PipelineReg #(
        .CTRL_WIDTH (1),
        .DATA_WIDTH ($bits(ex_mem_data_t)),
        .RESET_VALUE(1'b0)
    ) u_ex_mem_reg (
        .clk      (clk),
        .rst      (rst),
        .flush    (1'b0),
        .en       (1'b1),
        .ctrl_in  (id_ex_ctrl_out.valid),
        .ctrl_out (mem_ctrl_out),
        .data_in  (ex_mem_data_in),
        .data_out (mem_data_out)
    );

    // =========================================================================
    // Stage 4: Memory Access (MEM)
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

    // MEM/WB Pipeline Register Input Assignment
    assign mem_wb_data_in.reg_write  = mem_ctrl_out ? mem_data_out.reg_write  : 1'b0;
    assign mem_wb_data_in.mem_to_reg = mem_ctrl_out ? mem_data_out.mem_to_reg : 1'b0;
    assign mem_wb_data_in.rd         = mem_data_out.rd;
    assign mem_wb_data_in.alu_result = mem_data_out.alu_result;
    assign mem_wb_data_in.mem_rdata  = mem_rdata;

    PipelineReg #(
        .CTRL_WIDTH (1),
        .DATA_WIDTH ($bits(mem_wb_data_t)),
        .RESET_VALUE(1'b0)
    ) u_mem_wb_reg (
        .clk      (clk),
        .rst      (rst),
        .flush    (1'b0),
        .en       (1'b1),
        .ctrl_in  (mem_ctrl_out),
        .ctrl_out (mem_wb_ctrl_out),
        .data_in  (mem_wb_data_in),
        .data_out (mem_wb_data_out)
    );

    // =========================================================================
    // Stage 5: Write Back (WB)
    // =========================================================================
    assign wb_reg_write  = mem_wb_data_out.reg_write && mem_wb_ctrl_out;
    assign wb_write_reg  = mem_wb_data_out.rd;
    assign wb_write_data = mem_wb_data_out.mem_to_reg ? mem_wb_data_out.mem_rdata
                                                      : mem_wb_data_out.alu_result;

    // =========================================================================
    // Debug Monitor
    // =========================================================================
    // `define DEBUG_CORE

    `ifdef DEBUG_CORE
    initial begin
        $display("===============================================================================================================================================");
        $display(" Time(ns) | Cycle | [IF] pc_sel | [IF] next_PC | [IF] PC_reg | [IF] inst_PC | [IF] Instr | [ID] PC | [ID] Real_Inst | [EX] ALU_Result | RegW | Flush");
        $display("===============================================================================================================================================");
    end

    int cycle_cnt = 0;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) cycle_cnt <= 0;
        else cycle_cnt <= cycle_cnt + 1;
    end

    always @(posedge clk) if (!rst) begin
        $display("%8t | %5d |      2'b%b |   %h |   %h |   %h |  %h | %h |   %h   |      %h    |   %b   |   %b | stall=%b | id_flush=%b | ex_flush=%b | ex_valid=%b ex_mem=%b ex_wbe=%h | if_ack=%b",
                 $time,
                 cycle_cnt,
                 id_ex_ctrl_out.pc_sel,
                 u_ifu.next_PC,
                 u_ifu.PC_reg,
                 if_pc,
                 if_instruction,
                 id_pc,
                 id_instruction_real,
                 ex_alu_result,
                 wb_reg_write,
                 if_id_flush,
                 stall,
                 id_flush,
                 ex_flush,
                 id_ex_ctrl_out.valid,
                 id_ex_ctrl_out.mem_read,
                 id_ex_ctrl_out.mem_wbe,
                 if_valid
        );

        if (ex_flush) begin
            $display("          >>> [FLUSH DETECTED] Branch/Jump Taken at Time %0t ns | Target PC: %h <<<", $time, u_ifu.next_PC);
        end
    end
    `endif

endmodule