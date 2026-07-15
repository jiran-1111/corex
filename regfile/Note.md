# 2026.7.2

## 注释解读
```systemverilog
// Integer register file
// 整数寄存器堆
// Features:
// - Two combinational read ports and one synchronous write port.
//   两个组合逻辑读端口和一个同步写端口（同步写：等下一个时钟上升沿写 防止毛刺 数据传输可能不稳定
// - Synchronous reset clears all registers.
//   synchronous reset 同步复位，清除所有寄存器
// - x0 is hardwired to zero when ZERO_X0 is set.
//   ZERO_X0配置开关开启，hardwired硬连线，x0永远读出为0
// - Read-after-write to the same address returns the write data.
//   写后读发生锁存/冲突时，直接返回正在写入的数据
```
## 外部可调参数
```systemverilog
module RegFile #(
    parameter int REG_DATA_WIDTH = 32, // 数据宽度
    parameter int REG_SEL_WIDTH = 5,   // 地址宽度 2^5=32
    parameter bit ZERO_X0 = 1'b1       // x0寄存器是否硬连线的开关 默认1开启
) 
```

## 信号
```systemverilog
(
    input logic clk,
    input logic rst,
    // 1个同步写端口
    input logic wen,                        // 写使能开关 允许写入
    input logic [REG_SEL_WIDTH-1:0] waddr,  // 写地址
    input logic [REG_DATA_WIDTH-1:0] wdata, // 写数据
    // 2个读端口
    input logic [REG_SEL_WIDTH-1:0] raddr1, // 读地址1
    input logic [REG_SEL_WIDTH-1:0] raddr2, // 读地址2
    output logic [REG_DATA_WIDTH-1:0] rdata1, // 读数据1
    output logic [REG_DATA_WIDTH-1:0] rdata2 // 读数据2
);

```
## 实现
```systemverilog
    
    localparam int REG_COUNT = 2 ** REG_SEL_WIDTH; // 地址宽度REG_SEL_WIDTH=5 内部确立共32个寄存器
    // localparam内部私有常量

    // Register array
    //fpga内部只有两个地方存数据
    //分布式RAM distributed RAM 可异步读可同步读
    //块RAM block ram 设计大容量存储时使用 必须同步读
    (* ram_style = "distributed" *) // 属性指示 使用分布式RAM来实现 
    logic [REG_DATA_WIDTH-1:0] regs[0:REG_COUNT-1]; // 定义真正的32个寄存器数组  每个寄存器可以放一个32位的数据 regs为变量名 该行代码左边表示寄存器数组大小 右边表示寄存器个数

    // *********写逻辑*********
    logic write_fire; // 触发写入 只有当它为1时候，数据才会写进
    // 该信号定义了数据写进的3个条件
    // 1. rst复位信号为0
    // 2. wen写使能信号为1
    // 3. ZERO_X0硬连线开关为0 或者 waddr写地址不为0
    // 要么压根没开启 ZERO_X0 功能，要么你开启了，但你写的目标地址不能是0号寄存器。直接在源头上掐死：禁止任何人污染 x0 寄存器。

    assign write_fire = !rst && wen && (!ZERO_X0 || (waddr != '0));

    // *********读逻辑*********
    // 1. 如果开启ZERO_X0，且读地址为0，则直接返回0
    // 2. 如果读写任务都有，且读的地址raddr和写入地址waddr相同，则把准备写入的wdata截胡送给读端口
    // 3. 默认是regs[raddr]
    assign rdata1 = (ZERO_X0 && (raddr1 == '0)) ? '0 :
                    (write_fire && (waddr == raddr1)) ? wdata :
                    regs[raddr1];
    assign rdata2 = (ZERO_X0 && (raddr2 == '0)) ? '0 :
                    (write_fire && (waddr == raddr2)) ? wdata :
                    regs[raddr2];

    // 所有动作是同步逻辑，看上升沿

    always_ff @(posedge clk) begin
        if (rst) begin // 同步复位 所有寄存器为0
            for (int i = 0; i < REG_COUNT; i++) begin
                regs[i] <= '0;
            end
        end else if (write_fire) begin // 同步写
            regs[waddr] <= wdata; // 写入 非阻塞赋值 时序逻辑 
        end
    end
```
