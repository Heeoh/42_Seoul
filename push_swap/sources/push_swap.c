/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:48 by heson             #+#    #+#             */
/*   Updated: 2023/01/30 16:09:54 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/stack.h"
#include "../header/operations.h"
#include "../header/push_swap.h"

#include <stdio.h>  // printf
#include <stdlib.h> // atoi

void    init(int ac, char *av[], t_stack *stk_a, t_stack *stk_b)
{
	init_stack(stk_a, ac);
	init_stack(stk_b, ac);

	while (--ac)
		push_top(stk_a, atoi(av[ac]));
}



int main(int ac, char *av[])
{
	t_stack stk_a;
	t_stack stk_b;

	init(ac, av, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Init a and b: \n");
	// print_state(stk_a, stk_b);

	insertion_sort(&stk_a, &stk_b);

	// do_operation(SA, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Exec sa: \n");
	// print_state(stk_a, stk_b);

	// do_operation(PB, &stk_a, &stk_b);
	// do_operation(PB, &stk_a, &stk_b);
	// do_operation(PB, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Exec pb pb pb: \n");
	// print_state(stk_a, stk_b);

	// do_operation(RA, &stk_a, &stk_b);
	// do_operation(RB, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Exec ra rb: \n");
	// print_state(stk_a, stk_b);

	// do_operation(RRA, &stk_a, &stk_b);
	// do_operation(RRB, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Exec rra rrb: \n");
	// print_state(stk_a, stk_b);

	// do_operation(SA, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Exec sa: \n");
	// print_state(stk_a, stk_b);

	// do_operation(PA, &stk_a, &stk_b);
	// do_operation(PA, &stk_a, &stk_b);
	// do_operation(PA, &stk_a, &stk_b);
	// printf("------------------\n");
	// printf("Exec pa pa pa: \n");
	// print_state(stk_a, stk_b);
}