char *ft_strrchr(const char *s, int c)
{
    char *p = (char *)s + ft_strlen(s);
    while (1)
    {
        if (*p == c)
            return (p);
        if (*p == *s)
            return (0);
        p--;
    }
}