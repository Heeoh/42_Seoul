#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t      s_len;
    const char  *p;
    char        *res;
    char        *res_p;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (s_len < start + len)
    {
        if (s_len > start)
            res = (char *)malloc(s_len - start + 1);
        else
            res = (char *)malloc(1);
    }
    else
        res = (char *)malloc(len + 1);
    if (!res)
        return (NULL);
    res_p = res;
    if (start < s_len)
    {
        p = s + start;
        while (len-- && *p)
            *res_p++ = *p++;
    }
    *res_p = '\0';
    return (res);
}