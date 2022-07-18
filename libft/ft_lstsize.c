#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int     cnt;
    t_list  *p;

    cnt = 0;
    p = lst;
    while (p)
    {
        cnt++;
        p = p->next;
    }
    return (cnt);
}