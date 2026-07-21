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
 * Author: Chun Yang
 */

// Pipeline register
// Features:
// - Separate control and data registers.
// - Control register supports flush and synchronous reset.
// - Data register has no reset or flush for better PPA.
// - Data validity must be guaranteed by the control register.
module PipelineReg #(
    parameter int CTRL_WIDTH = 16,    // 控制总线位宽
    parameter int DATA_WIDTH = 32,    // 数据总线位宽
    parameter [CTRL_WIDTH-1:0] RESET_VALUE = '0  // 复位和清空时控制寄存器的默认值 
) (
    input logic clk,  // 时钟信号
    input logic rst,  // 复位信号
    input logic flush, // 流水线清空信号
    input logic en,   // 使能信号 如果下游阻塞stall en会变低 锁住当前数据
    // Control path 控制信号的输入输出
    input logic [CTRL_WIDTH-1:0] ctrl_in,
    output logic [CTRL_WIDTH-1:0] ctrl_out,
    // Data path 数据信号的输入输出
    input logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out
);

    // Control and data registers 将内部的控制/数据寄存器的值引出到输出端口
    logic [CTRL_WIDTH-1:0] ctrl_q;
    logic [DATA_WIDTH-1:0] data_q;
    assign ctrl_out = ctrl_q;
    assign data_out = data_q;

    // Control path
    // Priority: reset > flush > enable
    always_ff @(posedge clk) begin
        if (rst) begin
            ctrl_q <= RESET_VALUE;
        end else begin
            // Flush has higher priority than enable.
            if (flush) begin
                ctrl_q <= RESET_VALUE;
            end else if (en) begin
                ctrl_q <= ctrl_in;

            end
        end
    end

    // Data path
    // NO reset or flush for PPA optimization.
    // Data validity must be guaranteed by the control path.
    always_ff @(posedge clk) begin
        if (en) begin
            data_q <= data_in;
        end
    end

endmodule
