/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:17 by heson             #+#    #+#             */
/*   Updated: 2023/02/11 21:36:24 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../headers/operations.h"
#include "../headers/push_swap.h"


//-------------------------- quick sorting -----------------------------//

// void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
// void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
// {
// 	int	tmp;
// 	int	pivot;

// 	if (e - s < 2)
// 	{
// 		if (e - s == 1)
// 		{
// 			tmp = get_top(*stk_a);
// 			do_operation(SA, stk_a, stk_b);
// 			if (tmp < get_top(*stk_a))
// 				do_operation(SA, stk_a, stk_b);
// 		}
// 		return ;
// 	}
// 	pivot = sorted[(s + e) / 2];
// 	tmp = get_stk_size(*stk_a);
// 	while (tmp--)
// 	{
// 		if (get_top(*stk_a) >= pivot)
// 			do_operation(RA, stk_a, stk_b);
// 		else
// 			do_operation(PB, stk_a, stk_b);
// 	}
// 	a_to_b(stk_a, stk_b, (s + e) / 2, e, sorted);
// 	b_to_a(stk_a, stk_b, s, (s + e) / 2 - 1, sorted);
// }

// void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
// {
// 	int	tmp;
// 	int	pivot;

// 	if (e - s < 2)
// 	{
// 		if (e - s == 1)
// 		{
// 			tmp = get_top(*stk_b);
// 			do_operation(SB, stk_a, stk_b);
// 			if (tmp > get_top(*stk_b))
// 				do_operation(SB, stk_a, stk_b);
// 		}
// 		tmp = e - s + 1;
// 		while (tmp--)
// 			do_operation(PA, stk_a, stk_b);
// 		return ;
// 	}
// 	pivot = sorted[(s + e) / 2];
// 	tmp = get_stk_size(*stk_b);
// 	while (tmp--)
// 	{
// 		if (get_top(*stk_b) <= pivot)
// 			do_operation(RB, stk_a, stk_b);
// 		else
// 			do_operation(PA, stk_a, stk_b);
// 	}
// 	a_to_b(stk_a, stk_b, (s + e) / 2 + 1, e, sorted);
// 	b_to_a(stk_a, stk_b, s, (s + e) / 2, sorted);	
// }

//----------------------- dual quick sorting --------------------------//

void	partition_a(t_stack *stk_a, t_stack *stk_b, int pivot1, int pivot2)
{
	int	cnt;

	cnt = get_stk_size(*stk_a);
	while (cnt--)
	{
		if (get_top(*stk_a) >= pivot2)
			do_operation(RA, stk_a, stk_b);
		else
		{
			do_operation(PB, stk_a, stk_b);
			if (get_top(*stk_b) < pivot1)
				do_operation(RB, stk_a, stk_b);	
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
			do_operation(PB, stk_a, stk_b);
			do_operation(RA, stk_a, stk_b);
			do_operation(PA, stk_a, stk_b);
			do_operation(SA, stk_a, stk_b);
			do_operation(RRA, stk_a, stk_b);
			if (get_top(*stk_a) != sorted[s])
				do_operation(PB, stk_a, stk_b);
		}
		else if (get_top(*stk_a) == sorted[s] 
				&& stk_a->memory[stk_a->top - 1] == sorted[e])
		{
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
		if (get_top(*stk_a) != sorted[s])
			do_operation(SA, stk_a, stk_b);
		return;
	}
	pivot1 = s + ((e - s) / 3);
	pivot2 = e - ((e - s) / 3);
	partition_a(stk_a, stk_b, sorted[pivot1], sorted[pivot2]);
	a_to_b(stk_a, stk_b, pivot2, e, sorted);
	b_to_a(stk_a, stk_b, pivot1, pivot2 - 1, sorted);
	b_to_a(stk_a, stk_b, s, pivot1 - 1, sorted);	
}

void	partition_b(t_stack *stk_a, t_stack *stk_b, int pivot1, int pivot2)
{
	int	cnt;

	cnt = get_stk_size(*stk_b);
	while (cnt--)
	{
		if (get_top(*stk_b) < pivot1)
			do_operation(RB, stk_a, stk_b);
		else
		{
			do_operation(PA, stk_a, stk_b);
			if (get_top(*stk_a) >= pivot2)
				do_operation(RA, stk_a, stk_b);	
		}
	}
}

void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted)
{
	int	pivot1;
	int pivot2;

	if (e - s == 2)
	{
		
	}
	else if (e - s < 2)
	{
		if (get_top(*stk_b) != sorted[e])
			do_operation(SB, stk_a, stk_b);
		if (get_top(*stk_b) != sorted[s])
			do_operation(PA, stk_a, stk_b);
		do_operation(PA, stk_a, stk_b);
		return;
	}
	pivot1 = s + (e - s) / 3;
	pivot2 = e - (e - s) / 3;
	partition_b(stk_a, stk_b, sorted[pivot1], sorted[pivot2]);
	a_to_b(stk_a, stk_b, pivot1, pivot2 - 1, sorted);
	a_to_b(stk_a, stk_b, pivot2, e, sorted);
	b_to_a(stk_a, stk_b, s, pivot1 - 1, sorted);	
}

/* 

dual pivot
func a to b :
if size of stack A < = 2
	필요시 swap return
set pivot1, 2
partitioning => a - l & p2, b - s, p1, m
a to b (l, p2)
b to a (p1, m)

func b to a :
if size of stack B < = 2
	필요시 swap 
	pa * (e - s + 1)
	return
set pivot1, 2
partitioning => a - l, p2, m, p1, b - s
a to b (m, p1)
a to b (l, p2)
b to a (s)

// b to a 3 nums
1 2 3 -> pa pa pa
1 3 2 -> pa pa sa pa
2 1 3 -> pa pa pa sa
2 3 1 -> rrb pa pa rb pa
3 1 2 -> pa sb pa sa pa
3 2 1 -> rrb pa pa sa rb pa



// b to a 2 nums
top == e -> pa pa
top == s -> sb pa pa

// b to a 1 nums 
pa

// a to b 3 nums
1 2 3 -> pb ra pa sa rra sa
1 3 2 -> pb(ra) sa pa(rra) sa
2 1 3 -> pb ra pa sa rra
2 3 1 -> ra sa rra
3 1 2 -> sa
3 2 1 -> none

top
== 3 -> pb ra pa sa rra & top != 1 -> sa
== 2 -> prev == 3 -> pb sa pa
		sa
== 1 -> prev == 3 -> ra sa rra


// b to a 3 nums
1 2 3 -> pa pa pa
1 3 2 -> pa pa sa pa
2 1 3 -> pa pa pa sa
2 3 1 -> rrb pa pa rb pa
3 1 2 -> pa sb pa sa pa
3 2 1 -> rrb pa pa sa rb pa

top
== 3 -> pa pa pa & top_a != 1 -> sa
== 2 -> pa & top_b != 3 -> sb & pa sa pa
== 1 -> rrb pa pa & top_a == 3 -> sa & rb pa

*/