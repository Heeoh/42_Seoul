/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:15:54 by heson             #+#    #+#             */
/*   Updated: 2023/02/08 14:28:30 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

#include <stdlib.h> // malloc, free
#include <ctype.h>

void	print_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

void	check_dup(t_list *list, int num)
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
	int len;

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
	if (len < 10 || ret <= 0)
		return ;
	else if (len > 10 || ret > 0)
		print_error();
}

void	check_an_argv(char  *av, t_list **list)
{
	char	*av_p;
	int		is_int;
	int		*num;
	t_list	*new;

	is_int = TRUE;
	av_p = av;
	while (av_p && *av_p)
	{
		if (!isdigit(*av_p) && !(*av_p == '+' || *av_p == '-'))
			is_int = FALSE;
		av_p++;
	}
	if (!is_int)
		print_error();
	check_int_range(av);
	num = (int *)malloc(sizeof(int));
	if (!num)
		return ;
	*num = atoi(av);
	check_dup(*list, *num);
	new = ft_lstnew(num);
	ft_lstadd_front(list, new);
}

t_list	*parsing(int ac, char *av[])
{
	t_list	*list;
	char	**str_arr;
	int 	i;
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
				check_an_argv(str_arr[j++], &list);
			i++;
		}
	}
	return (list);
}
 