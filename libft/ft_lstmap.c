/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:30:22 by heson             #+#    #+#             */
/*   Updated: 2022/07/20 18:32:39 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *new_node;
    t_list  *p;
    t_list  *new_p;

    new_list = NULL;
    if (!lst)
        return (new_list);
    p = lst;
    while (p)
    {
        new_node = ft_lstnew(f(p->content));
        if (!new_node) 
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        if (!new_list)
            new_list = new_node;
        else
            new_p->next = new_node;
        new_p = new_node;
        p = p->next; 
    }
    return (new_list);
}

// #include <stdio.h>
// #include <string.h>

// void *map_length(void *s)
// {   
//     char *str = malloc(10);
//     if (str != NULL) 
//         sprintf(str, "__%lX", strlen((char *)s));
//     return str;
// }

// void delete(void *content)
// {   
//     char *str = (char *)content;
//     if (str == NULL)
//         return;
//     if (str[0] != '_' || str[1] != '_')
//         printf("error\n");
//     free(content);
// }


// int main() {
//     t_list *list = NULL;
//     char *data[] = {"one", "two", "three", "four", "five"};
//     t_list *pre;
//     for (int i=0; i<5; i++) {
//         t_list *new_node = (t_list*)malloc(sizeof(t_list));
//         new_node->content = data[i];
//         new_node->next = NULL;
//         if (!list) {
//             list = new_node;
//             pre = list;
//         }
//         else {
//             pre->next = new_node;
//             pre = new_node;
//         }
//     }
//     // t_list *p = list;
//     // while (p)
//     // {
//     //     printf("%s\n", (char *)(p->content));
//     //     p = p->next;
//     // }

//     t_list *l = ft_lstmap(list, map_length, delete);
//     t_list *p = l;
//     while (p)
//     {
//         printf("%s\n", (char *)(p->content));
//         p = p->next;
//     }
// }