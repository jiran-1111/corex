.section .text.start
.global _start

_start:
    li sp, 0x00004000    # 设置栈顶指针（DMem 顶，向下增长，避开 .data/.rodata 低区）
    call main            # 跳转执行 C 语言 main 函数
    # main 返回后写完成标志 0x2000 = 1（测试脚本轮询该地址）
    li t0, 1
    li t1, 0x00002000
    sw t0, 0(t1)
_loop:
    j _loop              # 停机循环
