/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:30:12 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 18:14:31 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
#include "../library/libft/libft.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdio.h>

void	print_op(t_op op)
{
	char	op_str[45];

	ft_strlcpy(op_str, "sa  sb  ss  pa  pb  ra  rb  rr  rra rrb rrr", 44);
	if (SA <= op && op <= RR)
		printf("%.2s\n", op_str + (op * 4));
	else if (RRA <= op && op <= RRR)
		printf("%.3s\n", op_str + (op * 4));
}

void	do_operation(t_op op, t_stack *stk_a, t_stack *stk_b)
{
	print_op(op);
	if (op == SA || op == SS)
		swap(stk_a);
	if (op == SB || op == SS)
		swap(stk_b);
	if (op == PA)
		push(stk_b, stk_a);
	else if (op == PB)
		push(stk_a, stk_b);
	if (op == RA || op == RR)
		rotate(stk_a);
	if (op == RB || op == RR)
		rotate(stk_b);
	if (op == RRA || op == RRR)
		reverse(stk_a);
	if (op == RRB || op == RRR)
		reverse(stk_b);
}

// void	sa(t_stack *stk)
// {
// 	printf("sa\n");
// 	swap(stk);
// }

// void	sb(t_stack *stk)
// {
// 	printf("sb\n");
// 	swap(stk);
// }

// void	ss(t_stack *stk_a, t_stack *stk_b)
// {
// 	printf("ss\n");
// 	swap(stk_a);
// 	swap(stk_b);
// }

// void	pa(t_stack *stk_a, t_stack *stk_b)
// {
// 	printf("pa\n");
// 	push(stk_b, stk_a);
// }

// void	pb(t_stack *stk_a, t_stack *stk_b)
// {
// 	printf("pb\n");
// 	push(stk_a, stk_b);
// }

// void	ra(t_stack *stk)
// {
// 	printf("ra\n");
// 	rotate(stk);
// }

// void	rb(t_stack *stk)
// {
// 	printf("rb\n");
// 	rotate(stk);
// }

// void	rr(t_stack *stk_a, t_stack *stk_b)
// {
// 	printf("rr\n");
// 	rotate(stk_a);
// 	rotate(stk_b);
// }

// void	rra(t_stack *stk)
// {
// 	printf("rra\n");
// 	reverse(stk);
// }

// void	rrb(t_stack *stk)
// {
// 	printf("rrb\n");
// 	reverse(stk);
// }

// void	rrr(t_stack *stk_a, t_stack *stk_b)
// {
// 	printf("rrr\n");
// 	reverse(stk_a);
// 	reverse(stk_b);
// }