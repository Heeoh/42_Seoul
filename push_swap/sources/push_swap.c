/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:48 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 02:20:39 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/operations.h"
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

void	init(t_list *nums, t_stack *stk_a, t_stack *stk_b, int **sorted)
{
	int		stack_size;
	int		i;
	t_list	*nums_p;

	stack_size = ft_lstsize(nums);
	init_stack(stk_a, stack_size);
	init_stack(stk_b, stack_size);
	*sorted = NULL;
	*sorted = (int *)malloc(sizeof(int) * stack_size);
	if (!*sorted)
		return ;
	nums_p = nums;
	i = 0;
	while (nums_p)
	{
		push_top(stk_a, *((int *)(nums_p->content)));
		(*sorted)[i++] = *((int *)(nums_p->content));
		nums_p = nums_p->next;
	}
	get_sorted_arr(*sorted, 0, stack_size - 1);
}

void	push_swap(t_stack *stk_a, t_stack *stk_b, int *sorted)
{
	int	top_idx;
	int	i;

	top_idx = stk_a->top;
	i = 0;
	while (i <= top_idx
		&& stk_a->memory[i] == sorted[top_idx - i])
		i++;
	if (i == get_stk_size(*stk_a))
		return ;
	if (get_stk_size(*stk_a) <= 5)
		sort_less_5nums(stk_a, stk_b, sorted);
	else
		a_to_b(stk_a, stk_b, 0, top_idx, sorted);
}

int	main(int ac, char *av[])
{
	t_list	*parsing_lst;
	t_stack	stk_a;
	t_stack	stk_b;
	int		*sorted;

	parsing_lst = parsing(ac, av);
	init(parsing_lst, &stk_a, &stk_b, &sorted);
	push_swap(&stk_a, &stk_b, sorted);
	// print_state(stk_a, stk_b);
	do_free(&parsing_lst, &stk_a, &stk_b, &sorted);
	// system("leaks push_swap");
}
