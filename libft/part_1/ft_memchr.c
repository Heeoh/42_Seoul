// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_memchr.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/13 15:10:01 by heson             #+#    #+#             */
// /*   Updated: 2022/07/13 16:39:18 by heson            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// void	*ft_memchr(const void *s, int c, unsigned int n)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)s;
// 	while (p - (unsigned char *)s < n)
// 	{
// 		if (*p == (unsigned char)c)
// 			return (p);
// 		if (!*p)
// 			return (0);
// 		p++;
// 	}
// 	return (0);
// }

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (*tmp && n)
	{
		if (*tmp == (unsigned char)c)
			break ;
		n--;
		tmp++;
	}
	if (n == 0)
		return (0);
	return (tmp);
}