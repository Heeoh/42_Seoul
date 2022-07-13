#include <stdlib.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *p = (unsigned char*)dst;
    unsigned char buf[len];
    unsigned int cnt = 0;

    while (cnt < len && *(const unsigned char*)src)
    {
        buf[cnt++] = *(const unsigned char*)src;
        src++;
    }
    p += cnt - 1;
    while (cnt--)
        *(p--) = buf[cnt];

    return (dst);
}