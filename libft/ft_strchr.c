char *ft_strchr(const char *s, int c)
{
    char *p = (char *)s;
    while (1)
    {
        if (*p == c)
            return (p);
        if (!*p)
            return (0);
        p++;
    }
}