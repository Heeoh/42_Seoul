#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *res;
    unsigned int    i;
    unsigned int    len;

    len = ft_strlen(s);
    res = (char *)malloc(len + 1);
    if (!res)
        return (NULL);
    i = 0;
    while (i < len)
    {
        res[i] = f(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}