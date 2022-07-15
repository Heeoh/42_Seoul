#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *new_node;
    t_list  *p;
    t_list  *new_p;

    p = lst;
    new_list = NULL;
    new_p = new_list;
    while (p)
    {
        new_node = ft_lstnew("");
        if (!new_node)
            ft_lstclear(&new_list, del);
        new_node = f(p);
        if (!new_p)
            new_list = new_node;
        else
            new_p->next = new_node;
        new_p = new_node;
        p = p->next;
    }
    return (new_list);
}