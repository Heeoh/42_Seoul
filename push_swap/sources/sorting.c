/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:17 by heson             #+#    #+#             */
/*   Updated: 2023/01/31 03:32:15 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/stack.h"
#include "../header/operations.h"
#include <stdio.h> // printf

void	print_state(t_stack stk_a, t_stack stk_b)
{
	int ia = 0, ib = 0;

	printf("a | ");
	while (ia <= stk_a.top)
		printf("%d ", stk_a.memory[ia++]);
	printf("\n");
	printf("b | ");
	while (ib <= stk_b.top)
		printf("%d ", stk_b.memory[ib++]);
	printf("\n");
}

unsigned int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	get_top_after_op(void op(t_stack *), t_stack **stk, int *prev, int *cur)
{
	*prev = *cur;
	op(*stk);
	*cur = get_top(**stk);
}

// more than 25 lines
void	find_pos(t_stack **stk_b, int x)
{
	int	first_top;
	int	prev_top;
	int	cur_top;

	prev_top = get_top(**stk_b);
	rrb(*stk_b);
	cur_top = get_top(**stk_b);
	first_top = prev_top;
	if (cur_top == prev_top)
		return ;
	if (cur_top < prev_top)
	{
		if (prev_top < x || x < cur_top)
		{
			rb(*stk_b);
			return ;
		}
		get_top_after_op(rb, stk_b, &prev_top, &cur_top);
		while (x < cur_top)
			get_top_after_op(rb, stk_b, &prev_top, &cur_top);
	}
	else
	{
		if (x < prev_top)
		{
			while (x < prev_top && cur_top < prev_top && cur_top != first_top)
				get_top_after_op(rb, stk_b, &prev_top, &cur_top);
			return ;
		}
		while (cur_top < x && prev_top < cur_top && cur_top != first_top)
			get_top_after_op(rrb, stk_b, &prev_top, &cur_top);
		rb(*stk_b);
	}
}

void	insertion_sort(t_stack *stk_a, t_stack *stk_b)
{
	int	a_top;
	int	b_top;

	while (!isEmpty(*stk_a))
	{
		a_top = get_top(*stk_a);
		if (!isEmpty(*stk_b))
		{
			b_top = get_top(*stk_b);
			find_pos(&stk_b, a_top);
		}
		pb(stk_a, stk_b);
		if (get_stk_size(*stk_b) == 2 && get_top(*stk_b) < b_top)
			sb(stk_b);
		// print_state(*stk_a, *stk_b);
	}
	b_top = get_top(*stk_b);
	rrb(stk_b);
	while (get_top(*stk_b) > b_top)
		rrb(stk_b);
	rb(stk_b);
	while (!isEmpty(*stk_b))
		pa(stk_a, stk_b);
	print_state(*stk_a, *stk_b);
}

/*
< insertion sort >
Init
A 24 8 42 75 29 77 38 57
B

Exec pb
A 24 8 42 75 29 77 38
B 57

Exec pb rb
A 24 8 42 75 29 77
B 38 57

Exec pb
A 24 8 42 75 29
B 38 57 77

Exec rrb rb pb rb
A 24 8 42 75
B 29 38 57 77

Exec rrb rb rb pb rrb
A 24 8 42
B 29 38 57 75 77

Exec rrb rrb rrb rb pb rb rb
A 24 8
B 29 38 42 57 75 77

Exec rrb rb pb rb
A 24
B 8 29 38 42 57 75 77

Exec rrb rrb rb pb rb rb
A
B 8 24 29 38 42 57 75 77

Exec pa pa pa pa pa pa pa pa
A 77 75 57 42 38 29 24 8
B
*/

/*

< dual pivot quick sorting >
Init
A 24 8 42 75 29 77 38 57
B

Exec sa pb ra
A 57 24 8 42 75 29 77
B 38

Exec ra pb rb ra pb pb rb pb rb
A 75 77 57
B 24 8 29 38 42

Exec pb 
A 
B
*/
