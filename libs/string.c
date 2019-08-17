
#include "string.h"

void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
    for (; len != 0; len--)
        *dest++ = *src;
}

void memset(void *dest, uint8_t val, uint32_t len)
{
    uint8_t *dest1 = (uint8_t *) dest;
    for (; len != 0; len--)
        *dest1 = val;
}

void bzero(void *dest, uint32_t len)
{
    memset(dest, 0, len);
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1) {
        char c1 = *str1++;
        char c2 = *str2++;
        if (c1 > c2)
            return 1;
        else if (c1 < c2)
            return -1;
    }
    return 0;
}

char *strcpy(char *dest, const char *src)
{
    memcpy(dest, src, strlen(src));
    return dest;
}

char *strcat(char *dest, const char *src)
{
    int last = strlen(dest);
    int last2 = last + strlen(src);
    for (int i = last; i < last2; i++) {
        dest[i] = src[i - last];
    }
    dest[last2] = '\0';
    return dest;
}

int strlen(const char *src)
{
    int n = 0;
    while (*src) {
        n++;
        src++;
    }
    return n;
}
