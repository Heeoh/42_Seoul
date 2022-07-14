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

#include "libft.h"

// part_1
size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	const char	*p;
	char		*res_p;

	res = (char *)malloc(strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	res_p = res;
	p = s1;
	while (*p)
		*res_p++ = *p++;
	p = s2;
	while (*p)
		*res_p++ = *p++;
	*res_p = '\0';
	return (res);
}