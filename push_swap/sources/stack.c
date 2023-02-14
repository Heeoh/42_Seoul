/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:56:07 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 18:17:10 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>

void	init_stack(t_stack *stack, int size)
{
	stack->top = -1;
	stack->mem_size = size;
	stack->memory = (int *)malloc(sizeof(int) * stack->mem_size);
	if (!stack->memory)
		return ;
}

void	push_top(t_stack *stack, int x)
{
	if (full(*stack))
	{
		ft_printf("Error - stack is full\n");
		return ;
	}
	stack->memory[++(stack->top)] = x;
}

void	pop_top(t_stack *stack)
{
	if (empty(*stack))
	{
		ft_printf("Error - stack is empty\n");
		return ;
	}
	stack->memory[(stack->top)--] = 0;
}

int	peek_top(t_stack stack)
{
	if (empty(stack))
	{
		ft_printf("Error - stack is empty\n");
		return (-1);
	}
	return (stack.memory[stack.top]);
}
