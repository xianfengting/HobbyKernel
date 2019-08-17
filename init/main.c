
#include <types.h>
#include <kernel/console.h>
#include <kernel/kernel.h>
#include <kernel/debug.h>
#include <kernel/panic.h>
#include <kernel/gdt.h>

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
    init_debug();
    init_gdt();

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

    console_clear();

    console_write_color("zhe shi wo de di yi ge cao zuo xi tong nei he!!!\n", rc_black, rc_green);
    //console_write_color("mima lianxi qq 123456789!\n", rc_black, rc_red);

    int n = strlen("abcdefg");
    int a = strcmp("abcdefg", "bbcdefg");

    printk("n=%d\n", n);
    printk("a=%d\n", a);
    printk("The char is %c\n", 'c');

    panic_without_message();

    return 0;
}

