
/*
 * stdlib.h : The standard header file.
 *
 * This header file defines the base functions
 * such as sprintf, vsprintf, etc.
 */

#ifndef __INCLUDE_STDLIB_H
#define __INCLUDE_STDLIB_H

#include "types.h"
#include "vargs.h"

void sprintf(char *buf, const char *fmt, ...);
void vsprintf(char *buf, const char *fmt, va_list vargs);
char* itoa(int value, char *str, int radix);
char* uitoa(uint32_t value, char *str, int radix);
char* gcvt(double value, int ndigit, char *buf);

#endif
