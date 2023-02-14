/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:30:11 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 19:37:40 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

#include "../headers/stack.h"
#include "../headers/operations.h"
#include "../headers/push_swap.h"

void    sort_3top_a(t_stack *stk_a, t_stack *stk_b, int bottom, int top);
void	relocation_a(t_stack *stk_a, t_stack *stk_b, int s, int e);
void	partition_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
void    sort_3top_b(t_stack *stk_a, t_stack *stk_b, int bottom, int top);
void	relocation_b(t_stack *stk_a, t_stack *stk_b, int s, int e);
void	partition_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);


#endif