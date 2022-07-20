/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:26:45 by heson             #+#    #+#             */
/*   Updated: 2022/07/20 18:26:47 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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