int ft_isdigit(int c)
{
    if ('0' <= c && c <= '9') 
        return (1);
    else
        return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char str[10] = "01234abcd";
//     for (int i=0; i < 10; i++) {
//         printf("ans: %d\t", isdigit(str[i]));
//         printf("ft: %d\n", ft_isdigit(str[i]));
//     }
// }
