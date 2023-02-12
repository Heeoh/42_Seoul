/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:48 by heson             #+#    #+#             */
/*   Updated: 2023/02/12 16:10:22 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
#include "../headers/push_swap.h"

#include <stdio.h>  // printf
#include <stdlib.h> // atoi

void	print_state(t_stack stk_a, t_stack stk_b)
{
	int ia = 0, ib = 0;

	printf("a | ");
	while (ia <= stk_a.top)
		printf("%d ", stk_a.memory[ia++]);
	printf("\n");
	printf("b | ");
	while (ib <= stk_b.top)
		printf("%d ", stk_b.memory[ib++]);
	printf("\n");
}

int	*get_sorted_arr(t_list	*nums, int size)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (nums)
	{
		sorted[i++] = *((int *)nums->content);
		nums = nums->next;
	}
	ft_quick_sort(sorted, 0, size - 1);
	return (sorted);
}

void    init(int ac, char *av[], t_stack *stk_a, t_stack *stk_b, int **sorted)
{
	t_list	*nums;
	t_list	*nums_p;
	int		stack_size;

	nums = parsing(ac, av);
	stack_size = ft_lstsize(nums);
	init_stack(stk_a, stack_size);
	init_stack(stk_b, stack_size);
	nums_p = nums;
	while (nums_p)
	{
		push_top(stk_a, *((int *)(nums_p->content)));
		nums_p = nums_p->next;
	}
	*sorted = get_sorted_arr(nums, stack_size);
}

void	push_swap(t_stack *stk_a, t_stack *stk_b, int *sorted)
{
	int	i;

	i = 0;
	while (i <= stk_a->top && stk_a->memory[i] == sorted[stk_a->top - i])
		i++;
	if (i == get_stk_size(*stk_a))
		return ;
	// print_state(*stk_a, *stk_b);
	if (get_stk_size(*stk_a) > 3)
		a_to_b(stk_a, stk_b, 0, stk_a->top, sorted);
	else if (get_stk_size(*stk_a) == 3)
		sort_3nums(stk_a, stk_b, sorted[2], sorted[0]);
	else if (get_stk_size(*stk_a) == 2)
		sort_2nums(stk_a, stk_b, sorted[0]);
	// print_state(*stk_a, *stk_b);
}

int main(int ac, char *av[])
{
	t_stack stk_a;
	t_stack stk_b;
	int		*sorted;

	sorted = NULL;
	init(ac, av, &stk_a, &stk_b, &sorted);
	push_swap(&stk_a, &stk_b, sorted);	
}