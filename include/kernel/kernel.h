
/*
 * kernel.h : The main kernel header file.
 */

#ifndef __INCLUDE_KERNEL_H
#define __INCLUDE_KERNEL_H

#include <kernel/console.h>

#define printk_log_debug(fmt, ...) printk_color(rc_black, rc_light_grey,\
        "[%llu] %s DEBUG: " fmt "\n", get_kernel_uptime_milli(), __func__, ##__VA_ARGS__ )
#define printk_log_info(fmt, ...) printk("[%llu] %s INFO: " fmt "\n", get_kernel_uptime_milli(), __func__, ##__VA_ARGS__ )

void printk(const char *fmt, ...);
void printk_color(real_color_t back, real_color_t fore, const char *format, ...);
void panic(const char *message);
long double get_kernel_uptime(void);
uint64_t get_kernel_uptime_milli(void);

#endif
