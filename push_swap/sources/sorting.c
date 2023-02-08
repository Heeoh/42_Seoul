/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:17 by heson             #+#    #+#             */
/*   Updated: 2023/02/08 15:31:36 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../headers/operations.h"
#include <stdio.h> // printf


//-------------------------- quick sorting -----------------------------//

void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	tmp;
	int	pivot;

	if (e - s < 2)
	{
		if (e - s == 1)
		{
			tmp = get_top(*stk_a);
			do_operation(SA, stk_a, stk_b);
			if (tmp < get_top(*stk_a))
				do_operation(SA, stk_a, stk_b);
		}
		return ;
	}
	pivot = sorted[(s + e) / 2];
	tmp = get_stk_size(*stk_a);
	while (tmp--)
	{
		if (get_top(*stk_a) >= pivot)
			do_operation(RA, stk_a, stk_b);
		else
			do_operation(PB, stk_a, stk_b);
	}
	a_to_b(stk_a, stk_b, (s + e) / 2, e, sorted);
	b_to_a(stk_a, stk_b, s, (s + e) / 2 - 1, sorted);
}

void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	tmp;
	int	pivot;

	if (e - s < 2)
	{
		if (e - s == 1)
		{
			tmp = get_top(*stk_b);
			do_operation(SB, stk_a, stk_b);
			if (tmp > get_top(*stk_b))
				do_operation(SB, stk_a, stk_b);
		}
		tmp = e - s + 1;
		while (tmp--)
			do_operation(PA, stk_a, stk_b);
		return ;
	}
	pivot = sorted[(s + e) / 2];
	tmp = get_stk_size(*stk_b);
	while (tmp--)
	{
		if (get_top(*stk_b) <= pivot)
			do_operation(RB, stk_a, stk_b);
		else
			do_operation(PA, stk_a, stk_b);
	}
	a_to_b(stk_a, stk_b, (s + e) / 2 + 1, e, sorted);
	b_to_a(stk_a, stk_b, s, (s + e) / 2, sorted);	
}

//----------------------- insertion sorting ----------------------------//
// void	get_top_after_op(t_op op, t_stack **stk, int *prev, int *cur)
// {
// 	*prev = *cur;
// 	do_operation(op, 0, *stk);
// 	*cur = get_top(**stk);
// }
// // more than 25 lines
// void	find_pos(t_stack **stk_b, int x)
// {
// 	int	first_top;
// 	int	prev_top;
// 	int	cur_top;

// 	prev_top = get_top(**stk_b);
// 	do_operation(RRB, 0, *stk_b);
// 	cur_top = get_top(**stk_b);
// 	first_top = prev_top;
// 	if (cur_top == prev_top)
// 		return ;
// 	if (cur_top < prev_top)
// 	{
// 		if (prev_top < x || x < cur_top)
// 		{
// 			do_operation(RB, 0, *stk_b);
// 			return ;
// 		}
// 		get_top_after_op(RB, stk_b, &prev_top, &cur_top);
// 		while (x < cur_top)
// 			get_top_after_op(RB, stk_b, &prev_top, &cur_top);
// 	}
// 	else
// 	{
// 		if (x < cur_top)
// 		{
// 			get_top_after_op(RB, stk_b, &prev_top, &cur_top);
// 			while (x < prev_top && cur_top < prev_top)
// 				get_top_after_op(RB, stk_b, &prev_top, &cur_top);
// 			return ;
// 		}
// 		while (cur_top < x && prev_top < cur_top && cur_top != first_top)
// 			get_top_after_op(RRB, stk_b, &prev_top, &cur_top);
// 		do_operation(RB, 0, *stk_b);
// 	}
// }

// void	insertion_sort(t_stack *stk_a, t_stack *stk_b)
// {
// 	int	a_top;
// 	int	b_top;

// 	while (!isEmpty(*stk_a))
// 	{
// 		a_top = get_top(*stk_a);
// 		if (!isEmpty(*stk_b))
// 		{
// 			b_top = get_top(*stk_b);
// 			find_pos(&stk_b, a_top);
// 		}
// 		do_operation(PB, stk_a, stk_b);
// 		if (get_stk_size(*stk_b) == 2 && get_top(*stk_b) < b_top)
// 			do_operation(SB, 0, stk_b);
// 		// print_state(*stk_a, *stk_b);
// 	}
// 	b_top = get_top(*stk_b);
// 	do_operation(RRB, 0, stk_b);
// 	while (get_top(*stk_b) > b_top)
// 		do_operation(RRB, 0, stk_b);
// 	do_operation(RB, 0, stk_b);
// 	while (!isEmpty(*stk_b))
// 		do_operation(PA, stk_a, stk_b);
// 	print_state(*stk_a, *stk_b);
// }

/*
< insertion sort >
Init
A 1 2 3 4 5
B


*/

/*

< dual pivot quick sorting >
Init
A 24 8 42 75 29 77 38 57
B

*/
