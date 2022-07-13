/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:21:17 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:42:19 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	i = 0;
	while (i < src_len && dst_len + i < size - 1)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i <= size - 1)
		dest[dst_len + i] = '\0';
	return (dst_len + src_len);
}
