/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:17:35 by heson             #+#    #+#             */
/*   Updated: 2023/02/13 16:18:01 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../headers/stack.h"
// #include "../headers/operations.h"
// #include "../headers/push_swap.h"

// void	sort_2nums(t_stack *stk_a, t_stack *stk_b, int top)
// {
// 	if (get_top(*stk_a) != top)
// 		do_operation(SA, stk_a, stk_b);
// }

// void	sort_3nums(t_stack *stk_a, t_stack *stk_b, int bottom, int top)
// {

// 	if (stk_a->memory[stk_a->top - 2] == bottom && get_top(*stk_a) == top)
// 		return ;
// 	else if (stk_a->memory[stk_a->top - 2] == bottom && get_top(*stk_a) != top)
// 		do_operation(SA, stk_a, stk_b);
// 	else if (stk_a->memory[stk_a->top - 2] == top && get_top(*stk_a) == bottom)
// 	{
// 		do_operation(SA, stk_a, stk_b);
// 		do_operation(RRA, stk_a, stk_b);
// 	}
// 	else if (stk_a->memory[stk_a->top - 2] == top && get_top(*stk_a) != bottom)
// 		do_operation(RRA, stk_a, stk_b);
// 	else if (get_top(*stk_a) == bottom)
// 		do_operation(RA, stk_a, stk_b);
// 	else if (get_top(*stk_a) == top)
// 	{
// 		do_operation(SA, stk_a, stk_b);
// 		do_operation(RA, stk_a, stk_b);
// 	}
// }

// void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
// {
// 	int	cnt;
// 	int mid;
// 	int	pivot;

// 	if (e - s < 2)
// 	{
// 		if (e - s == 1)
// 			sort_2nums(stk_a, stk_b, sorted[s]);
// 		return ;
// 	}
// 	mid = (s + e) / 2;
// 	pivot = sorted[mid];
// 	cnt = e - s + 1;
// 	while (cnt--)
// 	{
// 		if (get_top(*stk_a) > pivot)
// 			do_operation(RA, stk_a, stk_b);
// 		else
// 			do_operation(PB, stk_a, stk_b);
// 	}
// 	cnt = e - mid;
// 	while (cnt--)
// 		do_operation(RRA, stk_a, stk_b);
// 	a_to_b(stk_a, stk_b, mid + 1, e, sorted);
// 	b_to_a(stk_a, stk_b, s, mid, sorted);
// }

// void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
// {
// 	int	cnt;
// 	int mid;
// 	int	pivot;

// 	if (e - s < 2)
// 	{
// 		cnt = e - s + 1;
// 		while (cnt--)
// 			do_operation(PA, stk_a, stk_b);
// 		a_to_b(stk_a, stk_b, s, e, sorted);
// 		return ;
// 	}
// 	mid = (s + e) / 2;
// 	pivot = sorted[mid];
// 	cnt = e - s + 1;
// 	while (cnt--)
// 	{
// 		if (get_top(*stk_b) <= pivot)
// 			do_operation(RB, stk_a, stk_b);
// 		else
// 			do_operation(PA, stk_a, stk_b);
// 	}
// 	cnt = mid - s + 1;
// 	while (cnt--)
// 		do_operation(RRB, stk_a, stk_b);
// 	a_to_b(stk_a, stk_b, mid + 1, e, sorted);
// 	b_to_a(stk_a, stk_b, s, mid, sorted);	
// }