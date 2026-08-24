/* COREX 最小标准库头文件（裸机，无 newlib）
 *
 * 仅声明本项目自实现的最小 printf。用法与标准 stdio.h 一致：
 *   #include <stdio.h>
 */
#ifndef COREX_STDIO_H
#define COREX_STDIO_H

int printf(const char *fmt, ...);

#endif
