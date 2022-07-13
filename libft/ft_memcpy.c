#include <stdlib.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *p = (unsigned char*)dst;
    while (n-- && *((unsigned const char*)src))
    {
        *p++ = *((unsigned const char*)src);
        src++;
    }

    return (dst);
}