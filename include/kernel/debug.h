
#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include <kernel/console.h>
#include <vargs.h>
#include <elf.h>

// 初始化 Debug 信息
void init_debug(void);

// 打印当前的段存器值
void print_cur_status(void);

// Dump the current stack trace.
void print_stack_trace(void);

// Dump the current stack trace with color.
void print_stack_trace_color(real_color_t back, real_color_t fore);

#endif  // INCLUDE_DEBUG_H_
