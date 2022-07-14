#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    const char  *p;
    char        *res;
    char        *res_p;

    // if (!*s)
    //     return (NULL);
    res = (char *)malloc(len + 1);
    if (!res)
        return (NULL);
    res_p = res;
    p = s + start;
    while (len-- && *p)
        *res_p++ = *p++;
    *res_p = '\0';
    return (res);
}