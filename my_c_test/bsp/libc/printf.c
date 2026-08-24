/* COREX 最小 printf（裸机，-nostdlib 无 newlib）
 *
 * 支持格式：%d %i %u %x %X %c %s %%
 * 用 gcc 内建变参（__builtin_va_*），不依赖 stdarg.h。
 * 输出逐字符经 console_putc 写到 DMem 缓冲。
 * 无输出字符返回 0。
 */

void console_putc(char c);

/* 无符号十进制（含 0 的情况） */
static void print_uint(unsigned int v)
{
    char buf[12];
    int i = 0;
    if (v == 0) {
        console_putc('0');
        return;
    }
    while (v > 0) {
        buf[i++] = (char)('0' + (v % 10));
        v /= 10;
    }
    while (i > 0) {
        console_putc(buf[--i]);
    }
}

/* 无符号十六进制（小写，无前导零，0 输出 "0"） */
static void print_hex(unsigned int v)
{
    static const char hex[] = "0123456789abcdef";
    int started = 0;
    for (int s = 28; s >= 0; s -= 4) {
        int d = (int)((v >> s) & 0xf);
        if (d != 0 || started || s == 0) {
            console_putc(hex[d]);
            started = 1;
        }
    }
}

/* 有符号十进制 */
static void print_int(int v)
{
    if (v < 0) {
        console_putc('-');
        print_uint((unsigned int)(-v));
    } else {
        print_uint((unsigned int)v);
    }
}

int printf(const char *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);

    while (*fmt) {
        if (*fmt != '%') {
            console_putc(*fmt++);
            continue;
        }
        fmt++; /* 跳过 % */
        switch (*fmt) {
            case 'd':
            case 'i':
                print_int((int)__builtin_va_arg(ap, unsigned int));
                break;
            case 'u':
                print_uint(__builtin_va_arg(ap, unsigned int));
                break;
            case 'x':
            case 'X':
                print_hex(__builtin_va_arg(ap, unsigned int));
                break;
            case 'c':
                console_putc((char)__builtin_va_arg(ap, unsigned int));
                break;
            case 's': {
                const char *s = (const char *)__builtin_va_arg(ap, unsigned int);
                while (*s) {
                    console_putc(*s++);
                }
                break;
            }
            case '%':
                console_putc('%');
                break;
            default:
                console_putc('%');
                console_putc(*fmt);
                break;
        }
        fmt++;
    }

    __builtin_va_end(ap);
    return 0;
}
