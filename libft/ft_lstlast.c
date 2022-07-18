#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *p;

    p = lst;
    if (!p)
        return (NULL);
    while (p->next)
        p = p->next;
    return (p);
}
