/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:07 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 16:40:33 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (0);
	p = (char *)s + ft_strlen(s);
	while (1)
	{
		if (*p == (char)c)
			return (p);
		if (*p == *s)
			return (0);
		p--;
	}
}