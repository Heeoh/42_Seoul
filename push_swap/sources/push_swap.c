/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:48 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 02:50:15 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
#include "../headers/sorting.h"
#include "../headers/push_swap.h"

t_list	*parsing(int ac, char *av[])
{
	t_list	*list;
	char	**str_arr;
	int		i;
	int		j;

	list = 0;
	i = 0;
	while (++i < ac)
	{
		while (av[i] && *av[i])
		{
			str_arr = ft_split(av[i], ' ');
			j = 0;
			while (str_arr[j])
			{
				check_an_argv(str_arr[j], &list);
				free(str_arr[j]);
				j++;
			}
			free(str_arr);
			i++;
		}
	}
	return (list);
}

void	init(t_list *nums, t_two_stks *stk, int **sorted)
{
	int		stack_size;
	int		i;
	t_list	*nums_p;

	stack_size = ft_lstsize(nums);
	init_stack(&stk->a, stack_size);
	init_stack(&stk->b, stack_size);
	*sorted = NULL;
	*sorted = (int *)malloc(sizeof(int) * stack_size);
	if (!*sorted)
		print_error();
	nums_p = nums;
	i = 0;
	while (nums_p)
	{
		push_top(&stk->a, *((int *)(nums_p->content)));
		(*sorted)[i++] = *((int *)(nums_p->content));
		nums_p = nums_p->next;
	}
	get_sorted_arr(*sorted, 0, stack_size - 1);
}

void	push_swap(t_two_stks *stk, int *sorted)
{
	int	top_idx;
	int	i;

	top_idx = stk->a.top;
	i = 0;
	while (i <= top_idx
		&& stk->a.memory[i] == sorted[top_idx - i])
		i++;
	if (i == get_stk_size(stk->a))
		return ;
	if (get_stk_size(stk->a) <= 5)
		sort_less_5nums(stk, sorted);
	else
		a_to_b(stk, 0, top_idx, sorted);
}

int	main(int ac, char *av[])
{
	t_list		*parsing_lst;
	t_two_stks	stks;
	int			*sorted;

	parsing_lst = parsing(ac, av);
	init(parsing_lst, &stks, &sorted);
	push_swap(&stks, sorted);
	do_free(&parsing_lst, &stks, &sorted);
}
