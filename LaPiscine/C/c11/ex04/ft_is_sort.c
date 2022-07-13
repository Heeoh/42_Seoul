/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:50:40 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 16:05:02 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	*p;
	int	pre_max;

	p = tab;
	while (p < tab + length)
	{
		if (f(pre_max, *p) > 0)
			return (0);
		pre_max = *p;
		p++;
	}
	return (1);
}

#include <stdio.h>

int	cmp(int a,int b)
{
	if (a < b)
		return (-1);
	else if (a > b)
		return (1);
	else
		return (0);
}//ex04

int main()
{
	printf("\n----------------------ex04----------------------------\n");
	int tab[100] = {1,4,6,0,7,10,100};//7
	for(int i = 0; i < 7; i++)
		printf("tab[%d] ::::%d\n",i,tab[i]);
	printf("\nresult::::%d\n\n\n" ,ft_is_sort(tab, 7, cmp));
}

