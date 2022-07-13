#include <stdlib.h>

void *ft_bzero(void *b, size_t len)
{
    unsigned char *p = b;

    while (len--)
        *p++ = 0;

    return (b);
}