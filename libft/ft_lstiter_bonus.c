#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *p;

    p = lst;
    while (p)
    {
        f(p);
        p = p->next;
    }
}