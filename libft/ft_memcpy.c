/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:10:14 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 17:49:55 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (n--)
	{
		*p++ = *(unsigned char *)src;
		src++;
	}
	return (dst);
}
