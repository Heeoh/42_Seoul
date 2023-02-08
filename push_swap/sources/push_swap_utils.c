/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:23:45 by heson             #+#    #+#             */
/*   Updated: 2023/02/08 14:24:13 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_quick_sort(int *nums, int s, int e)
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
		ft_quick_sort(nums, s, right - 1);
	if (right + 1 < e)
		ft_quick_sort(nums, right + 1, e);
}