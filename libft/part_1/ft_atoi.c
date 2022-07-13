/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:08:49 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 19:03:50 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char			*p;
	int				sign;
	unsigned int	absolute_num;

	p = (char *)str;
	sign = 1;
	while (*p && (*p == ' ' || (9 <= *p && *p <= 13)))
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
		sign = -1;
		p++;
	}
	absolute_num = 0;
	while (*p && '0' <= *p && *p <= '9')
	{
		absolute_num = absolute_num * 10 + (*p - '0');
		p++;
	}
	return (absolute_num * sign);
}
