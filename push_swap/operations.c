/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:30:12 by heson             #+#    #+#             */
/*   Updated: 2023/01/29 20:35:05 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/operations.h"

void    do_operation(t_op op, t_stack *stk_a, t_stack *stk_b)
{
    if (op == SA)
        swap(stk_a);
    else if (op == SB)
        swap(stk_b);
    else if (op == SS)
    {
        swap(stk_a);
        swap(stk_b);
    }
    else if (op == PA)
        push(stk_b, stk_a);
    else if (op == PB)
        push(stk_a, stk_b);
    else if (op == RA)
        rotate(stk_a);
    else if (op == RB)
        rotate(stk_b);
    else if (op == RR)
    {
        rotate(stk_a);
        rotate(stk_b);
    }
    else if (op == RRA)
        reverse(stk_a);
    else if (op == RRB)
        reverse(stk_b);
    else if (op == RR)
    {
        reverse(stk_a);
        reverse(stk_b);
    }
}