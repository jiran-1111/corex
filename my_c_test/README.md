# C语言测试文件夹

## 该文件夹为对RTL三级流水线进行C语言程序的测试文件

## 一、文件结构

```
.
├── Makefile
├── README.md
├── bsp
│   ├── crt0.s            //汇编入口文件
│   └── link.ld           //链接脚本
├── cocotb_utils.py       //cocotb工具
├── src                //c语言源文件
│   ├── adder.c           //加法器
│   ├── binary_search.c   //二分查找
│   ├── crc32.c           //crc32
│   ├── factorial.c       //阶乘
│   ├── fibonacci.c       //斐波那契数列
│   ├── jar.c             //jar函数调用
│   ├── soft_mul_bit.c    //软乘法与位翻转
│   ├── sort.c            //冒泡排序
│   ├── str_toggle.c      //大小写反转
│   └── sum.c             //求和
└── sim_build
└── testcases            //cocotb测试用例文件夹
    ├── test_core_program.py   //通用测试脚本（内置 PROGRAMS 注册表，覆盖所有 C 程序）
    └── conftest.py            //COVERAGE=1 时启用 Python 覆盖率
```

## 二、说明
1、启动文件（汇编入口）：.crt0.s

2、main.c c语言测试程序，简单程序，如加减法、数组遍历、递归算法等

3、链接脚本  link.ld

告诉编译器指令段.text和数据段.data放在哪些内存地址 需要配合coreTop

4、交叉编译与生成hex机器码

需要安装riscv交叉编译器（riscv32-unkonwn-elf-gcc）

使用makefile执行编译 导出为16进制文本格式（hex）

5、使用cocotb加载hex并进行自动化验证，动态解析生成的.hex文件


## 三、实验步骤

1、编写main.c crt0.s link.ld Makefile文件

2、安装gcc-riscv64-unknown-elf 交叉编译器

```
sudo apt update
sudo apt install gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf


(base) ranrr@ranran:~/pku_workspace/corex/c_test$ which riscv64-unknown-elf-gcc
显示：/bin/riscv64-unknown-elf-gcc

检查是否安装成功
```
3、执行make指令 make TEST=adder

得到build/adder/ 下的 test.dump, test.elf, test.hex 编译产物

4、在 testcases/test_core_program.py 的 PROGRAMS 注册表中添加该程序的检查项
（超时周期 + 结果地址与期望值），无需另写 cocotb 脚本

5、运行 make run TEST=adder 运行单个测试
（等价于 python -m pytest testcases/test_core_program.py -k adder）

运行所有测试：make run-all


6、运行所有测试
```
make run-all

make run TEST=sort //运行指定的单个测试：
make run TEST=factorial
```

## 四、测试指令

```
cd ~/pku_workspace/corex/my_c_test
make run-all 
make clean
make TEST=adder
make run TEST=adder

```

## 五、添加测试

- 1、编写c语言源文件 src/name.c——结果写入 0x1000 起始的 DMem，结束前写 0x2000=1
- 2、在 testcases/test_core_program.py 的 PROGRAMS 注册表加一行（超时周期 + 结果地址与期望值）
- 3、运行 make run TEST=name 进行验证


