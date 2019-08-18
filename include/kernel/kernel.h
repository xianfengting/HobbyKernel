
/*
 * kernel.h : The main kernel header file.
 */

#ifndef __INCLUDE_KERNEL_H
#define __INCLUDE_KERNEL_H

#include <kernel/console.h>

void printk(const char *fmt, ...);
void printk_color(real_color_t back, real_color_t fore, const char *format, ...);
void panic(const char *message);
long double get_kernel_uptime(void);
uint64_t get_kernel_uptime_milli(void);

#endif
