/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by heson             #+#    #+#             */
/*   Updated: 2022/07/20 18:27:19 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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