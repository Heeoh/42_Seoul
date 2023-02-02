/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:48 by heson             #+#    #+#             */
/*   Updated: 2023/02/02 21:03:42 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
#include "../headers/push_swap.h"

#include <stdio.h>  // printf
#include <stdlib.h> // atoi


void    init(int ac, char *av[], t_stack *stk_a, t_stack *stk_b)
{
	t_list	*nums;
	t_list	*nums_p;
	int		stack_size;

	nums = check_argv(ac, av);
	stack_size = ft_lstsize(nums);
	init_stack(stk_a, stack_size);
	init_stack(stk_b, stack_size);
	nums_p = nums;
	while (nums_p)
	{
		push_top(stk_a, *((int *)(nums_p->content)));
		nums_p = nums_p->next;
	}
}

int main(int ac, char *av[])
{
	t_stack stk_a;
	t_stack stk_b;

	init(ac, av, &stk_a, &stk_b);
 
	insertion_sort(&stk_a, &stk_b);

}