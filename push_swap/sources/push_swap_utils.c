/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:23:45 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 02:48:30 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	get_sorted_arr(int *nums, int s, int e)
{
	int	pivot;
	int	left;
	int	right;

	pivot = nums[s];
	left = s + 1;
	right = e;
	while (left <= right)
	{
		while (left <= e && nums[left] < pivot)
			left++;
		while (right > s && nums[right] > pivot)
			right--;
		if (left < right)
			ft_swap(&nums[left], &nums[right]);
	}
	ft_swap(&nums[s], &nums[right]);
	if (s < right - 1)
		get_sorted_arr(nums, s, right - 1);
	if (right + 1 < e)
		get_sorted_arr(nums, right + 1, e);
}

void	print_state(t_two_stks stk)
{
	int	ia;
	int	ib;

	ia = 0;
	ib = 0;
	ft_printf("a | ");
	while (ia <= stk.a.top)
		ft_printf("%d ", stk.a.memory[ia++]);
	ft_printf("\n");
	ft_printf("b | ");
	while (ib <= stk.b.top)
		ft_printf("%d ", stk.b.memory[ib++]);
	ft_printf("\n");
}

void	do_free(t_list **lst, t_two_stks *stk, int **sorted)
{
	if (lst)
		ft_lstclear(lst, free);
	if (stk && stk->a.memory)
		free(stk->a.memory);
	if (stk && stk->b.memory)
		free(stk->b.memory);
	if (*sorted)
		free(*sorted);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
