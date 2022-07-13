/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:30:00 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 13:20:57 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

#include <stdio.h>
void	ft_print_num(int a)
{
	printf("%d ", a);
}

int main() {
	printf("-------ex00-------\n\n");
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("arr : ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	printf("foreach : ");
	ft_foreach(arr, 10, &ft_print_num);
	printf("\n\n");
}
