
/*
 * panic.c : Implemention of kernel/panic.h
 */

#include <kernel/kernel.h>
#include <kernel/debug.h>
#include <kernel/panic.h>

void panic(const char *msg)
{
    printk("*** System panic ***\n");
    printk("Sorry, a fatal error occurred in the system kernel and the system crashed.\n"
           "Please record the panic information and turn off your computer.\n"
           "If the panic happened again, please report it to the author.\n");
    printk("********************\n");
    printk("Panic message:\n");
    printk("%s\n", msg);
    printk("Stacktrace:\n");
    print_stack_trace();
    printk("Registers' values:\n");
    print_cur_status();
    printk("********************\n");

    // Halt the kernel by a loop.
    while(1);
}

void panic_without_message(void)
{
    panic("No message provided.");
}
