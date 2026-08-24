/* COREX 控制台输出：把 printf 的字节写到 DMem 固定地址的缓冲，
 * 供 cocotb 测试读取比对（见 test_core_program.py 的 console 检查）。
 *
 * 缓冲地址 0x2800 起，逐字节（SB 指令）写入，索引自增。
 * 索引存于 .bss（DMem 区，初始全零）。
 */
#define CONSOLE_BUF_ADDR ((volatile char *)0x2800)

static int console_index;

void console_putc(char c)
{
    CONSOLE_BUF_ADDR[console_index++] = c;
}
