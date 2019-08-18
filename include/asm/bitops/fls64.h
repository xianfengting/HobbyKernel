
#ifndef __INCLUDE_ASM_BITOPS_FLS64_H
#define __INCLUDE_ASM_BITOPS_FLS64_H

/**
 * __fls - find last (most-significant) set bit in a long word
 * @word: the word to search
 *
 * Undefined if no set bit exists, so code should check against 0 first.
 */
static inline unsigned long __fls(unsigned long word)
{
	return (sizeof(word) * 8) - 1 - __builtin_clzl(word);
}

static inline int fls64(unsigned long long x)
{
	if (x == 0)
		return 0;
	return __fls(x) + 1;
}

#endif
