/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:17 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 19:39:27 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sorting.h"

void	sort_2nums(t_stack *stk_a, t_stack *stk_b, int top)
{
	if (peek_top(*stk_a) != top)
		do_operation(SA, stk_a, stk_b);
}

void	sort_3nums(t_stack *stk_a, t_stack *stk_b, int bottom, int top)
{
	if (stk_a->memory[stk_a->top - 2] == bottom && peek_top(*stk_a) == top)
		return ;
	else if (stk_a->memory[stk_a->top - 2] == bottom && peek_top(*stk_a) != top)
		do_operation(SA, stk_a, stk_b);
	else if (stk_a->memory[stk_a->top - 2] == top && peek_top(*stk_a) == bottom)
	{
		do_operation(SA, stk_a, stk_b);
		do_operation(RRA, stk_a, stk_b);
	}
	else if (stk_a->memory[stk_a->top - 2] == top && peek_top(*stk_a) != bottom)
		do_operation(RRA, stk_a, stk_b);
	else if (peek_top(*stk_a) == bottom)
		do_operation(RA, stk_a, stk_b);
	else if (peek_top(*stk_a) == top)
	{
		do_operation(SA, stk_a, stk_b);
		do_operation(RA, stk_a, stk_b);
	}
}

void	sort_less_5nums(t_stack *stk_a, t_stack *stk_b, int *sorted)
{
	int	cnt;

	if (get_stk_size(*stk_a) <= 1)
		return ;
	else if (get_stk_size(*stk_a) == 2)
		sort_2nums(stk_a, stk_b, sorted[0]);
	else if (get_stk_size(*stk_a) == 3)
		sort_3nums(stk_a, stk_b, sorted[2], sorted[0]);
	else if (get_stk_size(*stk_a) == 4)
	{
		while (peek_top(*stk_a) > sorted[0])
			do_operation(RA, stk_a, stk_b);
		do_operation(PB, stk_a, stk_b);
		sort_3nums(stk_a, stk_b, sorted[3], sorted[1]);
		do_operation(PA, stk_a, stk_b);
	}
	else
	{
		cnt = 2;
		while (cnt)
		{
			if (peek_top(*stk_a) <= sorted[1])
			{
				do_operation(PB, stk_a, stk_b);
				cnt--;
				continue ;
			}
			do_operation(RA, stk_a, stk_b);
		}
		sort_3nums(stk_a, stk_b, sorted[4], sorted[2]);
		do_operation(PA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		sort_2nums(stk_a, stk_b, sorted[0]);
	}
}

void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	pivot1;
	int	pivot2;

	if (e - s == 2)
	{
		sort_3top_a(stk_a, stk_b, sorted[e], sorted[s]);
		return ;
	}
	else if (e - s < 2)
	{
		if (e != s)
			sort_2nums(stk_a, stk_b, sorted[s]);
		return ;
	}
	pivot1 = s + ((e - s) / 3);
	pivot2 = e - ((e - s) / 3);
	partition_a(stk_a, stk_b, s, e, sorted);
	a_to_b(stk_a, stk_b, pivot2, e, sorted);
	b_to_a(stk_a, stk_b, pivot1, pivot2 - 1, sorted);
	b_to_a(stk_a, stk_b, s, pivot1 - 1, sorted);
}

void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	cnt;
	int	pivot1;
	int	pivot2;

	if (e - s == 2)
	{
		sort_3top_b(stk_a, stk_b, sorted[e], sorted[s]);
		return ;
	}
	if (e - s < 2)
	{
		cnt = e - s + 1;
		while (cnt--)
			do_operation(PA, stk_a, stk_b);
		a_to_b(stk_a, stk_b, s, e, sorted);
		return ;
	}
	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	partition_b(stk_a, stk_b, s, e, sorted);
	a_to_b(stk_a, stk_b, pivot2, e, sorted);
	relocation_b(stk_a, stk_b, s, e);
	a_to_b(stk_a, stk_b, pivot1, pivot2 - 1, sorted);
	b_to_a(stk_a, stk_b, s, pivot1 - 1, sorted);
}
