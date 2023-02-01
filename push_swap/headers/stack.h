/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:07:35 by heson             #+#    #+#             */
/*   Updated: 2023/01/29 20:35:00 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack {
    int *memory;
    int top;
    int mem_size;
}   t_stack;

void init_stack(t_stack *stack, int size);
void push_top(t_stack *stack, int x);
void pop_top(t_stack *stack);
int get_top(t_stack stack);
int isFull(t_stack stack);
int isEmpty(t_stack stack);
int get_stk_size(t_stack stack);

#endif