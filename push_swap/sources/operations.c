/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:30:12 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 02:49:49 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/operations.h"
#include "../library/libft/libft.h"
#include "../library/printf/headers/ft_printf.h"

void	do_operation(t_op op, t_stack *stk_a, t_stack *stk_b)
{
	char	op_str[45];

	ft_strlcpy(op_str, "sa  sb  ss  pa  pb  ra  rb  rr  rra rrb rrr", 44);
	if (SA <= op && op <= RR)
		ft_printf("%.2s\n", op_str + (op * 4));
	else if (RRA <= op && op <= RRR)
		ft_printf("%.3s\n", op_str + (op * 4));
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

void	swap(t_stack *stk)
{
	int	top1;
	int	top2;

	if (get_stk_size(*stk) < 2)
		return ;
	top1 = peek_top(*stk);
	pop_top(stk);
	top2 = peek_top(*stk);
	pop_top(stk);
	push_top(stk, top1);
	push_top(stk, top2);
}

void	push(t_stack *from_stk, t_stack *to_stk)
{
	if (empty(*from_stk))
		return ;
	push_top(to_stk, peek_top(*from_stk));
	pop_top(from_stk);
}

void	rotate(t_stack *stk)
{
	int	*tmp;
	int	i;

	if (get_stk_size(*stk) < 2)
		return ;
	else if (get_stk_size(*stk) == 2)
		swap(stk);
	else
	{
		tmp = (int *)malloc(sizeof(int) * stk->top + 1);
		if (!tmp)
			print_error();
		i = 0;
		while (!empty(*stk))
		{
			tmp[i++] = peek_top(*stk);
			pop_top(stk);
		}
		push_top(stk, tmp[0]);
		while (--i > 0)
			push_top(stk, tmp[i]);
		free(tmp);
	}
}

void	reverse(t_stack *stk)
{
	int	*tmp;
	int	i;
	int	prev_top;

	if (get_stk_size(*stk) < 2)
		return ;
	else if (get_stk_size(*stk) == 2)
		swap(stk);
	else
	{
		tmp = (int *)malloc(sizeof(int) * stk->top + 1);
		if (!tmp)
			print_error();
		i = 0;
		while (!empty(*stk))
		{
			tmp[i++] = peek_top(*stk);
			pop_top(stk);
		}
		prev_top = tmp[--i];
		while (i--)
			push_top(stk, tmp[i]);
		push_top(stk, prev_top);
		free(tmp);
	}
}
