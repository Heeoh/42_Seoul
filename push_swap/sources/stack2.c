/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:17:54 by heson             #+#    #+#             */
/*   Updated: 2023/02/14 18:07:06 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack.h"

int	get_stk_size(t_stack stack)
{
	return (stack.top + 1);
}

bool	full(t_stack stack)
{
	return (stack.top + 1 == stack.mem_size);
}

bool	empty(t_stack stack)
{
	return (stack.top == -1);
}
