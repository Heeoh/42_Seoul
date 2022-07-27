/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:15:08 by heson             #+#    #+#             */
/*   Updated: 2022/07/27 16:18:37 by heson            ###   ########.fr       */
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
