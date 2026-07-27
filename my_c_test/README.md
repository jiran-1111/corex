.c文件 
.elf
.hex


1、启动文件（汇编入口）：.crt0.s

2、main.c c语言测试程序，简单程序，如加减法、数组遍历、递归算法等

3、链接脚本  link.ld

告诉编译器指令段.text和数据段.data放在哪些内存地址 需要配合coreTop

4、交叉编译与生成hex机器码

需要安装riscv交叉编译器（riscv32-unkonwn-elf-gcc）

使用makefile执行编译 导出为16进制文本格式（hex）

5、使用cocotb加载hex并进行自动化验证，动态解析生成的.hex文件


实验步骤

1、编写main.c crt0.s link.ld Makefile文件

2、安装gcc-riscv64-unknown-elf 交叉编译器

```
sudo apt update
sudo apt install gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf


(base) ranrr@ranran:~/pku_workspace/corex/c_test$ which riscv64-unknown-elf-gcc
/bin/riscv64-unknown-elf-gcc

检查是否安装成功
```
3、执行make指令 make TEST=adder

得到add_test.dump,add_test.elf,add_test.hex  4个新生成的文件

4、编写test_core_adder.py  用于加载hex文件并进行验证

5、运行 python -m pytest testcases/test_core_adder.py

运行testcases目录下的所有测试python -m pytest testcases/


6、运行所有测试
```
make run-all

make run TEST=sort //运行指定的单个测试：
make run TEST=factorial
```