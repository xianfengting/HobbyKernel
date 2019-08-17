
/*
 * panic.c : Implemention of kernel/panic.h
 */

#include <kernel/kernel.h>
#include <kernel/debug.h>
#include <kernel/panic.h>

/*
static void print_panic_message(const char *msg)
{
    printk_color(rc_black, rc_red, msg);
}
*/
#define print_panic_message(msg, ...) printk_color(rc_black, rc_red, msg, ##__VA_ARGS__)

void panic(const char *msg)
{
    print_panic_message("*** System panic ***\n");
    print_panic_message("Sorry, a fatal error occurred in the system kernel and the system crashed.\n"
            "Please record the panic information and turn off your computer.\n"
            "If the panic happened again, please report it to the author.\n");
    print_panic_message("********************\n");
    print_panic_message("Panic message:\n");
    print_panic_message("%s\n", msg);
    print_panic_message("Stacktrace:\n");
    print_stack_trace_color(rc_black, rc_red);
    print_panic_message("Registers' values:\n");
    //print_panic_message();
    print_cur_status_color(rc_black, rc_red);
    print_panic_message("********************\n");

    // Halt the kernel by a loop.
    while (1)
        __asm__ volatile("hlt"); // Halt the CPU.
}

void panic_without_message(void)
{
    panic("No message provided.");
}
