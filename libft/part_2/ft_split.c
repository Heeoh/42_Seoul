/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:11:47 by heson             #+#    #+#             */
/*   Updated: 2022/07/07 13:11:51 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_word_cnt(const char *str, char c)
{
	const char		*p;
	unsigned int	cnt;

	cnt = 0;
	p = str;
	if (*p && !c)
		return (1);
	while (*p)
	{
		if (*p == c)
			p++;
		if (*p != c)
		{
			cnt++;
			p++;
			while (*p && *p != c)
				p++;
		}
	}
	return (cnt);
}

// part 1
size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

// part 1
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i + 1 <= dstsize)
		dst[i] = '\0';
	return (src_len);
}

char	solve(const char *str, char c, char **res, unsigned int word_cnt)
{
	unsigned int	i;
	const char		*word_sp;

	i = 0;
	while (*str && i < word_cnt)
	{
		if (*str != c)
		{
			word_sp = str++;
			while (*str && *str != c)
				str++;
			res[i] = (char *)malloc(str - word_sp + 1);
			if (!res[i] || !ft_strlcpy(res[i], word_sp, str - word_sp + 1))
				return (0);
			i++;
		}
		str++;
	}
	res[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	word_cnt;
	char			**res;

	word_cnt = get_word_cnt(s, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	if (solve(s, c, res, word_cnt))
		return (res);
	else
		return (NULL);
}