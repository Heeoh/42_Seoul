/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:08:25 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 18:20:20 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	char	**p1;
	char	**p2;

	p1 = tab;
	while (*p1)
	{
		p2 = p1 + 1;
		while (*p2)
		{
			if (ft_strcmp(*p1, *p2) > 0)
				ft_swap(p1, p2);
			p2++;
		}
		p1++;
	}
}

#include <stdio.h>

int main() {
	char *arr[7];
	arr[0] = "hi";
	arr[1] = "my";
	arr[2] = "name";
	arr[3] = "is";
	arr[4] = "joushin";
	arr[5] = "aaaa";
	arr[6] = 0;
	for (int i = 0; i < 6; i++)
	{
		printf("before ::::::arr[%d] :: %s\n",i, arr[i]);
	}
	ft_sort_string_tab(arr);
	printf("\n\n\nafter\n\n\n\n");
	for (int i = 0; i < 6; i++)
	{
		printf("after ::::::arr[%d] :: %s\n",i, arr[i]);
	}
}
