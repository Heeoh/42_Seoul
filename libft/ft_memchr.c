void *ft_memchr(const void *s, int c, unsigned int n)
{
    char *p = (char *)s;

    while (p - (char*)s < n)
    {
        if (*p == c)
            return (p);
        if (!*p)
            return (0);
        p++;
    }
    return (0);
}