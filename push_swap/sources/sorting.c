/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:17 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 09:54:05 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sorting.h"

void	sort_2nums(t_two_stks *stk, int top)
{
	if (peek_top(stk->a) != top)
		do_operation(SA, &stk->a, &stk->b);
}

void	sort_3nums(t_two_stks *stk, int bottom, int top)
{
	if (stk->a.memory[stk->a.top - 2] == bottom && peek_top(stk->a) == top)
		return ;
	else if (stk->a.memory[stk->a.top - 2] == bottom && peek_top(stk->a) != top)
		do_operation(SA, &stk->a, &stk->b);
	else if (stk->a.memory[stk->a.top - 2] == top && peek_top(stk->a) == bottom)
	{
		do_operation(SA, &stk->a, &stk->b);
		do_operation(RRA, &stk->a, &stk->b);
	}
	else if (stk->a.memory[stk->a.top - 2] == top && peek_top(stk->a) != bottom)
		do_operation(RRA, &stk->a, &stk->b);
	else if (peek_top(stk->a) == bottom)
		do_operation(RA, &stk->a, &stk->b);
	else if (peek_top(stk->a) == top)
	{
		do_operation(SA, &stk->a, &stk->b);
		do_operation(RA, &stk->a, &stk->b);
	}
}

void	sort_less_5nums(t_two_stks *stk, int *sorted)
{
	int	cnt;
	int	i;

	if (get_stk_size(stk->a) <= 1)
		return ;
	else if (get_stk_size(stk->a) == 2)
		sort_2nums(stk, sorted[0]);
	else if (get_stk_size(stk->a) == 3)
		sort_3nums(stk, sorted[2], sorted[0]);
	else
	{
		cnt = get_stk_size(stk->a) - 3;
		i = 0;
		while (i < cnt)
		{
			if (peek_top(stk->a) < sorted[cnt] && i++)
				do_operation(PB, &stk->a, &stk->b);
			else
				do_operation(RA, &stk->a, &stk->b);
		}
		sort_3nums(stk, sorted[get_stk_size(stk->a) - 1], sorted[cnt]);
		while (cnt--)
			do_operation(PA, &stk->a, &stk->b);
		sort_2nums(stk, sorted[0]);
	}
}

void	a_to_b(t_two_stks *stk, int s, int e, int *sorted)
{
	int	pivot1;
	int	pivot2;

	if (e - s < 2)
	{
		if (e - s == 2)
		{
			if (!(peek_top(stk->a) == sorted[s]
				&& stk->a.memory[stk->a.top - 2] == sorted[e]))
				sort_3top_a(stk, sorted[e], sorted[s]);
		}
		else if (e - s == 1)
			sort_2nums(stk, sorted[s]);
		return ;
	}
	pivot1 = s + ((e - s) / 3);
	pivot2 = e - ((e - s) / 3);
	partition_a(stk, s, e, sorted);
	a_to_b(stk, pivot2, e, sorted);
	b_to_a(stk, pivot1, pivot2 - 1, sorted);
	b_to_a(stk, s, pivot1 - 1, sorted);
}

void	b_to_a(t_two_stks *stk, int s, int e, int *sorted)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	if (e - s < 2)
	{
		if (e - s == 2 && !(peek_top(stk->b) == sorted[e]))
			sort_3top_b(stk, sorted[e], sorted[s]);
		else
		{
			cnt = e - s + 1;
			while (cnt--)
				do_operation(PA, &stk->a, &stk->b);
			a_to_b(stk, s, e, sorted);
		}
		return ;
	}
	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	partition_b(stk, s, e, sorted);
	a_to_b(stk, pivot2, e, sorted);
	relocation_b(stk, s, e);
	a_to_b(stk, pivot1, pivot2 - 1, sorted);
	b_to_a(stk, s, pivot1 - 1, sorted);
}
