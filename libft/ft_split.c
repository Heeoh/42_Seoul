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

#include <stdlib.h>

char	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_word_cnt(char *str, char *charset)
{
	char	*p;
	int		cnt;

	cnt = 0;
	p = str;
	while (*p)
	{
		if (!*charset)
			return (1);
		if (!is_charset(*p, charset))
		{
			cnt++;
			p++;
			while (*str && !is_charset(*p, charset))
				p++;
		}
		p++;
	}
	return (cnt);
}

char	ft_strlcpy(char *dest, char *src, int n)
{
	int	i;

	if (n < 0)
		return (0);
	i = 0;
	while (src[i] && i < n - 1)
		*dest++ = src[i++];
	*dest = '\0';
	return (1);
}

char	solve(char *str, char *charset, char **res, int word_cnt)
{
	int		i;
	char	*word_sp;

	i = 0;
	while (*str && i < word_cnt)
	{
		if (!is_charset(*str, charset))
		{
			word_sp = str++;
			while (*str && !is_charset(*str, charset))
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

char	**ft_split(char *str, char *charset)
{
	int		word_cnt;
	char	**res;

	word_cnt = get_word_cnt(str, charset);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (0);
	if (solve(str, charset, res, word_cnt))
		return (res);
	else
		return (0);
}
