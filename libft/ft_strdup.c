#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    char *res;
    unsigned int i;
    unsigned int size;

    size = ft_strlen(s1);
    res = (char *)malloc(size + 1);
    if (!res)
        return (NULL);
    i = 0;
    while (((char *)s1)[i])
    {
        res[i] = s1[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

#include <stdio.h>
#include <string.h>

int main(int ac, char *av[]) {
    if (ac != 2)
        return 0;
    
    char *str1 = strdup(av[1]);
    char *str2 = ft_strdup(av[1]);

    printf("res: %s, %lu\n", str1, strlen(str1));
    printf("ft:  %s, %lu\n", str2, strlen(str2));


}