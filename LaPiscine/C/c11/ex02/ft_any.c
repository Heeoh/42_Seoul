/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:52:25 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 13:58:34 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int(*f)(char *))
{
	char **p;

	p = tab;
	while (*p)
	{
		if (!f(*p))
			return (1);
		p++;
	}
	return (0);
}

#include <stdio.h>

int check_num(char *arr)
{
	while (*arr)
	{
		if ('0' <= *arr && *arr <= '9')
			return (0);
		arr++;
	}
	return (1);
}//ex02 ex03

int main() {
	printf("\n----------------------ex02----------------------------\n");
	char *arr[7];
	arr[0] = "a";
	arr[1] = "b";
	arr[2] = "c";
	arr[3] = "d";
	arr[4] = "e";
	arr[5] = 0;
	for(int i = 0; i < 5; i++)
		printf("arr[%d] ::::%s\n",i,arr[i]);
	printf("\n\nresult:::: %d\n",ft_any(arr, check_num));
}
