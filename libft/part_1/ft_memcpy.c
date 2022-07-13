/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:10:14 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:44:57 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)dst;
	while (n-- && *((unsigned const char *)src))
	{
		*p++ = *((unsigned const char *)src);
		src++;
	}
	return (dst);
}
