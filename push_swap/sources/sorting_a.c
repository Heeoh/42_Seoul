/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:04 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 19:42:33 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sorting.h"

// == 3 -> pb ra pa sa rra & top != 1 -> sa
// == 2 -> prev == 3 -> pb sa pa & sa
// == 1 -> prev == 3 -> ra sa rra
void	sort_3top_a(t_stack *stk_a, t_stack *stk_b, int bottom, int top)
{
	if (peek_top(*stk_a) == bottom)
	{
		do_operation(PB, stk_a, stk_b);
		do_operation(RA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		do_operation(SA, stk_a, stk_b);
		do_operation(RRA, stk_a, stk_b);
		if (peek_top(*stk_a) != top)
			do_operation(SA, stk_a, stk_b);
	}
	else if (peek_top(*stk_a) == top)
	{
		if (stk_a->memory[stk_a->top - 1] != bottom)
			return ;
		do_operation(RA, stk_a, stk_b);
		do_operation(SA, stk_a, stk_b);
		do_operation(RRA, stk_a, stk_b);
	}
	else
	{
		if (stk_a->memory[stk_a->top - 1] == bottom)
		{
			do_operation(PB, stk_a, stk_b);
			do_operation(SA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
		}
		do_operation(SA, stk_a, stk_b);
	}
}

void	relocation_a(t_stack *stk_a, t_stack *stk_b, int s, int e)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	if (pivot2 - pivot1 <= e - pivot2 + 1)
	{
		cnt = pivot2 - pivot1;
		while (cnt--)
			do_operation(RRR, stk_a, stk_b);
		cnt = (e - pivot2 + 1) - (pivot2 - pivot1);
		while (cnt--)
			do_operation(RRA, stk_a, stk_b);
	}
	else
	{
		cnt = e - pivot2 + 1;
		while (cnt--)
			do_operation(RRR, stk_a, stk_b);
		cnt = (pivot2 - pivot1) - (e - pivot2 + 1);
		while (cnt--)
			do_operation(RRB, stk_a, stk_b);
	}
}

void	partition_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	cnt = e - s + 1;
	while (cnt--)
	{
		if (peek_top(*stk_a) >= sorted[pivot2])
			do_operation(RA, stk_a, stk_b);
		else
		{
			do_operation(PB, stk_a, stk_b);
			if (peek_top(*stk_b) >= sorted[pivot1])
				do_operation(RB, stk_a, stk_b);
		}
	}
	relocation_a(stk_a, stk_b, s, e);
}
