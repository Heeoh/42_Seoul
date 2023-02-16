/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:30:11 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 01:35:26 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "../headers/stack.h"
# include "../headers/operations.h"
# include "../headers/push_swap.h"

void	sort_less_5nums(t_two_stks *stk, int *sorted);
void	sort_2nums(t_two_stks *stk, int top);
void	sort_3nums(t_two_stks *stk, int bottom, int top);

void	a_to_b(t_two_stks *stk, int s, int e, int *sorted);
void	sort_3top_a(t_two_stks *stk, int bottom, int top);
void	relocation_a(t_two_stks *stk, int m_size, int l_size);
void	partition_a(t_two_stks *stk, int s, int e, int *sorted);

void	b_to_a(t_two_stks *stk, int s, int e, int *sorted);
void	sort_3top_b(t_two_stks *stk, int bottom, int top);
void	relocation_b(t_two_stks *stk, int s_size, int m_size);
int		partition_b(t_two_stks *stk, int s, int e, int *sorted);

#endif