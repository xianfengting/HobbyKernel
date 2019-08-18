
/*
 * debug.c : Implemention of kernel/debug.h
 */

#include <elf.h>
#include <kernel/kernel.h>
#include <kernel/debug.h>

static elf_t kernel_elf;

void init_debug(void)
{
    printk_log_info("Loading kernel ELF information from multiboot");
    // 从 GRUB 提供的信息中获取到内核符号表和代码地址信息
    kernel_elf = elf_from_multiboot(glb_mboot_ptr);
}

void print_cur_status(void)
{
    print_cur_status_color(rc_black, rc_white);
}

void print_cur_status_color(real_color_t back, real_color_t fore)
{
    static int round = 0;
    uint16_t reg1, reg2, reg3, reg4;

    asm volatile (  "mov %%cs, %0;"
            "mov %%ds, %1;"
            "mov %%es, %2;"
            "mov %%ss, %3;"
            : "=m"(reg1), "=m"(reg2), "=m"(reg3), "=m"(reg4));

    // 打印当前的运行级别
#define front_args back, fore
    printk_color(front_args, "%d: @ring %d\n", round, reg1 & 0x3);
    printk_color(front_args, "%d:  cs = %x\n", round, reg1);
    printk_color(front_args, "%d:  ds = %x\n", round, reg2);
    printk_color(front_args, "%d:  es = %x\n", round, reg3);
    printk_color(front_args, "%d:  ss = %x\n", round, reg4);
#undef front_args
    ++round;
}

void print_stack_trace(void)
{
    print_stack_trace_color(rc_black, rc_white);
}

void print_stack_trace_color(real_color_t back, real_color_t fore)
{
    uint32_t *ebp, *eip;

    asm volatile ("mov %%ebp, %0" : "=r" (ebp));
    while (ebp) {
        eip = ebp + 1;
        printk_color(back, fore, "   [0x%x] %s\n", *eip, elf_lookup_symbol(*eip, &kernel_elf));
        ebp = (uint32_t*)*ebp;
    }
}
