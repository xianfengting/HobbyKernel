
#include <types.h>
#include <kernel/console.h>
#include <kernel/kernel.h>
#include <kernel/debug.h>
#include <kernel/panic.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/pmm.h>

static void output_char(char c, uint8_t **input_ptr)
{
    //uint8_t *input = (uint8_t) 0xB8000;
    uint8_t *input = *input_ptr;
    uint8_t color = (0 << 4) | (15 & 0x0F);
    *input++ = c;
    *input++ = color;
    *input_ptr = input;
}

int start_kernel(void)
{
    console_clear();
    init_debug();
    init_gdt();
    init_idt();

    /*
    uint8_t *input = (uint8_t *)0xB8000;
    uint8_t color = (0 << 4) | (15 & 0x0F);

    *input++ = 'H'; *input++ = color;
    *input++ = 'e'; *input++ = color;
    *input++ = 'l'; *input++ = color;
    *input++ = 'l'; *input++ = color;
    *input++ = 'o'; *input++ = color;
    *input++ = ','; *input++ = color;
    *input++ = ' '; *input++ = color;
    *input++ = 'O'; *input++ = color;
    *input++ = 'S'; *input++ = color;
    *input++ = ' '; *input++ = color;
    *input++ = 'K'; *input++ = color;
    *input++ = 'e'; *input++ = color;
    *input++ = 'r'; *input++ = color;
    *input++ = 'n'; *input++ = color;
    *input++ = 'e'; *input++ = color;
    *input++ = 'l'; *input++ = color;
    *input++ = '!'; *input++ = color;
    */

    /*
    uint8_t *input = (uint8_t *)0xB8000;

    output_char('w', &input);
    output_char('o', &input);
    output_char(' ', &input);
    output_char('d', &input);
    output_char('e', &input);
    output_char(' ', &input);
    output_char('d', &input);
    output_char('i', &input);
    output_char(' ', &input);
    output_char('y', &input);
    output_char('i', &input);
    output_char(' ', &input);
    output_char('g', &input);
    output_char('e', &input);
    output_char(' ', &input);
    output_char('c', &input);
    output_char('a', &input);
    output_char('o', &input);
    output_char(' ', &input);
    output_char('z', &input);
    output_char('u', &input);
    output_char('o', &input);
    output_char(' ', &input);
    output_char('x', &input);
    output_char('i', &input);
    output_char(' ', &input);
    output_char('t', &input);
    output_char('o', &input);
    output_char('n', &input);
    output_char('g', &input);
    output_char(' ', &input);
    output_char('n', &input);
    output_char('e', &input);
    output_char('i', &input);
    output_char(' ', &input);
    output_char('h', &input);
    output_char('e', &input);
    */

    //console_write_color("zhe shi wo de di yi ge cao zuo xi tong nei he!!!\n", rc_black, rc_green);
    //console_write_color("mima lianxi qq 123456789!\n", rc_black, rc_red);

    //int n = strlen("abcdefg");
    //int a = strcmp("abcdefg", "bbcdefg");

    //printk("n=%d\n", n);
    //printk("a=%d\n", a);
    //printk("The char is %c\n", 'c');

    //__asm__ volatile ("int $0x3");
    //__asm__ volatile ("int $0x4");

    init_timer(1000);

    // 开启中断
    __asm__ volatile ("sti");

    printk_log_info("kernel in memory start: 0x%08X", kernel_start);
    printk_log_info("kernel in memory end:   0x%08X", kernel_end);
    printk_log_info("kernel in memory used:   %d KB\n", (kernel_end - kernel_start + 1023) / 1024);

    show_memory_map();

    //uint64_t b = get_kernel_uptime_milli();
    //printk("b=%llu\n", b);
    //printk_log_debug("b=%llu", b);

    //panic_without_message();

    return 0;
}

