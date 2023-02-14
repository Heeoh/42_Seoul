/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:29:19 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 01:41:27 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

typedef enum e_op
{
    SA = 0,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR,
    OP_CNT
} t_op;

void    do_operation(t_op op, t_stack *stk_a, t_stack *stk_b);
void    swap(t_stack *stk);
void    push(t_stack *from_stk, t_stack *to_stk);
void    rotate(t_stack *stk);
void    reverse(t_stack *stk);

#endif