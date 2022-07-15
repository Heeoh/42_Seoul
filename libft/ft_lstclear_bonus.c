#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *next;
    t_list  *p;

    p = *lst;
    while (p)
    {
        next = p->next;
        ft_lstdelone(p, del);
        p = next;
    }
    *lst = NULL;
}