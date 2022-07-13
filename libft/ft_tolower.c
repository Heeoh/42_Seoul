int ft_toupper(int c)
{
    if ('A' <= c && c <= 'Z')
        return (c + ('a' - 'A'));
    return (c);
}