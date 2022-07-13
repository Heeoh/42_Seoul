/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:10:27 by heson             #+#    #+#             */
/*   Updated: 2022/07/07 13:10:34 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	get_res_len(int size, char **strs, char *sep)
{
	int	res_len;
	int	i;

	res_len = 0;
	i = 0;
	while (i < size)
		res_len += ft_strlen(strs[i++]);
	if (size > 0)
		res_len += ft_strlen(sep) * (size - 1);
	return (res_len);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		res_len;
	char	*p;
	int		word_i;

	res_len = get_res_len(size, strs, sep);
	res = (char *)malloc(res_len + 1);
	if (!res)
		return (0);
	res[res_len] = '\0';
	if (size <= 0)
		return (res);
	word_i = 0;
	p = res;
	while (word_i < size - 1)
	{
		p = ft_strcpy(p, strs[word_i++]);
		p = ft_strcpy(p, sep);
	}
	p = ft_strcpy(p, strs[word_i++]);
	return (res);
}
