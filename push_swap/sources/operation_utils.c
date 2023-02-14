/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:34:11 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 19:18:34 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
#include <stdlib.h>

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
			return ;
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
			return ;
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
