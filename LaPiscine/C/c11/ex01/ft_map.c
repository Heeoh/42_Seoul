/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:33 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 13:47:37 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int *) * length);
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

#include <stdio.h>

int	plus(int num)
{
	return(num + 10);
}//ex01

int main() {
	printf("\n----------------------ex01----------------------------\n");
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *result = ft_map(arr, 10, plus);
	for(int i = 0; i < 10 ; i++)
		printf("result ::: arr[%d] :: %d\n",i,result[i]);
	//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
}

