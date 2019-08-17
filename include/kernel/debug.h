
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

#endif  // INCLUDE_DEBUG_H_
