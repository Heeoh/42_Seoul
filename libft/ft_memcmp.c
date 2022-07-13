int ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
    unsigned int i;
    const char *p1 = s1;
    const char *p2 = s2;

    if (!p1[0] && !p2[0])
        return (0);
    i = 0;
    while (i < n)
    {
        if (p1[i] != p2[i])
            return (p1[i] - p2[i]);
        i++;
    }
    return (0);
}

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello\0world";
    char str2[] = "hello\0sorld";

    printf("res: %d, ", memcmp(str1, str2, 20));
    printf("ft: %d\n", ft_memcmp(str1, str2, 20));
    printf("res: %d, ", memcmp(str1, str2, 5));
    printf("ft: %d\n", ft_memcmp(str1, str2, 5));
}