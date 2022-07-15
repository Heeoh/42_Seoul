/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:10:05 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 16:39:24 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int			i;
	const unsigned char		*p1;
	const unsigned char		*p2;

	p1 = s1;
	p2 = s2;
	if (!p1[0] && !p2[0])
		return (0);
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};

// 	/* 5 */ printf("%d\n",ft_memcmp(s2, s3, 4));
// 	write(1, "\n", 1);
// 	return (0);
// }