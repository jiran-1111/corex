/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Ziqing Lin
 */

// Integer register file
// Features:
// - Two combinational read ports and one synchronous write port.
// - Synchronous reset clears all registers.
// - x0 is hardwired to zero when ZERO_X0 is set.
// - Read-after-write to the same address returns the write data.

module RegFile #(
    parameter int DATA_WIDTH = 32,
    parameter int SEL_WIDTH = 5,
    parameter bit ZERO_X0 = 1'b1  // 常量减少重复
) (
    input logic clk,
    input logic rst,
    // asic中需要异步的reset,在fpga中需要同步的reset
    // 偏向fpga项目
    // 要对比不同处理器的写法
    input logic wen,
    input logic [SEL_WIDTH-1:0] waddr,
    input logic [DATA_WIDTH-1:0] wdata,

    input logic [SEL_WIDTH-1:0] raddr1,
    input logic [SEL_WIDTH-1:0] raddr2,
    output logic [DATA_WIDTH-1:0] rdata1,
    output logic [DATA_WIDTH-1:0] rdata2
);

    localparam int REG_COUNT = 2 ** SEL_WIDTH;

    // Register array
    // derective:写给编译器的指令

    //(* ram_style = "distributed" *)  // 不建议这么写？
    logic [DATA_WIDTH-1:0] regs[0:REG_COUNT-1];

    // 教科书 bypass:前半周期读 后半周期写
    // 处理器变复杂后 需要更复杂的bypass网络

    //没有bypass的版本 后续需要实现
    //generate
        //if (ZERO_X0) begin : gen_zero_x0
            //assign rdata1 = (raddr1 == '0) ? '0 : regs[raddr1];
            //assign rdata2 = (raddr2 == '0) ? '0 : regs[raddr2];
        //end else begin : gen_writable_x0
            //assign rdata1 = regs[raddr1];
            //assign rdata2 = regs[raddr2];
        //end
    //endgenerate

    // 初步在reg_file内部实现bypass的版本
    generate
        if (ZERO_X0) begin : gen_zero_x0
            // 读地址为0时硬编码为0；
            // 读地址与写地址相同时，若写使能有效，直接前传 wdata，否则读寄存器堆。
            assign rdata1 = (raddr1 == '0)             ? '0 : 
                            ((raddr1 == waddr) && wen) ? wdata : regs[raddr1];
                            
            assign rdata2 = (raddr2 == '0)             ? '0 : 
                            ((raddr2 == waddr) && wen) ? wdata : regs[raddr2];
        end else begin : gen_writable_x0
            // 无 x0 硬编码限制时的前传逻辑
            assign rdata1 = ((raddr1 == waddr) && wen) ? wdata : regs[raddr1];
            assign rdata2 = ((raddr2 == waddr) && wen) ? wdata : regs[raddr2];
        end
    endgenerate

    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < REG_COUNT; i++) begin
                regs[i] <= '0;
            end
        end else if (!rst && wen) begin
            regs[waddr] <= wdata;
        end
    end

endmodule
