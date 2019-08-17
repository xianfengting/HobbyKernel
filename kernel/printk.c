
/*
 * printk.c : implemention of printk() in kernel/kernel.h
 */

#include <stdlib.h>
#include <kernel/console.h>
#include <string.h>
#include <kernel/kernel.h>

void printk(const char *fmt, ...)
{
    char buf[256];
    va_list args;

    memset(buf, 0, sizeof(buf));
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    console_write(buf);
}

void printk_color(real_color_t back, real_color_t fore, const char *fmt, ...)
{
    char buf[256];
    va_list args;

    memset(buf, 0, sizeof(buf));
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    console_write_color(buf, back, fore);
}
