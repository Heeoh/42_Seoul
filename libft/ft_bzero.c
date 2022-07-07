void *ft_bzero(void *b, unsigned int len)
{
    char *p = b;
    int cnt = len / sizeof(b[0]);

    while (cnt--)
        *p++ = 0;

    return (b);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr1[10] = "hello";
    char arr2[10] = "hello";
    // int arr1[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // int arr2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    bzero(arr1, 3*sizeof(arr1[0]));
    ft_bzero(arr2, 3*sizeof(arr2[0]));

    printf("ans: %s\t", arr1);
    printf("ft:  %s\n", arr2);
    // for (int i=0; i<10; i++) {
    //     printf("%d ", arr1[i]);
    //     printf("%d\n", arr2[i]);       
    // }
}