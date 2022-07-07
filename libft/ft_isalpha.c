int ft_isalpha(char c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) 
        return (1);
    else
        return (0);
}