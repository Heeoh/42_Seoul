/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:17 by heson             #+#    #+#             */
/*   Updated: 2023/02/13 19:51:10 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../headers/operations.h"
#include "../headers/push_swap.h"

void	sort_2nums(t_stack *stk_a, t_stack *stk_b, int top)
{
	if (get_top(*stk_a) != top)
		do_operation(SA, stk_a, stk_b);
}

void	sort_3nums(t_stack *stk_a, t_stack *stk_b, int bottom, int top)
{
	if (stk_a->memory[stk_a->top - 2] == bottom && get_top(*stk_a) == top)
		return ;
	else if (stk_a->memory[stk_a->top - 2] == bottom && get_top(*stk_a) != top)
		do_operation(SA, stk_a, stk_b);
	else if (stk_a->memory[stk_a->top - 2] == top && get_top(*stk_a) == bottom)
	{
		do_operation(SA, stk_a, stk_b);
		do_operation(RRA, stk_a, stk_b);
	}
	else if (stk_a->memory[stk_a->top - 2] == top && get_top(*stk_a) != bottom)
		do_operation(RRA, stk_a, stk_b);
	else if (get_top(*stk_a) == bottom)
		do_operation(RA, stk_a, stk_b);
	else if (get_top(*stk_a) == top)
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
		while (get_top(*stk_a) > sorted[0])
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
			if (get_top(*stk_a) <= sorted[1])
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

void	partition_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	cnt;
	int pivot1;
	int pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	cnt = e - s + 1;
	while (cnt--)
	{
		if (get_top(*stk_a) >= sorted[pivot2])
			do_operation(RA, stk_a, stk_b);
		else
		{
			do_operation(PB, stk_a, stk_b);
			if (get_top(*stk_b) >= sorted[pivot1])
				do_operation(RB, stk_a, stk_b);	
		}
	}
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
		cnt =  e - pivot2 + 1;
		while (cnt--)
			do_operation(RRR, stk_a, stk_b);
		cnt = (pivot2 - pivot1) - (e - pivot2 + 1);
		while (cnt--)
			do_operation(RRB, stk_a, stk_b);
	}
}

void	partition_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	cnt;
	int pivot1;
	int pivot2;

	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	cnt = e - s + 1;
	while (cnt--)
	{
		if (get_top(*stk_b) < sorted[pivot1])
			do_operation(RB, stk_a, stk_b);
		else
		{
			do_operation(PA, stk_a, stk_b);
			if (get_top(*stk_a) < sorted[pivot2])
				do_operation(RA, stk_a, stk_b);	
		}
	}
}

void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	pivot1;
	int pivot2;

	if (e - s == 2)
	{
		if (get_top(*stk_a) == sorted[e])
		{
			// == 3 -> pb ra pa sa rra & top != 1 -> sa
			// == 2 -> prev == 3 -> pb sa pa & sa
			// == 1 -> prev == 3 -> ra sa rra
			do_operation(PB, stk_a, stk_b);
			do_operation(RA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			do_operation(SA, stk_a, stk_b);
			do_operation(RRA, stk_a, stk_b);
			if (get_top(*stk_a) != sorted[s])
				do_operation(SA, stk_a, stk_b);
		}
		else if (get_top(*stk_a) == sorted[s])
		{
			if (stk_a->memory[stk_a->top - 1] != sorted[e])
				return ;
			do_operation(RA, stk_a, stk_b);
			do_operation(SA, stk_a, stk_b);
			do_operation(RRA, stk_a, stk_b);
		}
		else
		{
			if (stk_a->memory[stk_a->top - 1] == sorted[e])
			{
				do_operation(PB, stk_a, stk_b);
				do_operation(SA, stk_a, stk_b);
				do_operation(PA, stk_a, stk_b);
			}
			do_operation(SA, stk_a, stk_b);
		}
		return;
	}
	else if (e - s < 2)
	{
		if (e != s)
			sort_2nums(stk_a, stk_b, sorted[s]);
		return;
	}
	pivot1 = s + ((e - s) / 3);
	pivot2 = e - ((e - s) / 3);
	partition_a(stk_a, stk_b, s, e, sorted);
	a_to_b(stk_a, stk_b, pivot2, e, sorted); 			// L
	b_to_a(stk_a, stk_b, pivot1, pivot2 - 1, sorted);	// M
	b_to_a(stk_a, stk_b, s, pivot1 - 1, sorted);		// S
}

void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int cnt;
	int	pivot1;
	int pivot2;

	if (e - s == 2)
	{
		// == 3 -> pa pa pa & top_a != 1 -> sa
		// == 2 -> pa & top_b != 3 -> sb & pa sa pa
		// == 1 -> rb pa pa & top_a == 3 -> sa & rrb pa
		if (get_top(*stk_b) == sorted[e])
		{
			do_operation(PA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			if (get_top(*stk_a) != sorted[s])
				do_operation(SA, stk_a, stk_b);
		}
		else if (get_top(*stk_b) == sorted[s])
		{
			do_operation(RB, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			if (get_top(*stk_a) == sorted[e])
				do_operation(SA, stk_a, stk_b);
			do_operation(RRB, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
		}
		else
		{
			do_operation(PA, stk_a, stk_b);
			if (get_top(*stk_b) != sorted[e])
				do_operation(SB, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			do_operation(SA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
		}
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
	a_to_b(stk_a, stk_b, pivot1, pivot2 - 1, sorted);
	b_to_a(stk_a, stk_b, s, pivot1 - 1, sorted);
}
