/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:30:12 by heson             #+#    #+#             */
/*   Updated: 2023/01/30 16:03:45 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/operations.h"
#include <stdio.h> // printf

void    sa(t_stack *stk)
{
    printf("sa\n");
    swap(stk);
}

void    sb(t_stack *stk)
{
    printf("sb\n");
    swap(stk);
}

void    ss(t_stack *stk_a, t_stack *stk_b)
{
    printf("ss\n");
    swap(stk_a);
    swap(stk_b);
}

void    pa(t_stack *stk_a, t_stack *stk_b)
{
    printf("pa\n");
    push(stk_b, stk_a);
}

void    pb(t_stack *stk_a, t_stack *stk_b)
{
    printf("pb\n");
    push(stk_a, stk_b);
}

void    ra(t_stack *stk)
{
    printf("ra\n");
    rotate(stk);
}

void    rb(t_stack *stk)
{
    printf("rb\n");
    rotate(stk);
}

void    rr(t_stack *stk_a, t_stack *stk_b)
{
    printf("rr\n");
    rotate(stk_a);
    rotate(stk_b);
}

void    rra(t_stack *stk)
{
    printf("rra\n");
    reverse(stk);
}

void    rrb(t_stack *stk)
{
    printf("rrb\n");
    reverse(stk);
}

void    rrr(t_stack *stk_a, t_stack *stk_b)
{
    printf("rrr\n");
    reverse(stk_a);
    reverse(stk_b);
}
