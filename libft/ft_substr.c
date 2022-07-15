#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	cnt;

// 	cnt = 0;
// 	while (*s++)
// 		cnt++;
// 	return (cnt);
// }


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
        res = (char *)malloc(s_len - start + 1);
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

// #include <stdio.h>

// int main() {
//     printf("%s\n", ft_substr("hellohello", 30, 5));
// }

// // #include <stdio.h>

// // int main() {
// //     char *s = ft_substr("tripouille", 100, 1);
// //     printf("%s\n", s);
// // 	// /* 5 */ check(!strcmp(s, ""));
// // 	// /* 6 */ mcheck(s, 1); free(s); showLeaks();
// // }