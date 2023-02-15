/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:04 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 03:15:59 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sorting.h"

// == 3 -> pb ra pa sa rra & top != 1 -> sa
// == 2 -> prev == 3 -> pb sa pa & sa
// == 1 -> prev == 3 -> ra sa rra
void	sort_3top_a(t_two_stks *stk, int bottom, int top)
{
	if (peek_top(stk->a) == bottom)
	{
		do_operation(PB, &stk->a, &stk->b);
		do_operation(RA, &stk->a, &stk->b);
		do_operation(PA, &stk->a, &stk->b);
		do_operation(SA, &stk->a, &stk->b);
		do_operation(RRA, &stk->a, &stk->b);
		sort_2nums(stk, top);
	}
	else if (peek_top(stk->a) == top)
	{
		do_operation(RA, &stk->a, &stk->b);
		do_operation(SA, &stk->a, &stk->b);
		do_operation(RRA, &stk->a, &stk->b);
	}
	else
	{
		if (stk->a.memory[stk->a.top - 1] == bottom)
		{
			do_operation(PB, &stk->a, &stk->b);
			do_operation(SA, &stk->a, &stk->b);
			do_operation(PA, &stk->a, &stk->b);
		}
		do_operation(SA, &stk->a, &stk->b);
	}
}

void	relocation_a(t_two_stks *stk, int s, int e)
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
			do_operation(RRR, &stk->a, &stk->b);
		cnt = (e - pivot2 + 1) - (pivot2 - pivot1);
		while (cnt--)
			do_operation(RRA, &stk->a, &stk->b);
	}
	else
	{
		cnt = e - pivot2 + 1;
		while (cnt--)
			do_operation(RRR, &stk->a, &stk->b);
		cnt = (pivot2 - pivot1) - (e - pivot2 + 1);
		while (cnt--)
			do_operation(RRB, &stk->a, &stk->b);
	}
}

void	partition_a(t_two_stks *stk, int s, int e, int *sorted)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	cnt = e - s + 1;
	while (cnt--)
	{
		if (peek_top(stk->a) >= sorted[pivot2])
			do_operation(RA, &stk->a, &stk->b);
		else
		{
			do_operation(PB, &stk->a, &stk->b);
			if (peek_top(stk->b) >= sorted[pivot1])
				do_operation(RB, &stk->a, &stk->b);
		}
	}
	relocation_a(stk, s, e);
}
