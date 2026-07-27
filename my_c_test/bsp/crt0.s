.section .text.start
.global _start

_start:
    li sp, 0x00000800    # 设置栈顶指针
    call main            # 跳转执行 C 语言 main 函数
_loop:
    j _loop              # main 函数返回后死循环停机