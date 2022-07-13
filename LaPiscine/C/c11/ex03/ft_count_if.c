/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:59:46 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 15:45:07 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	char	**p;
	int		cnt;

	cnt = 0;
	p = tab;
	while (p <= tab + length)
	{
		if (!f(*p))
			cnt++;
		p++;
	}
	return (cnt);
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
	printf("\n----------------------ex03----------------------------\n");
	char *arr[7];
	arr[0] = "012345";
	arr[1] = "0325";
	arr[2] = "123";
	arr[3] = "678";
	arr[4] = "cccc";
	arr[5] = "aaaa";
	for(int i = 0; i < 6; i++)
		printf("arr[%d] ::::%s\n",i,arr[i]);
	printf("\n\nresult:::: %d\n",ft_count_if(arr, 6, check_num));
}
