/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:53:56 by heson             #+#    #+#             */
/*   Updated: 2022/07/22 17:59:00 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_malloc_len(size_t s_len, size_t len, unsigned int start)
{
	if (s_len < start + len)
	{
		if (s_len > start)
			return (s_len - start + 1);
		else
			return (1);
	}
	else
		return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	const char	*p;
	char		*res;
	char		*res_p;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	res = (char *)malloc(get_malloc_len(s_len, len, start));
	if (!res)
		return (NULL);
	res_p = res;
	if (start < s_len)
	{
		p = s + start;
		while (len-- && *p)
			*res_p++ = *p++;
	}
	*res_p = '\0';
	return (res);
}
