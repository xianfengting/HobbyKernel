
/*
 * panic.h : Defines the functions used when the kernel crashes.
 */

#ifndef __INCLUDE_PANIC_H
#define __INCLUDE_PANIC_H

// Halt the kernel with a message.
void panic(const char *msg);

// Halt the kernel with no message.
void panic_without_message(void);

#endif
