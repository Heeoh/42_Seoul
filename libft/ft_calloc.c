#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    char            *res;
    unsigned int    arr_size;
    char            *p;

    arr_size = count * size;
    res = (char *)malloc(arr_size);
    if (!res)
    {
        free(res);
        return (NULL);
    }
    p = res;
    while (arr_size--)
        *p++ = 0;
    return (res);
}

#include <stdio.h>

int main(int ac, char *av[]) {
    if (ac != 3)
        return 0;
    int *arr1, *arr2;
    arr1 = calloc(atoi(av[1]), atoi(av[2]));
    arr2 = ft_calloc(atoi(av[1]), atoi(av[2]));
    // int cnt = atoi(av[1]) * atoi(av[2]);
    printf("res: ");
    (!arr1) ? printf("NULL, ") : printf("success, ");

    printf("\nft: ");
    (!arr2) ? printf("NULL, ") : printf("success, ");
    arr2 = realloc(arr2, 5);
    if (!arr2)
        printf("error\n");


    
}