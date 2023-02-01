/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:34:11 by heson             #+#    #+#             */
/*   Updated: 2023/02/01 19:27:08 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
#include <stdlib.h>  // malloc

void swap(t_stack *stk)
{
    int top1;
    int top2;

    if (get_stk_size(*stk) < 2)
        return ;
    top1 = get_top(*stk);
    pop_top(stk);
    top2 = get_top(*stk);
    pop_top(stk);
    push_top(stk, top1);
    push_top(stk, top2);
}

void push(t_stack *from_stk, t_stack *to_stk)
{
    if (isEmpty(*from_stk))
        return ;
    push_top(to_stk, get_top(*from_stk));
    pop_top(from_stk);
}

void rotate(t_stack *stk)
{
    int *tmp;
    int i;

     if (get_stk_size(*stk) < 2)
        return ;
    tmp = (int *)malloc(sizeof(int) * stk->top);
    i = 0;
    while (!isEmpty(*stk))
    {
        tmp[i++] = get_top(*stk);
        pop_top(stk);
    }
    push_top(stk, tmp[0]);
    while (--i > 0)
        push_top(stk, tmp[i]);
}

void reverse(t_stack *stk)
{
    int *tmp;
    int i;
    int prev_top;

    if (get_stk_size(*stk) < 2)
        return ;
    tmp = (int *)malloc(sizeof(int) * stk->top);
    i = 0;
    while (!isEmpty(*stk))
    {
        tmp[i++] = get_top(*stk);
        pop_top(stk);
    }
    prev_top = tmp[--i];
    while (i--)
        push_top(stk, tmp[i]);
    push_top(stk, prev_top);
}