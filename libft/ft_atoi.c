int ft_atoi(const char *str)
{
    char            *p;
    int             sign;
    unsigned int    absolute_num; 

    p = (char *)str;
    sign = 1;
    while (*p && *p == ' ')
        p++;
    if (*p == '-' || *p == '+')
    {
        if (*p == '-')
        sign = -1;
        p++;
    }
    absolute_num = 0;
    while (*p && '0' <= *p && *p <= '9')
    {
        absolute_num = absolute_num * 10 + (*p - '0');
        p++;
    }
    return (absolute_num * sign);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char* av[]) {
    if (ac == 1) return 0;
    for (int i=1; i<ac; i++) {
        printf("res: %d, ft: %d\n", atoi(av[i]), ft_atoi(av[i]));
    }
    // printf("res: %d, ft: %d\n", atoi("123abc"), ft_atoi("123abc"));
}