/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:10:22 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:47:41 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	buf[len];
	unsigned int	cnt;

	p = (unsigned char *)dst;
	cnt = 0;
	while (cnt < len && *(const unsigned char *)src)
	{
		buf[cnt++] = *(const unsigned char *)src;
		src++;
	}
	p += cnt - 1;
	while (cnt--)
		*(p--) = buf[cnt];
	return (dst);
}
