/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:18:19 by heson             #+#    #+#             */
/*   Updated: 2022/07/07 13:18:20 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcpy(char *dst, const char *src, size_t dstsize);
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len && i + 1 < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	while (i + 1 <= dstsize)
		dest[i++] = '\0';
	return (src_len);
}
