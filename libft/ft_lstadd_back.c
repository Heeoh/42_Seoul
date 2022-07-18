#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *pre;

    pre = ft_lstlast(*lst);
    if (!pre)
    {
        *lst = new;
        return ;
    }
    pre->next = new;
    return ;
}