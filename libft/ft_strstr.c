char *ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
    unsigned int i;

    if (!*needle)
        return ((char *)haystack);
    i = 0;
    while (i < len && haystack[i] && *needle) {
        if (haystack[i] == *needle)
        {
            unsigned int tmp_i = i;
            const char *tmp2 = needle;
            while (tmp_i < len && haystack[tmp_i] && *tmp2 && haystack[tmp_i] == *tmp2)
            {
                tmp_i++;
                tmp2++;
            }
            if (!*tmp2) 
                return (&((char *)haystack)[i]);
        }
        i++;
    }
    return (0);
}

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello world!!";
    char str2[] = "hellohello";
    char substr[] = "hello";

    printf("res: %s\n", strnstr(str1, substr, 3));
    printf("ft:  %s\n", ft_strnstr(str1, substr, 3));
    printf("res: %s\n", strnstr(str2, substr, 3));
    printf("ft:  %s\n", ft_strnstr(str2, substr, 3));
}

