
#ifndef INCLUDE_PMM_H
#define INCLUDE_PMM_H

#include "multiboot.h"

// 内核文件在内存中的起始和结束位置
// 在链接器脚本中要求链接器定义
extern uint8_t kernel_start[];
extern uint8_t kernel_end[];

// 输出 BIOS 提供的物理内存布局
void show_memory_map(void);

#endif  // INCLUDE_PMM_H
