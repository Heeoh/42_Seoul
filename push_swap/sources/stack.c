/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:56:07 by heson             #+#    #+#             */
/*   Updated: 2023/02/01 19:27:03 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"
#include <stdlib.h>
#include <stdio.h>

void init_stack(t_stack *stack, int size)
{
    stack->top = -1;
    stack->mem_size = size;
    stack->memory = (int *)malloc(sizeof(int) * stack->mem_size);
}

void push_top(t_stack *stack, int x)
{
    if (isFull(*stack))
    {
        printf("ERROR - stack is full\n");
        return ;
    }
    stack->memory[++(stack->top)] = x;
}

void pop_top(t_stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("ERROR - stack is empty\n");
        return ;
    }
    stack->memory[(stack->top)--] = 0;
}

int get_top(t_stack stack)
{
    if (isEmpty(stack))
    {
        printf("ERROR - stack is empty\n");
        return (-1);
    }
    return (stack.memory[stack.top]);
}

int isFull(t_stack stack)
{
    return (stack.top + 1 == stack.mem_size);
}

int isEmpty(t_stack stack)
{
    return (stack.top == -1);
}

int get_stk_size(t_stack stack)
{
    return (stack.top + 1);
}