/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:10:14 by heson             #+#    #+#             */
/*   Updated: 2022/07/20 18:41:43 by heson            ###   ########.fr       */
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
