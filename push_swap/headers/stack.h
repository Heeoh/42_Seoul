/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:07:35 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 15:10:22 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_stack {
	int	*memory;
	int	top;
	int	mem_size;
}	t_stack;

void	init_stack(t_stack *stack, int size);
void	push_top(t_stack *stack, int x);
void	pop_top(t_stack *stack);
int		peek_top(t_stack stack);
int		get_stk_size(t_stack stack);
bool	full(t_stack stack);
bool	empty(t_stack stack);

#endif