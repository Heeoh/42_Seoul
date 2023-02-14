/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:51 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 19:43:07 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sorting.h"

// == 3 -> pa pa pa & top_a != 1 -> sa
// == 2 -> pa & top_b != 3 -> sb & pa sa pa
// == 1 -> rb pa pa & top_a == 3 -> sa & rrb pa
void	sort_3top_b(t_stack *stk_a, t_stack *stk_b, int bottom, int top)
{
	if (peek_top(*stk_b) == bottom)
	{
		do_operation(PA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		if (peek_top(*stk_a) != top)
			do_operation(SA, stk_a, stk_b);
	}
	else if (peek_top(*stk_b) == top)
	{
		do_operation(RB, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		if (peek_top(*stk_a) == bottom)
			do_operation(SA, stk_a, stk_b);
		do_operation(RRB, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
	}
	else
	{
		do_operation(PA, stk_a, stk_b);
		if (peek_top(*stk_b) != bottom)
			do_operation(SB, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		do_operation(SA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
	}
}

void	relocation_b(t_stack *stk_a, t_stack *stk_b, int s, int e)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	if (pivot1 - s <= pivot2 - pivot1)
	{
		cnt = pivot1 - s;
		while (cnt--)
			do_operation(RRR, stk_a, stk_b);
		cnt = (pivot2 - pivot1) - (pivot1 - s);
		while (cnt--)
			do_operation(RRA, stk_a, stk_b);
	}
	else
	{
		cnt = pivot2 - pivot1;
		while (cnt--)
			do_operation(RRR, stk_a, stk_b);
		cnt = (pivot1 - s) - (pivot2 - pivot1);
		while (cnt--)
			do_operation(RRB, stk_a, stk_b);
	}
}

void	partition_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	cnt = e - s + 1;
	while (cnt--)
	{
		if (peek_top(*stk_b) < sorted[pivot1])
			do_operation(RB, stk_a, stk_b);
		else
		{
			do_operation(PA, stk_a, stk_b);
			if (peek_top(*stk_a) < sorted[pivot2])
				do_operation(RA, stk_a, stk_b);
		}
	}
}
