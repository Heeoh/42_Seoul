#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    char    *p;

    p = s;
    while (p && *p)
    {
        f(p - s, p);
        p++;
    }
}