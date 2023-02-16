/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:51 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 01:40:48 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sorting.h"

// == 3 -> pa pa pa & top_a != 1 -> sa
// == 2 -> pa & top_b != 3 -> sb & pa sa pa
// == 1 -> rb pa pa & top_a == 3 -> sa & rrb pa
void	sort_3top_b(t_two_stks *stk, int bottom, int top)
{
	if (peek_top(stk->b) == top)
	{
		do_operation(RB, &stk->a, &stk->b);
		do_operation(PA, &stk->a, &stk->b);
		do_operation(PA, &stk->a, &stk->b);
		if (peek_top(stk->a) == bottom)
			do_operation(SA, &stk->a, &stk->b);
		do_operation(RRB, &stk->a, &stk->b);
		do_operation(PA, &stk->a, &stk->b);
	}
	else
	{
		do_operation(PA, &stk->a, &stk->b);
		if (peek_top(stk->b) != bottom)
			do_operation(SB, &stk->a, &stk->b);
		do_operation(PA, &stk->a, &stk->b);
		do_operation(SA, &stk->a, &stk->b);
		do_operation(PA, &stk->a, &stk->b);
	}
}

void	relocation_b(t_two_stks *stk, int s_size, int m_size)
{
	int	cnt;

	if (s_size <= m_size)
	{
		cnt = s_size;
		while (cnt--)
			do_operation(RRR, &stk->a, &stk->b);
		cnt = (m_size) - (s_size);
		while (cnt--)
			do_operation(RRA, &stk->a, &stk->b);
	}
	else
	{
		cnt = m_size;
		while (cnt--)
			do_operation(RRR, &stk->a, &stk->b);
		cnt = (s_size) - (m_size);
		while (cnt--)
			do_operation(RRB, &stk->a, &stk->b);
	}
}

int	partition_b(t_two_stks *stk, int s, int e, int *sorted)
{
	int	rb_cnt;
	int	pa_cnt;
	int	pivot1;
	int	pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	rb_cnt = 0;
	pa_cnt = 0;
	while (pa_cnt < e - pivot1)
	{
		if (peek_top(stk->b) <= sorted[pivot1] && ++rb_cnt)
			do_operation(RB, &stk->a, &stk->b);
		else
		{
			do_operation(PA, &stk->a, &stk->b);
			pa_cnt++;
			if (peek_top(stk->a) < sorted[pivot2])
				do_operation(RA, &stk->a, &stk->b);
		}
	}
	return (rb_cnt);
}
