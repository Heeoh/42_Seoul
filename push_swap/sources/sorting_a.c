/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:04 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 17:14:46 by heson            ###   ########.fr       */
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

void	relocation_a(t_two_stks *stk, int m_size, int l_size)
{
	int	cnt;

	if (m_size <= l_size)
	{
		cnt = m_size;
		while (cnt--)
			do_operation(RRR, &stk->a, &stk->b);
		cnt = (l_size) - (m_size);
		while (cnt--)
			do_operation(RRA, &stk->a, &stk->b);
	}
	else
	{
		cnt = l_size;
		while (cnt--)
			do_operation(RRR, &stk->a, &stk->b);
		cnt = m_size - (l_size);
		while (cnt--)
			do_operation(RRB, &stk->a, &stk->b);
	}
}

void	partition_a(t_two_stks *stk, int s, int e, int *sorted)
{
	int	pivot1;
	int	pivot2;
	int	ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	ra_cnt = 0;
	pb_cnt = 0;
	rb_cnt = 0;
	while (pb_cnt < pivot2 - s)
	{
		if (peek_top(stk->a) >= sorted[pivot2] && ++ra_cnt)
			do_operation(RA, &stk->a, &stk->b);
		else
		{
			do_operation(PB, &stk->a, &stk->b);
			pb_cnt++;
			if (peek_top(stk->b) > sorted[pivot1] && ++rb_cnt)
				do_operation(RB, &stk->a, &stk->b);
		}
	}
	relocation_a(stk, rb_cnt, ra_cnt);
}
