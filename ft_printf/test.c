#include <stdio.h>
#include <stdarg.h>
// #include <stdlib.h>
#include <unistd.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);


void print_format(char *p, va_list ap) {
    write(1, p, 1);
    write(1, " ", 1);
    if (*p == 'd')
        printf("%d\n", va_arg(ap, int));
    else if (*p == 'c') {
        char c = va_arg(ap, int);
        write(1, &c, 1);
        write(1, "\n", 1);
    }
    else if (*p == 's') {
        char *s = va_arg(ap, char*);
        while (*s)
            write(1, s++, 1);
        write(1, "\n", 1);
    }
    else if (*p == 'p') {
        long address = va_arg(ap, long);
        printf("0x%lx\n", address);
    }
}

void my_print(char *str, ...) {
    va_list ap;
    char *p = str;

    va_start(ap, str);
    while (*p) {
        print_format(p, ap);
        p++;
    }
}

int main()
{
    int num = 10;
    // my_print("cdsp", 'a', 10, "hello", &num);
    // printf("%p\n", &num);

    printf("|%.1d|", num);

    return 0;
}
