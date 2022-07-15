#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char            res[10];
    unsigned int    i;
    int             write_n;

    if (n == 0)
        write(fd, "0", 1);
    if (n < 0)
        write(fd, "-", 1);
    i = 0;
    while (n != 0)
    {
        write_n = n % 10;
        if (write_n < 0) 
            write_n = -write_n;
        res[i++] = write_n + '0';
        n /= 10;
    }
    while (i--)
        write(fd, &res[i], 1);
}