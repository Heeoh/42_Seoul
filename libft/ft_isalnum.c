int ft_isalnum(int c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) 
        return (1);
    else if ('0' <= c && c <= '9')
        return (1);
    else
        return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char str[50] = "0129AaZzm * ";
//     for (int i=0; str[i] != '\0'; i++) {
//         printf("%c\t", str[i]);
//         printf("ans: %d\t", isalnum(str[i]));
//         printf("ft: %d\n", ft_isalnum(str[i]));
//     }
// }