/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:15:54 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 02:48:24 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

void	check_dup_num(t_list *list, int num)
{
	t_list	*p;

	p = list;
	while (p)
	{
		if (*((int *)(p->content)) == num)
			print_error();
		p = p->next;
	}
}

void	check_int_range(char *num)
{
	int	sign;
	int	ret;
	int	len;

	sign = 1;
	ret = 0;
	if (num[0] == '+' || num[0] == '-')
	{
		if (num[0] == '-')
			sign = -1;
		num++;
	}
	len = ft_strlen(num);
	if (len == 10)
	{
		if (sign > 0)
			ret = ft_strncmp(num, "2147483647", 10);
		else
			ret = ft_strncmp(num, "2147483648", 10);
	}
	if ((0 < len && len < 10) || (len == 10 && ret <= 0))
		return ;
	else
		print_error();
}

void	check_an_argv(char *av, t_list **list)
{
	char	*ch_p;
	int		is_int;
	int		*num;
	t_list	*new;

	is_int = true;
	ch_p = av;
	while (ch_p && *ch_p && is_int)
	{
		if (!ft_isdigit(*ch_p) && !(*ch_p == '+' || *ch_p == '-'))
			is_int = false;
		ch_p++;
	}
	if (!is_int)
		print_error();
	check_int_range(av);
	num = (int *)malloc(sizeof(int));
	if (!num)
		print_error();
	*num = atoi(av);
	check_dup_num(*list, *num);
	new = ft_lstnew(num);
	ft_lstadd_front(list, new);
}
