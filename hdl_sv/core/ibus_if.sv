/* COREX: Co-modeling RISC-V Example Core
 *
 * Copyright (C) 2026 Microprocessor R&D Center (MPRC), Peking University
 * All rights reserved.
 *
 * Author: Chun Yang
 */

// Instruction bus interface between IFU and memory
// 地址总线 数据总线 默认32位
interface IBusIf #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
)();

    // Address request
    //请求阶段信号 cpu->内存
    //req: 请求信号，1表示有请求，0表示没有请求
    //addr: 地址信号，表示请求的地址
    logic req;
    logic [ADDR_WIDTH-1:0] addr;

    // Data response
    //响应阶段信号 cpu<-内存
    //gnt: 授权信号，1表示授权，0表示拒绝
    //ack: 确认信号，1表示确认，0表示未确认
    //err: 错误信号，1表示错误，0表示无错误
    //rdata: 数据信号，表示响应的数据 读数据线 内存中读出来的指令机器码
    logic gnt;
    logic ack;
    logic err;
    logic [DATA_WIDTH-1:0] rdata;

    // From IFU to memory
    // master: cpu
    // slave: 内存
    modport master (
        output req, addr,
        input gnt, ack, err, rdata
    );

    // From memory to IFU
    modport slave (
        input req, addr,
        output gnt, ack, err, rdata
    );

endinterface
