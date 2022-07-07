void *ft_memset(void *b, int c, unsigned int len)
{
    char *p = b;
    int cnt = len / sizeof(b[0]);

    while (cnt--)
        *p++ = c;

    return (b);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     int arr1[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     int arr2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//     memset(arr1, 0, 3*sizeof(int));
//     ft_memset(arr2, 0, 3*sizeof(int));

//     // printf("ans: %s\t", arr1);
//     // printf("ft:  %s\n", arr2);
//     for (int i=0; i<10; i++) {
//         printf("%d ", arr1[i]);
//         printf("%d\n", arr2[i]);       
//     }
// }