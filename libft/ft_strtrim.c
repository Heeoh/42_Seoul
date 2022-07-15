#include "libft.h"

int is_set(char c, const char *set)
{
    while (*set)
    {
        if (*set++ == c)
            return (1);
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char        *res;
    const char  *p;
    const char  *end_p;
    char        *res_p;

    p = s1 + ft_strlen(s1) - 1;
    while (p >= s1 && is_set(*p, set))
        p--;
    end_p = p + 1;
    p = s1;
    while (p < end_p && is_set(*p, set))
        p++;
    res = (char *)malloc(end_p - p + 1);
    if (!res)
        return (NULL);
    res_p = res;
    while (p < end_p)
        *res_p++ = *p++;
    *res_p = '\0';
    return (res);
}

// s1 전체가 set에 해당될 경우 null string이 출력됨