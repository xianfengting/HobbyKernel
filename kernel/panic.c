
/*
 * panic.c : Implemention of kernel/panic.h
 */

#include <kernel/debug.h>
#include <kernel/panic.h>

void panic(const char *msg)
{
    printk("*** System panic: %s\n", msg);
    print_stack_trace();
    printk("***\n");

    // Halt the kernel by a loop.
    while(1);
}

void panic_without_message(void)
{
    panic("No message provided.");
}
