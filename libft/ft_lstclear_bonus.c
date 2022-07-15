#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *del_node;
    t_list  *p;

    p = *lst;
    while (p)
    {
        del_node = p;
        p = p->next;
        ft_lstdelone(del_node, del);
    }
    *lst = NULL;
}